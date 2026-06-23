#include <iostream>
#include "headers.h"
#include <algorithm>
#include <queue>
#include <stdexcept>
#include <stack>
#include <fstream>
#include <windows.h>
#include <map>


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
    return edges.countOfVertices;	//возвращаем значения
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
	//сравниваем все поля
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
	case inFileNotExist:	//нет входного файла
		return "Ошибка: входной файл не существует или недоступен для чтения. Путь: \""
			+ errorInputFileWay + "\"";

	case createOutFileFail:		//не создался выходной файл
		return "Ошибка: не удалось создать или открыть выходной файл для записи. Путь: \""
			+ errorOutputFileWay + "\"";

	case edgeNumberError:		//неверное кол-во дуг
		return "Ошибка: некорректное количество дуг в графе.";

	case verticesNumberError:	//неверное кол-во вершин
		return "Ошибка: некорректное количество вершин в графе.";

	case defenitionLineSyntaxError:		//ошибка в строке объявления графа
		return "Ошибка синтаксиса в строке определения графа (ожидается \"digraph <имя> {\").";

	case innerDescriptionSyntaxError:	//ошибка во внутреннем описании графа
		if (line >= 0)
		{
			return "Ошибка синтаксиса во внутреннем описании графа в строке "
				+ std::to_string(line) + ".";
		}
		return "Ошибка синтаксиса во внутреннем описании графа.";

	case endLineSyntaxError:		//ошибка в последней строке
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


bool extractTokensFromString(std::string& str, const std::string & delimeter, std::vector<std::string>& tokens)
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


bool tryParseInt(const std::string& str, int& result)
{
	try
	{
		size_t pos;
		result = std::stoi(str, &pos);
		return pos == str.length(); // все символы строки потреблены
	}
	catch (...)
	{
		return false;
	}
}


void parseInnerLine(const std::string& line, int lineNumber, std::vector<int>& vertexList, std::vector<std::pair<int, int>>& edgeList, std::vector<int>& edgeLineNumbers, bool& edgesStarted, std::vector<Error>& errorVector)
{
	//обрезаем лишние пробелы
	std::string trimmed = trim(line);
	if (trimmed.empty())
		return;

	std::string arrow = "->";
		//если содержит знак ->
	if (trimmed.find(arrow) != std::string::npos)
	{
		// Строка является дугой
		edgesStarted = true;

		std::vector<std::string> tokens;
		extractTokensFromString(trimmed, arrow, tokens);
		//если не соответствует шаблону число->число
		if (tokens.size() != 2)
		{
			errorVector.push_back(Error(lineNumber));
			return;
		}

		int fromVertex, toVertex;
		if (!tryParseInt(tokens[0], fromVertex) || !tryParseInt(tokens[1], toVertex))
		{
			errorVector.push_back(Error(lineNumber));
			return;
		}

		edgeList.push_back({ fromVertex, toVertex });
		edgeLineNumbers.push_back(lineNumber);
	}
	else
	{
		// Строка является вершиной
		if (edgesStarted)
		{
			errorVector.push_back(Error(lineNumber));
			return;
		}

		int vertex;
		//если не парсится как число - ошибка
		if (!tryParseInt(trimmed, vertex))
		{
			errorVector.push_back(Error(lineNumber));
			return;
		}

		vertexList.push_back(vertex);
	}
}



void processEdges(const std::vector<std::pair<int, int>>& edgeList, const std::vector<int>& edgeLineNumbers, const std::vector<int>& vertexList, DirGraph* graph, int inDegrees[1000], std::vector<Error>& errorVector)
{
	//для каждой вершины
	for (size_t i = 0; i < edgeList.size(); i++)
	{
		int fromVertex = edgeList[i].first;
		int toVertex = edgeList[i].second;
		int lineNumber = edgeLineNumbers[i];
		//проверяем наличие 
		auto itFrom = std::find(vertexList.begin(), vertexList.end(), fromVertex);
		auto itTo = std::find(vertexList.begin(), vertexList.end(), toVertex);

		if (itFrom == vertexList.end() || itTo == vertexList.end())
		{
			Error err(lineNumber);
			errorVector.push_back(err);
			continue;
		}
		//добавляем
		int toIndex = std::distance(vertexList.begin(), itTo);
		graph->addEdge(fromVertex, toVertex);
		inDegrees[toIndex]++;
	}
}


