#include <fstream>
#include <string>
#include <unordered_map>
#include <limits>   // Required for std::numeric_limits
#include <iostream> // For std::endl

// create a dictionary from a JSON file and return it
std::unordered_map<std::string, std::string> createDictionary(std::ifstream &inputFile, std::ofstream &outputFile) {
    int count = 0;
    std::unordered_map<std::string, std::string> dictionary;

    std::string key, value;
    int ch;

    // Correctly loop using the stream's get method to find the opening quote of a key
    while ((ch = inputFile.get()) != EOF) {
        if (ch == '"') {
            // 1. Read the key (up to the next quote)
            std::getline(inputFile, key, '"');

            // 2. Skip the colon and whitespace up to the opening quote of the value
            inputFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
            inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '"');

            // 3. Read the value (up to the closing quote)
            std::getline(inputFile, value, '"');

            // 4. Add the key-value pair to the dictionary
            dictionary[key] = value;

            count++;
        }
    }

    // Return the populated dictionary instead of an empty one
    return dictionary;
}
