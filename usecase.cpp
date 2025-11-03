#include <string>
#include <fstream>
#include <iostream>
#include "bst.cpp"
using namespace std;

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
