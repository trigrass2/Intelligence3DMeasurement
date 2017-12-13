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
	m_zoomRatio(1.0), m_zoomMax(8), m_zoomMin(0.8), m_zoomStep(0.1),
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
			connect(contextMenu.addAction("线 - 线：夹角"), SIGNAL(triggered(bool)), this, SLOT(SampleOfL2LAngle()));
		}
		else if (items.first()->type() == DXF_ELLIPSE && items.last()->type() == DXF_ELLIPSE) {
			connect(contextMenu.addAction("点 - 点：间距"), SIGNAL(triggered(bool)), this, SLOT(SampleOfP2PDist()));
		}
		else if ((items.first()->type() == DXF_ELLIPSE && items.last()->type() == DXF_POLY) ||
			(items.first()->type() == DXF_POLY && items.last()->type() == DXF_ELLIPSE)) {
			connect(contextMenu.addAction("点 - 线：间距"), SIGNAL(triggered(bool)), this, SLOT(SampleOfP2LDist()));
		}
		else if (items.first()->type() == DXF_MARK && items.last()->type() == DXF_MARK) {
			connect(contextMenu.addAction("激光测高"), SIGNAL(triggered(bool)), this, SLOT(SampleOfHeight()));
		}
		contextMenu.exec(QCursor::pos());
	}
	else if (items.count() == 1) {
		if (items.first()->type() == DXF_ELLIPSE) {
			connect(contextMenu.addAction("半径"), SIGNAL(triggered(bool)), this, SLOT(SampleOfRadius()));
			connect(contextMenu.addAction("弧角"), SIGNAL(triggered(bool)), this, SLOT(SampleOfArcAngle()));
			connect(contextMenu.addAction("圆度"), SIGNAL(triggered(bool)), this, SLOT(SampleOfCircular()));
		}
		else if (items.first()->type() == DXF_POLY) {
			connect(contextMenu.addAction("长度"), SIGNAL(triggered(bool)), this, SLOT(SampleOfLength()));
			connect(contextMenu.addAction("直线度"), SIGNAL(triggered(bool)), this, SLOT(SampleOfStraightness()));
		}
		else if (items.first()->type() == DXF_MARK) {
			connect(contextMenu.addAction("激光测高"), SIGNAL(triggered(bool)), this, SLOT(SampleOfHeight()));
		}
		contextMenu.exec(QCursor::pos());
	}
	else if (items.count() > 2) {
		bool isLaser = true;
		Q_FOREACH(QGraphicsItem *item, m_dxfScene->selectedItems()) {
			if (item->type() != DXF_MARK) { isLaser = false; }
		}
		if (isLaser) {
			connect(contextMenu.addAction("激光测高"), SIGNAL(triggered(bool)), this, SLOT(SampleOfHeight()));
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
	Global::g_projectInfo.camSequence.clear();
	QList<CAMERAITEM> items(Global::g_projectInfo.camearItems.toList());
	QPointF previousNode(begin);
	int n = items.count();
	while (n--) {
		int index;
		double min = INT_MAX;
		bool isInverted = false;
		for (int i = 0; i < items.count(); ++i) {
			qDebug() << "item->"<<items.at(i).nTemp <<"//"<< items.at(i).nHeight;
			if (items.at(i).nTemp != 1) {
				double d0 = P_DISTANCE(previousNode, items.at(i).ctrlNodes.first());
				double d1 = P_DISTANCE(previousNode, items.at(i).ctrlNodes.last());
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
		if (isInverted) { previousNode = items.at(index).ctrlNodes.first(); }
		else{ previousNode = items.at(index).ctrlNodes.last(); }
		items[index].nTemp = 1;		// processed
		Global::g_projectInfo.camSequence.append(index);
		Global::g_projectInfo.camearItems[index].bIsInverted = isInverted;
	}

	Global::g_projectInfo.startPoint = begin;
	LoadPathItem();
}
/**
 * @brief	Add pathitem
 */
void DxfPainter::LoadPathItem()
{
	QVector<QPointF> path, path1;

	path.append(Global::g_projectInfo.startPoint);
	Q_FOREACH(int sqc, Global::g_projectInfo.camSequence) {
		if (Global::g_projectInfo.camearItems.at(sqc).bIsInverted) {
			for (int i = Global::g_projectInfo.camearItems.at(sqc).ctrlNodes.count() - 1; i >= 0; --i) {
				path << Global::g_projectInfo.camearItems.at(sqc).ctrlNodes.at(i);
			}
		}
		else {
			path << Global::g_projectInfo.camearItems.at(sqc).ctrlNodes;
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
	Q_FOREACH(LASERITEM item, Global::g_projectInfo.laserItems) {
		for (int i = 0; i < item.nodes.count(); ++i) {
			MarkItem *laserItem = new MarkItem(1);
			laserItem->setPos(item.nodes.at(i));
			laserItem->SetProcessed();
			m_dxfScene->addItem(laserItem);
		}
		path1.append(item.nodes);
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
	QString path = CAD_DIRECTORY + Global::g_projectInfo.cadFile;
	EntitiesParser4DXF *entities = new EntitiesParser4DXF(path);
	entities->covPolyline2Line();		// disable polyline

	if (isCleanOpen) {
		Global::g_projectInfo.camSequence.clear();
		Global::g_projectInfo.camearItems.clear();
		Global::g_projectInfo.laserItems.clear();
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

	Global::g_projectInfo.camSequence.clear();
	Global::g_projectInfo.camearItems.clear();
	Global::g_projectInfo.laserItems.clear();
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
	int camCount = Global::g_projectInfo.camearItems.count();
	if (index.row() < camCount) {
		Q_FOREACH(QPointF p, Global::g_projectInfo.camearItems.at(index.row()).ctrlNodes) {
			MarkItem *mark = new MarkItem();
			mark->setPos(p);
			m_dxfScene->addItem(mark);
		}
	}
	else {
		Q_FOREACH(QPointF p, Global::g_projectInfo.laserItems.at(index.row() - camCount).nodes) {
			MarkItem *mark = new MarkItem();
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
/**
 * @brief	Line to line distance
 */
void DxfPainter::SampleOfL2LDist()
{
	DXFPolylineItem *line0 = POLY_PTR_CAST(m_dxfScene->selectedItems().first());
	DXFPolylineItem *line1 = POLY_PTR_CAST(m_dxfScene->selectedItems().last());
	
	QPointF line0S, line0E, line1S, line1E;
	line0S = line0->PolygonF().first();
	line0E = line0->PolygonF().last();
	line1S = line1->PolygonF().first();
	line1E = line1->PolygonF().last();
	line0->SetProcessed();
	line1->SetProcessed();

	// shortest(local) path connection
	double d1, d2, d3, d4, min;
	d1 = P_DISTANCE(line0S, line1S);
	d2 = P_DISTANCE(line0S, line1E);
	d3 = P_DISTANCE(line0E, line1S);
	d4 = P_DISTANCE(line0E, line1E);
	min = qMin(qMin(d1, d2), qMin(d3, d4));
	CAMERAITEM lineItem;
	if (min == d1) { lineItem.ctrlNodes << line0E << line0S << line1S << line1E; }
	else if (min == d2) { lineItem.ctrlNodes << line0E << line0S << line1E << line1S; }
	else if (min == d3) { lineItem.ctrlNodes << line0S << line0E << line1S << line1E; }
	else { lineItem.ctrlNodes << line0S << line0E << line1E << line1S; }

	lineItem.type = MeasureType::L2LD;
	lineItem.content = "Line-line distance";
	lineItem.nHeight = 0;
	Global::g_projectInfo.camearItems.append(lineItem);

	emit NodeListTableUpdate();
}
/**
 * @brief	Line to line angle
 */
void DxfPainter::SampleOfL2LAngle()
{
	DXFPolylineItem *line0 = POLY_PTR_CAST(m_dxfScene->selectedItems().first());
	DXFPolylineItem *line1 = POLY_PTR_CAST(m_dxfScene->selectedItems().last());

	QPointF line0S, line0E, line1S, line1E;
	line0S = line0->PolygonF().first();
	line0E = line0->PolygonF().last();
	line1S = line1->PolygonF().first();
	line1E = line1->PolygonF().last();
	line0->SetProcessed();
	line1->SetProcessed();

	// minor angle connection
	double d1, d2, d3, d4, min;
	d1 = P_DISTANCE(line0S, line1S);
	d2 = P_DISTANCE(line0S, line1E);
	d3 = P_DISTANCE(line0E, line1S);
	d4 = P_DISTANCE(line0E, line1E);
	min = qMin(qMin(d1, d2), qMin(d3, d4));
	CAMERAITEM lineItem;
	if (min == d1) { lineItem.ctrlNodes << line0E << line0S << line1S << line1E; }
	else if (min == d2) { lineItem.ctrlNodes << line0E << line0S << line1E << line1S; }
	else if (min == d3) { lineItem.ctrlNodes << line0S << line0E << line1S << line1E; }
	else { lineItem.ctrlNodes << line0S << line0E << line1E << line1S; }

	lineItem.type = MeasureType::L2LA;
	lineItem.content = "Line-line angle";
	lineItem.nHeight = 0;
	Global::g_projectInfo.camearItems.append(lineItem);

	emit NodeListTableUpdate();
}
/**
 * @brief	Point to point distance
 */
void DxfPainter::SampleOfP2PDist()
{
	DXFEllipseItem *ellipse0 = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().first());
	DXFEllipseItem *ellipse1 = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().last());

	if ((ellipse0->LALength() == ellipse0->SALength()) && (ellipse1->LALength() == ellipse1->SALength())) {
		QPointF c00, c01, c02, c10, c11, c12;
		bool isBig0, isBig1;

		if (2 * ellipse0->LALength() <= Global::g_camViewField) {
			// one point
			c00.setX(ellipse0->pos().x());
			c00.setY(ellipse0->pos().y());
			isBig0 = false;
		}
		else {
			// three points locate a circle
			if (ellipse0->SpanAngle() >= 360.0) {		// closed circle
				c00.setX(ellipse0->pos().x());
				c00.setY(ellipse0->pos().y() - ellipse0->SALength());
				c01.setX(ellipse0->pos().x() + ellipse0->LALength() * qCos(qDegreesToRadians(30.0)));
				c01.setY(ellipse0->pos().y() + ellipse0->SALength() / 2);
				c02.setX(ellipse0->pos().x() - ellipse0->LALength() * qCos(qDegreesToRadians(30.0)));
				c02.setY(c01.y());
			}
			else {		// open arc
				c00.setX(ellipse0->pos().x() + ellipse0->LALength() *
					qCos(qDegreesToRadians(ellipse0->StartAngle())));
				c00.setY(ellipse0->pos().y() + ellipse0->SALength() *
					qSin(qDegreesToRadians(ellipse0->StartAngle())));
				c01.setX(ellipse0->pos().x() + ellipse0->LALength() *
					qCos(qDegreesToRadians(ellipse0->StartAngle() + ellipse0->SpanAngle() / 2)));
				c01.setY(ellipse0->pos().y() + ellipse0->SALength() *
					qSin(qDegreesToRadians(ellipse0->StartAngle() + ellipse0->SpanAngle() / 2)));
				c02.setX(ellipse0->pos().x() + ellipse0->LALength() *
					qCos(qDegreesToRadians(ellipse0->EndAngle())));
				c02.setY(ellipse0->pos().y() + ellipse0->SALength() *
					qSin(qDegreesToRadians(ellipse0->EndAngle())));
			}
			isBig0 = true;
		}
		ellipse0->SetProcessed();

		if (2 * ellipse1->LALength() <= Global::g_camViewField) {
			c11.setX(ellipse1->pos().x());
			c11.setY(ellipse1->pos().y());
			isBig1 = false;
		}
		else {
			if (ellipse1->SpanAngle() >= 360.0) {
				c10.setX(ellipse1->pos().x());
				c10.setY(ellipse1->pos().y() - ellipse1->SALength());
				c11.setX(ellipse1->pos().x() + ellipse1->LALength() * qCos(qDegreesToRadians(30.0)));
				c11.setY(ellipse1->pos().y() + ellipse1->SALength() / 2);
				c12.setX(ellipse1->pos().x() - ellipse1->LALength() * qCos(qDegreesToRadians(30.0)));
				c12.setY(c11.y());
			}
			else {
				c10.setX(ellipse1->pos().x() + ellipse1->LALength() *
					qCos(qDegreesToRadians(ellipse1->StartAngle())));
				c10.setY(ellipse1->pos().y() + ellipse1->SALength() *
					qSin(qDegreesToRadians(ellipse1->StartAngle())));
				c11.setX(ellipse1->pos().x() + ellipse1->LALength() *
					qCos(qDegreesToRadians(ellipse1->StartAngle() + ellipse1->SpanAngle() / 2)));
				c11.setY(ellipse1->pos().y() + ellipse1->SALength() *
					qSin(qDegreesToRadians(ellipse1->StartAngle() + ellipse1->SpanAngle() / 2)));
				c12.setX(ellipse1->pos().x() + ellipse1->LALength() *
					qCos(qDegreesToRadians(ellipse1->EndAngle())));
				c12.setY(ellipse1->pos().y() + ellipse1->SALength() *
					qSin(qDegreesToRadians(ellipse1->EndAngle())));
			}
			isBig1 = true;
		}
		ellipse1->SetProcessed();

		CAMERAITEM ellipseItem;
		if (isBig0 && isBig1) {
			double d1, d2, d3, d4, min;
			d1 = P_DISTANCE(c00, c10);
			d2 = P_DISTANCE(c00, c12);
			d3 = P_DISTANCE(c02, c10);
			d4 = P_DISTANCE(c02, c12);
			min = qMin(qMin(d1, d2), qMin(d3, d4));
			if (min == d1) { ellipseItem.ctrlNodes << c02 << c01 << c00 << c10 << c11 << c12; }
			else if (min == d2) { ellipseItem.ctrlNodes << c02 << c01 << c00 << c12 << c11 << c10; }
			else if (min == d3) { ellipseItem.ctrlNodes << c00 << c01 << c02 << c10 << c11 << c12; }
			else { ellipseItem.ctrlNodes << c00 << c01 << c02 << c12 << c11 << c10; }
		}
		if (isBig0 && !isBig1) {
			double d1, d2, d3, d4, min;
			d1 = P_DISTANCE(c00, c11);
			d2 = P_DISTANCE(c02, c11);
			if (d1 <= d2) { ellipseItem.ctrlNodes << c02 << c01 << c00 << c11; }
			else { ellipseItem.ctrlNodes << c00 << c01 << c02 << c11; }
		}
		if (!isBig0 && isBig1) {
			double d1, d2, d3, d4, min;
			d1 = P_DISTANCE(c10, c00);
			d2 = P_DISTANCE(c12, c00);
			if (d1 <= d2) { ellipseItem.ctrlNodes << c12 << c11 << c10 << c00; }
			else { ellipseItem.ctrlNodes << c10 << c11 << c12 << c00; }
		}
		if (!isBig0 && !isBig1) { ellipseItem.ctrlNodes << c00 << c11; }

		ellipseItem.type = MeasureType::P2PD;
		ellipseItem.content = "Point-point distance";
		ellipseItem.nHeight = 0;
		Global::g_projectInfo.camearItems.append(ellipseItem);

		emit NodeListTableUpdate();
	}
}
/**
 * @brief	Point to line distance
 */
void DxfPainter::SampleOfP2LDist()
{
	QPointF c0, c1, c2, ls, le;
	bool isBig;
	Q_FOREACH(QGraphicsItem *item, m_dxfScene->selectedItems()) {
		if (item->type() == DXF_ELLIPSE) {
			DXFEllipseItem *ellipse = ELLIPSE_PTR_CAST(item);
			if ((ellipse->LALength() != ellipse->SALength())) { return; }

			if (2 * ellipse->LALength() <= Global::g_camViewField) {
				c0.setX(ellipse->pos().x());
				c0.setY(ellipse->pos().y());
				isBig = false;
			}
			else {
				if (ellipse->SpanAngle() >= 360.0) {		// closed circle
					c0.setX(ellipse->pos().x());
					c0.setY(ellipse->pos().y() - ellipse->SALength());
					c1.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(30.0)));
					c1.setY(ellipse->pos().y() + ellipse->SALength() / 2);
					c2.setX(ellipse->pos().x() - ellipse->LALength() * qCos(qDegreesToRadians(30.0)));
					c2.setY(c1.y());
				}
				else {		// open arc
					c0.setX(ellipse->pos().x() + ellipse->LALength() *
						qCos(qDegreesToRadians(ellipse->StartAngle())));
					c0.setY(ellipse->pos().y() + ellipse->SALength() *
						qSin(qDegreesToRadians(ellipse->StartAngle())));
					c1.setX(ellipse->pos().x() + ellipse->LALength() *
						qCos(qDegreesToRadians(ellipse->StartAngle() + ellipse->SpanAngle() / 2)));
					c1.setY(ellipse->pos().y() + ellipse->SALength() *
						qSin(qDegreesToRadians(ellipse->StartAngle() + ellipse->SpanAngle() / 2)));
					c2.setX(ellipse->pos().x() + ellipse->LALength() *
						qCos(qDegreesToRadians(ellipse->EndAngle())));
					c2.setY(ellipse->pos().y() + ellipse->SALength() *
						qSin(qDegreesToRadians(ellipse->EndAngle())));
				}
				isBig = true;
			}
			ellipse->SetProcessed();
		}
		else{
			DXFPolylineItem *line = POLY_PTR_CAST(item);
			ls = line->PolygonF().first();
			le = line->PolygonF().last();
			line->SetProcessed();
		}
	}
	
	CAMERAITEM item;
	if (isBig) {
		double d1, d2, d3, d4, min;
		d1 = P_DISTANCE(c0, ls);
		d2 = P_DISTANCE(c0, le);
		d3 = P_DISTANCE(c2, ls);
		d4 = P_DISTANCE(c2, le);
		min = qMin(qMin(d1, d2), qMin(d3, d4));
		if (min == d1) { item.ctrlNodes << c2 << c1 << c0 << ls << le; }
		else if (min == d2) { item.ctrlNodes << c2 << c1 << c0 << le << ls; }
		else if (min == d3) { item.ctrlNodes << c0 << c1 << c2 << ls << le; }
		else { item.ctrlNodes << c0 << c1 << c2 << le << ls; }
	}
	else {
		double d1, d2, d3, d4, min;
		d1 = P_DISTANCE(c0, ls);
		d2 = P_DISTANCE(c0, le);
		if (d1 <= d2) { item.ctrlNodes << c0 << ls << le; }
		else { item.ctrlNodes << c0 << le << ls; }
	}

	item.type = MeasureType::P2LD;
	item.content = "Point-line distance";
	item.nHeight = 0;
	Global::g_projectInfo.camearItems.append(item);

	emit NodeListTableUpdate();
}
/**
 * @brief	Radius
 */
void DxfPainter::SampleOfRadius()
{
	DXFEllipseItem *ellipse = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().first());

	if ((ellipse->LALength() != ellipse->SALength())) { return; }
	QPointF c0, c1, c2;
	bool isBig;

	if (2 * ellipse->LALength() <= Global::g_camViewField) {
		c0.setX(ellipse->pos().x());
		c0.setY(ellipse->pos().y());
		isBig = false;
	}
	else {
		if (ellipse->SpanAngle() >= 360.0) {	// closed circle
			c0.setX(ellipse->pos().x());
			c0.setY(ellipse->pos().y() - ellipse->SALength());
			c1.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(30.0)));
			c1.setY(ellipse->pos().y() + ellipse->SALength() / 2);
			c2.setX(ellipse->pos().x() - ellipse->LALength() * qCos(qDegreesToRadians(30.0)));
			c2.setY(c1.y());
		}
		else {		// open arc
			c0.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->StartAngle())));
			c0.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->StartAngle())));
			c1.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->StartAngle() + ellipse->SpanAngle() / 2)));
			c1.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->StartAngle() + ellipse->SpanAngle() / 2)));
			c2.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->EndAngle())));
			c2.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->EndAngle())));
		}
		isBig = true;
	}
	ellipse->SetProcessed();

	CAMERAITEM ellipseItem;
	if (isBig){ ellipseItem.ctrlNodes << c0 << c1 << c2; }
	else { ellipseItem.ctrlNodes << c0; }

	ellipseItem.type = MeasureType::RAD;
	ellipseItem.content = "Radius";
	ellipseItem.nHeight = 0;
	Global::g_projectInfo.camearItems.append(ellipseItem);

	emit NodeListTableUpdate();
}
/**
 * @brief	Arc angle
 */
