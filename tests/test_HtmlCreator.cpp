#include "../src/HtmlCreator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "gtest/gtest.h"

TEST(Test_HtmlCreator, replace) {
    HtmlCreator html;
    vector<string> v;
    v.push_back("жирный");
    html.setDict(&v);
    string str("текст жирный_и курсивный и жирный");
    string str_res("текст жирный_и курсивный и <b><i>жирный</i></b>");
    html.replace(&str);
    ASSERT_EQ(str_res, str);
}
