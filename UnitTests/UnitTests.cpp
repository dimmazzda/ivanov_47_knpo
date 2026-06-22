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
				{0}
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
				{0},
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
			expectedGraph.vertices = { 0,1,2 };
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
			expectedGraph.vertices = { 0,1,2,3 };
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
			expectedGraph.vertices = { 0,1,2};
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
			expectedGraph.vertices = { 0,1,2 };
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
			expectedGraph.vertices = { 0,1,2 };
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
			expectedGraph.vertices = {};
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
			expectedGraph.vertices = { 0,1,2 };
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
			expectedGraph.vertices = { 0,1,2,3,4 };
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

		TEST_METHOD(definitionLineSyntaxErrorTest)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"bigraph G {",
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

			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемый вектор ошибок
			std::vector<Error> expectedErrors;
			Error error1(defenitionLineSyntaxError);
			error1.line = 1;
			expectedErrors.push_back(error1);

			//проверка
			Assert::IsTrue(errorVectorsAreEqual(errorVector, expectedErrors));

			//зачистка
			if (parsedGraph != nullptr)
			{
				delete parsedGraph;
			}
		}

		TEST_METHOD(incorrectEdgeSyntax)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0--1",
				"1->0",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемый вектор ошибок
			std::vector<Error> expectedErrors;
			Error error1(5);
			expectedErrors.push_back(error1);

			//проверка
			Assert::IsTrue(errorVectorsAreEqual(errorVector, expectedErrors));

			//зачистка
			if (parsedGraph != nullptr)
			{
				delete parsedGraph;
			}
		}

		TEST_METHOD(incorrectVertexSyntax)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"a",
				"0->1",
				"1->0",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемый вектор ошибок
			std::vector<Error> expectedErrors;
			Error error1(4);
			expectedErrors.push_back(error1);

			//проверка
			Assert::IsTrue(errorVectorsAreEqual(errorVector, expectedErrors));

			//зачистка
			if (parsedGraph != nullptr)
			{
				delete parsedGraph;
			}
		}

		TEST_METHOD(endLineSyntaxErrorTest)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->0",
				"]"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемый вектор ошибок
			std::vector<Error> expectedErrors;
			Error error1(endLineSyntaxError);
			error1.line = 7;
			expectedErrors.push_back(error1);

			//проверка
			Assert::IsTrue(errorVectorsAreEqual(errorVector, expectedErrors));

			//зачистка
			if (parsedGraph != nullptr)
			{
				delete parsedGraph;
			}
		}

		TEST_METHOD(combinatedErrors)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"bigraph G {",
				"0",
				"1",
				"2",
				"0--1",
				"1->0",
				"]"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемый вектор ошибок
			std::vector<Error> expectedErrors;
			Error error1(defenitionLineSyntaxError);
			error1.line = 1;
			Error error2(5);
			Error error3(endLineSyntaxError);
			error3.line = 7;
			expectedErrors.push_back(error1);
			expectedErrors.push_back(error2);
			expectedErrors.push_back(error3);

			//проверка
			Assert::IsTrue(errorVectorsAreEqual(errorVector, expectedErrors));

			//зачистка
			if (parsedGraph != nullptr)
			{
				delete parsedGraph;
			}
		}

		TEST_METHOD(notStatedVertex)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"0->1",
				"1->2",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемый вектор ошибок
			std::vector<Error> expectedErrors;
			Error error1(5);
			expectedErrors.push_back(error1);

			//проверка
			Assert::IsTrue(errorVectorsAreEqual(errorVector, expectedErrors));

			//зачистка
			if (parsedGraph != nullptr)
			{
				delete parsedGraph;
			}
		}

		TEST_METHOD(wrongDescriptionOrder)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0->1",
				"1->2",
				"0",
				"1",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемый вектор ошибок
			std::vector<Error> expectedErrors;
			Error error1(2);  
			Error error2(3);  
			Error error3(4);  
			Error error4(5);

			expectedErrors.push_back(error1);
			expectedErrors.push_back(error2);
			expectedErrors.push_back(error3);
			expectedErrors.push_back(error4);

			//проверка
			Assert::IsTrue(errorVectorsAreEqual(errorVector, expectedErrors));

			//зачистка
			if (parsedGraph != nullptr)
			{
				delete parsedGraph;
			}
		}

		TEST_METHOD(severalInnerDescriptionErrors)
		{
			//входные данные
			std::vector<std::string> fileText = {
				"digraph G {",
				"0",
				"1",
				"0--1",
				"1-<0",
				"}"
			};

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(fileText, inDegrees, errorVector);

			//создаём ожидаемый вектор ошибок
			std::vector<Error> expectedErrors;
			Error error1(4);
			Error error2(5);
			expectedErrors.push_back(error1);
			expectedErrors.push_back(error2);

			//проверка
			Assert::IsTrue(errorVectorsAreEqual(errorVector, expectedErrors));

			//зачистка
			if (parsedGraph != nullptr)
			{
				delete parsedGraph;
			}
		}
	};

	TEST_CLASS(createSpanningTreeTests)
	{
	public:
		TEST_METHOD(linearTree)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"1->2",
				"2->3",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"1->2",
				"2->3",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(shrinkedlinearTree)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"1->2",
				"2->3",
				"}"
			};
			int inputRootVertex = 1; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"1",
				"2",
				"3",
				"1->2",
				"2->3",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}	

		TEST_METHOD(basicNonLinearTree)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"0->2",
				"0->3",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"0->2",
				"0->3",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(rootInDrain)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"0->2",
				"0->3",
				"}"
			};
			int inputRootVertex = 2; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"2",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(severalRoots)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"0->2",
				"1->2",
				"2->3",
				"2->4",
				"}"
			};
			int inputRootVertex = 1; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"1",
				"2",
				"3",
				"4",
				"1->2",
				"2->3",
				"2->4",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(simpleCycle)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->2",
				"2->0",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->2",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(containsCycle)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"1->2",
				"2->0",
				"1->3",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"1->2",
				"1->3",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(twoDirectionCycle)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->0",
				"1->2",
				"2->1",
				"0->2",
				"2->0",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"0->2",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(unreachebleVertices)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"0->2",
				"3->2",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"0->2",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(isolatedComponent)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"0->1",
				"0->2",
				"3->4",
				"4->3",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"0->2",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(searchOrderTest)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"0->2",
				"0->4",
				"2->1",
				"2->3",
				"3->5",
				"4->5",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"0->2",
				"0->4",
				"2->1",
				"2->3",
				"4->5",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(multigraph)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"0->1",
				"1->2",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->2",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}
		
		TEST_METHOD(stronglyConnectedGraph)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"1->0",
				"1->2",
				"2->1",
				"1->3",
				"3->1",
				"}"
			};
			int inputRootVertex = 1; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"1->0",
				"1->2",
				"1->3",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(simpleLoop)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->1",
				"1->2",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->2",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(complexLoops)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->0",
				"0->0",
				"0->1",
				"1->1",
				"1->2",
				"1->3",
				"3->0",
				"3->1",
				"}"
			};
			int inputRootVertex = 1; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"1->2",
				"1->3",
				"3->0",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(complexTest1)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"10",
				"11",
				"0->1",
				"0->1",
				"0->2",
				"0->3",
				"1->4",
				"1->5",
				"2->4",
				"2->6",
				"3->3",
				"3->1",
				"3->5",
				"10->11",
				"11->10",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"0->1",
				"0->2",
				"0->3",
				"1->4",
				"1->5",
				"2->6",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(complexTest2)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"7",
				"8",
				"0->1",
				"0->1",
				"0->2",
				"0->3",
				"1->4",
				"1->5",
				"2->4",
				"2->6",
				"3->3",
				"3->5",
				"7->0",
				"7->8",
				"8->7",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"0->1",
				"0->2",
				"0->3",
				"1->4",
				"1->5",
				"2->6",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(complexTest3)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"0->2",
				"2->0",
				"2->5",
				"5->5",
				"5->3",
				"5->4",
				"3->4",
				"3->6",
				"0->3",
				"3->5",
				"7->0",
				"7->8",
				"8->7",
				"}"
			};
			int inputRootVertex = 5; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"3",
				"4",
				"5",
				"6",
				"5->3",
				"5->4",
				"3->6",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}

		TEST_METHOD(complexTest4)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"0->1",
				"0->2",
				"0->3",
				"2->0",
				"2->5",
				"5->5",
				"5->3",
				"5->4",
				"3->6",
				"3->4",
				"}"
			};
			int inputRootVertex = 0; //входной корень

			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			//результат ф-ции
			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			DirGraph* createdTree = parsedGraph->generateSpanningTree(inputRootVertex);
			//ожидаемый граф
			std::vector<std::string> expectedText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"0->1",
				"0->2",
				"0->3",
				"2->5",
				"3->4",
				"3->6",
				"}"
			};
			DirGraph* expectedGraph = parseGraphFromText(expectedText, inDegrees, errorVector);
			Assert::IsTrue(createdTree->dirGraphIsEqual(*expectedGraph));

			//зачистка	
			delete parsedGraph;
			delete createdTree;
			delete expectedGraph;
		}
	};
	
	TEST_CLASS(findGraphTypeTests)
	{
	public:
		TEST_METHOD(linearTree)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"1->2",
				"2->3",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление (их состав не будет участвовать в коде)
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = tree;

			Assert::IsTrue(resultType == expectedType);

			delete parsedGraph;
		}

		TEST_METHOD(classicTree)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"0->1",
				"0->2",
				"1->3",
				"1->4",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = tree;


			Assert::IsTrue(resultType == expectedType);

			delete parsedGraph;
		}

		TEST_METHOD(oneVertexTree)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = tree;

			Assert::IsTrue(resultType == expectedType);

			delete parsedGraph;
		}

		TEST_METHOD(isolatedVertex)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = notConvertibleToTree;

			Assert::IsTrue(resultType == expectedType);

			delete parsedGraph;
		}

		TEST_METHOD(severalPotentialRoots)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"1->3",
				"2->3",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = notConvertibleToTree;

			Assert::IsTrue(resultType == expectedType);

			delete parsedGraph;
		}

		TEST_METHOD(onePotentialRootNotConvertible)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"0->1",
				"2->3",
				"3->2",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = notConvertibleToTree;

			Assert::IsTrue(resultType == expectedType);

			delete parsedGraph;
		}

		TEST_METHOD(noRoot)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"2->0",
				"2->1",
				"2->3",
				"3->2",
				"3->1",
				"1->0",
				"4->5",
				"5->4",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = notConvertibleToTree;

			Assert::IsTrue(resultType == expectedType);

			delete parsedGraph;
		}

		TEST_METHOD(simpleCycle)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"1->2",
				"2->0",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 3;
			expectedEdgeDifference.neighbours = {
				{1},
				{},
				{}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(excessEdge)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"0->1",
				"0->2",
				"2->1",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 3;
			expectedEdgeDifference.neighbours = {
				{},
				{},
				{1}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(onePotentialRootConvertible)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"0->1",
				"0->4",
				"1->2",
				"4->2",
				"2->3",
				"3->1",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 5;
			expectedEdgeDifference.neighbours = {
				{},
				{},
				{},
				{1},
				{2}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(noPotentialRoot)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"0->1",
				"0->4",
				"1->2",
				"4->2",
				"2->0",
				"2->3",
				"3->1",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 5;
			expectedEdgeDifference.neighbours = {
				{1},
				{},
				{3},
				{},
				{2}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(multiGraph)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"0->1",
				"0->4",
				"1->2",
				"4->2",
				"2->0",
				"2->3",
				"3->1",
				"3->1",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 5;
			expectedEdgeDifference.neighbours = {
				{1},
				{},
				{3},
				{1},
				{2}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(weakConnectedCycles)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"0->1",
				"1->2",
				"2->0",
				"3->4",
				"4->5",
				"5->3",
				"5->0",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 6;
			expectedEdgeDifference.neighbours = {
				{},
				{},
				{0},
				{},
				{},
				{3}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(strongConnectedCycles)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"0->1",
				"1->0",
				"1->2",
				"2->1",
				"2->0",
				"0->2",
				"3->0",
				"0->3",
				"3->4",
				"4->3",
				"4->5",
				"5->4",
				"3->5",
				"5->3",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 6;
			expectedEdgeDifference.neighbours = {
				{1, 2},
				{},
				{0, 1},
				{0},
				{3, 5},
				{3, 4}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(loops)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"0->1",
				"0->4",
				"4->2",
				"2->0",
				"1->1",
				"1->2",
				"2->3",
				"3->1",
				"3->3",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 5;
			expectedEdgeDifference.neighbours = {
				{1},
				{1},
				{3},
				{3},
				{2}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(complexTest1)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"0->1",
				"0->1",
				"0->2",
				"1->1",
				"1->3",
				"1->4",
				"1->5",
				"2->3",
				"2->3",
				"2->4",
				"3->1",
				"3->2",
				"3->3",
				"4->0",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 6;
			expectedEdgeDifference.neighbours = {
				{1,1,2},
				{1,3},
				{3,4},
				{2,3},
				{},
				{}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}

		TEST_METHOD(complexTest2)
		{
			//входной граф
			std::vector<std::string> inputText = {
				"digraph G {",
				"0",
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"0->1",
				"0->0",
				"0->3",
				"1->2",
				"2->0",
				"4->2",
				"6->4",
				"5->4",
				"4->5",
				"4->5",
				"}"
			};
			int inDegrees[1000] = { 0 };
			std::vector<Error> errorVector;

			DirGraph* parsedGraph = parseGraphFromText(inputText, inDegrees, errorVector);
			//дуги попадающие под удаление
			adjacencyList edgeDifference;
			//найденный тип графа
			graphType resultType = findGraphType(*parsedGraph, edgeDifference, inDegrees);
			//ождиаемые данные
			graphType expectedType = convertibleToTree;
			adjacencyList expectedEdgeDifference;
			expectedEdgeDifference.countOfVertices = 6;
			expectedEdgeDifference.neighbours = {
				{1,1,2},
				{1,3},
				{3,4},
				{2,3},
				{},
				{}
			};

			Assert::IsTrue(resultType == expectedType);
			Assert::IsTrue(expectedEdgeDifference.isEqualTo(edgeDifference));

			delete parsedGraph;
		}
	};
}

