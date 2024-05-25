//////////////////////////////////  @版权说明  //////////////////////////////////////////////////
///						Jiedi(China nanjing)Ltd.                                    
/// @版权说明 代码和课程版权有夏曹俊所拥有并已经申请著作权，此代码可用作为学习参考并可在项目中使用，
/// 课程中涉及到的其他开源软件，请遵守其相应的授权
/// 课程源码不可以直接转载到公开的博客，或者其他共享平台，不可以用以制作在线课程。
/// 课程中涉及到的其他开源软件，请遵守其相应的授权  @@              
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  源码说明  //////////////////////////////////////////////////
/// 项目名称: CMake构建大型c++项目
/// 博客   : 			    http://blog.csdn.net/jiedichina
/// 腾讯课堂			    https://jiedi.ke.qq.com/
/// 学浪				    搜索 夏曹俊
/// 老夏课堂			    http://cppds.com 
/// CMake手册    	        http://cmake.org.cn
/// ！！！请加入课程qq群 【296249312】与同学交流 
/// 欢迎加夏曹俊老师的微信：cppxcj
///加入老夏课堂群【296249312】直接联系群里客服下载课程资料
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// 课程交流qq群296249312 //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////// COMMENT ///////////////////////////////////////////////

//xlog.h
#ifndef XLOG_H
#define XLOG_H
//__declspec(dllexport)
//__declspec(dllexport) 导出XLog类的函数到lib文件中
// xlog库文件调用 dllexport
// test_xlog 调用 dllimport
#ifndef _WIN32 //linux mac unix Android
    #define XCPP_API
#else //windows
    #ifdef xlog_STATIC  //静态库
        #define XCPP_API
    #else               //动态库
        #ifdef xlog_EXPORTS
            #define XCPP_API __declspec(dllexport) //库项目调用
        #else
            #define XCPP_API __declspec(dllimport) //调用库项目调用
        #endif
    #endif
#endif
class XCPP_API XLog
{
public:
	XLog();
};
#endif
/*
102cmake_lib/
├── CMakeLists.txt
├── test_xlog
│?? ├── CMakeLists.txt
│?? └── test_xlog.cpp
└── xlog
    ├── CMakeLists.txt
    ├── xlog.cpp
    └── xlog.h

*/