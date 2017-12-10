/********************************************************************************
** Form generated from reading UI file 'MotionCtrlCfgDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTIONCTRLCFGDLG_H
#define UI_MOTIONCTRLCFGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotionCtrlCfgDlg
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *axisChsBox;
    QPushButton *wrtCurrentBtn;
    QPushButton *wrtAllBtn;
    QPushButton *readFileBtn;
    QPushButton *readCardBtn;
    QPushButton *resetBtn;
    QTabWidget *tabWidget;
    QWidget *tabIOMap;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *pelTypeBox;
    QComboBox *pelNoBox;
    QDoubleSpinBox *pelFilterSpin;
    QLabel *label_5;
    QComboBox *nelTypeBox;
    QComboBox *nelNoBox;
    QDoubleSpinBox *nelFilterSpin;
    QLabel *label_6;
    QComboBox *orgTypeBox;
    QComboBox *orgNoBox;
    QDoubleSpinBox *orgFilterSpin;
    QLabel *label_7;
    QComboBox *emgTypeBox;
    QComboBox *emgNoBox;
    QDoubleSpinBox *emgFilterSpin;
    QLabel *label_8;
    QComboBox *dstpTypeBox;
    QComboBox *dstpNoBox;
    QDoubleSpinBox *dstpFilterSpin;
    QLabel *label_9;
    QComboBox *almTypeBox;
    QComboBox *almNoBox;
    QDoubleSpinBox *almFilterSpin;
    QLabel *label_10;
    QComboBox *inpTypeBox;
    QComboBox *inpNoBox;
    QDoubleSpinBox *inpFilterSpin;
    QSpacerItem *verticalSpacer;
    QWidget *tabPulseMode;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *pulseMode0RBtn;
    QRadioButton *pulseMode1RBtn;
    QRadioButton *pulseMode2RBtn;
    QRadioButton *pulseMode3RBtn;
    QRadioButton *pulseMode4RBtn;
    QRadioButton *pulseMode5RBtn;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pulsePicLabel;
    QWidget *tabEncoder;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_15;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_28;
    QDoubleSpinBox *xEquivalency;
    QLabel *label_29;
    QDoubleSpinBox *yEquivalency;
    QLabel *label_30;
    QDoubleSpinBox *zEquivalency;
    QGroupBox *groupBox_16;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_31;
    QDoubleSpinBox *xyLineVectorVel;
    QLabel *label_32;
    QDoubleSpinBox *zVel;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *notABRBtn;
    QRadioButton *singleABRBtn;
    QRadioButton *doubleABRBtn;
    QRadioButton *quadrupleABRBtn;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *ezLowLvLRBtn;
    QRadioButton *ezHighLvLRBtn;
    QSpacerItem *verticalSpacer_6;
    QWidget *tabHomeReturn;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *hrSlowRBtn;
    QRadioButton *hrFastRBtn;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *hrNDirectionRBtn;
    QRadioButton *hrPDirectionRBtn;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *hrLowLvLRBtn;
    QRadioButton *hrHighLvLRBtn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QRadioButton *hrOnceRBtn;
    QRadioButton *hrOnceAndBackwardRBtn;
    QRadioButton *hrTwiceRBtn;
    QRadioButton *hrHomeAndForwardEZRBtn;
    QRadioButton *hrOnceEZRBtn;
    QRadioButton *hrHomeAndBackwardEZRBtn;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_9;
    QWidget *tabLimit;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_7;
    QLabel *label_11;
    QComboBox *hdwLimitEnableBox;
    QLabel *label_12;
    QComboBox *hdwLimitLvLBox;
    QLabel *label_13;
    QComboBox *hdwLimitModeBox;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_11;
    QLabel *label_21;
    QComboBox *ioDstpEnableBox;
    QLabel *label_22;
    QComboBox *ioDstpLvLBox;
    QLabel *label_23;
    QDoubleSpinBox *ioDstpTimeSpin;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_9;
    QLabel *label_14;
    QComboBox *sfwLimitEnableBox;
    QLabel *label_15;
    QComboBox *sfwLimitModeBox;
    QLabel *label_16;
    QComboBox *sfwLimitCounterBox;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_8;
    QLabel *label_17;
    QSpinBox *sfwLimitPPSpin;
    QLabel *label_18;
    QSpinBox *sfwLimitNPSpin;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_10;
    QLabel *label_19;
    QComboBox *emgEnableBox;
    QLabel *label_20;
    QComboBox *emgLvLBox;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_13;
    QLabel *label_24;
    QComboBox *almEnableBox;
    QLabel *label_25;
    QComboBox *almLvLBox;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_14;
    QLabel *label_26;
    QComboBox *inpEnableBox;
    QLabel *label_27;
    QComboBox *inpLvLBox;

    void setupUi(QDialog *MotionCtrlCfgDlg)
    {
        if (MotionCtrlCfgDlg->objectName().isEmpty())
            MotionCtrlCfgDlg->setObjectName(QStringLiteral("MotionCtrlCfgDlg"));
        MotionCtrlCfgDlg->resize(658, 553);
        MotionCtrlCfgDlg->setMinimumSize(QSize(658, 553));
        MotionCtrlCfgDlg->setMaximumSize(QSize(658, 553));
        gridLayout_2 = new QGridLayout(MotionCtrlCfgDlg);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        axisChsBox = new QComboBox(MotionCtrlCfgDlg);
        axisChsBox->setObjectName(QStringLiteral("axisChsBox"));
        axisChsBox->setMinimumSize(QSize(100, 25));
        axisChsBox->setMaximumSize(QSize(100, 25));

        horizontalLayout->addWidget(axisChsBox);

        wrtCurrentBtn = new QPushButton(MotionCtrlCfgDlg);
        wrtCurrentBtn->setObjectName(QStringLiteral("wrtCurrentBtn"));
        wrtCurrentBtn->setEnabled(false);

        horizontalLayout->addWidget(wrtCurrentBtn);

        wrtAllBtn = new QPushButton(MotionCtrlCfgDlg);
        wrtAllBtn->setObjectName(QStringLiteral("wrtAllBtn"));
        wrtAllBtn->setEnabled(true);

        horizontalLayout->addWidget(wrtAllBtn);

        readFileBtn = new QPushButton(MotionCtrlCfgDlg);
        readFileBtn->setObjectName(QStringLiteral("readFileBtn"));
        readFileBtn->setEnabled(false);

        horizontalLayout->addWidget(readFileBtn);

        readCardBtn = new QPushButton(MotionCtrlCfgDlg);
        readCardBtn->setObjectName(QStringLiteral("readCardBtn"));
        readCardBtn->setEnabled(false);

        horizontalLayout->addWidget(readCardBtn);

        resetBtn = new QPushButton(MotionCtrlCfgDlg);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));
        resetBtn->setEnabled(true);

        horizontalLayout->addWidget(resetBtn);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(MotionCtrlCfgDlg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setDocumentMode(true);
        tabIOMap = new QWidget();
        tabIOMap->setObjectName(QStringLiteral("tabIOMap"));
        verticalLayout = new QVBoxLayout(tabIOMap);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(-1, 20, 25, 12);
        label = new QLabel(tabIOMap);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(tabIOMap);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(tabIOMap);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(tabIOMap);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        pelTypeBox = new QComboBox(tabIOMap);
        pelTypeBox->setObjectName(QStringLiteral("pelTypeBox"));
        pelTypeBox->setEnabled(false);

        gridLayout->addWidget(pelTypeBox, 1, 1, 1, 1);

        pelNoBox = new QComboBox(tabIOMap);
        pelNoBox->setObjectName(QStringLiteral("pelNoBox"));
        pelNoBox->setEnabled(false);

        gridLayout->addWidget(pelNoBox, 1, 2, 1, 1);

        pelFilterSpin = new QDoubleSpinBox(tabIOMap);
        pelFilterSpin->setObjectName(QStringLiteral("pelFilterSpin"));
        pelFilterSpin->setEnabled(false);

        gridLayout->addWidget(pelFilterSpin, 1, 3, 1, 1);

        label_5 = new QLabel(tabIOMap);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        nelTypeBox = new QComboBox(tabIOMap);
        nelTypeBox->setObjectName(QStringLiteral("nelTypeBox"));
        nelTypeBox->setEnabled(false);

        gridLayout->addWidget(nelTypeBox, 2, 1, 1, 1);

        nelNoBox = new QComboBox(tabIOMap);
        nelNoBox->setObjectName(QStringLiteral("nelNoBox"));
        nelNoBox->setEnabled(false);

        gridLayout->addWidget(nelNoBox, 2, 2, 1, 1);

        nelFilterSpin = new QDoubleSpinBox(tabIOMap);
        nelFilterSpin->setObjectName(QStringLiteral("nelFilterSpin"));
        nelFilterSpin->setEnabled(false);

        gridLayout->addWidget(nelFilterSpin, 2, 3, 1, 1);

        label_6 = new QLabel(tabIOMap);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        orgTypeBox = new QComboBox(tabIOMap);
        orgTypeBox->setObjectName(QStringLiteral("orgTypeBox"));
        orgTypeBox->setEnabled(false);

        gridLayout->addWidget(orgTypeBox, 3, 1, 1, 1);

        orgNoBox = new QComboBox(tabIOMap);
        orgNoBox->setObjectName(QStringLiteral("orgNoBox"));
        orgNoBox->setEnabled(false);

        gridLayout->addWidget(orgNoBox, 3, 2, 1, 1);

        orgFilterSpin = new QDoubleSpinBox(tabIOMap);
        orgFilterSpin->setObjectName(QStringLiteral("orgFilterSpin"));
        orgFilterSpin->setEnabled(false);

        gridLayout->addWidget(orgFilterSpin, 3, 3, 1, 1);

        label_7 = new QLabel(tabIOMap);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        emgTypeBox = new QComboBox(tabIOMap);
        emgTypeBox->setObjectName(QStringLiteral("emgTypeBox"));
        emgTypeBox->setEnabled(false);

        gridLayout->addWidget(emgTypeBox, 4, 1, 1, 1);

        emgNoBox = new QComboBox(tabIOMap);
        emgNoBox->setObjectName(QStringLiteral("emgNoBox"));
        emgNoBox->setEnabled(false);

        gridLayout->addWidget(emgNoBox, 4, 2, 1, 1);

        emgFilterSpin = new QDoubleSpinBox(tabIOMap);
        emgFilterSpin->setObjectName(QStringLiteral("emgFilterSpin"));
        emgFilterSpin->setEnabled(false);

        gridLayout->addWidget(emgFilterSpin, 4, 3, 1, 1);

        label_8 = new QLabel(tabIOMap);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        dstpTypeBox = new QComboBox(tabIOMap);
        dstpTypeBox->setObjectName(QStringLiteral("dstpTypeBox"));
        dstpTypeBox->setEnabled(false);

        gridLayout->addWidget(dstpTypeBox, 5, 1, 1, 1);

        dstpNoBox = new QComboBox(tabIOMap);
        dstpNoBox->setObjectName(QStringLiteral("dstpNoBox"));
        dstpNoBox->setEnabled(false);

        gridLayout->addWidget(dstpNoBox, 5, 2, 1, 1);

        dstpFilterSpin = new QDoubleSpinBox(tabIOMap);
        dstpFilterSpin->setObjectName(QStringLiteral("dstpFilterSpin"));
        dstpFilterSpin->setEnabled(false);

        gridLayout->addWidget(dstpFilterSpin, 5, 3, 1, 1);

        label_9 = new QLabel(tabIOMap);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        almTypeBox = new QComboBox(tabIOMap);
        almTypeBox->setObjectName(QStringLiteral("almTypeBox"));
        almTypeBox->setEnabled(false);

        gridLayout->addWidget(almTypeBox, 6, 1, 1, 1);

        almNoBox = new QComboBox(tabIOMap);
        almNoBox->setObjectName(QStringLiteral("almNoBox"));
        almNoBox->setEnabled(false);

        gridLayout->addWidget(almNoBox, 6, 2, 1, 1);

        almFilterSpin = new QDoubleSpinBox(tabIOMap);
        almFilterSpin->setObjectName(QStringLiteral("almFilterSpin"));
        almFilterSpin->setEnabled(false);

        gridLayout->addWidget(almFilterSpin, 6, 3, 1, 1);

        label_10 = new QLabel(tabIOMap);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        inpTypeBox = new QComboBox(tabIOMap);
        inpTypeBox->setObjectName(QStringLiteral("inpTypeBox"));
        inpTypeBox->setEnabled(false);

        gridLayout->addWidget(inpTypeBox, 7, 1, 1, 1);

        inpNoBox = new QComboBox(tabIOMap);
        inpNoBox->setObjectName(QStringLiteral("inpNoBox"));
        inpNoBox->setEnabled(false);

        gridLayout->addWidget(inpNoBox, 7, 2, 1, 1);

        inpFilterSpin = new QDoubleSpinBox(tabIOMap);
        inpFilterSpin->setObjectName(QStringLiteral("inpFilterSpin"));
        inpFilterSpin->setEnabled(false);

        gridLayout->addWidget(inpFilterSpin, 7, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 371, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tabWidget->addTab(tabIOMap, QString());
        tabPulseMode = new QWidget();
        tabPulseMode->setObjectName(QStringLiteral("tabPulseMode"));
        gridLayout_4 = new QGridLayout(tabPulseMode);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(tabPulseMode);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(false);
        groupBox->setMinimumSize(QSize(531, 0));
        groupBox->setMaximumSize(QSize(531, 171));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(5);
        gridLayout_3->setVerticalSpacing(10);
        gridLayout_3->setContentsMargins(50, 10, 20, 10);
        pulseMode0RBtn = new QRadioButton(groupBox);
        pulseMode0RBtn->setObjectName(QStringLiteral("pulseMode0RBtn"));

        gridLayout_3->addWidget(pulseMode0RBtn, 0, 0, 1, 1);

        pulseMode1RBtn = new QRadioButton(groupBox);
        pulseMode1RBtn->setObjectName(QStringLiteral("pulseMode1RBtn"));

        gridLayout_3->addWidget(pulseMode1RBtn, 0, 1, 1, 1);

        pulseMode2RBtn = new QRadioButton(groupBox);
        pulseMode2RBtn->setObjectName(QStringLiteral("pulseMode2RBtn"));

        gridLayout_3->addWidget(pulseMode2RBtn, 0, 2, 1, 1);

        pulseMode3RBtn = new QRadioButton(groupBox);
        pulseMode3RBtn->setObjectName(QStringLiteral("pulseMode3RBtn"));

        gridLayout_3->addWidget(pulseMode3RBtn, 1, 0, 1, 1);

        pulseMode4RBtn = new QRadioButton(groupBox);
        pulseMode4RBtn->setObjectName(QStringLiteral("pulseMode4RBtn"));

        gridLayout_3->addWidget(pulseMode4RBtn, 1, 1, 1, 1);

        pulseMode5RBtn = new QRadioButton(groupBox);
        pulseMode5RBtn->setObjectName(QStringLiteral("pulseMode5RBtn"));
        pulseMode5RBtn->setChecked(true);

        gridLayout_3->addWidget(pulseMode5RBtn, 1, 2, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 3, 1, 2);

        pulsePicLabel = new QLabel(tabPulseMode);
        pulsePicLabel->setObjectName(QStringLiteral("pulsePicLabel"));
        pulsePicLabel->setMinimumSize(QSize(581, 321));
        pulsePicLabel->setMaximumSize(QSize(581, 321));
        pulsePicLabel->setPixmap(QPixmap(QString::fromUtf8(":/PIC/PULSE_MODE")));
        pulsePicLabel->setScaledContents(true);
        pulsePicLabel->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(pulsePicLabel, 1, 1, 1, 3);

        tabWidget->addTab(tabPulseMode, QString());
        tabEncoder = new QWidget();
        tabEncoder->setObjectName(QStringLiteral("tabEncoder"));
        gridLayout_5 = new QGridLayout(tabEncoder);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_15 = new QGroupBox(tabEncoder);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        groupBox_15->setEnabled(false);
        horizontalLayout_9 = new QHBoxLayout(groupBox_15);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(20, -1, 30, 20);
        label_28 = new QLabel(groupBox_15);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_28);

        xEquivalency = new QDoubleSpinBox(groupBox_15);
        xEquivalency->setObjectName(QStringLiteral("xEquivalency"));
        xEquivalency->setEnabled(false);
        xEquivalency->setAlignment(Qt::AlignCenter);
        xEquivalency->setReadOnly(false);
        xEquivalency->setAccelerated(true);
        xEquivalency->setDecimals(4);
        xEquivalency->setMinimum(0);
        xEquivalency->setMaximum(1);
        xEquivalency->setSingleStep(0.0001);
        xEquivalency->setValue(0.002);

        horizontalLayout_9->addWidget(xEquivalency);

        label_29 = new QLabel(groupBox_15);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_29);

        yEquivalency = new QDoubleSpinBox(groupBox_15);
        yEquivalency->setObjectName(QStringLiteral("yEquivalency"));
        yEquivalency->setAlignment(Qt::AlignCenter);
        yEquivalency->setAccelerated(true);
        yEquivalency->setDecimals(4);
        yEquivalency->setMinimum(0);
        yEquivalency->setMaximum(1);
        yEquivalency->setSingleStep(0.0001);
        yEquivalency->setValue(0.002);

        horizontalLayout_9->addWidget(yEquivalency);

        label_30 = new QLabel(groupBox_15);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_30);

        zEquivalency = new QDoubleSpinBox(groupBox_15);
        zEquivalency->setObjectName(QStringLiteral("zEquivalency"));
        zEquivalency->setAlignment(Qt::AlignCenter);
        zEquivalency->setAccelerated(true);
        zEquivalency->setDecimals(4);
        zEquivalency->setMinimum(0);
        zEquivalency->setMaximum(1);
        zEquivalency->setSingleStep(0.0001);
        zEquivalency->setValue(0.002);

        horizontalLayout_9->addWidget(zEquivalency);


        gridLayout_5->addWidget(groupBox_15, 1, 1, 1, 1);

        groupBox_16 = new QGroupBox(tabEncoder);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_16);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(20, -1, 30, -1);
        label_31 = new QLabel(groupBox_16);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_31);

        xyLineVectorVel = new QDoubleSpinBox(groupBox_16);
        xyLineVectorVel->setObjectName(QStringLiteral("xyLineVectorVel"));
        xyLineVectorVel->setAlignment(Qt::AlignCenter);
        xyLineVectorVel->setSuffix(QStringLiteral("p/s"));
        xyLineVectorVel->setDecimals(0);
        xyLineVectorVel->setMinimum(4000);
        xyLineVectorVel->setMaximum(200000);
        xyLineVectorVel->setSingleStep(200);

        horizontalLayout_10->addWidget(xyLineVectorVel);

        label_32 = new QLabel(groupBox_16);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_32);

        zVel = new QDoubleSpinBox(groupBox_16);
        zVel->setObjectName(QStringLiteral("zVel"));
        zVel->setAlignment(Qt::AlignCenter);
        zVel->setSuffix(QStringLiteral("p/s"));
        zVel->setDecimals(0);
        zVel->setMinimum(1000);
        zVel->setMaximum(200000);
        zVel->setSingleStep(200);
        zVel->setValue(4000);

        horizontalLayout_10->addWidget(zVel);


        gridLayout_5->addWidget(groupBox_16, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(65, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(65, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 0, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(70);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(tabEncoder);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(false);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(15, -1, 15, -1);
        notABRBtn = new QRadioButton(groupBox_2);
        notABRBtn->setObjectName(QStringLiteral("notABRBtn"));

        verticalLayout_2->addWidget(notABRBtn);

        singleABRBtn = new QRadioButton(groupBox_2);
        singleABRBtn->setObjectName(QStringLiteral("singleABRBtn"));

        verticalLayout_2->addWidget(singleABRBtn);

        doubleABRBtn = new QRadioButton(groupBox_2);
        doubleABRBtn->setObjectName(QStringLiteral("doubleABRBtn"));

        verticalLayout_2->addWidget(doubleABRBtn);

        quadrupleABRBtn = new QRadioButton(groupBox_2);
        quadrupleABRBtn->setObjectName(QStringLiteral("quadrupleABRBtn"));
        quadrupleABRBtn->setChecked(true);

        verticalLayout_2->addWidget(quadrupleABRBtn);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tabEncoder);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(false);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(50, -1, 50, -1);
        ezLowLvLRBtn = new QRadioButton(groupBox_3);
        ezLowLvLRBtn->setObjectName(QStringLiteral("ezLowLvLRBtn"));
        ezLowLvLRBtn->setChecked(true);

        verticalLayout_3->addWidget(ezLowLvLRBtn);

        ezHighLvLRBtn = new QRadioButton(groupBox_3);
        ezHighLvLRBtn->setObjectName(QStringLiteral("ezHighLvLRBtn"));

        verticalLayout_3->addWidget(ezHighLvLRBtn);


        horizontalLayout_2->addWidget(groupBox_3);


        gridLayout_5->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 502, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_6, 4, 1, 1, 1);

        tabWidget->addTab(tabEncoder, QString());
        tabHomeReturn = new QWidget();
        tabHomeReturn->setObjectName(QStringLiteral("tabHomeReturn"));
        verticalLayout_7 = new QVBoxLayout(tabHomeReturn);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(50);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_6 = new QGroupBox(tabHomeReturn);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setEnabled(false);
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setSpacing(15);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(25, 20, 25, 20);
        hrSlowRBtn = new QRadioButton(groupBox_6);
        hrSlowRBtn->setObjectName(QStringLiteral("hrSlowRBtn"));

        verticalLayout_6->addWidget(hrSlowRBtn);

        hrFastRBtn = new QRadioButton(groupBox_6);
        hrFastRBtn->setObjectName(QStringLiteral("hrFastRBtn"));
        hrFastRBtn->setChecked(true);

        verticalLayout_6->addWidget(hrFastRBtn);


        horizontalLayout_3->addWidget(groupBox_6);

        groupBox_5 = new QGroupBox(tabHomeReturn);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setEnabled(false);
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(25, 20, 25, 20);
        hrNDirectionRBtn = new QRadioButton(groupBox_5);
        hrNDirectionRBtn->setObjectName(QStringLiteral("hrNDirectionRBtn"));
        hrNDirectionRBtn->setChecked(true);

        verticalLayout_5->addWidget(hrNDirectionRBtn);

        hrPDirectionRBtn = new QRadioButton(groupBox_5);
        hrPDirectionRBtn->setObjectName(QStringLiteral("hrPDirectionRBtn"));

        verticalLayout_5->addWidget(hrPDirectionRBtn);


        horizontalLayout_3->addWidget(groupBox_5);

        groupBox_4 = new QGroupBox(tabHomeReturn);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setEnabled(false);
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(25, 20, 25, 20);
        hrLowLvLRBtn = new QRadioButton(groupBox_4);
        hrLowLvLRBtn->setObjectName(QStringLiteral("hrLowLvLRBtn"));
        hrLowLvLRBtn->setChecked(true);

        verticalLayout_4->addWidget(hrLowLvLRBtn);

        hrHighLvLRBtn = new QRadioButton(groupBox_4);
        hrHighLvLRBtn->setObjectName(QStringLiteral("hrHighLvLRBtn"));

        verticalLayout_4->addWidget(hrHighLvLRBtn);


        horizontalLayout_3->addWidget(groupBox_4);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_7->addLayout(horizontalLayout_5);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(55, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        groupBox_7 = new QGroupBox(tabHomeReturn);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setEnabled(false);
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(25);
        gridLayout_6->setVerticalSpacing(20);
        gridLayout_6->setContentsMargins(60, 20, 30, 20);
        hrOnceRBtn = new QRadioButton(groupBox_7);
        hrOnceRBtn->setObjectName(QStringLiteral("hrOnceRBtn"));
        hrOnceRBtn->setChecked(true);

        gridLayout_6->addWidget(hrOnceRBtn, 0, 0, 1, 1);

        hrOnceAndBackwardRBtn = new QRadioButton(groupBox_7);
        hrOnceAndBackwardRBtn->setObjectName(QStringLiteral("hrOnceAndBackwardRBtn"));

        gridLayout_6->addWidget(hrOnceAndBackwardRBtn, 0, 1, 1, 1);

        hrTwiceRBtn = new QRadioButton(groupBox_7);
        hrTwiceRBtn->setObjectName(QStringLiteral("hrTwiceRBtn"));

        gridLayout_6->addWidget(hrTwiceRBtn, 1, 0, 1, 1);

        hrHomeAndForwardEZRBtn = new QRadioButton(groupBox_7);
        hrHomeAndForwardEZRBtn->setObjectName(QStringLiteral("hrHomeAndForwardEZRBtn"));

        gridLayout_6->addWidget(hrHomeAndForwardEZRBtn, 1, 1, 1, 1);

        hrOnceEZRBtn = new QRadioButton(groupBox_7);
        hrOnceEZRBtn->setObjectName(QStringLiteral("hrOnceEZRBtn"));

        gridLayout_6->addWidget(hrOnceEZRBtn, 2, 0, 1, 1);

        hrHomeAndBackwardEZRBtn = new QRadioButton(groupBox_7);
        hrHomeAndBackwardEZRBtn->setObjectName(QStringLiteral("hrHomeAndBackwardEZRBtn"));

        gridLayout_6->addWidget(hrHomeAndBackwardEZRBtn, 2, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox_7);

        horizontalSpacer_9 = new QSpacerItem(55, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_7->addLayout(horizontalLayout_4);

        verticalSpacer_9 = new QSpacerItem(20, 328, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_9);

        tabWidget->addTab(tabHomeReturn, QString());
        tabLimit = new QWidget();
        tabLimit->setObjectName(QStringLiteral("tabLimit"));
        gridLayout_12 = new QGridLayout(tabLimit);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBox_8 = new QGroupBox(tabLimit);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setEnabled(false);
        gridLayout_7 = new QGridLayout(groupBox_8);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(20);
        gridLayout_7->setContentsMargins(25, 10, 25, 10);
        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_7->addWidget(label_11, 0, 0, 1, 1);

        hdwLimitEnableBox = new QComboBox(groupBox_8);
        hdwLimitEnableBox->setObjectName(QStringLiteral("hdwLimitEnableBox"));
        hdwLimitEnableBox->setMinimumSize(QSize(131, 0));

        gridLayout_7->addWidget(hdwLimitEnableBox, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_8);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_7->addWidget(label_12, 1, 0, 1, 1);

        hdwLimitLvLBox = new QComboBox(groupBox_8);
        hdwLimitLvLBox->setObjectName(QStringLiteral("hdwLimitLvLBox"));
        hdwLimitLvLBox->setMinimumSize(QSize(161, 0));

        gridLayout_7->addWidget(hdwLimitLvLBox, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox_8);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_7->addWidget(label_13, 2, 0, 1, 1);

        hdwLimitModeBox = new QComboBox(groupBox_8);
        hdwLimitModeBox->setObjectName(QStringLiteral("hdwLimitModeBox"));
        hdwLimitModeBox->setMinimumSize(QSize(191, 0));

        gridLayout_7->addWidget(hdwLimitModeBox, 2, 1, 1, 1);


        horizontalLayout_7->addWidget(groupBox_8);

        groupBox_12 = new QGroupBox(tabLimit);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setEnabled(false);
        gridLayout_11 = new QGridLayout(groupBox_12);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setVerticalSpacing(15);
        gridLayout_11->setContentsMargins(35, 10, 35, 10);
        label_21 = new QLabel(groupBox_12);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_11->addWidget(label_21, 0, 0, 1, 1);

        ioDstpEnableBox = new QComboBox(groupBox_12);
        ioDstpEnableBox->setObjectName(QStringLiteral("ioDstpEnableBox"));

        gridLayout_11->addWidget(ioDstpEnableBox, 0, 1, 1, 1);

        label_22 = new QLabel(groupBox_12);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_11->addWidget(label_22, 1, 0, 1, 1);

        ioDstpLvLBox = new QComboBox(groupBox_12);
        ioDstpLvLBox->setObjectName(QStringLiteral("ioDstpLvLBox"));

        gridLayout_11->addWidget(ioDstpLvLBox, 1, 1, 1, 1);

        label_23 = new QLabel(groupBox_12);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_11->addWidget(label_23, 2, 0, 1, 1);

        ioDstpTimeSpin = new QDoubleSpinBox(groupBox_12);
        ioDstpTimeSpin->setObjectName(QStringLiteral("ioDstpTimeSpin"));
        ioDstpTimeSpin->setMinimum(0.01);
        ioDstpTimeSpin->setSingleStep(0.01);
        ioDstpTimeSpin->setValue(0.01);

        gridLayout_11->addWidget(ioDstpTimeSpin, 2, 1, 1, 1);


        horizontalLayout_7->addWidget(groupBox_12);


        gridLayout_12->addLayout(horizontalLayout_7, 0, 0, 1, 2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        groupBox_9 = new QGroupBox(tabLimit);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setEnabled(false);
        horizontalLayout_6 = new QHBoxLayout(groupBox_9);
        horizontalLayout_6->setSpacing(12);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(25, 10, 25, 10);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setVerticalSpacing(12);
        label_14 = new QLabel(groupBox_9);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_9->addWidget(label_14, 0, 0, 1, 1);

        sfwLimitEnableBox = new QComboBox(groupBox_9);
        sfwLimitEnableBox->setObjectName(QStringLiteral("sfwLimitEnableBox"));

        gridLayout_9->addWidget(sfwLimitEnableBox, 0, 1, 1, 1);

        label_15 = new QLabel(groupBox_9);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_9->addWidget(label_15, 1, 0, 1, 1);

        sfwLimitModeBox = new QComboBox(groupBox_9);
        sfwLimitModeBox->setObjectName(QStringLiteral("sfwLimitModeBox"));
        sfwLimitModeBox->setMinimumSize(QSize(91, 0));

        gridLayout_9->addWidget(sfwLimitModeBox, 1, 1, 1, 1);

        label_16 = new QLabel(groupBox_9);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_9->addWidget(label_16, 2, 0, 1, 1);

        sfwLimitCounterBox = new QComboBox(groupBox_9);
        sfwLimitCounterBox->setObjectName(QStringLiteral("sfwLimitCounterBox"));
        sfwLimitCounterBox->setEnabled(false);
        sfwLimitCounterBox->setMinimumSize(QSize(91, 0));

        gridLayout_9->addWidget(sfwLimitCounterBox, 2, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_9);

        groupBox_10 = new QGroupBox(groupBox_9);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_8 = new QGridLayout(groupBox_10);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setVerticalSpacing(18);
        label_17 = new QLabel(groupBox_10);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_8->addWidget(label_17, 0, 0, 1, 1);

        sfwLimitPPSpin = new QSpinBox(groupBox_10);
        sfwLimitPPSpin->setObjectName(QStringLiteral("sfwLimitPPSpin"));
        sfwLimitPPSpin->setMinimumSize(QSize(75, 0));

        gridLayout_8->addWidget(sfwLimitPPSpin, 0, 1, 1, 1);

        label_18 = new QLabel(groupBox_10);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_8->addWidget(label_18, 1, 0, 1, 1);

        sfwLimitNPSpin = new QSpinBox(groupBox_10);
        sfwLimitNPSpin->setObjectName(QStringLiteral("sfwLimitNPSpin"));
        sfwLimitNPSpin->setMinimumSize(QSize(75, 0));

        gridLayout_8->addWidget(sfwLimitNPSpin, 1, 1, 1, 1);


        horizontalLayout_6->addWidget(groupBox_10);


        horizontalLayout_8->addWidget(groupBox_9);

        groupBox_11 = new QGroupBox(tabLimit);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setEnabled(false);
        gridLayout_10 = new QGridLayout(groupBox_11);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(25, 10, 25, 10);
        label_19 = new QLabel(groupBox_11);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_10->addWidget(label_19, 0, 0, 1, 1);

        emgEnableBox = new QComboBox(groupBox_11);
        emgEnableBox->setObjectName(QStringLiteral("emgEnableBox"));

        gridLayout_10->addWidget(emgEnableBox, 0, 1, 1, 1);

        label_20 = new QLabel(groupBox_11);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_10->addWidget(label_20, 1, 0, 1, 1);

        emgLvLBox = new QComboBox(groupBox_11);
        emgLvLBox->setObjectName(QStringLiteral("emgLvLBox"));

        gridLayout_10->addWidget(emgLvLBox, 1, 1, 1, 1);


        horizontalLayout_8->addWidget(groupBox_11);


        gridLayout_12->addLayout(horizontalLayout_8, 1, 0, 1, 2);

        groupBox_13 = new QGroupBox(tabLimit);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setEnabled(false);
        gridLayout_13 = new QGridLayout(groupBox_13);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(45, 10, 45, 10);
        label_24 = new QLabel(groupBox_13);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_13->addWidget(label_24, 0, 0, 1, 1);

        almEnableBox = new QComboBox(groupBox_13);
        almEnableBox->setObjectName(QStringLiteral("almEnableBox"));

        gridLayout_13->addWidget(almEnableBox, 0, 1, 1, 1);

        label_25 = new QLabel(groupBox_13);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_13->addWidget(label_25, 1, 0, 1, 1);

        almLvLBox = new QComboBox(groupBox_13);
        almLvLBox->setObjectName(QStringLiteral("almLvLBox"));

        gridLayout_13->addWidget(almLvLBox, 1, 1, 1, 1);


        gridLayout_12->addWidget(groupBox_13, 2, 0, 1, 1);

        groupBox_14 = new QGroupBox(tabLimit);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        groupBox_14->setEnabled(false);
        gridLayout_14 = new QGridLayout(groupBox_14);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(45, -1, 45, -1);
        label_26 = new QLabel(groupBox_14);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_14->addWidget(label_26, 0, 0, 1, 1);

        inpEnableBox = new QComboBox(groupBox_14);
        inpEnableBox->setObjectName(QStringLiteral("inpEnableBox"));

        gridLayout_14->addWidget(inpEnableBox, 0, 1, 1, 1);

        label_27 = new QLabel(groupBox_14);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_14->addWidget(label_27, 1, 0, 1, 1);

        inpLvLBox = new QComboBox(groupBox_14);
        inpLvLBox->setObjectName(QStringLiteral("inpLvLBox"));

        gridLayout_14->addWidget(inpLvLBox, 1, 1, 1, 1);


        gridLayout_12->addWidget(groupBox_14, 2, 1, 1, 1);

        tabWidget->addTab(tabLimit, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(pelTypeBox);
        label_5->setBuddy(nelTypeBox);
        label_6->setBuddy(orgTypeBox);
        label_7->setBuddy(emgTypeBox);
        label_8->setBuddy(dstpTypeBox);
        label_9->setBuddy(almTypeBox);
        label_10->setBuddy(inpTypeBox);
        label_11->setBuddy(hdwLimitEnableBox);
        label_12->setBuddy(hdwLimitLvLBox);
        label_13->setBuddy(hdwLimitModeBox);
        label_21->setBuddy(ioDstpEnableBox);
        label_22->setBuddy(ioDstpLvLBox);
        label_23->setBuddy(ioDstpTimeSpin);
        label_14->setBuddy(sfwLimitEnableBox);
        label_15->setBuddy(sfwLimitModeBox);
        label_16->setBuddy(sfwLimitCounterBox);
        label_17->setBuddy(sfwLimitPPSpin);
        label_18->setBuddy(sfwLimitNPSpin);
        label_19->setBuddy(emgEnableBox);
        label_20->setBuddy(emgLvLBox);
        label_24->setBuddy(almEnableBox);
        label_25->setBuddy(almLvLBox);
        label_26->setBuddy(inpEnableBox);
        label_27->setBuddy(inpLvLBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(axisChsBox, wrtCurrentBtn);
        QWidget::setTabOrder(wrtCurrentBtn, wrtAllBtn);
        QWidget::setTabOrder(wrtAllBtn, readFileBtn);
        QWidget::setTabOrder(readFileBtn, readCardBtn);
        QWidget::setTabOrder(readCardBtn, resetBtn);
        QWidget::setTabOrder(resetBtn, tabWidget);
        QWidget::setTabOrder(tabWidget, pelTypeBox);
        QWidget::setTabOrder(pelTypeBox, pelNoBox);
        QWidget::setTabOrder(pelNoBox, pelFilterSpin);
        QWidget::setTabOrder(pelFilterSpin, nelTypeBox);
        QWidget::setTabOrder(nelTypeBox, nelNoBox);
        QWidget::setTabOrder(nelNoBox, nelFilterSpin);
        QWidget::setTabOrder(nelFilterSpin, orgTypeBox);
        QWidget::setTabOrder(orgTypeBox, orgNoBox);
        QWidget::setTabOrder(orgNoBox, orgFilterSpin);
        QWidget::setTabOrder(orgFilterSpin, emgTypeBox);
        QWidget::setTabOrder(emgTypeBox, emgNoBox);
        QWidget::setTabOrder(emgNoBox, emgFilterSpin);
        QWidget::setTabOrder(emgFilterSpin, dstpTypeBox);
        QWidget::setTabOrder(dstpTypeBox, dstpNoBox);
        QWidget::setTabOrder(dstpNoBox, dstpFilterSpin);
        QWidget::setTabOrder(dstpFilterSpin, almTypeBox);
        QWidget::setTabOrder(almTypeBox, almNoBox);
        QWidget::setTabOrder(almNoBox, almFilterSpin);
        QWidget::setTabOrder(almFilterSpin, inpTypeBox);
        QWidget::setTabOrder(inpTypeBox, inpNoBox);
        QWidget::setTabOrder(inpNoBox, inpFilterSpin);
        QWidget::setTabOrder(inpFilterSpin, pulseMode0RBtn);
        QWidget::setTabOrder(pulseMode0RBtn, pulseMode1RBtn);
        QWidget::setTabOrder(pulseMode1RBtn, pulseMode2RBtn);
        QWidget::setTabOrder(pulseMode2RBtn, pulseMode3RBtn);
        QWidget::setTabOrder(pulseMode3RBtn, pulseMode4RBtn);
        QWidget::setTabOrder(pulseMode4RBtn, pulseMode5RBtn);
        QWidget::setTabOrder(pulseMode5RBtn, notABRBtn);
        QWidget::setTabOrder(notABRBtn, singleABRBtn);
        QWidget::setTabOrder(singleABRBtn, doubleABRBtn);
        QWidget::setTabOrder(doubleABRBtn, quadrupleABRBtn);
        QWidget::setTabOrder(quadrupleABRBtn, ezLowLvLRBtn);
        QWidget::setTabOrder(ezLowLvLRBtn, ezHighLvLRBtn);
        QWidget::setTabOrder(ezHighLvLRBtn, hrSlowRBtn);
        QWidget::setTabOrder(hrSlowRBtn, hrFastRBtn);
        QWidget::setTabOrder(hrFastRBtn, hrNDirectionRBtn);
        QWidget::setTabOrder(hrNDirectionRBtn, hrPDirectionRBtn);
        QWidget::setTabOrder(hrPDirectionRBtn, hrLowLvLRBtn);
        QWidget::setTabOrder(hrLowLvLRBtn, hrHighLvLRBtn);
        QWidget::setTabOrder(hrHighLvLRBtn, hrOnceRBtn);
        QWidget::setTabOrder(hrOnceRBtn, hrTwiceRBtn);
        QWidget::setTabOrder(hrTwiceRBtn, hrOnceEZRBtn);
        QWidget::setTabOrder(hrOnceEZRBtn, hrOnceAndBackwardRBtn);
        QWidget::setTabOrder(hrOnceAndBackwardRBtn, hrHomeAndForwardEZRBtn);
        QWidget::setTabOrder(hrHomeAndForwardEZRBtn, hrHomeAndBackwardEZRBtn);
        QWidget::setTabOrder(hrHomeAndBackwardEZRBtn, hdwLimitEnableBox);
        QWidget::setTabOrder(hdwLimitEnableBox, hdwLimitLvLBox);
        QWidget::setTabOrder(hdwLimitLvLBox, hdwLimitModeBox);
        QWidget::setTabOrder(hdwLimitModeBox, ioDstpEnableBox);
        QWidget::setTabOrder(ioDstpEnableBox, ioDstpLvLBox);
        QWidget::setTabOrder(ioDstpLvLBox, ioDstpTimeSpin);
        QWidget::setTabOrder(ioDstpTimeSpin, sfwLimitEnableBox);
        QWidget::setTabOrder(sfwLimitEnableBox, sfwLimitModeBox);
        QWidget::setTabOrder(sfwLimitModeBox, sfwLimitCounterBox);
        QWidget::setTabOrder(sfwLimitCounterBox, sfwLimitPPSpin);
        QWidget::setTabOrder(sfwLimitPPSpin, sfwLimitNPSpin);
        QWidget::setTabOrder(sfwLimitNPSpin, emgEnableBox);
        QWidget::setTabOrder(emgEnableBox, emgLvLBox);
        QWidget::setTabOrder(emgLvLBox, almEnableBox);
        QWidget::setTabOrder(almEnableBox, almLvLBox);
        QWidget::setTabOrder(almLvLBox, inpEnableBox);
        QWidget::setTabOrder(inpEnableBox, inpLvLBox);

        retranslateUi(MotionCtrlCfgDlg);

        tabWidget->setCurrentIndex(1);
        nelTypeBox->setCurrentIndex(1);
        orgTypeBox->setCurrentIndex(2);
        emgTypeBox->setCurrentIndex(6);
        dstpTypeBox->setCurrentIndex(6);
        almTypeBox->setCurrentIndex(3);
        inpTypeBox->setCurrentIndex(5);
        hdwLimitEnableBox->setCurrentIndex(1);
        emgEnableBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MotionCtrlCfgDlg);
    } // setupUi

    void retranslateUi(QDialog *MotionCtrlCfgDlg)
    {
        MotionCtrlCfgDlg->setWindowTitle(QApplication::translate("MotionCtrlCfgDlg", "\350\277\220\345\212\250\346\216\247\345\210\266\345\215\241\351\205\215\347\275\256", Q_NULLPTR));
        axisChsBox->clear();
        axisChsBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0\350\275\264", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1\350\275\264", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2\350\275\264", Q_NULLPTR)
        );
        wrtCurrentBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\206\231\345\205\245\345\275\223\345\211\215\350\275\264", Q_NULLPTR));
        wrtAllBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\206\231\345\205\245\346\211\200\346\234\211\350\275\264", Q_NULLPTR));
        readFileBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\350\257\273\345\217\226\351\205\215\347\275\256\346\226\207\344\273\266", Q_NULLPTR));
        readCardBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\350\257\273\345\217\226\346\216\247\345\210\266\345\215\241", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        resetBtn->setToolTip(QApplication::translate("MotionCtrlCfgDlg", "<html><head/><body><p>\346\201\242\345\244\215\346\211\200\346\234\211\351\205\215\347\275\256\357\274\214<span style=\" font-weight:600;\">\351\207\215\345\220\257\345\220\216\347\224\237\346\225\210</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        resetBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\351\207\215\347\275\256\347\241\254\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("MotionCtrlCfgDlg", "\347\261\273\345\236\213", Q_NULLPTR));
        label_2->setText(QApplication::translate("MotionCtrlCfgDlg", "\347\274\226\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\273\244\346\263\242\346\227\266\351\227\264\357\274\210s\357\274\211", Q_NULLPTR));
        label_4->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\255\243\351\231\220\344\275\215\344\277\241\345\217\267\357\274\232", Q_NULLPTR));
        pelTypeBox->clear();
        pelTypeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\346\255\243", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\350\264\237", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\346\212\245\350\255\246", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\207\206\345\244\207", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\210\260\344\275\215", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\200\232\347\224\250\350\276\223\345\205\245", Q_NULLPTR)
        );
        pelNoBox->clear();
        pelNoBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "4", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "5", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "6", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "7", Q_NULLPTR)
        );
        pelFilterSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "s", Q_NULLPTR));
        label_5->setText(QApplication::translate("MotionCtrlCfgDlg", "\350\264\237\351\231\220\344\275\215\344\277\241\345\217\267\357\274\232", Q_NULLPTR));
        nelTypeBox->clear();
        nelTypeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\346\255\243", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\350\264\237", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\346\212\245\350\255\246", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\207\206\345\244\207", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\210\260\344\275\215", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\200\232\347\224\250\350\276\223\345\205\245", Q_NULLPTR)
        );
        nelNoBox->clear();
        nelNoBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "4", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "5", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "6", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "7", Q_NULLPTR)
        );
        nelFilterSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "s", Q_NULLPTR));
        label_6->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271\344\277\241\345\217\267\357\274\232", Q_NULLPTR));
        orgTypeBox->clear();
        orgTypeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\346\255\243", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\350\264\237", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\346\212\245\350\255\246", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\207\206\345\244\207", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\210\260\344\275\215", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\200\232\347\224\250\350\276\223\345\205\245", Q_NULLPTR)
        );
        orgNoBox->clear();
        orgNoBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "4", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "5", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "6", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "7", Q_NULLPTR)
        );
        orgFilterSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "s", Q_NULLPTR));
        label_7->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\200\245\345\201\234\344\277\241\345\217\267\357\274\232", Q_NULLPTR));
        emgTypeBox->clear();
        emgTypeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\346\255\243", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\350\264\237", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\346\212\245\350\255\246", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\207\206\345\244\207", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\210\260\344\275\215", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\200\232\347\224\250\350\276\223\345\205\245", Q_NULLPTR)
        );
        emgNoBox->clear();
        emgNoBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "4", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "5", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "6", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "7", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "8", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "9", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "10", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "11", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "12", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "13", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "14", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "15", Q_NULLPTR)
        );
        emgFilterSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "s", Q_NULLPTR));
        label_8->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\207\217\351\200\237\345\201\234\346\255\242\344\277\241\345\217\267\357\274\232", Q_NULLPTR));
        dstpTypeBox->clear();
        dstpTypeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\346\255\243", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\350\264\237", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\346\212\245\350\255\246", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\207\206\345\244\207", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\210\260\344\275\215", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\200\232\347\224\250\350\276\223\345\205\245", Q_NULLPTR)
        );
        dstpNoBox->clear();
        dstpNoBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "4", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "5", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "6", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "7", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "8", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "9", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "10", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "11", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "12", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "13", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "14", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "15", Q_NULLPTR)
        );
        dstpFilterSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "s", Q_NULLPTR));
        label_9->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\346\212\245\350\255\246\344\277\241\345\217\267\357\274\232", Q_NULLPTR));
        almTypeBox->clear();
        almTypeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\346\255\243", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\350\264\237", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\346\212\245\350\255\246", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\207\206\345\244\207", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\210\260\344\275\215", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\200\232\347\224\250\350\276\223\345\205\245", Q_NULLPTR)
        );
        almNoBox->clear();
        almNoBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "4", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "5", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "6", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "7", Q_NULLPTR)
        );
        almFilterSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "s", Q_NULLPTR));
        label_10->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\210\260\344\275\215\344\277\241\345\217\267\357\274\232", Q_NULLPTR));
        inpTypeBox->clear();
        inpTypeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\346\255\243", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\350\264\237", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\346\212\245\350\255\246", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\207\206\345\244\207", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\344\274\272\346\234\215\345\210\260\344\275\215", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\200\232\347\224\250\350\276\223\345\205\245", Q_NULLPTR)
        );
        inpNoBox->clear();
        inpNoBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "4", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "5", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "6", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "7", Q_NULLPTR)
        );
        inpFilterSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "s", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabIOMap), QApplication::translate("MotionCtrlCfgDlg", "I/O Map", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\350\204\211\345\206\262\347\261\273\345\236\213", Q_NULLPTR));
        pulseMode0RBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "0\357\274\232\350\204\211\345\206\262+\346\226\271\345\220\221", Q_NULLPTR));
        pulseMode1RBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "1\357\274\232\350\204\211\345\206\262+\346\226\271\345\220\221", Q_NULLPTR));
        pulseMode2RBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "2\357\274\232\350\204\211\345\206\262+\346\226\271\345\220\221", Q_NULLPTR));
        pulseMode3RBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "3\357\274\232\350\204\211\345\206\262+\346\226\271\345\220\221", Q_NULLPTR));
        pulseMode4RBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "4\357\274\232\345\217\214\350\204\211\345\206\262", Q_NULLPTR));
        pulseMode5RBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "5\357\274\232\345\217\214\350\204\211\345\206\262", Q_NULLPTR));
        pulsePicLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabPulseMode), QApplication::translate("MotionCtrlCfgDlg", "Pulse Mode", Q_NULLPTR));
        groupBox_15->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\350\204\211\345\206\262\345\275\223\351\207\217", Q_NULLPTR));
        label_28->setText(QApplication::translate("MotionCtrlCfgDlg", "X-", Q_NULLPTR));
        xEquivalency->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "mm", Q_NULLPTR));
        label_29->setText(QApplication::translate("MotionCtrlCfgDlg", "Y-", Q_NULLPTR));
        yEquivalency->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "mm", Q_NULLPTR));
        label_30->setText(QApplication::translate("MotionCtrlCfgDlg", "Z-", Q_NULLPTR));
        zEquivalency->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "mm", Q_NULLPTR));
        groupBox_16->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\350\277\220\350\241\214\351\200\237\345\272\246", Q_NULLPTR));
        label_31->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\260\264\345\271\263\346\226\271\345\220\221-", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xyLineVectorVel->setToolTip(QApplication::translate("MotionCtrlCfgDlg", "<html><head/><body><p><span style=\" font-weight:600;\">\345\205\250\345\261\200</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_32->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\236\202\347\233\264\346\226\271\345\220\221-", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zVel->setToolTip(QApplication::translate("MotionCtrlCfgDlg", "<html><head/><body><p><span style=\" font-weight:600;\">\345\205\250\345\261\200</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\350\276\223\345\205\245\346\250\241\345\274\217", Q_NULLPTR));
        notABRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\351\235\236AB\347\233\270(\350\204\211\345\206\262/\346\226\271\345\220\221)", Q_NULLPTR));
        singleABRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "AB\347\233\2701\345\200\215\350\256\241\346\225\260(1*A/B)", Q_NULLPTR));
        doubleABRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "AB\347\233\2702\345\200\215\350\256\241\346\225\260(2*A/B)", Q_NULLPTR));
        quadrupleABRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "AB\347\233\2704\345\200\215\350\256\241\346\225\260(4*A/B)", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MotionCtrlCfgDlg", "EZ\344\277\241\345\217\267", Q_NULLPTR));
        ezLowLvLRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\216\347\224\265\345\271\263", Q_NULLPTR));
        ezHighLvLRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\351\253\230\347\224\265\345\271\263", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabEncoder), QApplication::translate("MotionCtrlCfgDlg", "Encoder", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\345\233\236\345\216\237\351\200\237\345\272\246", Q_NULLPTR));
        hrSlowRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\216\351\200\237", Q_NULLPTR));
        hrFastRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\351\253\230\351\200\237", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\345\233\236\345\216\237\346\226\271\345\220\221", Q_NULLPTR));
        hrNDirectionRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\350\264\237\345\220\221", Q_NULLPTR));
        hrPDirectionRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\255\243\345\220\221", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\346\234\211\346\225\210\347\224\265\345\271\263", Q_NULLPTR));
        hrLowLvLRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\216\347\224\265\345\271\263", Q_NULLPTR));
        hrHighLvLRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\351\253\230\347\224\265\345\271\263", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\345\233\236\345\216\237\346\226\271\345\274\217", Q_NULLPTR));
        hrOnceRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\270\200\346\254\241\345\233\236\351\233\266", Q_NULLPTR));
        hrOnceAndBackwardRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\270\200\346\254\241\345\233\236\351\233\266+\345\217\215\346\211\276", Q_NULLPTR));
        hrTwiceRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\272\214\346\254\241\345\233\236\351\233\266", Q_NULLPTR));
        hrHomeAndForwardEZRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271+\345\220\214\345\220\221EZ\345\233\236\351\233\266", Q_NULLPTR));
        hrOnceEZRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\270\200\346\254\241EZ\345\233\236\351\233\266", Q_NULLPTR));
        hrHomeAndBackwardEZRBtn->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\216\237\347\202\271+\345\217\215\346\211\276EZ\345\233\236\351\233\266", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabHomeReturn), QApplication::translate("MotionCtrlCfgDlg", "Home Return", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\347\241\254\344\273\266\351\231\220\344\275\215", Q_NULLPTR));
        label_11->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\277\350\203\275\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        hdwLimitEnableBox->clear();
        hdwLimitEnableBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0-\346\255\243\350\264\237\351\231\220\344\275\215\347\246\201\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1-\346\255\243\350\264\237\351\231\220\344\275\215\345\205\201\350\256\270", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2-\346\255\243\347\246\201\346\255\242,\350\264\237\345\205\201\350\256\270", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3-\346\255\243\345\205\201\350\256\270,\350\264\237\347\246\201\346\255\242", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\234\211\346\225\210\347\224\265\345\271\263\357\274\232", Q_NULLPTR));
        hdwLimitLvLBox->clear();
        hdwLimitLvLBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0-\346\255\243\350\264\237\351\231\220\344\275\215\344\275\216\346\234\211\346\225\210", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1-\346\255\243\350\264\237\351\231\220\344\275\215\351\253\230\346\234\211\346\225\210", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2-\346\255\243\344\275\216\346\234\211\346\225\210\357\274\214\350\264\237\351\253\230\346\234\211\346\225\210", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3-\346\255\243\351\253\230\346\234\211\346\225\210\357\274\214\350\264\237\344\275\216\346\234\211\346\225\210", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\210\266\345\212\250\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        hdwLimitModeBox->clear();
        hdwLimitModeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "0-\346\255\243\350\264\237\351\231\220\344\275\215\347\253\213\345\215\263\345\201\234\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "1-\346\255\243\350\264\237\351\231\220\344\275\215\345\207\217\351\200\237\345\201\234\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "2-\346\255\243\347\253\213\345\215\263\345\201\234\346\255\242\357\274\214\350\264\237\345\207\217\351\200\237\345\201\234\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "3-\346\255\243\345\207\217\351\200\237\345\201\234\346\255\242\357\274\214\350\264\237\347\253\213\345\215\263\345\201\234\346\255\242", Q_NULLPTR)
        );
        groupBox_12->setTitle(QApplication::translate("MotionCtrlCfgDlg", "I/O\350\247\246\345\217\221\345\207\217\351\200\237\345\201\234\346\255\242", Q_NULLPTR));
        label_21->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\277\350\203\275\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        ioDstpEnableBox->clear();
        ioDstpEnableBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\347\246\201\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\205\201\350\256\270", Q_NULLPTR)
        );
        label_22->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\234\211\346\225\210\347\224\265\345\271\263\357\274\232", Q_NULLPTR));
        ioDstpLvLBox->clear();
        ioDstpLvLBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\344\275\216\346\234\211\346\225\210", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\253\230\346\234\211\346\225\210", Q_NULLPTR)
        );
        label_23->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\201\234\346\255\242\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        ioDstpTimeSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "s", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\350\275\257\344\273\266\351\231\220\344\275\215", Q_NULLPTR));
        label_14->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\277\350\203\275\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        sfwLimitEnableBox->clear();
        sfwLimitEnableBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\347\246\201\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\205\201\350\256\270", Q_NULLPTR)
        );
        label_15->setText(QApplication::translate("MotionCtrlCfgDlg", "\345\210\266\345\212\250\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        sfwLimitModeBox->clear();
        sfwLimitModeBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\347\253\213\345\215\263\345\201\234\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\207\217\351\200\237\345\201\234\346\255\242", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("MotionCtrlCfgDlg", "\350\256\241\346\225\260\345\231\250\357\274\232", Q_NULLPTR));
        sfwLimitCounterBox->clear();
        sfwLimitCounterBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\346\214\207\344\273\244\344\275\215\347\275\256", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\347\274\226\347\240\201\345\231\250", Q_NULLPTR)
        );
        groupBox_10->setTitle(QApplication::translate("MotionCtrlCfgDlg", "\344\275\215\347\275\256", Q_NULLPTR));
        label_17->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\255\243\345\220\221\357\274\232", Q_NULLPTR));
        sfwLimitPPSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "p", Q_NULLPTR));
        label_18->setText(QApplication::translate("MotionCtrlCfgDlg", "\350\264\237\345\220\221\357\274\232", Q_NULLPTR));
        sfwLimitNPSpin->setSuffix(QApplication::translate("MotionCtrlCfgDlg", "p", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("MotionCtrlCfgDlg", "EMG", Q_NULLPTR));
        label_19->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\277\350\203\275\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        emgEnableBox->clear();
        emgEnableBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\347\246\201\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\205\201\350\256\270", Q_NULLPTR)
        );
        label_20->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\234\211\346\225\210\347\224\265\345\271\263\357\274\232", Q_NULLPTR));
        emgLvLBox->clear();
        emgLvLBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\344\275\216\346\234\211\346\225\210", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\253\230\346\234\211\346\225\210", Q_NULLPTR)
        );
        groupBox_13->setTitle(QApplication::translate("MotionCtrlCfgDlg", "ALM", Q_NULLPTR));
        label_24->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\277\350\203\275\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        almEnableBox->clear();
        almEnableBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\347\246\201\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\205\201\350\256\270", Q_NULLPTR)
        );
        label_25->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\234\211\346\225\210\347\224\265\345\271\263\357\274\232", Q_NULLPTR));
        almLvLBox->clear();
        almLvLBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\344\275\216\346\234\211\346\225\210", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\253\230\346\234\211\346\225\210", Q_NULLPTR)
        );
        groupBox_14->setTitle(QApplication::translate("MotionCtrlCfgDlg", "INP", Q_NULLPTR));
        label_26->setText(QApplication::translate("MotionCtrlCfgDlg", "\344\275\277\350\203\275\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        inpEnableBox->clear();
        inpEnableBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\347\246\201\346\255\242", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\345\205\201\350\256\270", Q_NULLPTR)
        );
        label_27->setText(QApplication::translate("MotionCtrlCfgDlg", "\346\234\211\346\225\210\347\224\265\345\271\263\357\274\232", Q_NULLPTR));
        inpLvLBox->clear();
        inpLvLBox->insertItems(0, QStringList()
         << QApplication::translate("MotionCtrlCfgDlg", "\344\275\216\346\234\211\346\225\210", Q_NULLPTR)
         << QApplication::translate("MotionCtrlCfgDlg", "\351\253\230\346\234\211\346\225\210", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tabLimit), QApplication::translate("MotionCtrlCfgDlg", "Limit && Servo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MotionCtrlCfgDlg: public Ui_MotionCtrlCfgDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTIONCTRLCFGDLG_H
