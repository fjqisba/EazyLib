#include "进程.h"



std::string 取运行目录()
{
	char Buf[260] = { 0 };
	GetCurrentDirectoryA(260, Buf);
	std::string ret = Buf;
	return ret;
}