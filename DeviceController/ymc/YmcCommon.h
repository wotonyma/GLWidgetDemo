#pragma once
#include "ymcPCAPI.h"
#include <vector>
#include <string>

namespace Ymc {
	//axis
	struct AxisController {
		DWORD axisNo; //轴号
		HAXIS hAxis;
		HDEVICE g_hDevice;
	};

	//cpu
	struct ComController {
		COM_DEVICE com_dev;
		std::vector<AxisController> v_AxisCtl;
		HCONTROLLER g_hController;
	};

	//axis motion param
	struct MotionRequest {
		std::vector<DWORD> axesNo;
		std::vector<MOTION_DATA> motionDatas;
		std::vector<POSITION_DATA> posDatas;
		/*jogMove need*/
		std::vector<WORD> directions;
		std::vector<WORD> timeouts;
		std::vector<WORD> waitForCompletions;
		DWORD moveIO;
		std::string objName;
	};

	//Motion Monitoring Parameter 更多信息请参考MontionAPI(PCAPI) Manual
	enum class MontionMonitor :ulong {
		DriveStatus = 0,
		Warning = 2,
		Alarm = 4,
		ServoStatus = 9, /*Servo module command status*/
		APOS = 22, /*Machine coordinate feedback position (APOS)*/
		Speed = 32, /*Speed reference output monitor*/
		ServoAlmCode = 45 /*Servo alarm code*/
	};

	enum class MontionSetting :ulong {
		RunCommands = 0,
		MotionCommand = 8,
		SpeedRef = 16, /*Speed reference */
		PSpeedLimit = 18,/*Positive speed limit value*/
		NSpeedLimit = 19
	};
}
