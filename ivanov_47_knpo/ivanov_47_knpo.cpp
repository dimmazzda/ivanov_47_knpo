#include <iostream>
#include "headers.h"
#include <algorithm>


bool adjacencyList::isEmpty()
    {
        for (int i = 0; i < countOfVertices; i++)       //если для всех вершин нет связей, список пустой
            if (neighbours[i].size() != 0)              //если хоть для одной есть - непустой
                return false;
        return false;
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


int main(int argc, char * argv[])
{

}
