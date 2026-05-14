#include "pch.h"
#include "CppUnitTest.h"
#include "Studentas.h"
#include <utility>

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

		TEST_METHOD(CopyConstructorWorks)
		{
			Studentas pirmas("Jonas", "Jonaitis", {8, 9, 10}, 9);
			
			Studentas antras(pirmas);
			
			Assert::IsTrue(antras.getVardas() == "Jonas");
			Assert::IsTrue(antras.getPavarde() == "Jonaitis");
			Assert::IsTrue(antras.getEgzaminas() == 9);
			Assert::IsTrue(antras.getPazymiai().size() == 3);

			Assert::IsTrue(antras.getPazymiai()[0] == 8);
			Assert::IsTrue(antras.getPazymiai()[1] == 9);
			Assert::IsTrue(antras.getPazymiai()[2] == 10);
		}
		TEST_METHOD(CopyAssignmentOperatorWorks)
		{
			Studentas pirmas("Jonas", "Jonaitis", {8, 9, 10}, 9);
			Studentas antras;

			antras = pirmas;

			Assert::IsTrue(antras.getVardas() == "Jonas");
			Assert::IsTrue(antras.getPavarde() == "Jonaitis");
			Assert::IsTrue(antras.getEgzaminas() == 9);
			Assert::IsTrue(antras.getPazymiai().size() == 3);

			Assert::IsTrue(antras.getPazymiai()[0] == 8);
			Assert::IsTrue(antras.getPazymiai()[1] == 9);
			Assert::IsTrue(antras.getPazymiai()[2] == 10);
		}
		TEST_METHOD(MoveConstructorWorks)
		{
			Studentas pirmas("Jonas", "Jonaitis", {8, 9, 10}, 9);
			
			Studentas antras(std::move(pirmas));

			Assert::IsTrue(antras.getVardas() == "Jonas");
			Assert::IsTrue(antras.getPavarde() == "Jonaitis");
			Assert::IsTrue(antras.getEgzaminas() == 9);
			Assert::IsTrue(antras.getPazymiai().size() == 3);

			Assert::IsTrue(antras.getPazymiai()[0] == 8);
			Assert::IsTrue(antras.getPazymiai()[1] == 9);
			Assert::IsTrue(antras.getPazymiai()[2] == 10);
		}
		TEST_METHOD(MoveAssignmentOperatorWorks)
		{
			Studentas pirmas("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
			Studentas antras;

			antras = std::move(pirmas);

			Assert::IsTrue(antras.getVardas() == "Jonas");
			Assert::IsTrue(antras.getPavarde() == "Jonaitis");
			Assert::IsTrue(antras.getEgzaminas() == 9);
			Assert::IsTrue(antras.getPazymiai().size() == 3);

			Assert::IsTrue(antras.getPazymiai()[0] == 8);
			Assert::IsTrue(antras.getPazymiai()[1] == 9);
			Assert::IsTrue(antras.getPazymiai()[2] == 10);
		}
	};
}
