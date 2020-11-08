#pragma once
#include "字节集.h"
//数据块填充相关函数



bool CheckNoPadding(unsigned int DataLen, unsigned int BlockSize);

void appendZeroPadding(字节集& Data,unsigned int BlockSize);
void removeZeroPadding(字节集& Data, unsigned int BlockSize);

void appendPkcs7Padding(字节集& Data, unsigned int BlockSize);
void removePkcs7Padding(字节集& Data, unsigned int BlockSize);