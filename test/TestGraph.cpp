#include "gtest/gtest.h"
#include "../graph/ColorGraph.h"

TEST(graphColorTest, fourNodesFourColorsValidTest){
    ColorGraph colorGraph;
    int numNode = 4;
    int numColors = 4;
    bool **graph = (bool **) malloc(numNode * sizeof(bool *));
    int array[numNode][numNode] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    for(int i = 0; i < numNode; i++){
        graph[i] = (bool *) malloc(numNode * sizeof(bool));
        for(int j = 0; j < numNode; j++){
            graph[i][j] = array[i][j];
        }
    }
    EXPECT_TRUE(colorGraph.colorGraph(numNode, numColors, graph));
}
