/********************************************************************************
** Form generated from reading UI file 'LaserPortCfgDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASERPORTCFGDLG_H
#define UI_LASERPORTCFGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LaserPortCfgDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *baudRateLabel;
    QComboBox *baudRateComboBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsComboBox;
    QLabel *parityLabel;
    QComboBox *parityComboBox;
    QLabel *stopBitLabel;
    QComboBox *stopBitsComboBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *readBtn;
    QLineEdit *testShowEdit;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *laserBiasX;
    QDoubleSpinBox *laserBiasY;
    QLineEdit *nameLineEdit;

    void setupUi(QDialog *LaserPortCfgDlg)
    {
        if (LaserPortCfgDlg->objectName().isEmpty())
            LaserPortCfgDlg->setObjectName(QStringLiteral("LaserPortCfgDlg"));
        LaserPortCfgDlg->resize(352, 203);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LaserPortCfgDlg->sizePolicy().hasHeightForWidth());
        LaserPortCfgDlg->setSizePolicy(sizePolicy);
        LaserPortCfgDlg->setMinimumSize(QSize(352, 203));
        LaserPortCfgDlg->setMaximumSize(QSize(352, 203));
        gridLayout = new QGridLayout(LaserPortCfgDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(LaserPortCfgDlg);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        sizePolicy.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy);
        nameLabel->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        baudRateLabel = new QLabel(LaserPortCfgDlg);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        gridLayout->addWidget(baudRateLabel, 1, 0, 1, 1);

        baudRateComboBox = new QComboBox(LaserPortCfgDlg);
        baudRateComboBox->setObjectName(QStringLiteral("baudRateComboBox"));
        baudRateComboBox->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(baudRateComboBox->sizePolicy().hasHeightForWidth());
        baudRateComboBox->setSizePolicy(sizePolicy1);
        baudRateComboBox->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(baudRateComboBox, 1, 1, 1, 1);

        dataBitsLabel = new QLabel(LaserPortCfgDlg);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));
        dataBitsLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(dataBitsLabel, 1, 2, 1, 1);

        dataBitsComboBox = new QComboBox(LaserPortCfgDlg);
        dataBitsComboBox->setObjectName(QStringLiteral("dataBitsComboBox"));
        dataBitsComboBox->setEnabled(false);
        sizePolicy1.setHeightForWidth(dataBitsComboBox->sizePolicy().hasHeightForWidth());
        dataBitsComboBox->setSizePolicy(sizePolicy1);
        dataBitsComboBox->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(dataBitsComboBox, 1, 3, 1, 1);

        parityLabel = new QLabel(LaserPortCfgDlg);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));

        gridLayout->addWidget(parityLabel, 2, 0, 1, 1);

        parityComboBox = new QComboBox(LaserPortCfgDlg);
        parityComboBox->setObjectName(QStringLiteral("parityComboBox"));
        parityComboBox->setEnabled(false);
        sizePolicy1.setHeightForWidth(parityComboBox->sizePolicy().hasHeightForWidth());
        parityComboBox->setSizePolicy(sizePolicy1);
        parityComboBox->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(parityComboBox, 2, 1, 1, 1);

        stopBitLabel = new QLabel(LaserPortCfgDlg);
        stopBitLabel->setObjectName(QStringLiteral("stopBitLabel"));
        stopBitLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(stopBitLabel, 2, 2, 1, 1);

        stopBitsComboBox = new QComboBox(LaserPortCfgDlg);
        stopBitsComboBox->setObjectName(QStringLiteral("stopBitsComboBox"));
        stopBitsComboBox->setEnabled(false);
        sizePolicy1.setHeightForWidth(stopBitsComboBox->sizePolicy().hasHeightForWidth());
        stopBitsComboBox->setSizePolicy(sizePolicy1);
        stopBitsComboBox->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(stopBitsComboBox, 2, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        readBtn = new QPushButton(LaserPortCfgDlg);
        readBtn->setObjectName(QStringLiteral("readBtn"));

        horizontalLayout_3->addWidget(readBtn);

        testShowEdit = new QLineEdit(LaserPortCfgDlg);
        testShowEdit->setObjectName(QStringLiteral("testShowEdit"));
        testShowEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(testShowEdit);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 4);

        groupBox = new QGroupBox(LaserPortCfgDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        laserBiasX = new QDoubleSpinBox(groupBox);
        laserBiasX->setObjectName(QStringLiteral("laserBiasX"));
        laserBiasX->setAlignment(Qt::AlignCenter);
        laserBiasX->setAccelerated(true);
        laserBiasX->setDecimals(0);
        laserBiasX->setMaximum(100000);

        horizontalLayout->addWidget(laserBiasX);

        laserBiasY = new QDoubleSpinBox(groupBox);
        laserBiasY->setObjectName(QStringLiteral("laserBiasY"));
        laserBiasY->setAlignment(Qt::AlignCenter);
        laserBiasY->setAccelerated(true);
        laserBiasY->setDecimals(0);
        laserBiasY->setMaximum(100000);

        horizontalLayout->addWidget(laserBiasY);


        gridLayout->addWidget(groupBox, 4, 0, 1, 4);

        nameLineEdit = new QLineEdit(LaserPortCfgDlg);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setAlignment(Qt::AlignCenter);
        nameLineEdit->setReadOnly(true);

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 3);

#ifndef QT_NO_SHORTCUT
        baudRateLabel->setBuddy(baudRateComboBox);
        dataBitsLabel->setBuddy(dataBitsComboBox);
        parityLabel->setBuddy(parityComboBox);
        stopBitLabel->setBuddy(stopBitsComboBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(baudRateComboBox, dataBitsComboBox);
        QWidget::setTabOrder(dataBitsComboBox, parityComboBox);
        QWidget::setTabOrder(parityComboBox, stopBitsComboBox);
        QWidget::setTabOrder(stopBitsComboBox, readBtn);
        QWidget::setTabOrder(readBtn, testShowEdit);

        retranslateUi(LaserPortCfgDlg);

        QMetaObject::connectSlotsByName(LaserPortCfgDlg);
    } // setupUi

    void retranslateUi(QDialog *LaserPortCfgDlg)
    {
        LaserPortCfgDlg->setWindowTitle(QApplication::translate("LaserPortCfgDlg", "\346\277\200\345\205\211\344\274\240\346\204\237\345\231\250\351\205\215\347\275\256", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("LaserPortCfgDlg", "\344\270\262\345\217\243\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        baudRateLabel->setText(QApplication::translate("LaserPortCfgDlg", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        baudRateComboBox->clear();
        baudRateComboBox->insertItems(0, QStringList()
         << QApplication::translate("LaserPortCfgDlg", "9600", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "19200", Q_NULLPTR)
        );
        dataBitsLabel->setText(QApplication::translate("LaserPortCfgDlg", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        dataBitsComboBox->clear();
        dataBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("LaserPortCfgDlg", "8", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "7", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "6", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "5", Q_NULLPTR)
        );
        parityLabel->setText(QApplication::translate("LaserPortCfgDlg", "\345\245\207\345\201\266\346\240\241\351\252\214\357\274\232", Q_NULLPTR));
        parityComboBox->clear();
        parityComboBox->insertItems(0, QStringList()
         << QApplication::translate("LaserPortCfgDlg", "None", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "Even", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "Odd", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "Space", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "Mark", Q_NULLPTR)
        );
        stopBitLabel->setText(QApplication::translate("LaserPortCfgDlg", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        stopBitsComboBox->clear();
        stopBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("LaserPortCfgDlg", "1", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "1.5", Q_NULLPTR)
         << QApplication::translate("LaserPortCfgDlg", "2", Q_NULLPTR)
        );
        readBtn->setText(QApplication::translate("LaserPortCfgDlg", "\350\257\273\345\217\226\346\265\213\350\257\225", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("LaserPortCfgDlg", "\346\277\200\345\205\211\345\244\264\345\235\220\346\240\207\345\201\217\345\267\256", Q_NULLPTR));
        laserBiasX->setPrefix(QApplication::translate("LaserPortCfgDlg", "\316\224X=", Q_NULLPTR));
        laserBiasX->setSuffix(QApplication::translate("LaserPortCfgDlg", "p", Q_NULLPTR));
        laserBiasY->setPrefix(QApplication::translate("LaserPortCfgDlg", "\316\224Y=", Q_NULLPTR));
        laserBiasY->setSuffix(QApplication::translate("LaserPortCfgDlg", "p", Q_NULLPTR));
        nameLineEdit->setText(QApplication::translate("LaserPortCfgDlg", "Unaccessible", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LaserPortCfgDlg: public Ui_LaserPortCfgDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASERPORTCFGDLG_H
