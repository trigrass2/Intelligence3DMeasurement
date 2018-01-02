/********************************************************************************
** Form generated from reading UI file 'centralwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTRALWIDGET_H
#define UI_CENTRALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "dxfpainter.h"

QT_BEGIN_NAMESPACE

class Ui_CentralWidget
{
public:
    QGridLayout *gridLayout;
    DxfPainter *graphicViewer;
    QHBoxLayout *horizontalLayout;
    QPushButton *newBtn;
    QPushButton *replanBtn;
    QPushButton *loadBtn;
    QPushButton *saveBtn;
    QPushButton *stopBtn;
    QPushButton *startBtn;
    QVBoxLayout *rightVLayout;
    QLabel *curPhotoViewer;
    QPushButton *cameraCtrlBtn;
    QTableView *projectItemsView;

    void setupUi(QWidget *CentralWidget)
    {
        if (CentralWidget->objectName().isEmpty())
            CentralWidget->setObjectName(QStringLiteral("CentralWidget"));
        CentralWidget->resize(1323, 703);
        gridLayout = new QGridLayout(CentralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(7, 7, 7, 7);
        graphicViewer = new DxfPainter(CentralWidget);
        graphicViewer->setObjectName(QStringLiteral("graphicViewer"));
        graphicViewer->setMinimumSize(QSize(600, 600));

        gridLayout->addWidget(graphicViewer, 0, 0, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newBtn = new QPushButton(CentralWidget);
        newBtn->setObjectName(QStringLiteral("newBtn"));

        horizontalLayout->addWidget(newBtn);

        replanBtn = new QPushButton(CentralWidget);
        replanBtn->setObjectName(QStringLiteral("replanBtn"));

        horizontalLayout->addWidget(replanBtn);

        loadBtn = new QPushButton(CentralWidget);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));

        horizontalLayout->addWidget(loadBtn);

        saveBtn = new QPushButton(CentralWidget);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));

        horizontalLayout->addWidget(saveBtn);

        stopBtn = new QPushButton(CentralWidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));

        horizontalLayout->addWidget(stopBtn);

        startBtn = new QPushButton(CentralWidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));

        horizontalLayout->addWidget(startBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        rightVLayout = new QVBoxLayout();
        rightVLayout->setSpacing(6);
        rightVLayout->setObjectName(QStringLiteral("rightVLayout"));
        curPhotoViewer = new QLabel(CentralWidget);
        curPhotoViewer->setObjectName(QStringLiteral("curPhotoViewer"));
        curPhotoViewer->setMinimumSize(QSize(700, 400));
        curPhotoViewer->setMaximumSize(QSize(700, 400));
        curPhotoViewer->setScaledContents(false);
        curPhotoViewer->setAlignment(Qt::AlignCenter);

        rightVLayout->addWidget(curPhotoViewer);

        cameraCtrlBtn = new QPushButton(CentralWidget);
        cameraCtrlBtn->setObjectName(QStringLiteral("cameraCtrlBtn"));

        rightVLayout->addWidget(cameraCtrlBtn);

        projectItemsView = new QTableView(CentralWidget);
        projectItemsView->setObjectName(QStringLiteral("projectItemsView"));
        projectItemsView->setMinimumSize(QSize(700, 200));
        projectItemsView->setMaximumSize(QSize(700, 9999));

        rightVLayout->addWidget(projectItemsView);


        gridLayout->addLayout(rightVLayout, 0, 1, 1, 1);


        retranslateUi(CentralWidget);

        QMetaObject::connectSlotsByName(CentralWidget);
    } // setupUi

    void retranslateUi(QWidget *CentralWidget)
    {
        CentralWidget->setWindowTitle(QApplication::translate("CentralWidget", "CentralWidget", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        newBtn->setToolTip(QApplication::translate("CentralWidget", "<html><head/><body><p>\351\207\215\346\226\260\345\210\266\345\256\232\346\226\271\346\241\210</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        newBtn->setText(QApplication::translate("CentralWidget", "\346\226\260\345\273\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        replanBtn->setToolTip(QApplication::translate("CentralWidget", "<html><head/><body><p>\345\210\240\351\231\244\346\211\200\346\234\211\350\267\257\345\276\204</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        replanBtn->setText(QApplication::translate("CentralWidget", "\351\207\215\350\256\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        loadBtn->setToolTip(QApplication::translate("CentralWidget", "<html><head/><body><p>\344\275\277\347\224\250\347\216\260\346\234\211\346\226\271\346\241\210</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        loadBtn->setText(QApplication::translate("CentralWidget", "\350\275\275\345\205\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveBtn->setToolTip(QApplication::translate("CentralWidget", "<html><head/><body><p>\344\277\235\345\255\230\345\275\223\345\211\215\346\226\271\346\241\210</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        saveBtn->setText(QApplication::translate("CentralWidget", "\344\277\235\345\255\230", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        stopBtn->setToolTip(QApplication::translate("CentralWidget", "<html><head/><body><p>\345\201\234\346\255\242\345\275\223\345\211\215\350\277\233\345\272\246</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        stopBtn->setText(QApplication::translate("CentralWidget", "\345\201\234\346\255\242", Q_NULLPTR));
        startBtn->setText(QApplication::translate("CentralWidget", "\345\274\200\345\247\213\357\274\2100\357\274\211", Q_NULLPTR));
        cameraCtrlBtn->setText(QApplication::translate("CentralWidget", "\347\233\270\346\234\272\346\216\247\345\210\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        projectItemsView->setToolTip(QApplication::translate("CentralWidget", "\346\226\271\346\241\210\350\257\246\346\203\205", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CentralWidget: public Ui_CentralWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTRALWIDGET_H
