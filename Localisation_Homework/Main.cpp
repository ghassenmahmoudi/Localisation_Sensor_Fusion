#define M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "OccupancyGrid.h"
#include "SensorReading.h"
using namespace std;





int main() {
    OccupancyGrid grid;
    SensorReading Sensors;

    Sensors.processSensorData("robot.csv", grid);
    grid.printGrid();

    return 0;
}
