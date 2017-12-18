#pragma once

#include <QWidget>
#include <QDateTime>
#include "ui_DataRangeSelector.h"

class DataRangeSelector : public QDialog
{
	Q_OBJECT

public:
	DataRangeSelector(QStringList list, QWidget *parent = Q_NULLPTR);

private:
	Ui::DataRangeSelector ui;

private slots:
	void on_acceptBtn_clicked();
	void on_rejectBtn_clicked();

	void SetConfig();
};
