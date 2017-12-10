#include <QDebug>
#include "Vision.h"

#include "Global.h"

Vision::Vision(QObject *parent)
	: QObject(parent)
{
	// 初始化相机 qdebug
}

Vision::~Vision()
{
	// 关闭相机
}

void Vision::ImgProc()
{
	qDebug() << "Processing images...";
	// 图像处理
	emit ProcessDone();
}