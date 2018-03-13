#ifndef FILESPARSE_H
#define FILESPARSE_H
#include <iostream>
#include <cstring>

using namespace std;
class FilesParse
{
    public:
        FilesParse();
        FilesParse(char* dirPath, char *fileName);
        virtual ~FilesParse();

    protected:

    private:
        bool scanDir(char *path);
        bool readFile(string file, string path);
        bool writeFile(string str, string sep, string fileName);
        const char *fileForWrite;

};

#endif // FILESPARSE_H
