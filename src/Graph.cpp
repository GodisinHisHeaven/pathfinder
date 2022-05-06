#include "Graph.h"
#include <limits>


Graph::Node::Node(double x, double y) : X(x), Y(y) {}

void Graph::addNode(double X, double Y) {
    entries.emplace_back(X, Y); // push back and construct object
    adjList.push_back({});
}

void Graph::addEdge(int startID, int endID, double distance) {
    adjList.at(startID).emplace_back(endID, distance);
}

Graph::Node Graph::getNodeAt(int ID) {
    return entries.at(ID);
}

std::vector<std::vector<Graph::Adjacency>> Graph::getAdjList() {
    return adjList;
}

std::vector<int> Graph::BFS(int startID, int endID) {
    std::vector<int> path;
    std::vector<bool> visited(entries.size(), false);
    std::queue<int> q;
    q.push(startID);
    visited[startID] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == endID) {
            path.push_back(curr);
            break;
        }

        for (auto &neighbor: adjList.at(curr)) {
            if (!visited[neighbor.ID]) {
                visited[neighbor.ID] = true;
                q.push(neighbor.ID);
            }
        }

        path.push_back(q.front());
    }

    return path;
}

std::vector<int> Graph::Dijkstra(int startID, int endID) {
    std::priority_queue<std::pair<double, int>> pq;
    std::vector<int> path;
    std::vector<int> dist(entries.size(), std::numeric_limits<int>::max());
    pq.push(std::make_pair(adjList.at(startID).at(0).dist, startID));

    dist.at(startID) = 0;

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        if (curr == endID) {
            path.push_back(curr);
            break;
        }

        //use priority queue to find the closest node
        for (auto &neighbor: adjList.at(curr)) {
            if (dist[neighbor.ID] > dist[curr] + neighbor.dist)
            {
                dist[neighbor.ID] = dist[curr] + neighbor.dist;
                pq.push(std::make_pair(neighbor.dist, neighbor.ID));
            }
        }
        path.push_back(pq.top().second);
    }

    return path;
}

// double Graph::getDistance(int startID, int endID) {
//     // return the distance between two nodes
//     // calculate the distance between two nodes by Haversine formula
//
//     double distance = 0;
//
//     double lat1 = entries.at(startID).X;
//     double lon1 = entries.at(startID).Y;
//     double lat2 = entries.at(endID).X;
//     double lon2 = entries.at(endID).Y;
//
//     double dLat = (lat2 - lat1) * (M_PI / 180);
//     double dLon = (lon2 - lon1) * (M_PI / 180);
//     double a = sin(dLat / 2) * sin(dLat / 2) +
//                cos(lat1 * (M_PI / 180)) * cos(lat2 * (M_PI / 180)) * sin(dLon / 2) * sin(dLon / 2);
//     double c = 2 * atan2(sqrt(a), sqrt(1 - a));
//     distance = 6371 * c;
//
//     return distance;
// }
