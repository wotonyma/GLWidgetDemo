#pragma once

#include "laser.h"
#include "Windows.h"
#include <tchar.h>
#include "MarkEzdDll.h"


class JCZ2Laser : public Laser 
{
public:
	JCZ2Laser();
	~JCZ2Laser() override;

	void HandleReset();

	virtual int laser_Open() override;
	virtual int laser_Close() override;

	//直接打标
	virtual int laser_MarkPoint(Point point, double delay, int pen) override;
	virtual int laser_MarkLine(Point point1, Point point2, int pen) override;
	//振镜控制
	virtual int laser_GotoPos(Point pos) override;
	virtual int laser_GetCurPos(Point& pos) override;
	//对象控制
	virtual int laser_LoadMarkFile(String file) override;
	virtual int laser_MarkFile() override;
	virtual int laser_MarkEntity(String ent) override;
	virtual int laser_MarkEntity(String ent, int pen) override;
	//virtual int laser_SetRotateMoveParam(QPointF moveOffset, QPointF rotateCenter, double rotateAngle);

	virtual int laser_MirrorEnt(String ent, Point center, bool bx, bool by) override;
	virtual int laser_MoveEnt(String ent, Point offset) override;
	virtual int laser_RotateEnt(String ent, Point center, double angle) override;
	virtual int laser_ScaleEnt(String ent, Point center, double scaleX, double scaleY) override;
	virtual int laser_GetEntSize(String ent, Rect& rect) override;

	virtual int laser_AddPolygon(String ent, PointVec poly, bool close) override;
	//virtual int laser_HatchEnt(String ent) override;
	//virtual int laser_UnHatchEnt(String ent) override;
	virtual int laser_EnableHatchEnt(String ent, bool enableHatch, double hatchLineDist, int penNo) override;

	virtual int laser_GetBitmapEnt(String ent, BitmapInfo& bmpInfo) override;
	virtual int laser_SetBitmapEnt(String ent, const BitmapInfo& bmpInfo) override;

	virtual int laser_ChangeEntText(String ent, String text) override;

	virtual int laser_SaveToFile(String ent) override;

	void SetEzdPath(String ezdPath) { m_ezdPath = ezdPath; };

private:
	int SetHatchBindParam(String ent, bool bEnableHatch, double dHatchLineDist, int nPenNo);

	HINSTANCE m_hEzdDLL;//DLL调用句柄

	LMC1_INITIAL       lmc1_Initial;
	LMC1_CLOSE         lmc1_Close;
	LMC1_STOPMARK      lmc1_StopMark;
	LMC1_LOADEZDFILE   lmc1_LoadEzdFile;
	LMC1_MARK          lmc1_Mark;
	LMC1_MARKENTITY    lmc1_MarkEntity;

	LMC1_GOTOPOS       lmc1_GotoPos;
	LMC1_GETCURCOOR    lmc1_GetCurCoor;

	LMC1_MARKPOINT     lmc1_MarkPoint;
	LMC1_MARKLINE      lmc1_MarkLine;

	LMC1_GETENTSIZE    lmc1_GetEntSize;
	LMC1_MOVEENT       lmc1_MoveEnt;
	LMC1_MIRRORENT     lmc1_MirrorEnt;
	LMC1_SCALEENT      lmc1_ScaleEnt;
	LMC1_ROTATEENT     lmc1_RotateEnt;
	LMC1_DELETEENT	   lmc1_DeleteEnt;

	LMC1_HATCHENT      lmc1_HatchEnt;
	LMC1_UNHATCHENT    lmc1_UnHatchEnt;

	LMC1_GETPENPARAM   lmc1_GetPenParam;
	LMC1_SETPENPARAM   lmc1_SetPenParam;
	LMC1_CLEARENTLIB   lmc1_ClearEntLib;
	LMC1_SETENTALLCHILDPEN lmc1_SetEntAllChildPen;

	LMC1_ADDCURVETOLIB  lmc1_AddCurveToLib;
	LMC1_ADDCIRCLETOLIB  lmc1_AddCircleToLib;
	LMC1_ADDBARCODETOLIB   lmc1_AddBarCodeToLib;
	LMC1_ADDTEXTTOLIB  lmc1_AddTextToLib;
	LMC1_ADDFILETOLIB  lmc1_AddFileToLib;
	LMC1_CHANGETEXTBYNAME lmc1_ChangeTextByName;

	LMC1_SAVEENTLIBTOFILE  lmc1_SaveEntLibToFile;

	LMC1_GETBITMAPENTPARAM lmc1_GetBitmapEntParam;
	LMC1_SETBITMAPENTPARAM2 lmc1_SetBitmapEntParam2;
	LMC1_SETHATCHENTPARAM2 lmc1_SetHatchEntParam2;


	String m_ezdPath;	//ezcad 可执行程序目录
	bool   m_laserEnable;  //激光是否被打开
};