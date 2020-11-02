#pragma once
#include "窗口.h"
#include "进程.h"
#include "文本.h"
#include "字节集.h"
#include "内存.h"


namespace EazyLib {

	//不能和Windows.h里面的宏定义冲突,只能用小写的名称了...
	enum PaddingMode_t
	{
		no_padding,			//不填充,原始数据必须是分组大小的整数倍，非整数倍时无法使用该模式
		zero_padding,		//原始数据不满足分组大小的整数倍,则填充0直到满足倍数为止
		pkcs5_padding,
		pkcs7_padding,
		//ISO10126_PADDING
	};

	class AESCryptoHelper
	{
	public:
		//出于易用性考虑,使用enum,而不是enum class
		enum AESMode_t
		{
			MODE_ECB,	//电子密码本模式,最简单模式
			MODE_CBC,	//密码分组链接,最常见模式
			//MODE_CFB,	//密文反馈模式
			//MODE_OFB,	//输出反馈模式
			MODE_CTR	//计算器模式
		};
		enum AESKeySize_t
		{
			AES_128,
			AES_192,
			AES_256
		};


		AESCryptoHelper(AESMode_t cryptmode = AESMode_t::MODE_ECB, AESKeySize_t keySize = AESKeySize_t::AES_128, PaddingMode_t padmode = PaddingMode_t::pkcs5_padding);
		~AESCryptoHelper();
		字节集 Encrypt(字节集 加密数据, 字节集 密钥, 字节集 向量 = {});
		字节集 Decrypt(字节集 解密数据, 字节集 密钥, 字节集 向量 = {});
	public:
		//加密模式一旦确认不可更改
		const AESMode_t m_AESMode;
		const AESKeySize_t m_AESKeySize;		//密钥的长度
		const PaddingMode_t m_PaddingMode;

	private:
		void SetKey(字节集& key);
		void SetIv(字节集& 向量);
		void KeyExpansion(unsigned char* RoundKey, unsigned char* Key);


		void Cipher(unsigned char* state);
		void InvCipher(unsigned char* state);

		void SubBytes(unsigned char* state);
		void InvSubBytes(unsigned char* state);
		void ShiftRows(unsigned char* state);
		void InvShiftRows(unsigned char* state);
		void MixColumns(unsigned char* state);
		void InvMixColumns(unsigned char* state);
		void AddRoundKey(unsigned char round, unsigned char* state);

		void AES_ECB_Encrypt(字节集& 加密数据, 字节集& 加密结果);
		void AES_ECB_Decrypt(字节集& 解密数据, 字节集& 解密结果);
		void AES_CBC_Encrypt(字节集& 加密数据, 字节集& 加密结果);
		void AES_CBC_Decrypt(字节集& 解密数据, 字节集& 解密结果);
	private:
		unsigned int Nk = 0;

		//运算回合轮数
		unsigned int Nr = 0;

		unsigned char RoundKey[240] = { 0 };
		unsigned char Iv[16] = { 0 };
	};

}



