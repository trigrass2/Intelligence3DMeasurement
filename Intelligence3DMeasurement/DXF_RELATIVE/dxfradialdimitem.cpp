#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <qmath.h>
#include "dxfradialdimitem.h"


DXFRadialDimItem::DXFRadialDimItem(const RADIALDIM &data):
	m_hasDeviation(true)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setZValue(1);

	m_isRadius = data.bIsRadius;
	m_lineAnchor.setX(data.lineAnchor.x());
	m_lineAnchor.setY(-data.lineAnchor.y());
	m_lineEnd.setX(data.lineEnd.x());
	m_lineEnd.setY(-data.lineEnd.y());
	m_rawText = data.rawText;
	m_standardValue = data.standardValue;
	if (qAbs(data.lineAnchor.x() - data.lineEnd.x()) == 0) {		// vertical line
		m_textEnd.setX(data.lineAnchor.x());
		m_textEnd.setY(-data.textMid.y());
		m_textAngle = 90.0;
	}
	else if (qAbs(data.lineAnchor.y() - data.lineEnd.y()) == 0) {	// horizonal line
		m_textEnd.setX(data.textMid.x());
		m_textEnd.setY(-data.lineAnchor.y());
		m_textAngle = 0.0;
	}
	else {
		double tEy, k = (data.lineAnchor.x() - data.lineEnd.x()) / (data.lineEnd.y() - data.lineAnchor.y());
		tEy = (k*data.lineEnd.x() + k*k*data.lineEnd.y() - data.textMid.x()*k + data.textMid.y()) / (1.0 + k*k);
		m_textEnd.setX(data.lineEnd.x() + k*data.lineEnd.y() - tEy*k);
		m_textEnd.setY(-tEy);
		m_textAngle = qRadiansToDegrees(qAtan(-1.0 / k));
    }
    
	m_mainFont.setPixelSize(6);
	m_sideFont.setPixelSize(3);
	QFontMetricsF fmfm(m_mainFont);
	QFontMetricsF fmfs(m_sideFont);

	if (m_rawText.isEmpty()) {
		m_hasDeviation = false;
		if (m_isRadius) { m_standardValue = "R" + m_standardValue; }
		else { m_standardValue = "Φ" + m_standardValue; }
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

int DXFRadialDimItem::type() const
{
	return Type;
}

QRectF DXFRadialDimItem::boundingRect() const
{
    return QRectF(m_textEnd, QSizeF(5,5));
}

void DXFRadialDimItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);

	QPen p1(QPen(QColor(255, 139, 255), 0.3, Qt::DotLine));
	QPen p2(QPen(QColor(240, 173, 109), 0.3, Qt::SolidLine));
	if (option->state & QStyle::State_Selected) {
		p1.setColor(Qt::red);
		p1.setWidthF(0.3);
		p1.setStyle(Qt::SolidLine);
		p2 = p1;
	}

	painter->setPen(p1);
	painter->drawLine(m_lineEnd, m_lineAnchor);
	painter->drawLine(m_lineAnchor, m_textEnd);

	painter->setPen(p2);
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
