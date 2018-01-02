#include <QDebug>
#include "Vision.h"

#include "Global.h"


Vision::Vision(QObject *parent)
	: QObject(parent)
{
	// 初始化相机
#if ENABLE_VISION_MODULE
	OpenFramegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "default", -1, "default", -1,
		"false", "default", "000748cef970_TheImagingSourceEuropeGmbH_DMK23GP", 0, -1,
		&Global::acqHandle);
	GrabImageStart(Global::acqHandle, -1);
#endif // ENABLE_VISION_MODULE
}

Vision::~Vision()
{
	// 关闭相机
#if ENABLE_VISION_MODULE
	CloseAllFramegrabbers();
#endif // ENABLE_VISION_MODULE
}

void Vision::ImgProc()
{
	qDebug() << "Processing images...";
	// 图像处理

	HObject  ho_Image, ho_Border, ho_UnionContours;
	HObject  ho_SelectedContours1;
	HTuple  hv_RowBegin, hv_ColBegin, hv_RowEnd, hv_ColEnd;
	HTuple  hv_Nr, hv_Nc, hv_Dist;


	//每采集一张图运行一次该程序，根据检测项目存储坐标点结果信息，最后处理结果。
	for (int i = 0; i < Global::g_projectInfo.camMeasurePath.count(); ++i)		// 得到索引
	{
		HTuple i_ = 0;
		Q_FOREACH(CAMERAITEM cam, Global::g_projectInfo.camItemList) {
			for (int i = 0; i < cam.feedbackPosList.count(); ++i) {
				ho_Image = cam.sampleData[i];
				WriteImage(ho_Image, "bmp", 0, "E:/SmartTest20171210/SmartTest/temp/" + i_ + ".bmp");
				i_ = i_ + 1;

				double tx, ty;
				tx = cam.feedbackPosList[i].x();
				ty = cam.feedbackPosList[i].y();
				qDebug() <<"idx"<<i<< "tx" << tx << "ty" << ty;

				if (Global::g_projectInfo.camItemList[i].nType == L2LD)   // LL
				{
					ThresholdSubPix(ho_Image, &ho_Border, 10);
					UnionCollinearContoursXld(ho_Border, &ho_UnionContours, 50, 2, 18, 0.7, "attr_keep");
					SelectContoursXld(ho_UnionContours, &ho_SelectedContours1, "contour_length", 500,
						100000, -0.5, 0.5);
					FitLineContourXld(ho_SelectedContours1, "tukey", -1, 0, 5, 2, &hv_RowBegin, &hv_ColBegin,
						&hv_RowEnd, &hv_ColEnd, &hv_Nr, &hv_Nc, &hv_Dist);

					//水平方向线线距
					if (abs(Global::g_projectInfo.camItemList[i].cadPosList[0].x() -
						Global::g_projectInfo.camItemList[i].cadPosList[1].x()) == 0)
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
					//竖直方向线线距
					if (abs(Global::g_projectInfo.camItemList[i].cadPosList[0].y() -
						Global::g_projectInfo.camItemList[i].cadPosList[1].y()) ==0)
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

				if (Global::g_projectInfo.camItemList[i].nType == P2PD) //Circle
				{
					//Circle  计算孔

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
					//将缺损的圆补全
					AreaCenter(ho_RegionTrans, &hv_Area, &hv_Row, &hv_Column);
					//计算半径
					hv_Radius = (hv_Area / 3.1415926).TupleSqrt();//Circle  计算孔

				}

				if (Global::g_projectInfo.camItemList[i].nType == 2)  //angle
				{

				}
			}
		}
		Global::g_projectInfo.camItemList[i].processedData[Global::g_projectInfo.nSubGroupSize-Global::IndexGen(false)] = 1;
	}
	
	//返回当前点图像坐标和检测项目类别信息
	//  return row,col,(R),type; 
	
	emit VisionProcessDone();
}