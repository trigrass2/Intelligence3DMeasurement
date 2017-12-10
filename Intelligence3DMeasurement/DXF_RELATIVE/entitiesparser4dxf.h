#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QVector>
#include <QFile>

enum {
	DXF_ALIGNED = 65539,
	DXF_ANGULAR = 65539,
	DXF_RADIAL = 65539,
	DXF_POLY = 65537,
	DXF_ELLIPSE = 65538,
	DXF_PATH = 65540,
	DXF_LASER = 65541,
	DXF_MARK = 65542
};

struct ALIGNEDDIM {
	QPointF lmtStart;
	QPointF lmtEnd;
	QPointF lineAnchor;
	QPointF textMid;
    QString rawText;
	QString standardValue;
	double nRotateFromX;
	// below varities are availiable only if "rawText" is not empty
	QString frontText;
	QString backText;
	QString upperDeviation;
	QString lowerDeviation;
};

struct ANGULARDIM {
	QPointF line1Start;
	QPointF line1End;
	QPointF line2Start;
	QPointF line2End;
	QPointF textMid;
    QString rawText;
	QString standardValue;
	// below varities are availiable only if "rawText" is not empty
	QString frontText;
	QString backText;
	QString upperDeviation;
	QString lowerDeviation;
};

struct RADIALDIM {
	QPointF lineAnchor;
	QPointF lineEnd;
	QPointF textMid;
	QString rawText;
	QString standardValue;
	bool bIsRadius;		///< radius or diameter
	// below varities are availiable only if "rawText" is not empty
	QString frontText;
	QString backText;
	QString upperDeviation;
	QString lowerDeviation;
};

struct ARC {
	QPointF center;
    double nRadius;
    double nAngleStart;		///< degree
    double nAngleEnd;
};

struct CIRCLE {
	QPointF center;
    double nRadius;
};

struct ELLIPSE {
	QPointF center;
	QPointF longAxisEnd;
    double nAxisRatio;		///< short : long
    double nAngleStart;		///< radian(= degree/180*pi)
    double nAngleEnd;
};

struct LINE {
	QPointF start;
	QPointF end;
};

struct LWPOLYLINE {
    int nType;		///< polyline type.
    int nNum;		///< total points number.
    QVector<QPointF> ctrlPoints;
};

/**
 * @brief parser circle、ellipse、arc、line、polyline from dxf file
 */
class EntitiesParser4DXF
{

public:
    EntitiesParser4DXF(const QString &filePath);
    ~EntitiesParser4DXF();

    QVector<ALIGNEDDIM> readAlignedDimData() const;
    QVector<ANGULARDIM> readAngularDimData() const;
    QVector<RADIALDIM> readRadialDimData() const;
    QVector<ARC> readArcData() const;
    QVector<CIRCLE> readCircleData() const;
    QVector<ELLIPSE> readEllipseData() const;
    QVector<LINE> readLineData() const;
    QVector<LWPOLYLINE> readPolylineData() const;

    void covPolyline2Line();
	QStringList Dimension2ObviousText(QString rawLine);

private:
    QVector<ALIGNEDDIM> m_alignedDimData;
    QVector<ANGULARDIM> m_angularDimData;
    QVector<RADIALDIM> m_radialDimData;
    QVector<ARC> m_arcData;
    QVector<CIRCLE> m_circleData;
    QVector<ELLIPSE> m_ellipseData;
    QVector<LINE> m_lineData;
    QVector<LWPOLYLINE> m_polylineData;
    QFile m_dxf;
	bool m_isAvailable;

};