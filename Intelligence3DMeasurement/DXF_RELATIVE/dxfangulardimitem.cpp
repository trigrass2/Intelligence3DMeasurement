#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "dxfangulardimitem.h"


DXFAngularDimItem::DXFAngularDimItem(const ANGULARDIM &data):
	m_hasDeviation(true), m_textAngle(0.0)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setZValue(3);

	m_line1Start.setX(data.line1Start.x());
	m_line1Start.setY(-data.line1Start.y());
	m_line1End.setX(data.line1End.x());
	m_line1End.setY(-data.line1End.y());
	m_line2Start.setX(data.line2Start.x());
	m_line2Start.setY(-data.line2Start.y());
	m_line2End.setX(data.line2End.x());
	m_line2End.setY(-data.line2End.y());
    m_rawText = data.rawText;
    m_textEnd.setX(data.textMid.x());
    m_textEnd.setY(-data.textMid.y());
	m_standardValue = data.standardValue;
    m_mainFont.setPixelSize(6);
    m_sideFont.setPixelSize(3);
    QFontMetricsF fmfm(m_mainFont);
    QFontMetricsF fmfs(m_sideFont);

	if (m_rawText.isEmpty()) {
		m_hasDeviation = false;
		m_standardValue.append("°");
		m_d_DimWidth = fmfm.width(m_standardValue);
	}
    else {
		m_frontText = data.frontText;
		m_backText = data.backText;
		m_upperDeviation = data.upperDeviation;
		m_lowerDeviation = data.lowerDeviation;
		m_frontTextWidth = fmfm.width(m_frontText);
		m_backTextWidth = fmfm.width(m_backText);
		m_deviationMaxWidth = qMax(fmfs.width(m_upperDeviation), fmfs.width(m_lowerDeviation));
    }

	m_formatedText = m_standardValue + "[" + m_upperDeviation + "," + m_lowerDeviation + "]";
}

int DXFAngularDimItem::type() const
{
	return Type;
}

QRectF DXFAngularDimItem::boundingRect() const
{
    return QRectF(m_textEnd, QSizeF(5,5));
}

void DXFAngularDimItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);

	QPen p(QPen(QColor(0, 255, 0), 0.3, Qt::SolidLine));
	if (option->state & QStyle::State_Selected) {
		p.setColor(Qt::red);
		p.setWidthF(0.3);
		p.setStyle(Qt::SolidLine);
	}

	painter->setPen(p);
	painter->drawLine(m_line1Start, m_line1End);
	painter->drawLine(m_line2Start, m_line2End);

	painter->setFont(m_mainFont);
	painter->translate(m_textEnd);
	painter->rotate(-m_textAngle);
	if (m_hasDeviation) {
		painter->drawText(-(m_frontTextWidth + m_backTextWidth + m_deviationMaxWidth) / 2.0, -1.0, m_frontText);
		painter->setFont(m_sideFont);
		painter->drawText((m_frontTextWidth - m_backTextWidth - m_deviationMaxWidth) / 2.0 + 0.5, -4.0, m_upperDeviation);
		painter->drawText((m_frontTextWidth - m_backTextWidth - m_deviationMaxWidth) / 2.0 + 0.5, -1.0, m_lowerDeviation);
		painter->setFont(m_mainFont);
		painter->drawText((m_frontTextWidth - m_backTextWidth + m_deviationMaxWidth) / 2.0, -1.0, m_backText);
	}
	else { painter->drawText(-m_d_DimWidth / 2.0, -1.0, m_standardValue); }
}
