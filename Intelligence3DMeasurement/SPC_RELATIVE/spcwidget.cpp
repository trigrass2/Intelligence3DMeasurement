#include "spcwidget.h"

SPCWidget::SPCWidget(QWidget *parent)
    : QDialog(parent)
{
    this->setAttribute(Qt::WA_QuitOnClose, false);
    info1 = new QTextEdit;
    info2 = new QTextEdit;
    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    setFixedSize(800,600);
    initPen();
    initFactor();
}
SPCWidget::~SPCWidget(){
    delete info1;
    delete info2;
}

//***PRIVATE***
void SPCWidget::initPen()
{
    //上下控制线
    ULPen.setWidthF(1.3);
    ULPen.setColor(QColor(255,0,0));
    ULPen.setStyle(Qt::DotLine);
    //中心控制线
    CLPen.setWidthF(1.3);
    CLPen.setColor(QColor(0,255,0));
    CLPen.setStyle(Qt::DashLine);
    //记录线
    valuePen.setWidthF(1.3);
    valuePen.setColor(QColor(0,0,255));
}
void SPCWidget::initFactor()
{
    //SPC控制系数表
    _d2.append(0.8862f); // 2
    _d2.append(0.5908f); // 3
    _d2.append(0.4857f); // 4
    _d2.append(0.4299f); // 5
    _d2.append(0.3946f); // 6
    _d2.append(0.3698f); // 7
    _d2.append(0.3512f); // 8
    _d2.append(0.3367f); // 9
    _d2.append(0.3248f); // 10
    D3.append(0.076f); // 7
    D3.append(0.136f); // 8
    D3.append(0.184f); // 9
    D3.append(0.223f); // 10
    D4.append(3.267f); // 2
    D4.append(2.579f); // 3
    D4.append(2.282f); // 4
    D4.append(2.115f); // 5
    D4.append(2.004f); // 6
    D4.append(1.924f); // 7
    D4.append(1.864f); // 8
    D4.append(1.816f); // 9
    D4.append(1.777f); // 10
    A2.append(1.880f); // 2
    A2.append(1.023f); // 3
    A2.append(0.729f); // 4
    A2.append(0.577f); // 5
    A2.append(0.483f); // 6
    A2.append(0.419f); // 7
    A2.append(0.373f); // 8
    A2.append(0.337f); // 9
    A2.append(0.308f); // 10
    A3.append(2.659f); // 2
    A3.append(1.954f); // 3
    A3.append(1.628f); // 4
    A3.append(1.427f); // 5
    A3.append(1.287f); // 6
    A3.append(1.182f); // 7
    A3.append(1.099f); // 8
    A3.append(1.032f); // 9
    A3.append(0.973f); // 10
    _C4.append(1.2533f); // 2
    _C4.append(1.1284f); // 3
    _C4.append(1.0854f); // 4
    _C4.append(1.0638f); // 5
    _C4.append(1.0510f); // 6
    _C4.append(1.0423f); // 7
    _C4.append(1.0363f); // 8
    _C4.append(1.0317f); // 9
    _C4.append(1.0281f); // 10
    B3.append(0.030f); // 6
    B3.append(0.118f); // 7
    B3.append(0.185f); // 8
    B3.append(0.239f); // 9
    B3.append(0.284f); // 10
    B4.append(3.267f); // 2
    B4.append(2.568f); // 3
    B4.append(2.266f); // 4
    B4.append(2.089f); // 5
    B4.append(1.970f); // 6
    B4.append(1.882f); // 7
    B4.append(1.815f); // 8
    B4.append(1.761f); // 9
    B4.append(1.716f); // 10
    B7.append(0.026f); // 5
    B7.append(0.115f); // 6
    B7.append(0.183f); // 7
    B7.append(0.237f); // 8
    B7.append(0.283f); // 9
    B7.append(0.321f); // 10
    B8.append(2.603f); // 2
    B8.append(2.281f); // 3
    B8.append(2.096f); // 4
    B8.append(1.974f); // 5
    B8.append(1.885f); // 6
    B8.append(1.817f); // 7
    B8.append(1.763f); // 8
    B8.append(1.717f); // 9
    B8.append(1.629f); // 10
}
double SPCWidget::getMeanValue(QVector<double> data)
{
    int n = data.count();
    double sum = 0,t;
    foreach (t, data) {
        sum += t;
    }
    return sum/n;
}

