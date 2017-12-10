#include <QSettings>
#include <QFileDialog>
#include "ProcessTypeCfgDlg.h"

#include "Global.h"


ProcessTypeCfgDlg::ProcessTypeCfgDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	// *³õÊ¼»¯ÅäÖÃ±í -BEGIN
	QFileInfo cfgFile("./config.ini");
	if (cfgFile.isFile()) {
		QSettings cfgFile("./config.ini", QSettings::IniFormat);
		Global::g_sampleVolume = cfgFile.value("/PROCESS/SampleVolume").toInt();
		Global::g_enable2DMode = cfgFile.value("/PROCESS/MeasureMode_X_Y").toBool();
		Global::g_enableQuietMode = cfgFile.value("/PROCESS/QuietMode").toBool();
		Global::g_camViewField = cfgFile.value("/PROCESS/CoverArea").toDouble();
	}
	else {
		Global::g_sampleVolume = 1;
		Global::g_enable2DMode = false;
		Global::g_enableQuietMode = false;
		Global::g_camViewField = 15.0;
	}
	// -END

	ui.subGroupVolSlider->setValue(Global::g_sampleVolume);
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

void ProcessTypeCfgDlg::closeEvent(QCloseEvent *e)
{
	QSettings cfgFile("./config.ini", QSettings::IniFormat);
	cfgFile.setValue("/PROCESS/SampleVolume", Global::g_sampleVolume);
	cfgFile.setValue("/PROCESS/MeasureMode_X_Y", Global::g_enable2DMode);
	cfgFile.setValue("/PROCESS/QuietMode", Global::g_enableQuietMode);
	cfgFile.setValue("/PROCESS/CoverArea", Global::g_camViewField);
}

void ProcessTypeCfgDlg::SyncMem()
{
	Global::g_sampleVolume = ui.subGroupVolSlider->value();
	Global::g_enable2DMode = ui.xyMeasureBtn->isChecked();
	Global::g_enableQuietMode = ui.autoSaveBtn->isChecked();
	Global::g_camViewField = ui.viewField->value();
}

