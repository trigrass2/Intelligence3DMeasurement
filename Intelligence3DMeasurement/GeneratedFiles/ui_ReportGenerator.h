/********************************************************************************
** Form generated from reading UI file 'ReportGenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTGENERATOR_H
#define UI_REPORTGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ReportGenerator
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *reportArea;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveBtn;
    QCheckBox *syncSQL;

    void setupUi(QDialog *ReportGenerator)
    {
        if (ReportGenerator->objectName().isEmpty())
            ReportGenerator->setObjectName(QStringLiteral("ReportGenerator"));
        ReportGenerator->resize(1350, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReportGenerator->sizePolicy().hasHeightForWidth());
        ReportGenerator->setSizePolicy(sizePolicy);
        ReportGenerator->setMinimumSize(QSize(1350, 800));
        ReportGenerator->setMaximumSize(QSize(1350, 800));
        ReportGenerator->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(ReportGenerator);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        reportArea = new QTextEdit(ReportGenerator);
        reportArea->setObjectName(QStringLiteral("reportArea"));
        reportArea->setReadOnly(true);

        gridLayout->addWidget(reportArea, 0, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        saveBtn = new QPushButton(ReportGenerator);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(saveBtn->sizePolicy().hasHeightForWidth());
        saveBtn->setSizePolicy(sizePolicy1);
        saveBtn->setMinimumSize(QSize(100, 28));
        saveBtn->setMaximumSize(QSize(200, 28));
        saveBtn->setFlat(false);

        gridLayout->addWidget(saveBtn, 1, 2, 1, 1);

        syncSQL = new QCheckBox(ReportGenerator);
        syncSQL->setObjectName(QStringLiteral("syncSQL"));
        syncSQL->setChecked(true);

        gridLayout->addWidget(syncSQL, 1, 3, 1, 1);


        retranslateUi(ReportGenerator);

        QMetaObject::connectSlotsByName(ReportGenerator);
    } // setupUi

    void retranslateUi(QDialog *ReportGenerator)
    {
        ReportGenerator->setWindowTitle(QApplication::translate("ReportGenerator", "\346\212\245\350\241\250\351\242\204\350\247\210", Q_NULLPTR));
        saveBtn->setText(QApplication::translate("ReportGenerator", "\344\277\235 \345\255\230", Q_NULLPTR));
        syncSQL->setText(QApplication::translate("ReportGenerator", "\345\255\230\345\205\245\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportGenerator: public Ui_ReportGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTGENERATOR_H
