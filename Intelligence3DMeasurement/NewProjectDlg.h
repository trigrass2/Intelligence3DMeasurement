#pragma once

#include <QDialog>
#include "ui_NewProjectDlg.h"

#include <QFileDialog>

class NewProjectDlg : public QDialog
{
	Q_OBJECT

public:
	NewProjectDlg(QWidget *parent = Q_NULLPTR);

private:
	Ui::NewProjectDlg ui;

private slots:
	void on_cadFileChsBtn_clicked();
	void on_confirmBtn_clicked();
	void on_abortBtn_clicked() { reject(); }
};
