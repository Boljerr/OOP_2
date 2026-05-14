#include "pch.h"
#include "CppUnitTest.h"
#include "Studentas.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentasUnitTests
{
	TEST_CLASS(StudentasUnitTests)
	{
	public:
		
		TEST_METHOD(DefaultConstructorCreatesObject)
		{
			Studentas studentas;
			Assert::IsTrue(true);
		}

	};
}
