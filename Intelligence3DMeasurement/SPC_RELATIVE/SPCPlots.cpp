#include <QSqlQuery>
#include <QSqlRecord>
#include <QSettings>
#include <QDebug>
#include "SPCPlots.h"

#include "Global.h"

SPCPlots::SPCPlots(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	if (!Global::g_spc.bF3) { ui.tabWidget->removeTab(3); }
	else {
		DrawXRsPlot();
	}

	if (!Global::g_spc.bF2) { ui.tabWidget->removeTab(2); }
	else {
		DrawXmedRPlot();
	}

	if (!Global::g_spc.bF1) { ui.tabWidget->removeTab(1); }
	else {
		DrawXbarSPlot();
	}

	if (!Global::g_spc.bF0) { ui.tabWidget->removeTab(0); }
	else {
		DrawXbarRPlot();
	}
}

double SPCPlots::GetMeanValue(QVector<double> data)
{
	double sum = 0;
	Q_FOREACH(double t, data) { sum += t; }
	return sum / data.count();
}

void SPCPlots::DrawXbarRPlot()
{
	QVector<double> xMeanValue, rValue;
	int sub, n;
	double totalMeanX, totalMeanR;
	QSqlQuery q;
	
	QString cmd = "SELECT subgroup FROM " + Global::g_spc.table + " WHERE m_item='" +
		Global::g_spc.item + "'";
	q.exec(cmd);
	n = q.size();
	q.next();
	sub = q.value(0).toInt();
	
	cmd = "SELECT ";
	for (int i = 1; i < sub; ++i) { cmd += "ipcq" + QString::number(i) + ","; }
	cmd += "ipcq" + QString::number(sub) + " FROM " + Global::g_spc.table + " WHERE m_item='" +
		Global::g_spc.item + "' AND m_date BETWEEN '" +
		Global::g_spc.lTime.toString("yyyy-MM-dd HH:mm:ss") + "' AND '" +
		Global::g_spc.rTime.toString("yyyy-MM-dd HH:mm:ss") + "'";
	q.exec(cmd);
	while (q.next()) {
		QVector<double> x;
		for (int i = 0; i < sub; ++i) { x << q.value(i).toDouble(); }
		qSort(x.begin(), x.end());
		xMeanValue << GetMeanValue(x);
		rValue << x.last() - x.first();
	}
	totalMeanX = GetMeanValue(xMeanValue);
	totalMeanR = GetMeanValue(rValue);

	QSettings factor("./SPC.ini", QSettings::IniFormat);
	double A_2_R = factor.value("/A_2/" + QString::number(sub)).toDouble() * totalMeanR;
	double xUC = totalMeanX + A_2_R;
	double xLC = totalMeanX - A_2_R;
	double rUC = factor.value("/D_4/" + QString::number(sub)).toDouble() * totalMeanR;
	double rLC = factor.value("/D_3/" + QString::number(sub)).toDouble() * totalMeanR;

	QVector<double> id, xCL, xUCL, xLCL, rCL, rUCL, rLCL;
	for (int i = 0; i < n; ++i) {
		id << (double)i;
		xCL << totalMeanX;
		xUCL << xUC;
		xLCL << xLC;
		rCL << totalMeanR;
		rUCL << rUC;
		rLCL << rLC;
	}

	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(0)->setPen(QPen(QColor(0,0,225), 1.3));
	ui.plotW0_x->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
	ui.plotW0_x->graph(0)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->xAxis->setRange(0, n-1);
	ui.plotW0_x->xAxis->setAutoTickStep(false);
	ui.plotW0_x->xAxis->setTickStep(1);
	ui.plotW0_x->yAxis->setLabel("Xbar");
	ui.plotW0_x->yAxis->setRange(totalMeanX - A_2_R * 2.25, totalMeanX + A_2_R * 2.25);
	ui.plotW0_x->graph(0)->setData(id, xMeanValue);
	QVector<double> xNG_Id, xNG_Value;
	ui.plotW0_x->addGraph();
	for (int i = 0; i<n; ++i) {
		if (xMeanValue[i] > xUC || xMeanValue[i] < xLC) {
			xNG_Id << i;
			xNG_Value << xMeanValue[i];
		}
	}
	ui.plotW0_x->graph(1)->setPen(QPen(QColor(255, 0, 0)));
	ui.plotW0_x->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.plotW0_x->graph(1)->setData(xNG_Id, xNG_Value);
	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(2)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW0_x->graph(2)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->graph(2)->setData(id, xUCL);
	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(3)->setPen(QPen(QColor(0, 255, 0), 1.3, Qt::DashLine));
	ui.plotW0_x->graph(3)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->graph(3)->setData(id, xCL);
	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(4)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW0_x->graph(4)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->graph(4)->setData(id, xLCL);

	ui.plotW0_r->addGraph();
	ui.plotW0_r->graph(0)->setPen(QPen(QColor(0, 0, 225), 1.3));
	ui.plotW0_r->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
	ui.plotW0_r->graph(0)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_r->xAxis->setRange(0, n - 1);
	ui.plotW0_r->xAxis->setAutoTickStep(false);
	ui.plotW0_r->xAxis->setTickStep(1);
	ui.plotW0_r->yAxis->setLabel("R");
	ui.plotW0_r->yAxis->setRange(rLC - (totalMeanR-rLC) * 1.5, rUC + (rUC-totalMeanR) * 1.5);
	ui.plotW0_r->graph(0)->setData(id, rValue);
	QVector<double> rNG_Id, rNG_Value;
	ui.plotW0_r->addGraph();
	for (int i = 0; i<n; ++i) {
		if (rValue[i] > rUC || rValue[i] < rLC) {
			rNG_Id << i;
			rNG_Value << rValue[i];
		}
	}
	ui.plotW0_r->graph(1)->setPen(QPen(QColor(255, 0, 0)));
	ui.plotW0_r->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.plotW0_r->graph(1)->setData(rNG_Id, rNG_Value);
	ui.plotW0_r->addGraph();
	ui.plotW0_r->graph(2)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW0_r->graph(2)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_r->graph(2)->setData(id, rUCL);
	ui.plotW0_r->addGraph();
	ui.plotW0_r->graph(3)->setPen(QPen(QColor(0, 255, 0), 1.3, Qt::DashLine));
	ui.plotW0_r->graph(3)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_r->graph(3)->setData(id, rCL);
	ui.plotW0_r->addGraph();
	ui.plotW0_r->graph(4)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW0_r->graph(4)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_r->graph(4)->setData(id, rLCL);

	this->setWindowTitle(Global::g_spc.lTime.toString("yyyy-MM-dd HH:mm:ss") +
		"~" + Global::g_spc.rTime.toString("yyyy-MM-dd HH:mm:ss"));
}

