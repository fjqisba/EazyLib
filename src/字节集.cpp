#include "字节集.h"
#include "../public.h"

#include <windows.h>

字节集::字节集()
{
	
}

字节集::~字节集()
{

}

字节集::字节集(std::initializer_list<unsigned char> _Ilist):std::vector<unsigned char>(_Ilist)
{
	return;
}

字节集::字节集(unsigned char* pBuf, unsigned int BufLen)
{
	this->resize(BufLen);
	memcpy(this->data(), pBuf, BufLen);
}

字节集::字节集(char* pBuf, unsigned int BufLen)
{
	this->resize(BufLen);
	memcpy(this->data(), pBuf, BufLen);
}

字节集 字节集::operator+(const 字节集& a)
{
	字节集 ret;
	ret.reserve(this->size() + a.size());
	if (this->size())
	{
		ret.insert(ret.end(), this->begin(), this->end());
	}
	if (a.size())
	{
		ret.insert(ret.end(), a.begin(), a.end());
	}
	return ret;
}

//————————————————————————————————————————————————————

字节集 到字节集(unsigned char* pBuf, unsigned int BufLen)
{
	字节集 ret(pBuf, BufLen);
	return ret;
}

字节集 到字节集(char* pBuf, unsigned int BufLen)
{
	字节集 ret(pBuf, BufLen);
	return ret;
}

字节集 到字节集(std::string 欲转换为字节集的文本)
{
	字节集 ret;
	size_t 文本长度 = 欲转换为字节集的文本.length();
	if (!文本长度)
	{
		return ret;
	}
	ret.resize(文本长度);
	memcpy(ret.data(), 欲转换为字节集的文本.c_str(), 文本长度);
	return ret;
}



std::string 字节集_字节集到十六进制(字节集& 原始字节集)
{
	auto BufLen = 原始字节集.size();
	if (!BufLen)
	{
		return "";
	}

	std::string ret;
	ret.resize(BufLen * 2 + 1, 0x0);
	int Index = 0;
	for (size_t n = 0; n < 原始字节集.size(); n++)
	{
		const char* pHex = UCharToStr(原始字节集[n]);
		ret[Index++] = pHex[0];
		ret[Index++] = pHex[1];
	}
	return ret;
}

字节集 字节集_十六进制到字节集(std::string& 原始16进制文本)
{
	字节集 ret;
	size_t Len = 原始16进制文本.length();
	if (Len & 1)
	{
		return ret;
	}

	ret.resize(Len / 2);
	for (unsigned int n = 0; n < Len / 2; n++)
	{
		ret[n] = StrToUchar(&原始16进制文本[2 * n]);
	}
	return ret;
}
