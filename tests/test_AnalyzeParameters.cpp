#include <QtTest/QTest>
#include "../src/AnalyzeParameters.h"
#include <QDebug>
#include <iostream>
#include <fstream>
#include <vector>
#include <QFile>

class Test_AnalyzeParameters : public QObject {
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void normParameters();
    void badParamN_1();
    void badParamN_2();
};

void Test_AnalyzeParameters::initTestCase() {
    ofstream out("dict.txt");
    if (!out) {
        cout << "Error open." << endl;
        return;
    }
    out << "текст1" << endl << "текст2" << endl << "текст1" << endl;
    out.close();
}

void Test_AnalyzeParameters::cleanupTestCase() {
    QFile file("dict.txt");
    file.remove();
}

void Test_AnalyzeParameters::normParameters() {
    const char* argv[]= {"test", "-n", "10", "-f", "file.txt", "-dict", "dict.txt"};
    vector<string> dict;
    dict.push_back("текст1");
    dict.push_back("текст2");
    int argc = 7;

    try {
        AnalyzeParameters param(argc, argv);
        QCOMPARE(10, param.getMaxLine());
        QCOMPARE(string("file.txt") , param.getFile());
        QVERIFY(dict == *param.getDict());
    } catch (AnalyzeParametersException e){
        cout << e.strErr;
        QVERIFY(false);
    }
}

void Test_AnalyzeParameters::badParamN_1() {
    const char* argv[]= {"test", "-n", "b10", "-f", "file.txt", "-dict", "dict.txt"};
    int argc = 7;
    try {
        AnalyzeParameters param(argc, argv);
    } catch (AnalyzeParametersException e){
        QVERIFY(true);
    }
}

void Test_AnalyzeParameters::badParamN_2() {
    const char* argv[]= {"test", "-n", "-10", "-f", "file.txt", "-dict", "dict.txt"};
    int argc = 7;
    try {
        AnalyzeParameters param(argc, argv);
    } catch (AnalyzeParametersException e){
        QVERIFY(true);
    }
}

QTEST_APPLESS_MAIN(Test_AnalyzeParameters)
#include "test_AnalyzeParameters.moc"
