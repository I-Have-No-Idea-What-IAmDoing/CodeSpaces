#ifndef PROGRAM3_TEMPLATE_FUNCTIONS_H
#define PROGRAM3_TEMPLATE_FUNCTIONS_H

#endif //PROGRAM3_TEMPLATE_FUNCTIONS_H
#include <string>
#include <vector>

std::vector<std::vector<std::string>> readRacingCSV(std::ifstream&, std::vector<double>&);

std::vector<std::vector<double>> combineTimeVectors(const std::vector<double>&, const std::vector<double>&);

std::vector<int> findWinners(const std::vector<std::vector<double>>&);