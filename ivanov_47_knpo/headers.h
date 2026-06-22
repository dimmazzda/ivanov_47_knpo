#pragma once
#include <vector>
#include <string>


/**
 * @mainpage Программа переброски слагаемых и множителей
 *
 *
 * @section sec_purpose Назначение
 * Программа принимает ориентированный граф описанный по стандартному формату dot
 * и определяет, является ли считанный граф деревом, а также можно ли его привести к дереву
 * и какие дуги для этого понадобится удалить.\n
 * Тип графа выносится отдельным узлом с подписью resultOfAnalysis, дуги, которые можно удалить для
 * приведения графа к дереву помечаеются красным цветом
 * 
 * @section sec_limits Ограничения
 * - имена вершин - целые неотрицательные числа, объявления вершин производятся на отдельных строках до объявления дуг
 * - дуги описываются через знак "->"
 * - Строки объявления и закрывающая скобка находятся на отдельных строках
 * - максимум 1000 вершин и 100000 дуг
 *
 *
 * @section sec_examples Пример преобразования:
 * Входное выражение:\n
 * digraph G {\n
 * 0\n
 * 1\n
 * 2\n
 * 0->1\n
 * 1->2\n
 * 2->1\n
 * }\n
 * Выходное выражение:\n
 * digraph G {\n
 * 0\n
 * 1\n
 * 2\n
 * 0->1\n
 * 1->2\n
 * 2->1 [color="red"]\n
 * "resultOfAnalysis: convertibleToTree"\n
 * }\n
 */

/**
* @brief возможные типы графа в терминах задачи
* @details tree - граф, являющийся деревом
* convertibleToTree - граф, который приводим к дереву удалением некоторого набора дуг
* notConvertibleToTree - граф, который неприводим к дереву
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
public:
	//поля
	errorType type;		///<тип ошибки
	std::string errorInputFileWay;		///<строка пути, откуда не удалось прочитать файл
	std::string errorOutputFileWay;		///<строка пути, куда не удалось записать файл
	std::string errorTagName;			///<строка, хранящая имя неизвестного тега
	int line;							///<номер строки с ошибкой, если ошибка во внутренней структуре файла
	

	//конструктор/деструктор
	Error();				///<базовый конструктор
	Error(errorType type);	///<конструктор ошибки с указанным типом
	Error(int line);		///<конструктор ошибки во внуреннем описании графа по номеру строки (тип ошибки по умолчанию=innerDescriptionSyntaxError)
	~Error();				///<базовый деструктор

	//методы
	/**
	* @brief генерация сообщения об ошибке
	* @return строка с сообщением об ошибке
	*/
	std::string generateErrorMessage() const;


	/**
	* @brief проверка ошибок на равенство
	* @return true, если ошибки одинаковые
	* return false, если ошибки разные
	*/
	bool isEqualTo(const Error& otherError) const;

};


/**
* @brief класс ориентированного графа
*/
class DirGraph
{
public:
	// поля
	std::vector<int> vertices;		///<список вершин графа (упорядоченный)
	adjacencyList edges;	///< дуги графа в виде списка смежности


	// конструктор/деструктор
	DirGraph();		///<конструктор по умолчанию создаёт пустой граф
	DirGraph(int countOfVertices);		///<создаёт граф с указанным количеством вершин без дуг
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
	* @param [in] fromVertex Индекс вершины, из которой исходит дуга
	* @param [in] toVertex Индекс вершины, в которую заходит дуга
	* @return true Если дуга есть в графе
	* @return false Если дуги нет в графе
	*/
	bool hasEdge(int fromVertex, int toVertex);


	/**
	* @brief добавить дугу в граф
	* @details добавляет дугу в граф, если входные вершины содержатся в графе
	* @param [in] fromVertex Индекс вершины, из которой исходит дуга
	* @param [in] toVertex Индекс вершины, в которую заходит дуга
	* @return true Если дуга добавлена
	* @return false Если дуга не добавлена
	*/
	bool addEdge(int fromVertex, int toVertex);


	/**
	* @brief получить дуги графа
	* @details извлекает дуги графа в виде списка смежности для последующих операций
	* @return указатель на список смежности
	*/
	adjacencyList* getEdges() const;


	/**
	* @brief проверить графы на равенство
	* @details графы равны если полностью совпадают вершины и дуги между ними
	* @note порядок описания дуг внутри списка смежности неважен, только состав
	* @param [in] otherGraph Константная ссылка на второй граф для сравнения
	* @return указатель на список смежности
	*/
	bool dirGraphIsEqual(const DirGraph& otherGraph);


	/**
	* @brief построить остовное дерево графа
	* @details обходит граф в ширину из указанной вершины и попутно строит остовное дерево
	* @param [in] rootVertex Индекс вершины-корня
	* @return указатель на новый граф - остовное дерево
	*/
	DirGraph* generateSpanningTree(int rootVertex) const;
};


