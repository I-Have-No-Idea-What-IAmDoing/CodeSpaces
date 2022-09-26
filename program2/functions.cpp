#include "functions.h"
#include <iostream>
#include<cmath>

/**
 * All the utility functions are here
 */

void toupperString(string& loweredString) {
    for (char& currentChar: loweredString) {
        currentChar = toupper(currentChar);
    }
}

// Make sure the key fits the requirements outlined
bool verifyKey(string& key) {
    bool goodSize = key.size() >= 1;
    bool goodInput = true;
    for (char currentChar: key) {
        if (!isalpha(currentChar) and !ispunct(currentChar) and !isspace(currentChar))
        {
            goodInput = false;
            break;
        }
    }
    return goodSize && goodInput;
}

string encryptMessage(string key, const string& message) {
    int i = 0;
    const int keySize = key.size();
    string finalMessage = "";

    for (char currentChar : message) {
        if (isalpha(currentChar))
        {
            int shift = key.at(i % keySize) - 65;
            int shiftedChar = (currentChar + shift) % 91;
            // Make sure it loops around
            if (shiftedChar < 65) shiftedChar += 65;
            finalMessage += static_cast<char>(shiftedChar);
            i++;
        }
        else{
            finalMessage += currentChar;
        }
    }

    return finalMessage;
}

string decryptMessage(string key, const string& message) {
    int i = 0;
    const int keySize = key.size();
    string finalMessage = "";

    for (char currentChar : message) {
        if (isalpha(currentChar))
        {
            int shift = key.at(i % keySize) - 65;
            int shiftedChar = (currentChar - shift);

            // Make sure it loops around, as you can see harder than the overflow
            if (shiftedChar < 65)
            {
                int underflowAmount = abs(shiftedChar - 65);
                shiftedChar = 91 - underflowAmount;
            }
            finalMessage += static_cast<char>(shiftedChar);
            i++;
        }
        else{
            finalMessage += currentChar;
        }
    }

    return finalMessage;
}
