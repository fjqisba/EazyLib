#pragma once
#include <vector>
#include <string>

class 字节集:public std::vector<unsigned char>
{
public:
	字节集();
	字节集(char* pBuf, unsigned int BufLen);
	字节集(unsigned char* pBuf, unsigned int BufLen);
	~字节集();
};


//Buffer转字节集
字节集 到字节集(unsigned char* pBuf, unsigned int BufLen);

//Buffer转字节集
字节集 到字节集(char* pBuf, unsigned int BufLen);

//将字节集用16进制文本表示
std::string 字节集_字节集到十六进制(字节集& 原始字节集);

//将一串十六进制文本还原为字节集
字节集 字节集_十六进制到字节集(std::string& 原始16进制文本);