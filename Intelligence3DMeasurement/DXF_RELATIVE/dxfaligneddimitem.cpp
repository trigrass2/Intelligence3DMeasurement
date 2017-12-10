#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "dxfaligneddimitem.h"


DXFAlignedDimItem::DXFAlignedDimItem(const ALIGNEDDIM &data):
	m_hasDeviation(true)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setZValue(1);

	m_lmtStart.setX(data.lmtStart.x());
	m_lmtStart.setY(-data.lmtStart.y());
	m_lmtEnd.setX(data.lmtEnd.x());
	m_lmtEnd.setY(-data.lmtEnd.y());
	m_lineAnchor.setX(data.lineAnchor.x());
	m_lineAnchor.setY(-data.lineAnchor.y());
	m_textMid.setX(data.textMid.x());
	m_textMid.setY(-data.textMid.y());
	m_rotateFromX = -data.nRotateFromX;
	m_rawText = data.rawText;
	m_standardValue = data.standardValue;
    double x,y;
    if (qAbs(data.lmtEnd.y() - data.lineAnchor.y()) == 0) {			// vertical line
        x = data.lineAnchor.x();
        y = data.lmtStart.y();
		m_textEnd.setX(x);
		m_textEnd.setY(-data.textMid.y());
    }
	else if (qAbs(data.lmtEnd.x() - data.lineAnchor.x()) == 0) {	// horizonal line
        x = data.lmtStart.x();
        y = data.lineAnchor.y();
		m_textEnd.setX(data.textMid.x());
		m_textEnd.setY(-y);
    }
	else {		// rotated line
		double tEx, k = (data.lineAnchor.x() - data.lmtEnd.x()) / (data.lmtEnd.y() - data.lineAnchor.y());
		x = -(data.lineAnchor.y() - data.lmtStart.y() - k*data.lineAnchor.x() - data.lmtStart.x() / k) / (k + 1.0 / k);
		y = data.lmtStart.y() - (x - data.lmtStart.x()) / k;
		tEx = (data.textMid.y() - data.lineAnchor.x() + k*data.lineAnchor.x() + data.textMid.x() / k) / (k + 1.0 / k);
		m_textEnd.setX(tEx);
		m_textEnd.setY(-(k*tEx - k*data.lineAnchor.x() + data.lineAnchor.y()));
    }
	m_lineEnd.setX(x);
	m_lineEnd.setY(-y);

    m_mainFont.setPixelSize(6);
    m_sideFont.setPixelSize(3);
    QFontMetricsF fmfm(m_mainFont);
    QFontMetricsF fmfs(m_sideFont);
	
    if (m_rawText.isEmpty()) {
        m_hasDeviation = false;
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

    m_formatedText = m_standardValue +"["+ m_upperDeviation +","+ m_lowerDeviation +"]";
}

QString DXFAlignedDimItem::getText()
{
	return m_formatedText;
}

int DXFAlignedDimItem::type() const
{
	return Type;
}

QRectF DXFAlignedDimItem::boundingRect() const
{
    return QRectF(m_textEnd, QSizeF(5,5));
}

void DXFAlignedDimItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);

	QPen p1(QPen(QColor(255, 139, 255), 0.3, Qt::DotLine));
	QPen p2(QPen(QColor(255, 139, 255), 0.3, Qt::SolidLine));
	QPen p3(QPen(QColor(240, 173, 109), 0.3, Qt::SolidLine));
	if (option->state & QStyle::State_Selected) {
		p1.setColor(Qt::red);
		p1.setWidthF(0.3);
		p1.setStyle(Qt::SolidLine);
		p2 = p1;
		p3 = p1;
	}

	painter->setPen(p1);
	painter->drawLine(m_lmtStart, m_lineEnd);
	painter->drawLine(m_lineAnchor, m_lmtEnd);

	painter->setPen(p2);
	painter->drawLine(m_lineEnd, m_lineAnchor);
	painter->drawLine(m_lineAnchor, m_textEnd);

	painter->setPen(p3);
	painter->setFont(m_mainFont);
	painter->translate(m_textEnd);
	painter->rotate(m_rotateFromX);
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
