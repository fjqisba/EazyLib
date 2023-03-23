#include "字节集.h"
#include "EazyLib.h"
#include <iostream>

using namespace EazyLib;
#include <windows.h>
int main()
{
	字节集 test = {0x31};

	AESCryptoHelper helper(AESCryptoHelper::AESMode_t::MODE_CBC,EazyLib::zero_padding);

	字节集 加密数据 = 到字节集("type=gettype&username=qw123456q&userpass=qw123456&sn=9854257836495834&sv=1");
	std::string key = "AB97B2C1ED0D9D3D560611295E68F2C9";
	std::string iv =  "69D874A41F529195FBE5D645D274F4AC";
	字节集 strKey = 字节集_十六进制到字节集(key);
	字节集 strIv = 字节集_十六进制到字节集(iv);

	auto 结果 = helper.Encrypt(加密数据, strKey, strIv);
	std::string result = 字节集_字节集到十六进制(结果);
	std::cout << result << std::endl;
	return true;
}