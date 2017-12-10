#pragma once

#include <QDialog>
#include <QSerialPort>
#include "ui_LaserPortCfgDlg.h"

/**
 * @brief �������ñ�
 */
struct LaserConfig {
	int nPortName;		///< ���ں�
	int nBaudRate;		///< ������
	int nDataBits;		///< ����λ
	int nParity;		///< У��λ
	int nStopBits;		///< ֹͣλ
};


class LaserPortCfgDlg : public QDialog
{
	Q_OBJECT

public:
	LaserPortCfgDlg(QWidget *parent = Q_NULLPTR);
	~LaserPortCfgDlg();

protected:
	void closeEvent(QCloseEvent *e) Q_DECL_OVERRIDE;

private:
	Ui::LaserPortCfgDlg ui;

	LaserConfig m_config;
	QSerialPort m_laser;
	void ApplyConfig();

	int m_currentIndex;

private slots:
	void on_readBtn_clicked();
	void SyncMem();

public slots:
	void GetData();
	void WriteData(int index);
};
