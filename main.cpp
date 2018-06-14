#include<stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>


/* A utility function to write the solution in dot-syntax to a file "output.txt".*/
/**
 * A utility function to write the solution in dot-syntax to a file "output.txt"
 * @param color final color-array.
 * @param size  size of graph and color-array
 * @param graph graph.
 */
void printit(int *color, int size, bool **graph){
    // init a few colors.
    std::string* pStr = new std::string[8] { "red", "blue", "yellow", "green", "grey", "chocolate", "cyan", "orange" };
    // init the writer
    std::ofstream out("output.dot");

    out << "graph g{" << std::endl;

    for (int i = 0; i < size; i++){

        for (int j = 0; j < size; j++) {
            if(j>=i && graph[i][j] && i!=j)
            out<< i << " -- " << j << " " << std::endl;
        }

        out <<  i << " [style=filled, fillcolor=\"" << pStr[*(color + i)] << "\"]" << "\n" << std::endl;
    }

    out << "}" << std::endl;
    out.close();

    std::system("dot -Tpng output.dot -o out.png");
    std::system("feh out.png");



}


/**
 * ckeck all neighbours of a given edge.
 * @param edge current Edge
 * @param graph complete graph
 * @param color current color-array
 * @param col color of current edge
 * @param size size of arrays.
 * @return true if color is possible, else false.
 */
bool checkNeighbourColors (int edge, bool **graph, int *color, int col, int size)
{
    for (int i = 0; i < size; i++) {
        if (graph[i][edge] && *(color + i) > 0 && col == *(color + i))
            return false;
    }
    return true;
}

/**
 *
 * @param graph complete graph
 * @param numCol number of colors that may be used
 * @param color collor-array, init 0 on start.
 * @param edge current edge, init 0
 * @param size size of arrays.
 * @return true if the graph can be colored given the number of colors, else false
 */
bool recColors(bool **graph, int numCol, int *color, int edge, int size)
{
    if (edge == size)
        return true;
    for (int col = 1; col <= numCol; col++)
    {
        if (checkNeighbourColors(edge, graph, color, col, size))
        {
            *(color+edge) = col;
            if (recColors (graph, numCol, color, edge+1, size) == true) {
                return true;
            }
            *(color+edge) = 0;
        }
    }
    return false;
}


/**
 * main
 * @return dot-representation of result.
 */
int main()
{


    std::cout<<"enter number of edges"<<std::endl;
    int numEdge;
    std::cin>>numEdge;

    // init values
    bool te2[numEdge][numEdge];
    bool **te;
    int val;



    // get all the graph-input
    std::cout<<"Your graph has " << numEdge << " Edges." << std::endl;
    std::cout<<"Please enter the Connections each edge has, set 1 for a connection, 0 for none." << std::endl;
    std::cout<<"Please seperate your input with a blank." << std::endl;
    std::cout<<"0 1 2 3 4" << std::endl;
    te = (bool **) malloc(numEdge * sizeof(bool*));

    // instanciate the array
    for (int row = 0; row<numEdge; row++) {
        te[row] = (bool *) malloc(numEdge * sizeof(bool));
    }

    int temEdge = numEdge;
    for(int j=0;j<numEdge;j++){
        bool temparray[numEdge];
        for(int i=0; i<numEdge; i++) {
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
    std::cin>>numColors;

    // call the function that does the coloring.
    // initialize the color-array, one color for each
    int colors[numEdge];
    // all color-vaules are initialized to 0.
    for (int i = 0; i < numColors; i++)
        colors[i] = 0;
    // call with edge 0 as starting point.
    bool tmp = recColors(te, numColors, colors, 0, numEdge);
    //color(numColors, te, numEdge);
    if (tmp == 1)
        printit(colors, numEdge, te);
    else {
        std::cout << "graph g{" << std::endl;
        std::cout << "Failed [style=filled, fillcolor=\"red\"]" << std::endl;
        std::cout << "}" << std::endl;
    }
}