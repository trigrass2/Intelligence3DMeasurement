/********************************************************************************
** Form generated from reading UI file 'DataRangeSelector.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATARANGESELECTOR_H
#define UI_DATARANGESELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DataRangeSelector
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *itemSelector;
    QLabel *label_2;
    QDateTimeEdit *dateLower;
    QLabel *label_3;
    QDateTimeEdit *dateUpper;
    QLabel *label_4;
    QCheckBox *xbarRChkBox;
    QCheckBox *xbarSChkBox;
    QCheckBox *xmedRChkBox;
    QCheckBox *xRsChkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *rejectBtn;
    QPushButton *acceptBtn;

    void setupUi(QDialog *DataRangeSelector)
    {
        if (DataRangeSelector->objectName().isEmpty())
            DataRangeSelector->setObjectName(QStringLiteral("DataRangeSelector"));
        DataRangeSelector->resize(444, 150);
        DataRangeSelector->setMinimumSize(QSize(444, 150));
        DataRangeSelector->setMaximumSize(QSize(444, 150));
        gridLayout_2 = new QGridLayout(DataRangeSelector);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(7, 7, 7, 7);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(DataRangeSelector);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        itemSelector = new QComboBox(DataRangeSelector);
        itemSelector->setObjectName(QStringLiteral("itemSelector"));

        gridLayout->addWidget(itemSelector, 0, 1, 1, 5);

        label_2 = new QLabel(DataRangeSelector);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        dateLower = new QDateTimeEdit(DataRangeSelector);
        dateLower->setObjectName(QStringLiteral("dateLower"));
        dateLower->setCalendarPopup(true);

        gridLayout->addWidget(dateLower, 1, 1, 1, 2);

        label_3 = new QLabel(DataRangeSelector);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 3, 1, 1);

        dateUpper = new QDateTimeEdit(DataRangeSelector);
        dateUpper->setObjectName(QStringLiteral("dateUpper"));
        dateUpper->setCalendarPopup(true);

        gridLayout->addWidget(dateUpper, 1, 4, 1, 2);

        label_4 = new QLabel(DataRangeSelector);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        xbarRChkBox = new QCheckBox(DataRangeSelector);
        xbarRChkBox->setObjectName(QStringLiteral("xbarRChkBox"));
        xbarRChkBox->setChecked(true);

        gridLayout->addWidget(xbarRChkBox, 2, 1, 1, 1);

        xbarSChkBox = new QCheckBox(DataRangeSelector);
        xbarSChkBox->setObjectName(QStringLiteral("xbarSChkBox"));

        gridLayout->addWidget(xbarSChkBox, 2, 2, 1, 1);

        xmedRChkBox = new QCheckBox(DataRangeSelector);
        xmedRChkBox->setObjectName(QStringLiteral("xmedRChkBox"));
        xmedRChkBox->setEnabled(false);

        gridLayout->addWidget(xmedRChkBox, 2, 3, 1, 2);

        xRsChkBox = new QCheckBox(DataRangeSelector);
        xRsChkBox->setObjectName(QStringLiteral("xRsChkBox"));
        xRsChkBox->setEnabled(false);

        gridLayout->addWidget(xRsChkBox, 2, 5, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(227, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        rejectBtn = new QPushButton(DataRangeSelector);
        rejectBtn->setObjectName(QStringLiteral("rejectBtn"));

        gridLayout_2->addWidget(rejectBtn, 1, 1, 1, 1);

        acceptBtn = new QPushButton(DataRangeSelector);
        acceptBtn->setObjectName(QStringLiteral("acceptBtn"));

        gridLayout_2->addWidget(acceptBtn, 1, 2, 1, 1);


        retranslateUi(DataRangeSelector);

        QMetaObject::connectSlotsByName(DataRangeSelector);
    } // setupUi

    void retranslateUi(QDialog *DataRangeSelector)
    {
        DataRangeSelector->setWindowTitle(QApplication::translate("DataRangeSelector", "SPC\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("DataRangeSelector", "\346\225\260\346\215\256\351\241\271\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("DataRangeSelector", "\346\230\276\347\244\272\350\214\203\345\233\264\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("DataRangeSelector", "-", Q_NULLPTR));
        label_4->setText(QApplication::translate("DataRangeSelector", "\345\233\276\350\241\250\357\274\232", Q_NULLPTR));
        xbarRChkBox->setText(QApplication::translate("DataRangeSelector", "Xbar-R", Q_NULLPTR));
        xbarSChkBox->setText(QApplication::translate("DataRangeSelector", "Xbar-S", Q_NULLPTR));
        xmedRChkBox->setText(QApplication::translate("DataRangeSelector", "Xmed-R", Q_NULLPTR));
        xRsChkBox->setText(QApplication::translate("DataRangeSelector", "X-Rs", Q_NULLPTR));
        rejectBtn->setText(QApplication::translate("DataRangeSelector", "\345\205\263\351\227\255", Q_NULLPTR));
        acceptBtn->setText(QApplication::translate("DataRangeSelector", "\345\274\271\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataRangeSelector: public Ui_DataRangeSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATARANGESELECTOR_H
