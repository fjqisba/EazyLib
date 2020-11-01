#include "EazyLib.h"
#include "Padding.h"

const unsigned char Sbox[256] =
{ /*  0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f */
	0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76, /*0*/
	0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0, /*1*/
	0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15, /*2*/
	0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75, /*3*/
	0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84, /*4*/
	0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf, /*5*/
	0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8, /*6*/
	0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2, /*7*/
	0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73, /*8*/
	0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb, /*9*/
	0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79, /*a*/
	0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08, /*b*/
	0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a, /*c*/
	0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e, /*d*/
	0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf, /*e*/
	0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16  /*f*/
};

const unsigned char InvSbox[256] =
{ /*  0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f  */
	0x52,0x09,0x6a,0xd5,0x30,0x36,0xa5,0x38,0xbf,0x40,0xa3,0x9e,0x81,0xf3,0xd7,0xfb, /*0*/
	0x7c,0xe3,0x39,0x82,0x9b,0x2f,0xff,0x87,0x34,0x8e,0x43,0x44,0xc4,0xde,0xe9,0xcb, /*1*/
	0x54,0x7b,0x94,0x32,0xa6,0xc2,0x23,0x3d,0xee,0x4c,0x95,0x0b,0x42,0xfa,0xc3,0x4e, /*2*/
	0x08,0x2e,0xa1,0x66,0x28,0xd9,0x24,0xb2,0x76,0x5b,0xa2,0x49,0x6d,0x8b,0xd1,0x25, /*3*/
	0x72,0xf8,0xf6,0x64,0x86,0x68,0x98,0x16,0xd4,0xa4,0x5c,0xcc,0x5d,0x65,0xb6,0x92, /*4*/
	0x6c,0x70,0x48,0x50,0xfd,0xed,0xb9,0xda,0x5e,0x15,0x46,0x57,0xa7,0x8d,0x9d,0x84, /*5*/
	0x90,0xd8,0xab,0x00,0x8c,0xbc,0xd3,0x0a,0xf7,0xe4,0x58,0x05,0xb8,0xb3,0x45,0x06, /*6*/
	0xd0,0x2c,0x1e,0x8f,0xca,0x3f,0x0f,0x02,0xc1,0xaf,0xbd,0x03,0x01,0x13,0x8a,0x6b, /*7*/
	0x3a,0x91,0x11,0x41,0x4f,0x67,0xdc,0xea,0x97,0xf2,0xcf,0xce,0xf0,0xb4,0xe6,0x73, /*8*/
	0x96,0xac,0x74,0x22,0xe7,0xad,0x35,0x85,0xe2,0xf9,0x37,0xe8,0x1c,0x75,0xdf,0x6e, /*9*/
	0x47,0xf1,0x1a,0x71,0x1d,0x29,0xc5,0x89,0x6f,0xb7,0x62,0x0e,0xaa,0x18,0xbe,0x1b, /*a*/
	0xfc,0x56,0x3e,0x4b,0xc6,0xd2,0x79,0x20,0x9a,0xdb,0xc0,0xfe,0x78,0xcd,0x5a,0xf4, /*b*/
	0x1f,0xdd,0xa8,0x33,0x88,0x07,0xc7,0x31,0xb1,0x12,0x10,0x59,0x27,0x80,0xec,0x5f, /*c*/
	0x60,0x51,0x7f,0xa9,0x19,0xb5,0x4a,0x0d,0x2d,0xe5,0x7a,0x9f,0x93,0xc9,0x9c,0xef, /*d*/
	0xa0,0xe0,0x3b,0x4d,0xae,0x2a,0xf5,0xb0,0xc8,0xeb,0xbb,0x3c,0x83,0x53,0x99,0x61, /*e*/
	0x17,0x2b,0x04,0x7e,0xba,0x77,0xd6,0x26,0xe1,0x69,0x14,0x63,0x55,0x21,0x0c,0x7d  /*f*/
};

unsigned char xtime(unsigned char x)
{
	return ((x << 1) ^ (((x >> 7) & 1) * 0x1b));
}

unsigned char Multiply(unsigned char x, unsigned char y)
{
	return (((y & 1) * x) ^
		((y >> 1 & 1) * xtime(x)) ^
		((y >> 2 & 1) * xtime(xtime(x))) ^
		((y >> 3 & 1) * xtime(xtime(xtime(x)))) ^
		((y >> 4 & 1) * xtime(xtime(xtime(xtime(x)))))); /* this last call to xtime() can be omitted */
}

