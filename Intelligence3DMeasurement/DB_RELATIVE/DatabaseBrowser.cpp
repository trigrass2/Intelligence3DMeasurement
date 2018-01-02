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

bool DatabaseBrowser::WriteIn(bool f)
{
	if (f) {
		QSqlQuery q;
		QString tableTemplate = "CREATE TABLE IF NOT EXISTS %1("
			"ID INT(11) NOT NULL AUTO_INCREMENT,"
			"product_model VARCHAR(40),"
			"order_number VARCHAR(40),"
			"m_date DATETIME NOT NULL,"
			"m_item VARCHAR(40),"
			"m_dimesion VARCHAR(40) NOT NULL,";
		for (int i = 0; i < Global::g_projectInfo.nSubGroupSize; ++i) {
			tableTemplate.append("ipqc" + QString::number(i + 1) + " DOUBLE NOT NULL,");
		}
		tableTemplate.append(
			"m_result VARCHAR(40),"
			"subgroup INT(11) NOT NULL,"
			"PRIMARY KEY(ID));");

		q.exec(tableTemplate.arg(Global::g_projectInfo.projectName +"_"+
			QString::number(Global::g_projectInfo.nSubGroupSize)));

		QString dataTemplate = "INSERT INTO " + Global::g_projectInfo.projectName +"_"+
			QString::number(Global::g_projectInfo.nSubGroupSize) +
			"(product_model,order_number,m_date,m_item,m_dimesion,";
		for (int i = 0; i < Global::g_projectInfo.nSubGroupSize; ++i) {
			dataTemplate.append("ipqc" + QString::number(i + 1) + ",");
		}
		dataTemplate.append("m_result,subgroup) VALUES('"+Global::g_projectInfo.productModel+
			"','"+Global::g_projectInfo.orderNumber+"','"+
			Global::g_projectInfo.mesurementDate+"',%1,%2,");
		int t = 0;
		for (; t < Global::g_projectInfo.nSubGroupSize; ++t) {
			dataTemplate.append("%" + QString::number(t + 3) + ",");
		}
		dataTemplate.append("%" + QString::number(t + 4) + ",");
		dataTemplate.append(QString::number(Global::g_projectInfo.nSubGroupSize) + ");");

		bool isSuccessed = true;
		Q_FOREACH(CAMERAITEM cam, Global::g_projectInfo.camItemList) {
			QString cmd = dataTemplate.arg("'"+cam.content+"'").arg(
				"'" + QString::number(cam.dStandardD) + "|" +
				QString::number(cam.dLowerD) + "|" + QString::number(cam.dUpperD) + "'");
			for (int i = 0; i < Global::g_projectInfo.nSubGroupSize; ++i) {
				cmd = cmd.arg(QString::number(cam.processedData[i]));
			}
			cmd = cmd.arg("'" + cam.conclusion + "'");
			qDebug() << cmd;
			isSuccessed = isSuccessed & q.exec(cmd);
			qDebug() << q.lastError();
		}
		Q_FOREACH(LASERITEM la, Global::g_projectInfo.laserItemList) {
			QString cmd = dataTemplate.arg("'" + la.content + "'").arg(
				"'" + QString::number(la.dStandardD) + "|" +
				QString::number(la.dLowerD) + "|" + QString::number(la.dUpperD) + "'");
			for (int i = 0; i < Global::g_projectInfo.nSubGroupSize; ++i) {
				cmd = cmd.arg(QString::number(la.processedData[i]));
			}
			cmd = cmd.arg("'" + la.conclusion + "'");
			qDebug() << cmd;
			isSuccessed = isSuccessed & q.exec(cmd);
		}

		if (isSuccessed) {
			QMessageBox::information(Q_NULLPTR, "数据库", "数据写入成功！", QMessageBox::Ok);
		}
		else {
			QMessageBox::warning(Q_NULLPTR, "数据库", "数据写入失败！", QMessageBox::Ok);
		}
		return isSuccessed;
	}
	return false;
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
	q.exec("SELECT m_item FROM " + Global::g_spc.table);
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
