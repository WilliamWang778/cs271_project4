//#ifndef BST_H
//#define BST_H

#include <string>
#include <sstream>

template <typename Data, typename Key>
class BST {
private:
    struct Node {
        Data data;
        Key key;
        Node* left;
        Node* right;
        Node* p;
    };

    Node* root;

    //Helping operations
    void FullClear(Node* current);

    const Node* getMinNode(Node* x = root){
        while (x != NULL && x -> left != NULL){
            x = x -> left;
        }
        return x;
    }

    const Node* getMaxNode(Node* x = root){
        while (x != NULL && x -> right != NULL){
            x = x -> right;
        }
        return x;
    }

    std::stringstream in_order_helper(Node* x) const;

    Node* searchNode(const Key& k) const;

    void transplant(Node* u, Node* v){
        if (u->p == nullptr) {
            root = v;
        } else if (u == u->p->left) {
            u->p->left = v;
        } else {
            u->p->right = v;
        }
        if (v != nullptr) {
            v->p = u->p;
        }
    }
    
    

public:

    //Default constructor
    BST (void);

    //Deconstructor
	~BST (void);

    //BST operations
    bool empty(){return root == NULL;}
    void insert(Data d, Key k);
    Data get(Key k);
    void remove(Key k);
    Data max_data();
    Key max_key();
    Data min_data();
    Key min_key();
    Key successor(Key k);
    std::string in_order();
    void trim(Key low, Key high);

    //Utility Operations
    std::string to_string();
    
    std::stringstream& ss;
};

//#endif
