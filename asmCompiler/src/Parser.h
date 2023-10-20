#ifndef ___Parser__

#include <tuple>
#include <string>
#include <iostream>
#include <map>
#include <list>

class Parser {
    private:
        int instructions = 0; //This is the amount of maximum instruction used in our program
        int instructionPointer = 0; //This will point to the current address in RAM
        std::list<std::pair<std::string, std::string>> instructions;

        std::string replace(std::string original, std::string toReplace, std::string replacement);
        std::tuple<std::string, std::string, std::string> parseInstruction(std::string line);
    public:
        Parser(std::string contentToParse);
        std::string parseFile(std::string content);
        bool writeBinFile(std::string content);
        std::string hashRoutine(std::string input);
};

#endif