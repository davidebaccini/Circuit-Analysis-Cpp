#pragma once

#include <string>
#include <vector>

class Component {
    bool type; // 1 = V, 0 = R for now.
    double value;
    int n1, n2;

public:

    Component(bool type, double value, int n1, int n2)
        : type(type), value(value), n1(n1), n2(n2) {}

    int get_n1() {
        return this->n1;
    }

    int get_n2() {
        return this->n2;
    }

};