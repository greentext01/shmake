#ifndef FILEREADER_H
#define FILEREADERH

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class fileReader
{
private:
    string buffer;
    vector<string> contents;
    ifstream fileStream;
    int findTarget(string target);
public:
    fileReader(string fileName);
    void readFile();
    void execute(string target);
};

#endif