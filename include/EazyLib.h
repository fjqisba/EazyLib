#pragma once
#include "����.h"
#include "����.h"
#include "�ı�.h"
#include "�ֽڼ�.h"
#include "�ڴ�.h"


namespace EazyLib {

	unsigned int ѭ������(unsigned int value, int shift);
	unsigned int ѭ������(unsigned int value, int shift);
	
	//���ܺ�Windows.h����ĺ궨���ͻ,ֻ����Сд��������...
	enum PaddingMode_t
	{
		no_padding,			//�����
		zero_padding,		//ԭʼ���ݲ���������С��������,�����0ֱ�����㱶��Ϊֹ
		pkcs5_padding,		//����ֽڵ���Blockȱ�ٵ��ֽڸ���,Block�Ĵ�С�̶�Ϊ8λ
		pkcs7_padding,		//����ֽڵ���Blockȱ�ٵ��ֽڸ���,Block��ΧΪ0x1-0xFF
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
			MODE_CFB,	//���ķ���ģʽ
			MODE_OFB,	//�������ģʽ
			MODE_CTR	//������ģʽ
		};

		AESCryptoHelper(AESMode_t cryptmode = AESMode_t::MODE_ECB, PaddingMode_t padmode = PaddingMode_t::pkcs7_padding);
		~AESCryptoHelper();

		//��Կ����ֻ��Ϊ16,24����32�ֽ�
		�ֽڼ� Encrypt(�ֽڼ� ��������, �ֽڼ� ��Կ, �ֽڼ� ���� = {});
		�ֽڼ� Decrypt(�ֽڼ� ��������, �ֽڼ� ��Կ, �ֽڼ� ���� = {});
	public:
		//����ģʽһ��ȷ�ϲ��ɸ���
		const AESMode_t m_AESMode;
		const PaddingMode_t m_PaddingMode;

	private:
		void SetKey(�ֽڼ�& key);
		void SetIv(�ֽڼ�& ����);
		bool AppendPadding(�ֽڼ�& ����);
		void RemovePadding(�ֽڼ�& ����);

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
		void AES_CTR_Encrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
		void AES_CTR_Decrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
		void AES_CFB_Encrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
		void AES_CFB_Decrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
		void AES_OFB_Encrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
		void AES_OFB_Decrypt(�ֽڼ�& ��������, �ֽڼ�& ���ܽ��);
	private:
		unsigned int Nk = 0;

		//����غ�����
		unsigned int Nr = 0;

		unsigned char RoundKey[240] = { 0 };
		unsigned char Iv[16] = { 0 };
	};



	
}



