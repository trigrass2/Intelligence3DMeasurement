#ifndef DXFALIGNEDDIMITEM_H
#define DXFALIGNEDDIMITEM_H

#include <QGraphicsItem>
#include <QFont>

#include "entitiesparser4dxf.h"

#define ALIGNED_PTR_CAST(i) qgraphicsitem_cast<DXFAlignedDimItem*>(i)

class DXFAlignedDimItem : public QGraphicsItem
{

public:
    DXFAlignedDimItem(const ALIGNEDDIM &data);
    enum { Type = DXF_ALIGNED};
	int type() const Q_DECL_OVERRIDE;
	QString getText();

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
	QPointF m_lmtStart, m_lmtEnd;
	QPointF m_lineAnchor, m_lineEnd;
	QPointF m_textMid, m_textEnd;
	QString m_rawText;
	QString m_standardValue;
	double m_rotateFromX;
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

#endif // DXFALIGNEDDIMITEM_H
