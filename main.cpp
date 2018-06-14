#include<stdio.h>
#include <iostream>


/* A utility function to print solution */
void printit(int *color, int size, bool **graph){
    std::string* pStr = new std::string[8] { "red", "blue", "yellow", "green", "grey", "chocolate", "cyan", "orange" };
    std::cout << "graph g{" << std::endl;
    for (int i = 0; i < size; i++){

        for (int j = 0; j < size; j++) {
            if(j>=i && graph[i][j] && i!=j)
            std::cout<< i << " -- " << j << " " << std::endl;
        }

        std::cout <<  i << " [style=filled, fillcolor=\"" << pStr[*(color + i)] << "\"]" << "\n" << std::endl;


    }

    std::cout << "}" << std::endl;

    // digraph G { 1[label="Node color" style=filled color="dodgerblue" fillcolor="lightyellow" ]; }
}


bool checkNeighbourColors (int edge, bool **graph, int *color, int col, int size)
{
    for (int i = 0; i < size; i++) {
//        std::cout << graph[edge][i] << "  this is graph" << std::endl;
//        std::cout << *(color + 0) << "  this is color from edge1" << std::endl;
//        std::cout << *(color + 1) << "  this is color from edge2" << std::endl;
       // std::cout << *(color + 2) << "  this is color from edge3" << std::endl;
       // std::cout << *(color + 3) << "  this is color from edge4" << std::endl;

        if (graph[i][edge] && *(color + i) > 0 && col == *(color + i))
            return false;
    }
    return true;
}

bool recColors(bool **graph, int numCol, int *color, int edge, int size)
{
    // (te, numColors, *colors, 0, numColors);
    if (edge == size)
        return true;
    // iterate over all possible colors
    for (int col = 1; col <= numCol; col++)
    {
        // check if edge can be assigned this color
        if (checkNeighbourColors(edge, graph, color, col, size))
        {
            *(color+edge) = col;
            if (recColors (graph, numCol, color, edge+1, size) == true) {


                //printit(color, size);
                return true;
            }
            *(color+edge) = 0;
        }
    }

    //std::cout << "Failed." << std::endl;
    return false;

}

int main()
{


    std::cout<<"enter number of edges"<<std::endl;
    int numEdge;
    std::cin>>numEdge;


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

    /*
     * todo: write tests
     */
}