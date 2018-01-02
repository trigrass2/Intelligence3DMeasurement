#include <QSettings>
#include <QMessagebox>
#include <QDateTime>
#include <QFileDialog>
#include "centralwidget.h"

#include "LTDMC.h"
#include "NewProjectDlg.h"
#include "Global.h"
#include "M_ALGRITHM_RELATIVE\Laser.h"


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
	connect(cameraCtrlPanel, SIGNAL(ShowAFrame()), this, SLOT(ShowPhoto()));

	LaserAlgrithm = new Laser(this);
	connect(LaserAlgrithm, SIGNAL(LaserProcessDone()), this, SLOT(ShowResult()));

	visionModule = new Vision(this);
	connect(visionModule, SIGNAL(VisionProcessDone()), LaserAlgrithm, SLOT(LaserProc()));
	

	if (ENABLE_VISION_MODULE) {
		// Display window initial
		OpenWindow(0, 0, 700, 400, (Hlong)ui.curPhotoViewer->winId(), "", "", &Global::hv_window);
		SetPart(Global::hv_window, 0, 0, 1944, 2592);
	}

	executor = new MotionExecutor;
	connect(executor, SIGNAL(finished()), visionModule, SLOT(ImgProc()));
	connect(executor, SIGNAL(ShowCurPhoto()), this, SLOT(ShowPhoto()));
	connect(executor, SIGNAL(LaserRequire(int)), this, SIGNAL(LaserRequire2(int)));
	connect(ui.stopBtn, SIGNAL(clicked()), executor, SLOT(Stop()));

	reporter = new ReportGenerator(this);
	reporter->hide();

	connect(this, SIGNAL(ProjectNew(bool)), ui.graphicViewer, SLOT(OpenDXF(bool)));
	connect(this, SIGNAL(ProjectLoad()), ui.graphicViewer, SLOT(LoadProject()));
	connect(ui.replanBtn, SIGNAL(clicked()), ui.graphicViewer, SLOT(Replan()));

	connect(ui.graphicViewer, SIGNAL(RequireTitleUpdate()), this, SIGNAL(TitleUpdate()));
	connect(ui.graphicViewer, SIGNAL(NodeListTableUpdate()), this, SLOT(UpdateNodeListTable()));
}

void CentralWidget::ShowPhoto()
{
	if (ENABLE_VISION_MODULE) {
		if (Global::g_enableCamCtrl) { GrabImage(&Global::g_curPhoto, Global::acqHandle); }
		DispObj(Global::g_curPhoto, Global::hv_window);
		DispCross(Global::hv_window, 972, 1296, 500, 0);
	}
}

void CentralWidget::on_cameraCtrlBtn_clicked()
{
	if (Global::g_enableCamCtrl) { cameraCtrlPanel->show(); }
}

