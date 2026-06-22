#include <iostream>
#include "headers.h"
#include <algorithm>
#include <queue>
#include <stdexcept>
#include <stack>

bool adjacencyList::isEmpty()
    {
        for (int i = 0; i < countOfVertices; i++)       //если для всех вершин нет связей, список пустой
            if (neighbours[i].size() != 0)              //если хоть для одной есть - непустой
                return false;
        return true;
    }

bool adjacencyList::isEqualTo(const adjacencyList& otherList)
{
    // если количества вершин разные - списки неравны
    if (countOfVertices != otherList.countOfVertices)
        return false;

    // для каждой вершины будем сравнивать наборы дуг
    for (int i = 0; i < countOfVertices; i++) {
        std::vector<int> edges1;
        //если такой вершины нет - считаем её список пустым
        if (i < neighbours.size()) {   
            edges1 = neighbours[i]; // если есть, копируем дуги
        }

        // аналогично получаем вектор дуг для списка 2
        std::vector<int> edges2;
        if (i < otherList.neighbours.size()) {
            edges2 = otherList.neighbours[i];
        }

        // если кол-во дуг разное => наборы неравны
        if (edges1.size() != edges2.size()) {
            return false;
        }

        // сортируем вектора для сравнения
        std::sort(edges1.begin(), edges1.end());
        std::sort(edges2.begin(), edges2.end());

        // сравниваем поэлементно
        if (edges1 != edges2) {
            return false;
        }
    }

    return true;


}

adjacencyList* adjacencyList::substract(const adjacencyList& subtrahend)
{
	// инициализируем разность
	adjacencyList* result = new adjacencyList();
	result->countOfVertices = countOfVertices;
	result->neighbours.resize(countOfVertices);

	// для всех вершин уменьшаемого
	for (int i = 0; i < countOfVertices; i++)
	{
		// копируем вектор дуг уменьшаемого
		std::vector<int> currentEdges;
		if (i < neighbours.size())
		{
			currentEdges = neighbours[i];
		}

		// копируем вектор дуг вычитаемого
		std::vector<int> subtrahendEdges;
		if (i < subtrahend.neighbours.size())
		{
			subtrahendEdges = subtrahend.neighbours[i];
		}

		// для каждой дуги вычитаемого
		for (int edge : subtrahendEdges)
		{   // ищем соответствующую дугу
			auto it = std::find(currentEdges.begin(), currentEdges.end(), edge);
            //если найдена
			if (it != currentEdges.end())
			{
				// удаляем её
				currentEdges.erase(it);
			}
		}

		// записываем результат в новый список
		result->neighbours[i] = currentEdges;
	}

	return result;
}

DirGraph::DirGraph()
{
	vertices.clear();
    edges.countOfVertices = 0;  //вершин нет т.к. граф пустой
    edges.neighbours.clear();
}

DirGraph::DirGraph(int countOfVertices)
{
	vertices.clear();
	vertices.resize(countOfVertices);
    edges.countOfVertices = countOfVertices; 
    edges.neighbours.clear();
    edges.neighbours.resize(countOfVertices);
}

DirGraph::~DirGraph() {
	;
}

int DirGraph::getVertexCount() {
    return edges.countOfVertices;
}

bool DirGraph::hasEdge(int fromVertex, int toVertex)
{
	// находим индекс вершины fromVertex в списке vertices
	auto itFrom = std::find(vertices.begin(), vertices.end(), fromVertex);
	if (itFrom == vertices.end())
	{
		return false; // вершина fromVertex не существует в графе
	}
	int indexFrom = std::distance(vertices.begin(), itFrom);

	// находим индекс вершины toVertex в списке vertices
	auto itTo = std::find(vertices.begin(), vertices.end(), toVertex);
	if (itTo == vertices.end())
	{
		return false; // вершина toVertex не существует в графе
	}
	int indexTo = std::distance(vertices.begin(), itTo);

	// проверка, что индекс fromVertex корректен
	if (indexFrom < 0 || indexFrom >= (int)edges.neighbours.size())
	{
		return false;
	}

	// ищем индекс toVertex в списке смежности вершины fromVertex
	const std::vector<int>& neighboursOfFrom = edges.neighbours[indexFrom];
	auto itEdge = std::find(neighboursOfFrom.begin(), neighboursOfFrom.end(), indexTo);

	// Если нашли - дуга существует
	return itEdge != neighboursOfFrom.end();
}


