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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseBrowser
{
public:
    QGridLayout *gridLayout;
    QPushButton *refreshBtn;
    QPushButton *queryBtn;
    QLabel *fieldLabel;
    QComboBox *fieldBox;
    QLabel *value1Label;
    QLineEdit *value1Edit;
    QLabel *value2Label;
    QLineEdit *value2Edit;
    QTreeView *tableArea;
    QTableView *dataArea;
    QPushButton *exportBtn;
    QPushButton *spcBtn;

    void setupUi(QWidget *DatabaseBrowser)
    {
        if (DatabaseBrowser->objectName().isEmpty())
            DatabaseBrowser->setObjectName(QStringLiteral("DatabaseBrowser"));
        DatabaseBrowser->resize(995, 752);
        gridLayout = new QGridLayout(DatabaseBrowser);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        refreshBtn = new QPushButton(DatabaseBrowser);
        refreshBtn->setObjectName(QStringLiteral("refreshBtn"));

        gridLayout->addWidget(refreshBtn, 0, 0, 1, 1);

        queryBtn = new QPushButton(DatabaseBrowser);
        queryBtn->setObjectName(QStringLiteral("queryBtn"));

        gridLayout->addWidget(queryBtn, 0, 1, 1, 1);

        fieldLabel = new QLabel(DatabaseBrowser);
        fieldLabel->setObjectName(QStringLiteral("fieldLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fieldLabel->sizePolicy().hasHeightForWidth());
        fieldLabel->setSizePolicy(sizePolicy);
        fieldLabel->setMinimumSize(QSize(45, 0));
        fieldLabel->setMaximumSize(QSize(45, 16777215));

        gridLayout->addWidget(fieldLabel, 0, 2, 1, 1);

        fieldBox = new QComboBox(DatabaseBrowser);
        fieldBox->setObjectName(QStringLiteral("fieldBox"));
        fieldBox->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(fieldBox, 0, 3, 1, 1);

        value1Label = new QLabel(DatabaseBrowser);
        value1Label->setObjectName(QStringLiteral("value1Label"));
        sizePolicy.setHeightForWidth(value1Label->sizePolicy().hasHeightForWidth());
        value1Label->setSizePolicy(sizePolicy);
        value1Label->setMinimumSize(QSize(50, 0));
        value1Label->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(value1Label, 0, 4, 1, 1);

        value1Edit = new QLineEdit(DatabaseBrowser);
        value1Edit->setObjectName(QStringLiteral("value1Edit"));

        gridLayout->addWidget(value1Edit, 0, 5, 1, 1);

        value2Label = new QLabel(DatabaseBrowser);
        value2Label->setObjectName(QStringLiteral("value2Label"));
        sizePolicy.setHeightForWidth(value2Label->sizePolicy().hasHeightForWidth());
        value2Label->setSizePolicy(sizePolicy);
        value2Label->setMinimumSize(QSize(50, 0));
        value2Label->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(value2Label, 0, 6, 1, 1);

        value2Edit = new QLineEdit(DatabaseBrowser);
        value2Edit->setObjectName(QStringLiteral("value2Edit"));

        gridLayout->addWidget(value2Edit, 0, 7, 1, 1);

        tableArea = new QTreeView(DatabaseBrowser);
        tableArea->setObjectName(QStringLiteral("tableArea"));
        tableArea->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(tableArea, 1, 0, 1, 2);

        dataArea = new QTableView(DatabaseBrowser);
        dataArea->setObjectName(QStringLiteral("dataArea"));

        gridLayout->addWidget(dataArea, 1, 2, 2, 6);

        exportBtn = new QPushButton(DatabaseBrowser);
        exportBtn->setObjectName(QStringLiteral("exportBtn"));

        gridLayout->addWidget(exportBtn, 2, 0, 1, 1);

        spcBtn = new QPushButton(DatabaseBrowser);
        spcBtn->setObjectName(QStringLiteral("spcBtn"));

        gridLayout->addWidget(spcBtn, 2, 1, 1, 1);

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

    void retranslateUi(QWidget *DatabaseBrowser)
    {
        DatabaseBrowser->setWindowTitle(QApplication::translate("DatabaseBrowser", "\350\256\260\345\275\225\346\237\245\350\257\242", Q_NULLPTR));
        refreshBtn->setText(QApplication::translate("DatabaseBrowser", "\345\210\267\346\226\260", Q_NULLPTR));
        queryBtn->setText(QApplication::translate("DatabaseBrowser", "\346\237\245\350\257\242", Q_NULLPTR));
        fieldLabel->setText(QApplication::translate("DatabaseBrowser", " \345\255\227\346\256\265\357\274\232", Q_NULLPTR));
        value1Label->setText(QApplication::translate("DatabaseBrowser", "  \345\200\2741\357\274\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        value1Edit->setToolTip(QApplication::translate("DatabaseBrowser", "<html><head/><body><p><span style=\" font-weight:600;\">Synax:</span></p><p>[<span style=\" font-style:italic;\">value1, +\342\210\236)</span></p><p>(-<span style=\" font-style:italic;\">\342\210\236, value2]</span></p><p>[<span style=\" font-style:italic;\">value1, value2]</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        value1Edit->setText(QString());
        value2Label->setText(QApplication::translate("DatabaseBrowser", "  \345\200\2742\357\274\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        value2Edit->setToolTip(QApplication::translate("DatabaseBrowser", "<html><head/><body><p><span style=\" font-weight:600;\">Synax:</span></p><p>[<span style=\" font-style:italic;\">value1, +\342\210\236)</span></p><p>(-<span style=\" font-style:italic;\">\342\210\236, value2]</span></p><p>[<span style=\" font-style:italic;\">value1, value2]</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        value2Edit->setText(QString());
        exportBtn->setText(QApplication::translate("DatabaseBrowser", "\345\257\274\345\207\272", Q_NULLPTR));
        spcBtn->setText(QApplication::translate("DatabaseBrowser", "SPC", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseBrowser: public Ui_DatabaseBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEBROWSER_H
