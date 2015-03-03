#include "Math.h"
#include "String.h"
#include "Point2D.h"
#include "Log.h"
#include <stdio.h>
#include "Swap.h"

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

	
}
*/




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

int main() 
{
	/*int a = 0;
	f(&a); // Ugly (but explicit)
	g(a);  // Clean (but hidden)

	Log::log("%d", a);


	char* p;
	char* p2 = "hola";

	strlen(p2);
	strcpy(p, p2);*/
	Point2D a(0, 0);
	Point2D b(1,1);
	a = b;
	Log::log("%f%f", a.x, a.y);
	/*String s1("hola");
	s1.clear();*/
	int a1 = 5;
	int b2 = 10;
	Log::log("%d%d", a1, b2);
	swap(a1, b2);
	Log::log("%d%d", a1, b2);
} ///:~



