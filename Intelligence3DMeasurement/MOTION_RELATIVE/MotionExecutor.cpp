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
 * 算法设计：当前高度需要提升时，先（绝对）移动Z轴；反之，后（绝对）移动Z轴
 */
void MotionExecutor::Coordinator(double dx, double dy, double dz, double &lastHeight)
{
	long pdx, pdy, pdz;
	if (dz - lastHeight > 0) {
		qDebug() << "	[Height]Adjusting to " << dz;
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
			qDebug() << "	->Done.";
		}

		qDebug() << "	[XY]Moving to " << "(" << dx << ", " << dy << ")";
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
			qDebug() << "	->Done.";
		}
	}
	else if(dz - lastHeight < 0) {
		qDebug() << "	[XY]Moving to " << "(" << dx << ", " << dy << ")";
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
			qDebug() << "	->Done.";
		}

		qDebug() << "	[Height]Adjusting to " << dz;
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
			qDebug() << "	->Done.";
		}
	}
	else {
		qDebug() << "	[XY]Moving to " << "(" << dx << ", " << dy << ")";
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
			qDebug() << "	->Done.";
		}
	}
	lastHeight = dz;
}

void MotionExecutor::Camera(int itemIndex)
{
	qDebug() << "	[Camera]capturing@item(" << itemIndex << ")";
	if (ENABLE_MOTION_MODULE) {
		long x = dmc_get_encoder(0, 0);
		long y = dmc_get_encoder(0, 1);
		if (ENABLE_VISION_MODULE) {
			Sleep(100);		// wait for tatally stop

			GrabImage(&Global::g_image, Global::AcqHandle);
			emit ShowCurrent();

			QString key = QString::number(itemIndex) + "_" + QString::number(x) + "_" + QString::number(y);
			Global::halconData.insert(key, Global::g_image);
			qDebug() << "	->Done.";
		}
	}
}

void MotionExecutor::ReturnControl(bool f)
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
		qDebug() << "Setup relative ORG.";
	}
	else {
		qDebug() << "Returning to relative ORG.";
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

void MotionExecutor::run()
{
	qDebug() << "#######Start#######";

	if (ENABLE_MOTION_MODULE) {
		dmc_set_vector_profile_multicoor(0, 0, 0, Global::g_xyLineVectorVel, 0.01, 0.01);
		dmc_set_profile(0, 0, 0, Global::g_zVel, 0.01, 0.01, 0);
		dmc_set_profile(0, 1, 0, Global::g_zVel, 0.01, 0.01, 0);
		dmc_set_profile(0, 2, 0, Global::g_zVel, 0.01, 0.01, 0);
	}

	ReturnControl(!m_break);

	double x0 = Global::g_projectInfo.startPoint.x();
	double y0 = Global::g_projectInfo.startPoint.y();
	double height = 0;

	qDebug() << "Enter camera area.";
	Q_FOREACH(int sqc, Global::g_projectInfo.camSequence) {
		double dx, dy, dz;
		if (Global::g_projectInfo.camearItems[sqc].bIsInverted) {
			dz = Global::g_projectInfo.camearItems[sqc].nHeight;
			for (int i = Global::g_projectInfo.camearItems[sqc].ctrlNodes.count() - 1; i >= 0; --i) {
				dx = Global::g_projectInfo.camearItems[sqc].ctrlNodes[i].x() - x0;
				dy = Global::g_projectInfo.camearItems[sqc].ctrlNodes[i].y() - y0;
				Coordinator(dx, dy, dz, height);
				Camera(sqc);
			}
			Global::g_projectInfo.camearItems[sqc].nTemp = 9999;	// 完成标识
		}
		else {
			for (int i = 0; i < Global::g_projectInfo.camearItems[sqc].ctrlNodes.count(); ++i) {
				dx = Global::g_projectInfo.camearItems[sqc].ctrlNodes[i].x() - x0;
				dy = Global::g_projectInfo.camearItems[sqc].ctrlNodes[i].y() - y0;
				dz = Global::g_projectInfo.camearItems[sqc].nHeight;
				Coordinator(dx, dy, dz, height);
				Camera(sqc);
			}
			Global::g_projectInfo.camearItems[sqc].nTemp = 9999;
		}
	}

	qDebug() << "Enter laser area.";
	for (int index = 0; index < Global::g_projectInfo.laserItems.count(); ++index) {
		double dx, dy, dz = Global::g_projectInfo.laserItems[index].nHeight;
		BiasCorrectionZ(dz);
		for (int i = 0; i < Global::g_projectInfo.laserItems[index].nodes.count(); ++i) {
			dx = Global::g_projectInfo.laserItems[index].nodes[i].x() - x0;
			dy = Global::g_projectInfo.laserItems[index].nodes[i].y() - y0;
			BiasCorrectionXY(dx, dy);
			Coordinator(dx, dy, dz, height);
			emit LaserRequire(index);
		}
	}

	if (!m_break){ ReturnControl(false); }
	qDebug() << "#######Finish#######";
}
