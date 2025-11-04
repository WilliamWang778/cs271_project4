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
        root = nullptr;
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

// Copy constructor
/*
Pre-Conditions: Other has the same template types
Post_Conditions: Tree is a perfect copy of other in the same order
*/
template <class Data, class Key>
    BST<Data, Key>::BST(const BST& other){
        root = nullptr;
        DeepCopy();
}

// Operator=
/*
Pre-Conditions: Other has the same template types
Post_Conditions: Tree is a perfect copy of other in the same order
*/
template <class Data, class Key>
    BST<Data, Key>& BST<Data, Key>::operator=(const BST& other){
        FullClear(root);
        root = nullptr;
        DeepCopy();
}


// BST operations


// INSERT

/*
Pre-Conditions: The BST object exists. Type Key supports operator<.
Post-Conditions: A new node storing (d,k) is inserted as a leaf. The BST ordering property is preserved.
*/
template <class Data, class Key>
void BST<Data, Key>::insert(Data d, Key k){

    // Create the new node
    Node* z = new Node();
    z -> data = d;
    z -> key = k;

    // track parent of the insertion spot
    Node* y = nullptr;
    // start from the root
    Node* x = root;

    // walk down the tree to find where to insert
    while (x != nullptr){
        y = x;
        if (k < x->key){
            x = x -> left;
        } else {
            x = x -> right;
        } 
    }

    // Link the new node under its parent
    z -> p = y;
    if (y == nullptr){
        root = z;
    } else if (z -> key < y -> key){
        y -> left = z;
    } else{
        y-> right = z;
    }

}


// SEARCH

/*
Pre-Conditions: Type Key supports operator<.
Post-Conditions: Returns a pointer to the node whose key == k if found; otherwise returns nullptr.
*/
template <class Data, class Key>
typename BST<Data, Key>::Node*
BST<Data, Key>::searchNode(const Key& k) const {
    // start at root
    Node* x = root;
    while (x != nullptr) {
        // search left if k is smaller
        if (k < x->key) {
            x = x->left;
            // search right if k is larger
        } else if (x->key < k) {
            x = x->right;
            // equal: found the key
        } else {
            return x;  
        }
    }
    return nullptr;
}




/*
Pre-Conditions: Type Key supports operator<.
Post-Conditions: If a node with key k exists, its data is returned.
*/
template <class Data, class Key>
Data BST<Data, Key>::get(Key k){
    // Find the node with key k
    Node* x = searchNode(k);

    // If found, return its data; otherwise return default value
    if (x != nullptr){
        return x -> data;
    } else {
        return Data{};
    }
    
    
}


/*
Pre-Conditions: The BST is valid and obeys the BST property. 
Post-Conditions:If a node with key k exists, removes one occurrence from the tree, deallocates 
that node, and preserves the BST property If no such node exists, the tree is unchanged.
*/
template <class Data, class Key>
void BST<Data, Key>::remove(Key k){

    // Find the node to delete
    Node* z = searchNode(k);
    if (!z) {
        return; 
    } 
    // Case 1: no left child
    if (z->left == nullptr) {
        transplant(z, z->right);
        delete z;
        // Case 2: no right child
    } else if (z->right == nullptr) {
        transplant(z, z->left);
        delete z;
        // Case 3: two children
    } else {
        Node* y = getMinNode(z->right); 

        // If successor y is not the direct right child of z
        if (y->p != z) {
            transplant(y, y->right);
            y->right = z->right;
            if (y->right != nullptr){
                y -> right -> p = y;
            }
            
        }
        // Replace z with y
        transplant(z, y);
        // Hook z's left subtree under y
        y->left = z->left;
        if (y->left != nullptr){
            y->left->p = y;
        }
        delete z;
    }
    
}

/*
Pre-Conditions: None
Post-Conditions: returns data of Max if not null
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
Pre-Conditions: None
Post-Conditions: returns key of Max if not null
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
Pre-Conditions: None
Post-Conditions: returns data of Min if not null
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
Pre-Conditions: None
Post-Conditions: returns key of Min if not null
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
Pre-Conditions: The BST that is valid and obeys the BST property.
Post-Conditions: Returns the key of the successor node if it exists, otherwise returns a default-constructed Key.
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
Pre-Conditions: The BST that is valid and obeys the BST property.
Post-Conditions: Returns a string of all keys in the BST in sorted order, separated by spaces.
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
Pre-Conditions: The BST that is valid and obeys the BST property.
Post-Conditions: The BST is modified to only contain nodes with keys in the range [low, high].
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
        nextChildNodes.clear();

        //add all siblings/cousins to the string
        for(int i=0; i<childNodes.size(); i++){
            if(first){
                first = false;
            }else{
                ss << " ";
            }

            ss << childNodes[i]->key;

            //potental kids stored
            if(childNodes[i]->left != nullptr){
                nextChildNodes.push_back(childNodes[i]->left);
            }
            if(childNodes[i]->right != nullptr){
                nextChildNodes.push_back(childNodes[i]->right);
            }
        }

        //empty kids
        childNodes.clear();

        //remake kids
        childNodes = nextChildNodes;
    }
    return ss.str();
}



//helper funciton (in_order_helper)
/*
Pre-Conditions: Current is either a node or nullptr
Post_Conditions: Current and it's children are deleted
*/

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



//helper funciton (Full Clear)
/*
Pre-Conditions: Current is either a node or NULL
Post_Conditions: Current and it's children are deleted
*/
template <class Data, class Key>
void BST<Data, Key>::FullClear(Node* current){
    if(current == nullptr){
        return;
    }
    FullClear(current->left);
    FullClear(current->right);
    delete current;
    return;
}

/*
Pre-Conditions: Root is null, AND they are of the same data and key type
Post_Conditions: Full copy of other
*/
template <class Data, class Key>
void BST<Data, Key>::DeepCopy(const BST& other){
    
    vector<Node*> Copying = {other.root};
    vector<Node*> nextToCopy;
    bool first = true;

    //ends when there are no parts
    while(!Copying.empty()){

        //clears NextCopies
        nextToCopy.clear();

        //Insert each row at a time
        for(int i=0; i<Copying.size(); i++){
            insert(Copying[i]->data, Copying[i]->key);

            //Next row saved to do
            if(Copying[i]->left != nullptr){
                nextToCopy.push_back(Copying[i]->left);
            }
            if(Copying[i]->right != nullptr){
                nextToCopy.push_back(Copying[i]->right);
            }
        }

        //empty current row
        Copying.clear();
        
        //remake row
        Copying = nextToCopy;
    }
    
    return;
}


#endif
