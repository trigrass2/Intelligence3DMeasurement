#include <QFileInfo>
#include <QFileDialog>
#include "NewProjectDlg.h"

#include "Global.h"


NewProjectDlg::NewProjectDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

void NewProjectDlg::on_cadFileChsBtn_clicked()
{
	QFile file(QFileDialog::getOpenFileName(this, "Choose a dxf file", CAD_DIRECTORY, "*.dxf"));
	QFileInfo info(file);
	ui.cadPath->setText(info.fileName());
}

void NewProjectDlg::on_confirmBtn_clicked()
{
	QString name = ui.projectName->text(), path = ui.cadPath->text();
	if (name.isEmpty() || path.isEmpty()) { return; }

	Global::g_projectInfo.projectName = name;
	Global::g_projectInfo.cadFile = path;
	Global::g_projectInfo.partName = ui.partName->text();
	Global::g_projectInfo.productModel = ui.productModel->text();
	Global::g_projectInfo.orderNumber = ui.orderNumber->text();
	Global::g_projectInfo.manufactory = ui.manufactory->text();
	Global::g_projectInfo.productionDate = ui.productionDate->date().toString("yyyy-MM-dd");
	Global::g_projectInfo.processName = ui.processName->text();
	Global::g_projectInfo.station = ui.station->text();

	accept();
}

