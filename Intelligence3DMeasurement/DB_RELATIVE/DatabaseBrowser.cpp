#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "DatabaseBrowser.h"

#include "Global.h"
#include "SPC_RELATIVE\DataRangeSelector.h"
#include "SPC_RELATIVE\SPCPlots.h"


DatabaseBrowser::DatabaseBrowser(QWidget *parent)
	: QDialog(parent, Qt::Window)
{
	ui.setupUi(this);
	ui.dataArea->verticalHeader()->hide();
	
	m_tbAreaModel = new QStandardItemModel(ui.tableArea);
	ui.tableArea->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableArea->setHeaderHidden(true);
	ui.tableArea->setModel(m_tbAreaModel);

	m_dataModel = new QSqlQueryModel(ui.dataArea);
	m_dataAreaModel = new QSortFilterProxyModel(ui.dataArea);
	m_dataAreaModel->setSourceModel(m_dataModel);
	ui.dataArea->setModel(m_dataAreaModel);
	ui.dataArea->setSortingEnabled(true);

	on_refreshBtn_clicked();
}

void DatabaseBrowser::WriteIn(bool f)
{
	if (f) {
		QSqlQuery q;
		q.exec("CREATE TABLE IF NOT EXISTS " + Global::g_projectInfo.projectName + "("
			"Project_ID INT(11) NOT NULL AUTO_INCREMENT,"
			"Content VARCHAR(40) NOT NULL,"
			"Standard DOUBLE NOT NULL,"
			"Upper DOUBLE NOT NULL,"
			"Lower DOUBLE NOT NULL,"
			"Ret DOUBLE NOT NULL,"
			"Conclusion VARCHAR(40) NOT NULL,"
			"MDate DATETIME NOT NULL,"
			"PRIMARY KEY(Project_ID));"
		);

		bool isSuccessed = true;
		Q_FOREACH(CAMERAITEM cam, Global::g_projectInfo.camearItems) {
			QString cmd = "INSERT INTO " + Global::g_projectInfo.projectName +
				"(Content,Standard,Upper,Lower,Ret,Conclusion,MDate) "
				"VALUES('" + cam.content + "'," +
				QString::number(cam.dStandard) + "," +
				QString::number(cam.dUpper) + "," +
				QString::number(cam.dLower) + "," + QString::number(cam.ret) + ","
				"'" + cam.conclusion + "',"
				"'" + Global::g_projectInfo.mesurementDate + "');";
			qDebug() << cmd;
			isSuccessed = isSuccessed & q.exec(cmd);
		}
		Q_FOREACH(LASERITEM la, Global::g_projectInfo.laserItems) {
			isSuccessed = isSuccessed & q.exec("INSERT INTO " + Global::g_projectInfo.projectName +
				"(Content,Standard,Upper,Lower,Ret,Conclusion,MDate) "
				"VALUES('" + la.content + "'," +
				QString::number(la.dStandard) + "," +
				QString::number(la.dUpper) + "," +
				QString::number(la.dLower) + "," + QString::number(la.ret) + ","
				"'" + la.conclusion + "',"
				"'" + Global::g_projectInfo.mesurementDate + "');"
			);
		}

		if (isSuccessed) {
			QMessageBox::information(Q_NULLPTR, "数据库", "数据写入成功！", QMessageBox::Ok);
		}
		else {
			QMessageBox::warning(Q_NULLPTR, "数据库", "数据写入失败！", QMessageBox::Ok);
		}
	}
}

void DatabaseBrowser::on_refreshBtn_clicked()
{
	m_tbAreaModel->clear();

	QSqlQuery q;
	q.exec("SHOW TABLES");
	while (q.next()) {
			QStandardItem *root = new QStandardItem(q.value(0).toString());
			m_tbAreaModel->appendRow(root);
	}
}

void DatabaseBrowser::on_queryBtn_clicked()
{
	QString field = ui.fieldBox->currentText(),
		value1 = ui.value1Edit->text(),
		value2 = ui.value2Edit->text();
	if (!value1 .isEmpty() && value2.isEmpty()) {
		m_dataModel->setQuery("SELECT * FROM " + Global::g_spc.table + " WHERE " + field +
			" >= " + value1);
	}
	else if (value1.isEmpty() && !value2.isEmpty()) {
		m_dataModel->setQuery("SELECT * FROM " + Global::g_spc.table + " WHERE " + field +
			" <= " + value2);
	}
	else if (!value1.isEmpty() && !value2.isEmpty()) {
		m_dataModel->setQuery("SELECT * FROM " + Global::g_spc.table + " WHERE " + field +
			" BETWEEN " + value1 + " AND " + value2);
	}
	else {
		m_dataModel->setQuery("SELECT " + field + " FROM " + Global::g_spc.table);
	}
}

void DatabaseBrowser::on_spcBtn_clicked()
{
	QStringList items;
	items << "NULL";

	QSqlQuery q;
	q.exec("SELECT Content FROM " + Global::g_spc.table);
	while (q.next()) { items << q.value(0).toString(); }
	items.removeDuplicates();

	DataRangeSelector drs(items, this);
	if (drs.exec() == QDialog::Accepted) {
		SPCPlots plot(this);
		plot.exec();
	}
}

void DatabaseBrowser::on_tableArea_clicked(const QModelIndex & index)
{
	ui.fieldBox->clear();

	if (index.isValid()) {
		Global::g_spc.table = index.data().toString();
		m_dataModel->setQuery("SELECT * FROM " + Global::g_spc.table);

		QStringList fieldList;
		QSqlQuery q;
		q.exec("DESC " + Global::g_spc.table);
		while (q.next()) { fieldList << q.value(0).toString(); }
		ui.fieldBox->addItems(fieldList);
	}
	else {
		ui.fieldBox->clear();
		m_dataModel->clear();
	}
}
