#include <iostream>
#include <string>
#include "AnalyzeParameters.h"
#include "HtmlCreator.h"

using namespace std;

int main(int argc, const char *argv[])
{
    try {
        //Проверяем переданные параметры запуска
        AnalyzeParameters param(argc, argv);
        //Создаем объект для обработки текста и передаем ему нужные пармаетры
        HtmlCreator htmlCreator;
        htmlCreator.setDict(param.getDict());
        htmlCreator.setFile(param.getFile());
        htmlCreator.setMaxLine(param.getMaxLine());
        //Запускаем обработку
        htmlCreator.analyze();
    }
    catch (AnalyzeParametersException e) {
        //Исключение, вывод информации о нем
        cout << e.strErr << endl;
        return -1;
    }
    return 0;
}

