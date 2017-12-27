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
	int nType;							///< type of measurement
	QString content;					///< content of measurement
	QVector<QPointF> cadPos;			///< control points(x-y) of measurement
	QVector<QPointF> feedbackPos;		///< real coordinate
	int nCADHeight;						///< camera height
	bool bIsInverted;					///< invert flag
	int nTemp = 0;						///< reserved variable
	double dStandard;
	double dUpper;
	double dLower;
	double ret[7] = { 0,0,0,0,0,0,0 };	///< return
	QString conclusion;					///< result
};

struct LASERITEM {
	int nType;
	QString content;
	QVector<QPointF> cadPos;
	QVector<QPointF> feedbackPos;
	QVector<double> directReading;
	int nCADHeight;						///< laser height
	double dStandard;
	double dUpper;
	double dLower;
	double ret[7] = {0,0,0,0,0,0,0};
	QString conclusion;
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
	int nSubGroup;		///< Data Process Config
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
	static bool g_isLocked;

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
	static HObject g_image;
	static HTuple AcqHandle;
	static HTuple hv_window;
	static QMap<QString, HObject> halconData;
};

