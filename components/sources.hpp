#pragma once

class V_DC {
    double voltage;

public:
    V_DC(double v) {
        this->voltage = v;
    }
};

class A_DC {
    double current;

public:
    A_DC(double a) {
        this->current = a;
    }
};