void DxfPainter::SampleOfArcAngle()
{
	DXFEllipseItem *ellipse = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().first());

	if ((ellipse->LALength() != ellipse->SALength())) { return; }
	QPointF c0, c1, c2;
	bool isBig;

	if (2 * ellipse->LALength() <= Global::g_camViewField) {
		c0.setX(ellipse->pos().x());
		c0.setY(ellipse->pos().y());
		isBig = false;
	}
	else {
		if (ellipse->SpanAngle() >= 360.0) {	// closed circle
			c0.setX(ellipse->pos().x());
			c0.setY(ellipse->pos().y() - ellipse->SALength());
			c1.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(30.0)));
			c1.setY(ellipse->pos().y() + ellipse->SALength() / 2);
			c2.setX(ellipse->pos().x() - ellipse->LALength() * qCos(qDegreesToRadians(30.0)));
			c2.setY(c1.y());
		}
		else {		// open arc
			c0.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->StartAngle())));
			c0.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->StartAngle())));
			c1.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->StartAngle() + ellipse->SpanAngle() / 2)));
			c1.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->StartAngle() + ellipse->SpanAngle() / 2)));
			c2.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->EndAngle())));
			c2.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->EndAngle())));
		}
		isBig = true;
	}
	ellipse->SetProcessed();

	CAMERAITEM ellipseItem;
	if (isBig) { ellipseItem.ctrlNodes << c0 << c1 << c2; }
	else { ellipseItem.ctrlNodes << c0; }

	ellipseItem.type = MeasureType::AA;
	ellipseItem.content = "Arc angle";
	ellipseItem.nHeight = 0;
	Global::g_projectInfo.camearItems.append(ellipseItem);

	emit NodeListTableUpdate();
}
/**
 * @brief	Circular
 */
