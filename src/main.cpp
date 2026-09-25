#include <fstream>
#include <string>
#include <iostream>

#include "cli.hpp"

int main(int argc, char* argv[]) {
    std::ifstream inputFile = getInputFromCLI(argc, argv);

    std::string outputFilename = argv[1];
    size_t pos = outputFilename.find_last_of('.');
    if (pos != std::string::npos) {
        outputFilename.replace(pos, 5, ".jbyte");
    }

    std::ofstream outputFile(outputFilename, std::ios::binary);

    int braceCounter = 0;
    for (char byte; inputFile.get(byte);) {
        if (byte == '{') {
            while (byte != ' ') {
                continue;
            }
            outputFile.put('0');
            braceCounter++;
        } else if (byte == '}') {
            braceCounter--;
        } else {
            outputFile.put(byte);
        }
    }

    inputFile.close();
}
/*
    int counter = 0;

    std::ofstream outputFile("output.bin", std::ios::binary);

    for (int i = 0; i < 1; ++i) {
        if (file.get(byte)) {
            outputFile.put(byte);
        }
    }
    file.close();
}*/