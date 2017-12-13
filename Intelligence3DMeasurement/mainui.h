#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QMainWindow>
#include "ui_mainui.h"

#include "centralwidget.h"
#include "LaserPortCfgDlg.h"
#include "ProcessTypeCfgDlg.h"
#include "MOTION_RELATIVE\MotionCtrlCfgDlg.h"
#include "DB_RELATIVE\DatabaseCfgDlg.h"


class MainUI : public QMainWindow
{
	Q_OBJECT

public:
	MainUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainUIClass ui;
	CentralWidget *m_ctWidget;

	MotionCtrlCfgDlg *m_motionModule;
	LaserPortCfgDlg *m_laserModule;
	DatabaseCfgDlg *m_dbModule;
	ProcessTypeCfgDlg *m_processTypeCfg;

	QMenu *m_deviceMgr;
	QMenu *m_infoMgr;
	QMenu *m_directoryMgr;
	void LoadMenu();

private slots:
	void ShowMC_triggerd();
	void ShowLaser_triggered();

	void RecordingLookUp_triggered();
	void DatabaseCfg_triggered();
	void ProcessTypeCfg_triggered();

	void ProjectDirectory_triggered();
	void CADFileDirectory_triggered();
	void ReportDirectory_triggered();

	void UpdateTitle();
};
