#include "reader.hpp"
#include <fstream>

std::vector<std::string> readLines(const std::string& path) {
    std::vector<std::string> lines;
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + path);
    }
    
    std::string line;

    while(std::getline(file, line)) {
        if(line != "") {
            lines.push_back(line);
        }
    }

    return lines;
}
