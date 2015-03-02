#include <wtypes.h>
#include "String.h"
#include "Log.h"
#include <stdio.h>

String::String()
{
	alloc(1);
	clear();
}

String::String(const char* _string, ...)
{
	//length = 0;
	if (_string != NULL && _string != "")
	{
		static char buff1[4096];
		va_list args;

		va_start(args, _string);
		int res = vsprintf_s(buff1, 4096, _string, args);
		va_end(args);

		if (res > 0)
		{
			alloc(res + 1);
			strcpy_s(string, size, buff1);
		}
	}
	else
	{
		alloc(1);
		clear();
	}
}

String::String(const String& _string)
{
	if (&_string != NULL)
	{
		alloc(_string.length()+1);
		strcpy_s(string, size, _string.getString());
	}
	else
	{
		alloc(1);
		clear();
	}
}

String::~String()
{
	delete[]string;
}

const String& String::operator= (const char* str)
{
	String s(str);
	
	(*this) = s; // FAU N DELETEEEEEEEEEEEEE!!!

	return (*this);
}
const String& String::operator= (const String& str)
{
	if (str.getString() != NULL)
	{
		if (str.length() > size)
		{
			delete[] string;
			alloc(str.length()+1);
			strcpy_s(string, size, str.getString());
		}
		else
		{
			size = str.length()+1;
			strcpy_s(string, size, str.getString());
		}		
	}
	else
	{
		string = "\0";
		size = 1;
	}

	return (*this);
}

bool String::operator== (const char* str)
{
	if (str != NULL)
		return strcmp(str, string) == 0;
	else
		return false;
}
bool String::operator== (const String& str)
{
	if (&str != NULL && str.getString() != NULL)
		return strcmp(str.getString(), string) == 0;
	else
		return false;

}



/*const String& String::operator!= (const char* str)
{

}*/
/*const String& String::operator!= (const String& str)
{

}*/
/*const String& String::operator+= (const char* str)
{

}*/
const String& String::operator+= (const String& str)
{


	return (*this);
}

void String::alloc(const int _size)
{
	size = _size;
	string = new char[_size];
}

/*
const String& String::operator= (const String& str)
{
	length = str.getLenght();
	strcpy(string, str.getString());
}*/