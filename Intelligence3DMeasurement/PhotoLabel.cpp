#include <QPainter>
#include "PhotoLabel.h"


PhotoLabel::PhotoLabel(QWidget *parent)
	: QLabel(parent), m_length(70)
{
}

PhotoLabel::~PhotoLabel()
{
}

void PhotoLabel::paintEvent(QPaintEvent *event)
{
	QLabel::paintEvent(event);
	QPainter painter;
	painter.begin(this);
	QPen pen(Qt::red, 1, Qt::DashDotLine);
	painter.setPen(pen);
	int h = this->height();
	int w = this->width();
	painter.drawLine((w - m_length) / 2, h / 2, (w + m_length) / 2, h / 2);
	painter.drawLine(w / 2, (h - m_length) / 2, w / 2, (h + m_length) / 2);
	painter.end();
}