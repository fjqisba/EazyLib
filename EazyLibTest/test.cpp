#include "�ֽڼ�.h"
#include "EazyLib.h"


using namespace EazyLib;
#include <windows.h>
int main()
{

	�ֽڼ� ��Կ = { 0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5,
						0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b };
	�ֽڼ� Iv = { 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff };


	�ֽڼ� �������� = { 0x1a, 0xbc, 0x93, 0x24, 0x17, 0x52, 0x1c, 0xa2, 0x4f, 0x2b, 0x04, 0x59, 0xfe, 0x7e, 0x6e, 0x0b,
						0x09, 0x03, 0x39, 0xec, 0x0a, 0xa6, 0xfa, 0xef, 0xd5, 0xcc, 0xc2, 0xc6, 0xf4, 0xce, 0x8e, 0x94,
						0x1e, 0x36, 0xb2, 0x6b, 0xd1, 0xeb, 0xc6, 0x70, 0xd1, 0xbd, 0x1d, 0x66, 0x56, 0x20, 0xab, 0xf7,
						0x4f, 0x78, 0xa7, 0xf6, 0xd2, 0x98, 0x09, 0x58, 0x5a, 0x97, 0xda, 0xec, 0x58 };

	AESCryptoHelper AesCrypt(AESCryptoHelper::MODE_CTR, AESCryptoHelper::AES_192, no_padding);
	�ֽڼ� ���ܽ�� = AesCrypt.Encrypt(��������, ��Կ, Iv);
	�ֽڼ� ���ܽ�� = AesCrypt.Decrypt(���ܽ��, ��Կ, Iv);
	return true;
}