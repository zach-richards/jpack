#include <fstream>
#include <string>
#include <iostream>

std::string getExtension(const std::string& filename) {
    size_t pos = filename.find_last_of('.');
    if (pos != std::string::npos) {
        return filename.substr(pos);
    }
    return "";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary);
    if (!file) {
        std::cerr << "No file with that name" << std::endl;
        return 1;
    } else if (getExtension(argv[1]) != ".json") {
        std::cerr << "File must be a JSON file" << std::endl;
        return 1;
    } else {
        std::cout << argv[1] << std::endl;
    }

    std::string outputFilename = argv[1];
    size_t pos = outputFilename.find_last_of('.');
    if (pos != std::string::npos) {
        outputFilename.replace(pos, 5, ".jbyte");
    }

    std::ofstream outputFile(outputFilename, std::ios::binary);

    int braceCounter = 0;
    for (char byte; file.get(byte);) {
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

    file.close();
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