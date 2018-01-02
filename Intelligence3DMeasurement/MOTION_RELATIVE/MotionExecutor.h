#pragma once

#include <QThread>


class MotionExecutor : public QThread
{
	Q_OBJECT

private:
	bool m_break = false;

	void BiasCorrectionXY(double &dx, double &dy);
	void BiasCorrectionZ(double &dz);
	void Coordinator(double dx, double dy, double dz, double &lastHeight);
	void HomeReturn(bool f);
	void Camera(int itemIndex);
	void Laser(int itemIndex);

protected:
	void run() Q_DECL_OVERRIDE;

signals:
	void ShowCurPhoto();
	void LaserRequire(int);

private slots:
	void Stop(){ m_break = true; }
};
