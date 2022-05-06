#include "Graph.cpp"
#include "GraphReader.cpp"
#include "Visualize.cpp"

int main() {
    auto *graph = new Graph();
    GraphReader gr(graph, "dataset/NA.cnode", "dataset/NA.cedge");
    gr.readNodes();

    auto *png = new cs225::PNG();
    png->readFromFile("dataset/base.png");

    std::vector<int> path;
    int start = 0; // start node, change it as you like
    int end = 20423; // end node, change it as you like, max node id is 175812!
    path = graph->Dijkstra(start, end);

    for (int i: path) {
        auto node = graph->getNodeAt(i);
        auto x = node.X;
        auto y = node.Y;
        png->getPixel((x / 10), 1000 - (y / 10)) = cs225::HSLAPixel(0, 1, 0);
    }

    png->writeToFile("output/result.png");
    return 0;
}