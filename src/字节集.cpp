#include "�ֽڼ�.h"
#include "../EazyLib.h"

�ֽڼ�::�ֽڼ�()
{

}

�ֽڼ�::~�ֽڼ�()
{

}

�ֽڼ�::�ֽڼ�(unsigned char* pBuf, unsigned int BufLen)
{
	this->resize(BufLen);
	memcpy(this->data(), pBuf, BufLen);
}

�ֽڼ�::�ֽڼ�(char* pBuf, unsigned int BufLen)
{
	this->resize(BufLen);
	memcpy(this->data(), pBuf, BufLen);
}

//��������������������������������������������������������������������������������������������������������

�ֽڼ� ���ֽڼ�(unsigned char* pBuf, unsigned int BufLen)
{
	�ֽڼ� ret(pBuf, BufLen);
	return ret;
}

�ֽڼ� ���ֽڼ�(char* pBuf, unsigned int BufLen)
{
	�ֽڼ� ret(pBuf, BufLen);
	return ret;
}

std::string �ֽڼ�_�ֽڼ���ʮ������(�ֽڼ�& ԭʼ�ֽڼ�)
{
	auto BufLen = ԭʼ�ֽڼ�.size();
	if (!BufLen)
	{
		return "";
	}

	std::string ret;
	char* NewBuf = new char[BufLen * 2 + 1];
	int Index = 0;
	for (size_t n = 0; n < ԭʼ�ֽڼ�.size(); n++)
	{
		const char* pHex = UCharToStr(ԭʼ�ֽڼ�[n]);
		NewBuf[Index++] = pHex[0];
		NewBuf[Index++] = pHex[1];
	}
	NewBuf[Index] = 0x0;
	ret = NewBuf;
	delete[] NewBuf;
	return ret;
}