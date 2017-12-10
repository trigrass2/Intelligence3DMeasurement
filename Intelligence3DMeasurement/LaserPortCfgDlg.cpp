#include <QSerialPortInfo>
#include <QSettings>
#include <QFileInfo>
#include <QDebug>
#include "LaserPortCfgDlg.h"

#include "Global.h"


LaserPortCfgDlg::LaserPortCfgDlg(QWidget *parent)
	: QDialog(parent), m_currentIndex(9999)
{
	ui.setupUi(this);

	// *³õÊ¼»¯ÅäÖÃ±í -BEGIN
	m_config.nPortName = 0;
	m_config.nBaudRate = 0;
	m_config.nDataBits = 0;
	m_config.nParity = 0;
	m_config.nStopBits = 0;
	Global::g_isLaserConnected = false;
	
	QFileInfo cfgFile("./config.ini");
	if (cfgFile.isFile()) {
		QSettings cfgFile("./config.ini", QSettings::IniFormat);
		Global::g_laserBiasX = cfgFile.value("/LASER/Bias_X").toDouble();
		Global::g_laserBiasY = cfgFile.value("/LASER/Bias_Y").toDouble();
	}
	else {
		Global::g_laserBiasX = 0;
		Global::g_laserBiasY = 0;
	}
	// -END

	ui.baudRateComboBox->setCurrentIndex(m_config.nBaudRate);
	ui.dataBitsComboBox->setCurrentIndex(m_config.nDataBits);
	ui.parityComboBox->setCurrentIndex(m_config.nParity);
	ui.stopBitsComboBox->setCurrentIndex(m_config.nStopBits);
	ui.laserBiasX->setValue(Global::g_laserBiasX);
	ui.laserBiasY->setValue(Global::g_laserBiasY);

	connect(ui.laserBiasX, SIGNAL(valueChanged(double)), SLOT(SyncMem()));
	connect(ui.laserBiasY, SIGNAL(valueChanged(double)), SLOT(SyncMem()));

	ApplyConfig();
}

LaserPortCfgDlg::~LaserPortCfgDlg()
{
	m_laser.close();
}

void LaserPortCfgDlg::closeEvent(QCloseEvent * e)
{
	SyncMem();
	QSettings cfgFile("./config.ini", QSettings::IniFormat);
	cfgFile.setValue("/LASER/Bias_X", Global::g_laserBiasX);
	cfgFile.setValue("/LASER/Bias_Y", Global::g_laserBiasY);
}

void LaserPortCfgDlg::ApplyConfig()
{
	QList<QSerialPortInfo> allPorts = QSerialPortInfo::availablePorts();
	if (allPorts.count()>0) {
		ui.nameLineEdit->setText(allPorts[m_config.nPortName].portName());
		m_laser.setPort(allPorts[m_config.nPortName]);

		if (m_laser.open(QIODevice::ReadWrite)) {

			if (0 == m_config.nBaudRate) { m_laser.setBaudRate(QSerialPort::Baud9600); }
			else { m_laser.setBaudRate(QSerialPort::Baud19200); }

			switch (m_config.nDataBits)
			{
			case 0:
				m_laser.setDataBits(QSerialPort::Data8);
				break;
			case 1:
				m_laser.setDataBits(QSerialPort::Data7);
				break;
			case 2:
				m_laser.setDataBits(QSerialPort::Data6);
				break;
			default:
				m_laser.setDataBits(QSerialPort::Data5);
				break;
			}

			switch (m_config.nParity)
			{
			case 0:
				m_laser.setParity(QSerialPort::NoParity);
				break;
			case 1:
				m_laser.setParity(QSerialPort::EvenParity);
				break;
			case 2:
				m_laser.setParity(QSerialPort::OddParity);
				break;
			case 3:
				m_laser.setParity(QSerialPort::SpaceParity);
				break;
			default:
				m_laser.setParity(QSerialPort::MarkParity);
				break;
			}
			
			switch (m_config.nStopBits)
			{
			case 0:
				m_laser.setStopBits(QSerialPort::OneStop);
				break;
			case 1:
				m_laser.setStopBits(QSerialPort::OneAndHalfStop);
				break;
			default:
				m_laser.setStopBits(QSerialPort::TwoStop);
				break;
			}
			
			m_laser.setFlowControl(QSerialPort::NoFlowControl);

			m_laser.clearError();
			m_laser.clear();
			connect(&m_laser, SIGNAL(readyRead()), this, SLOT(GetData()));
			Global::g_isLaserConnected = true;
		}
		else {
			qDebug() << "Cannot connect to laser!";
		}
	}
	else {
		qDebug() << "No available serialports detected!";
	}
}

void LaserPortCfgDlg::on_readBtn_clicked()
{
	if (Global::g_isLaserConnected) {
		unsigned char inst[10] = {
		0x02, 0x4D, 0x45, 0x41, 0x53, 0x55, 0x52, 0x45, 0x03 };
		m_laser.write((char*)inst, 9);
	}
}

void LaserPortCfgDlg::SyncMem()
{
	Global::g_laserBiasX = ui.laserBiasX->value();
	Global::g_laserBiasY = ui.laserBiasY->value();
}

void LaserPortCfgDlg::GetData()
{
	QString data = m_laser.readAll();

	ui.testShowEdit->clear();
	ui.testShowEdit->setText(data);

	if (m_currentIndex != 9999) {
		Global::g_projectInfo.laserItems[m_currentIndex].ret = data;
		m_currentIndex = 9999;
	}
}

void LaserPortCfgDlg::WriteData(int index)
{
	m_currentIndex = index;
	on_readBtn_clicked();
}