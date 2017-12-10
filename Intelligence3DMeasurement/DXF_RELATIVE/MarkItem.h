#pragma once

#include <QGraphicsItem>

#include "dxf-graphicsitems\entitiesparser4dxf.h"

#define MARK_PTR_CAST(i) qgraphicsitem_cast<MarkItem*>(i)

class MarkItem : public QGraphicsItem
{

public:
	MarkItem(int morph = 0);
	enum { Type = DXF_MARK };
	int type() const Q_DECL_OVERRIDE;

	void SetProcessed(bool f = true);
	int Morph() const;

protected:
	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
	int m_morph;
	double m_size;
	bool m_hasProcessed;
};
