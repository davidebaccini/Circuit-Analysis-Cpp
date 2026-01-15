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

class Meshes {
    int number;

public:
    Meshes(int n) {
        this->number = n;
    }


};

class Node {
    // nel constructor di node dovremmo aggiungere il node alla map nodes
    int id;
    std::vector<int> connected_ids;
public:
    Node(int id, Component comp) {
        this->id = id;
        connected_ids.push_back(comp.getId());
    }

    int getId() {
        return id;
    }
};