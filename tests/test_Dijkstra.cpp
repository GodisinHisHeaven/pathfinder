#include "../catch/catch.hpp"
#include "../includes/Graph.h"
#include "../includes/GraphReader.h"
#include <iostream>

TEST_CASE("Dijkstra works on simple route", "[line]") {
    Graph graph;
    std::string nodeFilePath = "tests/Dijkstra.cnode";
    std::string edgeFilePath = "tests/Dijkstra.cedge";
    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

    std::vector<int> path = graph.Dijkstra(7,8);

    REQUIRE(path.size() == 2);
    REQUIRE(path[0] == 8);
    REQUIRE(path[1] == 8);


}

TEST_CASE("Dijkstra works on cyclic route 1", "[cycle]") {
    Graph graph;
    std::string nodeFilePath = "tests/Dijkstra.cnode";
    std::string edgeFilePath = "tests/Dijkstra.cedge";
    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

    std::vector<int> path = graph.Dijkstra(1,5);

    REQUIRE(path.size() == 5);
    REQUIRE(path[0] == 2);
    REQUIRE(path[1] == 3);
    REQUIRE(path[2] == 4);
    REQUIRE(path[3] == 5);
    REQUIRE(path[4] == 5);

}

TEST_CASE("Dijkstra works on cyclic route 2", "[cycle]") {
    Graph graph;
    std::string nodeFilePath = "tests/Dijkstra.cnode";
    std::string edgeFilePath = "tests/Dijkstra.cedge";
    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

    std::vector<int> path = graph.Dijkstra(2,6);

    REQUIRE(path.size() == 4);
    REQUIRE(path[0] == 4);
    REQUIRE(path[1] == 5);
    REQUIRE(path[2] == 6);
    REQUIRE(path[3] == 6);

}

TEST_CASE("Dijkstra works on cyclic route 3", "[cycle]") {
    Graph graph;
    std::string nodeFilePath = "tests/Dijkstra.cnode";
    std::string edgeFilePath = "tests/Dijkstra.cedge";
    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

    std::vector<int> path = graph.Dijkstra(1,6);

    REQUIRE(path.size() == 6);
    REQUIRE(path[0] == 2);
    REQUIRE(path[1] == 3);
    REQUIRE(path[2] == 4);
    REQUIRE(path[3] == 5);
    REQUIRE(path[4] == 6);
    REQUIRE(path[5] == 6);

}

TEST_CASE("Dijkstra works on dsiconnected route ", "[disconnected]") {
    Graph graph;
    std::string nodeFilePath = "tests/Dijkstra.cnode";
    std::string edgeFilePath = "tests/Dijkstra.cedge";
    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

    std::vector<int> path = graph.Dijkstra(1,7);

    REQUIRE(path.size() == 6);
    REQUIRE(path[0] == 2);
    REQUIRE(path[1] == 3);
    REQUIRE(path[2] == 4);
    REQUIRE(path[3] == 5);
    REQUIRE(path[4] == 6);
    REQUIRE(path[5] != 6);

}

