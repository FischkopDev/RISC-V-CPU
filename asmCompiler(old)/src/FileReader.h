/*
    Read the actual content from a given file.
    Also check some stuff about the file.
*/
#ifndef __FileReader__

#include <string>
#include <iostream>
#include <fstream>

class FileReader {
    private:
        std::string fileName;
        std::string fileDir;
        int linePointer = 0;
        int maxLinePointer = 0;

    public:
        FileReader(std::string fileName);

        std::string getFileContent();
        bool isFileEmpty();
        bool hasNextLine();
        bool existsFile();
};


#endif