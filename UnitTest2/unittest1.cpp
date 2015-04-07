#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MyLibrary/Stack.h"
#include "../MyLibrary/Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(StackTest)
		{
			Stack<int> stk;

			stk.pushBack(1);
			stk.pushBack(2);
			stk.pushBack(3);
			stk.pop();
			stk.pushBack(4);

			Assert::AreEqual(stk.getLast(), 4);
			stk.pop();
			Assert::AreEqual(stk.getLast(), 2);
			stk.pop();
			Assert::AreEqual(stk.getLast(), 1);
			stk.pop();

		}
		TEST_METHOD(Stack_Pick)
		{
			Stack<int> stk;

			stk.pushBack(1);
			stk.pushBack(2);
			stk.pushBack(3);
			stk.pop();
			stk.pushBack(4);

			Assert::AreEqual(stk.pick(1), 2);

		}

		TEST_METHOD(Queue_Test)
		{
			Queue<int> stk;

			stk.pushBack(1);
			stk.pushBack(2);
			stk.pushBack(3);
			stk.pop();
			stk.pushBack(4);

			Assert::AreEqual(stk.pop(), 2);
			Assert::AreEqual(stk.pop(), 3);
			Assert::AreEqual(stk.pop(), 4);

		}

	};
}