#include "melsecplc.h"
#include "ActUtlType64_i.c"
#include "ActProgType64_i.c"
#include "ActSupportMsg64_i.c"
#include "ActUtlDataLogging64_i.c"
#include "ActProgDataLogging64_i.c"
#include "melexception.h"

#include <algorithm>
#include <ctype.h>
#include <comutil.h>
#ifdef _DEBUG
#pragma comment(lib,"comsuppwd.lib")
#else
#pragma comment(lib,"comsuppw.lib")
#endif

MelsecPLC::MelsecPLC()
	:m_pIUtlType(nullptr)
	, m_pIProgType(nullptr)
	, m_pISupportMsg(nullptr)
	, m_StationNumber(1)
{
}

MelsecPLC::~MelsecPLC()
{
	UnInitinal();
}

void MelsecPLC::OnInitial()
{
	HRESULT hr;
	//hr = CoInitialize(nullptr);
	hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	hr = m_pIUtlType.CoCreateInstance(__uuidof(ActUtlType64));
	if (FAILED(hr))
		throw MelException(hr, "ActUtlType64 CoCreateInstance() failed.");

	//method 2:
	hr = m_pIProgType.CoCreateInstance(__uuidof(ActProgType64));
	if (FAILED(hr))
		throw MelException(hr, "ActProgType64 CoCreateInstance() failed.");

	hr = m_pISupportMsg.CoCreateInstance(__uuidof(ActSupportMsg64));
	if (FAILED(hr))
		throw MelException(hr, "ActSupportMsg64 CoCreateInstance() failed.");

	hr = m_pIUtlDataLogging.CoCreateInstance(__uuidof(ActUtlDataLogging64));
	if (FAILED(hr))
		throw MelException(hr, "ActUtlDataLogging64 CoCreateInstance() failed.");

	hr = m_pIProgDataLogging.CoCreateInstance(__uuidof(ActProgDataLogging64));
	if (FAILED(hr))
		throw MelException(hr, "ActProgDataLogging64 CoCreateInstance() failed.");
}

void MelsecPLC::UnInitinal()
{
	//m_pIUtlType.Release();
	//m_pIProgType.Release();
	//m_pISupportMsg.Release();
	//CoUninitialize();
	//tag. don't call CoUninitialize() here, CoInitialize(NULL)/CoUninitialize() at init thread better.
}

long MelsecPLC::Connect(long no, const std::string& password)
{
	OnInitial(); //com init

	HRESULT hr;
	hr = m_pIUtlType->put_ActLogicalStationNumber(no);
	CComBSTR pw = password.c_str();
	hr = m_pIUtlType->put_ActPassword(pw.m_str);
	long ret = -1;
	hr = m_pIUtlType->Open(&ret);
	if (FAILED(hr))
		throw MelException(hr, "MX Component communication failed.");

	//logging
	long ret_log = -1;
	m_pIUtlDataLogging->put_ActLogicalStationNumber(no);
	m_pIUtlDataLogging->put_ActPassword(pw.m_str);
	hr = m_pIUtlDataLogging->Open(&ret_log);
	if (FAILED(hr))
		throw MelException(hr, "MX Component communication failed.");
	return ret;
}

long MelsecPLC::Disconnect()
{
	HRESULT hr;
	long ret = -1;
	hr = m_pIUtlType->Close(&ret);
	if (FAILED(hr))
		throw MelException(hr, "MX Component disconnect communication failed.");

	//logging
	hr = m_pIUtlDataLogging->ReadClose(&ret);
	hr = m_pIUtlDataLogging->Close(&ret);
	if (FAILED(hr))
		throw MelException(hr, "MX Component disconnect communication failed.");
	return ret;
}

long MelsecPLC::GetDevice16Bit(const std::string& dev, short& data)
{
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = dev.c_str();
	hr = m_pIUtlType->GetDevice2(szDev.m_str, &data, &ret);
	return ret;
}

long MelsecPLC::SetDevice16Bit(const std::string& dev, short data)
{
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = dev.c_str();
	hr = m_pIUtlType->SetDevice2(szDev.m_str, data, &ret);
	return ret;
}

