#include <windows.h>
#include <string>

//获取指定窗口句柄的标题
std::string 窗口_取标题(HWND 窗口句柄);

std::string 窗口_取类名(HWND 窗口句柄);

//向指定窗口句柄的窗口中后台发送文本内容,对游戏有效(无返回值)
void 窗口_投递文本(HWND 窗口句柄,std::string& 文本内容);

//向指定窗口句柄的窗口中后台发送文本内容,对游戏有效(无返回值)
void 窗口_投递文本(HWND 窗口句柄, std::string 文本内容);

