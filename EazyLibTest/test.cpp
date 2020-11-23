#include "字节集.h"
#include "EazyLib.h"
#include <iostream>

using namespace EazyLib;
#include <windows.h>
int main()
{
	std::string test = BASE64编码({ 0x5,0x6,0x77 });
	字节集 ret = BASE64解码(test);

	int a = 0;
	return true;
}