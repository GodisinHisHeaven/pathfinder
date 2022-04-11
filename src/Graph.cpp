#include "Graph.h"


using namespace std;

Graph::Node::Node(double x, double y) : X(x), Y(y) {}

void Graph::addNode(double X, double Y) {
    entries.emplace_back(X, Y); // push back and construct object
}

void Graph::addEdge(int startID, int endID, double distance) {
    adjList.at(startID).emplace_back(endID, distance);
}

int Graph::BFS(int startID, int endID) {
    int steps = 0;
    vector<Node> visited;
    queue<Node> q;

    q.push(entries.at(startID));
    visited.push_back(entries.at(startID));

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (current.X == entries.at(endID).X && current.Y == entries.at(endID).Y) {
            return steps;
        }

        for (auto &edge: adjList.at(entries.at(startID).X)) {
            if (find(visited.begin(), visited.end(), entries.at(edge.ID)) == visited.end()) {
                q.push(entries.at(edge.ID));
                visited.push_back(entries.at(edge.ID));
            }
        }
        steps++;
    }
    return -1;
}

std::vector<int> Graph::Dijkstra(int startID, int endID) {

}
