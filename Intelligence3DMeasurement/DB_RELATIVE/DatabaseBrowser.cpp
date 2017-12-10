#include <QSqlError>
#include <QSqlQuery>
#include "DatabaseBrowser.h"

#include "spc\spcwidget.h"

DatabaseBrowser::DatabaseBrowser(QWidget *parent)
	: QWidget(parent, Qt::Window)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
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

void DatabaseBrowser::on_refreshBtn_clicked()
{
	m_tbAreaModel->clear();
	QStringList tableTags, roots;
	QString key, value;
	QSqlQuery q;
	q.exec("SHOW TABLES");
	while (q.next()) {
		tableTags = q.value(0).toString().split("_");
		key = tableTags.first();
		value = tableTags.last();
		if (!roots.contains(key)) {
			roots << key;
			QStandardItem *root = new QStandardItem(key);
			m_tbAreaModel->appendRow(root);
			root->appendRow(new QStandardItem(value));
		}
		else {
			m_tbAreaModel->findItems(key).first()->appendRow(new QStandardItem(value));
		}
	}
}

void DatabaseBrowser::on_queryBtn_clicked()
{
	QString field = ui.fieldBox->currentText(),
		value1 = ui.value1Edit->text(),
		value2 = ui.value2Edit->text();
	if (!value1 .isEmpty() && value2.isEmpty()) {
		m_dataModel->setQuery("SELECT * FROM " + m_currentTable + " WHERE " + field +
			" >= " + value1);
	}
	else if (value1.isEmpty() && !value2.isEmpty()) {
		m_dataModel->setQuery("SELECT * FROM " + m_currentTable + " WHERE " + field +
			" <= " + value2);
	}
	else if (!value1.isEmpty() && !value2.isEmpty()) {
		m_dataModel->setQuery("SELECT * FROM " + m_currentTable + " WHERE " + field +
			" BETWEEN " + value1 + " AND " + value2);
	}
	else {
		m_dataModel->setQuery("SELECT " + field + " FROM " + m_currentTable);
	}
}
/**
 * @brief	读取当前表数据
 * @param	index	模型选中索引
 */
void DatabaseBrowser::on_tableArea_clicked(const QModelIndex & index)
{
	ui.fieldBox->clear();
	QModelIndex parent = index.parent();
	if (parent.isValid()) {
		m_currentTable = parent.data().toString() + "_" + index.data().toString();
		m_dataModel->setQuery("SELECT * FROM " + m_currentTable);

		QStringList fieldList;
		QSqlQuery q;
		q.exec("DESC " + m_currentTable);
		while (q.next())
		{
			fieldList << q.value(0).toString();
		}
		ui.fieldBox->addItems(fieldList);
	}
	else {
		ui.fieldBox->clear();
		m_dataModel->clear();
	}
}

void DatabaseBrowser::on_exportBtn_clicked()
{
}

void DatabaseBrowser::on_spcBtn_clicked()
{
	int n;														// 子组容量
	QVector<qreal> x, mean, r;
	x << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;		// 数据个数
	mean << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;	// 数据平均值
	r << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;		// 极距

	SPCWidget spc;
	spc.drawXRctrl(x, mean, r, n);
	spc.exec();
}
