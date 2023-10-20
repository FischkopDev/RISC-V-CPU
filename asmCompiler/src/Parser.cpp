#include "Parser.h"

Parser::Parser(std::string contentToParse){
    if(contentToParse.length() == 0)
        std::cerr << "There is nothing to parse" << std::endl;

    //setup of all instructions
    instructions.push_back(std::make_pair("ADD", "01"));
    instructions.push_back(std::make_pair("ADDI", "02"));
    instructions.push_back(std::make_pair("SUB", "03"));
    instructions.push_back(std::make_pair("SUBI", "04"));
    instructions.push_back(std::make_pair("MULT", "05"));
    instructions.push_back(std::make_pair("MULTI", "06"));
    instructions.push_back(std::make_pair("JMP", "10"));
    instructions.push_back(std::make_pair("BEQ", "11"));
    instructions.push_back(std::make_pair("BNEQ", "12"));

}

std::tuple<std::string, std::string, std::string> Parser::parseInstruction(std::string line){
    //TODO
}

//replace parts in string
std::string replace(std::string original, std::string toReplace, std::string replacement){
    size_t found = original.find(toReplace);

    while (found != std::string::npos) {
        original.replace(found, toReplace.length(), replacement);
        found = original.find(toReplace, found + replacement.length());
    }
    return original;
}

std::string Parser::parseFile(std::string content){
    for(std::pair element : instructions){
        content = replace(content, element->first(), element->second());
    }
}

std::string Parser::hashRoutine(std::string input){
    return input; //TODO create hash function
}