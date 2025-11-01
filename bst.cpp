#ifndef BST_CPP
#define BST_CPP

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
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
    Node* max = getMaxNode();
    return(max->data);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data, Key>::max_key(){
    Node* max = getMaxNode();
    return(max->key);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Data BST<Data, Key>::min_data(){
    Node* min = getMinNode();
    return(min->data);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data, Key>::min_key(){
    Node* min = getMinNode();
    return(min->key);
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
Pre-Conditions: None
Post-Conditions: A string with all key from top(root) to bottom(final leaves) from left to right
*/
template <class Data, class Key>
std::string BST<Data, Key>::to_string(){
    if(node == NULL){
        return "";
    }

    std::stringstream ss;
    
    vector<Node*> childNodes = {root};
    vector<Node*> nextChildNodes;
    bool first = true;

    //ends when there are no new generations
    while(!childNodes.empty()){

        //clears newChildren
        while(!nextChildNodes.empty()){
            nextChildNodes.pop_back();
        }

        //add all siblings/cousins to the string
        for(int i=0; i<len(childNodes); i++){
            if(first){
                first = false;
            }else{
                ss << " ";
            }

            ss << childNodes[i]->key;

            //potental kids stored
            if(childNodes[i]->left != NULL){
                nextChildNodes.push_back(childNodes[i]->left);
            }
            if(childNodes[i]->right != NULL){
                nextChildNodes.push_back(childNodes[i]->right);
            }
        }

        //empty kids
        while(!childNodes.empty()){
            childNodes.pop_back();
        }
        //remake kids
        for(int i=0; i<len(nextChildNodes); i++){
            childNodes.push_back(nextChildNodes[i]);
        }
    }
    return ss.str();
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
