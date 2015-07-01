/*
 * @brief Класс для преобразования файла
 * @detailed Читает файл построчно, редактирует строку согласно словарю,
 *           передает строку в класс HtmlWriter для записи.
 *
 */

#ifndef HTMLCREATOR_H
#define HTMLCREATOR_H

#include <vector>
#include <string>

using namespace std;

class HtmlCreator
{
public:
    /*
     * @brief Конструтор
     */
    HtmlCreator();
    /*
     * @brief Функция ищет в переданной строке слова, и вставляет необходимые теги.
     * @param line Строка, где производится поиск.
     */
    void replace(string* line);
    /*
     * @brief Функция устанавливает имя файла, к-ый надо преобразовать.
     * @param file Имя файла
     */
    void setFile(string file) {mFile = file;}
    /*
     * @brief Функция устанавливает вектор слов
     * @param dict вектор слов
     */void setDict(vector<string> * dict) {mDict = dict;}
    /*
     * @brief Функция устаналивает максимальное кол-во строк в html.
     * @param maxLine Максимальное кол-во строк
     */
    void setMaxLine(int maxLine) {mMaxLine = maxLine;}
    /*
     * @brief Функция запускает анализ установленного файла mFile.
     */
    int analyze();
private:
    int mMaxLine;
    string mFile;
    vector<string> * mDict;
    void writeLine(string* ptrLine);
};

#endif // HTMLCREATOR_H
