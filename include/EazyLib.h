#pragma once
#include "����.h"
#include "����.h"
#include "�ı�.h"
#include "�ֽڼ�.h"
#include "�ڴ�.h"


namespace EazyLib {

	//���ܺ�Windows.h����ĺ궨���ͻ,ֻ����Сд��������...
	enum PaddingMode_t
	{
		no_padding,			//�����,ԭʼ���ݱ����Ƿ����С������������������ʱ�޷�ʹ�ø�ģʽ
		zero_padding,		//ԭʼ���ݲ���������С��������,�����0ֱ�����㱶��Ϊֹ
		pkcs5_padding,
		pkcs7_padding,
		//ISO10126_PADDING
	};

	class AESCryptoHelper
	{
	public:
		//���������Կ���,ʹ��enum,������enum class
		enum AESMode_t
		{
			MODE_ECB,	//�������뱾ģʽ,���ģʽ
			MODE_CBC,	//�����������,���ģʽ
			//MODE_CFB,	//���ķ���ģʽ
			//MODE_OFB,	//�������ģʽ
			MODE_CTR	//������ģʽ
		};
		enum AESKeySize_t
		{
			AES_128,
			AES_192,
			AES_256
		};


		AESCryptoHelper(AESMode_t cryptmode = AESMode_t::MODE_ECB, AESKeySize_t keySize = AESKeySize_t::AES_128, PaddingMode_t padmode = PaddingMode_t::pkcs5_padding);
		~AESCryptoHelper();
		�ֽڼ� Encrypt(�ֽڼ� ��������, �ֽڼ� ��Կ, �ֽڼ� ���� = {});
		�ֽڼ� Decrypt(�ֽڼ� ��������, �ֽڼ� ��Կ, �ֽڼ� ���� = {});
	public:
		//����ģʽһ��ȷ�ϲ��ɸ���
		const AESMode_t m_AESMode;
		const AESKeySize_t m_AESKeySize;		//��Կ�ĳ���
		const PaddingMode_t m_PaddingMode;

	private:
		void SetKey(�ֽڼ�& key);
		void SetIv(�ֽڼ�& ����);
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

		void AES_ECB_Encrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
		void AES_ECB_Decrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
		void AES_CBC_Encrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
		void AES_CBC_Decrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
	private:
		unsigned int Nk = 0;

		//����غ�����
		unsigned int Nr = 0;

		unsigned char RoundKey[240] = { 0 };
		unsigned char Iv[16] = { 0 };
	};

}



