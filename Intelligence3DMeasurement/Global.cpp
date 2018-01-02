#include "Global.h"
#include <Qdebug>

bool Global::g_lockConfig;

double Global::g_pulseEquivalent;

double Global::g_xyLineVectorVel;
double Global::g_zVel;

double Global::g_laserBiasX;
double Global::g_laserBiasY;
double Global::g_laserBiasZ;

bool Global::g_isLaserConnected;

bool Global::g_enable2DMode;
bool Global::g_enableQuietMode;
double Global::g_camViewField;

ProjectInfo Global::g_projectInfo;
SPC Global::g_spc;

bool Global::g_enableCamCtrl = true;
HObject Global::g_curPhoto;
HTuple Global::acqHandle;
HTuple Global::hv_window;

int Global::g_index;

int Global::IndexGen(bool doSubstract)
{
	if (doSubstract) {
		if (g_index > 0) { g_index--; }
		if (0 == g_index) { Sync(); }
		return g_index;
	}
	return g_index;
}
