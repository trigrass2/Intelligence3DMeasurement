#pragma once

#include <QString>
#include <QVector>
#include <QPointF>

#define USING_SIMULATION_MODE true
#define REPLACE_HALCON_LIB false

#define PROJECT_DIRECTORY "../Projects/"
#define CAD_DIRECTORY "../CADs/"
#define REPORT_DIRECTORY "../Reports/"

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

/**
 * @brief Camera measurement's item
 */
struct CAMERAITEM {
	int type;					///< type of measurement
	QString content;				///< content of measurement
	QVector<QPointF> ctrlNodes;		///< control points(x-y) of measurement
	int nHeight;					///< camera height
	bool bIsInverted;				///< invert flag
	int nTemp;						///< reserved variable
	QString ret;					///< result
};
/**
 * @brief Laser measurement's item
 */
struct LASERITEM {
	QString content;			///< content of measurement
	QVector<QPointF> nodes;		///< points(x-y) of measurement
	int nHeight;				///< laser height
	QString ret;				///< result
};
/**
 * @brief Infomation of mesurement project
 */
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

	static bool g_isLaserConnected;

	// Data Process Config
	static int g_sampleVolume;
	static bool g_enable2DMode;	
	static bool g_enableQuietMode;
	static double g_camViewField;

	static ProjectInfo g_projectInfo;
};

