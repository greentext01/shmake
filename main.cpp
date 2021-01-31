#include "fileReader.hpp"
#include <unistd.h>
#define PATH_MAX 4096

int main(int argc, char* argv[]) {
    char cwd[PATH_MAX];
    if(argc < 2){
        cout << "Error: specify target\n";
        return 1;
    }
    fileReader fr(string(getcwd(cwd, sizeof(cwd))) + "/Shmfile");
    fr.readFile();
    fr.execute(argv[1]);
    return 0;
}