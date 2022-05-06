//
// Created by Xudong Xiao on 2022-04-06.
//

#include "../includes/GraphReader.h"


GraphReader::GraphReader(Graph *graph, const std::string &nodeFilePath, const std::string &edgeFilePath) : graph(graph),
                                                                                                           nodeFilePath(
                                                                                                                   nodeFilePath),
                                                                                                           edgeFilePath(
                                                                                                                   edgeFilePath) {}

void GraphReader::readNodes() {
    std::ifstream nodesFile(nodeFilePath);
//    nodesFile.open(nodeFilePath);
    int ID;
    double X, Y;
    while (nodesFile >> ID >> X >> Y) {
        graph->addNode(X, Y);
    }
}

void GraphReader::readEdges() {
    std::ifstream edgesFile(edgeFilePath);
    int ID;
    int start, end;
    double dist;
    while (edgesFile >> ID >> start >> end >> dist) {
        graph->addEdge(start, end, dist);
    }

}
