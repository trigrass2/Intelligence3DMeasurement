#pragma once

#include <QDialog>
#include <QSerialPort>
#include "ui_LaserPortCfgDlg.h"

/**
 * @brief 激光配置表
 */
struct LaserConfig {
	int nPortName;		///< 串口号
	int nBaudRate;		///< 波特率
	int nDataBits;		///< 数据位
	int nParity;		///< 校验位
	int nStopBits;		///< 停止位
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
