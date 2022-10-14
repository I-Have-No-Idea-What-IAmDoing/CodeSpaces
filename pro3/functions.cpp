#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "vector"
#include "functions.h"

using namespace std;

// Reads a properly formatted CSV file for F1 Racing
std::vector<std::vector<std::string>> readRacingCSV(ifstream &csvFile, vector<double> &driveTime) {
    std::vector<std::vector<std::string>> returnValue;
    while (csvFile.good()) {
        std::string currentLine;
        getline(csvFile, currentLine);

        // Remove any blank lines
        if (currentLine.empty()) continue;

        string currentTerm;
        vector<string> currentDriver;
        for (char currentChar: currentLine) {
            if (currentChar != '\n' and currentChar != ',') {
                currentTerm += currentChar;
            } else {
                currentDriver.push_back(currentTerm);

                currentTerm = "";
            }
        }
        returnValue.push_back(currentDriver);
        driveTime.push_back(stod(currentTerm));
    }

    return returnValue;
}

// Combines both time vector into a properly formatted single vector
std::vector<std::vector<double>> combineTimeVectors(const std::vector<double>& ItalyTimes, const std::vector<double>& NetherlandsTimes){
    std::vector<std::vector<double>> returnValue;

    for (int i = 0; i < ItalyTimes.size(); ++i) {
        std::vector<double> currentDriverTime;

        currentDriverTime.push_back(NetherlandsTimes.at(i));
        currentDriverTime.push_back(ItalyTimes.at(i));
        currentDriverTime.push_back(ItalyTimes.at(i) + NetherlandsTimes.at(i));

        returnValue.push_back(currentDriverTime);
    }
    return returnValue;
}

// Loops through everything and finds the winner
// 1st: Netherlands Winner, 2nd: Italy Winner, 3rd: Total Winner
std::vector<int> findWinners(const std::vector<std::vector<double>>& timeVector){
    int currentIndex = 0, italyIndex = 0, NetherlandsIndex = 0, totalIndex = 0;

    double italyMax = std::numeric_limits<double>::max();
    double NetherlandsMax = std::numeric_limits<double>::max();
    double totalMax = std::numeric_limits<double>::max();

    for (auto currentDriver : timeVector) {
        if (currentDriver.at(0) < NetherlandsMax)
        {
            NetherlandsIndex = currentIndex;
            NetherlandsMax = currentDriver.at(0);
        }

        if (currentDriver.at(1) < italyMax)
        {
            italyIndex = currentIndex;
            italyMax = currentDriver.at(1);
        }

        if (currentDriver.at(2) < totalMax)
        {
            totalIndex = currentIndex;
            totalMax = currentDriver.at(2);
        }

        currentIndex++;
    }
    return vector<int> { NetherlandsIndex, italyIndex, totalIndex };
}