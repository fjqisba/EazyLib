#include "����.h"

void ����_Ͷ���ı�(HWND ���ھ��, std::string& �ı�����)
{
	//��δ����д��ڲ��Խ׶�
	DWORD StartTime = GetTickCount();
	while (GetTickCount() < StartTime + 100)
	{
		SetForegroundWindow(���ھ��);
	}
	
	for (unsigned int n = 0; n < �ı�����.length(); n++)
	{
		PostMessageA(���ھ��, WM_CHAR, �ı�����[n], 0);
	}
	return;
}

void ����_Ͷ���ı�(HWND ���ھ��, std::string �ı�����)
{
	//��δ����д��ڲ��Խ׶�
	DWORD StartTime = GetTickCount();
	while (GetTickCount() < StartTime + 100)
	{
		SetForegroundWindow(���ھ��);
	}

	for (unsigned int n = 0; n < �ı�����.length(); n++)
	{
		PostMessageA(���ھ��, WM_CHAR, �ı�����[n], 0);
	}
	return;
}