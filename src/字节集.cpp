#include "�ֽڼ�.h"
#include "../public.h"

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
	ret.resize(BufLen * 2 + 1, 0x0);
	int Index = 0;
	for (size_t n = 0; n < ԭʼ�ֽڼ�.size(); n++)
	{
		const char* pHex = UCharToStr(ԭʼ�ֽڼ�[n]);
		ret[Index++] = pHex[0];
		ret[Index++] = pHex[1];
	}
	return ret;
}

�ֽڼ� �ֽڼ�_ʮ�����Ƶ��ֽڼ�(std::string& ԭʼ16�����ı�)
{
	�ֽڼ� ret;
	size_t Len = ԭʼ16�����ı�.length();
	if (Len & 1)
	{
		return ret;
	}

	ret.resize(Len / 2);
	for (unsigned int n = 0; n < Len / 2; n++)
	{
		ret[n] = StrToUchar(&ԭʼ16�����ı�[2 * n]);
	}
	return ret;
}


�ֽڼ� ���ֽڼ�(std::string& ��ת��Ϊ�ֽڼ����ı�)
{
	�ֽڼ� ret;
	size_t �ı����� = ��ת��Ϊ�ֽڼ����ı�.length();
	if (!�ı�����)
	{
		return ret;
	}
	ret.resize(�ı�����);
	memcpy(ret.data(), ��ת��Ϊ�ֽڼ����ı�.c_str(), �ı�����);
	return ret;
}