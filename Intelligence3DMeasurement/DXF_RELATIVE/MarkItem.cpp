#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "MarkItem.h"


MarkItem::MarkItem(int morph) : m_size(3.6), m_hasProcessed(false)
{
	if (0 == morph) {
		setZValue(5);
		setFlag(QGraphicsItem::ItemIsSelectable, false);
	}
	else if (1 == morph) {
		setZValue(4);
		setFlag(QGraphicsItem::ItemIsSelectable);
	}
	m_morph = morph;
}

int MarkItem::type() const
{
	return Type;
}

void MarkItem::SetProcessed(bool f)
{
	m_hasProcessed = f;
	setFlag(QGraphicsItem::ItemIsSelectable, !m_hasProcessed);
}

int MarkItem::Morph() const
{
	return m_morph;
}

QRectF MarkItem::boundingRect() const
{
	return QRectF(-m_size / 2.0, -m_size / 2.0, m_size, m_size);
}

void MarkItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);

	if (0 == m_morph) {
		painter->setPen(QPen(Qt::red, 0.3));
		painter->drawLine(QPoint(-m_size / 2.0, -m_size / 2.0), QPoint(m_size / 2.0, m_size / 2.0));
		painter->drawLine(QPoint(-m_size / 2.0, m_size / 2.0), QPoint(m_size / 2.0, -m_size / 2.0));
	}
	else if (1 == m_morph) {
		QPen p(QPen(Qt::yellow, 0.3));
		if (m_hasProcessed) {
			p.setColor(QColor(35, 255, 0));
			p.setWidthF(0.3);
		}
		else if (option->state & QStyle::State_Selected) {
			p.setColor(Qt::red);
			p.setWidthF(0.3);
		}

		painter->setPen(p);
		painter->drawLine(QPoint(-m_size / 2.0, 0), QPoint(m_size / 2.0, 0));
		painter->drawLine(QPoint(0, -m_size / 2.0), QPoint(0, m_size / 2.0));
	}
}