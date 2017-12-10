/********************************************************************************
** Form generated from reading UI file 'Intelligence3DMeasurement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTELLIGENCE3DMEASUREMENT_H
#define UI_INTELLIGENCE3DMEASUREMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Intelligence3DMeasurementClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Intelligence3DMeasurementClass)
    {
        if (Intelligence3DMeasurementClass->objectName().isEmpty())
            Intelligence3DMeasurementClass->setObjectName(QStringLiteral("Intelligence3DMeasurementClass"));
        Intelligence3DMeasurementClass->resize(600, 400);
        menuBar = new QMenuBar(Intelligence3DMeasurementClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Intelligence3DMeasurementClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Intelligence3DMeasurementClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Intelligence3DMeasurementClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Intelligence3DMeasurementClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Intelligence3DMeasurementClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Intelligence3DMeasurementClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Intelligence3DMeasurementClass->setStatusBar(statusBar);

        retranslateUi(Intelligence3DMeasurementClass);

        QMetaObject::connectSlotsByName(Intelligence3DMeasurementClass);
    } // setupUi

    void retranslateUi(QMainWindow *Intelligence3DMeasurementClass)
    {
        Intelligence3DMeasurementClass->setWindowTitle(QApplication::translate("Intelligence3DMeasurementClass", "Intelligence3DMeasurement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Intelligence3DMeasurementClass: public Ui_Intelligence3DMeasurementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTELLIGENCE3DMEASUREMENT_H
