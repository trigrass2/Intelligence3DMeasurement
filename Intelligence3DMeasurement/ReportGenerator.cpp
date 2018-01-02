#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>
#include "ReportGenerator.h"

#include "DB_RELATIVE\DatabaseBrowser.h"
#include "Global.h"


ReportGenerator::ReportGenerator(QWidget *parent)
	: QDialog(parent), m_isNew(false)
{
	ui.setupUi(this);
}

void ReportGenerator::RefreshData()
{
	m_report.clear();
	QString headerTemplate = "<!DOCTYPE html><html xmlns = 'http://www.w3.org/1999/xhtml'>"
		"<head><meta charset = 'gbk'/><title>Global::g_projectInfo.projectName</title></head>"
		"<body><table border = '0' width = '100%' cellspacing = '0' cellpadding = '6'>"
		"<tr><td colspan = '6' align = 'center'>"
		"<font size = '6'><B>%1</B></font>"
		"</td></tr>"
		"<tr>"
		"<td><B>������λ Manufactory��</B></td><td>%2</td>"
		"<td><B>�������� Production Date��</B></td><td>%3</td>"
		"<td><B>Ѳ������ Mesurement Date��</B></td><td>%4</td>"
		"</tr>"
		"<tr>"
		"<td><B>������� Part Name��</B></td><td>%5</td>"
		"<td><B>��Ʒ�ͺ� Product Model��</B></td><td>%6</td>"
		"<td><B>������ Order Number��</B></td><td>%7</td>"
		"</tr>"
		"<tr>"
		"<td><B>�������� Process Name��</B></td><td>%8</td>"
		"<td><B>��λ��� Station��</B></td><td>%9</td>"
		"</tr>"
		"</table>"
		"<table border = '1' width = '100%' cellspacing = '0' cellpadding = '5'>"
		"<tr>"
		"<td colspan = '2' rowspan = '2' align = 'center'>"
		"<font size = '5'><B>�����Ŀ<br>Measure Item</B></font>"
		"</td>"
		"<td colspan = '7' align = 'center'>"
		"<font size = '5'><B>Ѳ���¼ IPQC Record</B></font>"
		"</td>"
		"<td rowspan = '2' align = 'center'>"
		"<font size = '5'><B>�����<br>Result</B></font>"
		"</td>"
		"<td rowspan = '2' align = 'center'>"
		"<font size = '5'><B>�����������<br>Follow - up Action</B></font>"
		"</td>"
		"</tr>"
		"<tr>"
		"<td align = 'center'><B>1</B></td>"
		"<td align = 'center'><B>2</B></td>"
		"<td align = 'center'><B>3</B></td>"
		"<td align = 'center'><B>4</B></td>"
		"<td align = 'center'><B>5</B></td>"
		"<td align = 'center'><B>6</B></td>"
		"<td align = 'center'><B>7</B></td>"
		"</tr>";
	QString dataTemplate = "<tr>"
		"<td align = 'center'>%1</td><td align = 'center'>%2</td>"
		"<td align = 'center'>%3</td>"
		"<td align = 'center'>%4</td>"
		"<td align = 'center'>%5</td>"
		"<td align = 'center'>%6</td>"
		"<td align = 'center'>%7</td>"
		"<td align = 'center'>%8</td>"
		"<td align = 'center'>%9</td>"
		"<td align = 'center'>%10</td><td align = 'center'> </td>"
		"</tr>";

	m_report.append(headerTemplate.arg(Global::g_projectInfo.projectName+"_"+
	QString::number(Global::g_projectInfo.nSubGroupSize))
		.arg(Global::g_projectInfo.manufactory)
		.arg(Global::g_projectInfo.productionDate)
		.arg(Global::g_projectInfo.mesurementDate)
		.arg(Global::g_projectInfo.partName)
		.arg(Global::g_projectInfo.productModel)
		.arg(Global::g_projectInfo.orderNumber)
		.arg(Global::g_projectInfo.processName)
		.arg(Global::g_projectInfo.station)
	);

	for (int i = 0; i < Global::g_projectInfo.camMeasurePath.count(); ++i) {
		QString conclusionStr;
		QStringList retStr;
		double u = Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].dStandardD +
			Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].dUpperD;
		double l = Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].dStandardD +
			Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].dLowerD;
		
		bool isNG = false;
		for (int j = 0; j < 7; ++j) {
			if (Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].processedData[j] >= u ||
				Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].processedData[j] <= l) {
				retStr << "<font color='red'>" + QString::number(
					Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].processedData[j]) +
					"</font>";
				isNG = true;
			}
			else {
				retStr << QString::number(
					Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].processedData[j]);
			};
		}
		if (isNG) {
			Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].conclusion ="NG";
			conclusionStr = "<font color='red'><B>NG</B></font>";
		}
		else {
			Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].conclusion ="OK";
			conclusionStr = "<font color='blue'><B>OK</B></font>";
		}

		m_report.append(dataTemplate.arg(Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].content)
			.arg(QString::number(
				Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].dStandardD) + "|" +
				QString::number(
					Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].dLowerD) + "|" +
				QString::number(
					Global::g_projectInfo.camItemList[Global::g_projectInfo.camMeasurePath[i]].dUpperD))
			.arg(retStr[0]).arg(retStr[1]).arg(retStr[2]).arg(retStr[3]).arg(retStr[4])
			.arg(retStr[5]).arg(retStr[6]).arg(conclusionStr)
		);
	}

	for (int i = 0; i < Global::g_projectInfo.laserItemList.count(); ++i) {
		QString conclusionStr;
		QStringList retStr;
		double u = Global::g_projectInfo.laserItemList[i].dStandardD +
			Global::g_projectInfo.laserItemList[i].dUpperD;
		double l = Global::g_projectInfo.laserItemList[i].dStandardD +
			Global::g_projectInfo.laserItemList[i].dLowerD;
		
		bool isNG = false;
		for (int j = 0; j < 7; ++j) {
			if (Global::g_projectInfo.laserItemList[i].processedData[j] >= u ||
				Global::g_projectInfo.laserItemList[i].processedData[j] <= l) {
				retStr << "<font color='red'>" + QString::number(
					Global::g_projectInfo.laserItemList[i].processedData[j]) +
					"</font>";
				isNG = true;
			}
			else {
				retStr << QString::number(Global::g_projectInfo.laserItemList[i].processedData[j]);
			};
		}
		if (isNG) {
			Global::g_projectInfo.laserItemList[i].conclusion = "NG";
			conclusionStr = "<font color='red'><B>NG</B></font>";
		}
		else {
			Global::g_projectInfo.laserItemList[i].conclusion = "OK";
			conclusionStr = "<font color='blue'><B>OK</B></font>";
		}

		m_report.append(dataTemplate.arg(Global::g_projectInfo.laserItemList[i].content)
			.arg(QString::number(Global::g_projectInfo.laserItemList[i].dStandardD) + "|" +
				QString::number(Global::g_projectInfo.laserItemList[i].dLowerD) + "|" +
				QString::number(Global::g_projectInfo.laserItemList[i].dUpperD))
			.arg(retStr[0]).arg(retStr[1]).arg(retStr[2]).arg(retStr[3]).arg(retStr[4])
			.arg(retStr[5]).arg(retStr[6]).arg(conclusionStr)
		);
	}

	m_report.append("</table></body>");
	m_isNew = true;
}

