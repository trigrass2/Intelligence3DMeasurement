#include <QDebug>
#include "DataRangeSelector.h"

#include "Global.h"


DataRangeSelector::DataRangeSelector(QStringList list, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.itemSelector->addItems(list);

	connect(ui.itemSelector, SIGNAL(currentTextChanged(QString)), this, SLOT(SetConfig()));
	connect(ui.dateLower, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(SetConfig()));
	connect(ui.dateUpper, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(SetConfig()));
	connect(ui.xbarRChkBox, SIGNAL(clicked(bool)), this, SLOT(SetConfig()));
	connect(ui.xbarSChkBox, SIGNAL(clicked(bool)), this, SLOT(SetConfig()));
	connect(ui.xmedRChkBox, SIGNAL(clicked(bool)), this, SLOT(SetConfig()));
	connect(ui.xRsChkBox, SIGNAL(clicked(bool)), this, SLOT(SetConfig()));
}

void DataRangeSelector::on_acceptBtn_clicked()
{
	accept();
}

void DataRangeSelector::on_rejectBtn_clicked()
{
	reject();
}

void DataRangeSelector::SetConfig()
{
	Global::g_spc.item = ui.itemSelector->currentText();
	Global::g_spc.lTime = ui.dateLower->dateTime();
	Global::g_spc.rTime = ui.dateUpper->dateTime();
	Global::g_spc.bF0 = ui.xbarRChkBox->isChecked();
	Global::g_spc.bF1 = ui.xbarSChkBox->isChecked();
	Global::g_spc.bF2 = ui.xmedRChkBox->isChecked();
	Global::g_spc.bF3 = ui.xRsChkBox->isChecked();
}