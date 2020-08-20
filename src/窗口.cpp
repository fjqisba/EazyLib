#include "窗口.h"

void 窗口_投递文本(HWND 窗口句柄, std::string& 文本内容)
{
	//这段代码尚处于测试阶段
	DWORD StartTime = GetTickCount();
	while (GetTickCount() < StartTime + 100)
	{
		SetForegroundWindow(窗口句柄);
	}
	
	for (unsigned int n = 0; n < 文本内容.length(); n++)
	{
		PostMessageA(窗口句柄, WM_CHAR, 文本内容[n], 0);
	}
	return;
}

void 窗口_投递文本(HWND 窗口句柄, std::string 文本内容)
{
	//这段代码尚处于测试阶段
	DWORD StartTime = GetTickCount();
	while (GetTickCount() < StartTime + 100)
	{
		SetForegroundWindow(窗口句柄);
	}

	for (unsigned int n = 0; n < 文本内容.length(); n++)
	{
		PostMessageA(窗口句柄, WM_CHAR, 文本内容[n], 0);
	}
	return;
}