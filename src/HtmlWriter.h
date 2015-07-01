/*
 * @brief Класс для записи строки в html-страницу.
 * @detailed Создает html-страницу, с текстом. Текст передает построчно,
 * при превышении максимального кол-ва строк, создает новая html-страница.
 */

#ifndef HTMLWRITER_H
#define HTMLWRITER_H
#include <string>

using namespace std;

class HtmlWriter
{
public:
    /*
     * @brief Конструктор класса
     * @param path Имя html-страницы для сохранения
     */
    HtmlWriter(string path);
    /*
     * @brief Деструктор класса. Дописывает оставшиеся строки и закрывает файл.
     */
    ~HtmlWriter();
    /*
     * @brief Функция устаналивает максимальное кол-во строк в html.
     * @param maxLine Максимальное кол-во строк
     */
    void setMaxLine(int maxLine){mMaxLine = maxLine;}
    /*
     * @brief Функция добавляет строку в html-страницу.
     * @param line Строка
     */
    int addLine(string* line);
private:
    //Имя файла без расширения
    string mPath;
    //Максимальное кол-во строк в html-страницу
    int mMaxLine;
    //Кол-во строк в предложении
    int mCountLineSent;
    //Кол-во строк уже записанное в html-страницу
    int mCountLineFile;
    //Кол-во записанных файлов
    int mCountFile;
    //Строка, в к-ой хранятся предложения
    string mSentence;
    //Файл вывода
    ofstream * curOut;
    int writeSentence();
    //Заголовок html-страницы
    string html_begin;
    //Конец html-страницы
    string html_end;
};

#endif // HTMLWRITER_H
