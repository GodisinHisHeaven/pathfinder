//
// Created by Xudong Xiao on 2022-05-04.
//

#include "Graph.h"
#include "../cs225/PNG.h"
#include "vector"

/**
 * drawBaseMap path on given map
 * @param png initialized png, 1000 * 1000
 * @return png base map
 */
cs225::PNG * Graph::drawBaseMap(cs225::PNG *png) {

    for (size_t i = 0; i < 175812; ++i) {
        auto node = this->getNodeAt(i);
        auto x = node.X;
        auto y = node.Y;
        png->getPixel((x/10),1000-(y/10)) = cs225::HSLAPixel(0,1,1);
    }
    png->writeToFile("dataset/base.png");
    return png;
}

cs225::PNG * Graph::drawPath(cs225::PNG *png, const std::vector<int> &nodeID) {

    for (auto &&index: nodeID) {
        auto x = getNodeAt(index).X;
        auto y = getNodeAt(index).Y;
        png->getPixel((x/10),1000-(y/10)) = cs225::HSLAPixel(0,1,0.5);
    }
    png->writeToFile("dataset/path.png");
    return png;
}