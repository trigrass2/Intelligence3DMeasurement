#include <QSqlQuery>
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
	QSqlQuery q;
	// data
	QString cmd = "SELECT DataMean FROM " + Global::g_spc.table + " WHERE Content='" +
		Global::g_spc.item + "' AND MDate BETWEEN '" +
		Global::g_spc.lTime.toString("yyyy-MM-dd HH:mm:ss") + "' AND '" +
		Global::g_spc.rTime.toString("yyyy-MM-dd HH:mm:ss") + "'";
	q.exec(cmd);
	int n = q.size();

	QVector<double> x;
	while (q.next()) { x << q.value(0).toDouble(); }

	cmd = "SELECT DataRange FROM " + Global::g_spc.table + " WHERE Content='" +
		Global::g_spc.item + "' AND MDate BETWEEN '" +
		Global::g_spc.lTime.toString("yyyy-MM-dd HH:mm:ss") + "' AND '" +
		Global::g_spc.rTime.toString("yyyy-MM-dd HH:mm:ss") + "'";
	q.exec(cmd);

	QVector<double> r;
	while (q.next()) { r << q.value(0).toDouble(); }

	// CL
	cmd = "SELECT DataMean FROM " + Global::g_spc.table + " WHERE Content='" +
		Global::g_spc.item + "'";
	q.exec(cmd);

	QVector<double> xValue;
	while (q.next()) { xValue << q.value(0).toDouble(); }
	double xMean = GetMeanValue(xValue);

	cmd = "SELECT DataRange FROM " + Global::g_spc.table + " WHERE Content='" +
		Global::g_spc.item + "'";
	q.exec(cmd);

	QVector<double> rValue;
	while (q.next()) { rValue << q.value(0).toDouble(); }
	double rMean = GetMeanValue(rValue);

	QSettings factor("./SPC.ini", QSettings::IniFormat);
	//subGroup从数据库读出
	double bias = factor.value("/A_2/" /*+ QString::number(Global::g_sampleVolume)*/).toDouble() *
		rMean;
	double xUC = xMean + bias;
	double xLC = xMean - bias;
	double rUC = factor.value("/D_4/" /*+ QString::number(Global::g_sampleVolume)*/).toDouble() *
		rMean;
	double rLC = factor.value("/D_3/" /*+ QString::number(Global::g_sampleVolume)*/).toDouble() *
		rMean;

	QVector<double> id, xCL, xUCL, xLCL, rCL, rUCL, rLCL;
	for (int i = 0; i < n; ++i) {
		id << (double)i;
		xCL << xMean;
		xUCL << xUC;
		xLCL << xLC;
		rCL << rMean;
		rUCL << rUC;
		rLCL << rLC;
	}

	// Plot x-data
	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(0)->setPen(QPen(QColor(0,0,225), 1.3));
	ui.plotW0_x->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
	ui.plotW0_x->graph(0)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->xAxis->setRange(0, n-1);
	ui.plotW0_x->xAxis->setAutoTickStep(false);
	ui.plotW0_x->xAxis->setTickStep(1);
	ui.plotW0_x->yAxis->setLabel("Xbar");
	ui.plotW0_x->yAxis->setRange(xMean - 2 * bias, xMean + 2 * bias);
	ui.plotW0_x->graph(0)->setData(id, x);
	// 覆盖不合格数据点
	QVector<double> xUq_Id, xUq_Value;
	ui.plotW0_x->addGraph();
	for (int i = 0; i<n; ++i) {
		if (x[i] > xUC || x[i] < xLC) {
			xUq_Id << i;
			xUq_Value << xValue[i];
		}
	}
	ui.plotW0_x->graph(1)->setPen(QPen(QColor(255, 0, 0)));
	ui.plotW0_x->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.plotW0_x->graph(1)->setData(xUq_Id, xUq_Value);
	
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
	//ui.plotW0_x->replot();
	// Plot r-data
	ui.plotW0_r->addGraph();
	ui.plotW0_r->graph(0)->setPen(QPen(QColor(0, 0, 225), 1.3));
	ui.plotW0_r->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
	ui.plotW0_r->graph(0)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_r->xAxis->setRange(0, n - 1);
	ui.plotW0_r->xAxis->setAutoTickStep(false);
	ui.plotW0_r->xAxis->setTickStep(1);
	ui.plotW0_r->yAxis->setLabel("R");
	ui.plotW0_r->yAxis->setRange(rMean - 3.5 * bias, rMean + 3.5 * bias);
	ui.plotW0_r->graph(0)->setData(id, r);
	// 覆盖不合格数据点
	QVector<double> rUq_Id, rUq_Value;
	ui.plotW0_r->addGraph();
	for (int i = 0; i<n; ++i) {
		if (r[i] > rUC || r[i] < rLC) {
			rUq_Id << i;
			rUq_Value << rValue[i];
		}
	}
	ui.plotW0_r->graph(1)->setPen(QPen(QColor(255, 0, 0)));
	ui.plotW0_r->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.plotW0_r->graph(1)->setData(rUq_Id, rUq_Value);

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
	
}

void SPCPlots::DrawXmedRPlot()
{
	
}

void SPCPlots::DrawXRsPlot()
{
	
}
