#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "dxfpolylineitem.h"


DXFPolylineItem::DXFPolylineItem(const LWPOLYLINE &data):
	m_hasProcessed(false)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setZValue(2);

    m_type = data.nType;
    m_num = data.nNum;
	for (int i = 0; i < m_num; ++i) { m_polygon << QPointF(data.ctrlPoints[i].x(), -data.ctrlPoints[i].y()); }
	if (1 == m_type) { m_polygon << QPointF(data.ctrlPoints[0].x(), -data.ctrlPoints[0].y()); }
}

DXFPolylineItem::DXFPolylineItem(const LINE &data):
	m_hasProcessed(false), m_type(0), m_num(2)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setZValue(2);

    m_polygon<<QPointF(data.start.x(), -data.start.y());
    m_polygon<<QPointF(data.end.x(), -data.end.y());
}

int DXFPolylineItem::type() const
{
	return Type;
}

void DXFPolylineItem::SetProcessed(bool f)
{
	m_hasProcessed = f;
	setFlag(QGraphicsItem::ItemIsSelectable, !m_hasProcessed);
}

QPolygonF DXFPolylineItem::PolygonF() const
{
	return m_polygon;
}

QRectF DXFPolylineItem::boundingRect() const
{
    QPainterPath path;
    path.addPolygon(m_polygon);
    if (m_type == 1) {
        path.moveTo(m_polygon.first());
        path.lineTo(m_polygon.last());
    }
    return path.boundingRect();
}

void DXFPolylineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);

	QPen p(QPen(Qt::white, 0.5));
	if (m_hasProcessed) {
		p.setColor(Qt::blue);
		p.setWidthF(0.5);
	}
	else if (option->state & QStyle::State_Selected) {
		p.setColor(Qt::red);
		p.setWidthF(0.5);
	}

	painter->setPen(p);
    painter->drawPolyline(m_polygon);
}
