#ifndef PROGRAM02_TEMPLATE_FUNCTIONS_H
#define PROGRAM02_TEMPLATE_FUNCTIONS_H
#include <string>

using namespace std;

/**
 * Define Function Prototypes Here
 */

void toupperString(string& loweredString);

bool verifyKey(string& key);

string encryptMessage(string key, const string& message);

string decryptMessage(string key, const string& message);

#endif //PROGRAM02_TEMPLATE_FUNCTIONS_H
