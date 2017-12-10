#pragma once

#include <QLabel>

class PhotoLabel : public QLabel
{
	Q_OBJECT

public:
	PhotoLabel(QWidget *parent = Q_NULLPTR);
	~PhotoLabel();

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
	int m_length;
};