void DxfPainter::SampleOfCircular()
{
	DXFEllipseItem *ellipse = ELLIPSE_PTR_CAST(m_dxfScene->selectedItems().first());

	if ((ellipse->LALength() != ellipse->SALength())) { return; }
	QPointF c0, c1, c2;
	bool isBig;

	if (2 * ellipse->LALength() <= Global::g_camViewField) {
		c0.setX(ellipse->pos().x());
		c0.setY(ellipse->pos().y());
		isBig = false;
	}
	else {
		if (ellipse->SpanAngle() >= 360.0) {	// closed circle
			c0.setX(ellipse->pos().x());
			c0.setY(ellipse->pos().y() - ellipse->SALength());
			c1.setX(ellipse->pos().x() + ellipse->LALength() * qCos(qDegreesToRadians(30.0)));
			c1.setY(ellipse->pos().y() + ellipse->SALength() / 2);
			c2.setX(ellipse->pos().x() - ellipse->LALength() * qCos(qDegreesToRadians(30.0)));
			c2.setY(c1.y());
		}
		else {		// open arc
			c0.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->StartAngle())));
			c0.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->StartAngle())));
			c1.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->StartAngle() + ellipse->SpanAngle() / 2)));
			c1.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->StartAngle() + ellipse->SpanAngle() / 2)));
			c2.setX(ellipse->pos().x() + ellipse->LALength() *
				qCos(qDegreesToRadians(ellipse->EndAngle())));
			c2.setY(ellipse->pos().y() + ellipse->SALength() *
				qSin(qDegreesToRadians(ellipse->EndAngle())));
		}
		isBig = true;
	}
	ellipse->SetProcessed();

	CAMERAITEM ellipseItem;
	if (isBig) { ellipseItem.ctrlNodes << c0 << c1 << c2; }
	else { ellipseItem.ctrlNodes << c0; }

	ellipseItem.type = MeasureType::CIC;
	ellipseItem.content = "Circular";
	ellipseItem.nHeight = 0;
	Global::g_projectInfo.camearItems.append(ellipseItem);

	emit NodeListTableUpdate();
}
/**
 * @brief	Line length
 */
