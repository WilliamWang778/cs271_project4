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


// INSERT

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
void BST<Data, Key>::insert(Data d, Key k){

    Node* z = new Node(d,k);
    Node* y = NULL;
    Node* x = root;

    while (x != NULL){
        y = x;
        if (k < x->key){
            x = x -> left;
        } else {
            x = x -> right;
        } 
    }
    z -> p = y;
    if (y == NULL){
        root = z;
    } else if (z -> key < y -> key){
        y -> left = z;
    } else{
        y-> right = z;
    }

}


// SEARCH

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
typename BST<Data, Key>::Node*
BST<Data, Key>::searchNode(const Key& k) const {
    Node* x = root;
    while (x != nullptr) {
        if (k < x->key) {
            x = x->left;
        } else if (x->key < k) {
            x = x->right;
        } else {
            return x;  
        }
    }
    return nullptr;
}




/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Data BST<Data, Key>::get(Key k){

    Node* x = searchNode(k);
    if (x != NULL){
        return x -> data;
    } else {
        return Data{};
    }
    
    
}


/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
void BST<Data, Key>::remove(Key k){
    Node* z = searchNode(k);
    if (!z) {
        return; 
    } 

    if (z->left == nullptr) {
        transplant(z, z->right);
        delete z;
    } else if (z->right == nullptr) {
        transplant(z, z->left);
        delete z;
    } else {
        Node* y = getMinNode(z->right); 
        if (y->p != z) {
            transplant(y, y->right);
            y->right = z->right;
            if (y->right != NULL){
                y -> right -> p = y;
            }
            
        }
        transplant(z, y);
        y->left = z->left;
        if (y->left != NULL){
            y->left->p = y;
        }
        delete z;
    }
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Data BST<Data, Key>::max_data(){
    Node* max = getMaxNode(root);
    if(max == nullptr){
        return Data{};
    }
    return(max->data);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data,Key>::max_key(){
    Node* max = getMaxNode(root); 
    if (max == nullptr) { 
        return Key{};
    }
    return(max->key);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Data BST<Data, Key>::min_data(){
    Node* min = getMinNode(root);
    if(min == nullptr){
        return Data{};
    }
    return(min->data);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data, Key>::min_key(){
    Node* min = getMinNode(root);
    if(min == nullptr){
        return Key{};
    }
    return(min->key);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data, Key>::successor(Key k){
    // finding x
    Node* x = searchNode(k);

    // if x == nullptr
    if (x == nullptr){
        return Key{}; 
    }

    if (x -> right != nullptr) {
        return getMinNode(x->right) -> key; //key value
    }
    
    else {
        Node* y = x -> p;
        while (y != nullptr && x == y -> right) {
            x = y;
            y = y -> p;
        }
        
        // defending seg fault

        if (y == nullptr) {
            return Key{};
        }
        else {
            // y is successor
            return y -> key;
        }
    }
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
std::string BST<Data, Key>::in_order(){
    std::stringstream ss = in_order_helper(root);
    std::string result = ss.str();

    if (!result.empty()) {
        result.pop_back();
    }
    
    return result;
    
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
void BST<Data, Key>::trim(Key low, Key high){
    root = trim_helper(root, low, high);
    if (root != nullptr) {
        root -> p = nullptr;
    }
}




//Utility Operations
/*
Pre-Conditions: None
Post-Conditions: A string with all key from top(root) to bottom(final leaves) from left to right
*/
template <class Data, class Key>
std::string BST<Data, Key>::to_string(){
    if(root == nullptr){
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
        for(int i=0; i<childNodes.size(); i++){
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
        for(int i=0; i < nextChildNodes.size(); i++){
            childNodes.push_back(nextChildNodes[i]);
        }
    }
    return ss.str();
}


template<class Data, class Key>
std::stringstream BST<Data, Key>::in_order_helper(Node* x) const {
    
    std::stringstream ss; 

    if (x == nullptr) {
        return ss; 
    }
    
    ss << in_order_helper(x->left).str();  // L
    ss << x->key << " ";                   // C
    ss << in_order_helper(x->right).str(); // R
    
    return ss;
}







//helper funciton
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
