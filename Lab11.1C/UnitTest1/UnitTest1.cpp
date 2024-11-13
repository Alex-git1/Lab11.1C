#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.1C/Lab11.1C.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* line = "This is a test line with !!! in it.";
			int result = hasThreeConsecutiveExclamations(line);
			Assert::AreEqual(1, result);
		}
	};
}