bool DirGraph::addEdge(int fromVertex, int toVertex)
{
	// ищем fromVertex
	auto itFrom = std::find(vertices.begin(), vertices.end(), fromVertex);
	if (itFrom == vertices.end())
	{
		return false; // вершина fromVertex не существует в графе
	}
	int indexFrom = std::distance(vertices.begin(), itFrom);

	// ищем toVertex
	auto itTo = std::find(vertices.begin(), vertices.end(), toVertex);
	if (itTo == vertices.end())
	{
		return false; // вершина toVertex не существует в графе
	}
	int indexTo = std::distance(vertices.begin(), itTo);

	// проверяем корректность
	if (indexFrom < 0 || indexFrom >= (int)edges.neighbours.size())
	{
		return false;
	}

	// добавляем индекс в список смежности
	edges.neighbours[indexFrom].push_back(indexTo);

	return true;
}


adjacencyList* DirGraph::getEdges() const
{
	// создаём новый объект в динамической памяти
	adjacencyList* result = new adjacencyList();

	// копируем данные из внутреннего поля графа
	result->countOfVertices = edges.countOfVertices;
	result->neighbours = edges.neighbours;

	return result;
}


bool DirGraph::dirGraphIsEqual(const DirGraph & otherGraph)
{
	// сравниваем вершины
	if (vertices != otherGraph.vertices)
	{
		return false;
	}

	// Сравниваем списки смежности через готовый метод isEqualTo
	return edges.isEqualTo(otherGraph.edges);
}


DirGraph* DirGraph::generateSpanningTree(int rootVertex) const
{
	// проверка, что такой корень есть
	auto itRoot = std::find(vertices.begin(), vertices.end(), rootVertex);
	if (itRoot == vertices.end())
		return nullptr;
	int rootIndex = std::distance(vertices.begin(), itRoot);

	// массив посещённых
	std::vector<bool> visited(vertices.size(), false);
	visited[rootIndex] = true;

	// дуги, по которым мы прошли
	std::vector<std::pair<int, int>> treeEdges;

	// очередь для вершин
	std::queue<int> queue;
	queue.push(rootIndex);

	// обходим граф в ширину
	while (!queue.empty())
	{
		int sourceIdx = queue.front();
		queue.pop();

		for (int neighborIdx : edges.neighbours[sourceIdx])
		{
			if (!visited[neighborIdx])
			{
				visited[neighborIdx] = true;
				queue.push(neighborIdx);
				// запоминаем дугу, по которой прошли
				treeEdges.push_back({ sourceIdx, neighborIdx });
			}
		}
	}

	// пересчитываем индексы для посещённых вершин
	std::vector<int> oldToNewIndex(vertices.size(), -1);
	int newIndex = 0;
	for (size_t i = 0; i < vertices.size(); i++)
	{
		if (visited[i])
		{
			oldToNewIndex[i] = newIndex;
			newIndex++;
		}
	}

	// создаём результирующий граф
	DirGraph* tree = new DirGraph();
	tree->edges.countOfVertices = newIndex;
	tree->edges.neighbours.resize(newIndex);

	// заносим посещённые вершины
	for (size_t i = 0; i < vertices.size(); i++)
		if (visited[i])
			tree->vertices.push_back(vertices[i]);

	// заполняем список смежности
	for (const auto& edge : treeEdges)
	{
		int fromOldIdx = edge.first;
		int toOldIdx = edge.second;

		int fromNewIdx = oldToNewIndex[fromOldIdx];
		int toNewIdx = oldToNewIndex[toOldIdx];

		tree->edges.neighbours[fromNewIdx].push_back(toNewIdx);
	}

	return tree;
}


Error::Error() {
	errorInputFileWay = "";
	errorOutputFileWay = "";
	errorTagName = "";
	int line = -1;
}

Error::Error(errorType typeOfError) {
	type = typeOfError;
	errorInputFileWay = "";
	errorOutputFileWay = "";
	errorTagName = "";
	line = -1;
}

