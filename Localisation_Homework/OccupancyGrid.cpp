#include "OccupancyGrid.h"


void OccupancyGrid::worldToGrid(double x, double y, int& grid_x, int& grid_y)
{
    grid_x = int((x / gridResolution) + (gridSize / 2));
    grid_y = int((y / gridResolution) + (gridSize / 2));
}

void OccupancyGrid::updateGrid(double current_x, double current_y, double robot_angle, double sensor_angle, double distance)
{
    if (distance == 0 || distance > sensorRange) {
        for (double r = 0; r < sensorRange; r += gridResolution) {
            double x = current_x + r * cos(robot_angle + sensor_angle);
            double y = current_y + r * sin(robot_angle + sensor_angle);
            int grid_x, grid_y;
            worldToGrid(x, y, grid_x, grid_y);
            if (isValid(grid_x, grid_y)) {
                grid[grid_x][grid_y] = max(0.0, grid[grid_x][grid_y] - 0.1);// -0.1 for decreasing the probability of existance of an obstacle
            }
        }
    }
    else {
        for (double r = 0; r < distance; r += gridResolution) {
            double x = current_x + r * cos(robot_angle + sensor_angle);
            double y = current_y + r * sin(robot_angle + sensor_angle);
            int grid_x, grid_y;
            worldToGrid(x, y, grid_x, grid_y);
            if (isValid(grid_x, grid_y)) {
                grid[grid_x][grid_y] = max(0.0, grid[grid_x][grid_y] - 0.1);
            }
        }
        double x = current_x + distance * cos(robot_angle + sensor_angle);
        double y = current_y + distance * sin(robot_angle + sensor_angle);
        int grid_x, grid_y;
        worldToGrid(x, y, grid_x, grid_y);
        if (isValid(grid_x, grid_y)) {
            grid[grid_x][grid_y] = min(1.0, grid[grid_x][grid_y] + 0.4);// increasing the probability of existance of an obstacle and assuming the sensor is accurate
        }
    }
}

void OccupancyGrid::printGrid() const
{
    for (const auto& row : grid) {
        for (double cell : row) {
            cout << (cell > 0.5 ? "O" : "x");
        }
        cout << endl;
    }
}

bool OccupancyGrid::isValid(int x, int y) const
{
    return x >= 0 && x < gridSize && y >= 0 && y < gridSize;
}
