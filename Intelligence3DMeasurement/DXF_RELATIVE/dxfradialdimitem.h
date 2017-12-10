#ifndef DXFRADIALDIMITEM_H
#define DXFRADIALDIMITEM_H

#include <QGraphicsItem>
#include <QFont>

#include "entitiesparser4dxf.h"

#define RADIAL_PTR_CAST(i) qgraphicsitem_cast<DXFRadialDimItem*>(i)

class DXFRadialDimItem : public QGraphicsItem
{

public:
    DXFRadialDimItem(const RADIALDIM &data);
    enum { Type = DXF_RADIAL};
	int type() const Q_DECL_OVERRIDE;

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
	bool m_isRadius;
	QPointF m_lineAnchor;
	QPointF m_lineEnd;
	QPointF m_textMid, m_textEnd;
	double m_textAngle;
	QString m_rawText;
	QString m_standardValue;
	QString m_formatedText;
	bool m_hasDeviation;
	// below varities are availiable only if has deviation
	QString m_frontText, m_backText;
	QString m_upperDeviation, m_lowerDeviation;
	QFont m_mainFont, m_sideFont;
	double m_frontTextWidth, m_backTextWidth;
	double m_deviationMaxWidth;
	double m_d_DimWidth;
};

#endif // DXFRADIALDIMITEM_H
