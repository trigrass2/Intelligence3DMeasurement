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
	void Camera(int itemIndex);
	void ReturnControl(bool f);

protected:
	void run() Q_DECL_OVERRIDE;

signals:
	void ShowCurrent();
	void LaserRequire(int);

private slots:
	void Stop(){ m_break = true; }
};
