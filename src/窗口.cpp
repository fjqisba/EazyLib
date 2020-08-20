#include "窗口.h"

std::string 窗口_取标题(HWND 窗口句柄)
{
	std::string ret;
	unsigned int BufLen = GetWindowTextLengthA(窗口句柄) + 1;
	char* pBuffer = new char[BufLen];
	if (!pBuffer)
	{
		return ret;
	}
	memset(pBuffer, 0, BufLen);
	GetWindowTextA(窗口句柄, pBuffer, BufLen);
	ret = pBuffer;
	delete[] pBuffer;
	return ret;
}

std::string 窗口_取类名(HWND 窗口句柄)
{
	std::string ret;
	char* pBuffer = new char[50];
	if (!pBuffer)
	{
		return ret;
	}
	memset(pBuffer, 0, 50);
	GetClassNameA(窗口句柄, pBuffer, 50);
	ret = pBuffer;
	delete[] pBuffer;
	return ret;
}

void 窗口_投递文本(HWND 窗口句柄, std::string& 文本内容)
{
	for (unsigned int n = 0; n < 文本内容.length(); n++)
	{
		PostMessageA(窗口句柄, WM_CHAR, 文本内容[n], 0);
	}
	return;
}

void 窗口_投递文本(HWND 窗口句柄, std::string 文本内容)
{
	for (unsigned int n = 0; n < 文本内容.length(); n++)
	{
		PostMessageA(窗口句柄, WM_CHAR, 文本内容[n], 0);
	}
	return;
}