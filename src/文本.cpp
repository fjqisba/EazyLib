#include "�ı�.h"



std::string �ı�_ɾ��β��(std::string& Դ�ı�)
{
	if (!Դ�ı�.empty())
	{
		std::string ret = Դ�ı�;
		ret.erase(0, ret.find_first_not_of(" "));
		ret.erase(ret.find_last_not_of(" ") + 1);
		return ret;
	}

	return "";
}

std::string �ı�_ɾȫ����(std::string& Դ�ı�)
{
	int index = 0;
	if (!Դ�ı�.empty())
	{
		std::string ret = Դ�ı�;
		while ((index = ret.find(' ', index)) != std::string::npos)
		{
			ret.erase(index, 1);
		}
		return ret;
	}
	return "";
}