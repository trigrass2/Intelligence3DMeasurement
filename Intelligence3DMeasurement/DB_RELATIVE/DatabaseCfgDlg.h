/************************
 *		数据库配置模块		* 
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
	QString driverType;	///< 驱动类型
	QString hostName;	///< 主机名
	QString dbName;		///< 数据库名
	int nPort;			///< 端口号
	QString userName;	///< 用户名
	QString pwd;		///< 密码
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
