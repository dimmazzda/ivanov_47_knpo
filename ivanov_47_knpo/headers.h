#pragma once
#include <vector>

/**
* @brief возможные типы графа в терминах задачи
*/
enum graphType { tree, convertibleToTree, notConvertibleToTree };


/**
* @brief возможные ошибки
*/
enum errorType {
	inFileNotExist, createOutFileFail, edgeNumberError, verticesNumberError,
	defenitionLineSyntaxError, innerDescriptionSyntaxError, endLineSyntaxError
};


/**
* @brief список смежности
* @details представляет собой двуменрый массив, первый индекс - номер вершины-источника,
* второй индекс - номер вершины-приёмника, возможны несколько вхождений одной вершины-приёмника для описания
* кратных связей
*/
struct adjacencyList
{
	//поля структуры

	std::vector<std::vector<int>> neighbours; ///< двуменый массив дуг
	int countOfVertices; ///< количество вершин


	//методы

	/**
	* @brief проверка на полное отсутствие дуг
	* 
	* @return true Если список пустой
	* @return false Если список непустой
	*/
	bool isEmpty();


	/**
	* @brief проверка на равенство двух списков
	* 
	* @note порядок описания дуг внутри векторов неважен
	* @param otherList [in] Константная ссылка на второй список смежности для сравнения
	* @return true Если списки равны
	* @return false Если списки неравны
	*/
	bool isEqualTo(const adjacencyList & otherList);


	/**
	* @brief нахождение разности двух списков
	* @details убирает из первого списка все дуги, содержащиеся во втором
	* @note каждая дуга вычитается в том количестве, в котором содержится в вычитаемом
	* @param subtrahend [in] Константная ссылка на вычитаемое
	* @return Указатель на новый список - результат вычитания
	*/
	adjacencyList * substract(const adjacencyList & subtrahend);
};