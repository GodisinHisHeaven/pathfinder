/**
 *
 * @file Graph.h
 * @author Mingjun Liu (mingjun6)
 * @author Cooper Miller (kcm3)
 * @author
 * @author
 * @brief This file contains the Graph class, and implementation of BFS Traversal,
 *        Dijkstra's Algorithm.
 * @date 2022-03-28
 *
 */

#pragma once

#include <queue>
#include <vector>
#include <iostream>
#include <map>
#include "memory"

/**
 * using adjacency list to store graph.
 */
class Graph {
private:
    struct Node;
    struct Adjacency;
public:
    Graph() = default;

    Graph(const Graph &) = delete;

    /**
     * pre-allocate memories for graph
     * @param numNodes
     */
    Graph(int numNodes) {
        entries.reserve(numNodes);
        adjList.resize(numNodes);
    }

    ~Graph() = default;

    /**
     * add a node to the graph
     * @param X X-coordinate
     * @param Y Y-coordinate
     */
    void addNode(double X, double Y);

    /**
     * add an edge connecting two nodes.
     * @param startID
     * @param endID
     * @param distance
     */
    void addEdge(int startID, int endID, double distance);

    /**
     * @brief Get the Node At given ID
     * 
     * @param ID
     * @return Node 
     */
    Node getNodeAt(int ID);

    /**
     * @brief Return adjList
     * 
     * @param startID 
     * @return std::vector<std::vector<Adjacency> >
     */
    std::vector<std::vector<Adjacency> > getAdjList();

    /**
     * BFS Traversal
     * @param startID
     * @param endID
     * @return
     */
    std::vector<int> BFS(int startID, int endID);

    /**
     * Dijkstra's Algorithm
     * @param startID
     * @param endID
     * @return
     */
    std::vector<int> Dijkstra(int startID, int endID);


    // No need to implement since we have the distance in edge file
    /**
     * get the distance between two adjacent nodes
     * @param startID
     * @param endID
     * @return
     */
//    double getDistance(int startID, int endID);


private:

    struct Node {
        // node id was represented by index in vector
        double X;
        double Y;

        Node(double x, double y);
    };

    struct Adjacency {
        int ID;
        double dist;

        Adjacency(int ID, double dist) : ID(ID), dist(dist) {}
    };

    std::vector<Node> entries;
    std::vector<std::vector<Adjacency>> adjList;
};


