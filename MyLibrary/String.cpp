#include <wtypes.h>
#include "String.h"
#include "Log.h"
#include <stdio.h>

String::String()
{
	length = 1;
	string = new char[length];
	string[0] = '\0';
}

String::String(const char* _string, ...)
{
	length = 0;
	if (_string != NULL)
	{
		static char buff1[4096];
		va_list args;

		va_start(args, _string);
		int res = vsprintf_s(buff1, 4096, _string, args);
		va_end(args);

		if (res > 0)
		{
			length = res + 1;
			string = new char[length];
			strcpy_s(string, length, buff1);
		}
	}
}

String::String(const String& _string)
{
	length = _string.getLenght();
	string = new char[length];
	strcpy_s(string, length, _string.getString());
}

const String& String::operator= (const char* str)
{
	length = strlen(str) + 1;
	delete[] str;
	str = new char[length];
	strcpy_s(string, length, str);
	return (*this);
}
/*
const String& String::operator= (const String& str)
{
	length = str.getLenght();
	strcpy(string, str.getString());
}*/