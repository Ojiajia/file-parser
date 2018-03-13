
#include <FilesParse.h>

using namespace std;


int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "enter dir path and file-name"<<endl<<"example: FilePath \"dir-path\" \"file-name.txt\""<<endl;
    } else {
        FilesParse fp(argv[1], argv[2]);
    }

    return 0;
}
