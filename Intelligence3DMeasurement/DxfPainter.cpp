#include <QWheelEvent>
#include <QGraphicsRectItem>
#include <QModelIndex>
#include <QDebug>
#include <qmath.h>
#include "DxfPainter.h"

#include "DXF_RELATIVE\dxfellipseitem.h"
#include "DXF_RELATIVE\dxfpolylineitem.h"
#include "DXF_RELATIVE\dxfaligneddimitem.h"
#include "DXF_RELATIVE\dxfangulardimitem.h"
#include "DXF_RELATIVE\dxfradialdimitem.h"
#include "DXF_RELATIVE\MarkItem.h"
#include "Global.h"

#define P_DISTANCE(p1, p2) pow((p1.x()-p2.x()), 2) + pow((p1.y()-p2.y()), 2);


DxfPainter::DxfPainter(QWidget *parent) : QGraphicsView(parent),
	m_zoomRatio(1.0), m_zoomMax(10), m_zoomMin(0.8), m_zoomStep(0.1),
	m_hasPathItem(false), m_hasPathItem1(false), m_absorptionDis(8.0)
{
	setContextMenuPolicy(Qt::DefaultContextMenu);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	setRenderHint(QPainter::Antialiasing);
	setSceneRect(INT_MIN / 2, INT_MIN / 2, INT_MAX, INT_MAX);

	m_dxfScene = new QGraphicsScene;
	m_dxfScene->setBackgroundBrush(QColor(30, 30, 39));
	setScene(m_dxfScene);

	QString toolTip;
	toolTip.append("平移：鼠标中键\\方向键\n");
	toolTip.append("缩放：鼠标滚轮\n");
	toolTip.append("选中：左键\\右键\n");
	toolTip.append("删除选中：DEL\n");
	toolTip.append("显示标注：`\n");
	toolTip.append("显示路径：~\n");
	toolTip.append("设置路径：B");
	setToolTip(toolTip);
}

DxfPainter::~DxfPainter()
{
	delete m_dxfScene;
}
/**
 * @brief	Create pop-menu
 */
void DxfPainter::contextMenuEvent(QContextMenuEvent *event)
{
	// ASSERT: polyline is disabled.
	QMenu contextMenu;
	QList<QGraphicsItem*> items = m_dxfScene->selectedItems();
	if (items.count() == 2) {
		if (items.first()->type() == DXF_POLY && items.last()->type() == DXF_POLY) {
			connect(contextMenu.addAction("线 - 线：间距"), SIGNAL(triggered(bool)), this, SLOT(SampleOfL2LDist()));
			connect(contextMenu.addAction("线 - 线：夹角"), SIGNAL(triggered(bool)), this, SLOT(SampleTheL2LAngle()));
		}
		else if (items.first()->type() == DXF_ELLIPSE && items.last()->type() == DXF_ELLIPSE) {
			connect(contextMenu.addAction("点 - 点：间距"), SIGNAL(triggered(bool)), this, SLOT(SampleTheP2PDist()));
		}
		else if ((items.first()->type() == DXF_ELLIPSE && items.last()->type() == DXF_POLY) ||
			(items.first()->type() == DXF_POLY && items.last()->type() == DXF_ELLIPSE)) {
			connect(contextMenu.addAction("点 - 线：间距"), SIGNAL(triggered(bool)), this, SLOT(SampleTheP2LDist()));
		}
		else if (items.first()->type() == DXF_MARK && items.last()->type() == DXF_MARK) {
			connect(contextMenu.addAction("激光测高"), SIGNAL(triggered(bool)), this, SLOT(SampleTheHeight()));
		}
		contextMenu.exec(QCursor::pos());
	}
	else if (items.count() == 1) {
		if (items.first()->type() == DXF_ELLIPSE) {
			connect(contextMenu.addAction("半径"), SIGNAL(triggered(bool)), this, SLOT(SampleTheRadius()));
			connect(contextMenu.addAction("弧角"), SIGNAL(triggered(bool)), this, SLOT(SampleTheArcAngle()));
			connect(contextMenu.addAction("圆度"), SIGNAL(triggered(bool)), this, SLOT(SampleTheCircular()));
		}
		else if (items.first()->type() == DXF_POLY) {
			connect(contextMenu.addAction("长度"), SIGNAL(triggered(bool)), this, SLOT(SampleOfLength()));
			connect(contextMenu.addAction("直线度"), SIGNAL(triggered(bool)), this, SLOT(SampleTheStraightness()));
		}
		else if (items.first()->type() == DXF_MARK) {
			connect(contextMenu.addAction("激光测高"), SIGNAL(triggered(bool)), this, SLOT(SampleTheHeight()));
		}
		contextMenu.exec(QCursor::pos());
	}
	else if (items.count() > 2) {
		bool isLaser = true;
		Q_FOREACH(QGraphicsItem *item, m_dxfScene->selectedItems()) {
			if (item->type() != DXF_MARK) { isLaser = false; }
		}
		if (isLaser) {
			connect(contextMenu.addAction("激光测高"), SIGNAL(triggered(bool)), this, SLOT(SampleTheHeight()));
			contextMenu.exec(QCursor::pos());
		}
	}

	QGraphicsView::contextMenuEvent(event);
}
/**
 * @brief	Hide markitem
 */
void DxfPainter::focusInEvent(QFocusEvent *event)
{
	ClearMarkItem(0);
	QGraphicsView::focusInEvent(event);
}
/**
 * @brief	Key controller
 */
