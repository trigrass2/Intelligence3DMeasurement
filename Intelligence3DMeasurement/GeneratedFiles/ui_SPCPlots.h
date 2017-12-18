/********************************************************************************
** Form generated from reading UI file 'SPCPlots.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPCPLOTS_H
#define UI_SPCPLOTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_SPCPlots
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab0;
    QVBoxLayout *verticalLayout;
    QCustomPlot *plotW0_x;
    QCustomPlot *plotW0_r;
    QWidget *tab1;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *plotW1_x;
    QCustomPlot *plotW1_s;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_4;
    QCustomPlot *plotW2_xmd;
    QCustomPlot *plotW2_r;
    QWidget *tab3;
    QVBoxLayout *verticalLayout_5;
    QCustomPlot *plotW3_x;
    QCustomPlot *plotW3_rs;

    void setupUi(QDialog *SPCPlots)
    {
        if (SPCPlots->objectName().isEmpty())
            SPCPlots->setObjectName(QStringLiteral("SPCPlots"));
        SPCPlots->resize(965, 725);
        verticalLayout_2 = new QVBoxLayout(SPCPlots);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        tabWidget = new QTabWidget(SPCPlots);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab0 = new QWidget();
        tab0->setObjectName(QStringLiteral("tab0"));
        verticalLayout = new QVBoxLayout(tab0);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        plotW0_x = new QCustomPlot(tab0);
        plotW0_x->setObjectName(QStringLiteral("plotW0_x"));

        verticalLayout->addWidget(plotW0_x);

        plotW0_r = new QCustomPlot(tab0);
        plotW0_r->setObjectName(QStringLiteral("plotW0_r"));

        verticalLayout->addWidget(plotW0_r);

        tabWidget->addTab(tab0, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        verticalLayout_3 = new QVBoxLayout(tab1);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        plotW1_x = new QCustomPlot(tab1);
        plotW1_x->setObjectName(QStringLiteral("plotW1_x"));

        verticalLayout_3->addWidget(plotW1_x);

        plotW1_s = new QCustomPlot(tab1);
        plotW1_s->setObjectName(QStringLiteral("plotW1_s"));

        verticalLayout_3->addWidget(plotW1_s);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        verticalLayout_4 = new QVBoxLayout(tab2);
        verticalLayout_4->setSpacing(5);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, 5, 5, 5);
        plotW2_xmd = new QCustomPlot(tab2);
        plotW2_xmd->setObjectName(QStringLiteral("plotW2_xmd"));

        verticalLayout_4->addWidget(plotW2_xmd);

        plotW2_r = new QCustomPlot(tab2);
        plotW2_r->setObjectName(QStringLiteral("plotW2_r"));

        verticalLayout_4->addWidget(plotW2_r);

        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QStringLiteral("tab3"));
        verticalLayout_5 = new QVBoxLayout(tab3);
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        plotW3_x = new QCustomPlot(tab3);
        plotW3_x->setObjectName(QStringLiteral("plotW3_x"));

        verticalLayout_5->addWidget(plotW3_x);

        plotW3_rs = new QCustomPlot(tab3);
        plotW3_rs->setObjectName(QStringLiteral("plotW3_rs"));

        verticalLayout_5->addWidget(plotW3_rs);

        tabWidget->addTab(tab3, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(SPCPlots);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SPCPlots);
    } // setupUi

    void retranslateUi(QDialog *SPCPlots)
    {
        SPCPlots->setWindowTitle(QApplication::translate("SPCPlots", "SPCPlots", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab0), QApplication::translate("SPCPlots", "Xbar-R", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("SPCPlots", "Xbar-S", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("SPCPlots", "Xmed-R", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("SPCPlots", "X-Rs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SPCPlots: public Ui_SPCPlots {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPCPLOTS_H
