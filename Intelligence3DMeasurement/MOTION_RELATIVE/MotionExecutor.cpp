#include <QApplication>
#include <QDebug>
#include <Windows.h>
#include "MotionExecutor.h"

#include "LTDMC.h"
#include "Global.h"


void MotionExecutor::BiasCorrectionXY(double &dx, double &dy)
{
	dx += Global::g_pulseEquivalent * Global::g_laserBiasX;
	dy += Global::g_pulseEquivalent * Global::g_laserBiasY;
}

void MotionExecutor::BiasCorrectionZ(double &dz)
{
	dz += Global::g_pulseEquivalent * Global::g_laserBiasZ;
}
/**
 * @brief	Coordinator
 *
 * 根据高度上下文控制Z轴
 */
void MotionExecutor::Coordinator(double dx, double dy, double dz, double &lastHeight)
{
	long pdx, pdy, pdz;
	if (dz - lastHeight > 0) {
		qDebug() << "	[Height]adjusting to " << dz;
		pdz = dz / Global::g_pulseEquivalent;
		if (ENABLE_MOTION_MODULE) {
			dmc_pmove(0, 2, pdz, 1);
			while (dmc_check_done(0, 2) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			qDebug() << "	->Done";
		}

		qDebug() << "	[XY]moving to " << "(" << dx << ", " << dy << ")";
		pdx = dx / Global::g_pulseEquivalent;
		pdy = dy / Global::g_pulseEquivalent;
		if (ENABLE_MOTION_MODULE) {
			dmc_line_multicoor(0, 0, 2, new ushort[2]{ 0,1 }, new long[2]{ pdx, pdy }, 1);
			while (dmc_check_done_multicoor(0, 0) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			qDebug() << "	->Done";
		}
	}
	else if(dz - lastHeight < 0) {
		qDebug() << "	[XY]moving to " << "(" << dx << ", " << dy << ")";
		pdx = dx / Global::g_pulseEquivalent;
		pdy = dy / Global::g_pulseEquivalent;
		if (ENABLE_MOTION_MODULE) {
			dmc_line_multicoor(0, 0, 2, new ushort[2]{ 0,1 }, new long[2]{ pdx, pdy }, 1);
			while (dmc_check_done_multicoor(0, 0) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			qDebug() << "	->Done";
		}

		qDebug() << "	[Height]adjusting to " << dz;
		pdz = dz / Global::g_pulseEquivalent;
		if (ENABLE_MOTION_MODULE) {
			dmc_pmove(0, 2, pdz, 1);
			while (dmc_check_done(0, 2) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			qDebug() << "	->Done";
		}
	}
	else {
		qDebug() << "	[XY]moving to " << "(" << dx << ", " << dy << ")";
		pdx = dx / Global::g_pulseEquivalent;
		pdy = dy / Global::g_pulseEquivalent;
		if (ENABLE_MOTION_MODULE) {
			dmc_line_multicoor(0, 0, 2, new ushort[2]{ 0,1 }, new long[2]{ pdx, pdy }, 1);
			while (dmc_check_done_multicoor(0, 0) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			qDebug() << "	->Done";
		}
	}
	lastHeight = dz;
}

void MotionExecutor::HomeReturn(bool f)
{
	if (f) {
		if (ENABLE_MOTION_MODULE) {
			dmc_set_position(0, 0, 0);
			dmc_set_position(0, 1, 0);
			dmc_set_position(0, 2, 0);
			dmc_set_encoder(0, 0, 0);
			dmc_set_encoder(0, 1, 0);
			dmc_set_encoder(0, 2, 0);
		}
		qDebug() << "Setup relative home.";
	}
	else {
		qDebug() << "Returning to relative home.";
		if (ENABLE_MOTION_MODULE) {
			// Z轴回原
			dmc_home_move(0, 2);
			Sleep(100);
			while (dmc_check_done(0, 2) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			// X、Y轴复位
			dmc_pmove(0, 0, 0, 1);
			dmc_pmove(0, 1, 0, 1);
			while (dmc_check_done(0, 0) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			while (dmc_check_done(0, 1) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			// Z轴复位
			dmc_pmove(0, 2, 0, 1);
			while (dmc_check_done(0, 2) == 0) {
				if (m_break) {
					dmc_emg_stop(0);
					return;
				}
				qApp->processEvents();
			}
			qDebug() << "Done.";
		}
		m_break = false;
	}
}

void MotionExecutor::Camera(int itemIndex)
{
	qDebug() << "	[Camera]capturing item@" << itemIndex;
	if (ENABLE_MOTION_MODULE) {
		Sleep(100);		// wait for stop
		long x = dmc_get_encoder(0, 0);
		long y = dmc_get_encoder(0, 1);
		if (ENABLE_VISION_MODULE) {
			GrabImage(&Global::g_curPhoto, Global::acqHandle);
			Global::g_projectInfo.camItemList[itemIndex].feedbackPosList << QPoint(x, y);
			Global::g_projectInfo.camItemList[itemIndex].sampleData << Global::g_curPhoto;
			emit ShowCurPhoto();
			qDebug() << "	->Done";
		}
	}
}

void MotionExecutor::Laser(int itemIndex)
{
	qDebug() << "	[Laser]sampling item@" << itemIndex;
	if (ENABLE_MOTION_MODULE) {
		Sleep(100);
		long x = dmc_get_encoder(0, 0);
		long y = dmc_get_encoder(0, 1);
		if (ENABLE_VISION_MODULE) {
			Global::g_projectInfo.laserItemList[itemIndex].feedbackPosList << QPoint(x, y);
			emit LaserRequire(itemIndex);
			Sleep(50);		// wait for read
			qDebug() << "	->Done";
		}
	}
}

void MotionExecutor::run()
{
	qDebug() << "#######Start#######";
	if (ENABLE_MOTION_MODULE) {
		dmc_set_vector_profile_multicoor(0, 0, 0, Global::g_xyLineVectorVel, 0.01, 0.01);
		dmc_set_profile(0, 0, 0, Global::g_zVel, 0.01, 0.01, 0);
		dmc_set_profile(0, 1, 0, Global::g_zVel, 0.01, 0.01, 0);
		dmc_set_profile(0, 2, 0, Global::g_zVel, 0.01, 0.01, 0);
	}

	HomeReturn(!m_break);

	double x0 = Global::g_projectInfo.startCADPos.x();
	double y0 = Global::g_projectInfo.startCADPos.y();
	double height = 0;

	qDebug() << "Enter vision measure area.";
	Q_FOREACH(int index, Global::g_projectInfo.camMeasurePath) {
		double dx, dy, dz;
		if (Global::g_projectInfo.camItemList[index].bPosListInverted) {
			dz = Global::g_projectInfo.camItemList[index].nCADHeight;
			for (int i = Global::g_projectInfo.camItemList[index].cadPosList.count() - 1; i >= 0; --i) {
				dx = Global::g_projectInfo.camItemList[index].cadPosList[i].x() - x0;
				dy = Global::g_projectInfo.camItemList[index].cadPosList[i].y() - y0;
				Coordinator(dx, dy, dz, height);
				Camera(index);
				
			}
			Global::g_projectInfo.camItemList[index].nTemp = 9999;	// processed
		}
		else {
			for (int i = 0; i < Global::g_projectInfo.camItemList[index].cadPosList.count(); ++i) {
				dx = Global::g_projectInfo.camItemList[index].cadPosList[i].x() - x0;
				dy = Global::g_projectInfo.camItemList[index].cadPosList[i].y() - y0;
				dz = Global::g_projectInfo.camItemList[index].nCADHeight;
				Coordinator(dx, dy, dz, height);
				Camera(index);
			}
			Global::g_projectInfo.camItemList[index].nTemp = 9999;
		}
	}

	qDebug() << "Enter laser mesure area.";
	for (int index = 0; index < Global::g_projectInfo.laserItemList.count(); ++index) {
		double dx, dy, dz = Global::g_projectInfo.laserItemList[index].nCADHeight;
		BiasCorrectionZ(dz);
		for (int i = 0; i < Global::g_projectInfo.laserItemList[index].cadPosList.count(); ++i) {
			dx = Global::g_projectInfo.laserItemList[index].cadPosList[i].x() - x0;
			dy = Global::g_projectInfo.laserItemList[index].cadPosList[i].y() - y0;
			BiasCorrectionXY(dx, dy);
			Coordinator(dx, dy, dz, height);
			Laser(index);
		}
	}

	if (!m_break){ HomeReturn(false); }
	qDebug() << "#######Finish#######";
}
