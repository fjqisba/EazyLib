#include "����.h"



std::string ȡ����Ŀ¼()
{
	char Buf[260] = { 0 };
	GetCurrentDirectoryA(260, Buf);
	std::string ret = Buf;
	return ret;
}