#include "Math.h"
#include "String.h"
#include "Point2D.h"
#include "Log.h"
#include <stdio.h>
#include "Swap.h"
#include "List.h"

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
	String s("hola");
	String a("adeu");
	List<String>* l = new List<String>();
	l->add(s);
	l->add(a);

	Log::log("%s", l->start->val.getString());
	Log::log("%d", l->count());

	l->~List();
} ///:~



