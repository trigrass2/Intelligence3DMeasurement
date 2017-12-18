#include <QSettings>
#include <QDesktopServices>
#include <QDir>
#include "mainui.h"

#include "DB_RELATIVE\DatabaseBrowser.h"
#include "LTDMC.h"
#include "Global.h"


MainUI::MainUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowState(Qt::WindowMaximized);

	m_ctWidget = new CentralWidget;
	connect(m_ctWidget, SIGNAL(TitleUpdate()), this, SLOT(UpdateTitle()));
	setCentralWidget(m_ctWidget);

	LoadMenu();

	QDir dir;
	if (!dir.exists(PROJECT_DIRECTORY)){ dir.mkdir(PROJECT_DIRECTORY); }
	if (!dir.exists(CAD_DIRECTORY)) { dir.mkdir(CAD_DIRECTORY); }
	if (!dir.exists(REPORT_DIRECTORY)) { dir.mkdir(REPORT_DIRECTORY); }
	

	// *ģ���ʼ�� -BEGIN
	m_motionModule = new MotionCtrlCfgDlg(this);
	m_laserModule = new LaserPortCfgDlg(this);
	m_dbModule = new DatabaseCfgDlg(this);
	m_processTypeCfg = new ProcessTypeCfgDlg(this);

	connect(m_ctWidget, SIGNAL(LaserRequire2(int)), m_laserModule, SLOT(WriteData(int)));
	// -END
}

void MainUI::LoadMenu()
{
	m_deviceMgr = new QMenu("�豸����");
	m_deviceMgr->addAction("�˶����ƿ�", this, &MainUI::ShowMC_triggerd, tr("Ctrl+M"));
	m_deviceMgr->addAction("���⴫����", this, &MainUI::ShowLaser_triggered, tr("Ctrl+L"));

	m_infoMgr = new QMenu("��Ϣ����");
	m_infoMgr->addAction("��¼��ѯ", this, &MainUI::RecordingLookUp_triggered, tr("Ctrl+R"));
	m_infoMgr->addAction("���ݿ�����", this, &MainUI::DatabaseCfg_triggered, tr("Ctrl+D"));
	m_infoMgr->addAction("���ݴ�������", this, &MainUI::ProcessTypeCfg_triggered, tr("Ctrl+P"));

	m_directoryMgr = new QMenu("Ŀ¼����");
	m_directoryMgr->addAction("��������", this, &MainUI::ProjectDirectory_triggered);
	m_directoryMgr->addAction("CADͼֽ", this, &MainUI::CADFileDirectory_triggered);
	m_directoryMgr->addAction("����", this, &MainUI::ReportDirectory_triggered);

	menuBar()->addMenu(m_deviceMgr);
	menuBar()->addMenu(m_infoMgr);
	menuBar()->addMenu(m_directoryMgr);
}

void MainUI::ShowMC_triggerd()
{
	m_motionModule->exec();
}

void MainUI::ShowLaser_triggered()
{
	m_laserModule->show();
}

void MainUI::RecordingLookUp_triggered()
{
	DatabaseBrowser dbBrowser(this);
	dbBrowser.exec();
}

void MainUI::DatabaseCfg_triggered()
{
	m_dbModule->exec();
}

void MainUI::ProcessTypeCfg_triggered()
{
	m_processTypeCfg->exec();
}

void MainUI::ProjectDirectory_triggered()
{
	QDesktopServices::openUrl(QUrl(QString("file:") + PROJECT_DIRECTORY, QUrl::TolerantMode));
}

void MainUI::CADFileDirectory_triggered()
{
	QDesktopServices::openUrl(QUrl(QString("file:") + CAD_DIRECTORY, QUrl::TolerantMode));
}

void MainUI::ReportDirectory_triggered()
{
	QDesktopServices::openUrl(QUrl(QString("file:") + REPORT_DIRECTORY, QUrl::TolerantMode));
}

void MainUI::UpdateTitle()
{
	setWindowTitle("��ά���ܼ��ƽ̨ϵͳ - " + Global::g_projectInfo.projectName);
}