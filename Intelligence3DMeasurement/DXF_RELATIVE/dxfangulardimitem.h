#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QGraphicsItem>
#include <QFont>

#include "entitiesparser4dxf.h"

#define ANGULAR_PTR_CAST(i) qgraphicsitem_cast<DXFAngularDimItem*>(i)


class DXFAngularDimItem : public QGraphicsItem
{

public:
    DXFAngularDimItem(const ANGULARDIM &data);
    enum { Type = DXF_ANGULAR};
	int type() const Q_DECL_OVERRIDE;

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
	QPointF m_line1Start, m_line1End;
	QPointF m_line2Start, m_line2End;
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

