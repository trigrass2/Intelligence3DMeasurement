#include <QMessageBox>
#include <QSettings>
#include <QFileInfo>
#include <QDebug>
#include "MotionCtrlCfgDlg.h"

#include "Global.h"


MotionCtrlCfgDlg::MotionCtrlCfgDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	// *初始化配置表 -BEGIN
	m_motionCardCfg.nPelType[0] = 0;
	m_motionCardCfg.nPelType[1] = 0;
	m_motionCardCfg.nPelType[2] = 0;
	m_motionCardCfg.nPelNo[0] = 0;
	m_motionCardCfg.nPelNo[1] = 1;
	m_motionCardCfg.nPelNo[2] = 2;
	m_motionCardCfg.nPelFilter[0] = 0.0;
	m_motionCardCfg.nPelFilter[1] = 0.0;
	m_motionCardCfg.nPelFilter[2] = 0.0;
	m_motionCardCfg.nNelType[0] = 1;
	m_motionCardCfg.nNelType[1] = 1;
	m_motionCardCfg.nNelType[2] = 1;
	m_motionCardCfg.nNelNo[0] = 0;
	m_motionCardCfg.nNelNo[1] = 1;
	m_motionCardCfg.nNelNo[2] = 2;
	m_motionCardCfg.nNelFilter[0] = 0.0;
	m_motionCardCfg.nNelFilter[1] = 0.0;
	m_motionCardCfg.nNelFilter[2] = 0.0;
	m_motionCardCfg.nOrgType[0] = 2;
	m_motionCardCfg.nOrgType[1] = 2;
	m_motionCardCfg.nOrgType[2] = 2;
	m_motionCardCfg.nOrgNo[0] = 1;
	m_motionCardCfg.nOrgNo[1] = 0;
	m_motionCardCfg.nOrgNo[2] = 3;
	m_motionCardCfg.nOrgFilter[0] = 0.0;
	m_motionCardCfg.nOrgFilter[1] = 0.0;
	m_motionCardCfg.nOrgFilter[2] = 0.0;
	m_motionCardCfg.nEmgType[0] = 6;
	m_motionCardCfg.nEmgType[1] = 6;
	m_motionCardCfg.nEmgType[2] = 6;
	m_motionCardCfg.nEmgNo[0] = 0;
	m_motionCardCfg.nEmgNo[1] = 1;
	m_motionCardCfg.nEmgNo[2] = 2;
	m_motionCardCfg.nEmgFilter[0] = 0.0;
	m_motionCardCfg.nEmgFilter[1] = 0.0;
	m_motionCardCfg.nEmgFilter[2] = 0.0;
	m_motionCardCfg.nDstpType[0] = 6;
	m_motionCardCfg.nDstpType[1] = 6;
	m_motionCardCfg.nDstpType[2] = 6;
	m_motionCardCfg.nDstpNo[0] = 0;
	m_motionCardCfg.nDstpNo[1] = 1;
	m_motionCardCfg.nDstpNo[2] = 2;
	m_motionCardCfg.nDstpFilter[0] = 0.0;
	m_motionCardCfg.nDstpFilter[1] = 0.0;
	m_motionCardCfg.nDstpFilter[2] = 0.0;
	m_motionCardCfg.nAlmType[0] = 3;
	m_motionCardCfg.nAlmType[1] = 3;
	m_motionCardCfg.nAlmType[2] = 3;
	m_motionCardCfg.nAlmNo[0] = 0;
	m_motionCardCfg.nAlmNo[1] = 1;
	m_motionCardCfg.nAlmNo[2] = 2;
	m_motionCardCfg.nAlmFilter[0] = 0.0;
	m_motionCardCfg.nAlmFilter[1] = 0.0;
	m_motionCardCfg.nAlmFilter[2] = 0.0;
	m_motionCardCfg.nInpType[0] = 5;
	m_motionCardCfg.nInpType[1] = 5;
	m_motionCardCfg.nInpType[2] = 5;
	m_motionCardCfg.nInpNo[0] = 0;
	m_motionCardCfg.nInpNo[1] = 1;
	m_motionCardCfg.nInpNo[2] = 2;
	m_motionCardCfg.nInpFilter[0] = 0.0;
	m_motionCardCfg.nInpFilter[1] = 0.0;
	m_motionCardCfg.nInpFilter[2] = 0.0;

	m_motionCardCfg.nPulseModeIndex[0] = 5;
	m_motionCardCfg.nPulseModeIndex[1] = 5;
	m_motionCardCfg.nPulseModeIndex[2] = 5;

	m_motionCardCfg.nInputModeIndex[0] = 3;
	m_motionCardCfg.nInputModeIndex[1] = 3;
	m_motionCardCfg.nInputModeIndex[2] = 3;
	m_motionCardCfg.nEZLvLIndex[0] = 0;
	m_motionCardCfg.nEZLvLIndex[1] = 0;
	m_motionCardCfg.nEZLvLIndex[2] = 0;

	m_motionCardCfg.nHrSpeedIndex[0] = 1;
	m_motionCardCfg.nHrSpeedIndex[1] = 1;
	m_motionCardCfg.nHrSpeedIndex[2] = 1;
	m_motionCardCfg.nHrDirectionIndex[0] = 0;
	m_motionCardCfg.nHrDirectionIndex[1] = 0;
	m_motionCardCfg.nHrDirectionIndex[2] = 1;
	m_motionCardCfg.nHrLvLIndex[0] = 0;
	m_motionCardCfg.nHrLvLIndex[1] = 0;
	m_motionCardCfg.nHrLvLIndex[2] = 0;
	m_motionCardCfg.nHrModeIndex[0] = 0;
	m_motionCardCfg.nHrModeIndex[1] = 0;
	m_motionCardCfg.nHrModeIndex[2] = 0;

	m_motionCardCfg.nHdwLimitEnableIndex[0] = 1;
	m_motionCardCfg.nHdwLimitEnableIndex[1] = 1;
	m_motionCardCfg.nHdwLimitEnableIndex[2] = 1;
	m_motionCardCfg.nHdwLimitLvLIndex[0] = 0;
	m_motionCardCfg.nHdwLimitLvLIndex[1] = 0;
	m_motionCardCfg.nHdwLimitLvLIndex[2] = 0;
	m_motionCardCfg.nHdwLimitModeIndex[0] = 0;
	m_motionCardCfg.nHdwLimitModeIndex[1] = 0;
	m_motionCardCfg.nHdwLimitModeIndex[2] = 0;
	m_motionCardCfg.nSfwLimitEnableIndex[0] = 0;
	m_motionCardCfg.nSfwLimitEnableIndex[1] = 0;
	m_motionCardCfg.nSfwLimitEnableIndex[2] = 0;
	m_motionCardCfg.nSfwLimitModeIndex[0] = 0;
	m_motionCardCfg.nSfwLimitModeIndex[1] = 0;
	m_motionCardCfg.nSfwLimitModeIndex[2] = 0;
	m_motionCardCfg.nSfwLimitCounterIndex[0] = 0;
	m_motionCardCfg.nSfwLimitCounterIndex[1] = 0;
	m_motionCardCfg.nSfwLimitCounterIndex[2] = 0;
	m_motionCardCfg.nSfwLimitPPostion[0] = 0;
	m_motionCardCfg.nSfwLimitPPostion[1] = 0;
	m_motionCardCfg.nSfwLimitPPostion[2] = 0;
	m_motionCardCfg.nSfwLimitNPostion[0] = 0;
	m_motionCardCfg.nSfwLimitNPostion[1] = 0;
	m_motionCardCfg.nSfwLimitNPostion[2] = 0;
	m_motionCardCfg.nIODstpEnableIndex[0] = 0;
	m_motionCardCfg.nIODstpEnableIndex[1] = 0;
	m_motionCardCfg.nIODstpEnableIndex[2] = 0;
	m_motionCardCfg.nIODstpLvLIndex[0] = 0;
	m_motionCardCfg.nIODstpLvLIndex[1] = 0;
	m_motionCardCfg.nIODstpLvLIndex[2] = 0;
	m_motionCardCfg.nIODstpTime[0] = 0.01;
	m_motionCardCfg.nIODstpTime[1] = 0.01;
	m_motionCardCfg.nIODstpTime[2] = 0.01;
	m_motionCardCfg.nEmgEnableIndex[0] = 1;
	m_motionCardCfg.nEmgEnableIndex[1] = 1;
	m_motionCardCfg.nEmgEnableIndex[2] = 1;
	m_motionCardCfg.nEmgLvLIndex[0] = 0;
	m_motionCardCfg.nEmgLvLIndex[1] = 0;
	m_motionCardCfg.nEmgLvLIndex[2] = 0;
	m_motionCardCfg.nAlmEnableIndex[0] = 0;
	m_motionCardCfg.nAlmEnableIndex[1] = 0;
	m_motionCardCfg.nAlmEnableIndex[2] = 0;
	m_motionCardCfg.nAlmLvLIndex[0] = 0;
	m_motionCardCfg.nAlmLvLIndex[1] = 0;
	m_motionCardCfg.nAlmLvLIndex[2] = 0;
	m_motionCardCfg.nInpEnableIndex[0] = 0;
	m_motionCardCfg.nInpEnableIndex[1] = 0;
	m_motionCardCfg.nInpEnableIndex[2] = 0;
	m_motionCardCfg.nInpLvLIndex[0] = 0;
	m_motionCardCfg.nInpLvLIndex[1] = 0;
	m_motionCardCfg.nInpLvLIndex[2] = 0;
	
	QFileInfo cfgFile("./config.ini");
	if (cfgFile.isFile()) {
		QSettings cfgFile("./config.ini", QSettings::IniFormat);
		Global::g_pulseEquivalent = cfgFile.value("/MC/PulseEquivalent").toDouble();
		Global::g_xyLineVectorVel = cfgFile.value("/MC/RunVelocity_X_Y").toDouble();
		Global::g_zVel = cfgFile.value("/MC/RunVelocity_Z").toDouble();
	}
	else {
		Global::g_pulseEquivalent = 0.002;
		Global::g_xyLineVectorVel = 4000;
		Global::g_zVel = 4000;
	}
	// -END

	connect(ui.axisChsBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SyncUI(int)));
	SyncUI(0);

	ApplyConfig();
}

