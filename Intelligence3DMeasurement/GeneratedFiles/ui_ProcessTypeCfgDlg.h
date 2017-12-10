/********************************************************************************
** Form generated from reading UI file 'ProcessTypeCfgDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSTYPECFGDLG_H
#define UI_PROCESSTYPECFGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessTypeCfgDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *subGroupVolSlider;
    QLabel *subGroupVolLabel;
    QRadioButton *xyMeasureBtn;
    QRadioButton *xyzMeasureBtn;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *manualSaveBtn;
    QRadioButton *autoSaveBtn;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDoubleSpinBox *viewField;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ProcessTypeCfgDlg)
    {
        if (ProcessTypeCfgDlg->objectName().isEmpty())
            ProcessTypeCfgDlg->setObjectName(QStringLiteral("ProcessTypeCfgDlg"));
        ProcessTypeCfgDlg->resize(450, 304);
        ProcessTypeCfgDlg->setMinimumSize(QSize(450, 304));
        ProcessTypeCfgDlg->setMaximumSize(QSize(450, 304));
        verticalLayout = new QVBoxLayout(ProcessTypeCfgDlg);
        verticalLayout->setSpacing(25);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        groupBox_2 = new QGroupBox(ProcessTypeCfgDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(20, 7, 20, 7);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        subGroupVolSlider = new QSlider(groupBox_2);
        subGroupVolSlider->setObjectName(QStringLiteral("subGroupVolSlider"));
        subGroupVolSlider->setMinimumSize(QSize(250, 0));
        subGroupVolSlider->setMaximumSize(QSize(250, 16777215));
        subGroupVolSlider->setMinimum(1);
        subGroupVolSlider->setMaximum(17);
        subGroupVolSlider->setPageStep(3);
        subGroupVolSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(subGroupVolSlider);

        subGroupVolLabel = new QLabel(groupBox_2);
        subGroupVolLabel->setObjectName(QStringLiteral("subGroupVolLabel"));
        subGroupVolLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(subGroupVolLabel);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 2);

        xyMeasureBtn = new QRadioButton(groupBox_2);
        xyMeasureBtn->setObjectName(QStringLiteral("xyMeasureBtn"));
        xyMeasureBtn->setChecked(false);

        gridLayout_2->addWidget(xyMeasureBtn, 1, 0, 1, 1);

        xyzMeasureBtn = new QRadioButton(groupBox_2);
        xyzMeasureBtn->setObjectName(QStringLiteral("xyzMeasureBtn"));
        xyzMeasureBtn->setChecked(true);

        gridLayout_2->addWidget(xyzMeasureBtn, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(ProcessTypeCfgDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 7, 20, 7);
        manualSaveBtn = new QRadioButton(groupBox);
        manualSaveBtn->setObjectName(QStringLiteral("manualSaveBtn"));
        manualSaveBtn->setChecked(true);

        gridLayout->addWidget(manualSaveBtn, 0, 1, 1, 1);

        autoSaveBtn = new QRadioButton(groupBox);
        autoSaveBtn->setObjectName(QStringLiteral("autoSaveBtn"));
        autoSaveBtn->setChecked(false);

        gridLayout->addWidget(autoSaveBtn, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(ProcessTypeCfgDlg);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        groupBox_3->setFlat(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        viewField = new QDoubleSpinBox(groupBox_3);
        viewField->setObjectName(QStringLiteral("viewField"));
        viewField->setMinimumSize(QSize(111, 0));
        viewField->setMaximumSize(QSize(111, 16777215));
        viewField->setAlignment(Qt::AlignCenter);
        viewField->setDecimals(1);
        viewField->setMinimum(1);
        viewField->setMaximum(100);
        viewField->setSingleStep(0.1);
        viewField->setValue(15);

        horizontalLayout_2->addWidget(viewField);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBox_3);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(subGroupVolSlider);
        label_2->setBuddy(viewField);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(subGroupVolSlider, xyMeasureBtn);
        QWidget::setTabOrder(xyMeasureBtn, xyzMeasureBtn);
        QWidget::setTabOrder(xyzMeasureBtn, autoSaveBtn);
        QWidget::setTabOrder(autoSaveBtn, manualSaveBtn);
        QWidget::setTabOrder(manualSaveBtn, viewField);

        retranslateUi(ProcessTypeCfgDlg);
        QObject::connect(subGroupVolSlider, SIGNAL(valueChanged(int)), subGroupVolLabel, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(ProcessTypeCfgDlg);
    } // setupUi

    void retranslateUi(QWidget *ProcessTypeCfgDlg)
    {
        ProcessTypeCfgDlg->setWindowTitle(QApplication::translate("ProcessTypeCfgDlg", "\346\225\260\346\215\256\345\244\204\347\220\206\351\205\215\347\275\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ProcessTypeCfgDlg", "\346\265\213\351\207\217\346\250\241\345\274\217", Q_NULLPTR));
        label->setText(QApplication::translate("ProcessTypeCfgDlg", "\351\207\215\345\244\215\346\254\241\346\225\260\357\274\232", Q_NULLPTR));
        subGroupVolLabel->setText(QApplication::translate("ProcessTypeCfgDlg", "1", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xyMeasureBtn->setToolTip(QApplication::translate("ProcessTypeCfgDlg", "<html><head/><body><p>\344\270\215\344\275\277\347\224\250\346\277\200\345\205\211\357\274\214\345\217\252\350\277\233\350\241\214X-Y\345\271\263\351\235\242\346\265\213\351\207\217</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        xyMeasureBtn->setText(QApplication::translate("ProcessTypeCfgDlg", "X-Y\346\265\213\351\207\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xyzMeasureBtn->setToolTip(QApplication::translate("ProcessTypeCfgDlg", "<html><head/><body><p>\345\220\214\346\227\266\344\275\277\347\224\250\346\277\200\345\205\211\350\277\233\350\241\214Z\346\226\271\345\220\221\346\265\213\351\207\217</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        xyzMeasureBtn->setText(QApplication::translate("ProcessTypeCfgDlg", "X-Y-Z\346\265\213\351\207\217", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ProcessTypeCfgDlg", "\346\212\245\350\241\250\346\250\241\345\274\217", Q_NULLPTR));
        manualSaveBtn->setText(QApplication::translate("ProcessTypeCfgDlg", "\346\257\217\346\254\241\345\274\271\345\207\272\357\274\214\347\241\256\350\256\244\345\220\216\344\277\235\345\255\230", Q_NULLPTR));
        autoSaveBtn->setText(QApplication::translate("ProcessTypeCfgDlg", "\344\270\215\345\274\271\345\207\272\357\274\214\351\235\231\351\273\230\344\277\235\345\255\230", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ProcessTypeCfgDlg", "\351\207\207\346\240\267\345\210\206\345\211\262\350\256\276\345\256\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ProcessTypeCfgDlg", "\350\247\206\345\234\272\350\214\203\345\233\264\357\274\210\350\276\271\351\225\277\357\274\211\357\274\232", Q_NULLPTR));
        viewField->setSuffix(QApplication::translate("ProcessTypeCfgDlg", "mm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProcessTypeCfgDlg: public Ui_ProcessTypeCfgDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSTYPECFGDLG_H
