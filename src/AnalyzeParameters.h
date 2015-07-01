#ifndef ANALYZEPARAMETERS_H
#define ANALYZEPARAMETERS_H
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

/*
 * @brief Класс исключения, для отображения ошибки генерируемой классом AnalyzeParameters
 *
 */
class AnalyzeParametersException {
public:
    //Информация о возникшей ошибке
    string strErr;
    AnalyzeParametersException(const char *par, string err = "") {strErr = string("Неверный параметр. ") + string(par) + string(". ") + err + "\n";}
};

/*
 * @brief Класс для проверки входных параметров, генерирует исключение AnalyzeParametersException
 *
 */
class AnalyzeParameters
{
public:
    /*
     * @brief Конструктор класса
     * @param argc кол-во передаваемых параметров
     * @param const char* argv[] массив указателей на c-строку. содержащую имя параметра
     * @throw AnalyzeParametersException передан неверный параметр
     */
    AnalyzeParameters(int argc, const char* argv[]);
    /*
     * @brief Функция возвращает имя файла, к-ый нужно проанализировать
     * @return имя файла
     */
    string getFile() {return mOut;}
    /*
     * @brief Функция максимальное кол-во строк, к-ое может содержать html
     * @return кол-во строк
     */
    int getMaxLine() {return mMaxLine;}
    /*
     * @brief Функция возвращает вектор слов типа string из словаря
     * @return вектор слов
     */
    vector<string>* getDict() {return &mDict;}
private:
    string mOut;
    vector<std::string> mDict;
    int mMaxLine;
    int readMap(const char* path);
};

#endif // ANALYZEPARAMETERS_H
