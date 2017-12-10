#include <QSettings>
#include <QMessagebox>
#include <QDateTime>
#include "centralwidget.h"

#include "LTDMC.h"
#include "NewProjectDlg.h"
#include "Global.h"


CentralWidget::CentralWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.rightVLayout->setAlignment(ui.curPhotoViewer ,Qt::AlignCenter);
	
	projectItemsModel = new QStandardItemModel(ui.projectItemsView);
	projectItemsModel->setHorizontalHeaderItem(0, new QStandardItem("测量内容"));
	projectItemsModel->setHorizontalHeaderItem(1, new QStandardItem("Z坐标"));
	projectItemsModel->setHorizontalHeaderItem(2, new QStandardItem("标注值"));
	projectItemsModel->setHorizontalHeaderItem(3, new QStandardItem("上偏差"));
	projectItemsModel->setHorizontalHeaderItem(4, new QStandardItem("下偏差"));
	ui.projectItemsView->setModel(projectItemsModel);
	connect(projectItemsModel, SIGNAL(itemChanged(QStandardItem*)), SLOT(ModifyData(QStandardItem*)));
	connect(ui.projectItemsView, SIGNAL(clicked(QModelIndex)), ui.graphicViewer, SLOT(ActivateMarkItem(QModelIndex)));
	
	cameraCtrlPanel = new CameraCtrl(this);
	connect(cameraCtrlPanel, SIGNAL(SendAFrame(QPixmap)), this, SLOT(ShowPhoto(QPixmap)));

	visionModule = new Vision;
	connect(visionModule, SIGNAL(ProcessDone()), this, SLOT(ShowResult()));

	executor = new MotionExecutor;
	connect(executor, SIGNAL(finished()), visionModule, SLOT(ImgProc()));
	connect(executor, SIGNAL(LaserRequire(int)), this, SIGNAL(LaserRequire2(int)));

	reporter = new ReportGenerator(this);
	reporter->hide();

	connect(this, SIGNAL(ProjectNew(bool)), ui.graphicViewer, SLOT(OpenDXF(bool)));
	connect(this, SIGNAL(ProjectLoad()), ui.graphicViewer, SLOT(LoadProject()));
	connect(ui.replanBtn, SIGNAL(clicked()), ui.graphicViewer, SLOT(Replan()));

	connect(ui.graphicViewer, SIGNAL(RequireTitleUpdate()), this, SIGNAL(TitleUpdate()));
	connect(ui.graphicViewer, SIGNAL(NodeListTableUpdate()), this, SLOT(UpdateNodeListTable()));
}

CentralWidget::~CentralWidget()
{
	on_stopBtn_clicked();
	delete visionModule;
}

