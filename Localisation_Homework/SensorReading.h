#include <fstream>
#include <sstream>
#include <string>
#include "OccupancyGrid.h"


class SensorReading {
public:
    void processSensorData(const string& filename, OccupancyGrid& grid);
};