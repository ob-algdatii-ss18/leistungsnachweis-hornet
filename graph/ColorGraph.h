#ifndef LEISTUNGSNACHWEIS_HORNET_GRAPH_COLOR_H
#define LEISTUNGSNACHWEIS_HORNET_GRAPH_COLOR_H


class ColorGraph {
public:

    //TODO: DOC
    bool colorGraph(int numNode, int numColors, bool **graph);

private:
    /**
    * A utility function to write the solution in dot-syntax to a file "output.txt"
    * @param color final color-array.
    * @param size  size of graph and color-array
    * @param graph graph.
    */
    void printIt(int *color, int size, bool **graph, bool toPicture);

    /**
    * ckeck all neighbours of a given edge.
    * @param edge current Edge
    * @param graph complete graph
    * @param color current color-array
    * @param col color of current edge
    * @param size size of arrays.
    * @return true if color is possible, else false.
    */
    bool checkNeighbourColors(int edge, bool **graph, int *color, int col, int size);


    /**
    *
    * @param graph complete graph
    * @param numCol number of colors that may be used
    * @param color collor-array, init 0 on start.
    * @param edge current edge, init 0
    * @param size size of arrays.
    * @return true if the graph can be colored given the number of colors, else false
    */
    bool recColors(bool **graph, int numCol, int *color, int edge, int size);

};


#endif //LEISTUNGSNACHWEIS_HORNET_GRAPH_COLOR_H
