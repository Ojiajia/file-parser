#include "FilesParse.h"
#include <stdio.h>
#include <dirent.h>
#include <fstream>

using namespace std;
FilesParse::FilesParse()
{
    //ctor

}

FilesParse::FilesParse(char* dirPath, char* fileName)
{
    fileForWrite = fileName;
    ofstream file (fileName);
    file.close();
    if(scanDir(dirPath)) {
        cout << "successfully";
    }


}

FilesParse::~FilesParse()
{
    //dtor
}

bool FilesParse::scanDir(char *path)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (path)) != NULL) {

      while ((ent = readdir (dir)) != NULL) {
        if (strcmp (ent->d_name, "..") != 0 && strcmp (ent->d_name, ".") != 0) {
            //printf ("%s\n", ent->d_name);

            if(!readFile(string(ent->d_name),string(path))) {
                cout<<"READ ERROR"<<endl;
            }
        }

      }
      closedir (dir);
    } else {

      perror ("");
      return false;
    }
    return true;
}

bool FilesParse::readFile(string fileName, string path)
{
    string filePath = path  +"\\"+ fileName;
    ifstream file(filePath);

    string str,sep;

    if (file.is_open()) {
        getline(file, sep);
        while(getline(file, str)) {
            //cout<<str<<endl;

        }
    }else{
        cout<<"FILE NOT OPEN "<< filePath<<endl;
        return false;
    }
    file.close();

    if(!writeFile(str, sep, fileName)){
        cout<<"WRITE ERROR"<<endl;;
        return false;
    }
    return true;
}

bool FilesParse::writeFile(string str, string sep, string fileName)
{
    ofstream outFile;
    outFile.open(fileForWrite, ios::app);
    char chstr[str.size()+1];
    strcpy(chstr,str.c_str());
    const char *del = sep.c_str();
    char *sub = strtok(chstr, del);

    if(outFile.is_open()) {
            outFile << fileName << endl;
        while (sub != NULL) {
            outFile<<sub<<endl;
            //cout<<sub<<endl;
            sub = strtok(NULL, del);

        }
    }else{
        return false;
    }

    outFile.close();

    return true;
}
