#ifndef ANALYZEPARAMETERS_H
#define ANALYZEPARAMETERS_H
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class AnalyzeParametersException {
public:
    string strErr;
    AnalyzeParametersException(const char *par, string err = "") {strErr = string("Неверный параметр. ") + string(par) + string(". ") + err + "\n";}
};

class AnalyzeParameters
{
public:
    AnalyzeParameters(int argc, const char* argv[]);
    string getFile() {return mOut;}
    int getMaxLine() {return mMaxLine;}
    vector<string>* getDict() {return &mDict;}
private:
    string mOut;
    vector<std::string> mDict;
    int mMaxLine;
    int readMap(const char* path);
};

#endif // ANALYZEPARAMETERS_H
