#ifndef String_H
#define String_H

// Mai surt de rang! o si


class String
{
	public:
		String();
		String(const char*, ...);
		String(const String&);

		~String();

		bool operator== (const char*);
		bool operator== (const String&);
		bool operator!= (const char*);
		bool operator!= (const String&);

		const String& operator= (const char*);
		const String& operator= (const String&);
		const String& operator+= (const char*);
		const String& operator+= (const String&);		

		
		const int capacity()const { return sizeof(string)+1; }
		void clear(){ string[0] = '\0'; size = 1; }

		const char* getString()const { return string; } 
		const int length()const { return size-1; }
		
	private:
		int size;
		char *string;
		void alloc(const unsigned int);

};


#endif