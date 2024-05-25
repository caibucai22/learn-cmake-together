// xlog.h
#ifndef XLOG_H
#define XLOG_H
// __declspec(dllexport) 导出 xlog 到lib文件中

#ifndef _WIN32
#define XCPP_API
#else
// 针对 windows 平台
// xlog 库文件调用 dllexport
// test_xlog 调用 dllimport
// 通过预定义宏 确定是谁在调用
#ifdef xlog_EXPORTS
#define XCPP_API __declspec(dllexport) // 库项目调用
#else
#define XCPP_API __declspec(dllimport) // 调用库项目 调用
#endif
#endif

class XCPP_API XLog
{
public:
  XLog();
};
#endif