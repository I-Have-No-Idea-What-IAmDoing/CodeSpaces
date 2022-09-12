#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#include <iostream>
using namespace std;

// NAME: main.cpp
// OVERVIEW:
//      A program that converts ASCII text to a binary sequence and vice versa.
// USAGE:
//      Run it and follow the instruction given.


// SUMMARY:
//      Transform a STRING of CHAR into a binary sequence
// INPUT:
//      StringInput: a STRING of ASCII character that is terminated with a period.
// OUTPUT:
//      STRING: an ASCII STRING of a binary sequence for each CHAR decimal value of the |StringInput|.
// REMARKS:
//      Each binary form of each character is seperated with whitespace.
string encodeStringBinary(const string& StringInput);

// SUMMARY:
//      Encodes a single character into the binary sequence of the decimal value it represents.
// INPUT:
//      UnconvertedChar: An int that represents a single character to be encoded.
// OUTPUT:
//      STRING: a binary sequence of the |UnconvertedChar| character
string encodeCharBinary(const int& UnconvertedChar);

// SUMMARY:
//      Transform a binary sequence into an ASCII STRING
// INPUT:
//      BinaryInput: a STRING of a binary sequence with each encoded character separated with whitespace.
// OUTPUT:
//      STRING: an ASCII STRING based on each encoded character ASCII decimal value.
// REMARKS:
//      This function will assume that the sentence will end in a period.
//      The input string should ideally be trimmed beforehand.
string decodeStringBinary(const string& BinaryInput);

// SUMMARY:
//      Transform a STRING that is representing a single ASCII CHAR into a CHAR
// INPUT:
//      EncodedString: a STRING containing 7 characters of '1' and '0'
// OUTPUT:
//      CHAR: an ASCII character
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
//      Loops through the string character by character calling [encodeCharBinary] to transform it to the proper
//      representation.
string encodeStringBinary(const string& StringInput)
{
    string ReturnValue;

    for (const char currentChar : StringInput) {
        ReturnValue += encodeCharBinary(currentChar);
        // Need to separate every encoded character with a whitespace
        ReturnValue += " ";
    }

    return ReturnValue;
}

// DESCRIPTION:
//      Loops through the prepopulated string backwards turning a character into a one if it's not divisible
//      by two in that base
string encodeCharBinary(const int& UnconvertedChar)
{
    int charValue = static_cast<int>(UnconvertedChar);

    // Pre-populate the string because it probably more efficient?
    string encodedChar = "0000000";

    // Loop backwards through the string to get to the smallest value first
    for (int i = encodedChar.size() - 1; i >= 0; --i) {

        // Check if the value is not even as that means it's the smallest value that still fits
        if (charValue % 2 != 0) {
            encodedChar[i] = '1';
        }

        // In either cases reduce the charValue by half
        charValue /= 2;
    }

    return encodedChar;
}
#pragma clang diagnostic pop
// DESCRIPTION:
//      Loop through the whole string and then calling [decodeCharBinary] to transform it to the proper
//      representation.
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
//      Loop through the |EncodedString| in chunks of 7 character adding by the current base if the character is one
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