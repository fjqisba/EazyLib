#include "����.h"

std::string ����_ȡ����(HWND ���ھ��)
{
	std::string ret;
	unsigned int BufLen = GetWindowTextLengthA(���ھ��) + 1;
	char* pBuffer = new char[BufLen];
	if (!pBuffer)
	{
		return ret;
	}
	memset(pBuffer, 0, BufLen);
	GetWindowTextA(���ھ��, pBuffer, BufLen);
	ret = pBuffer;
	delete[] pBuffer;
	return ret;
}

std::string ����_ȡ����(HWND ���ھ��)
{
	std::string ret;
	char* pBuffer = new char[50];
	if (!pBuffer)
	{
		return ret;
	}
	memset(pBuffer, 0, 50);
	GetClassNameA(���ھ��, pBuffer, 50);
	ret = pBuffer;
	delete[] pBuffer;
	return ret;
}

void ����_Ͷ���ı�(HWND ���ھ��, std::string& �ı�����)
{
	for (unsigned int n = 0; n < �ı�����.length(); n++)
	{
		PostMessageA(���ھ��, WM_CHAR, �ı�����[n], 0);
	}
	return;
}

void ����_Ͷ���ı�(HWND ���ھ��, std::string �ı�����)
{
	for (unsigned int n = 0; n < �ı�����.length(); n++)
	{
		PostMessageA(���ھ��, WM_CHAR, �ı�����[n], 0);
	}
	return;
}