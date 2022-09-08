#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string passwordStr = "ab9";
   
   /* Your code goes here */
   bool allAlphas = true;
   for (int i = 0; i < passwordStr.size(); i++)
   {
    cout << !isalpha('9') << endl;
      if (!isalpha(passwordStr[i]))
      {
       
         allAlphas = false;
         break;
         }
      }
   if (allAlphas) {
      cout << "Good password" << endl;
   }
   else {
      cout << "Bad password" << endl;
   }

   return 0;
}