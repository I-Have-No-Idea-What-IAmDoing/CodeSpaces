#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "vector"
#include "functions.h"

using namespace std;

// Stores each driver's Name, Car Name, and Car Number
vector<vector<string>> driversInfo;
// Stores each driver's Netherlands Time, Italy Time and Total Time
vector<vector<double>> driverTimes;

int main() {
    std::string headerLine;

    // IMPORTANT NOTE: Notice using "../" to prefix the file name. You will need that to access files properly in CLION.
    std::ifstream netherlands_file("../Netherlands.csv");
    getline(netherlands_file, headerLine);

    vector<double> netherlandsTimes;
    driversInfo = readRacingCSV(netherlands_file, netherlandsTimes);
    netherlands_file.close();

    std::ifstream italy_file("../Italy.csv");
    getline(italy_file, headerLine);

    vector<double> ItalyTimes;
    readRacingCSV(italy_file, ItalyTimes);
    italy_file.close();

    // Needed to format the two temporary variables to their final destination
    driverTimes = combineTimeVectors(ItalyTimes, netherlandsTimes);

    // Find and print the winners
    std::vector<int> winners = findWinners(driverTimes);
    cout << std::setprecision(3) << std::fixed << "Announcing the Winners!\n"
            "Netherlands:  " << driversInfo.at(winners.at(0)).at(0)
                             << " with a time of " << driverTimes.at(winners.at(0)).at(0) << " minutes\n"

            "Italy:        " << driversInfo.at(winners.at(1)).at(0)
                             << " with a time of " << driverTimes.at(winners.at(0)).at(1) << " minutes\n"

            "Total:        " << driversInfo.at(winners.at(2)).at(0)
                             << " with a time of " << driverTimes.at(winners.at(0)).at(2) << " minutes\n" << endl;

    // Now create the output file
    ofstream stream("results.csv");
    stream << "Driver,Car,Car#,Netherlands,Italy,Total\n";
    int index = 0;
    for (vector<string> currentDriver : driversInfo) {
        stream << currentDriver.at(0) << "," << currentDriver.at(1) << "," << currentDriver.at(2) << ","
        << driverTimes.at(index).at(0) << "," << driverTimes.at(index).at(1) << ","
        << driverTimes.at(index).at(2) << endl;
        index++;
    }
    
    stream.close();
    return 0;
}
