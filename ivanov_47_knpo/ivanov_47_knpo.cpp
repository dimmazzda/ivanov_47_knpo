#include <iostream>
#include "headers.h"
#include <algorithm>
#include <queue>

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


adjacencyList* DirGraph::getEdges()
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


DirGraph* DirGraph::generateSpanningTree(int rootVertex)
{
	// проверка, что такой корень есть
	auto itRoot = std::find(vertices.begin(), vertices.end(), rootVertex);
	if (itRoot == vertices.end())
	{
		return nullptr; // корень не найден
	}
	int rootIndex = std::distance(vertices.begin(), itRoot);

	// массив посещённых
	std::vector<bool> visited(vertices.size(), false);

	// корень сразу считается посещённым
	visited[rootIndex] = true;

	// очередь для вершин
	std::queue<int> queue;
	queue.push(rootIndex);

	// обходим граф в ширину
	while (!queue.empty())
	{
		int sourceIdx = queue.front();
		queue.pop();

		// перебираем непосещённых соседей 
		for (int neighborIdx : edges.neighbours[sourceIdx])
		{
			if (!visited[neighborIdx])
			{
				visited[neighborIdx] = true;
				queue.push(neighborIdx);
			}
		}
	}

	// для посещённых вершин пересчитываем индекс с учётом удалённых вершин
	std::vector<int> oldToNewIndex(vertices.size(), -1); // -1 = вершина не в дереве
	int newIndex = 0;
	for (int i = 0; i < vertices.size(); i++)
	{
		if (visited[i])
		{
			oldToNewIndex[i] = newIndex;
			newIndex++;
		}
	}

	// подготавливаем результирующий граф
	DirGraph* tree = new DirGraph();
	tree->edges.countOfVertices = newIndex;
	tree->edges.neighbours.resize(newIndex);

	// заносим в граф только попавшие в обход вершины
	for (int i = 0; i < vertices.size(); i++)
	{
		if (visited[i])
		{
			tree->vertices.push_back(vertices[i]);
		}
	}

	// заполняем список смежности, пересчитывая индексы
	for (size_t i = 0; i < vertices.size(); i++)
		if (visited[i])
		{
			int currentNewIdx = oldToNewIndex[i];

			for (int neighborOldIdx : edges.neighbours[i])
			{
				// Добавляем дугу только если сосед тоже посещён
				if (visited[neighborOldIdx])
				{
					int neighborNewIdx = oldToNewIndex[neighborOldIdx];
					tree->edges.neighbours[currentNewIdx].push_back(neighborNewIdx);
				}
			}
		}

	return tree;
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


int main(int argc, char * argv[])
{
	
}