// This function adds the round key to state.
// The round key is added to the state by an XOR function.
void EazyLib::AESCryptoHelper::AddRoundKey(unsigned char round, unsigned char* state)
{
	for (unsigned char n = 0; n < 16; ++n)
	{
		state[n] ^= RoundKey[4 * 4 * round + n];
	}
}

void EazyLib::AESCryptoHelper::MixColumns(unsigned char* state)
{
	unsigned char i;
	unsigned char Tmp, Tm, t;
	for (i = 0; i < 4; ++i)
	{
		t = state[4 * i + 0];
		Tmp = state[4 * i + 0] ^ state[4 * i + 1] ^ state[4 * i + 2] ^ state[4 * i + 3];
		Tm = state[4 * i + 0] ^ state[4 * i + 1]; Tm = xtime(Tm);  state[4 * i + 0] ^= Tm ^ Tmp;
		Tm = state[4 * i + 1] ^ state[4 * i + 2]; Tm = xtime(Tm);  state[4 * i + 1] ^= Tm ^ Tmp;
		Tm = state[4 * i + 2] ^ state[4 * i + 3]; Tm = xtime(Tm);  state[4 * i + 2] ^= Tm ^ Tmp;
		Tm = state[4 * i + 3] ^ t;              Tm = xtime(Tm);  state[4 * i + 3] ^= Tm ^ Tmp;
	}
}

void EazyLib::AESCryptoHelper::InvMixColumns(unsigned char* state)
{
	int i;
	unsigned char a, b, c, d;
	for (i = 0; i < 4; ++i)
	{
		a = state[4 * i + 0];
		b = state[4 * i + 1];
		c = state[4 * i + 2];
		d = state[4 * i + 3];

		state[4 * i + 0] = Multiply(a, 0x0e) ^ Multiply(b, 0x0b) ^ Multiply(c, 0x0d) ^ Multiply(d, 0x09);
		state[4 * i + 1] = Multiply(a, 0x09) ^ Multiply(b, 0x0e) ^ Multiply(c, 0x0b) ^ Multiply(d, 0x0d);
		state[4 * i + 2] = Multiply(a, 0x0d) ^ Multiply(b, 0x09) ^ Multiply(c, 0x0e) ^ Multiply(d, 0x0b);
		state[4 * i + 3] = Multiply(a, 0x0b) ^ Multiply(b, 0x0d) ^ Multiply(c, 0x09) ^ Multiply(d, 0x0e);
	}
}

void EazyLib::AESCryptoHelper::SubBytes(unsigned char* state)
{
	for (unsigned int n = 0; n < 16; ++n)
	{
		state[n] = Sbox[state[n]];
	}
}

void EazyLib::AESCryptoHelper::InvSubBytes(unsigned char* state)
{
	for (unsigned int n = 0; n < 16; ++n)
	{
		state[n] = InvSbox[state[n]];
	}
}



void EazyLib::AESCryptoHelper::InvShiftRows(unsigned char* state)
{
	unsigned char temp;

	// Rotate first row 1 columns to right  
	temp = state[13];
	state[13] = state[9];
	state[9] = state[5];
	state[5] = state[1];
	state[1] = temp;

	// Rotate second row 2 columns to right 
	temp = state[2];
	state[2] = state[10];
	state[10] = temp;

	temp = state[6];
	state[6] = state[14];
	state[14] = temp;

	// Rotate third row 3 columns to right
	temp = state[3];
	state[3] = state[7];
	state[7] = state[11];
	state[11] = state[15];
	state[15] = temp;
}

void EazyLib::AESCryptoHelper::ShiftRows(unsigned char* state)
{
	unsigned char temp;

	// Rotate first row 1 columns to left  
	temp = state[1];
	state[1] = state[5];
	state[5] = state[9];
	state[9] = state[13];
	state[13] = temp;

	// Rotate second row 2 columns to left  
	temp = state[2];
	state[2] = state[10];
	state[10] = temp;

	temp = state[6];
	state[6] = state[14];
	state[14] = temp;

	// Rotate third row 3 columns to left
	temp = state[3];
	state[3] = state[15];
	state[15] = state[11];
	state[11] = state[7];
	state[7] = temp;
}


