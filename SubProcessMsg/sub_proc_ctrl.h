#pragma once

#include "Windows.h"
#include <string>

enum UserMsg
{
	WM_USER_SUB_EXIT = WM_USER + 1024		//子程序退出信号
};

class SubProcessCtrl
{
public:
	SubProcessCtrl();
	~SubProcessCtrl();

	// 回调函数用于枚举窗口
	static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

	void SetApplicationPath(const std::string& appPath);
	void SetApplicationPath(const std::wstring& appPath);

	bool StartSubProcess();		//开始子进程
	int ExitSubProcess();		//请求退出子进程

private:
	//定义子进程的路径
	std::wstring subAppPath;

	// 定义启动信息和进程信息结构
	STARTUPINFOW si;
	PROCESS_INFORMATION pi;

	// 变量存储子进程ID
	DWORD g_subProcessID;
	HWND g_subProcessHWND;
};

