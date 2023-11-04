#ifndef ___Parser__

#include <tuple>
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <sstream>

class Parser {
    private:
        int instructionAmount; //This is the amount of maximum instruction used in our program
        int instructionPointer; //This will point to the current address in RAM

        std::string binFileName;

        std::list<std::pair<std::string, std::string>> instructions;
        std::list<std::pair<std::string, std::string>> registers;

        std::string replace(std::string content, const std::string key, const std::string value);
        std::string replaceInstruction(std::string content, const std::string key, const std::string value);
        std::string replaceRoutine(std::string content);

        std::tuple<std::string, std::string, std::string> parseInstruction(std::string line);
    public:
        Parser(std::string contentToParse);
        std::string parseFile(std::string content, std::string fileName);
        bool writeBinFile(std::string content);
        std::string hashRoutine(std::string input);
};

#endif