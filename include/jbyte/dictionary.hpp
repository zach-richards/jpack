#include <fstream>
#include <string>
#include <unordered_map>
#include <limits>
#include <iostream>

std::unordered_map<std::string, std::string> createDictionary(std::ifstream &inputFile, std::ofstream &outputFile);