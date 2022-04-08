#include "Graph.h"


Graph::Node::Node(double x, double y) : X(x), Y(y) {}

void Graph::addNode(double X, double Y) {
    entries.emplace_back(X,Y); // push back and construct object
}

void Graph::addEdge(int startID, int endID, double distance) {
    adjList.at(startID).emplace_back(endID, distance);
}

std::vector<int> Graph::BFS(int startID, int endID) {
    std::vector<int> path;
    std::vector<bool> visited(entries.size(), false);
    std::queue<int> q;
    q.push(startID);
    visited[startID] = true;


}
