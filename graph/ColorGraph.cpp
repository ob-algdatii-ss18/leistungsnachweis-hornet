#include "ColorGraph.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>


void ColorGraph::printIt(int *color, int size, bool **graph, bool toPicture) {
    // init a few colors.
    std::string *pStr = new std::string[8]{"red", "blue", "yellow", "green", "grey", "chocolate", "cyan", "orange"};
    // init the writer
    std::ofstream out("output.dot");

    out << "graph g{" << std::endl;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {
            if (j >= i && graph[i][j] && i != j)
                out << i << " -- " << j << " " << std::endl;
        }

        out << i << " [style=filled, fillcolor=\"" << pStr[*(color + i)] << "\"]" << "\n" << std::endl;
    }

    out << "}" << std::endl;
    out.close();

    if (toPicture) {
        std::system("dot -Tpng output.dot -o out.png");
        //std::system("feh out.png");
    }


}


bool ColorGraph::checkNeighbourColors(int edge, bool **graph, int *color, int col, int size) {
    for (int i = 0; i < size; i++) {
        if (graph[i][edge] && *(color + i) > 0 && col == *(color + i))
            return false;
    }
    return true;
}

bool ColorGraph::recColors(bool **graph, int numCol, int *color, int edge, int size) {
    if (edge == size)
        return true;
    for (int col = 1; col <= numCol; col++) {
        if (checkNeighbourColors(edge, graph, color, col, size)) {
            *(color + edge) = col;
            if (recColors(graph, numCol, color, edge + 1, size)) {
                return true;
            }
            *(color + edge) = 0;
        }
    }
    return false;
}


bool ColorGraph::colorGraph(int numNode, int numColors, bool **graph) {
    // call the function that does the coloring.
    // initialize the color-array, one color for each
    int colors[numNode];
    // all color-vaules are initialized to 0.
    for (int i = 0; i < numColors; i++)
        colors[i] = 0;
    // call with edge 0 as starting point.
    bool tmp = recColors(graph, numColors, colors, 0, numNode);
    //color(numColors, te, numNode);
    if (tmp == 1) {
        printIt(colors, numNode, graph, true);
        return true;
    } else {
        std::cout << "graph g{" << std::endl;
        std::cout << "Failed [style=filled, fillcolor=\"red\"]" << std::endl;
        std::cout << "}" << std::endl;
        return false;
    }
}