DirGraph* parseGraphFromText(std::vector<std::string>& fileText, int inDegrees[1000], std::vector<Error>& errorVector)
{
	// Очистка входных данных
	for (int i = 0; i < 1000; i++)
		inDegrees[i] = 0;
	errorVector.clear();

	// Проверка на пустой файл
	if (fileText.empty())
	{
		Error err(defenitionLineSyntaxError);
		err.line = 1;
		errorVector.push_back(err);
		return nullptr;
	}

	// Извлекаем definition line
	std::string firstLine = trim(fileText[0]);
	std::vector<std::string> defTokens;
	std::string space = " ";
	extractTokensFromString(firstLine, space, defTokens);

	// Проверка на соответствие ожидаемому формату
	if (defTokens.size() < 2 || defTokens[0] != "digraph" || defTokens.back() != "{")
	{
		Error err(defenitionLineSyntaxError);
		err.line = 1;
		errorVector.push_back(err);
	}

	// Ищем закрывающую скобку
	int endLineIndex = -1;
	bool endLineNotFound = false;
	int lastNonEmptyLine = -1;

	for (int i = (int)fileText.size() - 1; i >= 1; i--)
	{
		std::string line = trim(fileText[i]);

		if (line == "}")
		{
			endLineIndex = i;
			break;
		}

		if (!line.empty() && lastNonEmptyLine == -1)
			lastNonEmptyLine = i;
	}

	if (endLineIndex == -1)
	{
		endLineNotFound = true;
		endLineIndex = (lastNonEmptyLine != -1) ? lastNonEmptyLine : (int)fileText.size();
	}

	// Парсим граф
	std::vector<int> vertexList;
	std::vector<std::pair<int, int>> edgeList;
	std::vector<int> edgeLineNumbers;
	bool edgesStarted = false;

	for (int i = 1; i < endLineIndex; i++)
	{
		parseInnerLine(fileText[i], i + 1, vertexList, edgeList,
			edgeLineNumbers, edgesStarted, errorVector);
	}

	// Добавляем ошибку об отсутствии закрывающей скобки
	if (endLineNotFound)
	{
		Error err(endLineSyntaxError);
		err.line = (endLineIndex == (int)fileText.size()) ? (int)fileText.size() : (endLineIndex + 1);
		errorVector.push_back(err);
	}

	// Создаём граф
	DirGraph* graph = new DirGraph((int)vertexList.size());
	graph->vertices = vertexList;
	graph->edges.countOfVertices = (int)vertexList.size();
	graph->edges.neighbours.resize(vertexList.size());

	// обрабатываем дуги
	processEdges(edgeList, edgeLineNumbers, vertexList, graph, inDegrees, errorVector);

	// Сортируем ошибки
	std::sort(errorVector.begin(), errorVector.end(),
		[](const Error& a, const Error& b) {
			return a.line < b.line;
		});

	return graph;
}


graphType tryBuildTreeFromVertex(const DirGraph& graph, int rootIdx, int vertexCount, adjacencyList& edgeDifference)
{
	//строим остовное дерево
	DirGraph* spanningTree = graph.generateSpanningTree(graph.vertices[rootIdx]);
	//если не построилось или охватывает не все вершины
	if (spanningTree == nullptr || spanningTree->getVertexCount() != vertexCount)
	{
		delete spanningTree;
		return notConvertibleToTree;
	}
	adjacencyList* graphEdges = graph.getEdges();
	adjacencyList* treeEdges = spanningTree->getEdges();
	edgeDifference = *graphEdges->substract(*treeEdges);
	//зачистка
	delete graphEdges;
	delete treeEdges;
	delete spanningTree;

	return edgeDifference.isEmpty() ? tree : convertibleToTree;
}


