#pragma once

#include <string>
#include <vector>

class Component {
    int type; // 1 = V, 0 = R for now.
    double value;
    int n1, n2;

public:
    Component(){
        this->type = 0;
        this->value = 0;
        this->n1 = 0;
        this->n2 = 0;
    }
    Component(std::vector<std::string> tokens){
        type = std::stoi(tokens[0]);
        value = std::stod(tokens[1]);
        n1 = std::stoi(tokens[2]);
        n2 = std::stoi(tokens[3]);
    }
    

    int get_n1() {
        return this->n1;
    }

    int get_n2() {
        return this->n2;
    }

};