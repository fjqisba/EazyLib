#include "EazyLib.h"

static const char 码表[] =	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
unsigned char 逆码表[255];
bool 逆码表初始化 = false;

std::string EazyLib::BASE64编码(字节集 编码数据)
{
	char BASE64_PAD = '=';
	std::string 编码结果;
	编码结果.resize((编码数据.size() + 2) / 3 * 4);

	int s = 0;
	unsigned int Len = 0;
	unsigned char lastC = 0;
	for (unsigned int n = 0; n < 编码数据.size(); ++n)
	{
		unsigned char c = 编码数据[n];

		switch (s)
		{
		case 0:
			s = 1;
			编码结果[Len++] = 码表[(c >> 2) & 0x3F];
			break;
		case 1:
			s = 2;
			编码结果[Len++] = 码表[((lastC & 0x3) << 4) | ((c >> 4) & 0xF)];
			break;
		case 2:
			s = 0;
			编码结果[Len++] = 码表[((lastC & 0xF) << 2) | ((c >> 6) & 0x3)];
			编码结果[Len++] = 码表[c & 0x3F];
			break;
		}
		lastC = c;
	}

	switch (s)
	{
	case 1:
		编码结果[Len++] = 码表[(lastC & 0x3) << 4];
		编码结果[Len++] = BASE64_PAD;
		编码结果[Len++] = BASE64_PAD;
		break;
	case 2:
		编码结果[Len++] = 码表[(lastC & 0xF) << 2];
		编码结果[Len++] = BASE64_PAD;
		break;
	}

	return 编码结果;
}

字节集 EazyLib::BASE64解码(std::string 文本)
{
	char BASE64_PAD = '=';

	if (!逆码表初始化)
	{
		for (unsigned int n = 0; n < 64; ++n)
		{
			逆码表[码表[n]] = n;
		}
		逆码表初始化 = true;
	}

	字节集 ret;
	size_t 文本长度 = 文本.size();
	if (文本长度 && (文本长度 & 0x3))
	{
		return ret;
	}

	size_t pos = 0;
	size_t 解码长度= 文本长度 / 4 * 3;
	ret.reserve(解码长度);

	while (pos < 文本长度)
	{
		unsigned char char_0 = 逆码表[(unsigned char)文本[pos + 0]];
		unsigned char char_1 = 逆码表[(unsigned char)文本[pos + 1]];
		ret.push_back((char_0 << 2) + ((char_1 & 0x30) >> 4));

		if (文本[pos + 2] != BASE64_PAD)
		{
			unsigned char char_2 = 逆码表[(unsigned char)文本[pos + 2]];
			ret.push_back(((char_1 & 0xF) << 4) + ((char_2 & 0x3C) >> 2));
			if (文本[pos + 3] != BASE64_PAD)
			{
				unsigned char char_3 = 逆码表[(unsigned char)文本[pos + 3]];
				ret.push_back(((char_2 & 0x03) << 6) + char_3);
			}
		}
		pos += 4;
	}

	return ret;
}