#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenu>

#include "DXF_RELATIVE\PathItem.h"


class DxfPainter : public QGraphicsView
{
	Q_OBJECT

public:
	DxfPainter(QWidget *parent = Q_NULLPTR);
	~DxfPainter();

protected:
	void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;
	void focusInEvent(QFocusEvent *event) Q_DECL_OVERRIDE;
	void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
	QGraphicsScene *m_dxfScene;
	double m_absorptionDis;

	qreal m_zoomRatio, m_zoomMax, m_zoomMin, m_zoomStep;
	QPoint m_lastCursorPos;
	QPointF m_currentCursorPos;
	bool m_isMouseDragMoveEnable;

	PathItem *m_pathItem, *m_pathItem1;
	bool m_hasPathItem, m_hasPathItem1;
	QPointF GetNearest(const QList<QPointF> &nearPoints, const QPointF &currentPos);
	void UpdateSqc();
	void LoadPathItem();
	
	void Translator(QPointF delta);

signals:
	void RequireTitleUpdate();
	void NodeListTableUpdate();

private slots:
	void OpenDXF(bool isCleanOpen);
	void Replan();
	void LoadProject();

	void ActivateMarkItem(const QModelIndex &index);
	void ClearMarkItem(int morph);

	void SampleOfL2LDist();
	void SampleTheL2LAngle();
	void SampleTheP2PDist();
	void SampleTheP2LDist();
	void SampleTheRadius();
	void SampleTheArcAngle();
	void SampleTheCircular();
	void SampleOfLength();
	void SampleTheStraightness();
	void SampleTheHeight();
};
