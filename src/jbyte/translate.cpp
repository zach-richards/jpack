#include "translate.hpp"

void writeDictionaryToFile(std::ofstream &outputFile, const std::unordered_map<std::string, std::string> &dictionary) {
    outputFile << "0A" << std::endl << std::endl; // Write dict code

    outputFile << dictionary.size() << std::endl << std::endl; // Write number of entries

    int iteration = 0;
    for (const auto &pair : dictionary) {
        outputFile << std::setw(4) << std::setfill('0') << iteration << " " << pair.second.length() << " " << pair.second << std::endl;
        iteration++;
    }
}

void translateToJByte(std::ifstream &inputFile, std::ofstream &outputFile, const std::unordered_map<std::string, std::string> &dictionary) {
}