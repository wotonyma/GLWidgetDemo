#include "YmcController.h"

YmcController::YmcController(QObject *parent)
	: QObject(parent)
{
	qRegisterMetaType<std::vector<long>>("std::vector<long>");
	qRegisterMetaType<Ymc::MontionMonitor>("Ymc::MontionMonitor");
	qRegisterMetaType<Ymc::MontionSetting>("Ymc::MontionSetting");
	qRegisterMetaType<QVector<QString>>("QVector<QString>");
	qRegisterMetaType<std::function<void(std::vector<ALARM_INFO>)>>("std::function<void(std::vector<ALARM_INFO>)>");
	qRegisterMetaType<std::shared_ptr<Ymc::MotionRequest>>("std::shared_ptr<Ymc::MotionRequest>");
}

YmcController& YmcController::Instance()
{
	// TODO: 在此处插入 return 语句
	static YmcController ctl(nullptr);
	return ctl;
}

YmcController::~YmcController()
{
}

void YmcController::connectObj(YmcObject* obj)
{
	if (obj == nullptr)
		return;
	ctlObj = obj;
	/*async signals and slots*/
	//init
	connect(this, &YmcController::MotionAPIOpenSignal, obj, &YmcObject::MotionAPIOpen);
	connect(this, &YmcController::MotionAPICloseSignal, obj, &YmcObject::MotionAPIClose);
	connect(this, &YmcController::MotionAPICloseAllSignal, obj, &YmcObject::MotionAPICloseAll);
	connect(this, &YmcController::InitAxisDeviceSignal, obj, &YmcObject::InitAxisDevice);
	connect(this, &YmcController::AxesServoControlSignal, obj, &YmcObject::AxesServoControl);
	//monitor and setting
	connect(this, &YmcController::AxesMotionMonitorSignal, obj, &YmcObject::AxesMotionMonitoring);
	connect(this, &YmcController::AxesMotionSettingSignal, obj, &YmcObject::AxesMotionSetting);
	//alarm
	connect(this, &YmcController::GetYmcAlarmSignal, obj, &YmcObject::GetYmcAlarmInfo);
	connect(obj, &YmcObject::YmcAlarmInfo, this, [this](QVector<QString> info) {emit YmcAlarmInfoSignal(info); });
	connect(this, &YmcController::YmcAlarmProcessSignal, obj, &YmcObject::YmcAlarmProcessing);
	connect(this, &YmcController::YmcAlarmClearSignal, obj, &YmcObject::YmcAlarmClear);
	connect(this, &YmcController::ServoAlarmGenerateSignal, obj, &YmcObject::ServoAlarmGenerate);
	connect(this, &YmcController::ServoAlarmClearSignal, obj, &YmcObject::ServoAlarmClear);
	//home position
	connect(this, &YmcController::HomePositionSignal, obj, &YmcObject::HomePosition);
	//jog
	connect(this, &YmcController::AxesMoveJogSignal, obj, &YmcObject::AxesMoveJog);
	connect(this, &YmcController::AxesStopJogSignal, obj, &YmcObject::AxesStopJog);
	//position
}

void YmcController::disconnectObj()
{
	disconnect();
	ctlObj = nullptr;
}

std::vector<long> YmcController::getAxesMotionMonitor(std::vector<long> axesNo, Ymc::MontionMonitor opt)
{
	if (ctlObj == nullptr)
		return std::vector<long>();
	//return ctlObj->AxesMotionMonitoring(axesNo, opt); 
	//此调用若不与Ymcobject在同一个线程无效
	//所以此函数不能在ymcObject内部调用，最好也不要在主线程调用
	std::vector<long> ret;
	QMetaObject::invokeMethod(ctlObj, "AxesMotionMonitoring", Qt::BlockingQueuedConnection,
		Q_RETURN_ARG(std::vector<long>, ret),
		Q_ARG(std::vector<long>, axesNo),
		Q_ARG(Ymc::MontionMonitor, opt));
	return ret;
}

bool YmcController::setAxesMotionSetting(std::vector<long> axesNo, std::vector<long> settings, Ymc::MontionSetting opt)
{
	if (ctlObj == nullptr)
		return false;
	//return ctlObj->AxesMotionSetting(axesNo, settings, opt);
	QMetaObject::invokeMethod(ctlObj, "AxesMotionSetting", Qt::AutoConnection,
		Q_ARG(std::vector<long>, axesNo),
		Q_ARG(std::vector<long>, settings),
		Q_ARG(Ymc::MontionSetting, opt));
	return true;
}

std::vector<long> YmcController::getAxesUsedNumber()
{
	if (ctlObj == nullptr)
		return std::vector<long>();
	return ctlObj->AxesUsedNumber();
}

std::vector<ALARM_INFO> YmcController::getAxesAlarmInfo()
{
	if (ctlObj == nullptr)
		return std::vector<ALARM_INFO>();
	return ctlObj->AxesAlarmInfo();
}

