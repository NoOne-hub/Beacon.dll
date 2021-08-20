#pragma once
#define filename(x) strrchr(x,'\\')?strrchr(x,'\\')+1:x
#define GetLastErrorEx(lpszFunction){LPVOID lpMsgBuf;DWORD dw = GetLastError();FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |FORMAT_MESSAGE_FROM_SYSTEM |FORMAT_MESSAGE_IGNORE_INSERTS,NULL,dw,MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),(LPSTR)&lpMsgBuf,0, NULL);\
if (lpszFunction)\
printf("%s(Line:%d)->Funtion:%s\ndiyInfo:%s\nError(%d)->Info:%s\n",\
filename(__FILE__), __LINE__, __FUNCTION__, lpszFunction, dw, lpMsgBuf);\
else \
printf("%s(Line:%d)->Funtion:%s\nError(%d)->Info:%s\n",\
filename(__FILE__), __LINE__, __FUNCTION__, dw, lpMsgBuf);\
LocalFree(lpMsgBuf);\
getchar();\
}