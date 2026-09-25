#include <fstream>
#include <string>
#include <unordered_map>


void writeDictionaryToFile(std::ofstream &outputFile, const std::unordered_map<std::string, std::string> &dictionary);
void translateToJByte(std::ifstream &inputFile, std::ofstream &outputFile, const std::unordered_map<std::string, std::string> &dictionary);

