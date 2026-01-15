#include "parser.hpp"
#include <sstream>

std::vector<std::string> split(const std::string& line, char separator) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream ss(line);

    while(std::getline(ss, token, separator)) {
        tokens.push_back(token);
    }

    return tokens;
}