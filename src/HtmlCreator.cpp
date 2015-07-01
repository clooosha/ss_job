#include "HtmlCreator.h"
#include "HtmlWriter.h"
#include <fstream>
#include <iostream>
#include <algorithm>

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
    //cout << mFile << endl;

    //Создаем объект для формирования html-страниц
    HtmlWriter htmlWriter(mFile);
    htmlWriter.setMaxLine(mMaxLine);

    char buf[LINE_LENGTH];
    //Читаем построчно файл
    while (in) {
        in.getline(buf, LINE_LENGTH);
        string line(buf);
        //Редактируем строку согласно словарю
        if (line.length() > 0) {
            replace(&line);
            //Передаем отредактированную строку
            if (htmlWriter.addLine(&line) != 0)
                return -1;
        }
    }
    return 0;
}

void HtmlCreator::replace(string* line) {
    //Открывающиеся теги
    string tag_start("<b><i>");
    //Закрывающиеся теги
    string tag_end("</i></b>");
    unsigned char pos = 0;
    while (pos < line->length()) {
        if (line->at(pos) != ' ') {
            unsigned char word_start = pos;
            pos ++;
            while (pos < line->length() && line->at(pos) != ' ')
                pos++;
            unsigned char word_end= pos;
            string word(*line, word_start, word_end - word_start);
            if (find(mDict->begin(), mDict->end(), word) != mDict->end()) {
                line->insert(word_start, tag_start);
                line->insert(word_start + tag_start.length() + word.length(), tag_end);
                pos += tag_start.length() + tag_end.length();
            }
        }
        pos++;
    }/*




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
    }*/
}