void CentralWidget::ShowPhoto(const QPixmap &p)
{
	ui.curPhotoViewer->setPixmap(
		p.scaled(ui.curPhotoViewer->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void CentralWidget::on_cameraCtrlBtn_clicked()
{
	cameraCtrlPanel->show();
}

void CentralWidget::UpdateNodeListTable()
{
	projectItemsModel->removeRows(0, projectItemsModel->rowCount());
	for (int i = 0; i<Global::g_projectInfo.camearItems.count(); ++i) {
		projectItemsModel->setItem(i, 0, new QStandardItem(Global::g_projectInfo.camearItems.at(i).content));
		projectItemsModel->setItem(i, 1, new QStandardItem(QString::number(
			Global::g_projectInfo.camearItems.at(i).nHeight)));
		projectItemsModel->setItem(i, 2, new QStandardItem("value"));
		projectItemsModel->setItem(i, 3, new QStandardItem("up"));
		projectItemsModel->setItem(i, 4, new QStandardItem("down"));
	}

	int bias = projectItemsModel->rowCount();
	for (int i = 0; i<Global::g_projectInfo.laserItems.count(); ++i) {
		projectItemsModel->setItem(i + bias, 0, new QStandardItem(Global::g_projectInfo.laserItems.at(i).content));
		projectItemsModel->setItem(i + bias, 1, new QStandardItem(QString::number(
			Global::g_projectInfo.laserItems.at(i).nHeight)));
		projectItemsModel->setItem(i + bias, 2, new QStandardItem("value"));
		projectItemsModel->setItem(i + bias, 3, new QStandardItem("up"));
		projectItemsModel->setItem(i + bias, 4, new QStandardItem("down"));
	}

	QString toolTip;
	toolTip.append("零件名称：" + Global::g_projectInfo.partName);
	toolTip.append("\n");
	toolTip.append("产品型号：" + Global::g_projectInfo.productModel);
	toolTip.append("\n");
	toolTip.append("订单号：" + Global::g_projectInfo.orderNumber);
	toolTip.append("\n");
	toolTip.append("生产单位：" + Global::g_projectInfo.manufactory);
	toolTip.append("\n");
	toolTip.append("生产日期：" + Global::g_projectInfo.productionDate);
	toolTip.append("\n");
	toolTip.append("工序名称：" + Global::g_projectInfo.processName);
	toolTip.append("\n");
	toolTip.append("工位编号：" + Global::g_projectInfo.station);
	ui.projectItemsView->setToolTip(toolTip);
}

void CentralWidget::on_newBtn_clicked()
{
	NewProjectDlg *newPrjDlg = new NewProjectDlg;
	if (newPrjDlg->exec() == QDialog::Accepted) {
		emit ProjectNew(true);
		on_replanBtn_clicked();
	}
	delete newPrjDlg;
}

void CentralWidget::on_replanBtn_clicked()
{
	projectItemsModel->removeRows(0, projectItemsModel->rowCount());
	
	ui.projectItemsView->setToolTip("方案详情");
}

void CentralWidget::on_loadBtn_clicked()
{
	QString prj = QFileDialog::getOpenFileName(this, tr("载入项目文件"),
		PROJECT_DIRECTORY + Global::g_projectInfo.projectName + ".prj", tr("Project (*.prj)"));
	if (!prj.isEmpty()) {
		// Load
		QSettings prjFile(prj, QSettings::IniFormat);
		Global::g_projectInfo.projectName = prjFile.value("OVERRALL/ProjectName").toString();
		Global::g_projectInfo.cadFile = prjFile.value("OVERRALL/CAD").toString();
		Global::g_projectInfo.partName = prjFile.value("OVERRALL/PartName").toString();
		Global::g_projectInfo.productModel = prjFile.value("OVERRALL/ProductModel").toString();
		Global::g_projectInfo.orderNumber = prjFile.value("OVERRALL/OrderNumber").toString();
		Global::g_projectInfo.manufactory = prjFile.value("OVERRALL/Manufactory").toString();
		Global::g_projectInfo.productionDate = prjFile.value("OVERRALL/ProductionDate").toString();
		Global::g_projectInfo.processName = prjFile.value("OVERRALL/ProcessName").toString();
		Global::g_projectInfo.station = prjFile.value("OVERRALL/Station").toString();
		int size = prjFile.beginReadArray("OVERRALL/CameraSequence");
		Global::g_projectInfo.camSequence.clear();
		for (int i = 0; i < size; ++i) {
			prjFile.setArrayIndex(i);
			Global::g_projectInfo.camSequence.append(prjFile.value("idx").toInt());
		}
		prjFile.endArray();
		size = prjFile.beginReadArray("OVERRALL/CameraItem");
		Global::g_projectInfo.camearItems.clear();
		for (int i = 0; i < size; ++i) {
			prjFile.setArrayIndex(i);
			CAMERAITEM item;
			int size2 = prjFile.beginReadArray("OVERRALL/CameraItem/Node");
			for (int j = 0; j < size2; ++j) {
				prjFile.setArrayIndex(j);
				item.ctrlNodes.append(prjFile.value("_p").toPointF());
			}
			prjFile.endArray();
			item.bIsInverted = prjFile.value("invert").toBool();
			item.type = prjFile.value("type").toInt();
			item.content = prjFile.value("content").toString();
			item.nHeight = prjFile.value("height").toInt();
			Global::g_projectInfo.camearItems.append(item);
		}
		prjFile.endArray();
		size = prjFile.beginReadArray("OVERRALL/LaserItem");
		Global::g_projectInfo.laserItems.clear();
		for (int i = 0; i < size; ++i) {
			prjFile.setArrayIndex(i);
			LASERITEM item;
			int size2 = prjFile.beginReadArray("OVERRALL/LaserItem/Node");
			for (int j = 0; j < size2; ++j) {
				prjFile.setArrayIndex(j);
				item.nodes.append(prjFile.value("_p").toPointF());
			}
			prjFile.endArray();
			item.content = prjFile.value("content").toString();
			item.nHeight = prjFile.value("height").toInt();
			Global::g_projectInfo.laserItems.append(item);
		}
		prjFile.endArray();
		Global::g_projectInfo.startPoint = prjFile.value("OVERRALL/StartPoint").toPointF();

		emit ProjectLoad();
		UpdateNodeListTable();
	}
}

void CentralWidget::on_saveBtn_clicked()
{
	QString prj = QFileDialog::getSaveFileName(this, tr("保存项目文件"),
		PROJECT_DIRECTORY + Global::g_projectInfo.projectName + ".prj", tr("Project (*.prj)"));
	QSettings prjFile(prj, QSettings::IniFormat);
	if (!prj.isEmpty()) {
		if (Global::g_projectInfo.camSequence.isEmpty()) {
			QMessageBox::warning(this, tr("提示"), tr("项目信息不完整！"));
		}
		else {
			// Save
			QSettings prjFile(prj, QSettings::IniFormat);
			prjFile.setValue("OVERRALL/ProjectName", Global::g_projectInfo.projectName);
			prjFile.setValue("OVERRALL/CAD", Global::g_projectInfo.cadFile);
			prjFile.setValue("OVERRALL/PartName", Global::g_projectInfo.partName);
			prjFile.setValue("OVERRALL/ProductModel", Global::g_projectInfo.productModel);
			prjFile.setValue("OVERRALL/OrderNumber", Global::g_projectInfo.orderNumber);
			prjFile.setValue("OVERRALL/Manufactory", Global::g_projectInfo.manufactory);
			prjFile.setValue("OVERRALL/ProductionDate", Global::g_projectInfo.productionDate);
			prjFile.setValue("OVERRALL/ProcessName", Global::g_projectInfo.processName);
			prjFile.setValue("OVERRALL/Station", Global::g_projectInfo.station);
			prjFile.beginWriteArray("OVERRALL/CameraSequence");
			for (int i = 0; i < Global::g_projectInfo.camSequence.count(); ++i) {
				prjFile.setArrayIndex(i);
				prjFile.setValue("idx", Global::g_projectInfo.camSequence.at(i));
			}
			prjFile.endArray();
			prjFile.beginWriteArray("OVERRALL/CameraItem");
			for (int i = 0; i < Global::g_projectInfo.camearItems.count(); ++i) {
				prjFile.setArrayIndex(i);
				prjFile.beginWriteArray("OVERRALL/CameraItem/Node");
				for (int j = 0; j < Global::g_projectInfo.camearItems.at(i).ctrlNodes.count(); ++j) {
					prjFile.setArrayIndex(j);
					prjFile.setValue("_p", Global::g_projectInfo.camearItems.at(i).ctrlNodes.at(j));
				}
				prjFile.endArray();
				prjFile.setValue("invert", Global::g_projectInfo.camearItems.at(i).bIsInverted);
				prjFile.setValue("type", Global::g_projectInfo.camearItems.at(i).type);
				prjFile.setValue("content", Global::g_projectInfo.camearItems.at(i).content);
				prjFile.setValue("height", Global::g_projectInfo.camearItems.at(i).nHeight);
			}
			prjFile.endArray();
			prjFile.beginWriteArray("OVERRALL/LaserItem");
			for (int i = 0; i < Global::g_projectInfo.laserItems.count(); ++i) {
				prjFile.setArrayIndex(i);
				prjFile.beginWriteArray("OVERRALL/LaserItem/Node");
				for (int j = 0; j < Global::g_projectInfo.laserItems.at(i).nodes.count(); ++j) {
					prjFile.setArrayIndex(j);
					prjFile.setValue("_p", Global::g_projectInfo.laserItems.at(i).nodes.at(j));
				}
				prjFile.endArray();
				prjFile.setValue("content", Global::g_projectInfo.laserItems.at(i).content);
				prjFile.setValue("height", Global::g_projectInfo.laserItems.at(i).nHeight);
			}
			prjFile.endArray();
			prjFile.setValue("OVERRALL/StartPoint", Global::g_projectInfo.startPoint);
		}
	}
}

void CentralWidget::on_stopBtn_clicked()
{
	cameraCtrlPanel->on_stopBtn_clicked();
}

void CentralWidget::on_startBtn_clicked()
{
	executor->start();
}

void CentralWidget::ShowResult()
{
	Global::g_projectInfo.mesurementDate = QDateTime::currentDateTime().toString("yyyy-MM-dd HHmmss");
	reporter->RefreshData();
	reporter->exec();
}

void CentralWidget::ModifyData(QStandardItem* item)
{
	if (item->column() == 0) {
		int row = item->row();
		int count0 = Global::g_projectInfo.camearItems.count();

		if (row <= count0 - 1) { Global::g_projectInfo.camearItems[row].content = item->text(); }
		else { Global::g_projectInfo.laserItems[row - count0].content = item->text(); }
	}

	if (item->column() == 1) {
		int row = item->row();
		int count0 = Global::g_projectInfo.camearItems.count();
		int newHeight = item->text().toInt();

		if (row <= count0 - 1) { Global::g_projectInfo.camearItems[row].nHeight = newHeight; }
		else { Global::g_projectInfo.laserItems[row - count0].nHeight = newHeight; }
	}
}
