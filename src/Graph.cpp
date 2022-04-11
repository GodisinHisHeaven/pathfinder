#include "Graph.h"


using namespace std;

Graph::Node::Node(double x, double y) : X(x), Y(y) {}

void Graph::addNode(double X, double Y) {
    entries.emplace_back(X, Y); // push back and construct object
}

void Graph::addEdge(int startID, int endID, double distance) {
    adjList.at(startID).emplace_back(endID, distance);
}

std::vector<int> Graph::BFS(int startID, int endID) {
    vector<int> path;
    vector<Adjacency> visited;
    queue<Adjacency> q;

    q.push(Adjacency(startID, 0));
    visited.emplace_back(startID, 0);

    while (!q.empty()) {
        Adjacency curr = q.front();
        q.pop();

        if (curr.ID == endID) {
            path.push_back(curr.ID);
            return path;
        }

        for (auto &adj : adjList[curr.ID]) {
            if (find(visited.begin(), visited.end(), adj) == visited.end()) {
                visited.emplace_back(adj.ID, adj.dist + curr.dist);
                q.push(Adjacency(adj.ID, adj.dist + curr.dist));
            }
        }

    }
    return path;
}

std::vector<int> Graph::Dijkstra(int startID, int endID) {

}
