#include <QTextStream>
#include <qmath.h>
#include "entitiesparser4dxf.h"


EntitiesParser4DXF::EntitiesParser4DXF(const QString &path):
	m_isAvailable(false)
{
    m_dxf.setFileName(path);
    if (m_dxf.open(QIODevice::ReadOnly)) {
        QTextStream fstream(&m_dxf);
        QString rawLine;

        QRegExp startMark("ENTITIES");
		bool isEntity = false;

		QRegExp arcMark("ARC");
		bool isArc = false;
		QRegExp circleMark("CIRCLE");
		bool isCircle = false;
		QRegExp ellipseMark("ELLIPSE");
		bool isEllipse = false;
		QRegExp lineMark("LINE");
		bool isLine = false;
		QRegExp lwPolylineMark("LWPOLYLINE");
		bool isLWPolyline = false;
        QRegExp dimMark("DIMENSION");
        bool isDimension = false;

        QRegExp subMarkAcDbCircle("AcDbCircle");
        QRegExp subMarkAcDbArc("AcDbArc");
        QRegExp subMarkAcDbEllipse("AcDbEllipse");
        QRegExp subMarkAcDbLine("AcDbLine");
        QRegExp subMarkAcDbPolyline("AcDbPolyline");
        bool isAcDbPolyline = false;
        QRegExp subMarkAcDbDimension("AcDbDimension");
        bool isAcDbDimension = false;
        QRegExp subMarkAcDbAlignedDim("AcDbAlignedDimension");
        QRegExp subMarkAcDbRadialDim("AcDbRadialDimension");
        QRegExp subMarkAcDbDiametricDim("AcDbDiametricDimension");
        QRegExp subMarkAcDb2LineAngularDim("AcDb2LineAngularDimension");

        QRegExp qRegE_End("ENDSEC");

		ARC arc;
		CIRCLE circle;
		ELLIPSE ellipse;
		LINE line;
		LWPOLYLINE lwPolyline;
		ALIGNEDDIM alignedDim;
		RADIALDIM radialDim;
		ANGULARDIM angularDim;
		double dimLAX, dimLAY, dimTMX, dimTMY;
		QString text, value;

        while(!fstream.atEnd()) {
            rawLine = fstream.readLine();
			if (startMark.indexIn(rawLine) != -1 && !isEntity) { isEntity = true; }		// ENTITIES start
            if (qRegE_End.indexIn(rawLine)==-1 && isEntity) {							// ENTITIES content
                // ARC
				if (arcMark.indexIn(rawLine) != -1 && !isArc) { isArc = true; }
                if (subMarkAcDbCircle.indexIn(rawLine)!=-1 && isArc) {
                    rawLine = fstream.readLine();
                    if (rawLine != " 39" && isArc) {
                        arc.center.setX(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        arc.center.setY(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        arc.nRadius = fstream.readLine().toDouble();
                    }
					else if (rawLine == " 39" && isArc) {
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        arc.center.setX(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        arc.center.setY(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        arc.nRadius = fstream.readLine().toDouble();
                    }
                }
                if (subMarkAcDbArc.indexIn(rawLine)!=-1 && isArc) {
                    rawLine = fstream.readLine();
                    arc.nAngleStart = fstream.readLine().toDouble();
                    rawLine = fstream.readLine();
                    arc.nAngleEnd = fstream.readLine().toDouble();
                    isArc = false;
                    m_arcData.append(arc);
                }
                // CIRCLE
				if (circleMark.indexIn(rawLine) != -1 && !isCircle) { isCircle = true; }
                if (subMarkAcDbCircle.indexIn(rawLine)!=-1 && isCircle) {
                    rawLine = fstream.readLine();
                    if (rawLine != " 39" && isCircle) {
                        circle.center.setX(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        circle.center.setY(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        circle.nRadius = fstream.readLine().toDouble();
                    }
					else if (rawLine == " 39" && isCircle) {
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        circle.center.setX(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        circle.center.setY(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        circle.nRadius = fstream.readLine().toDouble();
                    }
                    isCircle = false;
                    m_circleData.append(circle);
                }
                // ELLIPSE
				if (ellipseMark.indexIn(rawLine) != -1 && !isEllipse) { isEllipse = true; }
                if (subMarkAcDbEllipse.indexIn(rawLine)!=-1 && isEllipse) {
                    rawLine = fstream.readLine();
                    ellipse.center.setX(fstream.readLine().toDouble());
                    rawLine = fstream.readLine();
                    ellipse.center.setY(fstream.readLine().toDouble());
                    rawLine = fstream.readLine();
                    rawLine = fstream.readLine();
                    rawLine = fstream.readLine();
                    ellipse.longAxisEnd.setX(fstream.readLine().toDouble());
                    rawLine = fstream.readLine();
                    ellipse.longAxisEnd.setY(fstream.readLine().toDouble());
                    rawLine = fstream.readLine();
                    rawLine = fstream.readLine();
                    rawLine = fstream.readLine();
                    if (rawLine != "210" && isEllipse) {
                        ellipse.nAxisRatio = fstream.readLine().toDouble();
                        rawLine = fstream.readLine();
                        ellipse.nAngleStart = fstream.readLine().toDouble();
                        rawLine = fstream.readLine();
                        ellipse.nAngleEnd = fstream.readLine().toDouble();
                    }
					else if (rawLine == "210" && isEllipse) {
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        ellipse.nAxisRatio = fstream.readLine().toDouble();
                        rawLine = fstream.readLine();
                        ellipse.nAngleStart = fstream.readLine().toDouble();
                        rawLine = fstream.readLine();
                        ellipse.nAngleEnd = fstream.readLine().toDouble();
                    }
                    isEllipse = false;
                    m_ellipseData.append(ellipse);
                }
                // LINE
				if (lineMark.indexIn(rawLine) != -1 && !isLine) { isLine = true; }
                if (subMarkAcDbLine.indexIn(rawLine)!=-1 && isLine) {
                    rawLine = fstream.readLine();
                    if (rawLine != " 39" && isLine) {
						line.start.setX(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
						line.start.setY(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
						line.end.setX(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        line.end.setY(fstream.readLine().toDouble());
                    }
					else if (rawLine == " 39" && isLine) {
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
						line.start.setX(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
						line.start.setY(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        rawLine = fstream.readLine();
                        line.end.setX(fstream.readLine().toDouble());
                        rawLine = fstream.readLine();
                        line.end.setY(fstream.readLine().toDouble());
                    }
                    isLine = false;
                    m_lineData.append(line);
                }
                // LWPOLYLINE
				if (lwPolylineMark.indexIn(rawLine) != -1 && !isLWPolyline) { isLWPolyline = true; }
                if (subMarkAcDbPolyline.indexIn(rawLine)!=-1 && isLWPolyline) {
                    lwPolyline.ctrlPoints.clear();
                    rawLine = fstream.readLine();
                    lwPolyline.nNum = fstream.readLine().toInt();
                    rawLine = fstream.readLine();
                    lwPolyline.nType = fstream.readLine().toInt();
                    rawLine = fstream.readLine();
                    isAcDbPolyline = true;
                }
                if (rawLine == " 10" && isLWPolyline && isAcDbPolyline) {
                    for (int i=0; i<lwPolyline.nNum; ++i) {
                        double x = fstream.readLine().toDouble();
                        fstream.readLine();
                        double y = fstream.readLine().toDouble();
                        lwPolyline.ctrlPoints.append(QPointF(x, y));
                        fstream.readLine();
                    }
                    isAcDbPolyline = false;
                    isLWPolyline = false;
                    m_polylineData.append(lwPolyline);
                }
                // DIMENSION
				if (dimMark.indexIn(rawLine) != -1 && !isDimension) { isDimension = true; }
                if (subMarkAcDbDimension.indexIn(rawLine)!=-1 && isDimension) {
                    isAcDbDimension = true;
					text.clear();
					value.clear();
					alignedDim.rawText.clear();
					alignedDim.standardValue.clear();
					radialDim.rawText.clear();
					radialDim.standardValue.clear();
					angularDim.rawText.clear();
					angularDim.standardValue.clear();
                    fstream.readLine();
                    fstream.readLine();
                    fstream.readLine();
                    dimLAX = fstream.readLine().toDouble();
                    fstream.readLine();
                    dimLAY = fstream.readLine().toDouble();
                    fstream.readLine();
                    fstream.readLine();
                    fstream.readLine();
                    dimTMX = fstream.readLine().toDouble();
                    fstream.readLine();
                    dimTMY = fstream.readLine().toDouble();
                }
				if (rawLine == "  1" && isDimension && isAcDbDimension) { text = fstream.readLine(); }
				if (rawLine == " 42" && isDimension && isAcDbDimension) {
					value = fstream.readLine();
					double cut3 = ((int)(value.toDouble() * 1000)) / 1000.0;		// cut decimal to 3
					value = QString::number(cut3);
				}
				if (subMarkAcDbAlignedDim.indexIn(rawLine) != -1 && isDimension && isAcDbDimension) {
					alignedDim.rawText = text;
					alignedDim.standardValue = value;
					alignedDim.lineAnchor.setX(dimLAX);
					alignedDim.lineAnchor.setY(dimLAY);
					alignedDim.textMid.setX(dimTMX);
					alignedDim.textMid.setY(dimTMY);
					fstream.readLine();
					alignedDim.lmtStart.setX(fstream.readLine().toDouble());
					fstream.readLine();
					alignedDim.lmtStart.setY(fstream.readLine().toDouble());
					fstream.readLine();
					fstream.readLine();
					fstream.readLine();
					alignedDim.lmtEnd.setX(fstream.readLine().toDouble());
					fstream.readLine();
					alignedDim.lmtEnd.setY(fstream.readLine().toDouble());
					fstream.readLine();
					fstream.readLine();
					rawLine = fstream.readLine();
					if (rawLine == " 50") { alignedDim.nRotateFromX = fstream.readLine().toDouble(); }
					else { alignedDim.nRotateFromX = 0.0; }
					isAcDbDimension = false;
					isDimension = false;
					// process raw text
					if (!alignedDim.rawText.isEmpty()) {
						QStringList list = Dimension2ObviousText(text);
						QString std = list.at(0);
						alignedDim.upperDeviation = list.at(1);
						alignedDim.lowerDeviation = list.at(2);
						list = std.split("&");
						if (list.count() > 1) {
							alignedDim.frontText = list.at(0);
							alignedDim.frontText.append(alignedDim.standardValue);
							alignedDim.backText = list.at(1);
						}
						else {
							alignedDim.frontText = std.replace("&", alignedDim.standardValue);
							alignedDim.backText.clear();
						}
					}
					m_alignedDimData.append(alignedDim);
				}
                if (subMarkAcDbRadialDim.indexIn(rawLine)!=-1 && isDimension && isAcDbDimension) {
                    radialDim.bIsRadius = true;
                    radialDim.rawText = text;
                    radialDim.standardValue = value;
                    radialDim.lineAnchor.setX(dimLAX);
                    radialDim.lineAnchor.setY(dimLAY);
					radialDim.textMid.setX(dimTMX);
					radialDim.textMid.setY(dimTMY);
                    fstream.readLine();
                    radialDim.lineEnd.setX(fstream.readLine().toDouble());
                    fstream.readLine();
                    radialDim.lineEnd.setY(fstream.readLine().toDouble());
                    isAcDbDimension = false;
                    isDimension = false;
					// process raw text
					if (!text.isEmpty()) {
						QStringList list = Dimension2ObviousText(text);
						QString std = list.at(0);
						radialDim.upperDeviation = list.at(1);
						radialDim.lowerDeviation = list.at(2);
						list = std.split("&");
						if (list.count() > 1) {
							radialDim.frontText = list.at(0);
							if (radialDim.bIsRadius) {
								radialDim.frontText.append("R");
								radialDim.frontText.append(radialDim.standardValue);
							}
							else {
								radialDim.frontText.append("Φ");
								radialDim.frontText.append(radialDim.standardValue);
							}
							radialDim.backText = list.at(1);
						}
						else {
							if (radialDim.bIsRadius) { radialDim.frontText = std.replace("&", "R" + radialDim.standardValue); }
							else { radialDim.frontText = std.replace("&", "Φ" + radialDim.standardValue); }
							radialDim.backText.clear();
						}
					}
                    m_radialDimData.append(radialDim);
                }
                if (subMarkAcDbDiametricDim.indexIn(rawLine)!=-1 && isDimension && isAcDbDimension) {
                    radialDim.bIsRadius = false;
                    radialDim.rawText = text;
                    radialDim.standardValue = value;
                    radialDim.lineAnchor.setX(dimLAX);
                    radialDim.lineAnchor.setY(dimLAY);
					radialDim.textMid.setX(dimTMX);
					radialDim.textMid.setY(dimTMY);
                    fstream.readLine();
					radialDim.lineEnd.setX(fstream.readLine().toDouble());
                    fstream.readLine();
					radialDim.lineEnd.setY(fstream.readLine().toDouble());
                    isAcDbDimension = false;
                    isDimension = false;
					// process raw text
					if (!text.isEmpty()) {
						QStringList list = Dimension2ObviousText(text);
						QString std = list.at(0);
						radialDim.upperDeviation = list.at(1);
						radialDim.lowerDeviation = list.at(2);
						list = std.split("&");
						if (list.count() > 1) {
							radialDim.frontText = list.at(0);
							if (radialDim.bIsRadius) {
								radialDim.frontText.append("R");
								radialDim.frontText.append(radialDim.standardValue);
							}
							else { 
								radialDim.frontText.append("Φ");
								radialDim.frontText.append(radialDim.standardValue);
							}
							radialDim.backText = list.at(1);
						}
						else {
							if (radialDim.bIsRadius) { radialDim.frontText = std.replace("&", "R" + radialDim.standardValue); }
							else { radialDim.frontText = std.replace("&", "Φ" + radialDim.standardValue); }
							radialDim.backText.clear();
						}
					}
                    m_radialDimData.append(radialDim);
                }
                if (subMarkAcDb2LineAngularDim.indexIn(rawLine)!=-1 && isDimension && isAcDbDimension) {
                    angularDim.rawText = text;
					angularDim.standardValue = QString::number(qRadiansToDegrees(value.toDouble()));
                    angularDim.textMid.setX(dimTMX);
                    angularDim.textMid.setY(dimTMY);
                    fstream.readLine();
                    angularDim.line1Start.setX(fstream.readLine().toDouble());
                    fstream.readLine();
                    angularDim.line1Start.setY(fstream.readLine().toDouble());
                    fstream.readLine();
                    fstream.readLine();
                    fstream.readLine();
                    angularDim.line1End.setX(fstream.readLine().toDouble());
                    fstream.readLine();
                    angularDim.line1End.setY(fstream.readLine().toDouble());
                    fstream.readLine();
                    fstream.readLine();
                    fstream.readLine();
                    angularDim.line2Start.setX(fstream.readLine().toDouble());
                    fstream.readLine();
                    angularDim.line2Start.setY(fstream.readLine().toDouble());
                    angularDim.line2End.setX(dimLAX);
                    angularDim.line2End.setY(dimLAY);
                    isAcDbDimension = false;
                    isDimension = false;
					// process raw text
					if (!text.isEmpty()) {
						QStringList list = Dimension2ObviousText(text);
						QString std = list.at(0);
						angularDim.upperDeviation = list.at(1);
						angularDim.lowerDeviation = list.at(2);
						list = std.split("&");
						if (list.count() > 1) {
							angularDim.frontText = list.at(0);
							angularDim.frontText.append(angularDim.standardValue + "°");
							angularDim.backText = list.at(1);
							angularDim.backText.replace("°", "");
						}
						else {
							angularDim.frontText = std.replace("&", angularDim.standardValue + "°");
							angularDim.backText.clear();
						}
					}
                    m_angularDimData.append(angularDim);
                }
            }
			else if (qRegE_End.indexIn(rawLine)!=-1 && isEntity) {						// ENTITIES end
                isEntity = false;
                break;
            }
        }
        fstream.flush();
		m_isAvailable = true;
    }
}

EntitiesParser4DXF::~EntitiesParser4DXF()
{
	if (m_isAvailable) { m_dxf.close(); }
}

QVector<ALIGNEDDIM> EntitiesParser4DXF::readAlignedDimData() const
{
	return m_alignedDimData;
}

QVector<ANGULARDIM> EntitiesParser4DXF::readAngularDimData() const
{
    return m_angularDimData;
}

QVector<RADIALDIM> EntitiesParser4DXF::readRadialDimData() const
{
    return m_radialDimData;
}

QVector<ARC> EntitiesParser4DXF::readArcData() const
{
    return m_arcData;
}

QVector<CIRCLE> EntitiesParser4DXF::readCircleData() const
{
    return m_circleData;
}

QVector<ELLIPSE> EntitiesParser4DXF::readEllipseData() const
{
    return m_ellipseData;
}

QVector<LINE> EntitiesParser4DXF::readLineData() const
{
    return m_lineData;
}

QVector<LWPOLYLINE> EntitiesParser4DXF::readPolylineData() const
{
    return m_polylineData;
}
/**
 * @brief 将多段线转化为单段线，此函数调用后m_polylineData将清空
 * @return
 */
void EntitiesParser4DXF::covPolyline2Line()
{
    LINE line;
    for (int i=0; i<m_polylineData.count(); ++i) {
        for (int j=0; j<m_polylineData[i].ctrlPoints.count()-1; ++j){
			line.start.setX(m_polylineData[i].ctrlPoints[j].x());
            line.start.setY(m_polylineData[i].ctrlPoints[j].y());
            line.end.setX(m_polylineData[i].ctrlPoints[j+1].x());
            line.end.setY(m_polylineData[i].ctrlPoints[j+1].y());
            m_lineData.append(line);
        }
    }
    m_polylineData.clear();
}

QStringList EntitiesParser4DXF::Dimension2ObviousText(QString rawLine)
{
	QStringList processed;  // ret
	processed << "&" << "" << "";
	// strip formal deviation
	QRegExp formalDeviation("\\s(\\+?[0-9][0-9]*(\\.[0-9]+)?)\\^\\s(\\-?[0-9][0-9]*(\\.[0-9]+)?)");
	if (formalDeviation.indexIn(rawLine) != -1) {
		processed[1] = formalDeviation.cap(1);
		processed[2] = formalDeviation.cap(3);
	}
	rawLine = rawLine.replace(formalDeviation, "");
	// strip informal deviation
	rawLine = rawLine.replace("\\S", "");				// remove "\S"
	rawLine = rawLine.replace("%%P", "UD");				// "%%P" -> "UD"
	rawLine = rawLine.replace("±", "UD");				// "±" -> "UD"
	QRegExp informalDeviation("UD([0-9][0-9]*(\\.[0-9]+)?)");
	if (informalDeviation.indexIn(rawLine) != -1) {
		processed[1] = "+" + informalDeviation.cap(1);
		processed[2] = "-" + informalDeviation.cap(1);
	}
	rawLine = rawLine.replace(informalDeviation, "");

	rawLine = rawLine.replace(QRegExp("\\\\U\\+2205"), "Φ");					// "\U+2205" -> "Φ"
	rawLine = rawLine.replace(QRegExp("\\\\H[0-9][0-9]*(\\.[0-9]+)?x"), "");	// remove "\H0.625x"
	rawLine = rawLine.replace(QRegExp("\\\\A[0-9]"), "");						// remove "\A1"
	rawLine = rawLine.replace(QRegExp("\\\\C256"), "");							// remove "\C256"
	rawLine = rawLine.replace(QRegExp("\\\\f[a-zA-Z]+\\|b[0-9]+\\|i[0-9]+\\|c[0-9]+\\|p[0-9]+"), "");	// remove "\fISOCPEUR|b0|i0|c0|p34"
	rawLine = rawLine.replace(QRegExp("\\;"), "");		// remove ";"
	rawLine = rawLine.replace(QRegExp("\\{"), "");		// remove "{"
	rawLine = rawLine.replace(QRegExp("\\}"), "");		// remove "}"
	rawLine = rawLine.replace(QRegExp("\\s"), "");		// remove "}"
	rawLine = rawLine.replace(QRegExp("<>"), "&");		// "}" -> "&"

	processed[0] = rawLine;
	return processed;
}
