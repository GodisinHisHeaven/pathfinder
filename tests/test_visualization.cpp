//
// Created by Xudong Xiao on 2022-05-05.
//
#include "../catch/catch.hpp"
#include "../includes/Graph.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "../includes/GraphReader.h"
#include <iostream>

//cs225::PNG* draw(cs225::PNG* png, const std::vector<int>& nodeID, std::pair<double,double> topLeft,
//                        std::pair<double,double> rightDown){
//    (void) nodeID;
//    auto width = png->width();
//    auto height = png->height();
//
//
//
//    auto X = topLeft.first;
//    auto Y = rightDown.first;
//    auto A = topLeft.second;
//    auto B = rightDown.second;
//
//    auto Z = Y-X;
//    auto C = A-B;
//    auto J = 41.88380435822893;
//    auto K = -87.64138428241066;
//
//    auto XPixel = static_cast<int>((Y - J) / Z * width);
//    auto YPixel = static_cast<int>((A - K) / (C) * height);
//
//    png->getPixel(XPixel, YPixel) = cs225::HSLAPixel(0,1,0.5);
//    return png;
//}

//
//TEST_CASE("Visualization", "[vis]") {
//    cs225::PNG* png = new cs225::PNG();
//    png->readFromFile("dataset/test.png");
//    std::vector<int> v;
//
//    draw(png, v,std::make_pair(42.5035257373772, -89.02783333432652) ,std::make_pair(39.77496849762371, -86.16240757768885));
//    png->writeToFile("dataset/res.png");
//}


TEST_CASE("Visualization", "[vis]") {
    cs225::PNG *png = new cs225::PNG(1000, 1000);
    Graph *graph = new Graph();
    GraphReader gr(graph, "dataset/NA.cnode", "dataset/NA.cedge");
    gr.readNodes();
    for (size_t i = 0; i < 175812; ++i) {
        auto node = graph->getNodeAt(i);
        auto x = node.X;
        auto y = node.Y;
        png->getPixel((x / 10), 1000 - (y / 10)) = cs225::HSLAPixel(0, 1, 0);
    }
    png->writeToFile("dataset/base.png");
    delete png;
    delete graph;
}

TEST_CASE("Path Visualization", "[path]") {
    cs225::PNG *png = new cs225::PNG(1000, 1000);
    png->readFromFile("dataset/base.png");
    Graph *graph = new Graph();
    GraphReader gr(graph, "dataset/NA.cnode", "dataset/NA.cedge");
    gr.readNodes();
    std::vector<int> v;
    v = graph->BFS(500, 114514);
    graph->drawPath(png, v);
    png->writeToFile("dataset/path.png");
}
