#pragma once
#include <vector>
#include <string>


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


/**
* @brief класс для ошибок
*/
class Error
{
	//поля
	errorType type;		///<тип ошибки
	std::string errorInputFileWay;		///<строка пути, откуда не удалось прочитать файл
	std::string errorOutputFileWay;		///<строка пути, куда не удалось записать файл
	std::string errorTagName;			///<строка, хранящая имя неизвестного тега


	//методы
	/**
	* @brief генерация сообщения об ошибке
	* @return строка с сообщением об ошибке
	*/
	std::string generateErrorMessage();
};


/**
* @brief класс ориентированного графа
*/
class DirGraph
{
	// поля
	adjacencyList edges;	///< дуги графа в виде списка смежности


	// конструктор/деструктор
	DirGraph();		///<конструктор по умолчанию создаёт пустой граф
	~DirGraph();	///<деструктор по умолчаниюю


	// методы

	/**
	* @brief получить количество вершин
	* @return количество вершин графа
	*/
	int getVertexCount();


	/**
	* @brief проверка на наличие дуги
	* 
	* @param fromVertex [in] Индекс вершины, из которой исходит дуга
	* @param toVertex [in] Индекс вершины, в которую заходит дуга
	* @return true Если дуга есть в графе
	* @return false Если дуги нет в графе
	*/
	bool hasEdge(int fromVertex, int toVertex);


	/**
	* @brief добавить дугу в граф
	* @details добавляет дугу в граф, если входные вершины содержатся в графе
	* @param fromVertex [in] Индекс вершины, из которой исходит дуга
	* @param toVertex [in] Индекс вершины, в которую заходит дуга
	* @return true Если дуга добавлена
	* @return false Если дуга не добавлена
	*/
	bool addEdge(int fromVertex, int toVertex);


	/**
	* @brief получить дуги графа
	* @details извлекает дуги графа в виде списка смежности для последующих операций
	* @return указатель на список смежности
	*/
	adjacencyList * getEdges();


	/**
	* @brief проверить графы на равенство
	* @details графы равны если полностью совпадают вершины и дуги между ними
	* @note порядок описания дуг внутри списка смежности неважен, только состав
	* @param otherGraph [in] Константная ссылка на второй граф для сравнения
	* @return указатель на список смежности
	*/
	bool dirGraphIsEqual(const DirGraph & otherGraph);


	/**
	* @brief построить остовное дерево графа
	* @details обходит граф в ширину из указанной вершины и попутно строит остовное дерево
	* @param rootVertex [in] Индекс вершины-корня
	* @return указатель на новый граф - остовное дерево
	*/
	DirGraph * generateSpanningTree(int rootVertex);
};


// описания функций

/**
* @brief главная функция программы
* @param argc [in] Количество переданных аргументов командной строки
* @param argv[1] [in] Путь к проектному файлу
* @param argv[2] [in] Путь к выходной директории
* @return 0, если функция завершилась успешно
*/
int main(int argc, char* argv[]);


/**
* @brief функция чтения текста из файла
* @param fileText [in/out] Контейнер для записи текста из файла
* @param fileName [in] Путь к файлу с текстом
* @param errorVector [in/out] Контейнер для ошибок
* @return true, если функция завершилась успешно
* @return false, если функция завершилась с ошибками
*/
bool readTextFromFile(std::vector<std::string>& fileText, std::string & fileName, std::vector<Error> errorVector);


/**
* @brief функция парсинга графа из текста
* @param fileText [in] Контейнер с текстом
* @param inDegrees [in/out] Массив со степенями полузаходов вершин
* @param errorVector [in/out] Контейнер для ошибок
* @return Указатель на созданный граф
*/
DirGraph * parseGraphFromText(std::vector<std::string>& fileText, int * inDegrees[1000], std::vector<Error> errorVector);


/**
* @brief делит строку на токены по заданному разделителю
* @details возможен многосимвольный разделитель
* @param delimeter [in] Строка с разделителем
* @param tokens [in/out] Вектор с токенами
* @return true Если функция завершилась успешно
* @return false Если функция завершилась с ошибками
*/
bool extractTokensFromString(std::string & delimeter, std::vector<std::string> & tokens);


/**
* @brief определить тип графа
* @details определяет тип графа в соответствии с перечесленим graphType и возвращает его. Если граф приводим
* к дереву, находит список дуг, удаление которых сделает граф деревом
* @param graph [in] Константная ссылка на граф
* @param edgeDifference [in/out] Список смежности для разности дуг между графом и его остовным деревом
* @return Тип графа
*/
graphType findGraphType(const DirGraph & graph, adjacencyList & edgeDifference);