void DxfPainter::keyPressEvent(QKeyEvent * event)
{
	switch (event->key()) {
	case Qt::Key_B:
		UpdateSqc();
		break;
	case Qt::Key_Space:
		if (!Global::g_enable2DMode) {
			MarkItem *item = new MarkItem(1);
			item->setPos(m_currentCursorPos);
			m_dxfScene->addItem(item);
		}
		break;
	case Qt::Key_Up:
		Translator(QPointF(0, -3));	// viewport up
		break;
	case Qt::Key_Down:
		Translator(QPointF(0, 3));	// viewport down
		break;
	case Qt::Key_Left:
		Translator(QPointF(-3, 0));	// viewport left
		break;
	case Qt::Key_Right:
		Translator(QPointF(3, 0));	// viewport right
		break;
	case Qt::Key_QuoteLeft:
		Q_FOREACH (QGraphicsItem *item, m_dxfScene->items()) {
			if (item->type() == DXF_ALIGNED || item->type() == DXF_ANGULAR || item->type() == DXF_RADIAL) {
				item->setVisible(!item->isVisible());
			}
		}
		break;
	case Qt::Key_AsciiTilde:
		if (m_hasPathItem) { m_pathItem->setVisible(!m_pathItem->isVisible()); }
		if (m_hasPathItem1) { m_pathItem1->setVisible(!m_pathItem1->isVisible()); }
		break;
	case Qt::Key_Delete:
		qDeleteAll(m_dxfScene->selectedItems());
		break;
	default:
		QGraphicsView::keyPressEvent(event);
	}
}
/**
 * @brief	Mouse controller 1
 */
void DxfPainter::mouseMoveEvent(QMouseEvent * event)
{
	if (m_isMouseDragMoveEnable) {
		QPointF moveDelta = mapToScene(event->pos()) - mapToScene(m_lastCursorPos);
		Translator(moveDelta);
	}
	m_lastCursorPos = event->pos();
	m_currentCursorPos = mapToScene(event->pos());

	QGraphicsView::mouseMoveEvent(event);
}
/**
 * @brief	Mouse controller 2
 */
void DxfPainter::mousePressEvent(QMouseEvent * event)
{
	setDragMode(QGraphicsView::NoDrag);
	m_isMouseDragMoveEnable = false;

	if (event->button() == Qt::MidButton) {
		setCursor(Qt::OpenHandCursor);
		m_lastCursorPos = event->pos();
		m_isMouseDragMoveEnable = true;
	}
	// right button pops
	else if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
		setCursor(Qt::CrossCursor);
		setDragMode(QGraphicsView::RubberBandDrag);
	}

	QGraphicsView::mousePressEvent(event);
}
/**
 * @brief	Mouse controller 3
 */
void DxfPainter::mouseReleaseEvent(QMouseEvent * event)
{
	setCursor(Qt::ArrowCursor);
	// translate
	if (event->button() == Qt::MidButton) { m_isMouseDragMoveEnable = false; }

	QGraphicsView::mouseReleaseEvent(event);
}
/**
 * @brief	Mouse controller 4
 */
void DxfPainter::wheelEvent(QWheelEvent * event)
{
	qreal factor, ratio;
	if (event->delta() > 0) { factor = 1 + m_zoomStep; }
	if (event->delta() < 0) { factor = 1 - m_zoomStep; }
	ratio = transform().scale(factor, factor).mapRect(QRectF(0, 0, 1, 1)).width();
	if (ratio < m_zoomMin || ratio > m_zoomMax) { return; }
	scale(factor, factor);
	m_zoomRatio *= factor;
}
/**
 * @brief	Point attachment
 * @param	nearPoints
 * @param	currentPos
 */
QPointF DxfPainter::GetNearest(const QList<QPointF> &nearPoints, const QPointF &currentPos)
{
	QPointF target(currentPos);
	Q_FOREACH(QPointF p, nearPoints) {
		int temp = P_DISTANCE(p, currentPos);
		if (temp < m_absorptionDis) {
			target = p;		// may throw unknown exception:0xc0000005
		}
	}
	return target;
}
/**
 * @brief	Caculate camera path sequence
 */
void DxfPainter::UpdateSqc()
{
	// attach beginning point.
	QList<QPointF> endPoints;
	Q_FOREACH(QGraphicsItem* it, m_dxfScene->items()) {
		if (it->type() == DXF_POLY) { endPoints << POLY_PTR_CAST(it)->PolygonF().toList(); }
	}
	QPointF begin(GetNearest(endPoints, m_currentCursorPos));

	// connnect
	Global::g_projectInfo.camMeasurePath.clear();
	QList<CAMERAITEM> items(Global::g_projectInfo.camItemList.toList());
	QPointF previousNode(begin);
	int n = items.count();
	while (n--) {
		int index;
		double min = INT_MAX;
		bool isInverted = false;
		for (int i = 0; i < items.count(); ++i) {
			if (items.at(i).nTemp != 1) {
				double d0 = P_DISTANCE(previousNode, items.at(i).cadPosList.first());
				double d1 = P_DISTANCE(previousNode, items.at(i).cadPosList.last());
				if ((d0 < d1) && (d0 < min)) {
					min = d0;
					index = i;
					isInverted = false;
				}
				if ((d1 < d0) && (d1 < min)) {
					min = d1;
					index = i;
					isInverted = true;
				}
				if ((d0 == d1) && (d0 < min)) {
					min = d0;
					index = i;
					isInverted = false;
				}
			}
		}
		if (isInverted) { previousNode = items.at(index).cadPosList.first(); }
		else{ previousNode = items.at(index).cadPosList.last(); }
		items[index].nTemp = 1;		// processed
		Global::g_projectInfo.camMeasurePath.append(index);
		Global::g_projectInfo.camItemList[index].bPosListInverted = isInverted;
	}

	Global::g_projectInfo.startCADPos = begin;
	LoadPathItem();
}
/**
 * @brief	Add pathitem
 */
void DxfPainter::LoadPathItem()
{
	QVector<QPointF> path, path1;

	path.append(Global::g_projectInfo.startCADPos);
	Q_FOREACH(int sqc, Global::g_projectInfo.camMeasurePath) {
		if (Global::g_projectInfo.camItemList.at(sqc).bPosListInverted) {
			for (int i = Global::g_projectInfo.camItemList.at(sqc).cadPosList.count() - 1; i >= 0; --i) {
				path << Global::g_projectInfo.camItemList.at(sqc).cadPosList.at(i);
			}
		}
		else {
			path << Global::g_projectInfo.camItemList.at(sqc).cadPosList;
		}
	}
	if (path.count() > 0) {
		if (m_hasPathItem) { delete m_pathItem; }
		m_pathItem = new PathItem(path);
		m_pathItem->setPos(0, 0);
		m_dxfScene->addItem(m_pathItem);
		m_hasPathItem = true;
	}

	path1.append(path.last());
	Q_FOREACH(LASERITEM item, Global::g_projectInfo.laserItemList) {
		for (int i = 0; i < item.cadPosList.count(); ++i) {
			MarkItem *laserItem = new MarkItem(1);
			laserItem->setPos(item.cadPosList.at(i));
			laserItem->SetProcessed();
			m_dxfScene->addItem(laserItem);
		}
		path1.append(item.cadPosList);
	}
	if (path1.count() > 0) {
		if (m_hasPathItem1) { delete m_pathItem1; }
		m_pathItem1 = new PathItem(path1, 1);
		m_pathItem1->setPos(0, 0);
		m_dxfScene->addItem(m_pathItem1);
		m_hasPathItem1 = true;
	}
}
/**
 * @brief	Viewport x-y shift
 * @param	delta
 */