graphType findGraphType(const DirGraph& graph, adjacencyList& edgeDifference, int inDegrees[1000])
{
	//считаем кол-во вершин
	int vertexCount = graph.vertices.size();
	if (vertexCount == 0)
		return tree;

	//считаем потенциальные корни
	std::vector<int> potentialRoots;
	for (int i = 0; i < vertexCount; i++)
		if (inDegrees[i] == 0)
			potentialRoots.push_back(i);

	switch (potentialRoots.size())
	{
	case 1:	// потенциальный корень один
		return tryBuildTreeFromVertex(graph, potentialRoots[0], vertexCount, edgeDifference);

	case 0:		// потенциальных корней нет
	{
		//создаём хранилища для опробованных вершин и вершин, которые остаётся опробовать
		std::vector<bool> tried(vertexCount, false);
		std::stack<int> stack;

		stack.push(0);
		tried[0] = true;
		//пока в стеке есть вершины на апробацию
		while (!stack.empty())
		{
			int currentIdx = stack.top();
			stack.pop();

			std::vector<int> untriedParents;
			for (int i = 0; i < vertexCount; i++)
			{
				if (tried[i] || i == currentIdx)	//если это петля или уже опробованная вершина скип
					continue;
				//ищем родителей
				for (int neighborIdx : graph.edges.neighbours[i])
				{
					if (neighborIdx == currentIdx)
					{
						untriedParents.push_back(i);
						break;
					}
				}
			}
			//Если родителей нет
			if (untriedParents.empty())
			{
				graphType result = tryBuildTreeFromVertex(graph, currentIdx, vertexCount, edgeDifference);
				if (result != notConvertibleToTree)
					return result;
			}
			else          //если есть - строим из первого по номеру, остальные заносим в стек (если есть)
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

	default:
		return notConvertibleToTree;
	}
}


bool readTextFromFile(std::vector<std::string>& fileText, std::string& fileName, std::vector<Error>& errorVector)
{
	// очищаем контейнер перед заполнением
	fileText.clear();

	// открываем файл для чтения
	std::ifstream file(fileName);

	// проверяем, что файл успешно открылся
	if (!file.is_open())
	{
		Error err;
		err.type = inFileNotExist;
		err.errorInputFileWay = fileName;
		err.line = -1;
		errorVector.push_back(err);
		return false;
	}

	// Считываем файл построчно
	std::string line;
	while (std::getline(file, line))
	{
		fileText.push_back(line);
	}

	// Закрываем файл
	file.close();

	return true;
}

void printErrorsMessages(const std::vector<Error>& errorsVector)
{	//для каждой ошибки выводим сообщение
	for (int i = 0; i < errorsVector.size(); i++)
	{
		std::string curMessage = errorsVector[i].generateErrorMessage();
		std::cout << curMessage << std::endl;
	}
}


std::string processEdgeLine(const std::string& line, graphType type, const std::vector<std::string>& vertexNames, const std::map<std::pair<int, int>, int>& edgesToDeleteCount, std::map<std::pair<int, int>, int>& highlightedCount)
{
	std::string trimmed = trim(line);

	// если граф не приводимый или строка не дуга
	if (type != convertibleToTree || trimmed.find("->") == std::string::npos)
		return line;

	std::vector<std::string> tokens;
	std::string arrow = "->";
	extractTokensFromString(trimmed, arrow, tokens);

	// если строка не по формату
	if (tokens.size() != 2)
		return line;

	std::string fromName = trim(tokens[0]);
	std::string toName = trim(tokens[1]);

	auto itFrom = std::find(vertexNames.begin(), vertexNames.end(), fromName);
	auto itTo = std::find(vertexNames.begin(), vertexNames.end(), toName);

	// если одной из вершин нет
	if (itFrom == vertexNames.end() || itTo == vertexNames.end())
		return line;

	int fromIdx = std::distance(vertexNames.begin(), itFrom);
	int toIdx = std::distance(vertexNames.begin(), itTo);

	auto key = std::make_pair(fromIdx, toIdx);

	// если дуги нет в карте, считаем, что 0
	int requiredCount = 0;
	auto itCount = edgesToDeleteCount.find(key);
	if (itCount != edgesToDeleteCount.end())
		requiredCount = itCount->second;

	int currentCount = highlightedCount[key];

	// Если ещё не все дуги помечены — помечаем текущую
	if (currentCount < requiredCount)
	{
		highlightedCount[key]++;
		return trimmed + " [color=\"red\"]";
	}

	return line;
}


std::vector<std::string> generateOutputText(graphType type, std::vector<std::string>& inputFilePlainText, adjacencyList& edgesToDelete)
{
	std::vector<std::string> outputText;

	// извлекаем имена вершин
	std::vector<std::string> vertexNames;
	for (const auto& line : inputFilePlainText)
	{
		std::string trimmed = trim(line);
		if (trimmed.empty() ||
			trimmed.find("digraph") != std::string::npos ||
			trimmed == "}")
			continue;

		if (trimmed.find("->") == std::string::npos)
			vertexNames.push_back(trimmed);
	}

	// преобразование enum graphType в строку
	auto typeToString = [](graphType t) -> std::string
		{
			switch (t)
			{
			case tree:                 return "tree";
			case convertibleToTree:    return "convertibleToTree";
			case notConvertibleToTree: return "notConvertibleToTree";
			default:                   return "unknown";
			}
		};
	std::string resultNodeName = "resultOfAnalysis: " + typeToString(type);

	// подсчёт кол-ва каждой дуги edgesToDelete
	std::map<std::pair<int, int>, int> edgesToDeleteCount;
	for (int fromIdx = 0; fromIdx < edgesToDelete.countOfVertices; fromIdx++)
	{
		for (int toIdx : edgesToDelete.neighbours[fromIdx])
		{
			edgesToDeleteCount[{fromIdx, toIdx}]++;
		}
	}

	// счётчик уже выделенных дуг
	std::map<std::pair<int, int>, int> highlightedCount;

	// построчная обработка с модификацией
	bool resultNodeInserted = false;

	for (const auto& line : inputFilePlainText)
	{
		std::string trimmed = trim(line);

		// вставляем вершину-результат перед закрывающей скобкой
		if (trimmed == "}" && !resultNodeInserted)
		{
			outputText.push_back("\"" + resultNodeName + "\"");
			resultNodeInserted = true;
		}

		// обработка строки
		outputText.push_back(processEdgeLine(line, type, vertexNames,
			edgesToDeleteCount, highlightedCount));
	}

	// Если в файле не оказалось "}", вставляем результат в конец
	if (!resultNodeInserted)
		outputText.push_back("\"" + resultNodeName + "\"");

	return outputText;
}


int writeTextToFile(std::vector<std::string>& outputText, std::string& outputFileName, std::vector<Error>& errorsVector)
{
	//пытаемся открыть файл
	std::ofstream outFile(outputFileName);
	if (!outFile.is_open())
	{
		Error err;
		err.type = createOutFileFail;
		err.errorOutputFileWay = outputFileName;
		errorsVector.push_back(err);
		return 1;
	}
	//выводим построчно
	for (const auto& line : outputText)
		outFile << line << "\n";
	//закрываем файл
	outFile.close();
	return 0;
}


int main(int argc, char* argv[])
{
	// настройка кодировки консоли
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// проверка количества аргументов
	if (argc != 3)
		return 1;

	std::string inputFileName = argv[1];
	std::string outputFileName = argv[2];

	// читаем входной файл
	std::vector<std::string> fileText;
	std::vector<Error> errorsVector;
	if (!readTextFromFile(fileText, inputFileName, errorsVector))
	{
		printErrorsMessages(errorsVector);
		return 1;
	}

	// парсинг графа
	int inDegrees[1000] = { 0 };
	DirGraph* graph = parseGraphFromText(fileText, inDegrees, errorsVector);

	// если парсинг неудачный - выводим ошибки
	if (!errorsVector.empty())
	{
		printErrorsMessages(errorsVector);
		delete graph;  // освобождаем память
		return 1;
	}


	// анализ графа
	errorsVector.clear();
	adjacencyList edgesToDelete;
	graphType type = findGraphType(*graph, edgesToDelete, inDegrees);

	// формируем выходной текст
	std::vector<std::string> outputText = generateOutputText(type, fileText, edgesToDelete);

	// записываем в файл
	if (writeTextToFile(outputText, outputFileName, errorsVector) != 0)
	{
		printErrorsMessages(errorsVector);
		delete graph;
		return 1;
	}

	// Освобождение памяти
	delete graph;
	return 0;
}



