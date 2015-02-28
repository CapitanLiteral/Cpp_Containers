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

	Point2D p1(5, 2);
	Point2D p2(1, 3);
	Point2D p3;
	p3 = p1 - p2;

	float d = p1.distanceTo(p2);

	d = d * powf(10.0f, 4.0f);
	d = truncf(d);

	Log::log("D: %f", d);

	Log::log("D2: %d", p1.distanceTo(p2) == 1.0f);



/*	String s("hola");
	String a;
	String sa(s);
	Log::log("String: %s", s.getString());
	Log::log("String: %s", a.getString());
	Log::log("String: %s", sa.getString());*/
//	s = "hola";


} ///:~