void EazyLib::AESCryptoHelper::Cipher(unsigned char* state)
{
	AddRoundKey(0, state);

	unsigned char round = 0;
	for (round = 1; round < Nr; round++) {
		SubBytes(state);
		ShiftRows(state);
		MixColumns(state);
		AddRoundKey(round, state);
	}

	SubBytes(state);
	ShiftRows(state);
	AddRoundKey(Nr, state);
}

void EazyLib::AESCryptoHelper::InvCipher(unsigned char* state)
{
	AddRoundKey(Nr, state);

	unsigned char round = 0;
	for (round = Nr - 1; round > 0; round--) {
		InvShiftRows(state);
		InvSubBytes(state);
		AddRoundKey(round, state);
		InvMixColumns(state);
	}

	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(0, state);
}

EazyLib::AESCryptoHelper::AESCryptoHelper(AESMode_t cryptmode,AESBlockSize_t blocksize,PaddingMode_t padmode):m_AESMode(cryptmode),m_AESBlockSize(blocksize),m_PaddingMode(padmode)
{
	switch (m_AESBlockSize)
	{
	case AESCryptoHelper::AESBlockSize_t::AES_128:
		Nk = 4;
		Nr = 10;
		break;
	case AESCryptoHelper::AESBlockSize_t::AES_192:
		Nk = 6;
		Nr = 12;
		break;
	case AESCryptoHelper::AESBlockSize_t::AES_256:
		Nk = 8;
		Nr = 14;
		break;
	default:
		break;
	}
}

EazyLib::AESCryptoHelper::~AESCryptoHelper()
{

}

字节集 EazyLib::AESCryptoHelper::Encrypt(字节集 加密数据, 字节集 密钥, 字节集 向量)
{
	SetKey(密钥);
	SetIv(向量);

	switch (m_PaddingMode)
	{
	case PaddingMode_t::no_padding:
		if (!CheckNoPadding(加密数据.size(), (unsigned int)m_AESBlockSize))
		{
			return {};
		}
		break;
	case PaddingMode_t::zero_padding:
		appendZeroPadding(加密数据, (unsigned int)m_AESBlockSize);
		break;
	default:
		break;
	}


	字节集 加密结果;
	switch (m_AESMode)
	{
	case AESCryptoHelper::AESMode_t::MODE_ECB:
		AES_ECB_Encrypt(加密数据, 加密结果);
		break;
	case AESCryptoHelper::AESMode_t::MODE_CBC:
		break;
	case AESCryptoHelper::AESMode_t::MODE_CTR:
		break;
	default:
		break;
	}


	return 加密结果;
}

字节集 EazyLib::AESCryptoHelper::Decrypt(字节集 解密数据, 字节集 密钥, 字节集 向量)
{
	SetKey(密钥);
	SetIv(向量);

	字节集 解密结果;
	switch (m_AESMode)
	{
	case AESCryptoHelper::AESMode_t::MODE_ECB:
		AES_ECB_Decrypt(解密数据, 解密结果);
		break;
	case AESCryptoHelper::AESMode_t::MODE_CBC:
		break;
	case AESCryptoHelper::AESMode_t::MODE_CTR:
		break;
	default:
		break;
	}

	switch (m_PaddingMode)
	{
	case PaddingMode_t::no_padding:
		break;
	case PaddingMode_t::zero_padding:
		removeZeroPadding(解密结果, (unsigned int)m_AESBlockSize);
		break;
	default:
		break;
	}

	return 解密结果;
}



void EazyLib::AESCryptoHelper::AES_ECB_Encrypt(字节集& 加密数据, 字节集& 加密结果)
{
	//Block加密轮数
	for (unsigned int n = 0; n < 加密数据.size() / 16; n++)
	{
		Cipher(加密数据.data() + n * 16);
	}
	加密结果 = 加密数据;
}

void EazyLib::AESCryptoHelper::AES_ECB_Decrypt(字节集& 解密数据, 字节集& 解密结果)
{
	//Block加密轮数
	for (unsigned int n = 0; n < 解密数据.size() / 16; n++)
	{
		InvCipher(解密数据.data() + n * 16);
	}
	解密结果 = 解密数据;
}

void EazyLib::AESCryptoHelper::SetKey(字节集& key)
{
	//AES128,密钥长度16字节
	//AES192,密钥长度24字节
	//AES256,密钥长度32字节

	switch (m_AESBlockSize)
	{
	case AESCryptoHelper::AESBlockSize_t::AES_128:
		if (key.size() < 16)
		{
			key.resize(16, 0x0);
		}
		break;
	case AESCryptoHelper::AESBlockSize_t::AES_192:
		if (key.size() < 24)
		{
			key.resize(24, 0x0);
		}
		break;
	case AESCryptoHelper::AESBlockSize_t::AES_256:
		if (key.size() < 32)
		{
			key.resize(32, 0x0);
		}
		break;
	default:
		break;
	}
	KeyExpansion(RoundKey, key.data());
}

