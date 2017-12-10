#include "PathItem.h"

#include <QPen>
#include <QPainter>
#include <QDebug>
PathItem::PathItem(const QVector<QPointF> & path, int diff)
{
	setFlag(QGraphicsItem::ItemIsSelectable, false);
	setZValue(4);

	m_path.append(path);
	m_diff = diff;
}

QList<QPointF> PathItem::GetList() const
{
	return m_path.toList();
}

int PathItem::type() const
{
	return Type;
}

QRectF PathItem::boundingRect() const
{
	QPainterPath path;
	path.addPolygon(m_path);
	return path.boundingRect();
}

void PathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	if (0 == m_diff) { painter->setPen(QPen(QColor(0, 228, 255), 0.3)); }
	else if (1 == m_diff) { painter->setPen(QPen(QColor(35, 255, 0), 0.3)); }
	
	painter->drawPolyline(m_path);
}
