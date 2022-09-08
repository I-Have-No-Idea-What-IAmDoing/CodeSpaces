#include <iostream>
using namespace std;
int main()
{
    while (true)
    {
        int option = -1;

        // Temporary variable used to validate the input before putting it in option
        char tempInput;

        std::cout << "Please select an option: \n"
                     "1) Encode a sentence\n"
                     "2) Decode binary\n"
                     "0) Quit\n"
                     "Select Choice (1, 2, or 0): ";
        cin >> tempInput;

        // Validate the input and make sure it is a number
        if (not (tempInput >= 48 and tempInput <= 57))
        {
            cout << "\nERROR: You selected an invalid choice, please try again\n" << endl;
            continue;
        }

        option = tempInput - 48;

        switch (option) {
            case 0:
                goto endLoop;
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                cout << "\nERROR: You selected an invalid choice, please try again\n" << endl;
                break;
        }
    }

    // this feels dirty but this is what goto is for...
    // could use a flag but ehh?
    endLoop:
        cout << "\nThank you!! o(*￣▽￣*)ブ" << endl;
        return 0;
}
