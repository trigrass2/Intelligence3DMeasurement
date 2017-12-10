#ifndef DXFELLIPSEITEM_H
#define DXFELLIPSEITEM_H

#include <QGraphicsItem>

#include "dxf-graphicsitems\entitiesparser4dxf.h"

#define ELLIPSE_PTR_CAST(i) qgraphicsitem_cast<DXFEllipseItem*>(i)

class DXFEllipseItem : public QGraphicsItem
{

public:
    DXFEllipseItem(const ARC &data);
    DXFEllipseItem(const CIRCLE &data);
    DXFEllipseItem(const ELLIPSE &data);
    enum { Type = DXF_ELLIPSE};
	int type() const Q_DECL_OVERRIDE;
	void SetProcessed(bool f = true);

	QPointF CenterPos() const;
    double LALength() const;
    double SALength() const;
    double StartAngle() const;
    double EndAngle() const;
    double SpanAngle() const;
    double Rotation() const;

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
	QPointF m_center;
    QRectF m_boundingRect;
    double m_long, m_short;
    double m_angleStart, m_angleEnd;
    double m_spanAngle;
    double m_rotateAngle;
	bool m_hasProcessed;
};

#endif // DXFELLIPSEITEM_H
