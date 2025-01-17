#pragma once

#include "ActUtlType64_i.h"
#include "ActProgType64_i.h"
#include "ActSupportMsg64_i.h"
#include "ActUtlDataLogging64_i.h"
#include "ActProgDataLogging64_i.h"
#include "atlbase.h"
#include <string>
#include <vector>
#include <cstdint>

#define COM_ERR 0x0180840C //connect error

class MelsecPLC
{
public:
	MelsecPLC();
	~MelsecPLC();
	void OnInitial();
	void UnInitinal();
	//type long is Returned value of communication function 
	long Connect(long no, const std::string& password);
	long Disconnect();
	//according to test, 32bit api can't read 32bit data, should concat 16bit data
	long GetDevice16Bit(const std::string& dev, short& data);
	long SetDevice16Bit(const std::string& dev, short data);
	//long GetDevice32Bit(const std::string& dev, long& data);
	//long SetDevice32Bit(const std::string& dev, long data);
	long ReadDeviceRandom16Bit(const std::vector<std::string>& devs, std::vector<short>& datas);
	long WriteDeviceRandom16Bit(const std::vector<std::string>& devs, const std::vector<short>& datas);
	//long ReadDeviceRandom32Bit(const std::string& dev, long size, long* data); //work bad
	//long WriteDeviceRandom32Bit(const std::string& dev, long size, long* data);//work bad
	long ReadDeviceBlock16Bit(const std::string& dev, long size, short* data);
	long WriteDeviceBlock16Bit(const std::string& dev, long size, short* data);
	//long ReadDeviceBlock32Bit(const std::string& dev, long size, long* data);
	//long WriteDeviceBlock32Bit(const std::string& dev, long size, long* data);
	//modify 32bit api
	long GetDeviceINT32(const std::string& dev, int32_t& data);
	long SetDeviceINT32(const std::string& dev, int32_t data);
	long ReadDeviceRandomINT32(const std::vector<std::string>& devs, std::vector<int32_t>& datas);
	long WriteDeviceRandomINT32(const std::vector<std::string>& devs, const std::vector<int32_t>& datas);
	long ReadDeviceBlockINT32(const std::string& dev, long size, int32_t* data);
	long WriteDeviceBlockINT32(const std::string& dev, long size, int32_t* data);
	//
	long ReadBuffer(long io_addr, long buf_addr, long size, short* data);
	long WriteBuffer(long io_addr, long buf_addr, long size, short* data);
	long GetCpuType(std::string& cpu_name, long& cpu_type);
	long SetCpuStatus(long op); //0:run; 1:stop; 2:pause
	long GetClockData(short& year, short& month, short& day, short& week, short& hour, short& min, short& sec);
	long SetClockData(short year, short month, short day, short week, short hour, short min, short sec);
	long GetErrorMessage(long err_code, std::string& err_msg);

	//logging
private:
	CComPtr<IActUtlType64> m_pIUtlType;
	CComPtr<IActProgType64> m_pIProgType;
	CComPtr<IActSupportMsg64> m_pISupportMsg;

	CComPtr<IActUtlDataLogging64> m_pIUtlDataLogging;
	CComPtr<IActProgDataLogging64> m_pIProgDataLogging;

	long m_StationNumber;
	std::string m_Password;
};