void DxfPainter::Translator(QPointF delta)
{
	delta *= m_zoomRatio;	// based on current zoom ratio

	// get new viewport center based on cursor
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	QPoint newCenter(viewport()->rect().width() / 2 - delta.x(), viewport()->rect().height() / 2 - delta.y());
	centerOn(mapToScene(newCenter));

	setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}
/**
 * @brief	Open DXF File
 * @param	isCleanOpen
 *		-true	New.
 *		-false	Load.
 */
void DxfPainter::OpenDXF(bool isCleanOpen)
{
	QString path = CAD_DIRECTORY + Global::g_projectInfo.cadFileName;
	EntitiesParser4DXF *entities = new EntitiesParser4DXF(path);
	entities->covPolyline2Line();		// disable polyline

	if (isCleanOpen) {
		Global::g_projectInfo.camMeasurePath.clear();
		Global::g_projectInfo.camItemList.clear();
		Global::g_projectInfo.laserItemList.clear();
	}

	qDeleteAll(m_dxfScene->items());

	Q_FOREACH(LINE data, entities->readLineData()) {
		DXFPolylineItem *lineItem = new DXFPolylineItem(data);
		lineItem->setPos(0, 0);
		m_dxfScene->addItem(lineItem);
	}

	Q_FOREACH(ARC data, entities->readArcData()) {
		DXFEllipseItem *arcItem = new DXFEllipseItem(data);
		arcItem->setPos(arcItem->CenterPos());
		m_dxfScene->addItem(arcItem);
	}

	Q_FOREACH(CIRCLE data, entities->readCircleData()) {
		DXFEllipseItem *circleItem = new DXFEllipseItem(data);
		circleItem->setPos(circleItem->CenterPos());
		m_dxfScene->addItem(circleItem);
	}

	Q_FOREACH(ELLIPSE data, entities->readEllipseData()) {
		DXFEllipseItem *ellipseItem = new DXFEllipseItem(data);
		ellipseItem->setPos(ellipseItem->CenterPos());
		m_dxfScene->addItem(ellipseItem);
	}

	Q_FOREACH(ALIGNEDDIM data, entities->readAlignedDimData()) {
		DXFAlignedDimItem *alignedItem = new DXFAlignedDimItem(data);
		alignedItem->setPos(0, 0);
		m_dxfScene->addItem(alignedItem);
	}

	Q_FOREACH(ANGULARDIM data, entities->readAngularDimData()) {
		DXFAngularDimItem *angularItem = new DXFAngularDimItem(data);
		angularItem->setPos(0, 0);
		m_dxfScene->addItem(angularItem);
	}

	Q_FOREACH(RADIALDIM data, entities->readRadialDimData()) {
		DXFRadialDimItem *radialItem = new DXFRadialDimItem(data);
		radialItem->setPos(0, 0);
		m_dxfScene->addItem(radialItem);
		centerOn(radialItem);		// set viewer center
	}

	m_hasPathItem = false;
	m_hasPathItem1 = false;

	delete entities;
	emit RequireTitleUpdate();
}
/**
 * @brief	Reset mesurement path
 */
void DxfPainter::Replan()
{
	if (m_hasPathItem) {
		delete m_pathItem;
		m_hasPathItem = false;
	}
	if (m_hasPathItem1) {
		delete m_pathItem1;
		m_hasPathItem1 = false;
	}
	
	ClearMarkItem(0);
	ClearMarkItem(1);

	Q_FOREACH(QGraphicsItem *item, m_dxfScene->items()) {
		if (item->type() == DXF_POLY) { POLY_PTR_CAST(item)->SetProcessed(false); }
		if (item->type() == DXF_ELLIPSE) { ELLIPSE_PTR_CAST(item)->SetProcessed(false); }
	}

	Global::g_projectInfo.camMeasurePath.clear();
	Global::g_projectInfo.camItemList.clear();
	Global::g_projectInfo.laserItemList.clear();
}
/**
 * @brief	Load existing project
 */
void DxfPainter::LoadProject()
{
	OpenDXF(false);
	LoadPathItem();
}
/**
 * @brief	Activate markitem
 */
void DxfPainter::ActivateMarkItem(const QModelIndex & index)
{
	ClearMarkItem(0);
	int camCount = Global::g_projectInfo.camItemList.count();
	if (index.row() < camCount) {
		Q_FOREACH(QPointF p, Global::g_projectInfo.camItemList.at(index.row()).cadPosList) {
			MarkItem *mark = new MarkItem(0, Global::g_camViewField);
			mark->setPos(p);
			m_dxfScene->addItem(mark);
		}
	}
	else {
		Q_FOREACH(QPointF p, Global::g_projectInfo.laserItemList.at(index.row() - camCount).cadPosList) {
			MarkItem *mark = new MarkItem(1);
			mark->setPos(p);
			m_dxfScene->addItem(mark);
		}
	}
}
/**
 * @brief	Inactivate markitem
 */
void DxfPainter::ClearMarkItem(int morph)
{
	Q_FOREACH(QGraphicsItem *item, m_dxfScene->items()) {
		if (item->type() == DXF_MARK) {
			if (MARK_PTR_CAST(item)->Morph() == morph) { delete item; }
		}
	}
}

