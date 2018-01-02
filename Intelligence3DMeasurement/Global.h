#pragma once

#include <QString>
#include <QVector>
#include <QPointF>
#include <QMap>
#include <QDateTime>

#include "HALCONCpp/HalconCpp.h"
#include "HALCONCpp/HDevThread.h"

#define ENABLE_VISION_MODULE false
#define ENABLE_MOTION_MODULE false

#define PROJECT_DIRECTORY "../Projects/"
#define CAD_DIRECTORY "../CADs/"
#define REPORT_DIRECTORY "../Reports/"

using namespace HalconCpp;


enum MeasureType {
	L2LD,
	L2LA,
	P2PD,
	P2LD,
	RAD,
	AA,
	CIC,
	LEN,
	STN,
	FTN
};

struct CAMERAITEM {
	int nType;
	QString content = "content";
	double dStandardD = 0;
	double dUpperD = 0;
	double dLowerD = 0;

	bool bPosListInverted;
	QVector<QPointF> cadPosList;
	QVector<QPoint> feedbackPosList;
	int nCADHeight = 0;
	
	QVector<HObject> sampleData;
	double processedData[7] = { 0,0,0,0,0,0,0 };
	QString conclusion = "NG";

	int nTemp = 0;
};

struct LASERITEM {
	int nType;
	QString content = "content";
	double dStandardD = 0;
	double dUpperD = 0;
	double dLowerD = 0;

	QVector<QPointF> cadPosList;
	QVector<QPoint> feedbackPosList;
	int nCADHeight = 0;

	QVector<double> sampleData;
	double processedData[7] = { 0,0,0,0,0,0,0 };
	QString conclusion = "NG";
};

struct ProjectInfo {
	QString projectName;
	QString cadFileName;
	QString partName;
	QString productModel;
	QString orderNumber;
	QString manufactory;
	QString productionDate;
	QString mesurementDate;
	QString processName;
	QString station;
	int nSubGroupSize = 1;;

	QVector<CAMERAITEM> camItemList;
	QVector<LASERITEM> laserItemList;

	QVector<int> camMeasurePath;
	//QVector<int> laserMeasurePath;
	QPointF startCADPos;
};

struct SPC {
	QString table;
	QString item;
	QDateTime lTime;
	QDateTime rTime;
	bool bF0 = true;
	bool bF1 = false;
	bool bF2 = false;
	bool bF3 = false;
};


class Global
{
public:
	static bool g_lockConfig;

	static double g_pulseEquivalent;

	// Mesure Speed
	static double g_xyLineVectorVel;
	static double g_zVel;
	
	// Laser Offset Coordinate
	static double g_laserBiasX;
	static double g_laserBiasY;
	static double g_laserBiasZ;

	static bool g_isLaserConnected;

	// Data Process Config
	static bool g_enable2DMode;
	static bool g_enableQuietMode;
	static double g_camViewField;

	static ProjectInfo g_projectInfo;
	static SPC g_spc;

	// Halcon
	static bool g_enableCamCtrl;
	static HObject g_curPhoto;
	static HTuple acqHandle;
	static HTuple hv_window;

	static int IndexGen(bool doSubstract);
	static void Sync() { g_index = g_projectInfo.nSubGroupSize; };

private:
	static int g_index;
};

