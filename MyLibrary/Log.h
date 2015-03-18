#ifndef Log_H
#define Log_H

#include <Windows.h>
#include <stdarg.h>
#include <wtypes.h>
#include <stdio.h>

#define log(format, ...) print(__FILE__, __LINE__, format, __VA_ARGS__);



class Log
{
public:
	

	Log();
	~Log();

	static void print(const char file[], int line, const LPCSTR format, ...)
	{
		int nSize = 0;
		static char buff1[4096];
		static char buff2[4096]; 
		memset(buff1, 0, sizeof(buff1));
		memset(buff2, 0, sizeof(buff2));
		va_list args;

		va_start(args, format);
		vsprintf_s(buff1, 4096, format, args);
		va_end(args);
		sprintf_s(buff2, 4096, "\n%s(%d) : %s\n", file, line, buff1);
		OutputDebugString(buff2);

		/*va_start(args, format);
		nSize = vsnprintf_s(buff1, _countof(buff), _TRUNCATE, format, args);
		va_end(ap);

		if (nSize == -1)
			strcpy(buff, "Your log is too large, 4096 characters max\n");
		OutputDebugString(buff);*/
	}

	/*void log(const char file[], int line, const char* format, ...)
	{
		static char tmp_string[4096];
		static char tmp_string2[4096];
		static va_list  ap;

		// Construct the string from variable arguments
		va_start(ap, format);
		vsprintf_s(tmp_string, 4096, format, ap);
		va_end(ap);
		sprintf_s(tmp_string2, 4096, "\n%s(%d) : %s", file, line, tmp_string);
		OutputDebugString(tmp_string2);
	}*/


};



#endif