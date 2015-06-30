#include "HtmlCreator.h"
#include "HtmlWriter.h"
#include <fstream>
#include <iostream>

using namespace std;

#define LINE_LENGTH 1000

using namespace std;

HtmlCreator::HtmlCreator()
{
}

int HtmlCreator::analyze() {
    ifstream in(mFile.c_str());
    if (!in) {
        cout << "Ошибка открытия файла " << mFile << endl;
        return -1;
    }
    cout << mFile << endl;

    //Создаем объект для формирования html-страниц
    HtmlWriter htmlWriter(mFile);
    htmlWriter.setMaxLine(mMaxLine);

    char buf[LINE_LENGTH];
    //Читаем построчно файл
    while (in) {
        in.getline(buf, LINE_LENGTH);
        string line(buf);
        //Редактируем строку согласно словарю
        for (unsigned int i=0; i < mDict->size(); i++)
            replace(&line, mDict->at(i));
        //Передаем отредактированную строку
        if (htmlWriter.addLine(&line) != 0)
            return -1;
    }
    return 0;
}

void HtmlCreator::replace(string* line, const string word) {
    //Открывающиеся теги
    string tag_start("<b><i>");
    //Закрывающиеся теги
    string tag_end("</i></b>");
    unsigned int pos = 0;
    //Ищем позицию вхождения слова в строке
    pos = line->find(word, pos);
    while (pos != string::npos) {
        //Вставляем открывающиеся теги
        line->insert(pos, tag_start);
        //Вычисляем позию для закрывающихся тегов
        pos += tag_start.length() + word.length();
        //Вставляем закрывающиеся теги
        line->insert(pos, tag_end);
        pos += tag_end.length();
        //Продолжаем поиск
        pos = line->find(word, pos);
    }
}
