#pragma once

#include <QDialog>
#include "ui_SPCPlots.h"

#include "qcustomplot.h"

class SPCPlots : public QDialog
{
	Q_OBJECT

public:
	SPCPlots(QWidget *parent = Q_NULLPTR);

private:
	Ui::SPCPlots ui;

	double GetMeanValue(QVector<double> data);
	void DrawXbarRPlot();
	void DrawXbarSPlot();
	void DrawXmedRPlot();
	void DrawXRsPlot();
};
