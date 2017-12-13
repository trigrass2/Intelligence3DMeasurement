#include "Global.h"

double Global::g_pulseEquivalent;

double Global::g_xyLineVectorVel;
double Global::g_zVel;

double Global::g_laserBiasX;
double Global::g_laserBiasY;
double Global::g_laserBiasZ;

bool Global::g_isDBConnected;
bool Global::g_isLaserConnected ;

int Global::g_sampleVolume;
bool Global::g_enable2DMode;
bool Global::g_enableQuietMode;
double Global::g_camViewField;

ProjectInfo Global::g_projectInfo;

bool Global::g_enableCamCtrl = true;
HObject Global::g_image;
HTuple Global::AcqHandle;
HTuple Global::hv_window;
QMap<QString, HObject> Global::halconData;