void DxfPainter::SampleOfL2LDist()
{
	QVector<QPointF> ctrlPosList0, ctrlPosList1;

	DXFPolylineItem *line0 = POLY_PTR_CAST(m_dxfScene->selectedItems().first());
	DXFPolylineItem *line1 = POLY_PTR_CAST(m_dxfScene->selectedItems().last());

	QPointF ls0, le0;
	ls0 = line0->PolygonF().first();
	le0 = line0->PolygonF().last();

	double _d0 = P_DISTANCE(ls0, le0);
	double length0 = qSqrt(_d0);

	if (_d0 <= Global::g_camViewField) { ctrlPosList0 << ls0 << le0; }
	else {		// long
		int count = qCeil(length0 / Global::g_camViewField) + 1;

		if (le0.x() - ls0.x() == 0) {
			double deltaY = (le0.y() - ls0.y()) / count;
			
			for (int i = 0; i < count + 1; ++i) {
				double increase = (double)i * deltaY;
				QPointF p;
				p.setX(ls0.x());
				p.setY(ls0.y() + increase);
				ctrlPosList0 << p;
			}
		}
		else {
			double slope = (le0.y() - ls0.y()) / (le0.x() - ls0.x());
			double deltaX = (le0.x() - ls0.x()) / count;

			for (int i = 0; i < count + 1; ++i) {
				double increase = (double)i * deltaX;
				QPointF p;
				p.setX(ls0.x() + increase);
				p.setY(ls0.y() + increase*slope);
				ctrlPosList0 << p;
			}
		}
	}
	line0->SetProcessed();

	QPointF ls1, le1;
	ls1 = line1->PolygonF().first();
	le1 = line1->PolygonF().last();

	double _d1 = P_DISTANCE(ls1, le1);
	double length1 = qSqrt(_d1);

	if (_d1 <= Global::g_camViewField) {
		ctrlPosList1 << ls1 << le1;
	}
	else {		// long
		int count = qCeil(length1 / Global::g_camViewField) + 1;

		if (le1.x() - ls1.x() == 0) {
			double deltaY = (le1.y() - ls1.y()) / count;

			for (int i = 0; i < count + 1; ++i) {
				double increase = (double)i * deltaY;
				QPointF p;
				p.setX(ls1.x());
				p.setY(ls1.y() + increase);
				ctrlPosList1 << p;
			}
		}
		else {
			double slope = (le1.y() - ls1.y()) / (le1.x() - ls1.x());
			double deltaX = (le1.x() - ls1.x()) / count;

			for (int i = 0; i < count + 1; ++i) {
				double increase = (double)i * deltaX;
				QPointF p;
				p.setX(ls1.x() + increase);
				p.setY(ls1.y() + increase*slope);
				ctrlPosList1 << p;
			}
		}
	}
	line1->SetProcessed();

	CAMERAITEM lineItem;
	double d1, d2, d3, d4, min;
	d1 = P_DISTANCE(ctrlPosList0.first(), ctrlPosList1.first());
	d2 = P_DISTANCE(ctrlPosList0.first(), ctrlPosList1.last());
	d3 = P_DISTANCE(ctrlPosList0.last(), ctrlPosList1.first());
	d4 = P_DISTANCE(ctrlPosList0.last(), ctrlPosList1.last());
	min = qMin(qMin(d1, d2), qMin(d3, d4));

	if (min == d1) {
		while (!ctrlPosList0.isEmpty()) { lineItem.cadPosList << ctrlPosList0.takeLast(); }
		lineItem.cadPosList << ctrlPosList1;
	}
	else if (min == d2) {
		while (!ctrlPosList0.isEmpty()) { lineItem.cadPosList << ctrlPosList0.takeLast(); }
		while (!ctrlPosList1.isEmpty()) { lineItem.cadPosList << ctrlPosList1.takeLast(); }
	}
	else if (min == d3) { lineItem.cadPosList << ctrlPosList0 << ctrlPosList1; }
	else {
		lineItem.cadPosList << ctrlPosList0;
		while (!ctrlPosList1.isEmpty()) { lineItem.cadPosList << ctrlPosList1.takeLast(); }
	}

	lineItem.nType = MeasureType::L2LD;
	Global::g_projectInfo.camItemList.append(lineItem);

	emit NodeListTableUpdate();
}

