#include "HtmlWriter.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

HtmlWriter::HtmlWriter(string path)
{
    //Вычисляем имя файла без расширения
    unsigned int pos = path.find_last_of('.');
    if (pos != string::npos) {
        mPath = string(path.c_str(), pos);
    }
    else
        mPath = path;
    mMaxLine = 0;
    mCountLineFile = 0;
    mCountFile = 0;
    mCountLineSent = 0;

    html_begin = "<html>\n    <head>\n    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n";
    html_end = "\n</html>";
}

HtmlWriter::~HtmlWriter() {
    //Если есть незаписанные строки предложения, добавляем в файл
    if (mCountLineSent)
        *curOut << mSentence;
    *curOut << html_end;
    curOut->close();
}

int HtmlWriter::addLine(string * ptrLine) {
    if (mCountLineSent !=0) {
        //Если предложение не пустое,добавляем переход на новую строку
        mSentence += "<br/>";
        mSentence += "\n";
    }
    //Ищем с конца строки точку, для нахождения конца предложения
    unsigned int pos = ptrLine->find_last_of('.');
    if (pos != string::npos) {
        //Добавляем конец предложения
        mSentence +=string(ptrLine->c_str(), pos + 1) ;
        mCountLineSent++;
        //Записываем в файл
        if (writeSentence() !=0)
            return -1;
        if (pos != ptrLine->length()) {
            //Если есть начало предложения
            mCountLineSent = 1;
            mSentence = string(ptrLine->c_str() + pos + 1);
        } else
            //Если нет начала предложения, кол-во строк в предложениии обнуляем
            mCountLineSent = 0;
    } else {
        //Если нет конца предложения, добавляем всю строку
        mSentence += *ptrLine;
        mCountLineSent++;
    }
    return 0;
}

int HtmlWriter::writeSentence() {
    //Кол-во строк равно 0, значит файла еще нет
    if (mCountLineFile == 0) {
        //Формируем имя для файла
        string path;
        if (mMaxLine) {
            char tmp[10];
            memset(tmp, 0, sizeof(tmp));
            sprintf(tmp, "%d", mCountFile);
            path = mPath + "_" + tmp + ".html";
        }
        else
            path = mPath + ".html";

        curOut = new ofstream(path.c_str());
        if (!curOut) {
            cout << "Ошибка создания файла. " << path << endl;
            return -1;
        }
        //Записываем заголовок html-страницы
        *curOut << html_begin;
        //Записываем предложение
        *curOut << mSentence;
        //Увеличиваем кол-во строк в файле
        mCountLineFile += mCountLineSent;
        //Если кол-во строк превышает максимальное
        if (mMaxLine && (mCountLineFile > mMaxLine)) {
            //Обнуляем кол-во строк в предложении
            mCountLineSent = 0;
            //Обнуляем кол-во строк в файле
            mCountLineFile = 0;
            //Записываем конец html
            *curOut << html_end;
            //Закрываем файл
            curOut->close();
            //Увеличиваем кол-во записанных файлов
            mCountFile++;
        }
    }
    else {
        //Если при добавлении след предложения кол-во строк превысит максимальное
        if (mMaxLine && (mCountLineFile + mCountLineSent - 1 > mMaxLine)) {
            mCountLineFile = 0;
            *curOut << html_end;
            curOut->close();
            mCountFile++;
            writeSentence();
        }
        else {
            //Увеличиваем кол-во строк и записываем предложение
            mCountLineFile += mCountLineSent - 1;
            *curOut << mSentence;
            mCountLineSent = 0;
        }
    }
    return 0;
}
