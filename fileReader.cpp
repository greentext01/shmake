#include "fileReader.hpp"

fileReader::fileReader(string fileName)
{
    fileStream = ifstream(fileName);
    if(!fileStream.good()){
        throw runtime_error("Error: no such file");
    }
}

void fileReader::readFile()
{
    while(getline(fileStream, buffer)) {
        int index = buffer.find_first_not_of(' ');
        if(index != string::npos) {
            buffer = buffer.substr(index);
        }
        if(buffer[0] == '#') continue;
        contents.push_back(buffer);
    }
}

int fileReader::findTarget(string target)
{
    for(int line = 0; line < contents.size(); line++) {
        string currentLine = contents[line];
        if(currentLine == ":" + target) {
            return line;
        }
    }
    throw runtime_error("Error: no such target");
}

void fileReader::execute(string target)
{
    int targetLine = findTarget(target);
    for(int i = targetLine + 1; i < contents.size(); i++) {
        string currentLine = contents[i];
        switch(currentLine[0]){
            case ';':
                cout << "--" << currentLine.substr(1) << "--\n";
                break;
            
            case ':':
                return;
                break;
            
            case ',':
                execute(currentLine.substr(1));
                break;
            default:
                system(currentLine.c_str());
                break;
        }
    }
}