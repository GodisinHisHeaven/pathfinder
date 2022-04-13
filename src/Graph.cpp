#include "Graph.h"
#include <cmath>

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

//double Graph::getDistance(int startID, int endID) {
//    // return the distance between two nodes
//    // calculate the distance between two nodes by Haversine formula
//
//    double distance = 0;
//
//    double lat1 = entries.at(startID).X;
//    double lon1 = entries.at(startID).Y;
//    double lat2 = entries.at(endID).X;
//    double lon2 = entries.at(endID).Y;
//
//    double dLat = (lat2 - lat1) * (M_PI / 180);
//    double dLon = (lon2 - lon1) * (M_PI / 180);
//    double a = sin(dLat / 2) * sin(dLat / 2) +
//               cos(lat1 * (M_PI / 180)) * cos(lat2 * (M_PI / 180)) * sin(dLon / 2) * sin(dLon / 2);
//    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
//    distance = 6371 * c;
//
//    return distance;
//}
