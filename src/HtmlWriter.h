#ifndef HTMLWRITER_H
#define HTMLWRITER_H
#include <string>

using namespace std;

class HtmlWriter
{
public:
    HtmlWriter(string path);
    ~HtmlWriter();
    void setMaxLine(int maxLine){mMaxLine = maxLine;}
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
