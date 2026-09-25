#include "translate.hpp"

void writeDictionaryToFile(std::ofstream &outputFile, const std::unordered_map<std::string, std::string> &dictionary) {
    outputFile << "0A" << std::endl << std::endl; // Write dict code

    int dictSize = dictionary.size();

    for (const auto &pair : dictionary) {
        outputFile << pair.first << ":" << pair.second << std::endl;
    }
}

void translateToJByte(std::ifstream &inputFile, std::ofstream &outputFile, const std::unordered_map<std::string, std::string> &dictionary) {
}