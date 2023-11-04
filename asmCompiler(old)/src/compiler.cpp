#include <iostream>
#include "FileReader.cpp"
#include "Parser.cpp"

int main(){
    FileReader fr("../../asmPrograms/showcase.asm");

    std::string content = fr.getFileContent();
    Parser p(content);
    p.parseFile(content, "showcase");
    return 0;   
}