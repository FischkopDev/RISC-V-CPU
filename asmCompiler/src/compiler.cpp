#include <iostream>
#include "FileReader.cpp"

int main(){
    FileReader fr("../../asmPrograms/loopSum.asm");
    std::cout << fr.getFileContent() << std::endl;

    return 0;   
}