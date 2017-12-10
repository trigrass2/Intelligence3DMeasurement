#ifndef SPCWIDGET_H
#define SPCWIDGET_H

#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>
#include <QCloseEvent>
#include "qcustomplot.h"

class SPCWidget : public QDialog
{
    Q_OBJECT

public:
    SPCWidget(QWidget *parent = 0);
    ~SPCWidget();
    void drawXSctrl(QVector<double> id, QVector<double> mean, QVector<double> s, int vol); // 画X-S控制图(子组均值,子组方差,子组容量)
    void drawXRctrl(QVector<double> id, QVector<double> mean, QVector<double> r, int vol); // 画X-R控制图(子组均值,子组极差,子组容量)

private:
    QTextEdit *info1;
    QTextEdit *info2;
    QGridLayout *mainLayout;
    //画笔参数
    void initPen();
    QPen valuePen;
    QPen CLPen;
    QPen ULPen;
    //控制限系数
    void initFactor();
    QVarLengthArray<double> _d2,D3,D4,A2,A3,_C4,B3,B4,B7,B8;
    double getMeanValue(QVector<double> data); //求平均值

};

#endif // SPCWIDGET_H
