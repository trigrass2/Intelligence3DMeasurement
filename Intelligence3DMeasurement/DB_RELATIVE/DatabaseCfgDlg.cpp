#include <QSettings>
#include <QFileInfo>
#include <QDebug>
#include "DatabaseCfgDlg.h"


DatabaseCfgDlg::DatabaseCfgDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	// *Initialization -BEGIN
	m_config.driverType = "QMYSQL";
	m_config.hostName = "localhost";
	// User's config override
	QFileInfo cfgFile("./config.ini");
	if (cfgFile.isFile()) {
		QSettings cfgFile("./config.ini", QSettings::IniFormat);
		m_config.dbName = cfgFile.value("/DB/Datebase").toString();
		m_config.nPort = cfgFile.value("/DB/Port").toInt();
		m_config.userName = cfgFile.value("/DB/User").toString();
		m_config.pwd = cfgFile.value("/DB/Password").toString();
	}
	else {
		m_config.dbName = "testdb";
		m_config.nPort = 3306;
		m_config.userName = "root";
		m_config.pwd = "123456";
	}
	// -END

	ui.driverComboBox->setCurrentIndex(ui.driverComboBox->findText(m_config.driverType));
	ui.hostLineEdit->setText(m_config.hostName);
	ui.dbLineEdit->setText(m_config.dbName);
	ui.portSpinBox->setValue(m_config.nPort);
	ui.userLineEdit->setText(m_config.userName);
	ui.pwdLineEdit->setText(m_config.pwd);

	connect(ui.dbLineEdit, SIGNAL(textChanged(QString)), SLOT(SyncMem()));
	connect(ui.portSpinBox, SIGNAL(valueChanged(int)), SLOT(SyncMem()));
	connect(ui.userLineEdit, SIGNAL(textChanged(QString)), SLOT(SyncMem()));
	connect(ui.pwdLineEdit, SIGNAL(textChanged(QString)), SLOT(SyncMem()));

	ApplyConfig();
}

DatabaseCfgDlg::~DatabaseCfgDlg()
{
	m_db.close();
}

void DatabaseCfgDlg::closeEvent(QCloseEvent * e)
{
	SyncMem();
	QSettings cfgFile("./config.ini", QSettings::IniFormat);
	cfgFile.setValue("/DB/Datebase", m_config.dbName);
	cfgFile.setValue("/DB/Port", m_config.nPort);
	cfgFile.setValue("/DB/User", m_config.userName);
	cfgFile.setValue("/DB/Password", m_config.pwd);
}

void DatabaseCfgDlg::ApplyConfig()
{
	m_db = QSqlDatabase::addDatabase(m_config.driverType);
	m_db.setHostName(m_config.hostName);
	m_db.setDatabaseName(m_config.dbName);
	m_db.setPort(m_config.nPort);
	m_db.setUserName(m_config.userName);
	m_db.setPassword(m_config.pwd);
	if (!m_db.open()) {
		qDebug() << "DB disconnected!";
	}
}

void DatabaseCfgDlg::SyncMem()
{
	m_config.dbName = ui.dbLineEdit->text();
	m_config.nPort = ui.portSpinBox->value();
	m_config.userName = ui.userLineEdit->text();
	m_config.pwd = ui.pwdLineEdit->text();
}