// описания функций

/**
* @brief главная функция программы
* @param [in] argc Количество переданных аргументов командной строки
* @param [in] argv[1] Путь к проектному файлу
* @param [in] argv[2] Путь к выходной директории
* @return 0, если функция завершилась успешно
*/
int main(int argc, char* argv[]);


/**
* @brief функция чтения текста из файла
* @param [in/out] fileText Контейнер для записи текста из файла
* @param [in] fileName Путь к файлу с текстом
* @param [in/out] errorVector Контейнер для ошибок
* @return true, если функция завершилась успешно
* @return false, если функция завершилась с ошибками
*/
bool readTextFromFile(std::vector<std::string>& fileText, std::string& fileName, std::vector<Error>& errorVector);


/**
* @brief функция парсинга графа из текста
* @param [in] fileText Контейнер с текстом
* @param [in/out] inDegrees Массив со степенями полузаходов вершин
* @param [in/out] errorVector Контейнер для ошибок
* @return Указатель на созданный граф
*/
DirGraph* parseGraphFromText(std::vector<std::string>& fileText, int inDegrees[1000], std::vector<Error>& errorVector);


/**
* @brief обрезает пробельные символы по краям строки
* @details удаляет пробелы, табы, переносы строк и другие whitespace-символы
*          с начала и конца строки. Пробелы внутри строки сохраняются.
* @param [in] str Исходная строка
* @return Обрезанная строка. Если строка состояла только из пробелов — пустая строка
*/
std::string trim(const std::string& str);

/**
* @brief делит строку на токены по заданному разделителю
* @details возможен многосимвольный разделитель
* @param [in] str Строка символов
* @param [in] delimeter Строка с разделителем
* @param [in/out] tokens Вектор с токенами
* @return true Если функция завершилась успешно
* @return false Если функция завершилась с ошибками
*/
bool extractTokensFromString(std::string& str, const std::string& delimeter, std::vector<std::string>& tokens);


/**
* @brief попытаться построить остовное дерево из указанной вершины
* @param [in] graph Исходный граф
* @param [in] rootIdx Индекс вершины-корня
* @param [in] vertexCount Количество вершин в графе
* @param [in/out] edgeDifference Разность дуг графа и дерева
* @return Тип графа: tree, convertibleToTree или notConvertibleToTree
*/
graphType tryBuildTreeFromVertex(const DirGraph& graph, int rootIdx, int vertexCount, adjacencyList& edgeDifference);


/**
* @brief определить тип графа
* @details определяет тип графа в соответствии с перечесленим graphType и возвращает его. Если граф приводим
* к дереву, находит список дуг, удаление которых сделает граф деревом
* @param [in] graph Константная ссылка на граф
* @param [in/out] edgeDifference Список смежности для разности дуг между графом и его остовным деревом
* @param [in] inDegrees Вычисленные при парсинге степепи заходов вершин
* @return Тип графа
*/
graphType findGraphType(const DirGraph& graph, adjacencyList& edgeDifference, int inDegrees[1000]);


/**
* @brief вывод в консоль информации об ошибках
* @param [in] errorsVector контейнер с ошибками
*/
void printErrorsMessages(const std::vector<Error>& errorsVector);


/**
* @brief Обработка строки с дугой: если дуга подлежит удалению, помечает её красным
* @param [in] line Исходная строка из файла
* @param [in] type Тип графа
* @param [in] vertexNames Имена вершин графа (в порядке объявления)
* @param [in] edgesToDeleteCount Количество каждой дуги, подлежащей удалению
* @param [in/out] highlightedCount Счётчик уже помеченных дуг
* @return Модифицированная строка (с пометкой [color="red"]) или исходная строка
*/
std::string processEdgeLine(const std::string& line, graphType type, const std::vector<std::string>& vertexNames, const std::map<std::pair<int, int>, int>& edgesToDeleteCount, std::map<std::pair<int, int>, int>& highlightedCount);

/**
* @brief формирование текста выходного файла
* @param [in] type Найденный тип входного графа
* @param [in] inputFilePlainText Текстовое описание входного графа
* @param [in] edgesToDelete Дуги для удаления
* @return Вектор строк с текстом выходного файла
*/
std::vector<std::string> generateOutputText(graphType type, std::vector<std::string>& inputFilePlainText, adjacencyList& edgesToDelete);


/**
* @brief запись текста в файл
* @param [in] outputText Текст для записи
* @param [in] outputFileName Имя выходного файла
* @param [in/out] errorsVector Контейнер для ошибок
* @return 0, если файл успешно создан
* @return 1, если файл не удалось создать
*/
int writeTextToFile(std::vector<std::string>& outputText, std::string& outputFileName, std::vector<Error>& errorsVector);