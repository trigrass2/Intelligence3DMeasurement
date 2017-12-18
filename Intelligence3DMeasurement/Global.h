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
	STN
};

struct CAMERAITEM {
	int type;						///< type of measurement
	QString content;				///< content of measurement
	QVector<QPointF> ctrlNodes;		///< control points(x-y) of measurement
	int nHeight;					///< camera height
	bool bIsInverted;				///< invert flag
	int nTemp = 0;					///< reserved variable
	double dStandard;
	double dUpper;
	double dLower;
	double ret = 0.0;				///< return
	QString conclusion="N";
};

struct LASERITEM {
	QString content;			///< content of measurement
	QVector<QPointF> nodes;		///< points(x-y) of measurement
	int nHeight;				///< laser height
	double dStandard;
	double dUpper;
	double dLower;
	double ret = 0.0;			///< result
	QString conclusion= "N";
};

struct ProjectInfo {
	QString projectName;
	QString cadFile;
	QString partName;
	QString productModel;
	QString orderNumber;
	QString manufactory;
	QString productionDate;
	QString mesurementDate;
	QString processName;
	QString station;
	QVector<int> camSequence;
	QVector<CAMERAITEM> camearItems;
	QVector<LASERITEM> laserItems;
	QPointF startPoint;
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
	static int g_sampleVolume;
	static bool g_enable2DMode;	
	static bool g_enableQuietMode;
	static double g_camViewField;

	static ProjectInfo g_projectInfo;
	static SPC g_spc;

	// Halcon
	static bool g_enableCamCtrl;
	static HObject g_image;
	static HTuple AcqHandle;
	static HTuple hv_window;
	static QMap<QString, HObject> halconData;
};

