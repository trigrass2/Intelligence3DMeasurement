/********************************************************************************
** Form generated from reading UI file 'mainui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainUIClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainUIClass)
    {
        if (MainUIClass->objectName().isEmpty())
            MainUIClass->setObjectName(QStringLiteral("MainUIClass"));
        MainUIClass->resize(1231, 848);
        MainUIClass->setMinimumSize(QSize(1231, 848));
        centralWidget = new QWidget(MainUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1231, 26));
        MainUIClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainUIClass->setStatusBar(statusBar);

        retranslateUi(MainUIClass);

        QMetaObject::connectSlotsByName(MainUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainUIClass)
    {
        MainUIClass->setWindowTitle(QApplication::translate("MainUIClass", "\344\270\211\347\273\264\346\231\272\350\203\275\346\243\200\346\265\213\345\271\263\345\217\260\347\263\273\347\273\237", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        MainUIClass->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainUIClass: public Ui_MainUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
