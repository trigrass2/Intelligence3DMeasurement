#pragma once

#include <QDialog>
#include "ui_ProcessTypeCfgDlg.h"


class ProcessTypeCfgDlg : public QDialog
{
	Q_OBJECT

public:
	ProcessTypeCfgDlg(QWidget *parent = Q_NULLPTR);

protected:
	void showEvent(QShowEvent *e) Q_DECL_OVERRIDE;
	void closeEvent(QCloseEvent *e) Q_DECL_OVERRIDE;

private:
	Ui::ProcessTypeCfgDlg ui;

private slots:
	void SyncMem();
};
