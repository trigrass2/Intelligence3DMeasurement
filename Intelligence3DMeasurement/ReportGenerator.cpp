#include <QFile>
#include <QTextStream>
#include <QMessageBox>
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
		"<td><B>生产单位 Manufactory：</B></td><td>%2</td>"
		"<td><B>生产日期 Production Date：</B></td><td>%3</td>"
		"<td><B>巡检日期 Mesurement Date：</B></td><td>%4</td>"
		"</tr>"
		"<tr>"
		"<td><B>零件名称 Part Name：</B></td><td>%5</td>"
		"<td><B>产品型号 Product Model：</B></td><td>%6</td>"
		"<td><B>订单号 Order Number：</B></td>%7<td></td>"
		"</tr>"
		"<tr>"
		"<td><B>工序名称 Process Name：</B></td><td>%8</td>"
		"<td><B>工位编号 Station：</B></td><td>%9</td>"
		"</tr>"
		"</table>"
		"<table border = '1' width = '100%' cellspacing = '0' cellpadding = '5'>"
		"<tr>"
		"<td colspan = '2' rowspan = '2' align = 'center'>"
		"<font size = '5'><B>检测项目<br>Measure Item</B></font>"
		"</td>"
		"<td colspan = '7' align = 'center'>"
		"<font size = '5'><B>巡检记录 IPQC Record</B></font>"
		"</td>"
		"<td rowspan = '2' align = 'center'>"
		"<font size = '5'><B>检测结果<br>Result</B></font>"
		"</td>"
		"<td rowspan = '2' align = 'center'>"
		"<font size = '5'><B>不良结果跟进<br>Follow - up Action</B></font>"
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

	m_report.append(headerTemplate.arg(Global::g_projectInfo.projectName)
		.arg(Global::g_projectInfo.manufactory)
		.arg(Global::g_projectInfo.productionDate)
		.arg(Global::g_projectInfo.mesurementDate)
		.arg(Global::g_projectInfo.partName)
		.arg(Global::g_projectInfo.productModel)
		.arg(Global::g_projectInfo.orderNumber)
		.arg(Global::g_projectInfo.processName)
		.arg(Global::g_projectInfo.station)
	);

	for (int i = 0; i < Global::g_projectInfo.camSequence.count(); ++i) {
		QString conclusionStr;
		QStringList retStr;
		double u = Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].dStandard +
			Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].dUpper;
		double l = Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].dStandard +
			Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].dLower;
		
		bool isNG = false;
		for (int j = 0; j < 7; ++j) {
			if (Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].ret[j] >= u ||
				Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].ret[j] <= l) {
				retStr << "<font color='red'>" + QString::number(
					Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].ret[j]) +
					"</font>";
				isNG = true;
			}
			else {
				retStr << QString::number(
					Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].ret[j]);
			};
		}
		if (isNG) {
			Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].conclusion ="NG";
			conclusionStr = "<font color='red'><B>NG</B></font>";
		}
		else {
			Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].conclusion ="OK";
			conclusionStr = "<font color='blue'><B>OK</B></font>";
		}

		m_report.append(dataTemplate.arg(Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].content)
			.arg(QString::number(
				Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].dStandard) + "|" +
				QString::number(
					Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].dLower) + "|" +
				QString::number(
					Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].dUpper))
			.arg(retStr[0]).arg(retStr[1]).arg(retStr[2]).arg(retStr[3]).arg(retStr[4])
			.arg(retStr[5]).arg(retStr[6]).arg(conclusionStr)
		);
	}

	for (int i = 0; i < Global::g_projectInfo.laserItems.count(); ++i) {
		QString conclusionStr;
		QStringList retStr;
		double u = Global::g_projectInfo.laserItems[i].dStandard +
			Global::g_projectInfo.laserItems[Global::g_projectInfo.camSequence[i]].dUpper;
		double l = Global::g_projectInfo.laserItems[i].dStandard +
			Global::g_projectInfo.laserItems[i].dLower;
		
		bool isNG = false;
		for (int j = 0; j < 7; ++j) {
			if (Global::g_projectInfo.laserItems[i].ret[j] >= u ||
				Global::g_projectInfo.laserItems[i].ret[j] <= l) {
				retStr << "<font color='red'>" + QString::number(
					Global::g_projectInfo.laserItems[i].ret[j]) +
					"</font>";
				isNG = true;
			}
			else {
				retStr << QString::number(Global::g_projectInfo.laserItems[i].ret[j]);
			};
		}
		if (isNG) {
			Global::g_projectInfo.laserItems[i].conclusion = "NG";
			conclusionStr = "<font color='red'><B>NG</B></font>";
		}
		else {
			Global::g_projectInfo.laserItems[i].conclusion = "OK";
			conclusionStr = "<font color='blue'><B>OK</B></font>";
		}

		m_report.append(dataTemplate.arg(Global::g_projectInfo.laserItems[i].content)
			.arg(QString::number(Global::g_projectInfo.laserItems[i].dStandard) + "|" +
				QString::number(Global::g_projectInfo.laserItems[i].dLower) + "|" +
				QString::number(Global::g_projectInfo.laserItems[i].dUpper))
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
	QDialog::showEvent(e);
}

void ReportGenerator::closeEvent(QCloseEvent *e)
{
	if (m_isNew) {
		if (QMessageBox::warning(this, "保存报表", "测量结果还未保存，确认丢弃吗？",
			QMessageBox::Cancel | QMessageBox::Ok, QMessageBox::Cancel)== QMessageBox::Cancel){
			return;
		}
	}
	QDialog::closeEvent(e);
}

void ReportGenerator::on_saveBtn_clicked()
{
	QString fileName = REPORT_DIRECTORY + Global::g_projectInfo.projectName + "_" + Global::g_projectInfo.mesurementDate + ".html";
	QFile reportFile(fileName);
	reportFile.open(QIODevice::WriteOnly);

	QTextStream ofs(&reportFile);
	ofs << m_report;
	ofs << "\n";

	if (DatabaseBrowser::WriteIn(ui.syncSQL->isChecked())) {
		m_isNew = false;
		close();
	}
}