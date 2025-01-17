#include "jcz2_laser.h"
#include <iostream>

#define ToWStr(x) x.toStdWString().data()

JCZ2Laser::JCZ2Laser()
{
	HandleReset();
}

JCZ2Laser::~JCZ2Laser()
{
	if (m_hEzdDLL)
	{
		laser_Close();
	}
}

void JCZ2Laser::HandleReset()
{

	m_hEzdDLL = nullptr;//DLL调用句柄

	lmc1_Initial = nullptr;
	lmc1_Close = nullptr;
	lmc1_StopMark = nullptr;
	lmc1_LoadEzdFile = nullptr;
	lmc1_Mark = nullptr;
	lmc1_MarkEntity = nullptr;


	lmc1_GotoPos = nullptr;
	lmc1_GetCurCoor = nullptr;

	lmc1_MarkPoint = nullptr;
	lmc1_MarkLine = nullptr;

	lmc1_GetEntSize = nullptr;
	lmc1_MoveEnt = nullptr;
	lmc1_MirrorEnt = nullptr;
	lmc1_ScaleEnt = nullptr;
	lmc1_RotateEnt = nullptr;

	lmc1_GetPenParam = nullptr;
	lmc1_SetPenParam = nullptr;
	lmc1_ClearEntLib = nullptr;

	lmc1_AddCurveToLib = nullptr;
	lmc1_AddCircleToLib = nullptr;
	lmc1_AddBarCodeToLib = nullptr;
	lmc1_AddTextToLib = nullptr;
	lmc1_AddFileToLib = nullptr;
	lmc1_ChangeTextByName = nullptr;

	lmc1_SaveEntLibToFile = nullptr;

	lmc1_GetBitmapEntParam = nullptr;
	lmc1_SetBitmapEntParam2 = nullptr;
}

int JCZ2Laser::laser_Open()
{
	SetDllDirectory(ToWStr(m_ezdPath));
	m_hEzdDLL = LoadLibrary(_T("MarkEzd.dll"));//加载动态连接库	
	if (m_hEzdDLL == NULL)
	{
		std::cerr << "Loadlibrary [MarkEzd.dll] error" << std::endl;
		return LMC1_ERR_FAILEDOPEN;
	}

	auto GetDllAddress = [this](auto& fp, const char* fn) {
		fp = (std::remove_reference_t<decltype(fp)>)GetProcAddress(m_hEzdDLL, fn);
		if (fp == nullptr)
		{
			std::cerr << "Can not find funtion " << fn << " in MarkEzd.dll!" << std::endl;
		}
		};

	GetDllAddress(lmc1_Initial, "lmc1_Initial");
	GetDllAddress(lmc1_Close, "lmc1_Close");
	GetDllAddress(lmc1_StopMark, "lmc1_StopMark");
	GetDllAddress(lmc1_LoadEzdFile, "lmc1_LoadEzdFile");
	GetDllAddress(lmc1_Mark, "lmc1_Mark");
	GetDllAddress(lmc1_MarkEntity, "lmc1_MarkEntity");
	GetDllAddress(lmc1_GotoPos, "lmc1_GotoPos");
	GetDllAddress(lmc1_GetCurCoor, "lmc1_GetCurCoor");
	GetDllAddress(lmc1_MarkPoint, "lmc1_MarkPoint");
	GetDllAddress(lmc1_MarkLine, "lmc1_MarkLine");
	GetDllAddress(lmc1_GetEntSize, "lmc1_GetEntSize");
	GetDllAddress(lmc1_MoveEnt, "lmc1_MoveEnt");
	GetDllAddress(lmc1_MirrorEnt, "lmc1_MirrorEnt");
	GetDllAddress(lmc1_ScaleEnt, "lmc1_ScaleEnt");
	GetDllAddress(lmc1_RotateEnt, "lmc1_RotateEnt");
	GetDllAddress(lmc1_GetPenParam, "lmc1_GetPenParam");
	GetDllAddress(lmc1_SetPenParam, "lmc1_SetPenParam");
	GetDllAddress(lmc1_ClearEntLib, "lmc1_ClearEntLib");
	GetDllAddress(lmc1_AddCurveToLib, "lmc1_AddCurveToLib");
	GetDllAddress(lmc1_AddCircleToLib, "lmc1_AddCircleToLib");
	GetDllAddress(lmc1_AddBarCodeToLib, "lmc1_AddBarCodeToLib");
	GetDllAddress(lmc1_AddTextToLib, "lmc1_AddTextToLib");
	GetDllAddress(lmc1_AddFileToLib, "lmc1_AddFileToLib");
	GetDllAddress(lmc1_ChangeTextByName, "lmc1_ChangeTextByName");
	GetDllAddress(lmc1_SaveEntLibToFile, "lmc1_SaveEntLibToFile");
	GetDllAddress(lmc1_GetBitmapEntParam, "lmc1_GetBitmapEntParam");
	GetDllAddress(lmc1_SetBitmapEntParam2, "lmc1_SetBitmapEntParam2");
	
	if (lmc1_Initial != NULL)
	{
		int nErr = LMC1_ERR_SUCCESS;
		nErr = lmc1_Initial(ToWStr(m_ezdPath), FALSE, nullptr);

		if (nErr != LMC1_ERR_SUCCESS)
		{
			std::cerr << "Initial lmc1 failed!ErrCode = " << nErr << std::endl;
			return nErr;
		}
	}
	return 0;
}

