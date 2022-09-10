#include <iostream>
using namespace std;

// SUMMARY:
//      Transform a STRING of CHAR into a binary sequence
// INPUT:
//      a STRING of ASCII character that is terminated with a period.
// OUTPUT:
//      an ASCII STRING of a binary sequence for each CHAR decimal value of the |INPUT|.
// REMARKS:
//      Each binary form of each character is seperated with whitespace.
string encodeStringBinary(const string& Input);

// SUMMARY:
// INPUT:
// OUTPUT:
string encodeCharBinary(const char& Input);

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
                goto endLoop;
            case 1:
                cout << "Enter a sentence to be encoded (ending in a period):" << endl;
                getline(cin, input,'.');
                input += '.';
                encodeStringBinary(input);
                break;
            case 2:
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
string encodeStringBinary(const string& Input)
{
    for (const char currentChar : Input) {
        static_cast<int>(currentChar);
    }
    return Input;
}


string encodeCharBinary(const string& Input)
{

}

