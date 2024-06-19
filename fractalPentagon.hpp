#pragma once
#include <random>
#include <cmath>
#include "Utils/utils.hpp" 

using point = position<int>;

class fractalPentagon
{
private:

    //random number generator
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> corner_dis;
    std::uniform_real_distribution<float> fraction_dis;

    void initRandom();

    point getNextPointByDistance(const point&, const point&);
    point getRandomCorner();
    void initCorners(int);
public:
    std::vector<point> corners;
    std::vector<point> fractalPoints;
    std::pair<point, point> line;
    point currentPoint;
    point secondPoint;
    point oldCorner;
    fractalPentagon(int);
    void iterateFractal();
};

void fractalPentagon::initCorners(int size){
    double angle = M_PI/2 ; 
    double angleStep = 2 * M_PI / 5;
    for (int i = 0; i < 5; i++) {
        int x = size / 2 + size / 2 * cos(angle);
        int y = size / 2 + size / 2 * sin(angle);
        corners.push_back({x, y});
        angle += angleStep;
    }
}

void fractalPentagon::initRandom(){
    gen = std::mt19937(rd());
    corner_dis = std::uniform_int_distribution<int>(0, 4);
    fraction_dis = std::uniform_real_distribution<float>(0.0, 1.0);
}

point fractalPentagon::getNextPointByDistance(const point& a, const point& b){
    //float fraction = fraction_dis(gen);
    auto x_diff = (0.618) * (b.x - a.x);
    auto y_diff = (0.618) * (b.y - a.y);
    return point{a.x + static_cast<int>(x_diff), a.y + static_cast<int>(y_diff)};
}

void fractalPentagon::iterateFractal(){
    secondPoint = getRandomCorner();
    auto nextPoint = getNextPointByDistance(currentPoint, secondPoint);
    
    line = {currentPoint, secondPoint};
    fractalPoints.push_back(nextPoint);
    oldCorner = secondPoint;
    currentPoint = nextPoint;
}

point fractalPentagon::getRandomCorner(){
    int index;
    do {
        index = corner_dis(gen);
    } while (corners[index].x == oldCorner.x && corners[index].y == oldCorner.y);
    return corners[index];
}

fractalPentagon::fractalPentagon(int resolution){
    initCorners(resolution);
    initRandom();
    currentPoint = getRandomCorner();
}

