#include "sub_proc_ctrl.h"

#include <iostream>
#include <filesystem>

SubProcessCtrl::SubProcessCtrl()
{
	// 初始化结构
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	// 句柄信息
	g_subProcessID = 0;
	g_subProcessHWND = nullptr;
}

SubProcessCtrl::~SubProcessCtrl()
{
}

BOOL SubProcessCtrl::EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	SubProcessCtrl* ctrl = reinterpret_cast<SubProcessCtrl*>(lParam);
	DWORD processID;
	GetWindowThreadProcessId(hwnd, &processID);
	if (processID == ctrl->g_subProcessID) {
		ctrl->g_subProcessHWND = hwnd;
		return FALSE; // 找到后停止枚举
	}
	return TRUE; // 继续枚举
}

void SubProcessCtrl::SetApplicationPath(const std::string& appPath)
{
	subAppPath = std::filesystem::path(appPath).wstring();
}

void SubProcessCtrl::SetApplicationPath(const std::wstring& appPath)
{
	subAppPath = appPath;
}

bool SubProcessCtrl::StartSubProcess()
{
	auto appDir = std::filesystem::path(this->subAppPath).parent_path().wstring();

	// 创建子进程
	if (!CreateProcessW(
		subAppPath.data(), // 可执行文件路径
		NULL,              // 命令行参数
		NULL,              // 进程安全属性
		NULL,              // 线程安全属性
		FALSE,			   // 是否继承句柄
		0,                 // 创建标志
		NULL,              // 环境变量
		appDir.data(),     // 当前目录
		&si,               // 启动信息
		&pi                // 进程信息
	)) {
		std::cerr << "CreateProcess failed (" << GetLastError() << ").\n";
		return false;
	}

	std::cout << "SubProcess start sucess, processID: " << pi.dwProcessId << std::endl;
	g_subProcessID = pi.dwProcessId;

	return true;
}

/*此方法对于无窗口进程无效, 无法获取HWND*/
//int SubProcessCtrl::ExitSubProcess()
//{
//	// 枚举所有顶级窗口，找到子进程的窗口句柄
//	EnumWindows(EnumWindowsProc, (LPARAM)this);
//
//	if (g_subProcessHWND != NULL) {
//		// 发送自定义消息请求子进程退出
//		PostMessage(g_subProcessHWND, WM_USER_SUB_EXIT, 0, 0);
//		std::cout << "PostMessage to sub process wnd." << std::endl;
//	}
//	else {
//		std::cerr << "can't find subProcessHWND!" << std::endl;
//	}
//
//	// 等待子进程结束
//	//WaitForSingleObject(pi.hProcess, INFINITE);
//	WaitForSingleObject(pi.hProcess, 5000);
//
//	// 获取子进程的返回码
//	DWORD exitCode = 0;
//	//if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
//	if (TerminateProcess(pi.hProcess, 0)) {
//		std::cout << "SubProcess ExitCode: " << exitCode << std::endl;
//	}
//	else {
//		std::cerr << "obtain SubProcess Exit failed: (" << GetLastError() << ")." << std::endl;
//	}
//
//	// 关闭进程和线程句柄
//	CloseHandle(pi.hProcess);
//	CloseHandle(pi.hThread);
//	return exitCode;
//}

int SubProcessCtrl::ExitSubProcess()
{
	// 发送自定义消息请求子进程退出
	if (!PostThreadMessageA(pi.dwThreadId, WM_USER_SUB_EXIT, 0, 0))
	{
		std::cerr << "PostThreadMessageA error: " << GetLastError() << std::endl;
	}
	else 
	{
		std::cout << "PostThreadMessageA sucess." << std::endl;
	}

	// 等待子进程结束
	WaitForSingleObject(pi.hProcess, 10000);

	// 获取子进程的返回码
	DWORD exitCode = 0;
	//if (TerminateProcess(pi.hProcess, 0)) {
	if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
		std::cout << "SubProcess ExitCode: " << exitCode << std::endl;
	}
	else {
		std::cerr << "obtain SubProcess Exit failed: (" << GetLastError() << ")." << std::endl;
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return exitCode;
}