//long MelsecPLC::GetDevice32Bit(const std::string& dev, long& data)
//{
//	long ret = COM_ERR;
//	HRESULT hr;
//	CComBSTR szDev = dev.c_str();
//	hr = m_pIUtlType->GetDevice(szDev.m_str, &data, &ret);
//	return ret;
//}
//
//long MelsecPLC::SetDevice32Bit(const std::string& dev, long data)
//{
//	long ret = COM_ERR;
//	HRESULT hr;
//	CComBSTR szDev = dev.c_str();
//	hr = m_pIUtlType->SetDevice(szDev.m_str, data, &ret);
//	return ret;
//}

long MelsecPLC::ReadDeviceRandom16Bit(const std::vector<std::string>& devs, std::vector<short>& datas)
{
	std::string nameFormat;
	for (auto& dev : devs)
		nameFormat += (dev + '\n');
	nameFormat.pop_back();

	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = nameFormat.c_str();
	std::vector<short> buf(devs.size());
	hr = m_pIUtlType->ReadDeviceRandom2(szDev.m_str, devs.size(), buf.data(), &ret);
	datas = std::move(buf);
	return ret;
}

long MelsecPLC::WriteDeviceRandom16Bit(const std::vector<std::string>& devs, const std::vector<short>& datas)
{
	std::string nameFormat;
	for (auto& dev : devs)
		nameFormat += (dev + '\n');
	nameFormat.pop_back();

	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = nameFormat.c_str();
	hr = m_pIUtlType->WriteDeviceRandom2(szDev.m_str, devs.size(), (short*)datas.data(), &ret);
	return ret;
}

//long MelsecPLC::ReadDeviceRandom32Bit(const std::string& dev, long size, long* data)
//{
//	long ret = COM_ERR;
//	HRESULT hr;
//	CComBSTR szDev = dev.c_str();
//	hr = m_pIUtlType->ReadDeviceRandom(szDev.m_str, size, data, &ret);
//	return ret;
//}
//
//long MelsecPLC::WriteDeviceRandom32Bit(const std::string& dev, long size, long* data)
//{
//	long ret = COM_ERR;
//	HRESULT hr;
//	CComBSTR szDev = dev.c_str();
//	hr = m_pIUtlType->WriteDeviceRandom(szDev.m_str, size, data, &ret);
//	return ret;
//}

long MelsecPLC::ReadDeviceBlock16Bit(const std::string& dev, long size, short* data)
{
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = dev.c_str();
	hr = m_pIUtlType->ReadDeviceBlock2(szDev.m_str, size, data, &ret);
	return ret;
}

long MelsecPLC::WriteDeviceBlock16Bit(const std::string& dev, long size, short* data)
{
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = dev.c_str();
	hr = m_pIUtlType->WriteDeviceBlock2(szDev.m_str, size, data, &ret);
	return ret;
}

//long MelsecPLC::ReadDeviceBlock32Bit(const std::string& dev, long size, long* data)
//{
//	long ret = COM_ERR;
//	HRESULT hr;
//	CComBSTR szDev = dev.c_str();
//	hr = m_pIUtlType->ReadDeviceBlock(szDev.m_str, size, data, &ret);
//	return ret;
//}
//
//long MelsecPLC::WriteDeviceBlock32Bit(const std::string& dev, long size, long* data)
//{
//	long ret = COM_ERR;
//	HRESULT hr;
//	CComBSTR szDev = dev.c_str();
//	hr = m_pIUtlType->WriteDeviceBlock(szDev.m_str, size, data, &ret);
//	return ret;
//}

long MelsecPLC::GetDeviceINT32(const std::string& dev, int32_t& data)
{
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = dev.c_str();
	short buf[2] = { 0x0, 0x0 };
	hr = m_pIUtlType->ReadDeviceBlock2(szDev.m_str, 2, buf, &ret);
	data = *((int32_t*)buf);
	return ret;
}

long MelsecPLC::SetDeviceINT32(const std::string& dev, int32_t data)
{
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = dev.c_str();
	short buf[2] = { data & 0xFFFF, data >> 16 };
	hr = m_pIUtlType->WriteDeviceBlock2(szDev.m_str, 2, buf, &ret);
	return ret;
}