Error::Error(int lineOfError) {
	type = innerDescriptionSyntaxError;
	errorInputFileWay = "";
	errorOutputFileWay = "";
	errorTagName = "";
	line = lineOfError;
}

Error::~Error() {
	;
}

bool Error::isEqualTo(const Error& otherError) const {
	if (type == otherError.type &&
		errorInputFileWay == otherError.errorInputFileWay &&
		errorOutputFileWay == otherError.errorOutputFileWay &&
		errorTagName == otherError.errorTagName &&
		line == otherError.line)
		return true;
	else return false;
}


std::string Error::generateErrorMessage() const
{
	switch (type)
	{
	case inFileNotExist:
		return "Ошибка: входной файл не существует или недоступен для чтения. Путь: \""
			+ errorInputFileWay + "\"";

	case createOutFileFail:
		return "Ошибка: не удалось создать или открыть выходной файл для записи. Путь: \""
			+ errorOutputFileWay + "\"";

	case edgeNumberError:
		return "Ошибка: некорректное количество дуг в графе.";

	case verticesNumberError:
		return "Ошибка: некорректное количество вершин в графе.";

	case defenitionLineSyntaxError:
		return "Ошибка синтаксиса в строке определения графа (ожидается \"digraph <имя> {\").";

	case innerDescriptionSyntaxError:
		if (line >= 0)
		{
			return "Ошибка синтаксиса во внутреннем описании графа в строке "
				+ std::to_string(line) + ".";
		}
		return "Ошибка синтаксиса во внутреннем описании графа.";

	case endLineSyntaxError:
		if (line >= 0)
		{
			return "Ошибка синтаксиса в строке завершения графа (ожидается \"}\") в строке "
				+ std::to_string(line) + ".";
		}
		return "Ошибка синтаксиса в строке завершения графа (ожидается \"}\").";

	default:
		return "Неизвестная ошибка.";
	}
}


std::string trim(const std::string& str)
{
	// набор whitespace-символов
	const std::string whitespace = " \t\n\r\f\v";

	// ищем первый пробельный символ
	size_t start = str.find_first_not_of(whitespace);
	if (start == std::string::npos)
	{
		// строка пустая/состоит из пробелов
		return "";
	}
	// ищем последний не пробельный символ
	size_t end = str.find_last_not_of(whitespace);

	// возвращаем подстроку от start до end включительно
	return str.substr(start, end - start + 1);
}


bool extractTokensFromString(std::string& str, std::string& delimeter, std::vector<std::string>& tokens)
{
	// пустой разделитель - некорректные данные
	if (delimeter.empty())
	{
		return false;
	}

	// очищаем токены
	tokens.clear();

	// если строка пустая, оставляем вектор пустым
	if (str.empty())
	{
		return true;
	}

	int start = 0;
	int end = 0;
	int delimLen = delimeter.length();

	// ищем разделители в строке
	while ((end = str.find(delimeter, start)) != std::string::npos)
	{
		// извлекаем токен и обрезаем пробелы по краям
		std::string token = trim(str.substr(start, end - start));

		// если токен непустой, добавляем его
		if (!token.empty())
		{
			tokens.push_back(token);
		}

		// сдвигаем начало на позицию после разделителя
		start = end + delimLen;
	}

	// обрабатываем последний токен (после последнего разделителя)
	std::string lastToken = trim(str.substr(start));
	if (!lastToken.empty())
	{
		tokens.push_back(lastToken);
	}

	return true;
}


