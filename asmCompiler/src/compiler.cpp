#include <iostream>
#include "FileReader.cpp"
#include "Parser.cpp"

int main(){
    FileReader fr("../../asmPrograms/loopSum.asm");
    std::cout << fr.getFileContent() << std::endl;

    std::string content = fr.getFileContent();
    Parser p(content);
    p.parseFile(content, "loopSum");
    return 0;   
}