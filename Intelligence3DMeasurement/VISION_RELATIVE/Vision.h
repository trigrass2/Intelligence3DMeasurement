#pragma once

#include <QObject>

#if REPLACE_HALCON_LIB
#include "opencv2/opencv.hpp"
using namespace cv;
#endif // REPLACE_HALCON_LIB

class Vision : public QObject
{
	Q_OBJECT

public:
	Vision(QObject *parent = Q_NULLPTR);
	~Vision();

signals:
	void ProcessDone();

private slots:
	void ImgProc();
};
