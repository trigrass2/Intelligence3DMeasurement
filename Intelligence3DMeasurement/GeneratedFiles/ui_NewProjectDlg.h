/********************************************************************************
** Form generated from reading UI file 'NewProjectDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDLG_H
#define UI_NEWPROJECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewProjectDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *cadPath;
    QPushButton *cadFileChsBtn;
    QLineEdit *projectName;
    QGridLayout *gridLayout_2;
    QLineEdit *partName;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *productModel;
    QLabel *label_8;
    QLineEdit *manufactory;
    QLineEdit *orderNumber;
    QLabel *label_4;
    QLineEdit *processName;
    QLineEdit *station;
    QLabel *label_5;
    QDateEdit *productionDate;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *abortBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *confirmBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *NewProjectDlg)
    {
        if (NewProjectDlg->objectName().isEmpty())
            NewProjectDlg->setObjectName(QStringLiteral("NewProjectDlg"));
        NewProjectDlg->resize(565, 228);
        NewProjectDlg->setMinimumSize(QSize(565, 228));
        NewProjectDlg->setMaximumSize(QSize(565, 228));
        verticalLayout = new QVBoxLayout(NewProjectDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(NewProjectDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(NewProjectDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cadPath = new QLineEdit(NewProjectDlg);
        cadPath->setObjectName(QStringLiteral("cadPath"));
        cadPath->setReadOnly(true);
        cadPath->setClearButtonEnabled(false);

        horizontalLayout->addWidget(cadPath);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        cadFileChsBtn = new QPushButton(NewProjectDlg);
        cadFileChsBtn->setObjectName(QStringLiteral("cadFileChsBtn"));
        cadFileChsBtn->setMinimumSize(QSize(30, 24));
        cadFileChsBtn->setMaximumSize(QSize(30, 24));
        cadFileChsBtn->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cadFileChsBtn, 1, 2, 1, 1);

        projectName = new QLineEdit(NewProjectDlg);
        projectName->setObjectName(QStringLiteral("projectName"));
        projectName->setClearButtonEnabled(true);

        gridLayout->addWidget(projectName, 0, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        partName = new QLineEdit(NewProjectDlg);
        partName->setObjectName(QStringLiteral("partName"));

        gridLayout_2->addWidget(partName, 0, 1, 1, 3);

        label_6 = new QLabel(NewProjectDlg);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_9 = new QLabel(NewProjectDlg);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 1, 2, 1, 1);

        label_3 = new QLabel(NewProjectDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_7 = new QLabel(NewProjectDlg);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        productModel = new QLineEdit(NewProjectDlg);
        productModel->setObjectName(QStringLiteral("productModel"));

        gridLayout_2->addWidget(productModel, 1, 1, 1, 1);

        label_8 = new QLabel(NewProjectDlg);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 3, 2, 1, 1);

        manufactory = new QLineEdit(NewProjectDlg);
        manufactory->setObjectName(QStringLiteral("manufactory"));

        gridLayout_2->addWidget(manufactory, 2, 1, 1, 1);

        orderNumber = new QLineEdit(NewProjectDlg);
        orderNumber->setObjectName(QStringLiteral("orderNumber"));

        gridLayout_2->addWidget(orderNumber, 1, 3, 1, 1);

        label_4 = new QLabel(NewProjectDlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 2, 1, 1);

        processName = new QLineEdit(NewProjectDlg);
        processName->setObjectName(QStringLiteral("processName"));

        gridLayout_2->addWidget(processName, 3, 1, 1, 1);

        station = new QLineEdit(NewProjectDlg);
        station->setObjectName(QStringLiteral("station"));

        gridLayout_2->addWidget(station, 3, 3, 1, 1);

        label_5 = new QLabel(NewProjectDlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        productionDate = new QDateEdit(NewProjectDlg);
        productionDate->setObjectName(QStringLiteral("productionDate"));
        productionDate->setAlignment(Qt::AlignCenter);
        productionDate->setReadOnly(false);
        productionDate->setDateTime(QDateTime(QDate(2017, 1, 1), QTime(0, 0, 0)));
        productionDate->setCalendarPopup(true);

        gridLayout_2->addWidget(productionDate, 2, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        abortBtn = new QPushButton(NewProjectDlg);
        abortBtn->setObjectName(QStringLiteral("abortBtn"));

        horizontalLayout_3->addWidget(abortBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        confirmBtn = new QPushButton(NewProjectDlg);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));

        horizontalLayout_3->addWidget(confirmBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_3, 4, 0, 1, 4);


        verticalLayout->addLayout(gridLayout_2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(projectName);
        label_2->setBuddy(cadPath);
        label_6->setBuddy(productModel);
        label_9->setBuddy(orderNumber);
        label_3->setBuddy(manufactory);
        label_7->setBuddy(processName);
        label_8->setBuddy(station);
        label_4->setBuddy(productionDate);
        label_5->setBuddy(partName);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(projectName, cadPath);
        QWidget::setTabOrder(cadPath, partName);
        QWidget::setTabOrder(partName, productModel);
        QWidget::setTabOrder(productModel, orderNumber);
        QWidget::setTabOrder(orderNumber, manufactory);
        QWidget::setTabOrder(manufactory, productionDate);
        QWidget::setTabOrder(productionDate, processName);
        QWidget::setTabOrder(processName, station);
        QWidget::setTabOrder(station, abortBtn);
        QWidget::setTabOrder(abortBtn, confirmBtn);

        retranslateUi(NewProjectDlg);

        QMetaObject::connectSlotsByName(NewProjectDlg);
    } // setupUi

    void retranslateUi(QDialog *NewProjectDlg)
    {
        NewProjectDlg->setWindowTitle(QApplication::translate("NewProjectDlg", "\346\226\260\345\273\272\351\241\271\347\233\256", Q_NULLPTR));
        label->setText(QApplication::translate("NewProjectDlg", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("NewProjectDlg", "CAD\346\226\207\344\273\266\357\274\232", Q_NULLPTR));
        cadFileChsBtn->setText(QApplication::translate("NewProjectDlg", "...", Q_NULLPTR));
        label_6->setText(QApplication::translate("NewProjectDlg", "\344\272\247\345\223\201\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("NewProjectDlg", "\350\256\242\345\215\225\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("NewProjectDlg", "\347\224\237\344\272\247\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("NewProjectDlg", "\345\267\245\345\272\217\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("NewProjectDlg", "\345\267\245\344\275\215\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("NewProjectDlg", "\347\224\237\344\272\247\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("NewProjectDlg", "\351\233\266\344\273\266\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        productionDate->setDisplayFormat(QApplication::translate("NewProjectDlg", "yyyy-MM-dd", Q_NULLPTR));
        abortBtn->setText(QApplication::translate("NewProjectDlg", "\346\224\276\345\274\203", Q_NULLPTR));
        confirmBtn->setText(QApplication::translate("NewProjectDlg", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewProjectDlg: public Ui_NewProjectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDLG_H