int JCZ2Laser::laser_Close()
{
	if (lmc1_Close != nullptr)
	{
		lmc1_Close();
	}
	if (m_hEzdDLL != nullptr)
	{
		FreeLibrary(m_hEzdDLL);
	}
	HandleReset();
	return 0;
}

int JCZ2Laser::laser_MarkPoint(Point point, double delay, int pen)
{
	return lmc1_MarkPoint(point.x(), point.y(), delay, pen);
}

int JCZ2Laser::laser_MarkLine(Point point1, Point point2, int pen)
{
	return lmc1_MarkLine(point1.x(), point1.y(), point2.x(), point2.y(), pen);
}

int JCZ2Laser::laser_GotoPos(Point pos)
{
	return lmc1_GotoPos(pos.x(), pos.y());
}

int JCZ2Laser::laser_GetCurPos(Point& pos)
{
	return lmc1_GetCurCoor(pos.rx(), pos.ry());
}

int JCZ2Laser::laser_LoadMarkFile(String file)
{
	return lmc1_LoadEzdFile(ToWStr(file));
}

int JCZ2Laser::laser_MarkFile()
{
	return lmc1_Mark(FALSE);
}

int JCZ2Laser::laser_MarkEntity(String ent)
{
	return lmc1_MarkEntity(ToWStr(ent));
}

int JCZ2Laser::laser_MirrorEnt(String ent, Point center, bool bx, bool by)
{
	return lmc1_MirrorEnt(ToWStr(ent), center.x(), center.y(), bx, by);
}

int JCZ2Laser::laser_MoveEnt(String ent, Point offset)
{
	return lmc1_MoveEnt(ToWStr(ent), offset.x(), offset.y());
}

int JCZ2Laser::laser_RotateEnt(String ent, Point center, double angle)
{
	return lmc1_RotateEnt(ToWStr(ent), center.x(), center.y(), angle);
}

int JCZ2Laser::laser_ScaleEnt(String ent, Point center, double scaleX, double scaleY)
{
	return lmc1_ScaleEnt(ToWStr(ent), center.x(), center.y(), scaleX, scaleY);
}

int JCZ2Laser::laser_GetEntSize(String ent, Rect& rect)
{
	double tl_x, tl_y, br_x, br_y, z;
	int err = lmc1_GetEntSize(ToWStr(ent), tl_x, tl_y, br_x, br_y, z);
	rect.setTopLeft({ tl_x, tl_y });
	rect.setBottomRight({ br_x, br_y });
	return err;
}

int JCZ2Laser::laser_GetBitmapEnt(String ent, BitmapInfo& bmpInfo)
{
	WCHAR bmpPath[256] = {};
	auto err = lmc1_GetBitmapEntParam(ToWStr(ent),
		bmpPath,
		bmpInfo.bmpAttrib, 
		bmpInfo.scanAttrib, 
		bmpInfo.brightness, 
		bmpInfo.contrast, 
		bmpInfo.pointTime, 
		bmpInfo.importDpi);
	bmpInfo.bmpPath = QString::fromWCharArray(bmpPath);

	return err;
}

int JCZ2Laser::laser_SetBitmapEnt(String ent, const BitmapInfo& bmpInfo)
{
	return lmc1_SetBitmapEntParam2(ToWStr(ent), 
		ToWStr(bmpInfo.bmpPath), 
		bmpInfo.bmpAttrib, 
		bmpInfo.scanAttrib, 
		bmpInfo.brightness,
		bmpInfo.contrast,
		bmpInfo.pointTime,
		bmpInfo.importDpi,
		FALSE, 0);
}

int JCZ2Laser::laser_ChangeEntText(String ent, String text)
{
	return lmc1_ChangeTextByName(ToWStr(ent), ToWStr(text));
}
