#include "Padding.h"

inline unsigned int paddingLength(unsigned int DataLen, unsigned int BlockSize)
{
	return BlockSize - (DataLen % BlockSize);
}

bool CheckNoPadding(unsigned int DataLen, unsigned int BlockSize)
{
	if (DataLen % BlockSize)
	{
		return false;
	}
	return true;
}

void appendZeroPadding(字节集& Data, unsigned int BlockSize)
{
	unsigned int padLen = paddingLength(Data.size(), BlockSize);
	Data.resize(Data.size() + padLen, 0x20);
	return;
}

void removeZeroPadding(字节集& Data, unsigned int BlockSize)
{
	if (Data.size() < BlockSize)
	{
		return;
	}

	unsigned int unpadLen = 0;
	std::vector<unsigned char>::reverse_iterator it = Data.rbegin();
	for (unsigned int n = 0; n < BlockSize; n++)
	{
		if (*it++ != 0)
		{
			break;
		}
		unpadLen++;
	}
	Data.resize(Data.size() - unpadLen);
}

void appendPkcs7Padding(字节集& Data, unsigned int BlockSize)
{
	unsigned char padNum = paddingLength(Data.size(), BlockSize);
	Data.resize(Data.size() + padNum, padNum);
}

void removePkcs7Padding(字节集& Data, unsigned int BlockSize)
{
	if (Data.size() < BlockSize || !Data.size())
	{
		return;
	}

	Data.resize(Data.size() - Data.back());
}