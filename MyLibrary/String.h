// String
//
// Class to strorage and operate with strings
//


#ifndef String_H
#define String_H



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

		
		const int capacity()const { return sizeof(string)+1; } // returns *string capacity not *string lenght
		void clear(){ string[0] = '\0'; size = 1; }

		const char* getString()const { return string; } 
		const int length()const { return size-1; }
		
	private:
		int size; // string lenght
		char *string;
		void alloc(const unsigned int);

};


#endif