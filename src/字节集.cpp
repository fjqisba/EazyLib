#include "字节集.h"
#include "../EazyLib.h"

字节集::字节集()
{

}

字节集::~字节集()
{

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

std::string 字节集_字节集到十六进制(字节集& 原始字节集)
{
	auto BufLen = 原始字节集.size();
	if (!BufLen)
	{
		return "";
	}

	std::string ret;
	char* NewBuf = new char[BufLen * 2 + 1];
	int Index = 0;
	for (size_t n = 0; n < 原始字节集.size(); n++)
	{
		const char* pHex = UCharToStr(原始字节集[n]);
		NewBuf[Index++] = pHex[0];
		NewBuf[Index++] = pHex[1];
	}
	NewBuf[Index] = 0x0;
	ret = NewBuf;
	delete[] NewBuf;
	return ret;
}