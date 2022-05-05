#include "../catch/catch.hpp"
#include "../includes/Graph.h"
#include "../includes/GraphReader.h"
#include <iostream>

TEST_CASE("BFS works on small dataset", "[BFS]") {
   Graph graph;
    std::string nodeFilePath = "tests/test.cnode";
    std::string edgeFilePath = "tests/test.cedge";
    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

   std::vector<int> path = graph.BFS(0, 4); // throws exception

    REQUIRE(path.size() == 3);
    REQUIRE(path[1] == 2);
    REQUIRE(path[2] == 3);
    REQUIRE(path[3] == 4);
   
}
