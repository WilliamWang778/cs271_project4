#include <iostream>
#include <string>
using namespace std;
#include "usecase.cpp"


/*


main()

Builds a BST from the CSV file "binhex.txt". Then it shows two fixed example 
conversions and finally asks the user to type a binary string to convert. 
The conversion is done by convert(), which looks up each 4-bit chunk in the 
BST and returns the hex string.


Input : user types a binary string in the terminal
Output: prints the hexadecimal representation of that binary string.

*/

int main(){

    // Build the BST from the provided CSV
    BST<string, string>* bst = create_bst("binhex.txt");

    // Example 1
    string bin1 = "111010100101";
    string hex1 = convert(bst, bin1);
    cout << "Enter binary representation for conversion:\n";
    cout << bin1 << "\n";
    cout << "Hexidecimal representation of " << bin1 << " is " << hex1 << "\n\n";


    // Example 2
    string bin2 = "110101";
    string hex2 = convert(bst, bin2);
    cout << "Enter binary representation for conversion:\n";
    cout << bin2 << "\n";
    cout << "Hexidecimal representation of " << bin2 << " is " << hex2 << "\n\n";

    // Ask the user for a binary string and print the result
    cout << "Enter binary representation for conversion: ";
    string user_bin;
    if (getline(cin, user_bin)){
        string user_hex = convert(bst, user_bin);
        cout << "Hexidecimal representation of " << user_bin << " is " << user_hex << "\n";
    }

    // Clean up the tree
    delete bst;
    return 0;
}