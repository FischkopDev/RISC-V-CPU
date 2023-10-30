#include "Parser.h"
#include <iostream>
#include <fstream>

Parser::Parser(std::string contentToParse) {
    if (contentToParse.empty()) {
        std::cerr << "There is nothing to parse" << std::endl;
        // Handle the error, e.g., throw an exception or return.
    }

    // Setup of all instructions
    instructions.push_back(std::make_pair("ADD", "01"));
    instructions.push_back(std::make_pair("ADDI", "02"));
    instructions.push_back(std::make_pair("SUB", "03"));
    instructions.push_back(std::make_pair("SUBI", "04"));
    instructions.push_back(std::make_pair("MULT", "05"));
    instructions.push_back(std::make_pair("MULTI", "06"));
    instructions.push_back(std::make_pair("JMP", "10"));
    instructions.push_back(std::make_pair("BEQ", "11"));
    instructions.push_back(std::make_pair("BNEQ", "12"));

    //setup all registers
    registers.push_back(std::make_pair("zero","00"));
    registers.push_back(std::make_pair("ra","01"));
    registers.push_back(std::make_pair("sp","02"));
    registers.push_back(std::make_pair("gp","03"));
    registers.push_back(std::make_pair("tp","04"));
    registers.push_back(std::make_pair("t0","05"));
    registers.push_back(std::make_pair("t1","06"));
    registers.push_back(std::make_pair("t2","07"));
    registers.push_back(std::make_pair("s0","08"));
    registers.push_back(std::make_pair("s1","09"));
    registers.push_back(std::make_pair("s2","0A"));

}

//std::tuple<std::string, std::string, std::string> Parser::parseInstruction(std::string line) {
    // Implement the logic to parse instructions.
    // You should return a tuple with the parsed information.

/*
    Replace the actual content. This will replace a string with another string. 
    It goes for each entry in the given string.
*/
std::string Parser::replace(std::string content, const std::string key, const std::string value) {
    size_t pos = 0;
    while ((pos = content.find(key, pos)) != std::string::npos) {
        content.replace(pos, key.length(), value);
        // Move past the replaced portion to avoid an infinite loop
        pos += value.length();
    }
    return content;
}

/*
    Parse a file and replace its content with specific constrains.
    The parsed part will be written down into another file for 
    translating more efficient if no big changes accured.
*/
std::string Parser::parseFile(std::string content, std::string fileName) {
    //For each element in our instruction replace the instruction inside the file with its
    //Hex code.
    for (const std::pair<std::string, std::string>& element : instructions) {
        content = replace(content, element.first, element.second);
    }

    //replace each mentioned register with its hex code
    for (const std::pair<std::string, std::string>& element : registers) {
        content = replace(content, element.first, element.second);
    }

    //write the parsed content back to a file with <filename>.bin 
    std::ofstream outputFile("../../asmPrograms/" + fileName + ".bin");
    if (outputFile.is_open()) {
        outputFile << content;
        outputFile.close();
    } else {
        std::cerr << "Unable to open the file '" << fileName << "' for writing." << std::endl;
    }

    //return the content to continue translating/executing the file.
    return content;
}

std::string Parser::hashRoutine(std::string input) {
    // TODO Implement the hash function.
    // You can use a standard hash function or custom logic as needed.
    return "";
}