#include <iostream>
#include <string>

class Bipolar {
protected:
    int terminals = 2;
    double voltage;
    double current;
};

class Resistor : protected Bipolar {
protected:
    double R;

public:
    Resistor(double resistance) {
        this->R = resistance;
    }

    void setResistance(double resistance) {
        this->R = resistance;
    }

    double getResistance() {
        return R;
    }
};

class Capacitor : protected Bipolar {
protected:
    double C;

public:
    Capacitor(double capacitance) {
        this->C = capacitance;
    }

    void setCapacitance(double capacitance) {
        this->C = capacitance;
    }

    double getCapacitance() {
        return C;
    }
};

class Inductor : protected Bipolar {
protected:
    double L;

public:
    Inductor(double inductance) {
        this->L = inductance;
    }

    void setInductance(double inductance) {
        this->L = inductance;
    }

    double getInductance() {
        return L;
    }
};