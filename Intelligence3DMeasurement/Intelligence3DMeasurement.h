#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Intelligence3DMeasurement.h"

class Intelligence3DMeasurement : public QMainWindow
{
	Q_OBJECT

public:
	Intelligence3DMeasurement(QWidget *parent = Q_NULLPTR);

private:
	Ui::Intelligence3DMeasurementClass ui;
};