std::shared_ptr<Ymc::MotionRequest> YmcController::GeneratePositionMsg(std::vector<long> axesNo, std::vector<long> pos, short mv_type, long velo, WORD wait)
{
	// Sets the motion parameter.
	auto spReq = std::make_shared<Ymc::MotionRequest>();

	MOTION_DATA mData;
	mData.CoordinateSystem = WORK_SYSTEM;
	mData.MoveType = mv_type; //MTYPE_ABSOLUTE or MTYPE_RELATIVE
	mData.VelocityType = VTYPE_UNIT_PAR;
	mData.AccDecType = ATYPE_TIME;
	mData.FilterType = FTYPE_NOTHING;
	mData.DataType = 0x0000;
	mData.Acceleration = 100;
	mData.Deceleration = 100;
	mData.Velocity = velo;

	for (auto no : axesNo)
	{
		spReq->axesNo.emplace_back((DWORD)no);
		spReq->motionDatas.emplace_back(mData);
		spReq->waitForCompletions.emplace_back(wait);
	}

	POSITION_DATA pData;
	pData.DataType = DATATYPE_IMMEDIATE;
	for (auto p : pos)
	{
		pData.PositionData = p;
		spReq->posDatas.emplace_back(pData);
	}

	return spReq;
}

void YmcController::AsyncMotionPositioning(std::vector<long> axesNo, std::vector<long> pos, short mv_type, long velo)
{
	auto spReq = GeneratePositionMsg(axesNo, pos, mv_type, velo, COMMAND_STARTED);
	QMetaObject::invokeMethod(ctlObj, "AxesMovePositioning", Qt::AutoConnection, Q_ARG(std::shared_ptr<Ymc::MotionRequest>, spReq));
}

bool YmcController::SyncMotionPositioning(std::vector<long> axesNo, std::vector<long> pos, short mv_type, long velo)
{
	auto spReq = GeneratePositionMsg(axesNo, pos, mv_type, velo, POSITIONING_COMPLETED);
	bool ret = false;
	QMetaObject::invokeMethod(ctlObj, "AxesMovePositioning", Qt::BlockingQueuedConnection,
		Q_RETURN_ARG(bool, ret),
		Q_ARG(std::shared_ptr<Ymc::MotionRequest>, spReq));
	return ret;
}

void YmcController::StopMotionPositioning(std::vector<long> axesNo)
{
	auto spReq = std::make_shared<Ymc::MotionRequest>(); 

	MOTION_DATA mData;
	mData.AccDecType = ATYPE_TIME;
	mData.DataType = 0x0000;
	mData.Deceleration = 100;
	WORD wait = DISTRIBUTION_COMPLETED;
	for (auto no : axesNo)
	{
		spReq->axesNo.emplace_back((DWORD)no);
		spReq->motionDatas.emplace_back(mData);
		spReq->waitForCompletions.emplace_back(wait);
	}
	QMetaObject::invokeMethod(ctlObj, "AxesStopPositioning", Qt::AutoConnection, Q_ARG(std::shared_ptr<Ymc::MotionRequest>, spReq));	
}

void YmcController::StopJog(std::vector<long> axesNo)
{
	auto req = std::make_shared<Ymc::MotionRequest>();
	for (auto axis : axesNo)
	{
		req->axesNo.emplace_back(axis);
	}
	req->objName = "StopJ";
	req->waitForCompletions.emplace_back(POSITIONING_COMPLETED);
	YmcController::Instance().AxesStopJogSignal(req);
}

void YmcController::AxisJogNegative(int axis, long velo)
{
	AxisJogMotion(axis, velo, DIRECTION_NEGATIVE);
}

void YmcController::AxisJogPositive(int axis, long velo)
{
	AxisJogMotion(axis, velo, DIRECTION_POSITIVE);
}

void YmcController::AxisJogMotion(int axis, long velo, long direction)
{
	auto req = std::make_shared<Ymc::MotionRequest>();
	req->objName = "Jog";
	req->axesNo.emplace_back(axis);
	req->directions.emplace_back((WORD)direction);

	MOTION_DATA mData;
	mData.CoordinateSystem = WORK_SYSTEM;	// Work coordinate system
	mData.MoveType = MTYPE_RELATIVE;		// Incremental value specified
	mData.VelocityType = VTYPE_UNIT_PAR;	// Speed [reference unit/s]
	mData.AccDecType = ATYPE_TIME;			// Time constant specified [ms]
	mData.FilterType = FTYPE_S_CURVE;		// Moving average filter (simplified S-curve)			
	mData.DataType = 0;						// All parameters directly specified
	/* Not Use mData.MaxVelocity  = NULL; */
	mData.Acceleration = 100;		// Acceleration time constant [ms] 
	mData.Deceleration = 100;		// Deceleration time constant [ms]
	mData.FilterTime = 10;					// Filter time [0.1 ms]
	mData.Velocity = velo;			// Speed [reference unit/s]					
	/* Not Use mData.ApproachVelocity = NULL; */
	/* Not Use mData.CreepVelocity    = NULL; */
	req->motionDatas.emplace_back(mData);
	req->timeouts.emplace_back(0);

	YmcController::Instance().AxesMoveJogSignal(req);
}

bool YmcController::AxisAbsoluteMotion(int axis, long pos, long velo)
{
	return YmcController::Instance().SyncMotionPositioning({ axis }, { pos }, MTYPE_ABSOLUTE, { velo });
}

bool YmcController::AxisRelativeMotion(int axis, long pos, long velo)
{
	return YmcController::Instance().SyncMotionPositioning({ axis }, { pos }, MTYPE_RELATIVE, { velo });
}
