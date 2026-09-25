#include "cli.hpp"

std::ifstream getInputFromCLI(int argc, char* argv[]) {;
    if (argc < 2) {
        throw std::runtime_error("Not enough arguments. Usage: jtpack <input>");
    }

    std::ifstream inputFile(argv[1], std::ios::binary);
    if (!inputFile) {
        throw std::runtime_error("No file with that name.");
    } else if (getExtension(argv[1]) != ".json") {
        throw std::runtime_error("File must be JSON.");
    } else {
        return inputFile;
    }
}