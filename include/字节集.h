#pragma once
#include <vector>
#include <string>

class �ֽڼ�:public std::vector<unsigned char>
{
public:
	�ֽڼ�();
	�ֽڼ�(char* pBuf, unsigned int BufLen);
	�ֽڼ�(unsigned char* pBuf, unsigned int BufLen);
	~�ֽڼ�();
};


//Bufferת�ֽڼ�
�ֽڼ� ���ֽڼ�(unsigned char* pBuf, unsigned int BufLen);

//Bufferת�ֽڼ�
�ֽڼ� ���ֽڼ�(char* pBuf, unsigned int BufLen);

std::string �ֽڼ�_�ֽڼ���ʮ������(�ֽڼ�& ԭʼ�ֽڼ�);