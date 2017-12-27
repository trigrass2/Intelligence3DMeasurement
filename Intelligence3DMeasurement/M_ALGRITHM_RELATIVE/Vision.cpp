#include <QDebug>
#include "Vision.h"

#include "Global.h"

#include <HALCONCpp/HalconCpp.h>
#include <HALCONCpp/HDevThread.h>
using namespace HalconCpp;

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

	HObject  ho_Image, ho_Border, ho_UnionContours;
	HObject  ho_SelectedContours1;
	HTuple  hv_RowBegin, hv_ColBegin, hv_RowEnd, hv_ColEnd;
	HTuple  hv_Nr, hv_Nc, hv_Dist;


	//ÿ�ɼ�һ��ͼ����һ�θó��򣬸��ݼ����Ŀ�洢���������Ϣ�����������
	for (int i = 0; i < Global::g_projectInfo.camSequence.count(); ++i)		// �õ�����
	{
		HTuple i_ = 0;
		Q_FOREACH(QString name, Global::halconData.keys()) {
			if (name.split("_").first().toInt() == Global::g_projectInfo.camSequence[i]) {
				// �ҵ��˶�Ӧ��ͼ
				
				i_=i_+1;
				ho_Image = Global::halconData.value(name);
				WriteImage(ho_Image, "bmp", 0, "E:/SmartTest20171210/SmartTest/temp/" + i_ + ".bmp");
				// ����������
				double tx, ty;
				tx = name.split("_")[1].toInt();
				ty = name.split("_").last().toInt();
				qDebug() <<"idx"<<i<< "tx" << tx << "ty" << ty;

				if (Global::g_projectInfo.camearItems[i].nType == L2LD)   // LL
				{
					ThresholdSubPix(ho_Image, &ho_Border, 10);
					UnionCollinearContoursXld(ho_Border, &ho_UnionContours, 50, 2, 18, 0.7, "attr_keep");
					SelectContoursXld(ho_UnionContours, &ho_SelectedContours1, "contour_length", 500,
						100000, -0.5, 0.5);
					FitLineContourXld(ho_SelectedContours1, "tukey", -1, 0, 5, 2, &hv_RowBegin, &hv_ColBegin,
						&hv_RowEnd, &hv_ColEnd, &hv_Nr, &hv_Nc, &hv_Dist);

					//ˮƽ�������߾�
					if (abs(Global::g_projectInfo.camearItems[i].cadPos[0].x() -
						Global::g_projectInfo.camearItems[i].cadPos[1].x()) == 0)
					{
						for (int m = 0; m < hv_Nr.Length(); m++)
						{
							if (hv_Nr[m]<0.1 && hv_Nc[m]>0.9)
							{
								HTuple Col = (hv_ColBegin[m] + hv_ColEnd[m]) / 2;
								qDebug() << "Col" << Col.D();
								break;
							}
						}
					}
					//��ֱ�������߾�
					if (abs(Global::g_projectInfo.camearItems[i].cadPos[0].y() -
						Global::g_projectInfo.camearItems[i].cadPos[1].y()) ==0)
					{
						for (int m = 0; m < hv_Nr.Length(); m++)
						{
							if (hv_Nr[m] > 0.9 && hv_Nc[m] < 0.1)
							{
								HTuple Row = (hv_RowBegin[m] + hv_RowEnd[m]) / 2;
								qDebug() << "Row" << Row.D();
								break;
							}
						}
					}
				}

				if (Global::g_projectInfo.camearItems[i].nType == P2PD) //Circle
				{
					//Circle  �����

					HObject  /*ho_Image,*/ ho_ImageGauss, ho_ROI_0, ho_ImageReduced;
					HObject  ho_ImageRoberts, ho_Regions, ho_ConnectedRegions;
					HObject  ho_SelectedRegions, ho_RegionTrans;
					HTuple  hv_Area, hv_Row, hv_Column, hv_Radius;


					GaussFilter(ho_Image, &ho_ImageGauss, 7);
					GenRectangle1(&ho_ROI_0, 18.9925, 42.8244, 1553.08, 1710.18);
					ReduceDomain(ho_ImageGauss, ho_ROI_0, &ho_ImageReduced);
					Roberts(ho_ImageReduced, &ho_ImageRoberts, "gradient_sum");
					Threshold(ho_ImageRoberts, &ho_Regions, 0, 2);
					Connection(ho_Regions, &ho_ConnectedRegions);
					SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", 40000, 901850);
					ShapeTrans(ho_SelectedRegions, &ho_RegionTrans, "outer_circle");
					//��ȱ���Բ��ȫ
					AreaCenter(ho_RegionTrans, &hv_Area, &hv_Row, &hv_Column);
					//����뾶
					hv_Radius = (hv_Area / 3.1415926).TupleSqrt();//Circle  �����

				}

				if (Global::g_projectInfo.camearItems[i].nType == 2)  //angle
				{

				}
			}
		}
		
	}
	
	//���ص�ǰ��ͼ������ͼ����Ŀ�����Ϣ
	//  return row,col,(R),type; 

	emit VisionProcessDone();
}