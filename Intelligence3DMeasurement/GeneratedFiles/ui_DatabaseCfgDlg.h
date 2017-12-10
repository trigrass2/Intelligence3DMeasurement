/********************************************************************************
** Form generated from reading UI file 'DatabaseCfgDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASECFGDLG_H
#define UI_DATABASECFGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DatabaseCfgDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *driverLabel;
    QComboBox *driverComboBox;
    QLabel *hostLabel;
    QLineEdit *hostLineEdit;
    QLabel *dbNameLabel;
    QLineEdit *dbLineEdit;
    QLabel *portLabel;
    QSpinBox *portSpinBox;
    QLabel *userLabel;
    QLineEdit *userLineEdit;
    QLabel *pwdLabel;
    QLineEdit *pwdLineEdit;

    void setupUi(QDialog *DatabaseCfgDlg)
    {
        if (DatabaseCfgDlg->objectName().isEmpty())
            DatabaseCfgDlg->setObjectName(QStringLiteral("DatabaseCfgDlg"));
        DatabaseCfgDlg->resize(269, 269);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DatabaseCfgDlg->sizePolicy().hasHeightForWidth());
        DatabaseCfgDlg->setSizePolicy(sizePolicy);
        DatabaseCfgDlg->setMinimumSize(QSize(269, 269));
        DatabaseCfgDlg->setMaximumSize(QSize(269, 269));
        gridLayout = new QGridLayout(DatabaseCfgDlg);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, -1, 20, -1);
        driverLabel = new QLabel(DatabaseCfgDlg);
        driverLabel->setObjectName(QStringLiteral("driverLabel"));

        gridLayout->addWidget(driverLabel, 0, 0, 1, 1);

        driverComboBox = new QComboBox(DatabaseCfgDlg);
        driverComboBox->setObjectName(QStringLiteral("driverComboBox"));
        driverComboBox->setEnabled(false);
        driverComboBox->setLayoutDirection(Qt::LeftToRight);
        driverComboBox->setAutoFillBackground(false);
        driverComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(driverComboBox, 0, 1, 1, 1);

        hostLabel = new QLabel(DatabaseCfgDlg);
        hostLabel->setObjectName(QStringLiteral("hostLabel"));

        gridLayout->addWidget(hostLabel, 1, 0, 1, 1);

        hostLineEdit = new QLineEdit(DatabaseCfgDlg);
        hostLineEdit->setObjectName(QStringLiteral("hostLineEdit"));
        hostLineEdit->setEnabled(false);
        hostLineEdit->setAlignment(Qt::AlignCenter);
        hostLineEdit->setReadOnly(false);

        gridLayout->addWidget(hostLineEdit, 1, 1, 1, 1);

        dbNameLabel = new QLabel(DatabaseCfgDlg);
        dbNameLabel->setObjectName(QStringLiteral("dbNameLabel"));

        gridLayout->addWidget(dbNameLabel, 2, 0, 1, 1);

        dbLineEdit = new QLineEdit(DatabaseCfgDlg);
        dbLineEdit->setObjectName(QStringLiteral("dbLineEdit"));
        dbLineEdit->setAlignment(Qt::AlignCenter);
        dbLineEdit->setReadOnly(false);

        gridLayout->addWidget(dbLineEdit, 2, 1, 1, 1);

        portLabel = new QLabel(DatabaseCfgDlg);
        portLabel->setObjectName(QStringLiteral("portLabel"));

        gridLayout->addWidget(portLabel, 3, 0, 1, 1);

        portSpinBox = new QSpinBox(DatabaseCfgDlg);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setEnabled(true);
        portSpinBox->setAlignment(Qt::AlignCenter);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(3306);

        gridLayout->addWidget(portSpinBox, 3, 1, 1, 1);

        userLabel = new QLabel(DatabaseCfgDlg);
        userLabel->setObjectName(QStringLiteral("userLabel"));

        gridLayout->addWidget(userLabel, 4, 0, 1, 1);

        userLineEdit = new QLineEdit(DatabaseCfgDlg);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setAlignment(Qt::AlignCenter);
        userLineEdit->setReadOnly(false);

        gridLayout->addWidget(userLineEdit, 4, 1, 1, 1);

        pwdLabel = new QLabel(DatabaseCfgDlg);
        pwdLabel->setObjectName(QStringLiteral("pwdLabel"));

        gridLayout->addWidget(pwdLabel, 5, 0, 1, 1);

        pwdLineEdit = new QLineEdit(DatabaseCfgDlg);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setMaxLength(20);
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        pwdLineEdit->setAlignment(Qt::AlignCenter);
        pwdLineEdit->setReadOnly(false);

        gridLayout->addWidget(pwdLineEdit, 5, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        driverLabel->setBuddy(driverComboBox);
        hostLabel->setBuddy(hostLineEdit);
        dbNameLabel->setBuddy(dbLineEdit);
        portLabel->setBuddy(portSpinBox);
        userLabel->setBuddy(userLineEdit);
        pwdLabel->setBuddy(pwdLineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(driverComboBox, hostLineEdit);
        QWidget::setTabOrder(hostLineEdit, dbLineEdit);
        QWidget::setTabOrder(dbLineEdit, portSpinBox);
        QWidget::setTabOrder(portSpinBox, userLineEdit);
        QWidget::setTabOrder(userLineEdit, pwdLineEdit);

        retranslateUi(DatabaseCfgDlg);

        driverComboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DatabaseCfgDlg);
    } // setupUi

    void retranslateUi(QDialog *DatabaseCfgDlg)
    {
        DatabaseCfgDlg->setWindowTitle(QApplication::translate("DatabaseCfgDlg", "\346\225\260\346\215\256\345\272\223\351\205\215\347\275\256", Q_NULLPTR));
        driverLabel->setText(QApplication::translate("DatabaseCfgDlg", "\346\225\260\346\215\256\345\272\223\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        driverComboBox->clear();
        driverComboBox->insertItems(0, QStringList()
         << QApplication::translate("DatabaseCfgDlg", "QSQLITE", Q_NULLPTR)
         << QApplication::translate("DatabaseCfgDlg", "QMYSQL", Q_NULLPTR)
         << QApplication::translate("DatabaseCfgDlg", "QMYSQL3", Q_NULLPTR)
         << QApplication::translate("DatabaseCfgDlg", "QODBC", Q_NULLPTR)
         << QApplication::translate("DatabaseCfgDlg", "QODBC3", Q_NULLPTR)
         << QApplication::translate("DatabaseCfgDlg", "QPSQL", Q_NULLPTR)
         << QApplication::translate("DatabaseCfgDlg", "QPSQL7", Q_NULLPTR)
        );
        hostLabel->setText(QApplication::translate("DatabaseCfgDlg", "\344\270\273\346\234\272\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        hostLineEdit->setText(QApplication::translate("DatabaseCfgDlg", "localhost", Q_NULLPTR));
        dbNameLabel->setText(QApplication::translate("DatabaseCfgDlg", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", Q_NULLPTR));
        dbLineEdit->setText(QApplication::translate("DatabaseCfgDlg", "testdb", Q_NULLPTR));
        portLabel->setText(QApplication::translate("DatabaseCfgDlg", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        userLabel->setText(QApplication::translate("DatabaseCfgDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        userLineEdit->setText(QApplication::translate("DatabaseCfgDlg", "testuser", Q_NULLPTR));
        pwdLabel->setText(QApplication::translate("DatabaseCfgDlg", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pwdLineEdit->setText(QApplication::translate("DatabaseCfgDlg", "431134", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseCfgDlg: public Ui_DatabaseCfgDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASECFGDLG_H
