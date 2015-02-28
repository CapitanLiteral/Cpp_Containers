#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\MyLibrary\Point2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(isZero)
		{
			Point2D point;

			point.setZero();
			Assert::IsTrue(point.isxyZero());

			// TODO: Agregar aquí el código de la prueba
		}
		TEST_METHOD(Sum)
		{
			Point2D a;
			Point2D b;
			Point2D c;

			a.x = 2;
			a.y = 3;
			b.x = 3;
			b.y = 2;

			c = a + b;

			Assert::AreEqual(c.x, 5.0f);
			Assert::AreEqual(c.y, 5.0f);

			// TODO: Agregar aquí el código de la prueba
		}
		TEST_METHOD(EqualSum)
		{
			Point2D a;
			Point2D b;

			a.x = 2;
			a.y = 3;
			b.x = 3;
			b.y = 2;

			a += b;

			Assert::AreEqual(a.x, 5.0f);
			Assert::AreEqual(a.y, 5.0f);

			// TODO: Agregar aquí el código de la prueba
		}
		TEST_METHOD(Decrease)
		{
			Point2D a;
			Point2D b;
			Point2D c;

			a.x = 2;
			a.y = 3;
			b.x = 3;
			b.y = 2;

			c = a - b;

			Assert::AreEqual(c.x, -1.0f);
			Assert::AreEqual(c.y, 1.0f);

			// TODO: Agregar aquí el código de la prueba
		}
		TEST_METHOD(EqualDecrease)
		{
			Point2D a;
			Point2D b;

			a.x = 2;
			a.y = 3;
			b.x = 3;
			b.y = 2;

			a -= b;

			Assert::AreEqual(a.x, -1.0f);
			Assert::AreEqual(a.y, 1.0f);

			// TODO: Agregar aquí el código de la prueba
		}
		TEST_METHOD(Assignation)
		{
			Point2D a;
			Point2D b;

			a.x = 2;
			a.y = 3;

			b = a;


			Assert::AreEqual(b.x, 2.0f);
			Assert::AreEqual(b.y, 3.0f);

			// TODO: Agregar aquí el código de la prueba
		}
		TEST_METHOD(EqualEqual)
		{
			Point2D a;
			Point2D b;

			a.x = 3;
			a.y = 3;
			b.x = 3;
			b.y = 3;

			Assert::IsTrue(a == b);

			// TODO: Agregar aquí el código de la prueba
		}
		TEST_METHOD(Different)
		{
			Point2D a;
			Point2D b;

			a.x = 3;
			a.y = 3;
			b.x = 3;
			b.y = 2;

			Assert::IsTrue(a != b);

			// TODO: Agregar aquí el código de la prueba
		}
	};
}