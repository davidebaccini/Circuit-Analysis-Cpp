#include "component.hpp"
#include <stdexcept>

Component makeComponent(const std::vector<std::string>& tokens, int j) {
    if (tokens.size() < 5) {
        throw std::runtime_error("Invalid component line");
    }
    
    int id = j;
    bool type = std::stoi(tokens[0]);
    const std::string& name = tokens[1];
    double value = std::stod(tokens[2]);
    int n1 = std::stoi(tokens[3]);
    int n2 = std::stoi(tokens[4]);

    return Component(id, type, name, value, n1, n2);
}