//***PUBLIC***
/**********************************************************************************
 * 绘制框架函数(QVector<double>, QVector<double>, QVector<double>, int)
 * 入口参数分别为：x,y1,y2,n
 * x-横坐标    y1\y2-纵坐标   vol-子组采样数
 **********************************************************************************/
void SPCWidget::drawXSctrl(QVector<double> id, QVector<double> mean, QVector<double> s, int vol)
{
	setWindowTitle("X-S");

    int n = mean.count(); // 样本组数
    double xCL = getMeanValue(mean),_s,xAbis,xUCL,xLCL;
    _s = getMeanValue(s);
    xAbis = _s*A3[vol-2];
    xUCL = xCL+xAbis;
    xLCL = xCL-xAbis;
    QVector<double> xUq,sUq,yUq; // 不合格记录存放

    /* X-bar */
    QCustomPlot *xPlot = new QCustomPlot;
    xPlot->addGraph(); // 添加坐标轴及绘图属性
    xPlot->graph(0)->setPen(valuePen);
    xPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); // 散点图
    xPlot->graph(0)->setLineStyle(QCPGraph::lsLine); // 散点连线
    xPlot->xAxis->setRange(1,25);
    xPlot->xAxis->setAutoTickStep(false);
    xPlot->xAxis->setTickStep(1);
    xPlot->yAxis->setLabel(tr("X-bar"));
    xPlot->yAxis->setRange(xCL-2*xAbis,xCL+2*xAbis);
    xPlot->graph(0)->setData(id,mean); // 绑定记录
    //超控点设置为红色(取出不合格记录)
    xPlot->addGraph();
    for (int i=0;i<n;++i) {
        if(mean[i]>xUCL||mean[i]<xLCL)
        {
            xUq<<i+1;
            yUq<<mean[i];
        }
    }
    xPlot->graph(1)->setPen(QPen(QColor(255,0,0)));
    xPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
    xPlot->graph(1)->setData(xUq,yUq);
    yUq.clear();
    //控制上限
    QVector<double> uclx;
    for(int i=0;i<n;++i)
        uclx<<xUCL;
    xPlot->addGraph();
    xPlot->graph(2)->setPen(ULPen);
    xPlot->graph(2)->setLineStyle(QCPGraph::lsLine);
    xPlot->graph(2)->setData(id,uclx);
    //控制中限
    QVector<double> clx;
    for(int i=0;i<n;++i)
        clx<<xCL;
    xPlot->addGraph();
    xPlot->graph(3)->setPen(CLPen);
    xPlot->graph(3)->setLineStyle(QCPGraph::lsLine);
    xPlot->graph(3)->setData(id,clx);
    //控制下限
    QVector<double> lclx;
    for(int i=0;i<n;++i)
        lclx<<xLCL;
    xPlot->addGraph();
    xPlot->graph(4)->setPen(ULPen);
    xPlot->graph(4)->setLineStyle(QCPGraph::lsLine);
    xPlot->graph(4)->setData(id,lclx);
    xPlot->replot();
    mainLayout->addWidget(xPlot,0,0,6,4);

    /* S-bar */
    double sCL = _s,sUCL,sLCL,sAbis;
    sUCL = _s*B8[vol-2];
    sLCL = _s*B7[vol-2];
    sAbis = sUCL-sLCL;
    QCustomPlot *sPlot = new QCustomPlot;
    sPlot->clearGraphs();
    sPlot->addGraph(); // 添加坐标轴及绘图属性
    sPlot->graph(0)->setPen(valuePen);
    sPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); // 散点图
    sPlot->graph(0)->setLineStyle(QCPGraph::lsLine); // 散点连线
    sPlot->xAxis->setRange(1,25);
    sPlot->xAxis->setAutoTickStep(false);
    sPlot->xAxis->setTickStep(1);
    sPlot->yAxis->setLabel(tr("S-bar"));
    sPlot->yAxis->setRange(sCL-sAbis,sCL+sAbis);
    sPlot->graph(0)->setData(id,s); // 绑定记录
    //超控点设置为红色
    sPlot->addGraph();
    for (int i=0;i<n;++i) {
        if(s[i]>sUCL||s[i]<sLCL)
        {
            sUq<<i+1;
            yUq<<s[i];
        }
    }
    sPlot->graph(1)->setPen(QPen(QColor(255,0,0)));
    sPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
    sPlot->graph(1)->setData(sUq,yUq);
    yUq.clear();
    //上限
    QVector<double> ucls;
    for(int i=0;i<n;++i)
        ucls<<sUCL;
    sPlot->addGraph();
    sPlot->graph(2)->setPen(ULPen);
    sPlot->graph(2)->setLineStyle(QCPGraph::lsLine);
    sPlot->graph(2)->setData(id,ucls);
    //中限
    QVector<double> cls;
    for(int i=0;i<n;++i)
        cls<<sCL;
    sPlot->addGraph();
    sPlot->graph(3)->setPen(CLPen);
    sPlot->graph(3)->setLineStyle(QCPGraph::lsLine);
    sPlot->graph(3)->setData(id,cls);
    //下限
    QVector<double> lcls;
    for(int i=0;i<n;++i)
        lcls<<sLCL;
    sPlot->addGraph();
    sPlot->graph(4)->setPen(ULPen);
    sPlot->graph(4)->setLineStyle(QCPGraph::lsLine);
    sPlot->graph(4)->setData(id,lcls);
    mainLayout->addWidget(sPlot,7,0,6,4);
    //图示标注
    info1->append(tr("X-bar  CL: ")+QString::number(xCL)
                  +tr("  UCL: ")+QString::number(xUCL)
                  +tr("   LCL: ")+QString::number(xLCL)
                  +tr("\t\t\t\t   Group Size: ")+QString::number(n));
    info1->append(tr("S-bar  CL: ")+QString::number(sCL)
                  +tr("  UCL: ")+QString::number(sUCL)
                  +tr("  LCL: ")+QString::number(sLCL)
                  +tr("\t\t\t\t   Subgrp Size: ")+QString::number(vol));
    info1->append("************************************************");
    //得到不合格ID
    info1->append("X Unqualified: \n");
    float t;
    for(int i=0;i<xUq.count();++i)
    {
        t = xUq[i];
        info1->insertPlainText(QString::number(t)+"\t");
    }
    xUq.clear();
    info1->append("StD Unqualified: \n");
    for(int i=0;i<sUq.count();++i)
    {
        t = sUq[i];
        info1->insertPlainText(QString::number(t)+"\t");
    }
    sUq.clear();
    info1->setReadOnly(true);
    mainLayout->addWidget(info1,13,0,2,4);
}
void SPCWidget::drawXRctrl(QVector<double> id, QVector<double> mean, QVector<double> r, int vol)
{
	setWindowTitle("X-R");

    int n = mean.count(); // 样本组数
    double xCL = getMeanValue(mean),_r,xAbis,xUCL,xLCL;
    _r = getMeanValue(r);
    xAbis = _r*A2[vol-2];
    xUCL = xCL+xAbis;
    xLCL = xCL-xAbis;
    QVector<double> xUq,rUq,yUq; // 超线点临时存放
    /* X-bar */
    QCustomPlot *xPlot = new QCustomPlot;
    xPlot->addGraph(); // 添加坐标轴及绘图属性
    xPlot->graph(0)->setPen(valuePen);
    xPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); // 散点图
    xPlot->graph(0)->setLineStyle(QCPGraph::lsLine); // 散点连线
    xPlot->xAxis->setRange(1,25);
    xPlot->xAxis->setAutoTickStep(false);
    xPlot->xAxis->setTickStep(1);
    xPlot->yAxis->setLabel(tr("X-bar"));
    xPlot->yAxis->setRange(xCL-2*xAbis,xCL+2*xAbis);
    xPlot->graph(0)->setData(id,mean); // 绑定记录
    //超控点设置为红色
    xPlot->addGraph();
    for (int i=0;i<n;++i) {
        if(mean[i]>xUCL||mean[i]<xLCL)
        {
            xUq<<i+1;
            yUq<<mean[i];
        }
    }
    xPlot->graph(1)->setPen(QPen(QColor(255,0,0)));
    xPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
    xPlot->graph(1)->setData(xUq,yUq);
    yUq.clear();
    //控制上限
    QVector<double> uclx;
    for(int i=0;i<n;++i)
        uclx<<xUCL;
    xPlot->addGraph();
    xPlot->graph(2)->setPen(ULPen);
    xPlot->graph(2)->setLineStyle(QCPGraph::lsLine);
    xPlot->graph(2)->setData(id,uclx);
    //控制中限
    QVector<double> clx;
    for(int i=0;i<n;++i)
        clx<<xCL;
    xPlot->addGraph();
    xPlot->graph(3)->setPen(CLPen);
    xPlot->graph(3)->setLineStyle(QCPGraph::lsLine);
    xPlot->graph(3)->setData(id,clx);
    //控制下限
    QVector<double> lclx;
    for(int i=0;i<n;++i)
        lclx<<xLCL;
    xPlot->addGraph();
    xPlot->graph(4)->setPen(ULPen);
    xPlot->graph(4)->setLineStyle(QCPGraph::lsLine);
    xPlot->graph(4)->setData(id,lclx);
    xPlot->replot();
    mainLayout->addWidget(xPlot,0,0,6,4);
    /* R-bar */
    double rCL = _r,rUCL,rLCL,rAbis;
    rUCL = _r*D4[vol-2];
    rLCL = _r*D3[vol-2];
    rAbis = rUCL-rLCL;
    QCustomPlot *rPlot = new QCustomPlot;
    rPlot->clearGraphs();
    rPlot->addGraph(); // 添加坐标轴及绘图属性
    rPlot->graph(0)->setPen(valuePen);
    rPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); // 散点图
    rPlot->graph(0)->setLineStyle(QCPGraph::lsLine); // 散点连线
    rPlot->xAxis->setRange(1,25);
    rPlot->xAxis->setAutoTickStep(false);
    rPlot->xAxis->setTickStep(1);
    rPlot->yAxis->setLabel(tr("R-bar"));
    rPlot->yAxis->setRange(rCL-rAbis,rCL+rAbis);
    rPlot->graph(0)->setData(id,r); // 绑定记录
    //超控点设置为红色
    rPlot->addGraph();
    for (int i=0;i<n;++i) {
        if(r[i]>rUCL||r[i]<rLCL)
        {
            rUq<<i+1;
            yUq<<r[i];
        }
    }
    rPlot->graph(1)->setPen(QPen(QColor(255,0,0)));
    rPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
    rPlot->graph(1)->setData(rUq,yUq);
    yUq.clear();
    //上限
    QVector<double> uclr;
    for(int i=0;i<n;++i)
        uclr<<rUCL;
    rPlot->addGraph();
    rPlot->graph(2)->setPen(ULPen);
    rPlot->graph(2)->setLineStyle(QCPGraph::lsLine);
    rPlot->graph(2)->setData(id,uclr);
    //中限
    QVector<double> clr;
    for(int i=0;i<n;++i)
        clr<<rCL;
    rPlot->addGraph();
    rPlot->graph(3)->setPen(CLPen);
    rPlot->graph(3)->setLineStyle(QCPGraph::lsLine);
    rPlot->graph(3)->setData(id,clr);
    //下限
    QVector<double> lclr;
    for(int i=0;i<n;++i)
        lclr<<rLCL;
    rPlot->addGraph();
    rPlot->graph(4)->setPen(ULPen);
    rPlot->graph(4)->setLineStyle(QCPGraph::lsLine);
    rPlot->graph(4)->setData(id,lclr);
    mainLayout->addWidget(rPlot,7,0,6,4);

    //图示标注
    info2->append(tr("X-bar  CL: ")+QString::number(xCL)
                  +tr("  UCL: ")+QString::number(xUCL)
                  +tr("   LCL: ")+QString::number(xLCL)
                  +tr("\t\t\t\t   Group Size: ")+QString::number(n));
    info2->append(tr("S-bar  CL: ")+QString::number(rCL)
                  +tr("  UCL: ")+QString::number(rUCL)
                  +tr("  LCL: ")+QString::number(rLCL)
                  +tr("\t\t\t\t   Subgrp Size: ")+QString::number(vol));
    info2->append("************************************************");
    //得到不合格ID
    info2->append("X Unqualified: \n");
    float t;
    for(int i=0;i<xUq.count();++i)
    {
        t = xUq[i];
        info2->insertPlainText(QString::number(t)+"\t");
    }
    xUq.clear();
    info2->append("R Unqualified: \n");
    for(int i=0;i<rUq.count();++i)
    {
        t = rUq[i];
        info2->insertPlainText(QString::number(t)+"\t");
    }
    rUq.clear();
    info2->setReadOnly(true);
    mainLayout->addWidget(info2,13,0,2,4);
}
