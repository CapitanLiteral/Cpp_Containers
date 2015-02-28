#ifndef String_H
#define String_H

// Mai surt de rang! o si


class String
{
	public:
		String();
		String(const char*, ...);
		String(const String&);

		const String& operator= (const char*);
		//const String& operator= (const String&);

		char* getString()const { return string; } 
		int getLenght()const { return length; }
	private:
		int length;
		char *string;

};


#endif