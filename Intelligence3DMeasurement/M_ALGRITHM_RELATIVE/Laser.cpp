#include <QDebug>
#include "Laser.h"

#include "Global.h"


Laser::Laser(QObject *parent)
	: QObject(parent)
{
}

Laser::~Laser()
{
}

void Laser::LaserProc()
{
	//Q_FOREACH(LASERITEM la, Global::g_projectInfo.laserItems) {
	//	double a1, a2, a3;
	//	double t_x = 0, t_y = 0, t_z = 0, t_xx = 0, t_yy = 0, t_xy = 0, t_xz = 0, t_yz = 0;
	//	int i = 0;
	//	for (; i < la.nodes.count(); ++i) {
	//		t_x += la.nodes[i].x() / 100.0;
	//		t_y += la.nodes[i].y() / 100.0;
	//		t_z += la.measure[i];
	//		t_xx += la.nodes[i].x() / 100.0*la.nodes[i].x() / 100.0;
	//		t_yy += la.nodes[i].y() / 100.0*la.nodes[i].y() / 100.0;
	//		t_xy += la.nodes[i].x() / 100.0*la.nodes[i].y() / 100.0;
	//		t_xz += la.nodes[i].x() / 100.0*la.measure[i];
	//		t_yz += la.nodes[i].y() / 100.0*la.measure[i];
	//	}
	//	qDebug() << t_x << t_y << t_z << t_xx << t_yy << t_xy << t_xz << t_yz;

	//	try {
	//		a3 = ((t_z / (double)i - t_xz / t_x)*(t_xx - t_xy) / (t_x / (double)i - t_xx / t_x) - t_xz + t_yz) /
	//			((t_y / (double)i - t_xy / t_x)*(t_xx - t_xy) / (t_x / (double)i - t_xx / t_x) - t_xy + t_yy);
	//		a2 = (t_xz - t_yz - (t_xy - t_yy)*a3) / (t_xx - t_xy);
	//		a1 = t_z / (double)i - t_x*a2 / (double)i - t_y*a3 / (double)i;
	//		qDebug() << a1 << a2 << a3;
	//	}
	//	catch (QString exception) {
	//		qDebug() << exception;
	//		return;
	//	}

	//	QVector<double> f;
	//	for (int j = 0; j < la.nodes.count(); ++j) {
	//		f << la.measure[j] - (a1 + a2*la.nodes[j].x() + a3*la.nodes[j].y());
	//	}
	//	qSort(f.begin(), f.end());
	//	qDebug() << f;
	//	double finalF = qAbs(f.first()) + qAbs(f.last());
	//	qDebug() << "FF=" << finalF;
	//	la.measure.clear();
	//}

	Q_FOREACH(LASERITEM la, Global::g_projectInfo.laserItemList) {
		qSort(la.sampleData.begin(), la.sampleData.end());
		qDebug() << la.sampleData;
		double finalF = qAbs(la.sampleData.last() - la.sampleData.first());
		la.processedData[Global::g_projectInfo.nSubGroupSize - Global::IndexGen(false)] = finalF;
		qDebug() << "Faltness=" << finalF;
		la.sampleData.clear();
	}

	emit LaserProcessDone();
}