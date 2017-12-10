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
	connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(RealtimeCapture()));
	connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(StatusDisplay()));

	connect(ui.axis0MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	connect(ui.axis1MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	connect(ui.axis2MaxVel, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	connect(ui.axis0AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	connect(ui.axis1AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	connect(ui.axis2AccTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	connect(ui.axis0SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	connect(ui.axis1SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
	connect(ui.axis2SmoothTime, SIGNAL(valueChanged(double)), this, SLOT(SetProfile()));
}

void CameraCtrl::showEvent(QShowEvent *event)
{
	double minVel, maxVel, acc, dec, stopVel, smooth, sMode = 0;

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

#if REPLACE_HALCON_LIB
		if (!camera.isOpened()) { camera.open(0); }
#endif // REPLACE_HALCON_LIB

	m_updateTimer.start();

	QDialog::showEvent(event);
}

void CameraCtrl::closeEvent(QCloseEvent *event)
{
	m_updateTimer.stop();

#if REPLACE_HALCON_LIB
	camera.release();
#endif // REPLACE_HALCON_LIB

	on_stopBtn_clicked();
	QDialog::closeEvent(event);
}
/**
 * @brief 相机实时显示
 */
void CameraCtrl::RealtimeCapture()
{
#if REPLACE_HALCON_LIB
	if (!camera.isOpened()) {
		qDebug() << "Camera cannot open!";
		return;
	}

	Mat frame;
	camera >> frame;
	if (frame.empty()) {
		qDebug() << "No accessible video stream!";
		return;
	}

	cvtColor(frame, frame, CV_BGR2RGB);
	QPixmap pixmap;
	pixmap = QPixmap::fromImage(QImage((uchar*)frame.data, frame.cols, frame.rows, QImage::Format_RGB888));
	emit SendAFrame(pixmap);
#endif // REPLACE_HALCON_LIB
}
/**
 * @brief 状态显示
 */
void CameraCtrl::StatusDisplay()
{
	ui.axis0Pos->setText(QString::number(-dmc_get_encoder(0, 0)));
	ui.axis1Pos->setText(QString::number(dmc_get_encoder(0, 1)));
	ui.axis2Pos->setText(QString::number(dmc_get_encoder(0, 2)));

	ui.axis0Vel->setValue(dmc_read_current_speed(0, 0));
	ui.axis1Vel->setValue(dmc_read_current_speed(0, 1));
	ui.axis2Vel->setValue(dmc_read_current_speed(0, 2));
}
/**
 * @brief	设定参数
 */
void CameraCtrl::SetProfile()
{
	dmc_set_profile(0, 0, 0, ui.axis0MaxVel->value(), ui.axis0AccTime->value(), ui.axis0AccTime->value(), 0);
	dmc_set_profile(0, 1, 0, ui.axis1MaxVel->value(), ui.axis1AccTime->value(), ui.axis1AccTime->value(), 0);
	dmc_set_profile(0, 2, 0, ui.axis2MaxVel->value(), ui.axis2AccTime->value(), ui.axis2AccTime->value(), 0);
	dmc_set_s_profile(0, 0, 0, ui.axis0SmoothTime->value());
	dmc_set_s_profile(0, 1, 0, ui.axis1SmoothTime->value());
	dmc_set_s_profile(0, 2, 0, ui.axis2SmoothTime->value());
}
/**
 * @brief	相对位移
 */
void CameraCtrl::on_axisBiasBtn_clicked()
{
	dmc_pmove(0, 0, ui.axis0AbiasPos->value(), 0);
	dmc_pmove(0, 1, ui.axis1AbiasPos->value(), 0);
	dmc_pmove(0, 2, ui.axis2AbiasPos->value(), 0);
}
/**
 * @brief	后移
 */
void CameraCtrl::on_backwardMoveBtn_pressed()
{
	dmc_vmove(0, 1, 0);
}
/**
 * @brief	前移
 */
void CameraCtrl::on_forwardMoveBtn_pressed()
{
	dmc_vmove(0, 1, 1);
}
/**
 * @brief	左移
 */
void CameraCtrl::on_leftMoveBtn_pressed()
{
	dmc_vmove(0, 0, 0);
}
/**
 * @brief	右移
 */
void CameraCtrl::on_rightMoveBtn_pressed()
{
	dmc_vmove(0, 0, 1);
}
/**
 * @brief	计数清零
 */
void CameraCtrl::on_clearEncoderBtn_clicked()
{
	dmc_set_encoder(0, 0, 0);
	dmc_set_encoder(0, 1, 0);
	dmc_set_encoder(0, 2, 0);
	dmc_set_position(0, 0, 0);
	dmc_set_position(0, 1, 0);
	dmc_set_position(0, 2, 0);
}
/**
 * @brief	原点限位校准
 */
void CameraCtrl::on_homeCalibrationBtn_clicked()
{
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
/**
 * @brief	Z轴抬升
 */
void CameraCtrl::on_raiseBtn_clicked()
{
	dmc_vmove(0, 2, 1);
}
/**
 * @brief	Z轴下放
 */
void CameraCtrl::on_dropBtn_clicked()
{
	dmc_vmove(0, 2, 0);
}
/**
 * @brief	三轴停止
 */
void CameraCtrl::on_stopBtn_clicked()
{
	dmc_stop(0, 0, 1);
	dmc_stop(0, 1, 1);
	dmc_stop(0, 2, 1);
}

void CameraCtrl::on_brightnessSlider_sliderMoved(int value)
{
	qDebug() << "[Brightness]>" << value;
}

void CameraCtrl::on_contrastSlider_sliderMoved(int value)
{
	qDebug() << "[Contrast]>" << value;
}
