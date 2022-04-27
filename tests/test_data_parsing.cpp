#include "../catch/catch.hpp"
#include "../includes/Graph.h"
#include "../includes/GraphReader.h"
#include <iostream>

TEST_CASE("addNode works", "[Basic Function]") {
    Graph graph;

    graph.addNode(0, 0);
    graph.addNode(1, 1);
    graph.addNode(2, 3);

    REQUIRE((graph.getNodeAt(0).X == 0 && graph.getNodeAt(0).Y == 0));
    REQUIRE((graph.getNodeAt(1).X == 1 && graph.getNodeAt(1).Y == 1));
    REQUIRE((graph.getNodeAt(2).X == 2 && graph.getNodeAt(2).Y == 3));
}

TEST_CASE("GraphReader reads small dataset correctly", "[Data Parsing]") {
    Graph graph;
    std::string nodeFilePath = "tests/test.cnode";
    std::string edgeFilePath = "tests/test.cedge";
    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

    REQUIRE((graph.getNodeAt(0).X == 0 && graph.getNodeAt(0).Y == 0));
    REQUIRE((graph.getNodeAt(1).X == 1 && graph.getNodeAt(1).Y == 1));
    REQUIRE((graph.getNodeAt(2).X == 2 && graph.getNodeAt(2).Y == 3));
    REQUIRE((graph.getNodeAt(3).X == 4 && graph.getNodeAt(3).Y == 2));
    REQUIRE((graph.getNodeAt(4).X == 5 && graph.getNodeAt(4).Y == 0));

    REQUIRE(graph.getAdjList().at(0).size() == 2);
    REQUIRE(graph.getAdjList().at(2).size() == 1);
    REQUIRE(graph.getAdjList().at(3).size() == 1);
}


TEST_CASE("GraphReader reads nodes correctly", "[Data Parsing]") {
    Graph graph;
    std::string nodeFilePath = "dataset/NA.cnode";
    std::string edgeFilePath = "dataset/NA.cedge";
    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

    std::ifstream nodesFile(nodeFilePath);
    int ID;
    double X, Y;
    bool statement = true;
    while (nodesFile >> ID >> X >> Y) {
        if (X != graph.getNodeAt(ID).X || Y != graph.getNodeAt(ID).Y) {
            statement = false;
            std::cout << "wrong data at " << ID << std::endl;
            break;
        }

    }

    REQUIRE(statement == true);
}

//TEST_CASE("GraphReader reads edges correctly", "[Data Parsing]") {
//    Graph graph;
//    std::string nodeFilePath = "dataset/NA.cnode";
//    std::string edgeFilePath = "dataset/NA.cedge";
//    GraphReader graphReader(&graph, nodeFilePath, edgeFilePath);
//    graphReader.readNodes();
//    graphReader.readEdges();
//
//    std::ifstream edgesFile(edgeFilePath);
//    int ID;
//    int start, end;
//    double dist;
//    bool statement = true;
//    while (edgesFile >> ID >> start >> end >> dist) {
//
//        for (size_t i = 0; i < graph.getAdjList().at(start).size(); i++) {
//            if (graph.getAdjList().at(start).at(i).ID == end && graph.getAdjList().at(start).at(i).dist != dist) {
//                statement = false;
//                std::cout << "wrong data at " << ID << std::endl;
//                break;
//            }
//        }
//
//    }
//
//    REQUIRE(statement == true);
//}