long MelsecPLC::ReadDeviceRandomINT32(const std::vector<std::string>& devs, std::vector<int32_t>& datas)
{
	std::string formatName;
	for (auto& dev : devs)
	{
		size_t pos = dev.find_first_of("0123456789");
		std::string_view addrType(dev.c_str(), pos);
		std::string_view addrNumber(dev.c_str() + pos, dev.size() - 1);
		std::string high16bitAddr(addrType);
		high16bitAddr += std::to_string(std::stoi(addrNumber.data()) + 1);
		formatName += (dev + '\n');
		formatName += (high16bitAddr + '\n');
	}
	formatName.pop_back();

	std::vector<short> buf(devs.size() * 2);
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDevList = formatName.c_str();
	hr = m_pIUtlType->ReadDeviceRandom2(szDevList, buf.size(), buf.data(), &ret);
	int32_t* p = (int32_t*)buf.data();
	datas.assign(p, p + devs.size());
	return ret;
}

long MelsecPLC::WriteDeviceRandomINT32(const std::vector<std::string>& devs, const std::vector<int32_t>& datas)
{
	std::string formatName;
	for (auto& dev : devs)
	{
		size_t pos = dev.find_first_of("0123456789");
		std::string_view addrType(dev.c_str(), pos);
		std::string_view addrNumber(dev.c_str() + pos, dev.size() - 1);
		std::string high16bitAddr(addrType);
		high16bitAddr += std::to_string(std::stoi(addrNumber.data()) + 1);
		formatName += (dev + '\n');
		formatName += (high16bitAddr + '\n');
	}
	formatName.pop_back();

	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDevList = formatName.c_str();
	short* p = (short*)datas.data();
	hr = m_pIUtlType->WriteDeviceRandom2(szDevList, datas.size() * 2, p, &ret);
	return ret;
}

long MelsecPLC::ReadDeviceBlockINT32(const std::string& dev, long size, int32_t* data)
{
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = dev.c_str();
	std::vector<short> buf(size * 2);
	hr = m_pIUtlType->ReadDeviceBlock2(szDev.m_str, 2 * size, buf.data(), &ret);
	int32_t* ip = (int32_t*)buf.data();
	std::copy(ip, ip + size, data);
	return ret;
}

long MelsecPLC::WriteDeviceBlockINT32(const std::string& dev, long size, int32_t* data)
{
	long ret = COM_ERR;
	HRESULT hr;
	CComBSTR szDev = dev.c_str();
	std::vector<short> buf;
	short* shp = (short*)data;
	buf.assign(shp, shp + size * 2);
	hr = m_pIUtlType->WriteDeviceBlock2(szDev.m_str, size * 2, buf.data(), &ret);
	return ret;
}

long MelsecPLC::ReadBuffer(long io_addr, long buf_addr, long size, short* data)
{
	long ret = COM_ERR;
	HRESULT hr;
	hr = m_pIUtlType->ReadBuffer(io_addr, buf_addr, size, data, &ret);
	return ret;
}

long MelsecPLC::WriteBuffer(long io_addr, long buf_addr, long size, short* data)
{
	long ret = COM_ERR;
	HRESULT hr;
	hr = m_pIUtlType->WriteBuffer(io_addr, buf_addr, size, data, &ret);
	return ret;
}

long MelsecPLC::GetCpuType(std::string& cpu_name, long& cpu_type)
{
	long ret = COM_ERR;
	HRESULT hr;
	_bstr_t name;
	hr = m_pIUtlType->GetCpuType(&name.GetBSTR(), &cpu_type, &ret);
	cpu_name = name;
	return ret;
	return 0;
}

long MelsecPLC::SetCpuStatus(long op)
{
	long ret = COM_ERR;
	HRESULT hr;
	hr = m_pIUtlType->SetCpuStatus(op, &ret);
	return ret;
}

long MelsecPLC::GetClockData(short& year, short& month, short& day, short& week, short& hour, short& min, short& sec)
{
	long ret = COM_ERR;
	HRESULT hr;
	hr = m_pIUtlType->GetClockData(&year, &month, &day, &week, &hour, &min, &sec, &ret);
	return ret;
}

long MelsecPLC::SetClockData(short year, short month, short day, short week, short hour, short min, short sec)
{
	long ret = COM_ERR;
	HRESULT hr;
	hr = m_pIUtlType->SetClockData(year, month, day, week, hour, min, sec, &ret);
	return ret;
}

long MelsecPLC::GetErrorMessage(long err_code, std::string& err_msg)
{
	long ret = COM_ERR;
	HRESULT hr;
	_bstr_t msg;
	hr = m_pISupportMsg->GetErrorMessage(err_code, &msg.GetBSTR(), &ret);
	err_msg = msg;
	return ret;
}
