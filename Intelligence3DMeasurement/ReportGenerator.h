#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QDialog>
#include "ui_ReportGenerator.h"

class ReportGenerator : public QDialog
{
	Q_OBJECT

public:
	ReportGenerator(QWidget *parent = Q_NULLPTR);
	void RefreshData();

protected:
	void showEvent(QShowEvent *e) Q_DECL_OVERRIDE;
	void closeEvent(QCloseEvent *e) Q_DECL_OVERRIDE;

private:
	Ui::ReportGenerator ui;

	bool m_isNew;
	QString m_report;

public slots:
	void on_saveBtn_clicked();
};
