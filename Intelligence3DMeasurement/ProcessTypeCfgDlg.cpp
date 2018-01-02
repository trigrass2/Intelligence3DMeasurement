#include <QSettings>
#include <QFileDialog>
#include <QDebug>
#include "ProcessTypeCfgDlg.h"

#include "Global.h"


ProcessTypeCfgDlg::ProcessTypeCfgDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	// *��ʼ�����ñ� -BEGIN
	QFileInfo cfgFile("./config.ini");
	if (cfgFile.isFile()) {
		QSettings cfgFile("./config.ini", QSettings::IniFormat);
		Global::g_enable2DMode = cfgFile.value("PROCESS/MeasureMode_X_Y").toBool();
		Global::g_enableQuietMode = cfgFile.value("PROCESS/QuietMode").toBool();
		Global::g_camViewField = cfgFile.value("PROCESS/CoverArea").toDouble();
	}
	else {
		Global::g_enable2DMode = false;
		Global::g_enableQuietMode = false;
		Global::g_camViewField = 15.0;
	}
	// -END

	if (!Global::g_isLaserConnected) {
		ui.xyMeasureBtn->setChecked(true);
		ui.xyzMeasureBtn->setDisabled(true);
	}
	else { ui.xyMeasureBtn->setChecked(Global::g_enable2DMode); }
	ui.autoSaveBtn->setChecked(Global::g_enableQuietMode);
	ui.viewField->setValue(Global::g_camViewField);
	
	connect(ui.subGroupVolSlider, SIGNAL(valueChanged(int)), this, SLOT(SyncMem()));
	connect(ui.xyMeasureBtn, SIGNAL(toggled(bool)), this, SLOT(SyncMem()));
	connect(ui.xyzMeasureBtn, SIGNAL(toggled(bool)), this, SLOT(SyncMem()));
	connect(ui.autoSaveBtn, SIGNAL(toggled(bool)), this, SLOT(SyncMem()));
	connect(ui.manualSaveBtn, SIGNAL(toggled(bool)), this, SLOT(SyncMem()));
	connect(ui.viewField, SIGNAL(valueChanged(double)), this, SLOT(SyncMem()));
}

void ProcessTypeCfgDlg::showEvent(QShowEvent *e)
{
	if (Global::g_lockConfig) {
		ui.subGroupVolSlider->setDisabled(Global::g_lockConfig);
		ui.subGroupVolSlider->setValue(Global::g_projectInfo.nSubGroupSize);
	}
	else {
		ui.subGroupVolSlider->setDisabled(Global::g_lockConfig);
		ui.subGroupVolSlider->setValue(1);
	}
}

void ProcessTypeCfgDlg::closeEvent(QCloseEvent *e)
{
	QSettings cfgFile("./config.ini", QSettings::IniFormat);
	cfgFile.setValue("/PROCESS/MeasureMode_X_Y", Global::g_enable2DMode);
	cfgFile.setValue("/PROCESS/QuietMode", Global::g_enableQuietMode);
	cfgFile.setValue("/PROCESS/CoverArea", Global::g_camViewField);
}

void ProcessTypeCfgDlg::SyncMem()
{
	Global::g_projectInfo.nSubGroupSize = ui.subGroupVolSlider->value();
	Global::g_enable2DMode = ui.xyMeasureBtn->isChecked();
	Global::g_enableQuietMode = ui.autoSaveBtn->isChecked();
	Global::g_camViewField = ui.viewField->value();
}

