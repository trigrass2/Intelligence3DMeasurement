#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QDialog>
#include <QSortFilterProxyModel>
#include <QSqlQueryModel>
#include <QStandardItemmodel>
#include "ui_DatabaseBrowser.h"


class DatabaseBrowser : public QDialog
{
	Q_OBJECT

public:
	DatabaseBrowser(QWidget *parent = Q_NULLPTR);
	static bool WriteIn(bool f);

private:
	Ui::DatabaseBrowser ui;

	QStandardItemModel *m_tbAreaModel;
	QSqlQueryModel *m_dataModel;
	QSortFilterProxyModel *m_dataAreaModel;

private slots:
	void on_refreshBtn_clicked();
	void on_queryBtn_clicked();
	void on_spcBtn_clicked();
	void on_tableArea_clicked(const QModelIndex &index);
};