void DxfPainter::SampleTheL2LAngle()
{
	QVector<QPointF> ctrlPosList0, ctrlPosList1;

	DXFPolylineItem *line0 = POLY_PTR_CAST(m_dxfScene->selectedItems().first());
	DXFPolylineItem *line1 = POLY_PTR_CAST(m_dxfScene->selectedItems().last());

	QPointF ls0, le0;
	ls0 = line0->PolygonF().first();
	le0 = line0->PolygonF().last();

	double _d0 = P_DISTANCE(ls0, le0);
	double length0 = qSqrt(_d0);

	if (_d0 <= Global::g_camViewField) { ctrlPosList0 << ls0 << le0; }
	else {		// long
		int count = qCeil(length0 / Global::g_camViewField) + 1;

		if (le0.x() - ls0.x() == 0) {
			double deltaY = (le0.y() - ls0.y()) / count;

			for (int i = 0; i < count + 1; ++i) {
				double increase = (double)i * deltaY;
				QPointF p;
				p.setX(ls0.x());
				p.setY(ls0.y() + increase);
				ctrlPosList0 << p;
			}
		}
		else {
			double slope = (le0.y() - ls0.y()) / (le0.x() - ls0.x());
			double deltaX = (le0.x() - ls0.x()) / count;

			for (int i = 0; i < count + 1; ++i) {
				double increase = (double)i * deltaX;
				QPointF p;
				p.setX(ls0.x() + increase);
				p.setY(ls0.y() + increase*slope);
				ctrlPosList0 << p;
			}
		}
	}
	line0->SetProcessed();

	QPointF ls1, le1;
	ls1 = line1->PolygonF().first();
	le1 = line1->PolygonF().last();

	double _d1 = P_DISTANCE(ls1, le1);
	double length1 = qSqrt(_d1);

	if (_d1 <= Global::g_camViewField) {
		ctrlPosList1 << ls1 << le1;
	}
	else {		// long
		int count = qCeil(length1 / Global::g_camViewField) + 1;

		if (le1.x() - ls1.x() == 0) {
			double deltaY = (le1.y() - ls1.y()) / count;

			for (int i = 0; i < count + 1; ++i) {
				double increase = (double)i * deltaY;
				QPointF p;
				p.setX(ls1.x());
				p.setY(ls1.y() + increase);
				ctrlPosList1 << p;
			}
		}
		else {
			double slope = (le1.y() - ls1.y()) / (le1.x() - ls1.x());
			double deltaX = (le1.x() - ls1.x()) / count;

			for (int i = 0; i < count + 1; ++i) {
				double increase = (double)i * deltaX;
				QPointF p;
				p.setX(ls1.x() + increase);
				p.setY(ls1.y() + increase*slope);
				ctrlPosList1 << p;
			}
		}
	}
	line1->SetProcessed();
	
	CAMERAITEM lineItem;
	double d1, d2, d3, d4, min;
	d1 = P_DISTANCE(ctrlPosList0.first(), ctrlPosList1.first());
	d2 = P_DISTANCE(ctrlPosList0.first(), ctrlPosList1.last());
	d3 = P_DISTANCE(ctrlPosList0.last(), ctrlPosList1.first());
	d4 = P_DISTANCE(ctrlPosList0.last(), ctrlPosList1.last());
	min = qMin(qMin(d1, d2), qMin(d3, d4));
	
	if (min == d1) {
		while (!ctrlPosList0.isEmpty()) { lineItem.cadPosList << ctrlPosList0.takeLast(); }
		lineItem.cadPosList << ctrlPosList1;
	}
	else if (min == d2) {
		while (!ctrlPosList0.isEmpty()) { lineItem.cadPosList << ctrlPosList0.takeLast(); }
		while (!ctrlPosList1.isEmpty()) { lineItem.cadPosList << ctrlPosList1.takeLast(); }
	}
	else if (min == d3) { lineItem.cadPosList << ctrlPosList0 << ctrlPosList1; }
	else {
		lineItem.cadPosList << ctrlPosList0;
		while (!ctrlPosList1.isEmpty()) { lineItem.cadPosList << ctrlPosList1.takeLast(); }
	}

	lineItem.nType = MeasureType::L2LA;
	Global::g_projectInfo.camItemList.append(lineItem);

	emit NodeListTableUpdate();
}