DirGraph* parseGraphFromText(std::vector<std::string>& fileText, int inDegrees[1000], std::vector<Error>& errorVector)
{	//очистка входных данных
	for (int i = 0; i < 1000; i++)
		inDegrees[i] = 0;
	errorVector.clear();

	// проверка на пустой файл
	if (fileText.empty())
	{
		Error err(defenitionLineSyntaxError);
		err.line = 1;
		errorVector.push_back(err);
		return nullptr;
	}

	// извлекаем definition line
	std::string firstLine = trim(fileText[0]);
	std::vector<std::string> defTokens;
	std::string space = " ";
	extractTokensFromString(firstLine, space, defTokens);

	// проверка на соответствие ожидаемому формату "digraph <name> {"
	if (defTokens.size() < 2 || defTokens[0] != "digraph" || defTokens.back() != "{")
	{
		Error err;
		err.type = defenitionLineSyntaxError;
		err.line = 1;
		errorVector.push_back(err);
	}
	// ищем закрывающую скобку
	int endLineIndex = -1;
	bool endLineNotFound = false;
	for (int i = (int)fileText.size() - 1; i >= 1; i--)
	{
		std::string line = trim(fileText[i]);
		if (line == "}")
		{
			endLineIndex = i;
			break;
		}
	}
	//если не нашли
	if (endLineIndex == -1)
	{
		endLineNotFound = true;
		// Находим последнюю непустую строку
		int lastNonEmptyLine = -1;
		for (int i = fileText.size() - 1; i >= 1; i--)
		{
			if (!trim(fileText[i]).empty())
			{
				lastNonEmptyLine = i;
				break;
			}
		}

		if (lastNonEmptyLine != -1)
			// парсим все до последней непустой строки невключительно
			endLineIndex = lastNonEmptyLine;
		else
			endLineIndex = (int)fileText.size();

	}

	// парсим граф
	std::vector<int> vertexList;
	std::vector<std::pair<int, int>> edgeList;
	std::vector<int> edgeLineNumbers;
	bool edgesStarted = false;
	std::string arrow = "->";

	for (int i = 1; i < endLineIndex; i++)
	{
		std::string line = trim(fileText[i]);
		if (line.empty())
			continue;

		if (line.find(arrow) != std::string::npos)
		{
			// строка является дугой
			edgesStarted = true;

			std::vector<std::string> edgeTokens;
			extractTokensFromString(line, arrow, edgeTokens);

			if (edgeTokens.size() != 2)	//должно быть 2 токена
			{
				Error err(i + 1);
				errorVector.push_back(err);
				continue;
			}

			int fromVertex, toVertex;
			try
			{
				size_t pos1, pos2;		//токены должны быть числами без лишних символов
				fromVertex = std::stoi(edgeTokens[0], &pos1);
				toVertex = std::stoi(edgeTokens[1], &pos2);

				if (pos1 != edgeTokens[0].length() || pos2 != edgeTokens[1].length())	//если длины не совпадают - значит есть лишние символы
				{
					Error err(i + 1);
					errorVector.push_back(err);
					continue;
				}
			}
			catch (...)
			{
				Error err(i + 1);
				errorVector.push_back(err);
				continue;
			}

			edgeList.push_back({ fromVertex, toVertex });
			edgeLineNumbers.push_back(i + 1);
		}
		else
		{	// Строка является вершиной
			if (edgesStarted)		//неправильный порядок
			{
				Error err(i + 1);
				errorVector.push_back(err);
				continue;
			}
			int vertex;
			try
			{
				size_t pos;
				vertex = std::stoi(line, &pos);
				if (pos != line.length())
				{
					Error err(i + 1);
					errorVector.push_back(err);
					continue;
				}
			}
			catch (...)
			{
				Error err(i + 1);
				errorVector.push_back(err);
				continue;
			}
			vertexList.push_back(vertex);
		}
	}

	// добавляем в конец ошибку об отсутствии закрывающей скобки
	if (endLineNotFound)
	{
		Error err;
		err.type = endLineSyntaxError;
		err.line = (endLineIndex == fileText.size()) ? fileText.size() : (endLineIndex + 1);
		errorVector.push_back(err);
	}

	// создаём граф
	DirGraph* graph = new DirGraph((int)vertexList.size());
	graph->vertices = vertexList;
	graph->edges.countOfVertices = (int)vertexList.size();
	graph->edges.neighbours.resize(vertexList.size());

	// заносим дуги и считаем степени захода
	for (size_t i = 0; i < edgeList.size(); i++)
	{
		int fromVertex = edgeList[i].first;
		int toVertex = edgeList[i].second;
		int lineNumber = edgeLineNumbers[i];  // номер строки в файле

		// проверяем, что обе вершины существуют в графе
		auto itFrom = std::find(vertexList.begin(), vertexList.end(), fromVertex);
		auto itTo = std::find(vertexList.begin(), vertexList.end(), toVertex);

		if (itFrom == vertexList.end() || itTo == vertexList.end())
		{
			Error err(lineNumber);
			errorVector.push_back(err);
			continue;
		}

		// находим индекс вершины-приёмника
		int toIndex = std::distance(vertexList.begin(), itTo);

		// добавляем дугу в граф
		graph->addEdge(fromVertex, toVertex);

		// 
		inDegrees[toIndex]++;
	}
	//сортируем ошибки по номеру строки, где она появилась
	std::sort(errorVector.begin(), errorVector.end(),
		[](const Error& a, const Error& b) {
			return a.line < b.line;
		});
	return graph;
}


