#include "�ֽڼ�.h"
#include "EazyLib.h"
#include <iostream>

using namespace EazyLib;
#include <windows.h>
int main()
{
	�ֽڼ� test = {0x31};

	AESCryptoHelper helper(AESCryptoHelper::AESMode_t::MODE_CBC,EazyLib::zero_padding);

	�ֽڼ� �������� = ���ֽڼ�("type=gettype&username=qw123456q&userpass=qw123456&sn=9854257836495834&sv=1");
	std::string key = "AB97B2C1ED0D9D3D560611295E68F2C9";
	std::string iv =  "69D874A41F529195FBE5D645D274F4AC";
	�ֽڼ� strKey = �ֽڼ�_ʮ�����Ƶ��ֽڼ�(key);
	�ֽڼ� strIv = �ֽڼ�_ʮ�����Ƶ��ֽڼ�(iv);

	auto ��� = helper.Encrypt(��������, strKey, strIv);
	std::string result = �ֽڼ�_�ֽڼ���ʮ������(���);
	std::cout << result << std::endl;
	return true;
}