void DxfPainter::SampleTheP2PDist()
{
	QVector<QPointF> ctrlPosList0, ctrlPosList1;
	bool isBig0, isBig1;

	DXFEllipseItem *ellipse0 = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().first());
	DXFEllipseItem *ellipse1 = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().last());

	if ((ellipse0->LALength() == ellipse0->SALength()) && (ellipse1->LALength() == ellipse1->SALength())) {
		if (2 * ellipse0->LALength() <= Global::g_camViewField) {
			QPointF p;
			p.setX(ellipse0->pos().x());
			p.setY(ellipse0->pos().y());
			ctrlPosList0 << p;
			isBig0 = false;
		}
		else {
			double halfStepAngle = qRadiansToDegrees(qAsin(Global::g_camViewField / 2.0 /
				ellipse0->LALength()));
			if (ellipse0->SpanAngle() >= 360.0) {	// closed circle
				double splitNo = qCeil(360.0 / halfStepAngle / 2.0) + 1;
				double stepAngle = 360.0 / splitNo;
				
				for (int i = 0; i < splitNo; ++i) {
					double angle = stepAngle*i + 0.0;
					QPointF p;
					p.setX(ellipse0->pos().x() + ellipse0->LALength() * qCos(qDegreesToRadians(angle)));
					p.setY(ellipse0->pos().y() + ellipse0->LALength() * qSin(qDegreesToRadians(angle)));
					ctrlPosList0 << p;
				}
			}
			else {		// open arc
				double splitNo = qCeil(ellipse0->SpanAngle() / halfStepAngle / 2.0) + 1;
				double stepAngle = ellipse0->SpanAngle() / splitNo;
				
				for (int i = 0; i < splitNo + 1; ++i) {
					QPointF p;
					if (0 == i) {
						p.setX(ellipse0->pos().x() + ellipse0->LALength() *
							qCos(qDegreesToRadians(ellipse0->StartAngle())));
						p.setY(ellipse0->pos().y() + ellipse0->LALength() *
							qSin(qDegreesToRadians(ellipse0->StartAngle())));
					}
					else if (splitNo == i) {
						p.setX(ellipse0->pos().x() + ellipse0->LALength() *
							qCos(qDegreesToRadians(ellipse0->EndAngle())));
						p.setY(ellipse0->pos().y() + ellipse0->LALength() *
							qSin(qDegreesToRadians(ellipse0->EndAngle())));
					}
					else {
						double angle = ellipse0->StartAngle() + stepAngle*i;
						p.setX(ellipse0->pos().x() + ellipse0->LALength() *
							qCos(qDegreesToRadians(angle)));
						p.setY(ellipse0->pos().y() + ellipse0->LALength() *
							qSin(qDegreesToRadians(angle)));
					}
					ctrlPosList0 << p;
				}
			}
			isBig0 = true;
		}
		ellipse0->SetProcessed();
		
		if (2 * ellipse1->LALength() <= Global::g_camViewField) {
			QPointF p;
			p.setX(ellipse1->pos().x());
			p.setY(ellipse1->pos().y());
			ctrlPosList1 << p;
			isBig1 = false;
		}
		else {
			double halfStepAngle = qRadiansToDegrees(qAsin(Global::g_camViewField / 2.0 /
				ellipse1->LALength()));
			if (ellipse1->SpanAngle() >= 360.0) {	// closed circle
				double splitNo = qCeil(360.0 / halfStepAngle / 2.0) + 1;
				double stepAngle = 360.0 / splitNo;
				
				for (int i = 0; i < splitNo; ++i) {
					double angle = stepAngle*i + 0.0;
					QPointF p;
					p.setX(ellipse1->pos().x() + ellipse0->LALength() * qCos(qDegreesToRadians(angle)));
					p.setY(ellipse1->pos().y() + ellipse0->LALength() * qSin(qDegreesToRadians(angle)));
					ctrlPosList1 << p;
				}
			}
			else {		// open arc
				double splitNo = qCeil(ellipse1->SpanAngle() / halfStepAngle / 2.0) + 1;
				double stepAngle = ellipse1->SpanAngle() / splitNo;
				
				for (int i = 0; i < splitNo + 1; ++i) {
					QPointF p;
					if (0 == i) {
						p.setX(ellipse1->pos().x() + ellipse1->LALength() *
							qCos(qDegreesToRadians(ellipse1->StartAngle())));
						p.setY(ellipse1->pos().y() + ellipse1->LALength() *
							qSin(qDegreesToRadians(ellipse1->StartAngle())));
					}
					else if (splitNo == i) {
						p.setX(ellipse1->pos().x() + ellipse1->LALength() *
							qCos(qDegreesToRadians(ellipse1->EndAngle())));
						p.setY(ellipse1->pos().y() + ellipse1->LALength() *
							qSin(qDegreesToRadians(ellipse1->EndAngle())));
					}
					else {
						double angle = ellipse1->StartAngle() + stepAngle*i;
						p.setX(ellipse1->pos().x() + ellipse1->LALength() *
							qCos(qDegreesToRadians(angle)));
						p.setY(ellipse1->pos().y() + ellipse1->LALength() *
							qSin(qDegreesToRadians(angle)));
					}
					ctrlPosList1 << p;
				}
			}
			isBig1 = true;
		}
		ellipse1->SetProcessed();

		CAMERAITEM ellipseItem;
		if (isBig0 && isBig1) {
			double d1, d2, d3, d4, min;
			d1 = P_DISTANCE(ctrlPosList0.first(), ctrlPosList1.first());
			d2 = P_DISTANCE(ctrlPosList0.first(), ctrlPosList1.last());
			d3 = P_DISTANCE(ctrlPosList0.last(), ctrlPosList1.first());
			d4 = P_DISTANCE(ctrlPosList0.last(), ctrlPosList1.last());
			min = qMin(qMin(d1, d2), qMin(d3, d4));
			if (min == d1) {
				while (!ctrlPosList0.isEmpty()) { ellipseItem.cadPosList << ctrlPosList0.takeLast(); }
				ellipseItem.cadPosList << ctrlPosList1;
			}
			else if (min == d2) {
				while (!ctrlPosList0.isEmpty()) { ellipseItem.cadPosList << ctrlPosList0.takeLast(); }
				while (!ctrlPosList1.isEmpty()) { ellipseItem.cadPosList << ctrlPosList1.takeLast(); }
			}
			else if (min == d3) {
				ellipseItem.cadPosList << ctrlPosList0 << ctrlPosList1; }
			else {
				ellipseItem.cadPosList << ctrlPosList0;
				while (!ctrlPosList1.isEmpty()) { ellipseItem.cadPosList << ctrlPosList1.takeLast(); }
			}
		}
		if (isBig0 && !isBig1) {
			double d1, d2, d3, d4, min;
			d1 = P_DISTANCE(ctrlPosList0.first(), ctrlPosList1.first());
			d2 = P_DISTANCE(ctrlPosList0.last(), ctrlPosList1.first());
			if (d1 <= d2) {
				while (!ctrlPosList0.isEmpty()) { ellipseItem.cadPosList << ctrlPosList0.takeLast(); }
				ellipseItem.cadPosList << ctrlPosList1; }
			else { ellipseItem.cadPosList << ctrlPosList0 << ctrlPosList1; }
		}
		if (!isBig0 && isBig1) {
			double d1, d2, d3, d4, min;
			d1 = P_DISTANCE(ctrlPosList1.first(), ctrlPosList0.first());
			d2 = P_DISTANCE(ctrlPosList1.last(), ctrlPosList0.first());
			if (d1 <= d2) {
				while (!ctrlPosList1.isEmpty()) { ellipseItem.cadPosList << ctrlPosList1.takeLast(); }
				ellipseItem.cadPosList << ctrlPosList0; }
			else {
				ellipseItem.cadPosList << ctrlPosList1 << ctrlPosList0; }
		}
		if (!isBig0 && !isBig1) { ellipseItem.cadPosList << ctrlPosList0 << ctrlPosList1; }

		ellipseItem.nType = MeasureType::P2PD;
		Global::g_projectInfo.camItemList.append(ellipseItem);

		emit NodeListTableUpdate();
	}
}

