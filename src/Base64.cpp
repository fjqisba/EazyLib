#include "EazyLib.h"

static const char ���[] =	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
unsigned char �����[255];
bool ������ʼ�� = false;

std::string EazyLib::BASE64����(�ֽڼ� ��������)
{
	char BASE64_PAD = '=';
	std::string ������;
	������.resize((��������.size() + 2) / 3 * 4);

	int s = 0;
	unsigned int Len = 0;
	unsigned char lastC = 0;
	for (unsigned int n = 0; n < ��������.size(); ++n)
	{
		unsigned char c = ��������[n];

		switch (s)
		{
		case 0:
			s = 1;
			������[Len++] = ���[(c >> 2) & 0x3F];
			break;
		case 1:
			s = 2;
			������[Len++] = ���[((lastC & 0x3) << 4) | ((c >> 4) & 0xF)];
			break;
		case 2:
			s = 0;
			������[Len++] = ���[((lastC & 0xF) << 2) | ((c >> 6) & 0x3)];
			������[Len++] = ���[c & 0x3F];
			break;
		}
		lastC = c;
	}

	switch (s)
	{
	case 1:
		������[Len++] = ���[(lastC & 0x3) << 4];
		������[Len++] = BASE64_PAD;
		������[Len++] = BASE64_PAD;
		break;
	case 2:
		������[Len++] = ���[(lastC & 0xF) << 2];
		������[Len++] = BASE64_PAD;
		break;
	}

	return ������;
}

�ֽڼ� EazyLib::BASE64����(std::string �ı�)
{
	char BASE64_PAD = '=';

	if (!������ʼ��)
	{
		for (unsigned int n = 0; n < 64; ++n)
		{
			�����[���[n]] = n;
		}
		������ʼ�� = true;
	}

	�ֽڼ� ret;
	size_t �ı����� = �ı�.size();
	if (�ı����� && (�ı����� & 0x3))
	{
		return ret;
	}

	size_t pos = 0;
	size_t ���볤��= �ı����� / 4 * 3;
	ret.reserve(���볤��);

	while (pos < �ı�����)
	{
		unsigned char char_0 = �����[(unsigned char)�ı�[pos + 0]];
		unsigned char char_1 = �����[(unsigned char)�ı�[pos + 1]];
		ret.push_back((char_0 << 2) + ((char_1 & 0x30) >> 4));

		if (�ı�[pos + 2] != BASE64_PAD)
		{
			unsigned char char_2 = �����[(unsigned char)�ı�[pos + 2]];
			ret.push_back(((char_1 & 0xF) << 4) + ((char_2 & 0x3C) >> 2));
			if (�ı�[pos + 3] != BASE64_PAD)
			{
				unsigned char char_3 = �����[(unsigned char)�ı�[pos + 3]];
				ret.push_back(((char_2 & 0x03) << 6) + char_3);
			}
		}
		pos += 4;
	}

	return ret;
}