#include <QFile>
#include <QTextStream>
#include <QMessageBox>
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
	m_data.clear();
	m_data.append(
		"<!DOCTYPE html>"
		"<html xmlns = 'http://www.w3.org/1999/xhtml'>"
		"<head>"
		"<meta charset = 'gbk'/>"
		"<title>Global::g_projectInfo.projectName</title>"
		"</head>"
		"<body>"
		"<table border = '0' width = '100%' cellspacing = '0' cellpadding = '6'>"
		"<tr>"
		"<td colspan = '6' align = 'center'>"
		"<font size = '6'><B>" + Global::g_projectInfo.projectName + "</B></font>"
		"</td>"
		"</tr>"
		"<tr>"
		"<td><B>������λ Manufactory��</B></td>"
		"<td>" + Global::g_projectInfo.manufactory + "</td>"
		"<td><B>�������� Production Date��</B></td>"
		"<td>" + Global::g_projectInfo.productionDate + "</td>"
		"<td><B>Ѳ������ Mesurement Date��</B></td>"
		"<td>" + Global::g_projectInfo.mesurementDate + "</td>"
		"</tr>"
		"<tr>"
		"<td><B>������� Part Name��</B></td>"
		"<td>" + Global::g_projectInfo.partName + "</td>"
		"<td><B>��Ʒ�ͺ� Product Model��</B></td>"
		"<td>" + Global::g_projectInfo.productModel + "</td>"
		"<td><B>������ Order Number��</B></td>"
		"<td>" + Global::g_projectInfo.orderNumber + "</td>"
		"</tr>"
		"<tr>"
		"<td><B>�������� Process Name��</B></td>"
		"<td>" + Global::g_projectInfo.processName + "</td>"
		"<td><B>��λ��� Station��</B></td>"
		"<td>" + Global::g_projectInfo.station + "</td>"
		"</tr>"
		"</table>"
		"<table border = '1' width = '100%' cellspacing = '0' cellpadding = '5'>"
		"<tr>"
		"<td colspan = '2' rowspan = '2' align = 'center'>"
		"<font size = '5'><B>�����Ŀ<br>Measure Item</B></font>"
		"</td>"
		"<td colspan = '6' align = 'center'>"
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
		"</tr>"
	);
	for (int i = 0; i < Global::g_projectInfo.camSequence.count(); ++i) {
		m_data.append(
			"<tr>"
			"<td colspan = '2' align = 'center'>" +
			Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].content + "</td>"
			"<td align = 'center'>" + QString::number(
			Global::g_projectInfo.camearItems[Global::g_projectInfo.camSequence[i]].ret) + "</td>"
			"<td align = 'center'>��¼2</td>"
			"<td align = 'center'>��¼3</td>"
			"<td align = 'center'>��¼4</td>"
			"<td align = 'center'>��¼5</td>"
			"<td align = 'center'>��¼6</td>"
			"<td align = 'center'>���</td>"
			"<td align = 'center'>����</td>"
			"</tr>");
	}
	for (int i = 0; i < Global::g_projectInfo.laserItems.count(); ++i) {
		m_data.append(
			"<tr>"
			"<td colspan = '2' align = 'center'>" + Global::g_projectInfo.laserItems[i].content + "</td>"
			"<td align = 'center'>" + QString::number(
				Global::g_projectInfo.laserItems[i].ret) + "</td>"
			"<td align = 'center'>��¼2</td>"
			"<td align = 'center'>��¼3</td>"
			"<td align = 'center'>��¼4</td>"
			"<td align = 'center'>��¼5</td>"
			"<td align = 'center'>��¼6</td>"
			"<td align = 'center'>���</td>"
			"<td align = 'center'>����</td>"
			"</tr>"
		);
	}
	m_data.append("</table></body>");

	m_isNew = true;
}

void ReportGenerator::showEvent(QShowEvent *e)
{
	ui.reportArea->clear();
	ui.reportArea->append(m_data);

	QDialog::showEvent(e);
}

void ReportGenerator::closeEvent(QCloseEvent *e)
{
	if (m_isNew) {
		if (QMessageBox::warning(this, "���汨��", "���������δ���棬ȷ�϶�����",
			QMessageBox::Cancel | QMessageBox::Ok, QMessageBox::Cancel)== QMessageBox::Cancel){
			return;
		}
	}
	QDialog::closeEvent(e);
}

void ReportGenerator::on_saveBtn_clicked()
{
	QString fileName = REPORT_DIRECTORY + Global::g_projectInfo.productionDate + "_" + Global::g_projectInfo.projectName + ".html";
	QFile reportFile(fileName);
	reportFile.open(QIODevice::WriteOnly);

	QTextStream ofs(&reportFile);
	ofs << m_data;
	ofs << "\n";

	DatabaseBrowser::WriteIn(ui.syncSQL->isChecked());

	m_isNew = false;
	close();
}