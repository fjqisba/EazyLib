#include "内存.h"

bool 写内存字节集(unsigned int 进程ID, size_t 地址, 字节集& 数据, size_t 写入长度)
{
	HANDLE 操作句柄;
	if (进程ID == 0xFFFFFFFF)
	{
		操作句柄 = GetCurrentProcess();
	}
	else
	{
		操作句柄 = OpenProcess(PROCESS_ALL_ACCESS, 0, 进程ID);
	}

	bool ret = WriteProcessMemory(操作句柄, (LPVOID)地址, 数据.data(), 写入长度 = 0 ? 数据.size() : 写入长度, 0);
	CloseHandle(操作句柄);
	return ret;
}

bool 写内存文本型(unsigned int 进程ID, size_t 地址, std::string& 内容)
{
	HANDLE 操作句柄;
	if (进程ID == 0xFFFFFFFF)
	{
		操作句柄 = GetCurrentProcess();
	}
	else
	{
		操作句柄 = OpenProcess(PROCESS_ALL_ACCESS, 0, 进程ID);
	}

	字节集 字节集数据 = 到字节集(内容);
	bool ret = WriteProcessMemory(操作句柄, (LPVOID)地址, 字节集数据.data(), 字节集数据.size(), 0);
	CloseHandle(操作句柄);
	return ret;
}