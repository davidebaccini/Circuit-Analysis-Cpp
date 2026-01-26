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

void makeNodes() {
    for (Component& x : branches) {
        int na = x.get_n1();
        int nb = x.get_n2();
        // se il nodo NON esiste, viene creato
        if (nodes.find(na) == nodes.end()) {
            nodes.emplace(na, Node(x,na));
        } else if( nodes.find(nb) == nodes.end()){
            nodes.emplace(nb, Node(x,nb));
        }

        // collega i componenti
        nodes[na].connected.push_back(x);
        nodes[nb].connected.push_back(x);
    }
}

std::vector<Node> makeMesh(Node obj, Node *current, std::vector<Node> path){
        Node *current = current;
    for(Component &c : current->connected){
        int na = c.get_n1();
        int nb = c.get_n2();
        if(nodes[na].getId() == obj.getId() || nodes[nb].getId() == obj.getId()){
            if(nodes[na].getId() == obj.getId()){
                path.push_back(nodes[na]);
                return path;
            } else{
                path.push_back(nodes[nb]);
                return path;
            }
            //recursive mesh finding algorithm
        }else{
        if(nodes[na].getId() == obj.getId()){
            current = &nodes[nb];
            path.push_back(*current);
        }else{
            current = &nodes[na];
            path.push_back(*current);
        }
        makeMesh(obj, current, path);
        }
    }
    }
void makeMeshes(){

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