graphType findGraphType(const DirGraph& graph, adjacencyList& edgeDifference, int inDegrees[1000])
{
	int vertexCount = graph.vertices.size();
	// Обработка пустого графа
	if (vertexCount == 0)
		return tree; // пустой граф считаем деревом

	// ищем потенциальные корни
	std::vector<int> potentialRoots;
	for (int i = 0; i < vertexCount; i++)
		if (inDegrees[i] == 0)
			potentialRoots.push_back(i);

	// если корней > 1 граф неприводим
	if (potentialRoots.size() > 1)
		return notConvertibleToTree;

	// если корень 1 - строим из него дерево
	if (potentialRoots.size() == 1)
	{
		int rootIdx = potentialRoots[0];
		int rootVertex = graph.vertices[rootIdx];

		DirGraph* spanningTree = graph.generateSpanningTree(rootVertex);
		// проверяем, охватывает ли дерево все вершины
		if (spanningTree->getVertexCount() != vertexCount)
		{
			delete spanningTree;
			return notConvertibleToTree;
		}
		else
		{
			// Вычисляем разность дуг
			adjacencyList* graphEdges = graph.getEdges();
			adjacencyList* treeEdges = spanningTree->getEdges();
			edgeDifference = *graphEdges->substract(*treeEdges);
			delete graphEdges;
			delete treeEdges;
			delete spanningTree;
			if (edgeDifference.isEmpty())
				return tree;
			else
				return convertibleToTree;

			return edgeDifference.isEmpty() ? tree : convertibleToTree;
		}
	}

	if (potentialRoots.size() == 0)
	{// если потенциальных корней нет
		std::vector<bool> tried(vertexCount, false);
		std::stack<int> stack;

		// инициализируем стек первой вершиной
		stack.push(0);
		tried[0] = true;

		// пока стек непустой
		while (!stack.empty())
		{
			int currentIdx = stack.top();
			stack.pop();

			// находим неопробованных родителей
			std::vector<int> untriedParents;
			for (int i = 0; i < vertexCount; i++)
			{
				if (tried[i] || i==currentIdx)
					continue;

				for (int neighborIdx : graph.edges.neighbours[i])
				{
					if (neighborIdx == currentIdx)
					{
						untriedParents.push_back(i);
						break;
					}
				}
			}

			if (untriedParents.empty())
			{
				// нет родителей - пытаемся построить дерево
				int rootVertex = graph.vertices[currentIdx];
				DirGraph* spanningTree = graph.generateSpanningTree(rootVertex);
				if (spanningTree != nullptr && spanningTree->getVertexCount() == vertexCount)
				{
					adjacencyList* graphEdges = graph.getEdges();
					adjacencyList* treeEdges = spanningTree->getEdges();
					edgeDifference = *graphEdges->substract(*treeEdges);

					delete graphEdges;
					delete treeEdges;
					delete spanningTree;

					return edgeDifference.isEmpty() ? tree : convertibleToTree;
				}
				delete spanningTree;
			}
			else if (untriedParents.size() == 1)
			{
				stack.push(untriedParents[0]);
				tried[untriedParents[0]] = true;
			}
			else
			{
				for (int i = (int)untriedParents.size() - 1; i >= 0; i--)
				{
					stack.push(untriedParents[i]);
					tried[untriedParents[i]] = true;
				}
			}
		}

		return notConvertibleToTree;
	}
}


int main(int argc, char * argv[])
{
	
}