void EazyLib::AESCryptoHelper::SetIv(字节集& 向量)
{
	//ECB和CTR模式忽略IV
	switch (m_AESMode)
	{
	case AESCryptoHelper::AESMode_t::MODE_ECB:
		return;
	case AESCryptoHelper::AESMode_t::MODE_CTR:
		return;
	default:
		break;
	}

	if (向量.size() < 16)
	{
		向量.resize(16, 0x0);
	}
	memcpy(Iv, 向量.data(), 16);
}

void EazyLib::AESCryptoHelper::KeyExpansion(unsigned char* RoundKey, unsigned char* Key)
{
	// The round constant word array, Rcon[i], contains the values given by 
	// x to the power (i-1) being powers of x (x is denoted as {02}) in the field GF(2^8)
	const unsigned char Rcon[11] = {
	  0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };

	/*
	 * Jordan Goulder points out in PR #12 (https://github.com/kokke/tiny-AES-C/pull/12),
	 * that you can remove most of the elements in the Rcon array, because they are unused.
	 *
	 * From Wikipedia's article on the Rijndael key schedule @ https://en.wikipedia.org/wiki/Rijndael_key_schedule#Rcon
	 *
	 * "Only the first some of these constants are actually used – up to rcon[10] for AES-128 (as 11 round keys are needed),
	 *  up to rcon[8] for AES-192, up to rcon[7] for AES-256. rcon[0] is not used in AES algorithm."
	 */


	// The number of columns comprising a state in AES. This is a constant in AES. Value=4
	unsigned int Nb = 4;

	unsigned i, j, k;
	unsigned char tempa[4]; // Used for the column/row operations

	// The first round key is the key itself.
	for (i = 0; i < Nk; ++i)
	{
		RoundKey[(i * 4) + 0] = Key[(i * 4) + 0];
		RoundKey[(i * 4) + 1] = Key[(i * 4) + 1];
		RoundKey[(i * 4) + 2] = Key[(i * 4) + 2];
		RoundKey[(i * 4) + 3] = Key[(i * 4) + 3];
	}
	// All other round keys are found from the previous round keys.
	for (i = Nk; i < Nb * (Nr + 1); ++i)
	{
		{
			k = (i - 1) * 4;
			tempa[0] = RoundKey[k + 0];
			tempa[1] = RoundKey[k + 1];
			tempa[2] = RoundKey[k + 2];
			tempa[3] = RoundKey[k + 3];

		}

		if (i % Nk == 0)
		{
			// This function shifts the 4 bytes in a word to the left once.
			// [a0,a1,a2,a3] becomes [a1,a2,a3,a0]

			// Function RotWord()
			{
				const uint8_t u8tmp = tempa[0];
				tempa[0] = tempa[1];
				tempa[1] = tempa[2];
				tempa[2] = tempa[3];
				tempa[3] = u8tmp;
			}

			// SubWord() is a function that takes a four-byte input word and 
			// applies the S-box to each of the four bytes to produce an output word.

			// Function Subword()
			{
				tempa[0] = Sbox[tempa[0]];
				tempa[1] = Sbox[tempa[1]];
				tempa[2] = Sbox[tempa[2]];
				tempa[3] = Sbox[tempa[3]];
			}

			tempa[0] = tempa[0] ^ Rcon[i / Nk];
		}
		else if (m_AESBlockSize == AESBlockSize_t::AES_256 && i % Nk == 4)
		{
			// Function Subword()
			{
				tempa[0] = Sbox[tempa[0]];
				tempa[1] = Sbox[tempa[1]];
				tempa[2] = Sbox[tempa[2]];
				tempa[3] = Sbox[tempa[3]];
			}
		}

		j = i * 4; k = (i - Nk) * 4;
		RoundKey[j + 0] = RoundKey[k + 0] ^ tempa[0];
		RoundKey[j + 1] = RoundKey[k + 1] ^ tempa[1];
		RoundKey[j + 2] = RoundKey[k + 2] ^ tempa[2];
		RoundKey[j + 3] = RoundKey[k + 3] ^ tempa[3];
	}
}