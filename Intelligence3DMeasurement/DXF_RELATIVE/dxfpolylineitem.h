#ifndef DXFPOLYLINEITEM_H
#define DXFPOLYLINEITEM_H

#include <QGraphicsItem>

#include "entitiesparser4dxf.h"

#define POLY_PTR_CAST(i) qgraphicsitem_cast<DXFPolylineItem*>(i)


class DXFPolylineItem : public QGraphicsItem
{

public:
    DXFPolylineItem(const LWPOLYLINE &data);
    DXFPolylineItem(const LINE &data);
    enum { Type = DXF_POLY};
	int type() const Q_DECL_OVERRIDE;

	void SetProcessed(bool f = true);
	QPolygonF PolygonF() const;

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
    QPolygonF m_polygon;
    int m_num;
    int m_type;				///< 0=open、1=close
	bool m_hasProcessed;
};

#endif // DXFPOLYLINEITEM_H
