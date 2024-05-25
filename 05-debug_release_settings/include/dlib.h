
#ifndef _WIN32 // linux mac unix android
  #define XCPP_API
#else // windows

  #ifdef dlib_EXPORTS
    #define XCPP_API __declspec(dllexport) // 库项目调用
  #else
    #define XCPP_API __declspec(dllimport) // 调用库项目调用
  #endif

#endif

XCPP_API void dlib();

