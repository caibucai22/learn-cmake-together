#ifndef LOG_H
#define LOG_H
// __declspec(dllexport) 导出 xlog 到lib文件中

#ifndef _WIN32
#define CPP_API
#else
// 针对 windows 平台
// log 库文件调用 dllexport
// test_log 调用 dllimport
// 通过预定义宏 确定是谁在调用
#ifdef log_EXPORTS
#define CPP_API __declspec(dllexport) // 库项目调用
#else
#define CPP_API __declspec(dllimport) // 调用库项目 调用
#endif
#endif

class CPP_API Log
{
public:
  Log();
};
#endif