void SPCPlots::DrawXbarSPlot()
{
	QVector<double> xMeanValue, sValue;
	int sub, n;
	double totalMeanX, totalMeanS;
	QSqlQuery q;

	QString cmd = "SELECT subgroup FROM " + Global::g_spc.table + " WHERE m_item='" +
		Global::g_spc.item + "'";
	q.exec(cmd);
	n = q.size();
	q.next();
	sub = q.value(0).toInt();

	cmd = "SELECT ";
	for (int i = 1; i < sub; ++i) { cmd += "ipcq" + QString::number(i) + ","; }
	cmd += "ipcq" + QString::number(sub) + " FROM " + Global::g_spc.table + " WHERE m_item='" +
		Global::g_spc.item + "' AND m_date BETWEEN '" +
		Global::g_spc.lTime.toString("yyyy-MM-dd HH:mm:ss") + "' AND '" +
		Global::g_spc.rTime.toString("yyyy-MM-dd HH:mm:ss") + "'";
	q.exec(cmd);
	while (q.next()) {
		QVector<double> x;
		for (int i = 0; i < sub; ++i) { x << q.value(i).toDouble(); }
		double mean = GetMeanValue(x);
		xMeanValue << mean;
		double sum_ = 0;
		for (int i = 0; i < sub; ++i) { sum_ += qPow((x[i] - mean), 2); }
		sValue << qSqrt(sum_ / (sub - 1));
	}
	totalMeanX = GetMeanValue(xMeanValue);
	totalMeanS = GetMeanValue(sValue);

	QSettings factor("./SPC.ini", QSettings::IniFormat);
	double A_3_S = factor.value("/A_3/" + QString::number(sub)).toDouble() * totalMeanS;
	double xUC = totalMeanX + A_3_S;
	double xLC = totalMeanX - A_3_S;
	double sUC = factor.value("/B_4/" + QString::number(sub)).toDouble() * totalMeanS;
	double sLC = factor.value("/B_3/" + QString::number(sub)).toDouble() * totalMeanS;

	QVector<double> id, xCL, xUCL, xLCL, sCL, sUCL, sLCL;
	for (int i = 0; i < n; ++i) {
		id << (double)i;
		xCL << totalMeanX;
		xUCL << xUC;
		xLCL << xLC;
		sCL << totalMeanS;
		sUCL << sUC;
		sLCL << sLC;
	}

	ui.plotW1_x->addGraph();
	ui.plotW1_x->graph(0)->setPen(QPen(QColor(0, 0, 225), 1.3));
	ui.plotW1_x->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
	ui.plotW1_x->graph(0)->setLineStyle(QCPGraph::lsLine);
	ui.plotW1_x->xAxis->setRange(0, n - 1);
	ui.plotW1_x->xAxis->setAutoTickStep(false);
	ui.plotW1_x->xAxis->setTickStep(1);
	ui.plotW1_x->yAxis->setLabel("Xbar");
	ui.plotW1_x->yAxis->setRange(totalMeanX - A_3_S * 2.25, totalMeanX + A_3_S * 2.25);
	ui.plotW1_x->graph(0)->setData(id, xMeanValue);
	QVector<double> xNG_Id, xNG_Value;
	ui.plotW1_x->addGraph();
	for (int i = 0; i<n; ++i) {
		if (xMeanValue[i] > xUC || xMeanValue[i] < xLC) {
			xNG_Id << i;
			xNG_Value << xMeanValue[i];
		}
	}
	ui.plotW1_x->graph(1)->setPen(QPen(QColor(255, 0, 0)));
	ui.plotW1_x->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.plotW1_x->graph(1)->setData(xNG_Id, xNG_Value);
	ui.plotW1_x->addGraph();
	ui.plotW1_x->graph(2)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW1_x->graph(2)->setLineStyle(QCPGraph::lsLine);
	ui.plotW1_x->graph(2)->setData(id, xUCL);
	ui.plotW1_x->addGraph();
	ui.plotW1_x->graph(3)->setPen(QPen(QColor(0, 255, 0), 1.3, Qt::DashLine));
	ui.plotW1_x->graph(3)->setLineStyle(QCPGraph::lsLine);
	ui.plotW1_x->graph(3)->setData(id, xCL);
	ui.plotW1_x->addGraph();
	ui.plotW1_x->graph(4)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW1_x->graph(4)->setLineStyle(QCPGraph::lsLine);
	ui.plotW1_x->graph(4)->setData(id, xLCL);

	ui.plotW1_s->addGraph();
	ui.plotW1_s->graph(0)->setPen(QPen(QColor(0, 0, 225), 1.3));
	ui.plotW1_s->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
	ui.plotW1_s->graph(0)->setLineStyle(QCPGraph::lsLine);
	ui.plotW1_s->xAxis->setRange(0, n - 1);
	ui.plotW1_s->xAxis->setAutoTickStep(false);
	ui.plotW1_s->xAxis->setTickStep(1);
	ui.plotW1_s->yAxis->setLabel("S");
	ui.plotW1_s->yAxis->setRange(sLC - (totalMeanS - sLC) * 1.5, sUC + (sUC - totalMeanS) * 1.5);
	ui.plotW1_s->graph(0)->setData(id, sValue);
	QVector<double> sNG_Id, sNG_Value;
	ui.plotW1_s->addGraph();
	for (int i = 0; i<n; ++i) {
		if (sValue[i] > sUC || sValue[i] < sLC) {
			sNG_Id << i;
			sNG_Value << sValue[i];
		}
	}
	ui.plotW1_s->graph(1)->setPen(QPen(QColor(255, 0, 0)));
	ui.plotW1_s->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.plotW1_s->graph(1)->setData(sNG_Id, sNG_Value);
	ui.plotW1_s->addGraph();
	ui.plotW1_s->graph(2)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW1_s->graph(2)->setLineStyle(QCPGraph::lsLine);
	ui.plotW1_s->graph(2)->setData(id, sUCL);
	ui.plotW1_s->addGraph();
	ui.plotW1_s->graph(3)->setPen(QPen(QColor(0, 255, 0), 1.3, Qt::DashLine));
	ui.plotW1_s->graph(3)->setLineStyle(QCPGraph::lsLine);
	ui.plotW1_s->graph(3)->setData(id, sCL);
	ui.plotW1_s->addGraph();
	ui.plotW1_s->graph(4)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW1_s->graph(4)->setLineStyle(QCPGraph::lsLine);
	ui.plotW1_s->graph(4)->setData(id, sLCL);

	this->setWindowTitle(Global::g_spc.lTime.toString("yyyy-MM-dd HH:mm:ss") +
		"~" + Global::g_spc.rTime.toString("yyyy-MM-dd HH:mm:ss"));
}

void SPCPlots::DrawXmedRPlot()
{
	
}

void SPCPlots::DrawXRsPlot()
{
	
}
