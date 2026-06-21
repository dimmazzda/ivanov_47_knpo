#include "pch.h"
#include "CppUnitTest.h"
#include "../ivanov_47_knpo/headers.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(substractOfAdjacencyListsTests)
	{
	public:
		TEST_METHOD(partialOverlap)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{1,2},
				{2},
				{}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 3;
			subtrahend.neighbours = {
				{1},
				{},
				{0}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{2},
				{2},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(equalLists)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{1},
				{2},
				{0}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 3;
			subtrahend.neighbours = {
				{1},
				{2},
				{0}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{},
				{},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(noOverlap)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 2;
			minuend.neighbours = {
				{1},
				{}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 2;
			subtrahend.neighbours = {
				{},
				{0}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 2;
			expected.neighbours = {
				{1},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(fullOverlapOfSubtrahend)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{1,2,3},
				{1,2},
				{}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 3;
			subtrahend.neighbours = {
				{1,2},
				{2},
				{}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{3},
				{1},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(fullOverlapOfMinuend)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 2;
			minuend.neighbours = {
				{1,2},
				{2}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 2;
			subtrahend.neighbours = {
				{1,2,3},
				{2}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 2;
			expected.neighbours = {
				{},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(emptyMinuend)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{},
				{},
				{}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 3;
			subtrahend.neighbours = {
				{1},
				{2},
				{}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{},
				{},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(emptySubtrahend)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{1},
				{2},
				{}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 3;
			subtrahend.neighbours = {
				{},
				{},
				{}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{1},
				{2},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(diffVertexCntMinSmler)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 2;
			minuend.neighbours = {
				{1},
				{}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 3;
			subtrahend.neighbours = {
				{1},
				{2},
				{0}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 2;
			expected.neighbours = {
				{},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(diffVertexCntMinBger)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{1},
				{2},
				{0}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 2;
			subtrahend.neighbours = {
				{1},
				{}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{},
				{2},
				{0}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(selfSubtraction)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 2;
			minuend.neighbours = {
				{1, 2},
				{0}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 2;
			expected.neighbours = {
				{},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(minuend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(duplicateEdges)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 2;
			minuend.neighbours = {
				{1, 1, 2},
				{}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 2;
			subtrahend.neighbours = {
				{1},
				{}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 2;
			expected.neighbours = {
				{1, 2},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(loopEdges)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{0, 1},
				{2},
				{}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 3;
			subtrahend.neighbours = {
				{0},
				{2},
				{}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{1},
				{},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(complexTest1)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{0, 0, 1, 2},
				{0, 2},
				{2}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 3;
			subtrahend.neighbours = {
				{0, 1},
				{0, 1, 2},
				{2}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{0, 2},
				{},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(complexTest2)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{0, 1, 1},
				{0, 1, 2},
				{0}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 2;
			subtrahend.neighbours = {
				{1},
				{1}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{0, 1},
				{0, 2},
				{}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}

		TEST_METHOD(complexTest3)
		{	//уменьшаемое
			adjacencyList minuend;
			minuend.countOfVertices = 3;
			minuend.neighbours = {
				{1, 0, 0},
				{2, 0, 1},
				{0}
			};
			//вычитаемое
			adjacencyList subtrahend;
			subtrahend.countOfVertices = 2;
			subtrahend.neighbours = {
				{0, 1, 1},
				{1},
				{1}
			};
			//ожидаемый результат
			adjacencyList expected;
			expected.countOfVertices = 3;
			expected.neighbours = {
				{0, 1},
				{0, 2},
				{0}
			};

			//результат
			adjacencyList* result = minuend.substract(subtrahend);

			//проверка
			Assert::IsTrue(result->isEqualTo(expected));

			delete result;
		}
	};
}
