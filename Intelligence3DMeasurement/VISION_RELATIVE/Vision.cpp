#include <QDebug>
#include "Vision.h"

#include "Global.h"


Vision::Vision(QObject *parent)
	: QObject(parent)
{
	// ��ʼ����� qdebug
}

Vision::~Vision()
{
	// �ر����
}

void Vision::ImgProc()
{
	qDebug() << "Processing images...";
	// ͼ����
	emit ProcessDone();
}