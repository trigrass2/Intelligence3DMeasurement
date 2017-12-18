#include <QSqlQuery>
#include <QSettings>
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
	Q_FOREACH(int t, data) { sum += t; }
	return sum / data.count();
}

void SPCPlots::DrawXbarRPlot()
{
	QString cmd = "SELECT Ret FROM " + Global::g_spc.table + " WHERE Content='" +
		Global::g_spc.item + "'";
	QSqlQuery q;
	q.exec(cmd);
	int n = q.size();	

	QVector<double> xMeanValue, rMeanValue;
	// 计算组内均值+组内间距
	/**/
	double dxTotalMean = GetMeanValue(xMeanValue);
	double drTotalMean = GetMeanValue(rMeanValue);
 
	QSettings factor("../SPC.ini", QSettings::IniFormat);
	double dxBias = factor.value("A_2").toDouble() * drTotalMean;
	double dxUCL = dxTotalMean + dxBias;
	double dxLCL = dxTotalMean - dxBias;
	double drUCL = factor.value("D_4").toDouble() * drTotalMean;
	double drLCL = factor.value("D_3").toDouble() * drTotalMean;

	QVector<double> xUCL;
	for (int i = 0; i < n; ++i) { xUCL << dxUCL; }
	QVector<double> xLCL;
	for (int i = 0; i < n; ++i) { xLCL << dxUCL; }
	QVector<qreal> xCL;
	for (int i = 0; i < n; ++i) { xCL << dxTotalMean; }
	QVector<qreal> nId;
	for (int i = 0; i < n; ++i) { nId << i; }

	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(0)->setPen(QPen(QColor(0,0,225), 1.3));
	ui.plotW0_x->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
	ui.plotW0_x->graph(0)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->xAxis->setRange(0, n);
	ui.plotW0_x->xAxis->setAutoTickStep(false);
	ui.plotW0_x->xAxis->setTickStep(1);
	ui.plotW0_x->yAxis->setLabel(tr("Xbar"));
	ui.plotW0_x->yAxis->setRange(dxTotalMean - 2 * dxBias, dxTotalMean + 2 * dxBias);
	ui.plotW0_x->graph(0)->setData(nId, xMeanValue);		// 所有数据点
	// 覆盖不合格数据点
	QVector<double> xUq_Id, xUq_Value;
	ui.plotW0_x->addGraph();
	for (int i = 0; i<n; ++i) {
		if (xMeanValue[i] > dxUCL || xMeanValue[i] < dxLCL) {
			xUq_Id << i;
			xUq_Value << xMeanValue[i];
		}
	}
	ui.plotW0_x->graph(1)->setPen(QPen(QColor(255, 0, 0)));
	ui.plotW0_x->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.plotW0_x->graph(1)->setData(xUq_Id, xUq_Value);
	// 控制上限
	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(2)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW0_x->graph(2)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->graph(2)->setData(nId, xUCL);
	//控制中限
	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(3)->setPen(QPen(QColor(0, 255, 0), 1.3, Qt::DashLine));
	ui.plotW0_x->graph(3)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->graph(3)->setData(nId, xCL);
	//控制下限
	ui.plotW0_x->addGraph();
	ui.plotW0_x->graph(4)->setPen(QPen(QColor(255, 0, 0), 1.3, Qt::DotLine));
	ui.plotW0_x->graph(4)->setLineStyle(QCPGraph::lsLine);
	ui.plotW0_x->graph(4)->setData(nId, xLCL);
	ui.plotW0_x->replot();
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
