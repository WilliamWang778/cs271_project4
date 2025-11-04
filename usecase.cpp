#include <string>
#include <fstream>
#include <iostream>
#include "bst.cpp"
using namespace std;

/*
Pre-Conditions: fname is a file name, and data and class are strings
Post_Conditions: BST from the file is made
*/

// Creates a BST from a CSV file with lines of "hex,bin"
// Returns a pointer to the created BST
// Default template types are string for both Data and Key
// You can specify different types if needed
// For example: BST<int, string>* bst = create_bst<int, string>("file.txt");
// But for this use case, we use string for both
// The binary strings are the keys, and the hexadecimal strings are the data

template <class Data = string, class Key = string>
BST<Data, Key>* create_bst(string fname){
    BST<Data, Key> *bst = new BST<Data, Key>();
    ifstream file(fname);

    string line;
    while (getline(file, line))
    {
        size_t comma = line.find(",");

        string hex = line.substr(0, comma);
        string bin = line.substr(comma + 1);

        bst->insert(hex, bin);
    }
    return bst;
}

/*
Pre-Conditions: Types for data and key are the same (string) and bin contains only 1's + 0's
Post_Conditions: The hex code from the binary given is returned as a string
*/
template <class Data, class Key>
string convert(BST<Data, Key>*bst, string bin){
    while(bin.length()%4 != 0){
        bin = "0" + bin;
    }

    string retHex = "";
    while(!bin.empty()){
        string key = bin.substr(0,4);
        bin = bin.substr(4);

        retHex = retHex + bst->get(key); 
    }

    return retHex;
}
