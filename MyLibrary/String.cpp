// String
// Implementation

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
	
	if (_string != NULL && _string[0] != '\0')
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
	
	if (str != NULL)
	{
		int lstr = strlen(str);
		if (lstr > size)
		{
			delete[] string;
			alloc(lstr + 1);
			strcpy_s(string, size, str);
		}
		else
		{
			size = lstr + 1;
			strcpy_s(string, size, str);
		}
	}
	else
	{
		string = "\0";
		size = 1;
	}

	return (*this);


	/*String s1(str); // si faig això em fa un delete i no entenc molt be que passa encara -------------------------- revisar...
	(*this) = s1;
	//(*this) = s; // FA UN DELETEEEEEEEEEEEEE!!!

	return s1;*/
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

bool String::operator!= (const char* str)
{
	return !((*this) == str);
}

bool String::operator!= (const String& str)
{
	return !((*this) == str);;
}

const String& String::operator+= (const char* str)
{
	if (str != NULL)
	{	
		String tmp;
		if (string != "")
			tmp = string;
		else
			tmp = "";
		int tsize = strlen(str) + tmp.length() + 1;
		if (capacity() <= tsize)
		{
			delete[]string;
			alloc(tsize);
		}
		strcpy_s(string, tsize, tmp.getString());
		strcat_s(string, tsize, str);
	}
	else
	{

	}
	return (*this);
}

const String& String::operator+= (const String& str)
{
	if (&str != NULL)
	{
		String tmp(string);
		int tsize = str.length() + tmp.length() + 1;
		if (capacity() <= tsize)
		{
			delete[]string;
			alloc(tsize);
		}
		strcpy_s(string, tsize, tmp.getString());
		strcat_s(string, tsize, str.getString());
	}
	return (*this);
}

void String::alloc(const unsigned int _size)
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