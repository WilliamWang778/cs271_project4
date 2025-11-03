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

// Copy constructor
/*
Pre-Conditions: Other has the same template types
Post_Conditions: Tree is a perfect copy of other in the same order
*/
template <class Data, class Key>
    BST<Data, Key>::BST(const BST& other){
        root = NULL;
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
        root = NULL;
        DeepCopy();
}

// BST operations


// INSERT

/*
Pre-Conditions: #1 The BST object exists and its attributes are well-formed. #2 Enough memory is available to allocate a new Node.
Post-Conditions: A new node storing is inserted as a leaf. Parent pointers are updated; the BST property is preserved.
*/
template <class Data, class Key>
void BST<Data, Key>::insert(Data d, Key k){

    // allocate new node with (d,k)
    Node* z = new Node(d,k);
    Node* y = NULL;
    // start from root
    Node* x = root;

    // Walk down the tree to find the insertion spot
    while (x != NULL){
        y = x;
        if (k < x->key){
            // go left if k is smaller
            x = x -> left;
        } else {
            // go right if k >= x->key
            x = x -> right;
        } 
    }

    // Link z under y
    z -> p = y;
    if (y == NULL){
        root = z;
    } else if (z -> key < y -> key){
        // attach as left child
        y -> left = z;
    } else{
        // attach as right child
        y-> right = z;
    }

}


// SEARCH

/*
Pre-Conditions: The BST structure is valid and satisfies the BST property.
Post-Conditions:  Returns a pointer to a node whose key == k if found; otherwise returns nullptr.
*/
template <class Data, class Key>
typename BST<Data, Key>::Node*
BST<Data, Key>::searchNode(const Key& k) const {

    // search start at root
    Node* x = root;
    while (x != nullptr) {
        // search left subtree
        if (k < x->key) {
            x = x->left;
        } else if (x->key < k) {
            // search right subtree
            x = x->right;
        } else {
            // found the same match
            return x;  
        }
    }
    // not found
    return nullptr;
}




/*
Pre-Conditions: The BST is valid.
Post-Conditions: If a node with key k exists, returns its data. If a node with key k exists, returns its data.
*/
template <class Data, class Key>
Data BST<Data, Key>::get(Key k){

    // locate node with key k
    Node* x = searchNode(k);
    if (x != NULL){
        // return stored data if found
        return x -> data;
    } else {
        // not found: default value
        return Data{};
    }
    
    
}


/*
Pre-Conditions: The BST is valid and obeys the BST property. Type Key supports operator<.
Post-Conditions:If a node with key k exists, removes one occurrence from the tree, deallocates 
that node, and preserves the BST property If no such node exists, the tree is unchanged.
*/
template <class Data, class Key>
void BST<Data, Key>::remove(Key k){

    // find node to delete
    Node* z = searchNode(k);
    if (!z) {
        return; 
    } 

    // case 1: no left child: replace z by right child
    if (z->left == nullptr) {
        transplant(z, z->right);
        delete z;

        // Case 2: no right child: replace z by left child
    } else if (z->right == nullptr) {
        transplant(z, z->left);
        delete z;
    } else {
        // Case 3: two children
        Node* y = minimum(z->right); 
        if (y->p != z) {
            // Move y's right child up where y was
            transplant(y, y->right);
            // Put z's right subtree under y
            y->right = z->right;
            if (y->right != NULL){
                y -> right -> p = y;
            }
            
        }
        // replace z with y
        transplant(z, y);
        // attach z's left subtree under y
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
    Node* max = getMaxNode();
    if(max == NULL){
        return Data{};
    }
    return(max->data);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Key BST<Data, Key>::max_key(){
    Node* max = getMaxNode();
    if(max == NULL){
        return Data{};
    }
    return(max->key);
}

/*
Pre-Conditions: 
Post-Conditions: 
*/
template <class Data, class Key>
Data BST<Data, Key>::min_data(){
    Node* min = getMinNode();
    if(min == NULL){
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
    Node* min = getMinNode();
    if(min == NULL){
        return Data{};
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
            if(childNodes[i]->left != NULL){
                nextChildNodes.push_back(childNodes[i]->left);
            }
            if(childNodes[i]->right != NULL){
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
            this.insert(Copying[i]->data, Copying[i]->key);

            //Next row saved to do
            if(Copying[i]->left != NULL){
                nextToCopy.push_back(Copying[i]->left);
            }
            if(Copying[i]->right != NULL){
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
