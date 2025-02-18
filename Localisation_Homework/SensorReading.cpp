#include "SensorReading.h"


void SensorReading::processSensorData(const string& filename, OccupancyGrid& grid)
{
    {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream ss(line);
            double timestamp, x, y, angle, sensor1, sensor2, sensor3, sensor4;
            char comma;

            ss >> timestamp >> comma >> x >> comma >> y >> comma >> angle >> comma >> sensor1 >> comma >> sensor2 >> comma >> sensor3 >> comma >> sensor4;

            double distances[4] = {
                sensor1 * OccupancyGrid::SpeedOfSound,
                sensor2 * OccupancyGrid::SpeedOfSound,
                sensor3 * OccupancyGrid::SpeedOfSound,
                sensor4 * OccupancyGrid::SpeedOfSound
            };

            grid.updateGrid(x, y, angle, M_PI / 4, distances[0]);
            grid.updateGrid(x, y, angle, -M_PI / 4, distances[1]);
            grid.updateGrid(x, y, angle, 3 * M_PI / 4, distances[2]);
            grid.updateGrid(x, y, angle, -3 * M_PI / 4, distances[3]);
        }

        file.close();
    }
}
