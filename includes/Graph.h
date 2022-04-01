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

using namespace std;

class Graph
{
public:
    /**
     * @brief Construct a new Graph object
     *
     */
    Graph();

    /**
     * @brief Destroy the Graph object
     *
     */
    ~Graph();

    /**
     * @brief Add a new edge to the graph
     *
     * @param start
     * @param dest
     */
    void addEdge(string start, string dest);

    /**
     * @brief BFS Traversal
     *
     * @param start_node
     */
    void BFS(string start_node);

    /**
     * @brief Dijkstra's Algorithm
     *
     * @param start_node
     */
    void Dijkstra(string start_node);

    /**
     * @brief K-nearest neighbor(kNN)
     *
     * @param start_node
     * @param end_node
     * returns nodes closest to start and end nodes
     */
    map<string, string> kNN(string start_node, string end_node);

private:
    int num_vertices;
    map<string, vector<string>> adj_list;
    bool **visited;
};
