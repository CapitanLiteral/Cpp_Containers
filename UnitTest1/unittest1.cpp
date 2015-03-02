#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\MyLibrary\Log.h"
#include "..\MyLibrary\String.h"
#include "..\MyLibrary\String.cpp"
#include "..\MyLibrary\Point2D.h"
#include "..\MyLibrary\Point2D.cpp"
//#include "math.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		/*TEST_METHOD(setZero)
		{
			Point2D point;

			point.setZero();

			Assert::IsTrue(point.x == 0.0f && point.y == 0.0f);


		}*/
		TEST_METHOD(PointisZero)
		{
			Point2D point;

			point.setZero();
			Assert::IsTrue(point.isxyZero());


		}
		TEST_METHOD(PointSum)
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


		}
		TEST_METHOD(PointEqualSum)
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


		}
		TEST_METHOD(PointDecrease)
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


		}
		TEST_METHOD(PointEqualDecrease)
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


		}
		TEST_METHOD(PointAssignation)
		{
			Point2D a;
			Point2D b;

			a.x = 2;
			a.y = 3;

			b = a;


			Assert::AreEqual(b.x, 2.0f);
			Assert::AreEqual(b.y, 3.0f);


		}
		TEST_METHOD(PointEqualEqual)
		{
			Point2D a;
			Point2D b;

			a.x = 3;
			a.y = 3;
			b.x = 3;
			b.y = 3;

			Assert::IsTrue(a == b);


		}
		TEST_METHOD(PointDifferent)
		{
			Point2D a;
			Point2D b;

			a.x = 3;
			a.y = 3;
			b.x = 3;
			b.y = 2;

			Assert::IsTrue(a != b);
		}
		TEST_METHOD(PointSumWithoutNumbers)
		{
			Point2D a;
			Point2D b;

			a += b;

			Assert::AreEqual(a.x, 0.0f);
			Assert::AreEqual(a.y, 0.0f);
		}
		TEST_METHOD(PointDistance1)
		{
			Point2D a(1, 0);
			Point2D b(0, 0);

			Assert::AreEqual(a.distanceTo(b), 1.0f);


		}
		TEST_METHOD(PointDistance2)
		{
			Point2D a(5, 2);
			Point2D b(1, 3);
			float d = a.distanceTo(b);
			/*d = d * powf(10.0f, 4.0f);
			d = truncf(d);*/
			Assert::AreEqual(d, 4.1231f, 0.0001f);
		}
		
		
		
		//-------------------------------------------------------------------
		//-------------------------------------------------------------------
		//----------------------------- STRING ------------------------------
		//-------------------------------------------------------------------
		//-------------------------------------------------------------------
		//-------------------------------------------------------------------
		TEST_METHOD(StringVoidConstructor)
		{
			String s;
			Assert::AreEqual(s.length(), 0);
			Assert::AreEqual(s.getString(), "\0");	
		}
		TEST_METHOD(StringFormatConstructor)
		{
			String s("%s%s%s", "param1", "param2", "param3");

			Assert::AreEqual(s.length(), 18);
			Assert::AreEqual(s.getString(), "param1param2param3");
		}
		TEST_METHOD(StringFormatConstructorNULL)
		{
			String s(NULL);
			Assert::AreEqual(s.length(), 0);
			Assert::AreEqual(s.getString(), "");
		}
		TEST_METHOD(StringCopyConstructor)
		{
			String s1("hi");
			String s2(s1);
			Assert::AreEqual(s1.length(), s2.length());
			Assert::AreEqual(s1.length(), 2);
			Assert::AreEqual(s1.getString(), s2.getString());

		}
		TEST_METHOD(StringCopyConstructorNULL)
		{			
			String s1(NULL);
			Assert::AreEqual(s1.length(), 0);
			Assert::AreEqual(s1.getString(), "");
		}
		TEST_METHOD(StringOperatorAssignationChar01)
		{
			String s2("");
			String s1("hola");

			s2 = s1.getString();

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationChar02)
		{
			String s2;
			String s1("hola");

			s2 = s1.getString();

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationChar03)
		{
			String s2(NULL);
			String s1("hola");
			s2 = s1.getString();

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationChar04)
		{
			String s2("abcdefghijklm");
			String s1("hola");
			s2 = s1.getString();

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass01)
		{
			String s1("");
			String s2("");

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass02)
		{
			String s1;
			String s2;

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass03)
		{
			String s1("hhhhhh");
			String s2("");

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass04)
		{
			String s1("");
			String s2("hhhhhh");

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass05)
		{
			String s1(NULL);
			String s2(NULL);

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass06)
		{
			String s1(NULL);
			String s2("aaa");

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass07)
		{
			String s1("aaa");
			String s2(NULL);

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass08)
		{
			String s1("aaa%s%f", "jaja", 0.01f);
			String s2(NULL);

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass09)
		{
			String s1("aaa%s%f", "jaja", 0.01f);
			String s2 = NULL;

			s2 = s1;

			Assert::AreEqual(s2.length(), s1.length());
			Assert::AreEqual(s2.getString(), s1.getString());
		}
		TEST_METHOD(StringOperatorAssignationClass10)
		{
			String s1 = NULL;
			String s2 = NULL;

			s2 = s1;

			Assert::AreEqual(s2.length(), 0);
			Assert::AreEqual(s2.getString(), "");
		}
		TEST_METHOD(StringOperatorEqualChar01)
		{
			String s1;

			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(StringOperatorEqualChar02)
		{
			String s1("hola");
			
			Assert::IsTrue(s1 == "hola");
		}
		TEST_METHOD(StringOperatorEqualChar03)
		{
			String s1("hola%s", "hola");

			Assert::IsTrue(s1 == "holahola");
		}
		TEST_METHOD(StringOperatorEqualChar04)
		{
			String s1("");

			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(StringOperatorEqualChar05)
		{
			String s1("");

			Assert::IsFalse(s1 == NULL);
		}
		TEST_METHOD(StringOperatorEqualChar06)
		{
			String s1;

			Assert::IsFalse(s1 == NULL);
		}
		TEST_METHOD(StringOperatorEqualChar07)
		{
			String s1(NULL);

			Assert::IsFalse(s1 == NULL);
		}
		TEST_METHOD(StringOperatorEqualChar08)
		{
			String s1("hola");
			s1 = "";

			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(StringOperatorEqualClass01)
		{
			String s1 = NULL;
			String s2;

			Assert::IsTrue(s1 == s2);
			
		}
		TEST_METHOD(StringOperatorEqualClass02)
		{
			String s1("hola");
			String s2("hola");

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(StringOperatorEqualClass03)
		{
			String s1("");
			String s2("");

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(StringOperatorEqualClass04)
		{
			String s1(NULL);
			String s2("");

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(StringOperatorEqualClass05)
		{
			String s1 = NULL;
			String s2("");

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(StringOperatorEqualClass06)
		{
			String s1("%s%s%f", "hola", "hola", 0.0f);
			String s2("%s%s%f", "hola", "hola", 0.0f);

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(StringOperatorEqualClass07)
		{
			String s1 = NULL;
			String s2 = NULL;

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(StringOperatorDiferentChar01)
		{
			String s1("hola");
			String s2;

			Assert::IsTrue(s1 != "holaaaa");
		}
		TEST_METHOD(StringOperatorDiferentClass01)
		{
			String s1("hola");
			String s2;

			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(StringOperatorConcatChar01)
		{
			String s1("hola");
			s1 += "hola";

			Assert::IsTrue(s1 == "holahola");			
		}
		TEST_METHOD(StringOperatorConcatClass01)
		{
			String s1("hola");
			String s2("hola");
			s1 += s2;

			Assert::IsTrue(s1 == "holahola");
		}
	};
}