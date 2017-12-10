#pragma once

#include <QGraphicsItem>

#include "entitiesparser4dxf.h"


class PathItem : public QGraphicsItem
{

public:
	PathItem(const QVector<QPointF> &path, int diff = 0);
	enum { Type = DXF_PATH };
	int type() const Q_DECL_OVERRIDE;
	QList<QPointF> GetList() const;

protected:
	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
	int m_diff;
	QPolygonF m_path;
};
