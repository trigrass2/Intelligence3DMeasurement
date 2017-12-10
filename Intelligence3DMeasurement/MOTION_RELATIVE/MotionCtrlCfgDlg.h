#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QDialog>
#include "ui_MotionCtrlCfgDlg.h"

#include "LTDMC.h"

/**
 * @brief	‘Àøÿø®≈‰÷√±Ì
 */
struct MotionCardConfig {
	// I/O Map
	int nPelType[3];
	int nPelNo[3];
	double nPelFilter[3];
	int nNelType[3];
	int nNelNo[3];
	double nNelFilter[3];
	int nOrgType[3];
	int nOrgNo[3];
	double nOrgFilter[3];
	int nEmgType[3];
	int nEmgNo[3];
	double nEmgFilter[3];
	int nDstpType[3];
	int nDstpNo[3];
	double nDstpFilter[3];
	int nAlmType[3];
	int nAlmNo[3];
	double nAlmFilter[3];
	int nInpType[3];
	int nInpNo[3];
	double nInpFilter[3];
	// Pulse Mode
	int nPulseModeIndex[3];
	// Encoder
	int nInputModeIndex[3];
	int nEZLvLIndex[3];
	// Home Return
	double nHrSpeedIndex[3];
	int nHrDirectionIndex[3];
	int nHrLvLIndex[3];
	int nHrModeIndex[3];
	// Limit & Servo
	int nHdwLimitEnableIndex[3];
	int nHdwLimitLvLIndex[3];
	int nHdwLimitModeIndex[3];
	int nSfwLimitEnableIndex[3];
	int nSfwLimitModeIndex[3];
	int nSfwLimitCounterIndex[3];
	long nSfwLimitPPostion[3];
	long nSfwLimitNPostion[3];
	int nIODstpEnableIndex[3];
	int nIODstpLvLIndex[3];
	double nIODstpTime[3];
	int nEmgEnableIndex[3];
	int nEmgLvLIndex[3];
	int nAlmEnableIndex[3];
	int nAlmLvLIndex[3];
	int nInpEnableIndex[3];
	int nInpLvLIndex[3];
};


class MotionCtrlCfgDlg : public QDialog
{
	Q_OBJECT

public:
	MotionCtrlCfgDlg(QWidget *parent = Q_NULLPTR);
	~MotionCtrlCfgDlg();

	void EmergencyStop();

protected:
	void closeEvent(QCloseEvent *e) Q_DECL_OVERRIDE;

private:
	Ui::MotionCtrlCfgDlg ui;

	MotionCardConfig m_motionCardCfg;

	WORD Write2Card(int axis);
	void ApplyConfig();

private slots:
	void on_wrtAllBtn_clicked();
	void on_resetBtn_clicked();

	void SyncMem();
	void SyncUI(int axis);
};
