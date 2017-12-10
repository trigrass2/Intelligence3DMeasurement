#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QWidget>
#include <QSortFilterProxyModel>
#include <QSqlQueryModel>
#include <QStandardItemmodel>
#include "ui_DatabaseBrowser.h"


class DatabaseBrowser : public QWidget
{
	Q_OBJECT

public:
	DatabaseBrowser(QWidget *parent = Q_NULLPTR);

private:
	Ui::DatabaseBrowser ui;

	QStandardItemModel *m_tbAreaModel;
	QSqlQueryModel *m_dataModel;		///< 数据库查询模型
	QSortFilterProxyModel *m_dataAreaModel;
	QString m_currentTable;

private slots:
	void on_refreshBtn_clicked();
	void on_queryBtn_clicked();
	void on_tableArea_clicked(const QModelIndex &index);
	void on_exportBtn_clicked();
	void on_spcBtn_clicked();
};
