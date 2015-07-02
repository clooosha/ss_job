#include "../src/AnalyzeParameters.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <gtest/gtest.h>

class TestAnalyzeParameters: public ::testing::Test
{
protected:
    void SetUp()
    {
        ofstream out("dict.txt");
        if (!out) {
            cout << "Error open." << endl;
            return;
        }
        out << "текст1" << endl << "текст2" << endl << "текст1" << endl;
        out.close();
    }
    void TearDown()
    {
        remove("dict.txt");
    }
};

TEST_F(TestAnalyzeParameters,normParameters) {
    const char* argv[]= {"test", "-n", "10", "-f", "file.txt", "-d", "dict.txt"};
    vector<string> dict;
    dict.push_back("текст1");
    dict.push_back("текст2");
    int argc = 7;

    try {
        AnalyzeParameters param(argc, argv);
        ASSERT_EQ(10, param.getMaxLine());
        ASSERT_EQ(string("file.txt") , param.getFile());
        ASSERT_EQ(dict , *param.getDict());
    } catch (AnalyzeParametersException e){
        cout << e.strErr;
        ASSERT_TRUE(false);
    }
}

TEST_F(TestAnalyzeParameters, badParam_N_bad) {
    const char* argv[]= {"test", "-n", "b10", "-f", "file.txt", "-d", "dict.txt"};
    int argc = 7;
    try {
        AnalyzeParameters param(argc, argv);
    } catch (AnalyzeParametersException e) {
        ASSERT_TRUE(true);
    }
};

TEST_F(TestAnalyzeParameters, badParam_N_negative) {
    const char* argv[]= {"test", "-n", "-10", "-f", "file.txt", "-d", "dict.txt"};
    int argc = 7;
    try {
        AnalyzeParameters param(argc, argv);
    } catch (AnalyzeParametersException e){
        ASSERT_TRUE(true);
    }
}
