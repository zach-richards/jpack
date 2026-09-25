#include <fstream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> createDictionary(std::ifstream &inputFile, std::ofstream &outputFile);