#pragma once

#include "字节集.h"
#include <windows.h>


bool 写内存字节集(unsigned int 进程ID, size_t 地址, 字节集& 数据, size_t 写入长度 = 0);

bool 写内存文本型(unsigned int 进程ID, size_t 地址, std::string& 内容);