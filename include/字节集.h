#pragma once
#include <vector>
#include <string>

class �ֽڼ�:public std::vector<unsigned char>
{
public:
	�ֽڼ� operator+(const �ֽڼ�& a);
	�ֽڼ�();
	�ֽڼ�(std::initializer_list<unsigned char> _Ilist);
	�ֽڼ�(char* pBuf, unsigned int BufLen);
	�ֽڼ�(unsigned char* pBuf, unsigned int BufLen);
	~�ֽڼ�();
};


//Bufferת�ֽڼ�
�ֽڼ� ���ֽڼ�(unsigned char* pBuf, unsigned int BufLen);

//Bufferת�ֽڼ�
�ֽڼ� ���ֽڼ�(char* pBuf, unsigned int BufLen);

//�ı�ת�ֽڼ�
�ֽڼ� ���ֽڼ�(std::string ��ת��Ϊ�ֽڼ����ı�);

//���ֽڼ���16�����ı���ʾ
std::string �ֽڼ�_�ֽڼ���ʮ������(�ֽڼ�& ԭʼ�ֽڼ�);

//��һ��ʮ�������ı���ԭΪ�ֽڼ�
�ֽڼ� �ֽڼ�_ʮ�����Ƶ��ֽڼ�(std::string& ԭʼ16�����ı�);