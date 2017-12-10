#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#pragma once

#include <QWidget>
#include <QStandardItemModel>
#include "ui_centralwidget.h"

#include "DxfPainter.h"
#include "ReportGenerator.h"
#include "MOTION_RELATIVE\CameraCtrl.h"
#include "MOTION_RELATIVE\MotionExecutor.h"
#include "VISION_RELATIVE\Vision.h"


class CentralWidget : public QWidget
{
	Q_OBJECT

public:
	CentralWidget(QWidget *parent = Q_NULLPTR);
	~CentralWidget();

private:
	Ui::CentralWidget ui;

	QStandardItemModel *projectItemsModel;
	CameraCtrl *cameraCtrlPanel;
	MotionExecutor *executor;
	ReportGenerator *reporter;
	Vision *visionModule;

signals:
	void ProjectNew(bool isCleanOpen);
	void ProjectLoad();
	void TitleUpdate();

	void LaserRequire2(int index);

private slots:
	void ShowPhoto(const QPixmap &p);
	void on_cameraCtrlBtn_clicked();

	void UpdateNodeListTable();

	void on_newBtn_clicked();
	void on_replanBtn_clicked();
	void on_loadBtn_clicked();
	void on_saveBtn_clicked();
	void on_stopBtn_clicked();
	void on_startBtn_clicked();

	void ShowResult();

	void ModifyData(QStandardItem* item);
};
