#include "../catch/catch.hpp"
#include "../includes/Graph.h"
#include "../includes/GraphReader.h"
#include <iostream>

TEST_CASE("GraphReader reads nodes correctly", "[Data Parsing]") {
    Graph* graph =nullptr;
    std::string nodeFilePath = "dataset/NA.cnode";
    std::string edgeFilePath = "dataset/NA.cedge";
    GraphReader graphReader(graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();

    std::ifstream nodesFile(nodeFilePath);
    int ID;
    double X, Y;
    bool statement = true;
    while (nodesFile >> ID >> X >> Y) {
        if(X != graph->getNodeAt(ID).X || Y != graph->getNodeAt(ID).Y) {
            statement = false;
            std::cout << "wrong data at " << ID << std::endl;
            break;
        }
        
    }

    REQUIRE(statement == true);
}

TEST_CASE("GraphReader reads edges correctly", "[Data Parsing]") {
    Graph *graph = nullptr;
    std::string nodeFilePath = "dataset/NA.cnode";
    std::string edgeFilePath = "dataset/NA.cedge";
    GraphReader graphReader(graph, nodeFilePath, edgeFilePath);
    graphReader.readNodes();
    graphReader.readEdges();
    
    std::ifstream edgesFile(edgeFilePath);
    int ID;
    int start, end;
    double dist;
    bool statement = true;
    while (edgesFile >> ID >> start >> end >> dist) {

        for (size_t i = 0; i < graph->getAdjList().at(start).size(); i++) {
            if (graph->getAdjList().at(start).at(i).ID == end && graph->getAdjList().at(start).at(i).dist != dist) {
                statement = false;
                std::cout << "wrong data at " << ID << std::endl;
                break;
            }
        }

    }

    REQUIRE(statement == true);
}