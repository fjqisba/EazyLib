#include "�ڴ�.h"

bool д�ڴ��ֽڼ�(unsigned int ����ID, size_t ��ַ, �ֽڼ�& ����, size_t д�볤��)
{
	HANDLE �������;
	if (����ID == 0xFFFFFFFF)
	{
		������� = GetCurrentProcess();
	}
	else
	{
		������� = OpenProcess(PROCESS_ALL_ACCESS, 0, ����ID);
	}

	bool ret = WriteProcessMemory(�������, (LPVOID)��ַ, ����.data(), д�볤�� = 0 ? ����.size() : д�볤��, 0);
	CloseHandle(�������);
	return ret;
}

bool д�ڴ��ı���(unsigned int ����ID, size_t ��ַ, std::string& ����)
{
	HANDLE �������;
	if (����ID == 0xFFFFFFFF)
	{
		������� = GetCurrentProcess();
	}
	else
	{
		������� = OpenProcess(PROCESS_ALL_ACCESS, 0, ����ID);
	}

	�ֽڼ� �ֽڼ����� = ���ֽڼ�(����);
	bool ret = WriteProcessMemory(�������, (LPVOID)��ַ, �ֽڼ�����.data(), �ֽڼ�����.size(), 0);
	CloseHandle(�������);
	return ret;
}