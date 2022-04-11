#include "Graph.h"


Graph::Node::Node(double x, double y) : X(x), Y(y) {}

void Graph::addNode(double X, double Y) {
    entries.emplace_back(X, Y); // push back and construct object
}

void Graph::addEdge(int startID, int endID, double distance) {
    adjList.at(startID).emplace_back(endID, distance);
}

// Version 1, only calculate the distance between two nodes
std::vector<Graph::Node> Graph::BFS(int startID, int endID) {
    // TODO: return the shortest path from startID to endID not only the distance
    std::vector<Node> path;
    std::vector<Node> visited;
    std::queue<Node> q;

    q.push(entries.at(startID));
    visited.push_back(entries.at(startID));

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (current.X == entries.at(endID).X && current.Y == entries.at(endID).Y) {
            path.push_back(current);
            break;
        }

        for (auto &neighbor: adjList.at(current.X)) {
            if (std::find(visited.begin(), visited.end(), neighbor) == visited.end()) {
                Node next = entries.at(neighbor.ID);
                q.push(next);
                visited.push_back(next);
            }
        }

    }

    return path;

}

std::vector<int> Graph::Dijkstra(int startID, int endID) {

}
