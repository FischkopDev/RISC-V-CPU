#include "FileReader.h"

FileReader::FileReader(std::string fileName) : fileName(fileName){
    if(!existsFile())
        std::cerr << "This file couldn't be opened. It might not exist" << std::endl;
}

std::string FileReader::getFileContent(){
    std::string all = ""; //variable for entire content
    
    //check if file exists
    if(existsFile()){
        //open it
        std::ifstream file;
        file.open(fileName);

        //get its content
        std::string line = "";
        while(std::getline(file, line)){
            all += line + "\n";
            linePointer++;
        }
        maxLinePointer = linePointer;
        linePointer = 0;
    }

    return all;
}

bool FileReader::isFileEmpty(){
    if(existsFile())
        return getFileContent().length() == 0;
    else
        return true;
}

bool FileReader::hasNextLine(){
    return maxLinePointer > linePointer;
}

bool FileReader::existsFile(){
    //open the file
    std::ifstream file;
    file.open(fileName);

    //set the current status
    bool status = file.is_open();

    //close the file again if open
    if(status)
        file.close();

    return status;
}