MotionCtrlCfgDlg::~MotionCtrlCfgDlg()
{
	if (ENABLE_MOTION_MODULE) { dmc_board_close(); }
}

void MotionCtrlCfgDlg::closeEvent(QCloseEvent *e)
{
	SyncMem();
	QSettings cfgFile("./config.ini", QSettings::IniFormat);
	cfgFile.setValue("/MC/PulseEquivalent", Global::g_pulseEquivalent);
	cfgFile.setValue("/MC/RunVelocity_X_Y", Global::g_xyLineVectorVel);
	cfgFile.setValue("/MC/RunVelocity_Z", Global::g_zVel);
}

WORD MotionCtrlCfgDlg::Write2Card(int axis)
{
	WORD ret = 0;
	if (ENABLE_MOTION_MODULE) {
		ret += dmc_set_axis_io_map(0, axis, 0, m_motionCardCfg.nPelType[axis],
			m_motionCardCfg.nPelNo[axis], m_motionCardCfg.nPelFilter[axis]);
		ret += dmc_set_axis_io_map(0, axis, 1, m_motionCardCfg.nNelType[axis],
			m_motionCardCfg.nNelNo[axis], m_motionCardCfg.nNelFilter[axis]);
		ret += dmc_set_axis_io_map(0, axis, 2, m_motionCardCfg.nOrgType[axis],
			m_motionCardCfg.nOrgNo[axis], m_motionCardCfg.nOrgFilter[axis]);
		ret += dmc_set_axis_io_map(0, axis, 3, m_motionCardCfg.nEmgType[axis],
			m_motionCardCfg.nEmgNo[axis], m_motionCardCfg.nEmgFilter[axis]);
		ret += dmc_set_axis_io_map(0, axis, 4, m_motionCardCfg.nDstpType[axis],
			m_motionCardCfg.nDstpNo[axis], m_motionCardCfg.nDstpFilter[axis]);
		ret += dmc_set_axis_io_map(0, axis, 5, m_motionCardCfg.nAlmType[axis],
			m_motionCardCfg.nAlmNo[axis], m_motionCardCfg.nAlmFilter[axis]);
		ret += dmc_set_axis_io_map(0, axis, 7, m_motionCardCfg.nInpType[axis],
			m_motionCardCfg.nInpNo[axis], m_motionCardCfg.nInpFilter[axis]);

		ret += dmc_set_pulse_outmode(0, axis, m_motionCardCfg.nPulseModeIndex[axis]);

		ret += dmc_set_counter_inmode(0, axis, m_motionCardCfg.nInputModeIndex[axis]);
		ret += dmc_set_ez_mode(0, axis, m_motionCardCfg.nEZLvLIndex[axis]);

		ret += dmc_set_home_pin_logic(0, axis, m_motionCardCfg.nHrLvLIndex[axis]);
		ret += dmc_set_homemode(0, axis, m_motionCardCfg.nHrDirectionIndex[axis],
			m_motionCardCfg.nHrSpeedIndex[axis],
			m_motionCardCfg.nHrModeIndex[axis]);

		ret += dmc_set_el_mode(0, axis, m_motionCardCfg.nHdwLimitEnableIndex[axis],
			m_motionCardCfg.nHdwLimitLvLIndex[axis],
			m_motionCardCfg.nHdwLimitModeIndex[axis]);
		ret += dmc_set_softlimit(0, axis, m_motionCardCfg.nSfwLimitEnableIndex[axis],
			m_motionCardCfg.nSfwLimitCounterIndex[axis],
			m_motionCardCfg.nSfwLimitModeIndex[axis], m_motionCardCfg.nSfwLimitPPostion[axis],
			m_motionCardCfg.nSfwLimitNPostion[axis]);
		ret += dmc_set_io_dstp_mode(0, axis, m_motionCardCfg.nIODstpEnableIndex[axis],
			m_motionCardCfg.nIODstpLvLIndex[axis]);
		ret += dmc_set_dec_stop_time(0, axis, m_motionCardCfg.nIODstpTime[axis]);
		ret += dmc_set_emg_mode(0, axis, m_motionCardCfg.nEmgEnableIndex[axis],
			m_motionCardCfg.nEmgLvLIndex[axis]);
		ret += dmc_set_alm_mode(0, axis, m_motionCardCfg.nAlmEnableIndex[axis],
			m_motionCardCfg.nAlmLvLIndex[axis], 0);
		ret += dmc_set_inp_mode(0, axis, m_motionCardCfg.nInpEnableIndex[axis],
			m_motionCardCfg.nInpLvLIndex[axis]);
	}
	return ret;
}

