/********************************************************************************
** Form generated from reading UI file 'DatabaseBrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEBROWSER_H
#define UI_DATABASEBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_DatabaseBrowser
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *refreshBtn;
    QPushButton *queryBtn;
    QPushButton *spcBtn;
    QTreeView *tableArea;
    QGridLayout *gridLayout_2;
    QLabel *fieldLabel;
    QComboBox *fieldBox;
    QLabel *value1Label;
    QLineEdit *value1Edit;
    QLabel *value2Label;
    QLineEdit *value2Edit;
    QTableView *dataArea;

    void setupUi(QDialog *DatabaseBrowser)
    {
        if (DatabaseBrowser->objectName().isEmpty())
            DatabaseBrowser->setObjectName(QStringLiteral("DatabaseBrowser"));
        DatabaseBrowser->resize(995, 752);
        horizontalLayout = new QHBoxLayout(DatabaseBrowser);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        refreshBtn = new QPushButton(DatabaseBrowser);
        refreshBtn->setObjectName(QStringLiteral("refreshBtn"));

        gridLayout->addWidget(refreshBtn, 0, 0, 1, 1);

        queryBtn = new QPushButton(DatabaseBrowser);
        queryBtn->setObjectName(QStringLiteral("queryBtn"));

        gridLayout->addWidget(queryBtn, 0, 1, 1, 1);

        spcBtn = new QPushButton(DatabaseBrowser);
        spcBtn->setObjectName(QStringLiteral("spcBtn"));
        spcBtn->setEnabled(true);

        gridLayout->addWidget(spcBtn, 0, 2, 1, 1);

        tableArea = new QTreeView(DatabaseBrowser);
        tableArea->setObjectName(QStringLiteral("tableArea"));
        tableArea->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(tableArea, 1, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        fieldLabel = new QLabel(DatabaseBrowser);
        fieldLabel->setObjectName(QStringLiteral("fieldLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fieldLabel->sizePolicy().hasHeightForWidth());
        fieldLabel->setSizePolicy(sizePolicy);
        fieldLabel->setMinimumSize(QSize(45, 28));
        fieldLabel->setMaximumSize(QSize(45, 28));

        gridLayout_2->addWidget(fieldLabel, 0, 0, 1, 1);

        fieldBox = new QComboBox(DatabaseBrowser);
        fieldBox->setObjectName(QStringLiteral("fieldBox"));
        fieldBox->setMinimumSize(QSize(180, 28));
        fieldBox->setMaximumSize(QSize(16777215, 28));

        gridLayout_2->addWidget(fieldBox, 0, 1, 1, 1);

        value1Label = new QLabel(DatabaseBrowser);
        value1Label->setObjectName(QStringLiteral("value1Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(value1Label->sizePolicy().hasHeightForWidth());
        value1Label->setSizePolicy(sizePolicy1);
        value1Label->setMinimumSize(QSize(50, 28));
        value1Label->setMaximumSize(QSize(50, 28));

        gridLayout_2->addWidget(value1Label, 0, 2, 1, 1);

        value1Edit = new QLineEdit(DatabaseBrowser);
        value1Edit->setObjectName(QStringLiteral("value1Edit"));
        value1Edit->setMinimumSize(QSize(0, 28));
        value1Edit->setMaximumSize(QSize(16777215, 28));

        gridLayout_2->addWidget(value1Edit, 0, 3, 1, 1);

        value2Label = new QLabel(DatabaseBrowser);
        value2Label->setObjectName(QStringLiteral("value2Label"));
        sizePolicy1.setHeightForWidth(value2Label->sizePolicy().hasHeightForWidth());
        value2Label->setSizePolicy(sizePolicy1);
        value2Label->setMinimumSize(QSize(50, 28));
        value2Label->setMaximumSize(QSize(50, 28));

        gridLayout_2->addWidget(value2Label, 0, 4, 1, 1);

        value2Edit = new QLineEdit(DatabaseBrowser);
        value2Edit->setObjectName(QStringLiteral("value2Edit"));
        value2Edit->setMinimumSize(QSize(0, 28));
        value2Edit->setMaximumSize(QSize(16777215, 28));

        gridLayout_2->addWidget(value2Edit, 0, 5, 1, 1);

        dataArea = new QTableView(DatabaseBrowser);
        dataArea->setObjectName(QStringLiteral("dataArea"));

        gridLayout_2->addWidget(dataArea, 1, 0, 1, 6);


        horizontalLayout->addLayout(gridLayout_2);

#ifndef QT_NO_SHORTCUT
        fieldLabel->setBuddy(fieldBox);
        value1Label->setBuddy(value1Edit);
        value2Label->setBuddy(value2Edit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(fieldBox, value1Edit);
        QWidget::setTabOrder(value1Edit, value2Edit);
        QWidget::setTabOrder(value2Edit, tableArea);

        retranslateUi(DatabaseBrowser);

        QMetaObject::connectSlotsByName(DatabaseBrowser);
    } // setupUi

    void retranslateUi(QDialog *DatabaseBrowser)
    {
        DatabaseBrowser->setWindowTitle(QApplication::translate("DatabaseBrowser", "\350\256\260\345\275\225\346\237\245\350\257\242", Q_NULLPTR));
        refreshBtn->setText(QApplication::translate("DatabaseBrowser", "\345\210\267\346\226\260", Q_NULLPTR));
        queryBtn->setText(QApplication::translate("DatabaseBrowser", "\346\237\245\350\257\242", Q_NULLPTR));
        spcBtn->setText(QApplication::translate("DatabaseBrowser", "SPC", Q_NULLPTR));
        fieldLabel->setText(QApplication::translate("DatabaseBrowser", " \345\255\227\346\256\265\357\274\232", Q_NULLPTR));
        value1Label->setText(QApplication::translate("DatabaseBrowser", "\345\267\246\345\200\274\357\274\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        value1Edit->setToolTip(QApplication::translate("DatabaseBrowser", "<html><head/><body><p><span style=\" font-weight:600;\">Synax:</span></p><p>\346\225\260\345\200\274\347\261\273\345\236\213\347\233\264\346\216\245\350\276\223\345\205\245</p><p>\345\255\227\347\254\246\347\261\273\345\236\213\351\234\200\345\212\240\345\215\225\345\274\225\345\217\267</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        value1Edit->setText(QString());
        value2Label->setText(QApplication::translate("DatabaseBrowser", "\345\217\263\345\200\274\357\274\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        value2Edit->setToolTip(QApplication::translate("DatabaseBrowser", "<html><head/><body><p><span style=\" font-weight:600;\">Synax:</span></p><p>\346\225\260\345\200\274\347\261\273\345\236\213\347\233\264\346\216\245\350\276\223\345\205\245</p><p>\345\255\227\347\254\246\347\261\273\345\236\213\351\234\200\345\212\240\345\215\225\345\274\225\345\217\267</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        value2Edit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DatabaseBrowser: public Ui_DatabaseBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEBROWSER_H