void CentralWidget::UpdateNodeListTable()
{
	projectItemsModel->removeRows(0, projectItemsModel->rowCount());
	for (int i = 0; i<Global::g_projectInfo.camItemList.count(); ++i) {
		projectItemsModel->setItem(i, 0, new QStandardItem(
			Global::g_projectInfo.camItemList.at(i).content));
		projectItemsModel->setItem(i, 1, new QStandardItem(QString::number(
			Global::g_projectInfo.camItemList.at(i).nCADHeight)));
		projectItemsModel->setItem(i, 2, new QStandardItem(QString::number(
			Global::g_projectInfo.camItemList.at(i).dStandardD)));
		projectItemsModel->setItem(i, 3, new QStandardItem(QString::number(
			Global::g_projectInfo.camItemList.at(i).dUpperD)));
		projectItemsModel->setItem(i, 4, new QStandardItem(QString::number(
			Global::g_projectInfo.camItemList.at(i).dLowerD)));
	}

	int bias = projectItemsModel->rowCount();
	for (int i = 0; i<Global::g_projectInfo.laserItemList.count(); ++i) {
		projectItemsModel->setItem(i + bias, 0, new QStandardItem(
			Global::g_projectInfo.laserItemList.at(i).content));
		projectItemsModel->setItem(i + bias, 1, new QStandardItem(QString::number(
			Global::g_projectInfo.laserItemList.at(i).nCADHeight)));
		projectItemsModel->setItem(i + bias, 2, new QStandardItem(QString::number(
			Global::g_projectInfo.laserItemList.at(i).dStandardD)));
		projectItemsModel->setItem(i + bias, 3, new QStandardItem(QString::number(
			Global::g_projectInfo.laserItemList.at(i).dUpperD)));
		projectItemsModel->setItem(i + bias, 4, new QStandardItem(QString::number(
			Global::g_projectInfo.laserItemList.at(i).dLowerD)));
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
	Global::g_lockConfig = false;
}

void CentralWidget::on_loadBtn_clicked()
{
	QString prj = QFileDialog::getOpenFileName(this, tr("载入项目文件"),
		PROJECT_DIRECTORY + Global::g_projectInfo.projectName + ".prj", tr("Project (*.prj)"));
	if (!prj.isEmpty()) {
		// Load
		QSettings prjFile(prj, QSettings::IniFormat);
		Global::g_projectInfo.projectName = prjFile.value("OVERRALL/ProjectName").toString();
		Global::g_projectInfo.cadFileName = prjFile.value("OVERRALL/CADFileName").toString();
		Global::g_projectInfo.partName = prjFile.value("OVERRALL/PartName").toString();
		Global::g_projectInfo.productModel = prjFile.value("OVERRALL/ProductModel").toString();
		Global::g_projectInfo.orderNumber = prjFile.value("OVERRALL/OrderNumber").toString();
		Global::g_projectInfo.manufactory = prjFile.value("OVERRALL/Manufactory").toString();
		Global::g_projectInfo.productionDate = prjFile.value("OVERRALL/ProductionDate").toString();
		Global::g_projectInfo.processName = prjFile.value("OVERRALL/ProcessName").toString();
		Global::g_projectInfo.station = prjFile.value("OVERRALL/Station").toString();
		int size = prjFile.beginReadArray("OVERRALL/CameraMeasurePath");
		Global::g_projectInfo.camMeasurePath.clear();
		for (int i = 0; i < size; ++i) {
			prjFile.setArrayIndex(i);
			Global::g_projectInfo.camMeasurePath.append(prjFile.value("idx").toInt());
		}
		prjFile.endArray();
		size = prjFile.beginReadArray("OVERRALL/CameraItemList");
		Global::g_projectInfo.camItemList.clear();
		for (int i = 0; i < size; ++i) {
			prjFile.setArrayIndex(i);
			CAMERAITEM item;
			int size2 = prjFile.beginReadArray("OVERRALL/CameraItemList/CADPosList");
			for (int j = 0; j < size2; ++j) {
				prjFile.setArrayIndex(j);
				item.cadPosList.append(prjFile.value("_p").toPointF());
			}
			prjFile.endArray();
			item.bPosListInverted = prjFile.value("invert").toBool();
			item.nType = prjFile.value("type").toInt();
			item.content = prjFile.value("content").toString();
			item.nCADHeight = prjFile.value("height").toInt();
			item.dStandardD = prjFile.value("standard").toDouble();
			item.dUpperD = prjFile.value("upper").toDouble();
			item.dLowerD = prjFile.value("lower").toDouble();
			Global::g_projectInfo.camItemList.append(item);
		}
		prjFile.endArray();
		size = prjFile.beginReadArray("OVERRALL/LaserItemList");
		Global::g_projectInfo.laserItemList.clear();
		for (int i = 0; i < size; ++i) {
			prjFile.setArrayIndex(i);
			LASERITEM item;
			int size2 = prjFile.beginReadArray("OVERRALL/LaserItemList/CADPosList");
			for (int j = 0; j < size2; ++j) {
				prjFile.setArrayIndex(j);
				item.cadPosList.append(prjFile.value("_p").toPointF());
			}
			prjFile.endArray();
			item.content = prjFile.value("content").toString();
			item.nCADHeight = prjFile.value("height").toInt();
			item.dStandardD = prjFile.value("standard").toDouble();
			item.dUpperD = prjFile.value("upper").toDouble();
			item.dLowerD = prjFile.value("lower").toDouble();
			Global::g_projectInfo.laserItemList.append(item);
		}
		prjFile.endArray();
		Global::g_projectInfo.startCADPos = prjFile.value("OVERRALL/StartCADPos").toPointF();
		Global::g_projectInfo.nSubGroupSize = prjFile.value("OVERRALL/SubGroupSize").toInt();

		emit ProjectLoad();
		UpdateNodeListTable();
		Global::g_lockConfig = true;
		Global::Sync();
		ui.startBtn->setText("开始（"+QString::number(Global::IndexGen(false))+")");
	}
}

void CentralWidget::on_saveBtn_clicked()
{
	QString prj = QFileDialog::getSaveFileName(this, tr("保存项目文件"),
		PROJECT_DIRECTORY + Global::g_projectInfo.projectName + "_" +
		QString::number(Global::g_projectInfo.nSubGroupSize) +
		".prj", tr("Project (*.prj)"));
	QSettings prjFile(prj, QSettings::IniFormat);
	if (!prj.isEmpty()) {
		if (Global::g_projectInfo.camMeasurePath.isEmpty()) {
			QMessageBox::warning(this, tr("提示"), tr("项目信息不完整！"));
		}
		else {
			// Save
			QSettings prjFile(prj, QSettings::IniFormat);
			prjFile.setValue("OVERRALL/ProjectName", Global::g_projectInfo.projectName);
			prjFile.setValue("OVERRALL/CADFileName", Global::g_projectInfo.cadFileName);
			prjFile.setValue("OVERRALL/PartName", Global::g_projectInfo.partName);
			prjFile.setValue("OVERRALL/ProductModel", Global::g_projectInfo.productModel);
			prjFile.setValue("OVERRALL/OrderNumber", Global::g_projectInfo.orderNumber);
			prjFile.setValue("OVERRALL/Manufactory", Global::g_projectInfo.manufactory);
			prjFile.setValue("OVERRALL/ProductionDate", Global::g_projectInfo.productionDate);
			prjFile.setValue("OVERRALL/ProcessName", Global::g_projectInfo.processName);
			prjFile.setValue("OVERRALL/Station", Global::g_projectInfo.station);
			prjFile.beginWriteArray("OVERRALL/CameraMeasurePath");
			for (int i = 0; i < Global::g_projectInfo.camMeasurePath.count(); ++i) {
				prjFile.setArrayIndex(i);
				prjFile.setValue("idx", Global::g_projectInfo.camMeasurePath.at(i));
			}
			prjFile.endArray();
			prjFile.beginWriteArray("OVERRALL/CameraItemList");
			for (int i = 0; i < Global::g_projectInfo.camItemList.count(); ++i) {
				prjFile.setArrayIndex(i);
				prjFile.beginWriteArray("OVERRALL/CameraItemList/CADPosList");
				for (int j = 0; j < Global::g_projectInfo.camItemList.at(i).cadPosList.count(); ++j) {
					prjFile.setArrayIndex(j);
					prjFile.setValue("_p", Global::g_projectInfo.camItemList.at(i).cadPosList.at(j));
				}
				prjFile.endArray();
				prjFile.setValue("invert", Global::g_projectInfo.camItemList.at(i).bPosListInverted);
				prjFile.setValue("type", Global::g_projectInfo.camItemList.at(i).nType);
				prjFile.setValue("content", Global::g_projectInfo.camItemList.at(i).content);
				prjFile.setValue("height", Global::g_projectInfo.camItemList.at(i).nCADHeight);
				prjFile.setValue("standard", Global::g_projectInfo.camItemList.at(i).dStandardD);
				prjFile.setValue("upper", Global::g_projectInfo.camItemList.at(i).dUpperD);
				prjFile.setValue("lower", Global::g_projectInfo.camItemList.at(i).dLowerD);
			}
			prjFile.endArray();
			prjFile.beginWriteArray("OVERRALL/LaserItemList");
			for (int i = 0; i < Global::g_projectInfo.laserItemList.count(); ++i) {
				prjFile.setArrayIndex(i);
				prjFile.beginWriteArray("OVERRALL/LaserItemList/CADPosList");
				for (int j = 0; j < Global::g_projectInfo.laserItemList.at(i).cadPosList.count(); ++j) {
					prjFile.setArrayIndex(j);
					prjFile.setValue("_p", Global::g_projectInfo.laserItemList.at(i).cadPosList.at(j));
				}
				prjFile.endArray();
				prjFile.setValue("content", Global::g_projectInfo.laserItemList.at(i).content);
				prjFile.setValue("height", Global::g_projectInfo.laserItemList.at(i).nCADHeight);
				prjFile.setValue("standard", Global::g_projectInfo.laserItemList.at(i).dStandardD);
				prjFile.setValue("upper", Global::g_projectInfo.laserItemList.at(i).dUpperD);
				prjFile.setValue("lower", Global::g_projectInfo.laserItemList.at(i).dLowerD);
			}
			prjFile.endArray();
			prjFile.setValue("OVERRALL/StartCADPos", Global::g_projectInfo.startCADPos);
			prjFile.setValue("OVERRALL/SubGroupSize", Global::g_projectInfo.nSubGroupSize);
		}
		Global::g_lockConfig = true;
	}
}

void CentralWidget::on_startBtn_clicked()
{
	Global::g_enableCamCtrl = false;
	executor->start();
}

void CentralWidget::ShowResult()
{
	Global::g_enableCamCtrl = true;
	Global::g_projectInfo.mesurementDate = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
	reporter->RefreshData();
	reporter->exec();
	ui.startBtn->setText("开始（" + QString::number(Global::IndexGen(true)) + ")");
}

void CentralWidget::ModifyData(QStandardItem* item)
{
	if (item->column() == 0) {
		int row = item->row();
		int count0 = Global::g_projectInfo.camItemList.count();

		if (row <= count0 - 1) { Global::g_projectInfo.camItemList[row].content = item->text(); }
		else { Global::g_projectInfo.laserItemList[row - count0].content = item->text(); }
	}

	if (item->column() == 1) {
		int row = item->row();
		int count0 = Global::g_projectInfo.camItemList.count();
		int newHeight = item->text().toInt();

		if (row <= count0 - 1) { Global::g_projectInfo.camItemList[row].nCADHeight = newHeight; }
		else { Global::g_projectInfo.laserItemList[row - count0].nCADHeight = newHeight; }
	}

	if (item->column() == 2) {
		int row = item->row();
		int count0 = Global::g_projectInfo.camItemList.count();
		double standard = item->text().toDouble();

		if (row <= count0 - 1) { Global::g_projectInfo.camItemList[row].dStandardD = standard; }
		else { Global::g_projectInfo.laserItemList[row - count0].dStandardD = standard; }
	}

	if (item->column() == 3) {
		int row = item->row();
		int count0 = Global::g_projectInfo.camItemList.count();
		double upper = item->text().toDouble();

		if (row <= count0 - 1) { Global::g_projectInfo.camItemList[row].dUpperD = upper; }
		else { Global::g_projectInfo.laserItemList[row - count0].dUpperD = upper; }
	}

	if (item->column() == 4) {
		int row = item->row();
		int count0 = Global::g_projectInfo.camItemList.count();
		double lower = item->text().toDouble();

		if (row <= count0 - 1) { Global::g_projectInfo.camItemList[row].dLowerD = lower; }
		else { Global::g_projectInfo.laserItemList[row - count0].dLowerD = lower; }
	}
}
