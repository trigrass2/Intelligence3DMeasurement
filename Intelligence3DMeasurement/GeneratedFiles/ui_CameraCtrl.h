/********************************************************************************
** Form generated from reading UI file 'CameraCtrl.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERACTRL_H
#define UI_CAMERACTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CameraCtrl
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_4;
    QPushButton *axisBiasBtn;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *axis0Pos;
    QSpinBox *axis0AbiasPos;
    QDoubleSpinBox *axis0MaxVel;
    QDoubleSpinBox *axis0AccTime;
    QDoubleSpinBox *axis0SmoothTime;
    QLabel *label_2;
    QLineEdit *axis1Pos;
    QSpinBox *axis1AbiasPos;
    QDoubleSpinBox *axis1AccTime;
    QDoubleSpinBox *axis1SmoothTime;
    QLabel *label_3;
    QLineEdit *axis2Pos;
    QSpinBox *axis2AbiasPos;
    QDoubleSpinBox *axis2AccTime;
    QDoubleSpinBox *axis2SmoothTime;
    QDoubleSpinBox *axis1MaxVel;
    QDoubleSpinBox *axis2MaxVel;
    QDoubleSpinBox *axis0Vel;
    QDoubleSpinBox *axis1Vel;
    QDoubleSpinBox *axis2Vel;
    QFrame *line;
    QGridLayout *gridLayout_2;
    QPushButton *rightMoveBtn;
    QPushButton *backwardMoveBtn;
    QPushButton *forwardMoveBtn;
    QPushButton *dropBtn;
    QPushButton *raiseBtn;
    QPushButton *clearEncoderBtn;
    QPushButton *stopBtn;
    QPushButton *leftMoveBtn;
    QPushButton *homeCalibrationBtn;
    QFrame *line_2;
    QGridLayout *gridLayout_3;
    QSlider *brightnessSlider;
    QLabel *label_9;
    QLabel *label_7;
    QSlider *contrastSlider;

    void setupUi(QDialog *CameraCtrl)
    {
        if (CameraCtrl->objectName().isEmpty())
            CameraCtrl->setObjectName(QStringLiteral("CameraCtrl"));
        CameraCtrl->resize(658, 330);
        CameraCtrl->setMinimumSize(QSize(658, 330));
        CameraCtrl->setMaximumSize(QSize(658, 330));
        gridLayout_4 = new QGridLayout(CameraCtrl);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(CameraCtrl);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        label_4 = new QLabel(CameraCtrl);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        axisBiasBtn = new QPushButton(CameraCtrl);
        axisBiasBtn->setObjectName(QStringLiteral("axisBiasBtn"));
        axisBiasBtn->setMinimumSize(QSize(90, 0));
        axisBiasBtn->setMaximumSize(QSize(90, 16777215));
        axisBiasBtn->setFocusPolicy(Qt::StrongFocus);
        axisBiasBtn->setIconSize(QSize(0, 0));
        axisBiasBtn->setCheckable(false);
        axisBiasBtn->setFlat(false);

        gridLayout->addWidget(axisBiasBtn, 0, 3, 1, 1);

        label_5 = new QLabel(CameraCtrl);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        label_10 = new QLabel(CameraCtrl);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 5, 1, 1);

        label_6 = new QLabel(CameraCtrl);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 6, 1, 1);

        label = new QLabel(CameraCtrl);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(25, 0));
        label->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        axis0Pos = new QLineEdit(CameraCtrl);
        axis0Pos->setObjectName(QStringLiteral("axis0Pos"));
        axis0Pos->setMinimumSize(QSize(0, 0));
        axis0Pos->setMaximumSize(QSize(999, 16777215));
        axis0Pos->setAlignment(Qt::AlignCenter);
        axis0Pos->setReadOnly(true);

        gridLayout->addWidget(axis0Pos, 1, 1, 1, 1);

        axis0AbiasPos = new QSpinBox(CameraCtrl);
        axis0AbiasPos->setObjectName(QStringLiteral("axis0AbiasPos"));
        axis0AbiasPos->setMinimumSize(QSize(90, 0));
        axis0AbiasPos->setMaximumSize(QSize(90, 16777215));
        axis0AbiasPos->setAlignment(Qt::AlignCenter);
        axis0AbiasPos->setAccelerated(true);
        axis0AbiasPos->setMinimum(-100000);
        axis0AbiasPos->setMaximum(100000);

        gridLayout->addWidget(axis0AbiasPos, 1, 3, 1, 1);

        axis0MaxVel = new QDoubleSpinBox(CameraCtrl);
        axis0MaxVel->setObjectName(QStringLiteral("axis0MaxVel"));
        axis0MaxVel->setMinimumSize(QSize(110, 0));
        axis0MaxVel->setMaximumSize(QSize(110, 16777215));
        axis0MaxVel->setAlignment(Qt::AlignCenter);
        axis0MaxVel->setAccelerated(true);
        axis0MaxVel->setSuffix(QStringLiteral("p/s"));
        axis0MaxVel->setDecimals(0);
        axis0MaxVel->setMinimum(500);
        axis0MaxVel->setMaximum(2e+6);
        axis0MaxVel->setSingleStep(500);
        axis0MaxVel->setValue(4000);

        gridLayout->addWidget(axis0MaxVel, 1, 4, 1, 1);

        axis0AccTime = new QDoubleSpinBox(CameraCtrl);
        axis0AccTime->setObjectName(QStringLiteral("axis0AccTime"));
        axis0AccTime->setMinimumSize(QSize(70, 0));
        axis0AccTime->setMaximumSize(QSize(70, 16777215));
        axis0AccTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        axis0AccTime->setAccelerated(true);
        axis0AccTime->setDecimals(3);
        axis0AccTime->setMinimum(0.001);
        axis0AccTime->setMaximum(1);
        axis0AccTime->setSingleStep(0.001);

        gridLayout->addWidget(axis0AccTime, 1, 5, 1, 1);

        axis0SmoothTime = new QDoubleSpinBox(CameraCtrl);
        axis0SmoothTime->setObjectName(QStringLiteral("axis0SmoothTime"));
        axis0SmoothTime->setMinimumSize(QSize(70, 0));
        axis0SmoothTime->setMaximumSize(QSize(70, 16777215));
        axis0SmoothTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        axis0SmoothTime->setReadOnly(false);
        axis0SmoothTime->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        axis0SmoothTime->setAccelerated(true);
        axis0SmoothTime->setDecimals(3);
        axis0SmoothTime->setMinimum(0.001);
        axis0SmoothTime->setMaximum(1);
        axis0SmoothTime->setSingleStep(0.001);
        axis0SmoothTime->setValue(0.001);

        gridLayout->addWidget(axis0SmoothTime, 1, 6, 1, 1);

        label_2 = new QLabel(CameraCtrl);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(25, 0));
        label_2->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        axis1Pos = new QLineEdit(CameraCtrl);
        axis1Pos->setObjectName(QStringLiteral("axis1Pos"));
        axis1Pos->setMinimumSize(QSize(0, 0));
        axis1Pos->setMaximumSize(QSize(999, 16777215));
        axis1Pos->setAlignment(Qt::AlignCenter);
        axis1Pos->setReadOnly(true);

        gridLayout->addWidget(axis1Pos, 2, 1, 1, 1);

        axis1AbiasPos = new QSpinBox(CameraCtrl);
        axis1AbiasPos->setObjectName(QStringLiteral("axis1AbiasPos"));
        axis1AbiasPos->setMinimumSize(QSize(90, 0));
        axis1AbiasPos->setMaximumSize(QSize(90, 16777215));
        axis1AbiasPos->setAlignment(Qt::AlignCenter);
        axis1AbiasPos->setAccelerated(true);
        axis1AbiasPos->setMinimum(-100000);
        axis1AbiasPos->setMaximum(100000);

        gridLayout->addWidget(axis1AbiasPos, 2, 3, 1, 1);

        axis1AccTime = new QDoubleSpinBox(CameraCtrl);
        axis1AccTime->setObjectName(QStringLiteral("axis1AccTime"));
        axis1AccTime->setMinimumSize(QSize(70, 0));
        axis1AccTime->setMaximumSize(QSize(70, 16777215));
        axis1AccTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        axis1AccTime->setAccelerated(true);
        axis1AccTime->setDecimals(3);
        axis1AccTime->setMinimum(0.001);
        axis1AccTime->setMaximum(1);
        axis1AccTime->setSingleStep(0.001);

        gridLayout->addWidget(axis1AccTime, 2, 5, 1, 1);

        axis1SmoothTime = new QDoubleSpinBox(CameraCtrl);
        axis1SmoothTime->setObjectName(QStringLiteral("axis1SmoothTime"));
        axis1SmoothTime->setMinimumSize(QSize(70, 0));
        axis1SmoothTime->setMaximumSize(QSize(70, 16777215));
        axis1SmoothTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        axis1SmoothTime->setAccelerated(true);
        axis1SmoothTime->setDecimals(3);
        axis1SmoothTime->setMinimum(0.001);
        axis1SmoothTime->setMaximum(1);
        axis1SmoothTime->setSingleStep(0.001);
        axis1SmoothTime->setValue(0.001);

        gridLayout->addWidget(axis1SmoothTime, 2, 6, 1, 1);

        label_3 = new QLabel(CameraCtrl);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(25, 0));
        label_3->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        axis2Pos = new QLineEdit(CameraCtrl);
        axis2Pos->setObjectName(QStringLiteral("axis2Pos"));
        axis2Pos->setMinimumSize(QSize(0, 0));
        axis2Pos->setMaximumSize(QSize(999, 16777215));
        axis2Pos->setAlignment(Qt::AlignCenter);
        axis2Pos->setReadOnly(true);

        gridLayout->addWidget(axis2Pos, 3, 1, 1, 1);

        axis2AbiasPos = new QSpinBox(CameraCtrl);
        axis2AbiasPos->setObjectName(QStringLiteral("axis2AbiasPos"));
        axis2AbiasPos->setMinimumSize(QSize(90, 0));
        axis2AbiasPos->setMaximumSize(QSize(90, 16777215));
        axis2AbiasPos->setAlignment(Qt::AlignCenter);
        axis2AbiasPos->setAccelerated(true);
        axis2AbiasPos->setMinimum(-100000);
        axis2AbiasPos->setMaximum(100000);

        gridLayout->addWidget(axis2AbiasPos, 3, 3, 1, 1);

        axis2AccTime = new QDoubleSpinBox(CameraCtrl);
        axis2AccTime->setObjectName(QStringLiteral("axis2AccTime"));
        axis2AccTime->setMinimumSize(QSize(70, 0));
        axis2AccTime->setMaximumSize(QSize(70, 16777215));
        axis2AccTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        axis2AccTime->setAccelerated(true);
        axis2AccTime->setDecimals(3);
        axis2AccTime->setMinimum(0.001);
        axis2AccTime->setMaximum(1);
        axis2AccTime->setSingleStep(0.001);

        gridLayout->addWidget(axis2AccTime, 3, 5, 1, 1);

        axis2SmoothTime = new QDoubleSpinBox(CameraCtrl);
        axis2SmoothTime->setObjectName(QStringLiteral("axis2SmoothTime"));
        axis2SmoothTime->setMinimumSize(QSize(70, 0));
        axis2SmoothTime->setMaximumSize(QSize(70, 16777215));
        axis2SmoothTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        axis2SmoothTime->setAccelerated(true);
        axis2SmoothTime->setDecimals(3);
        axis2SmoothTime->setMinimum(0.001);
        axis2SmoothTime->setMaximum(1);
        axis2SmoothTime->setSingleStep(0.001);
        axis2SmoothTime->setValue(0.001);

        gridLayout->addWidget(axis2SmoothTime, 3, 6, 1, 1);

        axis1MaxVel = new QDoubleSpinBox(CameraCtrl);
        axis1MaxVel->setObjectName(QStringLiteral("axis1MaxVel"));
        axis1MaxVel->setMinimumSize(QSize(110, 0));
        axis1MaxVel->setMaximumSize(QSize(110, 16777215));
        axis1MaxVel->setAlignment(Qt::AlignCenter);
        axis1MaxVel->setAccelerated(true);
        axis1MaxVel->setSuffix(QStringLiteral("p/s"));
        axis1MaxVel->setDecimals(0);
        axis1MaxVel->setMinimum(500);
        axis1MaxVel->setMaximum(2e+6);
        axis1MaxVel->setSingleStep(500);
        axis1MaxVel->setValue(4000);

        gridLayout->addWidget(axis1MaxVel, 2, 4, 1, 1);

        axis2MaxVel = new QDoubleSpinBox(CameraCtrl);
        axis2MaxVel->setObjectName(QStringLiteral("axis2MaxVel"));
        axis2MaxVel->setMinimumSize(QSize(110, 0));
        axis2MaxVel->setMaximumSize(QSize(110, 16777215));
        axis2MaxVel->setAlignment(Qt::AlignCenter);
        axis2MaxVel->setAccelerated(true);
        axis2MaxVel->setSuffix(QStringLiteral("p/s"));
        axis2MaxVel->setDecimals(0);
        axis2MaxVel->setMinimum(500);
        axis2MaxVel->setMaximum(2e+6);
        axis2MaxVel->setSingleStep(500);
        axis2MaxVel->setValue(4000);

        gridLayout->addWidget(axis2MaxVel, 3, 4, 1, 1);

        axis0Vel = new QDoubleSpinBox(CameraCtrl);
        axis0Vel->setObjectName(QStringLiteral("axis0Vel"));
        axis0Vel->setMinimumSize(QSize(110, 0));
        axis0Vel->setMaximumSize(QSize(999, 16777215));
        axis0Vel->setAlignment(Qt::AlignCenter);
        axis0Vel->setReadOnly(true);
        axis0Vel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        axis0Vel->setDecimals(0);
        axis0Vel->setMaximum(2e+6);

        gridLayout->addWidget(axis0Vel, 1, 2, 1, 1);

        axis1Vel = new QDoubleSpinBox(CameraCtrl);
        axis1Vel->setObjectName(QStringLiteral("axis1Vel"));
        axis1Vel->setMinimumSize(QSize(110, 0));
        axis1Vel->setMaximumSize(QSize(999, 16777215));
        axis1Vel->setAlignment(Qt::AlignCenter);
        axis1Vel->setReadOnly(true);
        axis1Vel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        axis1Vel->setDecimals(0);
        axis1Vel->setMaximum(2e+6);

        gridLayout->addWidget(axis1Vel, 2, 2, 1, 1);

        axis2Vel = new QDoubleSpinBox(CameraCtrl);
        axis2Vel->setObjectName(QStringLiteral("axis2Vel"));
        axis2Vel->setMinimumSize(QSize(110, 0));
        axis2Vel->setMaximumSize(QSize(999, 16777215));
        axis2Vel->setAlignment(Qt::AlignCenter);
        axis2Vel->setReadOnly(true);
        axis2Vel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        axis2Vel->setDecimals(0);
        axis2Vel->setMaximum(2e+6);

        gridLayout->addWidget(axis2Vel, 3, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 3);

        line = new QFrame(CameraCtrl);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(0, 5));
        line->setMaximumSize(QSize(16777215, 5));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::HLine);

        gridLayout_4->addWidget(line, 1, 0, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        rightMoveBtn = new QPushButton(CameraCtrl);
        rightMoveBtn->setObjectName(QStringLiteral("rightMoveBtn"));
        rightMoveBtn->setMinimumSize(QSize(51, 51));
        rightMoveBtn->setMaximumSize(QSize(51, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ICON/ARROW_RIGHT"), QSize(), QIcon::Normal, QIcon::Off);
        rightMoveBtn->setIcon(icon);
        rightMoveBtn->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(rightMoveBtn, 1, 3, 1, 1);

        backwardMoveBtn = new QPushButton(CameraCtrl);
        backwardMoveBtn->setObjectName(QStringLiteral("backwardMoveBtn"));
        backwardMoveBtn->setMinimumSize(QSize(51, 51));
        backwardMoveBtn->setMaximumSize(QSize(51, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ICON/ARROW_UP"), QSize(), QIcon::Normal, QIcon::Off);
        backwardMoveBtn->setIcon(icon1);
        backwardMoveBtn->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(backwardMoveBtn, 0, 2, 1, 1);

        forwardMoveBtn = new QPushButton(CameraCtrl);
        forwardMoveBtn->setObjectName(QStringLiteral("forwardMoveBtn"));
        forwardMoveBtn->setMinimumSize(QSize(51, 51));
        forwardMoveBtn->setMaximumSize(QSize(51, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ICON/ARROW_DOWN"), QSize(), QIcon::Normal, QIcon::Off);
        forwardMoveBtn->setIcon(icon2);
        forwardMoveBtn->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(forwardMoveBtn, 2, 2, 1, 1);

        dropBtn = new QPushButton(CameraCtrl);
        dropBtn->setObjectName(QStringLiteral("dropBtn"));
        dropBtn->setMinimumSize(QSize(51, 51));
        dropBtn->setMaximumSize(QSize(51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ICON/DROP"), QSize(), QIcon::Normal, QIcon::Off);
        dropBtn->setIcon(icon3);
        dropBtn->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(dropBtn, 2, 3, 1, 1);

        raiseBtn = new QPushButton(CameraCtrl);
        raiseBtn->setObjectName(QStringLiteral("raiseBtn"));
        raiseBtn->setMinimumSize(QSize(51, 51));
        raiseBtn->setMaximumSize(QSize(51, 51));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/ICON/RAISE"), QSize(), QIcon::Normal, QIcon::Off);
        raiseBtn->setIcon(icon4);
        raiseBtn->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(raiseBtn, 0, 3, 1, 1);

        clearEncoderBtn = new QPushButton(CameraCtrl);
        clearEncoderBtn->setObjectName(QStringLiteral("clearEncoderBtn"));
        clearEncoderBtn->setMinimumSize(QSize(51, 51));
        clearEncoderBtn->setMaximumSize(QSize(51, 51));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/ICON/CIRCLE_CLEAR"), QSize(), QIcon::Normal, QIcon::Off);
        clearEncoderBtn->setIcon(icon5);
        clearEncoderBtn->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(clearEncoderBtn, 2, 1, 1, 1);

        stopBtn = new QPushButton(CameraCtrl);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setMinimumSize(QSize(51, 51));
        stopBtn->setMaximumSize(QSize(51, 51));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/ICON/STOP"), QSize(), QIcon::Normal, QIcon::Off);
        stopBtn->setIcon(icon6);
        stopBtn->setIconSize(QSize(45, 45));

        gridLayout_2->addWidget(stopBtn, 1, 2, 1, 1);

        leftMoveBtn = new QPushButton(CameraCtrl);
        leftMoveBtn->setObjectName(QStringLiteral("leftMoveBtn"));
        leftMoveBtn->setMinimumSize(QSize(51, 51));
        leftMoveBtn->setMaximumSize(QSize(51, 51));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/ICON/ARROW_LEFT"), QSize(), QIcon::Normal, QIcon::Off);
        leftMoveBtn->setIcon(icon7);
        leftMoveBtn->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(leftMoveBtn, 1, 1, 1, 1);

        homeCalibrationBtn = new QPushButton(CameraCtrl);
        homeCalibrationBtn->setObjectName(QStringLiteral("homeCalibrationBtn"));
        homeCalibrationBtn->setMinimumSize(QSize(51, 51));
        homeCalibrationBtn->setMaximumSize(QSize(51, 51));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/ICON/HOME_RETURN"), QSize(), QIcon::Normal, QIcon::Off);
        homeCalibrationBtn->setIcon(icon8);
        homeCalibrationBtn->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(homeCalibrationBtn, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 2, 0, 1, 1);

        line_2 = new QFrame(CameraCtrl);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMinimumSize(QSize(5, 0));
        line_2->setMaximumSize(QSize(5, 16777215));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 2, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        brightnessSlider = new QSlider(CameraCtrl);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setMinimum(0);
        brightnessSlider->setMaximum(100);
        brightnessSlider->setValue(50);
        brightnessSlider->setOrientation(Qt::Horizontal);
        brightnessSlider->setTickPosition(QSlider::TicksAbove);
        brightnessSlider->setTickInterval(5);

        gridLayout_3->addWidget(brightnessSlider, 1, 1, 1, 1);

        label_9 = new QLabel(CameraCtrl);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        label_7 = new QLabel(CameraCtrl);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        contrastSlider = new QSlider(CameraCtrl);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setMinimum(0);
        contrastSlider->setMaximum(100);
        contrastSlider->setValue(50);
        contrastSlider->setOrientation(Qt::Horizontal);
        contrastSlider->setInvertedAppearance(false);
        contrastSlider->setInvertedControls(false);
        contrastSlider->setTickPosition(QSlider::TicksAbove);
        contrastSlider->setTickInterval(5);

        gridLayout_3->addWidget(contrastSlider, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 2, 2, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_9->setBuddy(brightnessSlider);
        label_7->setBuddy(contrastSlider);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(stopBtn, forwardMoveBtn);
        QWidget::setTabOrder(forwardMoveBtn, backwardMoveBtn);
        QWidget::setTabOrder(backwardMoveBtn, rightMoveBtn);
        QWidget::setTabOrder(rightMoveBtn, leftMoveBtn);
        QWidget::setTabOrder(leftMoveBtn, raiseBtn);
        QWidget::setTabOrder(raiseBtn, dropBtn);
        QWidget::setTabOrder(dropBtn, clearEncoderBtn);
        QWidget::setTabOrder(clearEncoderBtn, homeCalibrationBtn);
        QWidget::setTabOrder(homeCalibrationBtn, axis0MaxVel);
        QWidget::setTabOrder(axis0MaxVel, axis0AccTime);
        QWidget::setTabOrder(axis0AccTime, axis0SmoothTime);
        QWidget::setTabOrder(axis0SmoothTime, axis1MaxVel);
        QWidget::setTabOrder(axis1MaxVel, axis1AccTime);
        QWidget::setTabOrder(axis1AccTime, axis1SmoothTime);
        QWidget::setTabOrder(axis1SmoothTime, axis2MaxVel);
        QWidget::setTabOrder(axis2MaxVel, axis2AccTime);
        QWidget::setTabOrder(axis2AccTime, axis2SmoothTime);
        QWidget::setTabOrder(axis2SmoothTime, axis0AbiasPos);
        QWidget::setTabOrder(axis0AbiasPos, axis1AbiasPos);
        QWidget::setTabOrder(axis1AbiasPos, axis2AbiasPos);
        QWidget::setTabOrder(axis2AbiasPos, axisBiasBtn);
        QWidget::setTabOrder(axisBiasBtn, contrastSlider);
        QWidget::setTabOrder(contrastSlider, brightnessSlider);
        QWidget::setTabOrder(brightnessSlider, axis0Pos);
        QWidget::setTabOrder(axis0Pos, axis1Pos);
        QWidget::setTabOrder(axis1Pos, axis2Pos);
        QWidget::setTabOrder(axis2Pos, axis0Vel);
        QWidget::setTabOrder(axis0Vel, axis1Vel);
        QWidget::setTabOrder(axis1Vel, axis2Vel);

        retranslateUi(CameraCtrl);

        QMetaObject::connectSlotsByName(CameraCtrl);
    } // setupUi

    void retranslateUi(QDialog *CameraCtrl)
    {
        CameraCtrl->setWindowTitle(QApplication::translate("CameraCtrl", "\347\233\270\346\234\272\346\216\247\345\210\266\351\235\242\346\235\277", Q_NULLPTR));
        label_8->setText(QApplication::translate("CameraCtrl", "\345\275\223\345\211\215\344\275\215\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("CameraCtrl", "\345\275\223\345\211\215\351\200\237\345\272\246", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        axisBiasBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\350\277\233\350\241\214<span style=\" font-weight:600;\">\347\233\270\345\257\271</span>\344\275\215\347\247\273</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        axisBiasBtn->setText(QApplication::translate("CameraCtrl", "\345\201\217\347\247\273\344\275\215\347\275\256", Q_NULLPTR));
        label_5->setText(QApplication::translate("CameraCtrl", "\347\233\256\346\240\207\351\200\237\345\272\246", Q_NULLPTR));
        label_10->setText(QApplication::translate("CameraCtrl", "\345\212\240\351\200\237\346\227\266\351\227\264", Q_NULLPTR));
        label_6->setText(QApplication::translate("CameraCtrl", "\345\271\263\346\273\221\346\227\266\351\227\264", Q_NULLPTR));
        label->setText(QApplication::translate("CameraCtrl", "0\350\275\264", Q_NULLPTR));
        axis0AccTime->setPrefix(QString());
        axis0AccTime->setSuffix(QApplication::translate("CameraCtrl", "s", Q_NULLPTR));
        axis0SmoothTime->setPrefix(QString());
        axis0SmoothTime->setSuffix(QApplication::translate("CameraCtrl", "s", Q_NULLPTR));
        label_2->setText(QApplication::translate("CameraCtrl", "1\350\275\264", Q_NULLPTR));
        axis1AccTime->setSuffix(QApplication::translate("CameraCtrl", "s", Q_NULLPTR));
        axis1SmoothTime->setSuffix(QApplication::translate("CameraCtrl", "s", Q_NULLPTR));
        label_3->setText(QApplication::translate("CameraCtrl", "2\350\275\264", Q_NULLPTR));
        axis2AccTime->setSuffix(QApplication::translate("CameraCtrl", "s", Q_NULLPTR));
        axis2SmoothTime->setSuffix(QApplication::translate("CameraCtrl", "s", Q_NULLPTR));
        axis0Vel->setSuffix(QApplication::translate("CameraCtrl", "p/s", Q_NULLPTR));
        axis1Vel->setSuffix(QApplication::translate("CameraCtrl", "p/s", Q_NULLPTR));
        axis2Vel->setSuffix(QApplication::translate("CameraCtrl", "p/s", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rightMoveBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\345\220\221\345\217\263\347\247\273\345\212\250</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        backwardMoveBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\345\220\216\351\200\200</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        forwardMoveBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\345\211\215\350\277\233</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        dropBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\346\224\276\344\270\213\347\233\270\346\234\272</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        dropBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        raiseBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\346\217\220\345\215\207\347\233\270\346\234\272</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        raiseBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        clearEncoderBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\350\256\241\346\225\260\346\270\205\351\233\266</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        stopBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\345\201\234\346\255\242</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        stopBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        leftMoveBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\345\220\221\345\267\246\347\247\273\345\212\250</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        homeCalibrationBtn->setToolTip(QApplication::translate("CameraCtrl", "<html><head/><body><p>\345\233\236\351\231\220\344\275\215\345\216\237\347\202\271</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        homeCalibrationBtn->setText(QString());
        label_9->setText(QApplication::translate("CameraCtrl", "\344\272\256\345\272\246\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("CameraCtrl", "\345\257\271\346\257\224\345\272\246\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CameraCtrl: public Ui_CameraCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACTRL_H
