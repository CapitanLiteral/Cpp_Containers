#include "Math.h"
#include "String.h"
#include "Point2D.h"
#include "Log.h"
#include <stdio.h>


/*void mes(int a)
{
	a++;
}*/

/*void mes(int *a)
{
	a++;
}

int main()
{
	int a = 0;
	Log::log("%d", -a);

	
}*/


int* f(int* x) {
	(*x)++;
	return x; // Safe, x is outside this scope
}

int& g(int& x) {
	x++; // Same effect as in f()
	return x; // Safe, outside this scope
}

int& h() {
	int q;
	//!  return q;  // Error
	static int x;
	return x; // Safe, x lives outside this scope
}

int main() {
	/*int a = 0;
	f(&a); // Ugly (but explicit)
	g(a);  // Clean (but hidden)

	Log::log("%d", a);


	char* p;
	char* p2 = "hola";

	strlen(p2);
	strcpy(p, p2);*/

	String s2("sdfsdf");
	String s1 = NULL;

	s2 = s1.getString();

	int a = s2.length();
	int b = s1.length();
} ///:~



