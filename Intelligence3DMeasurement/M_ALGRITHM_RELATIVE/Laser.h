#pragma once

#include <QObject>

class Laser : public QObject
{
	Q_OBJECT

public:
	Laser(QObject *parent);
	~Laser();

signals:
	void LaserProcessDone();

private slots:
	void LaserProc();
};
