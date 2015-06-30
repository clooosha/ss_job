#include <QtTest/QTest>
#include "../src/HtmlCreator.h"
#include <QDebug>
#include <iostream>
#include <fstream>
#include <vector>
#include <QFile>

class Test_HtmlCreator : public QObject {
    Q_OBJECT
private slots:
    //void initTestCase();
    //void cleanupTestCase();
    void replace();
};

void Test_HtmlCreator::replace() {
//    HtmlCreator html;
//    string str("текст жирный и курсивный и жирный");
//    string str_res("текст <b><i>жирный</i></b> и курсивный и <b><i>жирный</i></b>");
//    html.replace(&str, "жирный");
//    QCOMPARE(str_res, str);
}

QTEST_APPLESS_MAIN(Test_HtmlCreator)
#include "test_HtmlCreator.moc"
