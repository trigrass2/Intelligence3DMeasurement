#include "dxfellipseitem.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <qmath.h>

DXFEllipseItem::DXFEllipseItem(const ARC &data):
	m_hasProcessed(false), m_rotateAngle(0.0)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setRotation(m_rotateAngle);
	setZValue(2);

	m_center.setX(data.center.x());
	m_center.setY(-data.center.y());
    m_long = m_short = data.nRadius;
    m_angleStart = data.nAngleStart;
    m_angleEnd = data.nAngleEnd;
	if (m_angleEnd > m_angleStart) { m_spanAngle = m_angleEnd - m_angleStart; }
	else { m_spanAngle = m_angleEnd - m_angleStart + 360.0; }
    m_boundingRect = QRectF(-m_long, -m_short, 2.0*m_long, 2.0*m_short);
}

DXFEllipseItem::DXFEllipseItem(const CIRCLE &data):
	m_hasProcessed(false), m_angleStart(0.0), m_angleEnd(360.0), m_spanAngle(360.0), m_rotateAngle(0.0)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setRotation(m_rotateAngle);
	setZValue(2);

	m_center.setX(data.center.x());
	m_center.setY(-data.center.y());
	m_long = m_short = data.nRadius;
    m_boundingRect = QRectF(-m_long, -m_short, 2.0*m_long, 2.0*m_short);
}

DXFEllipseItem::DXFEllipseItem(const ELLIPSE &data):
	m_hasProcessed(false)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setZValue(2);

	m_center.setX(data.center.x());
	m_center.setY(-data.center.y());
    m_long = sqrt(data.longAxisEnd.x() * data.longAxisEnd.x() + data.longAxisEnd.y() * data.longAxisEnd.y());
	m_short = m_long * data.nAxisRatio;
    m_angleStart = qRadiansToDegrees(data.nAngleEnd);
    m_angleEnd = qRadiansToDegrees(data.nAngleEnd);
	if (m_angleEnd > m_angleStart) { m_spanAngle = m_angleEnd - m_angleStart; }
	else { m_spanAngle = m_angleEnd - m_angleStart + 360.0; }
    m_boundingRect = QRectF(-m_long, -m_short, 2.0*m_long, 2.0*m_short);
	m_rotateAngle = qRadiansToDegrees(qAtan(data.longAxisEnd.y() / data.longAxisEnd.x()));

	setRotation(m_rotateAngle);
}

int DXFEllipseItem::type() const
{
	return Type;
}

void DXFEllipseItem::SetProcessed(bool f)
{
	m_hasProcessed = f;
	setFlag(QGraphicsItem::ItemIsSelectable, !m_hasProcessed);
}

QPointF DXFEllipseItem::CenterPos() const
{
	return m_center;
}

double DXFEllipseItem::LALength() const
{
    return m_long;
}

double DXFEllipseItem::SALength() const
{
    return m_short;
}

double DXFEllipseItem::StartAngle() const
{
    return m_angleStart;
}

double DXFEllipseItem::EndAngle() const
{
    return m_angleEnd;
}

double DXFEllipseItem::SpanAngle() const
{
    return m_spanAngle;
}
/**
 * @brief relative rotation
 */
double DXFEllipseItem::Rotation() const
{
    return m_rotateAngle;
}

QRectF DXFEllipseItem::boundingRect() const
{
    QPainterPath path;
    path.arcMoveTo(m_boundingRect, m_angleStart);
    path.arcTo(m_boundingRect, m_angleStart, m_spanAngle);
    return path.boundingRect();
}

void DXFEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    painter->drawArc(m_boundingRect, (int)(16.0*m_angleStart), (int)(16.0*m_spanAngle));
}
