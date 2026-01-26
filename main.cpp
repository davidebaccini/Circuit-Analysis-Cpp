/*

    To run the code use:
    g++ -Wall -Wextra main.cpp .\util\component.cpp .\util\parser.cpp .\util\reader.cpp

    -Wall -Wextra = all end extra warnings
    the util are attached since they need to be passed to the compiler

*/

#include <iostream>
#include "util/reader.hpp"
#include "util/parser.hpp"
#include "util/component.hpp"
#include "components/topology.hpp"
#include <unordered_map>

const char SEPARATOR = ';';

double ohm_current(double V, double R) {
    return V/R;
}

int num_meshes(int b, int n) {
    return b - n + 1;
}

// This function uses the fundamental law of totpology to find the number of meshes
Circuit discover_topology(std::vector<Component> components) {
    int n_branches = components.size();
    int n_nodes = 0;
    int n1, n2;
    // Cycles through the elements and find the number of nodes
    for(Component &x : components) {
        n1 = x.get_n1();
        n2 = x.get_n2();
        if(n1 > n_nodes) {
            n_nodes = n1;
        }
        else if(n2 > n_nodes) {
            n_nodes = n2;
        }
    }
    int n_meshes = num_meshes(n_branches, n_nodes);

    Circuit circuit = Circuit(n_branches, n_nodes, n_meshes);
    return circuit;
}
    std::vector<Component> branches;
    std::unordered_map<int, Node> nodes;
    std::vector<Mesh> meshes;

void makeNodes(std::vector<Component>& comps) {
    for (Component& x : comps) {
        int n = x.get_n1();

        // se il nodo NON esiste, viene creato
        if (nodes.find(n) == nodes.end()) {
            nodes.emplace(n, Node(x));
        }

        // collega il componente
        nodes[n].connected.push_back(x);
    }
}
void makeMeshes(std::vector<Component>& comps, std::unordered_map<int, Node> nodes){
    
}



/*
int kvl(Circuit circuit, std::vector<Component> components) {
    int n_meshes = circuit.get_meshes();

    if(n_meshes = 0) {
        std::cout << "Error in mesh number!";
        return 1;
    }

    int n_components = 0;

    if(n_meshes != 1) {
        for(int m=0; m<n_meshes; m++) {
            for(int c=0; c<n_components; c++) {
                
            }
        }
    }

    

}
*/

int main() {

    // Read the file
    auto lines = readLines("util/netlist.csv");
    //std::cout << "After readLines\n";

    int i=0;
    for(auto& line : lines) {
        std::vector<std::string> tokens = split(line, SEPARATOR);
        branches.push_back(Component(tokens));
        i++;
    }

    std::cout << "Size: " << branches.size();

    Circuit circuit = discover_topology(branches);
    circuit.print();
        
}