void MotionCtrlCfgDlg::ApplyConfig()
{
	if (ENABLE_MOTION_MODULE) {
		if (dmc_board_init()) {
			dmc_write_sevon_pin(0, 0, 0);
			dmc_write_sevon_pin(0, 1, 0);
			dmc_write_sevon_pin(0, 2, 1);
			on_wrtAllBtn_clicked();
		}
		else { qDebug() << "Motion control card initialization failed!"; }
	}
}

void MotionCtrlCfgDlg::on_wrtAllBtn_clicked()
{
	QString info;
	if (Write2Card(0)) { info.append("0"); }
	if (Write2Card(1)) { info.append("1"); }
	if (Write2Card(2)) { info.append("2"); }
	if (info.isEmpty()) { setWindowTitle("运动控制卡配置（写入成功！）"); }
	else { setWindowTitle("运动控制卡配置（" + info + "写入失败！）"); }
}

void MotionCtrlCfgDlg::on_resetBtn_clicked()
{
	switch (QMessageBox::warning(this, "MC Reset", "<font size='5' color='black'>Restart to reset motion control card?</font>",
		QMessageBox::Cancel | QMessageBox::Ok, QMessageBox::Cancel)) {
	case QMessageBox::Cancel:
		return;
		break;
	case QMessageBox::Ok:
		if (ENABLE_MOTION_MODULE) { dmc_board_reset(); }
		exit(0);
		break;
	};
}

