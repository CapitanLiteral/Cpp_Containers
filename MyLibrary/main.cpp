#include "Math.h"
#include "String.h"
#include "Point2D.h"
#include "Log.h"
#include <stdio.h>
#include "Swap.h"
#include "List.h"
#include "DList.h"
#include "DynArray.h"
#include "Stack.h"
#include "Tree.h"
#include "TreeNode.h"

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
	//int q;
	//!  return q;  // Error
	static int x;
	return x; // Safe, x lives outside this scope
}

int main() 
{
	Tree<char> t('F');
	TreeNode<char>* b = t.add('B');
	TreeNode<char>* g = t.add('G');
	t.add('A', b);
	TreeNode<char>* d = t.add('D', b);
	t.add('C', d);
	t.add('E', d);

	DList<char> l;

	t.visitAllNodes(l);

	for (int i = 0; i < l.count(); i++)
	{
		printf("%c\n", l.getAt(i));
	}
	getchar();

} ///:~


/*
#include <stdlib.h>
#include "../SdlModules/Application.h"
#include "../SdlModules/Globals.h"


enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};


int main(int argc, char ** argv)
{
	int main_return = EXIT_FAILURE;
	main_states state = MAIN_CREATION;
	Application* App = NULL;

	while (state != MAIN_EXIT)
	{
		switch (state)
		{
		case MAIN_CREATION:

			LOG("\nApplication Creation --------------");
			App = new Application();
			state = MAIN_START;
			break;

		case MAIN_START:

			LOG("\nApplication Init --------------");
			if (App->Init() == false)
			{
				LOG("\nApplication Init exits with error -----");
				state = MAIN_EXIT;
			}
			else
				state = MAIN_UPDATE;

			break;

		case MAIN_UPDATE:
		{
							int update_return = App->Update();

							if (update_return == UPDATE_ERROR)
							{
								LOG("\nApplication Update exits with error -----");
								state = MAIN_EXIT;
							}

							if (update_return == UPDATE_STOP)
								state = MAIN_FINISH;
		}
			break;

		case MAIN_FINISH:

			LOG("\nApplication CleanUp --------------");
			if (App->CleanUp() == false)
			{
				LOG("\nApplication CleanUp exits with error -----");
			}
			else
				main_return = EXIT_SUCCESS;

			state = MAIN_EXIT;

			break;
		}
	}

	delete App;
	LOG("\nBye :)\n");
	return main_return;
}*/