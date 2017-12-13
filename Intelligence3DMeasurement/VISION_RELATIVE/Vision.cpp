#include <QDebug>
#include "Vision.h"

#include "Global.h"

using namespace HalconCpp;


Vision::Vision(QObject *parent)
	: QObject(parent)
{
	// ��ʼ�����
#if ENABLE_VISION_MODULE
	OpenFramegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "default", -1, "default", -1,
		"false", "default", "000748cef970_TheImagingSourceEuropeGmbH_DMK23GP", 0, -1,
		&Global::AcqHandle);
	GrabImageStart(Global::AcqHandle, -1);
#endif // ENABLE_VISION_MODULE
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