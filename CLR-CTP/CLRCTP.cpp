// 这是主 DLL 文件。

#include "stdafx.h"

#include "CLRCTP.h"

#include <ctime>
#include <iostream>
#include <atomic>
#include <windows.h>
#include <Dbghelp.h>

LONG WINAPI ExpFilter(struct _EXCEPTION_POINTERS *pExp)
{

	time_t now;
	time(&now);

	// 定义两个变量，存储转换结果
	struct tm tmTmp;
	char stTmp[256] = { 0 };

	// 转换为tm结构
	localtime_s(&tmTmp, &now);


	wchar_t dest[256];
	wcsftime(dest, 80, L"%Y-%m-%d-%H-%M-%S.dmp", &tmTmp);


	HANDLE hFile = ::CreateFile(
		dest,
		GENERIC_WRITE,
		0,
		nullptr,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr);
	if (INVALID_HANDLE_VALUE != hFile)
	{
		MINIDUMP_EXCEPTION_INFORMATION einfo;
		einfo.ThreadId = ::GetCurrentThreadId();
		einfo.ExceptionPointers = pExp;
		einfo.ClientPointers = FALSE;

		::MiniDumpWriteDump(
			::GetCurrentProcess(),
			::GetCurrentProcessId(),
			hFile,
			MiniDumpWithFullMemory,
			&einfo,
			nullptr,
			nullptr);
		CloseHandle(hFile);
	}
	std::cout << "Unhandled Exception!!!" << std::endl;
	return EXCEPTION_EXECUTE_HANDLER;
}

std::atomic_bool total(false);

void StartUnhandledExceptionFilter()
{
	if (!total)
	{
		SetUnhandledExceptionFilter(ExpFilter);
		total = true;
	}

}
