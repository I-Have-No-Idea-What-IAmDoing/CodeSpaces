#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#include <iostream>
using namespace std;

// NAME: main.cpp
// OVERVIEW:
//      TODO
// USAGE:
//      TODO


// SUMMARY:
//      Transform a STRING of CHAR into a binary sequence
// INPUT:
//      StringInput: a STRING of ASCII character that is terminated with a period.
// OUTPUT:
//      STRING: an ASCII STRING of a binary sequence for each CHAR decimal value of the |INPUT|.
// REMARKS:
//      Each binary form of each character is seperated with whitespace.
string encodeStringBinary(const string& StringInput);

// SUMMARY:
//      TODO
// INPUT:
//      TODO
// OUTPUT:
//      TODO
string encodeCharBinary(const int& UnconvertedChar);

// SUMMARY:
//      TODO
// INPUT:
//      BinaryInput: TODO
// OUTPUT:
//      STRING: TODO
// REMARKS:
//      TODO
string decodeStringBinary(const string& BinaryInput);

// SUMMARY:
//      TODO
// INPUT:
//      TODO
// OUTPUT:
//      TODO
char decodeCharBinary(const string& EncodedString);

int main()
{
    while (true)
    {
        // The menu option that is chosen (Should be between 0 and 2 inclusive)
        int option;

        // The input to be encoded/decoded
        string input;

        // Temporary variable used to validate the input before putting it in option
        char tempInput;

        std::cout << "Please select an option: \n"
                     "1) Encode a sentence\n"
                     "2) Decode binary\n"
                     "0) Quit\n"
                     "Select Choice (1, 2, or 0): " << endl;
        cin >> tempInput;

        // Validate the input and make sure it is a number
        if (not (tempInput >= 48 and tempInput <= 57))
        {
            cout << "ERROR: You selected an invalid choice, please try again\n" << endl;
            continue;
        }

        // Convert the number ASCII value into the proper value it represents
        option = tempInput - 48;

        switch (option) {
            case 0:
                // Quit Branch
                goto endLoop;
            case 1:
                // Encoding Branch
                cout << "Enter a sentence to be encoded (ending in a period):" << endl;
                cin.ignore();
                getline(cin, input,'.');
                input += '.';
                cout << "Encoded String: " << encodeStringBinary(input) << endl;
                break;
            case 2:
                // Decoding Branch
                cout << "Enter a series of bytes to decode:" << endl;
                cin.ignore();
                getline(cin, input);
                cout << "Decoded String: " << decodeStringBinary(input) << endl;
                break;
            default:
                cout << "ERROR: You selected an invalid choice, please try again\n" << endl;
                break;
        }
    }

    // this feels dirty but this is what goto is for...
    // could use a flag but ehh?
    endLoop:
        cout << "\nThank you!! o(*￣▽￣*)ブ" << endl;
        return 0;
}

// DESCRIPTION:
//      TODO
string encodeStringBinary(const string& StringInput)
{
    string ReturnValue;

    for (const char currentChar : StringInput) {
        ReturnValue += encodeCharBinary(currentChar);
        // Need to separate every "byte" with a whitespace
        ReturnValue += " ";
    }

    return ReturnValue;
}

// DESCRIPTION:
//      TODO
string encodeCharBinary(const int& UnconvertedChar)
{
    int charValue = static_cast<int>(UnconvertedChar);

    // Pre-populate the string because it probably more efficient?
    string encodedChar = "0000000";
    while (charValue > 0) {
        // Loop backwards through the string
        for (int i = encodedChar.size() - 1; i >= 0; --i) {

            // Check if the value is not even as that means TODO
            if (charValue % 2 != 0) {
                encodedChar[i] = '1';
            }

            // In either cases reduce the charValue
            charValue /= 2;
        }
    }

    return encodedChar;
}
#pragma clang diagnostic pop
// DESCRIPTION:
//      TODO
string decodeStringBinary(const string& BinaryInput)
{
    string ReturnValue;

    string currentCharSequence;
    int currentPosition = 0;

    while (currentCharSequence != "0101110" and (currentPosition + 8) < BinaryInput.size())
    {
        currentCharSequence = BinaryInput.substr(currentPosition,7);
        ReturnValue += decodeCharBinary(currentCharSequence);
        currentPosition += 8;
    }

    return ReturnValue + '.';
}

// DESCRIPTION:
//      TODO
char decodeCharBinary(const string& EncodedString)
{
    int base = 64;
    int charValue = 0;
    for (const char currentChar : EncodedString) {
        switch (currentChar) {
            case '1':
                charValue += base;
            case '0':
                base /= 2;
                break;
            default:
                break;
        }
    }

    return static_cast<char>(charValue);
}