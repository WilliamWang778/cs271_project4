#ifndef BST_CPP
#define BST_CPP

#include <string>
#include <sstream>
#include <iostream>
#include "bst.h"

using namespace std;

// Constructor
/*
Pre-Conditions: None
Post_Conditions: start for tree. root is NULL
*/
template <class Data, class Key>
    BST<Data, Key>::BST(void){
        root = NULL;
}

// Destructor
/*
Pre-Conditions: BST is a tree
Post_Conditions: All nodes are clears and dealocated
*/
template <class Data, class Key>
    BST<Data, Key>::~BST(){
        FullClear(root);
}


// BST operations
/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
void BST<Data, Key>::insert(Data d, Key k){
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Data BST<Data, Key>::get(Key k){
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
void BST<Data, Key>::remove(Key k){
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Data BST<Data, Key>::max_data(){
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data, Key>::max_key(){
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Data BST<Data, Key>::min_data(){
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data, Key>::min_key(){
    
}


/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data, Key>::successor(Key k){
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
std::string BST<Data, Key>::in_order(){
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
void BST<Data, Key>::trim(Key low, Key high){
    
}

//Utility Operations
/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
std::string BST<Data, Key>::to_string(){
    
}


//healper funciton
/*
Pre-Conditions: Current is either a node or NULL
Post_Conditions: Current and it's children are deleted
*/
template <class Data, class Key>
void BST<Data, Key>::FullClear(Node* current){
    if(current == NULL){
        return;
    }
    FullClear(current->left);
    FullClear(current->right);
    delete current;
    return;
}

#endif
