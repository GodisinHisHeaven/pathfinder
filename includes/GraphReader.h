//
// Created by Xudong Xiao on 2022-04-06.
//
#pragma once
#include "Graph.h"
#include "fstream"
/**
 * read graph from file
 * TODO: tests
 */
class GraphReader {
public:
    GraphReader(Graph *graph, const std::string &nodeFilePath, const std::string &edgeFilePath);
    void readNodes();
    void readEdges();
private:
    Graph* graph;
    std::string nodeFilePath;
    std::string edgeFilePath;
};