void ReportGenerator::showEvent(QShowEvent *e)
{
	ui.reportArea->clear();
	ui.reportArea->append(m_report);
	if (Global::IndexGen(false) != 1) {ui.saveBtn->setDisabled(true);}
	else {ui.saveBtn->setEnabled(true);}
	QDialog::showEvent(e);
}

void ReportGenerator::closeEvent(QCloseEvent *e)
{
	if (m_isNew) {
		if (Global::IndexGen(false) == 1) {
			if (QMessageBox::warning(this, "���汨��", "���������δ���棬ȷ�϶�����",
				QMessageBox::Cancel | QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Cancel) {
				e->ignore();
			}
			else { QDialog::closeEvent(e); }
		}
	}
}

void ReportGenerator::on_saveBtn_clicked()
{
	QString fileName = REPORT_DIRECTORY + Global::g_projectInfo.projectName + "_" +
		QString::number(Global::g_projectInfo.nSubGroupSize)+"_"+
		Global::g_projectInfo.mesurementDate.split(" ").first() + ".html";
	QFile reportFile(fileName);
	reportFile.open(QIODevice::WriteOnly);

	QTextStream ofs(&reportFile);
	ofs << m_report;
	ofs << "\n";

	if (DatabaseBrowser::WriteIn(ui.syncSQL->isChecked())) {
		qDebug() << "SAVE sql";
		m_isNew = false;
		close();
	}
	qDebug() << "SAVE report";
}