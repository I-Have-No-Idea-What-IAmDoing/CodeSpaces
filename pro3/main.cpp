#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

int main() {
    std::string example;

    // IMPORTANT NOTE: Notice using "../" to prefix the file name. You will need that to access files properly in CLION.
    std::ifstream netherlands_file("../Netherlands.csv");
    getline(netherlands_file, example);

    // Prints out first row of netherlands file
    std::cout << example << std::endl;
    return 0;
}
