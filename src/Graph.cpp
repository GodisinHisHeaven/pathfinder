#include "Graph.h"
#include <limits>
#include "unordered_map"


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
    class Comparator{
    public:
        bool operator()(std::pair<double,int> a,std::pair<double,int> b) const{
            return a.first < b.first;
        }
    };

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, Comparator> pq;
    std::vector<int> path;
    std::vector<int> dist(entries.size(), std::numeric_limits<int>::max());
    pq.push(std::make_pair(0, startID));
    std::vector<int> visited(entries.size(), false);

    dist.at(startID) = 0;

    std::map<int, int> prev; // map a node to its predecessor

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        if (curr == endID) {
//            path.push_back(curr);
            break;
        }

        for (auto &neighbor: adjList.at(curr)) {
            if (!visited[neighbor.ID] && dist.at(neighbor.ID) > dist.at(curr) + neighbor.dist) {
                dist.at(neighbor.ID) = dist.at(curr) + neighbor.dist;
                pq.push(std::make_pair(dist.at(neighbor.ID), neighbor.ID));
                prev[neighbor.ID] = curr;
            }
        }
        visited[curr] = 1;

    }

//    auto curr = endID;
//    auto currprev = prev[curr];

    for ( auto curr = endID; curr != startID; curr = prev[curr]) {
        path.push_back(curr);
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
