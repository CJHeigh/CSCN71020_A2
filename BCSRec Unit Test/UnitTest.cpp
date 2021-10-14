#include "pch.h"
#include "CppUnitTest.h"

extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);

extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecUnitTest
{
	TEST_CLASS(BCSRecUnitTest)
	{
	public:
		TEST_METHOD(GetPerimeter)
		{
			int length = 5;
			int width = 5;

			int result = getPerimeter(&length, &width);
			int intendedResult = (length + length + width + width);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(GetArea)
		{
			int length = 57;
			int width = 16;

			int result = getArea(&length, &width);
			int intendedResult = (length * width);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(SetLength)
		{
			int input = 55;
			int length = 1;
			int timesRun = 1;
			while (timesRun < 4)
			{
				setLength(input, &length); // I know that '&' takes a value from the function in the source code and returns it. Silly me.
				Assert::AreEqual(input, length);

				// Changes input variable values after the above has been executed
				timesRun++;
				if (timesRun == 2)
					input = 34;
				else if (timesRun == 3)
					input = 87;
			}
		}
		TEST_METHOD(SetWidth)
		{
			int input = 0;
			int width = 1;
			int timesRun = 1;
			while (timesRun < 4)
			{
				setLength(input, &width);
				Assert::AreEqual(input, width);

				timesRun++;
				if (timesRun == 2)
					input = 50;
				else if (timesRun == 3)
					input = 99;
			}
		}
	};
}