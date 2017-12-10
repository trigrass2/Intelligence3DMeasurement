/************************
 *		���ݿ�����ģ��		* 
 *		2017-12-01		*
 *		by XF			*
 ************************/
#pragma once

#include <QDialog>
#include <QSqlDatabase>
#include "ui_DatabaseCfgDlg.h"

/**
 * @brief Config Table
 */
struct DBCongfig {
	QString driverType;	///< ��������
	QString hostName;	///< ������
	QString dbName;		///< ���ݿ���
	int nPort;			///< �˿ں�
	QString userName;	///< �û���
	QString pwd;		///< ����
};


class DatabaseCfgDlg : public QDialog
{
	Q_OBJECT

public:
	DatabaseCfgDlg(QWidget *parent = Q_NULLPTR);
	~DatabaseCfgDlg();

protected:
	void closeEvent(QCloseEvent *e) Q_DECL_OVERRIDE;

private:
	Ui::DatabaseCfgDlg ui;

	DBCongfig m_config;

	QSqlDatabase m_db;

	void ApplyConfig();

private slots:
	void SyncMem();
};
