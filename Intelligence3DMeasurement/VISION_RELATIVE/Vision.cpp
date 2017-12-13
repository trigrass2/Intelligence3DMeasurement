#include <QDebug>
#include "Vision.h"

#include "Global.h"

using namespace HalconCpp;


Vision::Vision(QObject *parent)
	: QObject(parent)
{
	// 初始化相机
#if ENABLE_VISION_MODULE
	OpenFramegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "default", -1, "default", -1,
		"false", "default", "000748cef970_TheImagingSourceEuropeGmbH_DMK23GP", 0, -1,
		&Global::AcqHandle);
	GrabImageStart(Global::AcqHandle, -1);
#endif // ENABLE_VISION_MODULE
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