void MotionCtrlCfgDlg::SyncMem()
{
	Global::g_xyLineVectorVel = ui.xyLineVectorVel->value();
	Global::g_zVel = ui.zVel->value();
}

void MotionCtrlCfgDlg::SyncUI(int axis)
{
	disconnect(ui.xyLineVectorVel, SIGNAL(valueChanged(double)), this, SLOT(SyncMem()));
	disconnect(ui.zVel, SIGNAL(valueChanged(double)), this, SLOT(SyncMem()));

	ui.pelTypeBox->setCurrentIndex(m_motionCardCfg.nPelType[axis]);
	ui.pelNoBox->setCurrentIndex(m_motionCardCfg.nPelNo[axis]);
	ui.pelFilterSpin->setValue(m_motionCardCfg.nPelFilter[axis]);
	ui.nelTypeBox->setCurrentIndex(m_motionCardCfg.nNelType[axis]);
	ui.nelNoBox->setCurrentIndex(m_motionCardCfg.nNelNo[axis]);
	ui.nelFilterSpin->setValue(m_motionCardCfg.nNelFilter[axis]);
	ui.orgTypeBox->setCurrentIndex(m_motionCardCfg.nOrgType[axis]);
	ui.orgNoBox->setCurrentIndex(m_motionCardCfg.nOrgNo[axis]);
	ui.orgFilterSpin->setValue(m_motionCardCfg.nOrgFilter[axis]);
	ui.emgTypeBox->setCurrentIndex(m_motionCardCfg.nEmgType[axis]);
	ui.emgNoBox->setCurrentIndex(m_motionCardCfg.nEmgNo[axis]);
	ui.emgFilterSpin->setValue(m_motionCardCfg.nEmgFilter[axis]);
	ui.dstpTypeBox->setCurrentIndex(m_motionCardCfg.nDstpType[axis]);
	ui.dstpNoBox->setCurrentIndex(m_motionCardCfg.nDstpNo[axis]);
	ui.dstpFilterSpin->setValue(m_motionCardCfg.nDstpFilter[axis]);
	ui.almTypeBox->setCurrentIndex(m_motionCardCfg.nAlmType[axis]);
	ui.almNoBox->setCurrentIndex(m_motionCardCfg.nAlmNo[axis]);
	ui.almFilterSpin->setValue(m_motionCardCfg.nAlmFilter[axis]);
	ui.inpTypeBox->setCurrentIndex(m_motionCardCfg.nInpType[axis]);
	ui.inpNoBox->setCurrentIndex(m_motionCardCfg.nInpNo[axis]);
	ui.inpFilterSpin->setValue(m_motionCardCfg.nInpFilter[axis]);

	switch (m_motionCardCfg.nPulseModeIndex[axis]) {
	case 0:
		ui.pulseMode0RBtn->setChecked(true);
		break;
	case 1:
		ui.pulseMode1RBtn->setChecked(true);
		break;
	case 2:
		ui.pulseMode2RBtn->setChecked(true);
		break;
	case 3:
		ui.pulseMode3RBtn->setChecked(true);
		break;
	case 4:
		ui.pulseMode4RBtn->setChecked(true);
		break;
	case 5:
		ui.pulseMode5RBtn->setChecked(true);
		break;
	}

	switch (m_motionCardCfg.nInputModeIndex[axis]) {
	case 0:
		ui.notABRBtn->setChecked(true);
		break;
	case 1:
		ui.singleABRBtn->setChecked(true);
		break;
	case 2:
		ui.doubleABRBtn->setChecked(true);
		break;
	case 3:
		ui.quadrupleABRBtn->setChecked(true);
		break;
	}
	if (0 == m_motionCardCfg.nEZLvLIndex[axis]) { ui.ezLowLvLRBtn->setChecked(true); }
	else { ui.ezHighLvLRBtn->setChecked(true); }
	ui.xEquivalency->setValue(Global::g_pulseEquivalent);
	ui.yEquivalency->setValue(Global::g_pulseEquivalent);
	ui.zEquivalency->setValue(Global::g_pulseEquivalent);
	ui.xyLineVectorVel->setValue(Global::g_xyLineVectorVel);
	ui.zVel->setValue(Global::g_zVel);

	if (0 == m_motionCardCfg.nHrSpeedIndex[axis]) { ui.hrSlowRBtn->setChecked(true); }
	else { ui.hrFastRBtn->setChecked(true); }
	if (0 == m_motionCardCfg.nHrDirectionIndex[axis]) { ui.hrNDirectionRBtn->setChecked(true); }
	else { ui.hrPDirectionRBtn->setChecked(true); }
	if (0 == m_motionCardCfg.nHrLvLIndex[axis]) { ui.hrLowLvLRBtn->setChecked(true); }
	else { ui.hrHighLvLRBtn->setChecked(true); }
	switch (m_motionCardCfg.nHrModeIndex[axis]) {
	case 0:
		ui.hrOnceRBtn->setChecked(true);
		break;
	case 1:
		ui.hrOnceAndBackwardRBtn->setChecked(true);
		break;
	case 2:
		ui.hrTwiceRBtn->setChecked(true);
		break;
	case 3:
		ui.hrHomeAndForwardEZRBtn->setChecked(true);
		break;
	case 4:
		ui.hrOnceEZRBtn->setChecked(true);
		break;
	case 5:
		ui.hrHomeAndBackwardEZRBtn->setChecked(true);
		break;
	}

	ui.hdwLimitEnableBox->setCurrentIndex(m_motionCardCfg.nHdwLimitEnableIndex[axis]);
	ui.hdwLimitLvLBox->setCurrentIndex(m_motionCardCfg.nHdwLimitLvLIndex[axis]);
	ui.hdwLimitModeBox->setCurrentIndex(m_motionCardCfg.nHdwLimitModeIndex[axis]);
	ui.sfwLimitEnableBox->setCurrentIndex(m_motionCardCfg.nSfwLimitEnableIndex[axis]);
	ui.sfwLimitModeBox->setCurrentIndex(m_motionCardCfg.nSfwLimitModeIndex[axis]);
	ui.sfwLimitCounterBox->setCurrentIndex(m_motionCardCfg.nSfwLimitCounterIndex[axis]);
	ui.sfwLimitPPSpin->setValue(m_motionCardCfg.nSfwLimitPPostion[axis]);
	ui.sfwLimitNPSpin->setValue(m_motionCardCfg.nSfwLimitNPostion[axis]);
	ui.ioDstpEnableBox->setCurrentIndex(m_motionCardCfg.nIODstpEnableIndex[axis]);
	ui.ioDstpLvLBox->setCurrentIndex(m_motionCardCfg.nIODstpLvLIndex[axis]);
	ui.ioDstpTimeSpin->setValue(m_motionCardCfg.nIODstpTime[axis]);
	ui.emgEnableBox->setCurrentIndex(m_motionCardCfg.nEmgEnableIndex[axis]);
	ui.emgLvLBox->setCurrentIndex(m_motionCardCfg.nEmgLvLIndex[axis]);
	ui.almEnableBox->setCurrentIndex(m_motionCardCfg.nAlmEnableIndex[axis]);
	ui.almLvLBox->setCurrentIndex(m_motionCardCfg.nAlmLvLIndex[axis]);
	ui.inpEnableBox->setCurrentIndex(m_motionCardCfg.nInpEnableIndex[axis]);
	ui.inpLvLBox->setCurrentIndex(m_motionCardCfg.nInpLvLIndex[axis]);

	connect(ui.xyLineVectorVel, SIGNAL(valueChanged(double)), this, SLOT(SyncMem()));
	connect(ui.zVel, SIGNAL(valueChanged(double)), this, SLOT(SyncMem()));
}