void DxfPainter::SampleTheP2LDist()
{
	QVector<QPointF> ctrlPosList, lineCtrlPosList;
	bool isBig;

	Q_FOREACH(QGraphicsItem *item, m_dxfScene->selectedItems()) {
		if (item->type() == DXF_ELLIPSE) {
			DXFEllipseItem *ellipse = ELLIPSE_PTR_CAST(item);
			if ((ellipse->LALength() != ellipse->SALength())) { return; }

			if (2 * ellipse->LALength() <= Global::g_camViewField) {
				QPointF p;
				p.setX(ellipse->pos().x());
				p.setY(ellipse->pos().y());
				ctrlPosList << p;
				isBig = false;
			}
			else {
				double halfStepAngle = qRadiansToDegrees(qAsin(Global::g_camViewField / 2.0 /
					ellipse->LALength()));
				if (ellipse->SpanAngle() >= 360.0) {	// closed circle
					double splitNo = qCeil(360.0 / halfStepAngle / 2.0) + 1;
					double stepAngle = 360.0 / splitNo;

					for (int i = 0; i < splitNo; ++i) {
						double angle = stepAngle*i + 0.0;
						QPointF p;
						p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(angle)));
						p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(angle)));
						ctrlPosList << p;
					}
				}
				else {		// open arc
					double splitNo = qCeil(ellipse->SpanAngle() / halfStepAngle / 2.0) + 1;
					double stepAngle = ellipse->SpanAngle() / splitNo;

					for (int i = 0; i < splitNo + 1; ++i) {
						QPointF p;
						if (0 == i) {
							p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(ellipse->StartAngle())));
							p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(ellipse->StartAngle())));
						}
						else if (splitNo == i) {
							p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(ellipse->EndAngle())));
							p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(ellipse->EndAngle())));
						}
						else {
							double angle = ellipse->StartAngle() + stepAngle*i;
							p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(angle)));
							p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(angle)));
						}
						ctrlPosList << p;
					}
				}
				isBig = true;
			}
			ellipse->SetProcessed();
		}
		else{
			DXFPolylineItem *line = POLY_PTR_CAST(item);
			QPointF ls, le;
			ls = line->PolygonF().first();
			le = line->PolygonF().last();

			double d = P_DISTANCE(ls, le);
			double length = qSqrt(d);

			if (d <= Global::g_camViewField) {		// short
				lineCtrlPosList << ls << le;
			}
			else {		// long
				double slope = (le.y() - ls.y()) / (le.x() - ls.x());
				int count = qCeil(length / Global::g_camViewField) + 1;
				double deltaX = (le.x() - ls.x()) / count;

				for (int i = 0; i < count + 1; ++i) {
					double increase = (double)i * deltaX;
					QPointF p;
					p.setX(ls.x() + increase);
					p.setY(ls.y() + increase*slope);
					lineCtrlPosList << p;
				}
			}
			line->SetProcessed();
		}
	}
	
	CAMERAITEM item;
	if (isBig) {
		double d1, d2, d3, d4, min;
		d1 = P_DISTANCE(ctrlPosList.first(), lineCtrlPosList.first());
		d2 = P_DISTANCE(ctrlPosList.first(), lineCtrlPosList.last());
		d3 = P_DISTANCE(ctrlPosList.last(), lineCtrlPosList.first());
		d4 = P_DISTANCE(ctrlPosList.last(), lineCtrlPosList.last());
		min = qMin(qMin(d1, d2), qMin(d3, d4));
		if (min == d1) {
			while (!ctrlPosList.isEmpty()) { item.cadPosList << ctrlPosList.takeLast(); }
			item.cadPosList << lineCtrlPosList;
		}
		else if (min == d2) {
			while (!ctrlPosList.isEmpty()) { item.cadPosList << ctrlPosList.takeLast(); }
			while (!lineCtrlPosList.isEmpty()) { item.cadPosList << lineCtrlPosList.takeLast(); }
		}
		else if (min == d3) { item.cadPosList << ctrlPosList << lineCtrlPosList; }
		else {
			item.cadPosList << ctrlPosList;
			while (!lineCtrlPosList.isEmpty()) { item.cadPosList << lineCtrlPosList.takeLast(); }
		}
	}
	else {
		double d1, d2, d3, d4, min;
		d1 = P_DISTANCE(ctrlPosList.first(), lineCtrlPosList.first());
		d2 = P_DISTANCE(ctrlPosList.first(), lineCtrlPosList.last());
		if (d1 <= d2) { item.cadPosList << ctrlPosList << lineCtrlPosList; }
		else {
			item.cadPosList << ctrlPosList;
			while (!lineCtrlPosList.isEmpty()) { item.cadPosList << lineCtrlPosList.takeLast(); }
		}
	}

	item.nType = MeasureType::P2LD;
	Global::g_projectInfo.camItemList.append(item);

	emit NodeListTableUpdate();
}

void DxfPainter::SampleTheRadius()
{
	DXFEllipseItem *ellipse = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().first());

	if ((ellipse->LALength() != ellipse->SALength())) { return; }
	QVector<QPointF> ctrlPosList;

	if (2 * ellipse->LALength() <= Global::g_camViewField) {
		QPointF p;
		p.setX(ellipse->pos().x());
		p.setY(ellipse->pos().y());
		ctrlPosList << p;
	}
	else {
		double halfStepAngle = qRadiansToDegrees(qAsin(Global::g_camViewField / 2.0 /
			ellipse->LALength()));
		if (ellipse->SpanAngle() >= 360.0) {	// closed circle
			double splitNo = qCeil(360.0 / halfStepAngle / 2.0) + 1;
			double stepAngle = 360.0 / splitNo;

			for (int i = 0; i < splitNo; ++i) {
				double angle = stepAngle*i + 0.0;
				QPointF p;
				p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(angle)));
				p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(angle)));
				ctrlPosList << p;
			}
		}
		else {		// open arc
			double splitNo = qCeil(ellipse->SpanAngle() / halfStepAngle / 2.0) + 1;
			double stepAngle = ellipse->SpanAngle() / splitNo;

			for (int i = 0; i < splitNo+1; ++i) {
				QPointF p;
				if (0 == i) {
					p.setX(ellipse->pos().x() + ellipse->LALength() *
						qCos(qDegreesToRadians(ellipse->StartAngle())));
					p.setY(ellipse->pos().y() + ellipse->LALength() *
						qSin(qDegreesToRadians(ellipse->StartAngle())));
				}
				else if (splitNo == i) {
					p.setX(ellipse->pos().x() + ellipse->LALength() *
						qCos(qDegreesToRadians(ellipse->EndAngle())));
					p.setY(ellipse->pos().y() + ellipse->LALength() *
						qSin(qDegreesToRadians(ellipse->EndAngle())));
				}
				else {
					double angle = ellipse->StartAngle() + stepAngle*i;
					p.setX(ellipse->pos().x() + ellipse->LALength() *
						qCos(qDegreesToRadians(angle)));
					p.setY(ellipse->pos().y() + ellipse->LALength() *
						qSin(qDegreesToRadians(angle)));
				}
				ctrlPosList << p;
			}
		}
	}
	ellipse->SetProcessed();

	CAMERAITEM ellipseItem;
	ellipseItem.cadPosList << ctrlPosList;

	ellipseItem.nType = MeasureType::RAD;
	Global::g_projectInfo.camItemList.append(ellipseItem);

	emit NodeListTableUpdate();
}

