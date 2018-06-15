#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "graph/ColorGraph.h"


/**
 * main
 * @return dot-representation of result.
 */
int main() {
    ColorGraph colorGraph;
    std::cout << "enter number of nodes" << std::endl;
    int numNode;
    std::cin >> numNode;

    // init values
    bool te2[numNode][numNode];
    bool **te;
    int val;



    // get all the graph-input
    std::cout << "Your graph has " << numNode << " Nodes." << std::endl;
    std::cout << "Please enter the Connections each node has, set 1 for a connection, 0 for none." << std::endl;
    std::cout << "Please seperate your input with a blank." << std::endl;
    std::string nodes;
    for (int i = 0; i < numNode; i++) {
        nodes += std::to_string(i) + " ";
    }
    std::cout << nodes << std::endl;
    te = (bool **) malloc(numNode * sizeof(bool *));

    // instanciate the array
    for (int row = 0; row < numNode; row++) {
        te[row] = (bool *) malloc(numNode * sizeof(bool));
    }

    int temEdge = numNode;
    for (int j = 0; j < numNode; j++) {
        bool temparray[numNode];
        for (int i = 0; i < numNode; i++) {
            std::cin >> val;
            if (val != 0 and val != 1) {
                std::cout << "You entered a invalid number, please start over." << std::endl;
                return true;
            } else {
                te[j][i] = val;
            }
        }
    }

    std::cout << "Please enter the number of colors." << std::endl;

    int numColors;
    std::cin >> numColors;

    colorGraph.colorGraph(numNode, numColors, te);

}