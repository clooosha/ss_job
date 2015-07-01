#include "AnalyzeParameters.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LENGTH_LINE 1000

AnalyzeParameters::AnalyzeParameters(int argc, const char* argv[])
{
    mMaxLine = 0;
    for(int i=1; i<argc; i+=2)
        if (!strcmp(argv[i], "-f")) {
            if (i+1 < argc) {
                mOut = argv[i+1];
            }
            else
                throw AnalyzeParametersException(argv[i], "Отсутствует значение.\n");
        } else if (!strcmp(argv[i], "-n")) {
            if (i+1 < argc) {
                 mMaxLine = atol(argv[i+1]);
                 if (mMaxLine < 1)
                     throw AnalyzeParametersException(argv[i]);
            }
            else
                throw AnalyzeParametersException(argv[i]);
        } else if (!strcmp(argv[i], "-dict")) {
            if (i+1 < argc) {
                readMap(argv[i+1]);
            }
            else
                throw AnalyzeParametersException(argv[i], "Отсутствует значение.\n");
        }
        else {
            throw AnalyzeParametersException(argv[i], "Нет в списке возможных.\n");
        }

    if (mOut.length() == 0)
        throw AnalyzeParametersException("-f", "Нет в списке переданных параметров.\n");
    if (mDict.size() == 0)
        throw AnalyzeParametersException("-dict", "Нет в списке переданных параметров.\n");
}

int AnalyzeParameters::readMap(const char* path) {
    ifstream in(path);
    if (!in) {
        //std::cout << "Невозможно открыть файл " << path;
        throw AnalyzeParametersException("-dict", "Невозможно открыть файл.\n");
        return -1;
    }

    char line[LENGTH_LINE];

    while(in) {
        in.getline(line, LENGTH_LINE);
        //Добавляем в вектор, если нет данного элемента
        if (strlen(line) && find(mDict.begin(), mDict.end(), string(line)) == mDict.end())
        {
            mDict.push_back(line);
        }
    }
    return 0;
}
