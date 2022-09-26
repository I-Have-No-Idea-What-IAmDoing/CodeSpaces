#include "functions.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    // The menu option that is chosen (Should be between 0 and 2 inclusive)
   int option;
   do
   {
       // The input to be encrypted/decrypted
       string input;

       // The user key for the cipher
       string inputKey;

       // Temporary variable used to validate the input before putting it in option
       char tempInput;

       std::cout << "1. Encrypt Message\n"
                    "2. Decrypt Message\n"
                    "3. Quit\n"
                    "Enter:" << endl;
       cin >> tempInput;

       // Validate the input and make sure it is a number
       if (not (tempInput >= 48 and tempInput <= 57))
       {
           cout << "ERROR: You selected an invalid choice, please try again\n" << endl;
           cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           continue;
       }

       // Convert the number ASCII value into the proper value it represents
       option = tempInput - 48;

       switch (option) {
           case 3:
               // Quit Branch
                break;
           case 1:
               // Encrypt Branch
               cin.ignore();

               cout << "Key: " << endl;
               do {
                   getline(cin, inputKey);
               }while(!verifyKey(inputKey));

               toupperString(inputKey);

               cout << "Plaintext Message: " << endl;
               getline(cin, input);
               toupperString(input);

               cout << "Ciphertext Message: " << encryptMessage(inputKey, input) << endl;
               break;
           case 2:
               // Encrypt Branch
               cin.ignore();

               cout << "Key: " << endl;
               do {
                   getline(cin, inputKey);
               }while(!verifyKey(inputKey));
               toupperString(inputKey);

               cout << "Ciphertext Message: " << endl;
               getline(cin, input);
               toupperString(input);

               cout << "Plaintext Message: " << decryptMessage(inputKey, input) << endl;
               break;
           default:
               cout << "ERROR: You selected an invalid choice, please try again\n" << endl;
               break;
       }
   }while(option != 3);

    return 0;
}
