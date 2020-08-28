#include "文本.h"



std::string 文本_删首尾空(std::string& 源文本)
{
	if (!源文本.empty())
	{
		std::string ret = 源文本;
		ret.erase(0, ret.find_first_not_of(" "));
		ret.erase(ret.find_last_not_of(" ") + 1);
		return ret;
	}

	return "";
}

std::string 文本_删全部空(std::string& 源文本)
{
	int index = 0;
	if (!源文本.empty())
	{
		std::string ret = 源文本;
		while ((index = ret.find(' ', index)) != std::string::npos)
		{
			ret.erase(index, 1);
		}
		return ret;
	}
	return "";
}