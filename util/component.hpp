#pragma once

#include <string>
#include <vector>

class Component {
    int id;
    bool type;
    std::string name;
    double value;
    int n1, n2;

public:

    Component(int id, bool type, const std::string& name, double value, int n1, int n2)
        : id(id), type(type), name(name), value(value), n1(n1), n2(n2) {}
    int get_n1() {
        return this->n1;
    }

    int get_n2() {
        return this->n2;
    }

    int getId(){
        return this->id;
    }
};

Component makeComponent(const std::vector<std::string>& tokens, int i);