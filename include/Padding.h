#pragma once
#include "�ֽڼ�.h"
//���ݿ������غ���



bool CheckNoPadding(unsigned int DataLen, unsigned int BlockSize);

void appendZeroPadding(�ֽڼ�& Data,unsigned int BlockSize);
void removeZeroPadding(�ֽڼ�& Data, unsigned int BlockSize);

void appendPkcs7Padding(�ֽڼ�& Data, unsigned int BlockSize);
void removePkcs7Padding(�ֽڼ�& Data, unsigned int BlockSize);