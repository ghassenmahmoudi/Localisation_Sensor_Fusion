#pragma once
#define M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class OccupancyGrid {
public:
    static constexpr double SpeedOfSound = 343.0;
    static constexpr double sensorRange = 4.0;
    static constexpr double gridResolution = 0.1;
    static constexpr int gridSize = 250;

    vector<vector<double>> grid;


    OccupancyGrid() : grid(gridSize, vector<double>(gridSize, 0.5)) {}  //0.5 for unknonwn occupancy

    void worldToGrid(double x, double y, int& grid_x, int& grid_y);

    void updateGrid(double current_x, double current_y, double robot_angle, double sensor_angle, double distance);

    void printGrid() const;

private:
    bool isValid(int x, int y) const;
};