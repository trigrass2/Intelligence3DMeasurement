#pragma once

#include <QDialog>
#include <QTimer>
#include "ui_CameraCtrl.h"

#include "Global.h"


class CameraCtrl : public QDialog
{
	Q_OBJECT

public:
	CameraCtrl(QWidget *parent = Q_NULLPTR);

protected:
	void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
	Ui::CameraCtrl ui;

	int m_updateInternal;		///< msec
	QTimer m_updateTimer;

signals:
	void ShowAFrame();

private slots:
	void StatusDisplay();
	void SetProfile();

	void on_axisBiasBtn_clicked();

	void on_backwardMoveBtn_pressed();
	void on_forwardMoveBtn_pressed();
	void on_leftMoveBtn_pressed();
	void on_rightMoveBtn_pressed();

	void on_raiseBtn_clicked();
	void on_dropBtn_clicked();

	void on_clearEncoderBtn_clicked();
	void on_homeCalibrationBtn_clicked();

	void on_brightnessSlider_sliderMoved(int value);
	void on_contrastSlider_sliderMoved(int value);

public slots:
	void on_stopBtn_clicked();
};
