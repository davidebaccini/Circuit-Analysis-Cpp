#pragma once

#include <iostream>
#include <vector>

class Circuit {
    int branches;
    int nodes;
    int meshes;

public:
    Circuit(int b, int n, int m) {
        this->branches = b;
        this->nodes = n;
        this->meshes = m;
    }

    int get_branches() {
        return this->branches;
    }

    int get_nodes() {
        return this->nodes;
    }

    int get_meshes() {
        return this->meshes;
    }

    void print() {
        std::cout << "\n\n" <<
            "Branches:\t" << this->branches << "\n" <<
            "Nodes:\t" << this->nodes << "\n" <<
            "Meshes:\t" << this->meshes <<
            "\n\n";
    }
};

class Mesh {
    std::vector<Component> comps;
public:
    Mesh(Component c) {
        comps.push_back(c);
    }
};

class Node {
    
public:
    std::vector<Component> connected;
    Node(Component comp) {
        connected.push_back(comp);
    }
};