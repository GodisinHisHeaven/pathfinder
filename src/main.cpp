#include "Graph.h"
#include "GraphReader.h"
#include "iostream"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Missing argument:\nUsage: exec [start_node_id] [end_node_id]";
        return -1;
    }
    int arg0 = std::stoi(argv[1], nullptr, 10);
    int arg1 = std::stoi(argv[2], nullptr, 10);

    if (arg0 < 0 || arg1 > 175812) {
        std::cout << "Node ID should be in range [1, 175812]\n";
        return -1;
    }

    auto *graph = new Graph();
    GraphReader gr(graph, "dataset/NA.cnode", "dataset/NA.cedge");
    gr.readNodes();
    gr.readEdges();

    auto *png = new cs225::PNG(1000, 1000);
    png = graph->drawBaseMap(png);
    std::vector<int> path;
    int start = arg0; // start node, change it as you like
    int end = arg1; // end node, change it as you like, max node id is 175812!
    path = graph->Dijkstra(start, end);

    graph->drawPath(png, path);
    std::cout<<"PNG saved to output/result.png\n";
    png->writeToFile("output/result.png");
    return 0;
}