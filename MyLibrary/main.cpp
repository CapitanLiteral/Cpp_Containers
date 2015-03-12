#include "Math.h"
#include "String.h"
#include "Point2D.h"
#include "Log.h"
#include <stdio.h>
#include "Swap.h"
#include "List.h"
#include "DList.h"

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

	List<int>* l1 = new List<int>();
	l1->add(5);
	l1->add(6);

	Log::log("%d", l1->start->val);
	Log::log("%d", l1->start->next);
	Log::log("%d", l1->count());

	l1->~List();


	DList<int>* l = new DList<int>();
	l->add(5);
	l->add(6);

	Log::log("%d", l->start->val);
	Log::log("%d", l->start->next);
	Log::log("%d", l->count());

	l->~DList();


} ///:~



