#include <QApplication>
#include <QDebug>
#include "MotionExecutor.h"

#include "LTDMC.h"
#include "Global.h"


/**
 * @brief	修正激光采样坐标误差
 */
void MotionExecutor::ErrorCorrection(double &dx, double &dy)
{
	dx += Global::g_pulseEquivalent * Global::g_laserBiasX;
	dy += Global::g_pulseEquivalent * Global::g_laserBiasY;
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
		qDebug() << "[Height adjusting to " << dz << "]";
		pdz = dz / Global::g_pulseEquivalent;
		if (!USING_SIMULATION_MODE) {
			dmc_pmove(0, 2, pdz, 1);
			while (dmc_check_done(0, 2) == 0) { qApp->processEvents(); }
		}

		qDebug() << "X-Y moving to " << "(" << dx << ", " << dy << ")";
		pdx = dx / Global::g_pulseEquivalent;
		pdy = dy / Global::g_pulseEquivalent;
		if (!USING_SIMULATION_MODE) {
			dmc_line_multicoor(0, 0, 2, new ushort[2]{ 0,1 }, new long[2]{ pdx, pdy }, 1);
			while (dmc_check_done_multicoor(0, 0) == 0) { qApp->processEvents(); }
		}
	}
	else if(dz - lastHeight < 0) {
		qDebug() << "X-Y moving to " << "(" << dx << ", " << dy << ")";
		pdx = dx / Global::g_pulseEquivalent;
		pdy = dy / Global::g_pulseEquivalent;
		if (!USING_SIMULATION_MODE) {
			dmc_line_multicoor(0, 0, 2, new ushort[2]{ 0,1 }, new long[2]{ pdx, pdy }, 1);
			while (dmc_check_done_multicoor(0, 0) == 0) { qApp->processEvents(); }
		}

		qDebug() << "[Height adjusting to " << dz << "]";
		pdz = dz / Global::g_pulseEquivalent;
		if (!USING_SIMULATION_MODE) {
			dmc_pmove(0, 2, pdz, 1);
			while (dmc_check_done(0, 2) == 0) { qApp->processEvents(); }
		}
	}
	else {
		qDebug() << "X-Y moving to " << "(" << dx << ", " << dy << ")";
		pdx = dx / Global::g_pulseEquivalent;
		pdy = dy / Global::g_pulseEquivalent;
		if (!USING_SIMULATION_MODE) {
			dmc_line_multicoor(0, 0, 2, new ushort[2]{ 0,1 }, new long[2]{ pdx, pdy }, 1);
			while (dmc_check_done_multicoor(0, 0) == 0) { qApp->processEvents(); }
		}
	}
	lastHeight = dz;
}

bool MotionExecutor::Camera(double x, double y, int itemIndex)
{
	qDebug() << "	Camera: capturing@item[" << itemIndex << "]";
	if (!USING_SIMULATION_MODE) {
		// 保存图片
		return true;
	}
	return false;
}

void MotionExecutor::run()
{
	qDebug() << "Starting...setup relative ORG.";
	if (!USING_SIMULATION_MODE) {
		dmc_set_position(0, 0, 0);
		dmc_set_position(0, 1, 0);
		dmc_set_position(0, 2, 0);
	}

	double x0 = Global::g_projectInfo.startPoint.x();
	double y0 = Global::g_projectInfo.startPoint.y();
	double height = 0;

	if (!USING_SIMULATION_MODE) {
		dmc_set_vector_profile_multicoor(0, 0, 0, Global::g_xyLineVectorVel, 0.01);
		dmc_set_profile(0, 2, 0, Global::g_zVel, 0.01, 0, 0);
	}

	qDebug() << "Move to camera area.";
	Q_FOREACH(int sqc, Global::g_projectInfo.camSequence) {
		double dx, dy, dz;
		if (Global::g_projectInfo.camearItems[sqc].bIsInverted) {
			dz = Global::g_projectInfo.camearItems[sqc].nHeight;
			for (int i = Global::g_projectInfo.camearItems[sqc].ctrlNodes.count() - 1; i >= 0; --i) {
				dx = Global::g_projectInfo.camearItems[sqc].ctrlNodes[i].x() - x0;
				dy = Global::g_projectInfo.camearItems[sqc].ctrlNodes[i].y() - y0;
				Coordinator(dx, dy, dz, height);
				if (Camera(dx, dy, sqc)) { qDebug() << "	->done."; }
				else { qDebug() << "	->failed!"; }
			}
			Global::g_projectInfo.camearItems[sqc].nTemp = 9999;	// 完成标识
		}
		else {
			for (int i = 0; i < Global::g_projectInfo.camearItems[sqc].ctrlNodes.count(); ++i) {
				dx = Global::g_projectInfo.camearItems[sqc].ctrlNodes[i].x() - x0;
				dy = Global::g_projectInfo.camearItems[sqc].ctrlNodes[i].y() - y0;
				dz = Global::g_projectInfo.camearItems[sqc].nHeight;
				Coordinator(dx, dy, dz, height);
				if (Camera(dx, dy, sqc)) { qDebug() << "	->done."; }
				else { qDebug() << "	->failed!"; }
			}
			Global::g_projectInfo.camearItems[sqc].nTemp = 9999;
		}
	}

	qDebug() << "Move to laser area.";
	for (int index = 0; index < Global::g_projectInfo.laserItems.count(); ++index) {
		double dx, dy, dz = Global::g_projectInfo.laserItems[index].nHeight;
		for (int i = 0; i < Global::g_projectInfo.laserItems[index].nodes.count(); ++i) {
			dx = Global::g_projectInfo.laserItems[index].nodes[i].x() - x0;
			dy = Global::g_projectInfo.laserItems[index].nodes[i].y() - y0;
			ErrorCorrection(dx, dy);
			Coordinator(dx, dy, dz, height);
			emit LaserRequire(index);
		}
	}

	qDebug() << "Return to relative ORG.";
	if (!USING_SIMULATION_MODE) {
		dmc_home_move(0, 2);
		while (dmc_check_done(0, 2) == 0) { qApp->processEvents(); }	// Z轴先复位
		dmc_pmove(0, 0, 0, 1);
		dmc_pmove(0, 1, 0, 1);
		while (dmc_check_done(0, 0) == 0) { qApp->processEvents(); }
		while (dmc_check_done(0, 1) == 0) { qApp->processEvents(); }
		dmc_pmove(0, 2, 0, 1);
		while (dmc_check_done(0, 2) == 0) { qApp->processEvents(); }
	}
}