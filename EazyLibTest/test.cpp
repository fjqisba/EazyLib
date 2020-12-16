#include "字节集.h"
#include "EazyLib.h"
#include <iostream>

using namespace EazyLib;
#include <windows.h>
int main()
{
	字节集 test = {0x31};


	字节集 ret = 哈希_SHA256(test);

	int a = 0;
	return true;
}