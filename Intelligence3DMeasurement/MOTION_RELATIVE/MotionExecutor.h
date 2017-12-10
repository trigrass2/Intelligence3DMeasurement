#pragma once

#include <QThread>


class MotionExecutor : public QThread
{
	Q_OBJECT

private:
	void ErrorCorrection(double &dx, double &dy);
	void Coordinator(double dx, double dy, double dz, double &lastHeight);
	bool Camera(double x, double y, int itemIndex);

protected:
	void run() Q_DECL_OVERRIDE;

signals:
	void LaserRequire(int);
};
