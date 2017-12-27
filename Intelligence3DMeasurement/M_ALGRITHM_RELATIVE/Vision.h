#pragma once

#include <QObject>


class Vision : public QObject
{
	Q_OBJECT

public:
	Vision(QObject *parent = Q_NULLPTR);
	~Vision();

signals:
	void VisionProcessDone();

private slots:
	void ImgProc();
};