void DxfPainter::SampleOfLength()
{
	DXFPolylineItem *line = POLY_PTR_CAST(m_dxfScene->selectedItems().first());

	QPointF ls, le;
	ls = line->PolygonF().first();
	le = line->PolygonF().last();
	line->SetProcessed();

	CAMERAITEM lineItem;
	lineItem.ctrlNodes << ls << le;

	lineItem.type = MeasureType::LEN;
	lineItem.content = "Length";
	lineItem.nHeight = 0;
	Global::g_projectInfo.camearItems.append(lineItem);

	emit NodeListTableUpdate();
}
/**
 * @brief	Straightness
 */
void DxfPainter::SampleOfStraightness()
{
	DXFPolylineItem *line = POLY_PTR_CAST(m_dxfScene->selectedItems().first());

	QPointF ls, le;
	ls = line->PolygonF().first();
	le = line->PolygonF().last();
	double d = P_DISTANCE(ls, le);
	double length = qSqrt(d);
	
	CAMERAITEM lineItem;
	if (d <= Global::g_camViewField){ lineItem.ctrlNodes << ls << le; }
	else {
		double slope = (le.y() - ls.y()) / (le.x() - ls.x());
		int count = qCeil(length / Global::g_camViewField );
		double deltaX = (le.x() - ls.x())/ count;
		for (int i = 0; i < count + 1; ++i) {
			double increase = (double)i * deltaX;
			QPointF p;
			p.setX(ls.x() + increase);
			p.setY(ls.y() + increase*slope);
			lineItem.ctrlNodes << p;
		}
	}
	line->SetProcessed();

	lineItem.type = MeasureType::LEN;
	lineItem.content = "Straightness";
	lineItem.nHeight = 0;
	Global::g_projectInfo.camearItems.append(lineItem);

	emit NodeListTableUpdate();
}
/**
 * @brief	Height
 */
void DxfPainter::SampleOfHeight()
{
	LASERITEM laserItem;
	Q_FOREACH(QGraphicsItem *item, m_dxfScene->selectedItems()) {
		MARK_PTR_CAST(item)->SetProcessed();
		laserItem.nodes.append(item->pos());
	}

	laserItem.content = "Height";
	laserItem.nHeight = 0;
	Global::g_projectInfo.laserItems.append(laserItem);

	emit NodeListTableUpdate();
}
