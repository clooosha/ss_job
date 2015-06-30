#ifndef HTMLCREATOR_H
#define HTMLCREATOR_H

#include <vector>
#include <string>

using namespace std;

class HtmlCreator
{
public:
    HtmlCreator();
    void replace(string* line, const string word);
    void setFile(string file) {mFile = file;}
    void setDict(vector<string> * dict) {mDict = dict;}
    void setMaxLine(int maxLine) {mMaxLine = maxLine;}
    int analyze();
private:
    int mMaxLine;
    string mFile;
    vector<string> * mDict;
    void writeLine(string* ptrLine);
};

#endif // HTMLCREATOR_H
