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

	TEST_CLASS(parseGraphFromTextTests)
	{
	public:

		bool arraysAreEqual(int* array1, int* array2, int length) {
			for (int i = 0; i < length; i++)
			{
				if (array1[i] != array2[i])
					return false;
			}
			return true;
		}

		bool errorVectorsAreEqual(const std::vector<Error>& vector1, const std::vector<Error>& vector2)
		{
			// Проверяем размеры векторов
			if (vector1.size() != vector2.size())
			{
				return false;
			}

			// Сравниваем каждую ошибку поэлементно, порядок ошибок единственно-возможный по порядку строк
			for (int i = 0; i < vector1.size(); i++)
			{
				if (!(vector1[i].isEqualTo(vector2[i])))
				{
					return false;
				}
			}

			return true;
		}

		TEST_METHOD(basicValidGraph)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->2",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//запаршенный граф
			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемые данные
			DirGraph expectedGraph(3);
			expectedGraph.addEdge(0, 1);
			expectedGraph.addEdge(1, 2);
			int expDegrees[1000] = { 0,1,1 };
			//проверка
			Assert::IsTrue(parsedGraph->dirGraphIsEqual(expectedGraph));
			Assert::AreEqual((size_t)0, errorVector.size());
			Assert::IsTrue(arraysAreEqual(inDegrees, expDegrees, 3));

			//зачистка
			delete parsedGraph;
		}

		TEST_METHOD(isolatedVertices)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//запаршенный граф
			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемые данные
			DirGraph expectedGraph(4);
			expectedGraph.addEdge(0, 1);
			int expDegrees[1000] = { 0, 1, 0, 0 };

			//проверка
			Assert::IsTrue(parsedGraph->dirGraphIsEqual(expectedGraph));
			Assert::AreEqual((size_t)0, errorVector.size());
			Assert::IsTrue(arraysAreEqual(inDegrees, expDegrees, 4));

			//зачистка
			delete parsedGraph;
		}

		TEST_METHOD(loops)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->1",
				"2->2",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//запаршенный граф
			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемые данные
			DirGraph expectedGraph(3);
			expectedGraph.addEdge(0, 1);
			expectedGraph.addEdge(1, 1);
			expectedGraph.addEdge(2, 2);
			int expDegrees[1000] = { 0, 2, 1 };

			//проверка
			Assert::IsTrue(parsedGraph->dirGraphIsEqual(expectedGraph));
			Assert::AreEqual((size_t)0, errorVector.size());
			Assert::IsTrue(arraysAreEqual(inDegrees, expDegrees, 3));

			//зачистка
			delete parsedGraph;
		}

		TEST_METHOD(multigraph)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"0->1",
				"0->2",
				"2->0",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//запаршенный граф
			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемые данные
			DirGraph expectedGraph(3);
			expectedGraph.addEdge(0, 1);
			expectedGraph.addEdge(0, 1);
			expectedGraph.addEdge(0, 2);
			expectedGraph.addEdge(2, 0);
			int expDegrees[1000] = { 1, 2, 1 };

			//проверка
			Assert::IsTrue(parsedGraph->dirGraphIsEqual(expectedGraph));
			Assert::AreEqual((size_t)0, errorVector.size());
			Assert::IsTrue(arraysAreEqual(inDegrees, expDegrees, 3));

			//зачистка
			delete parsedGraph;
		}

		TEST_METHOD(noEdges)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//запаршенный граф
			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемые данные
			DirGraph expectedGraph(3);
			int expDegrees[1000] = { 0, 0, 0 };

			//проверка
			Assert::IsTrue(parsedGraph->dirGraphIsEqual(expectedGraph));
			Assert::AreEqual((size_t)0, errorVector.size());
			Assert::IsTrue(arraysAreEqual(inDegrees, expDegrees, 3));

			//зачистка
			delete parsedGraph;
		}

		TEST_METHOD(emptyGraph)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//запаршенный граф
			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемые данные
			DirGraph expectedGraph(0);
			int expDegrees[1000] = { 0 };

			//проверка
			Assert::IsTrue(parsedGraph->dirGraphIsEqual(expectedGraph));
			Assert::AreEqual((size_t)0, errorVector.size());
			Assert::IsTrue(arraysAreEqual(inDegrees, expDegrees, 0));

			//зачистка
			delete parsedGraph;
		}

		TEST_METHOD(whiteDelimeters)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"   0   ",
				"  1 ",
				"2",
				"",
				"    0  ->  1 ",
				"1->2",
				"",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//запаршенный граф
			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемые данные
			DirGraph expectedGraph(3);
			expectedGraph.addEdge(0, 1);
			expectedGraph.addEdge(1, 2);
			int expDegrees[1000] = { 0, 1, 1 };

			//проверка
			Assert::IsTrue(parsedGraph->dirGraphIsEqual(expectedGraph));
			Assert::AreEqual((size_t)0, errorVector.size());
			Assert::IsTrue(arraysAreEqual(inDegrees, expDegrees, 3));

			//зачистка
			delete parsedGraph;
		}

		TEST_METHOD(disconnectedComponents)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"0->1",
				"1->0",
				"3->4",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//запаршенный граф
			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемые данные
			DirGraph expectedGraph(5);
			expectedGraph.addEdge(0, 1);
			expectedGraph.addEdge(1, 0);
			expectedGraph.addEdge(3, 4);
			int expDegrees[1000] = { 1, 1, 0, 0, 1 };

			//проверка
			Assert::IsTrue(parsedGraph->dirGraphIsEqual(expectedGraph));
			Assert::AreEqual((size_t)0, errorVector.size());
			Assert::IsTrue(arraysAreEqual(inDegrees, expDegrees, 5));

			//зачистка
			delete parsedGraph;
		}

		
	};


}