void DxfPainter::SampleTheArcAngle()
{
	DXFEllipseItem *ellipse = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().first());

	if ((ellipse->LALength() != ellipse->SALength())) { return; }
	QVector<QPointF> ctrlPosList;

	if (2 * ellipse->LALength() <= Global::g_camViewField) {
		QPointF p;
		p.setX(ellipse->pos().x());
		p.setY(ellipse->pos().y());
		ctrlPosList << p;
	}
	else {
		double halfStepAngle = qRadiansToDegrees(qAsin(Global::g_camViewField / 2.0 /
			ellipse->LALength()));
		if (ellipse->SpanAngle() >= 360.0) {	// closed circle
			double splitNo = qCeil(360.0 / halfStepAngle / 2.0) + 1;
			double stepAngle = 360.0 / splitNo;

			for (int i = 0; i < splitNo; ++i) {
				double angle = stepAngle*i + 0.0;
				QPointF p;
				p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(angle)));
				p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(angle)));
				ctrlPosList << p;
			}
		}
		else {		// open arc
			double splitNo = qCeil(ellipse->SpanAngle() / halfStepAngle / 2.0) + 1;
			double stepAngle = ellipse->SpanAngle() / splitNo;

			for (int i = 0; i < splitNo + 1; ++i) {
				QPointF p;
				if (0 == i) {
					p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(ellipse->StartAngle())));
					p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(ellipse->StartAngle())));
				}
				else if (splitNo == i) {
					p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(ellipse->EndAngle())));
					p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(ellipse->EndAngle())));
				}
				else {
					double angle = ellipse->StartAngle() + stepAngle*i;
					p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(angle)));
					p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(angle)));
				}
				ctrlPosList << p;
			}
		}
	}
	ellipse->SetProcessed();

	CAMERAITEM ellipseItem;
	ellipseItem.cadPosList << ctrlPosList;

	ellipseItem.nType = MeasureType::AA;
	Global::g_projectInfo.camItemList.append(ellipseItem);

	emit NodeListTableUpdate();
}

void DxfPainter::SampleTheCircular()
{
	DXFEllipseItem *ellipse = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().first());

	if ((ellipse->LALength() != ellipse->SALength())) { return; }
	QVector<QPointF> ctrlPosList;

	if (2 * ellipse->LALength() <= Global::g_camViewField) {
		QPointF p;
		p.setX(ellipse->pos().x());
		p.setY(ellipse->pos().y());
	}
	else {
		double halfStepAngle = qRadiansToDegrees(qAsin(Global::g_camViewField / 2.0 /
			ellipse->LALength()));
		if (ellipse->SpanAngle() >= 360.0) {	// closed circle
			double splitNo = qCeil(360.0 / halfStepAngle / 2.0) + 1;
			double stepAngle = 360.0 / splitNo;

			for (int i = 0; i < splitNo; ++i) {
				double angle = stepAngle*i + 0.0;
				QPointF p;
				p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(angle)));
				p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(angle)));
				ctrlPosList << p;
			}
		}
		else {		// open arc
			double splitNo = qCeil(ellipse->SpanAngle() / halfStepAngle / 2.0) + 1;
			double stepAngle = ellipse->SpanAngle() / splitNo;

			for (int i = 0; i < splitNo + 1; ++i) {
				QPointF p;
				if (0 == i) {
					p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(ellipse->StartAngle())));
					p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(ellipse->StartAngle())));
				}
				else if (splitNo == i) {
					p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(ellipse->EndAngle())));
					p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(ellipse->EndAngle())));
				}
				else {
					double angle = ellipse->StartAngle() + stepAngle*i;
					p.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(angle)));
					p.setY(ellipse->pos().y() + ellipse->LALength() * qSin(qDegreesToRadians(angle)));
				}
				ctrlPosList << p;
			}
		}
	}
	ellipse->SetProcessed();

	CAMERAITEM ellipseItem;
	ellipseItem.cadPosList << ctrlPosList;

	ellipseItem.nType = MeasureType::CIC;
	Global::g_projectInfo.camItemList.append(ellipseItem);

	emit NodeListTableUpdate();
}

void DxfPainter::SampleOfLength()
{
	DXFPolylineItem *line = POLY_PTR_CAST(m_dxfScene->selectedItems().first());

	QPointF ls, le;
	ls = line->PolygonF().first();
	le = line->PolygonF().last();
	double d = P_DISTANCE(ls, le);
	double length = qSqrt(d);

	CAMERAITEM lineItem;
	if (d <= Global::g_camViewField) { lineItem.cadPosList << ls << le; }
	else {
		double slope = (le.y() - ls.y()) / (le.x() - ls.x());
		int count = qCeil(length / Global::g_camViewField) + 1;
		double deltaX = (le.x() - ls.x()) / count;

		for (int i = 0; i < count + 1; ++i) {
			double increase = (double)i * deltaX;
			QPointF p;
			p.setX(ls.x() + increase);
			p.setY(ls.y() + increase*slope);
			lineItem.cadPosList << p;
		}
	}
	line->SetProcessed();

	lineItem.nType = MeasureType::LEN;
	Global::g_projectInfo.camItemList.append(lineItem);

	emit NodeListTableUpdate();
}

void DxfPainter::SampleTheStraightness()
{
	DXFPolylineItem *line = POLY_PTR_CAST(m_dxfScene->selectedItems().first());

	QPointF ls, le;
	ls = line->PolygonF().first();
	le = line->PolygonF().last();
	double d = P_DISTANCE(ls, le);
	double length = qSqrt(d);
	
	CAMERAITEM lineItem;
	if (d <= Global::g_camViewField){ lineItem.cadPosList << ls << le; }
	else {
		double slope = (le.y() - ls.y()) / (le.x() - ls.x());
		int count = qCeil(length / Global::g_camViewField ) + 1;
		double deltaX = (le.x() - ls.x())/ count;

		for (int i = 0; i < count + 1; ++i) {
			double increase = (double)i * deltaX;
			QPointF p;
			p.setX(ls.x() + increase);
			p.setY(ls.y() + increase*slope);
			lineItem.cadPosList << p;
		}
	}
	line->SetProcessed();

	lineItem.nType = MeasureType::STN;
	Global::g_projectInfo.camItemList.append(lineItem);

	emit NodeListTableUpdate();
}

void DxfPainter::SampleTheHeight()
{
	LASERITEM laserItem;
	Q_FOREACH(QGraphicsItem *item, m_dxfScene->selectedItems()) {
		MARK_PTR_CAST(item)->SetProcessed();
		laserItem.cadPosList.append(item->pos());
	}

	laserItem.nType = MeasureType::FTN;
	Global::g_projectInfo.laserItemList.append(laserItem);

	emit NodeListTableUpdate();
}
