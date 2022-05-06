//
// Created by Xudong Xiao on 2022-05-04.
//

#include "Graph.h"
#include "../cs225/PNG.h"
#include "vector"

/**
 * draw path on given map
 * @param png
 * @param nodeID
 * @param topLeft longtitude, latitude of topLeft pixel
 * @param rightDown
 * @return
 */
cs225::PNG* Graph::draw(cs225::PNG* png, const std::vector<int>& nodeID, std::pair<double,double> topLeft,
                        std::pair<double,double> rightDown){

    auto width = png->width();
    auto height = png->height();


    auto point = this->entries.at(nodeID[0]);
    auto X = topLeft.first;
    auto Y = rightDown.first;
    auto A = topLeft.second;
    auto B = rightDown.second;

    auto Z = Y-X;
    auto C = A-B;
    auto J = point.X;
    auto K = point.Y;

    auto XPixel = static_cast<int>((Y - J) / Z * width);
    auto YPixel = static_cast<int>((A - K) / (C) * height);

    png->getPixel(XPixel, YPixel) = cs225::HSLAPixel(0,1,0.5);
    return png;
}