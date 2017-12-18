#include <QMessageBox>
#include <QDebug>
#include "CameraCtrl.h"

#include "LTDMC.h"


CameraCtrl::CameraCtrl(QWidget *parent)
	: QDialog(parent), m_updateInternal(100)
{
	ui.setupUi(this);

	m_updateTimer.setInterval(m_updateInternal);
	m_updateTimer.setSingleShot(false);
	connect(&m_updateTimer, SIGNAL(timeout()), this, SIGNAL(ShowAFrame()));
	connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(StatusDisplay()));
}

void CameraCtrl::showEvent(QShowEvent *event)
{
	double minVel, maxVel, acc, dec, stopVel, smooth, sMode = 0;
	if (ENABLE_MOTION_MODULE) {
		dmc_get_profile(0, 0, &minVel, &maxVel, &acc, &dec, &stopVel);
		dmc_get_s_profile(0, 0, sMode, &smooth);
		ui.axis0MaxVel->setValue(maxVel);
		ui.axis0AccTime->setValue(acc);
		ui.axis0SmoothTime->setValue(smooth);

		dmc_get_profile(0, 1, &minVel, &maxVel, &acc, &dec, &stopVel);
		dmc_get_s_profile(0, 1, sMode, &smooth);
		ui.axis1MaxVel->setValue(maxVel);
		ui.axis1AccTime->setValue(acc);
		ui.axis1SmoothTime->setValue(smooth);

		dmc_get_profile(0, 2, &minVel, &maxVel, &acc, &dec, &stopVel);
		dmc_get_s_profile(0, 2, sMode, &smooth);
		ui.axis2MaxVel->setValue(maxVel);
		ui.axis2AccTime->setValue(acc);
		ui.axis2SmoothTime->setValue(smooth);

		SetProfile();
		connect(ui.axis0MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
		connect(ui.axis1MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
		connect(ui.axis2MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
		connect(ui.axis0AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
		connect(ui.axis1AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
		connect(ui.axis2AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
		connect(ui.axis0SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
		connect(ui.axis1SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
		connect(ui.axis2SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));

		m_updateTimer.start();
	}

	QDialog::showEvent(event);
}

void CameraCtrl::closeEvent(QCloseEvent *event)
{
	m_updateTimer.stop();
	on_stopBtn_clicked();

	disconnect(ui.axis0MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	disconnect(ui.axis1MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	disconnect(ui.axis2MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	disconnect(ui.axis0AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	disconnect(ui.axis1AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	disconnect(ui.axis2AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	disconnect(ui.axis0SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	disconnect(ui.axis1SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	disconnect(ui.axis2SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	QDialog::closeEvent(event);
}

void CameraCtrl::StatusDisplay()
{
	if (ENABLE_MOTION_MODULE) {
		ui.axis0Pos->setText(QString::number(-dmc_get_encoder(0, 0)));
		ui.axis1Pos->setText(QString::number(dmc_get_encoder(0, 1)));
		ui.axis2Pos->setText(QString::number(dmc_get_encoder(0, 2)));

		ui.axis0Vel->setValue(dmc_read_current_speed(0, 0));
		ui.axis1Vel->setValue(dmc_read_current_speed(0, 1));
		ui.axis2Vel->setValue(dmc_read_current_speed(0, 2));
	}
}

void CameraCtrl::SetProfile()
{
	dmc_set_profile(0, 0, 0, ui.axis0MaxVel->value(), ui.axis0AccTime->value(), ui.axis0AccTime->value(), 0);
	dmc_set_profile(0, 1, 0, ui.axis1MaxVel->value(), ui.axis1AccTime->value(), ui.axis1AccTime->value(), 0);
	dmc_set_profile(0, 2, 0, ui.axis2MaxVel->value(), ui.axis2AccTime->value(), ui.axis2AccTime->value(), 0);
	dmc_set_s_profile(0, 0, 0, ui.axis0SmoothTime->value());
	dmc_set_s_profile(0, 1, 0, ui.axis1SmoothTime->value());
	dmc_set_s_profile(0, 2, 0, ui.axis2SmoothTime->value());
}

void CameraCtrl::on_axisBiasBtn_clicked()
{
	if (ENABLE_MOTION_MODULE) {
		dmc_pmove(0, 0, ui.axis0AbiasPos->value(), 0);
		dmc_pmove(0, 1, ui.axis1AbiasPos->value(), 0);
		dmc_pmove(0, 2, ui.axis2AbiasPos->value(), 0);
	}
}

void CameraCtrl::on_backwardMoveBtn_pressed()
{
	if (ENABLE_MOTION_MODULE) { dmc_vmove(0, 1, 0); }
}

void CameraCtrl::on_forwardMoveBtn_pressed()
{
	if (ENABLE_MOTION_MODULE) { dmc_vmove(0, 1, 1); }
}

void CameraCtrl::on_leftMoveBtn_pressed()
{
	if (ENABLE_MOTION_MODULE) { dmc_vmove(0, 0, 0); }
}

void CameraCtrl::on_rightMoveBtn_pressed()
{
	if (ENABLE_MOTION_MODULE) { dmc_vmove(0, 0, 1); }
}

void CameraCtrl::on_clearEncoderBtn_clicked()
{
	if (ENABLE_MOTION_MODULE) {
		dmc_set_encoder(0, 0, 0);
		dmc_set_encoder(0, 1, 0);
		dmc_set_encoder(0, 2, 0);
		dmc_set_position(0, 0, 0);
		dmc_set_position(0, 1, 0);
		dmc_set_position(0, 2, 0);
	}
}

void CameraCtrl::on_homeCalibrationBtn_clicked()
{
	if (ENABLE_MOTION_MODULE) {
		dmc_home_move(0, 0);
		dmc_home_move(0, 1);
		dmc_home_move(0, 2);

		while (dmc_check_done(0, 0) == 0) { qApp->processEvents(); }
		dmc_set_encoder(0, 0, 0);
		while (dmc_check_done(0, 1) == 0) { qApp->processEvents(); }
		dmc_set_encoder(0, 1, 0);
		while (dmc_check_done(0, 2) == 0) { qApp->processEvents(); }
		dmc_set_encoder(0, 2, 0);
	}
}

void CameraCtrl::on_raiseBtn_clicked()
{
	if (ENABLE_MOTION_MODULE) { dmc_vmove(0, 2, 1); }
}

void CameraCtrl::on_dropBtn_clicked()
{
	if (ENABLE_MOTION_MODULE) { dmc_vmove(0, 2, 0); }
}

void CameraCtrl::on_stopBtn_clicked()
{
	if (ENABLE_MOTION_MODULE) {
		dmc_stop(0, 0, 1);
		dmc_stop(0, 1, 1);
		dmc_stop(0, 2, 1);
	}
}

void CameraCtrl::on_brightnessSlider_sliderMoved(int value)
{
	if (ENABLE_VISION_MODULE) {
		qDebug() << "[Brightness]>" << value;
	}
}

void CameraCtrl::on_contrastSlider_sliderMoved(int value)
{
	if (ENABLE_VISION_MODULE) {
		qDebug() << "[Contrast]>" << value;
	}
}
