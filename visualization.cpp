#include <iostream>
#include <string>
#include "bst.cpp" // Includes the BST implementation

using namespace std;

// Helper function to print a separator for clarity
void printSeparator() {
    cout << "\n" << string(70, '=') << "\n\n";
}

// Main function to run the visualization demos
int main() {
    cout << "\n*** BST (Binary Search Tree) Visualization Demo ***\n";

    // A balanced tree used for several demos
    // Keys: {5, 2, 7, 1, 3, 9, 8, 10}
    // to_string() output: 5 2 7 1 3 9 8 10
    // in_order() output: 1 2 3 5 7 8 9 10
    BST<string, int> demo_bst;
    int keys[] = {5, 2, 7, 1, 3, 9, 8, 10};
    for (int key : keys) {
        demo_bst.insert("data_" + to_string(key), key);
    }

    // ========== Demo 1: empty() ==========
    printSeparator();
    cout << "Demo 1: empty()\n\n";
    BST<string, int> bst1;
    cout << "Newly created BST, bst1.empty(): " << (bst1.empty() ? "true" : "false") << "\n";
    bst1.insert("one", 1);
    cout << "After inserting one element, bst1.empty(): " << (bst1.empty() ? "true" : "false") << "\n";

    // ========== Demo 2: insert() ==========
    printSeparator();
    cout << "Demo 2: insert()\n\n";
    BST<string, int> bst2;
    cout << "Inserting keys {5, 2, 7, 1, 3, 9, 8, 10} to build a balanced tree.\n\n";
    cout << "Initial (empty) tree:\n" << bst2.to_string() << "\n\n";
    int keys2[] = {5, 2, 7, 1, 3, 9, 8, 10};
    for (int key : keys2) {
        bst2.insert("data_" + to_string(key), key);
        cout << "After inserting key " << key << ":\n";
        cout << "Tree Structure (level order): " << bst2.to_string() << "\n\n";
    }
    cout << "Final Tree Structure (level order): " << bst2.to_string() << "\n";
    cout << "Final Tree (in order): " << bst2.in_order() << "\n";

    // ========== Demo 3: get() ==========
    printSeparator();
    cout << "Demo 3: get()\n\n";
    cout << "Using this tree:\n";
    cout << "Tree Structure: " << demo_bst.to_string() << "\n\n";
    cout << "bst.get(7): " << demo_bst.get(7) << "\n";
    cout << "bst.get(1): " << demo_bst.get(1) << "\n";
    cout << "bst.get(99) (not in tree): \"" << demo_bst.get(99) << "\" (default string)\n";

    // ========== Demo 4: remove() ==========
    printSeparator();
    cout << "Demo 4: remove()\n\n";
    BST<string, int> bst4;
    int keys4[] = {5, 2, 8, 1, 3, 6, 9, 7};
    for (int key : keys4) {
        bst4.insert("data_" + to_string(key), key);
    }
    cout << "Initial Tree: " << bst4.to_string() << "\n\n";

    cout << "1. Removing a leaf node (key=1):\n";
    bst4.remove(1);
    cout << "   Tree Structure: " << bst4.to_string() << "\n\n";

    cout << "2. Removing a node with one child (key=9):\n";
    bst4.remove(9);
    cout << "   Tree Structure: " << bst4.to_string() << "\n\n";
    
    cout << "3. Removing a node with two children (key=8):\n";
    cout << "   (Successor is 6 with child 7)\n";
    bst4.remove(6); // Re-inserting the previous tree state for this demo
    bst4.insert("data_9", 9);
    bst4.remove(8);
    cout << "   Tree Structure: " << bst4.to_string() << "\n\n";
    
    cout << "4. Removing the root node (key=5):\n";
    bst4.remove(5);
    cout << "   Tree Structure: " << bst4.to_string() << "\n";

    // ========== Demo 5: max_data() and max_key() ==========
    printSeparator();
    cout << "Demo 5: max_data() and max_key()\n\n";
    cout << "Using this tree:\n";
    cout << "Tree Structure: " << demo_bst.to_string() << "\n";
    cout << "Sorted Keys:    " << demo_bst.in_order() << "\n\n";
    cout << "Max Key:  " << demo_bst.max_key() << "\n";
    cout << "Max Data: " << demo_bst.max_data() << "\n";

    // ========== Demo 6: min_data() and min_key() ==========
    printSeparator();
    cout << "Demo 6: min_data() and min_key()\n\n";
    cout << "Using this tree:\n";
    cout << "Tree Structure: " << demo_bst.to_string() << "\n";
    cout << "Sorted Keys:    " << demo_bst.in_order() << "\n\n";
    cout << "Min Key:  " << demo_bst.min_key() << "\n";
    cout << "Min Data: " << demo_bst.min_data() << "\n";

    // ========== Demo 7: successor() ==========
    printSeparator();
    cout << "Demo 7: successor()\n\n";
    cout << "Using this tree:\n";
    cout << "Tree Structure: " << demo_bst.to_string() << "\n";
    cout << "Sorted Keys:    " << demo_bst.in_order() << "\n\n";
    cout << "Successor of 3: " << demo_bst.successor(3) << " (should be 5)\n";
    cout << "Successor of 5: " << demo_bst.successor(5) << " (should be 7)\n";
    cout << "Successor of 8: " << demo_bst.successor(8) << " (should be 9)\n";
    cout << "Successor of 10 (max key): " << demo_bst.successor(10) << " (should be 0, as there's no successor)\n";


    // ========== Demo 8: in_order() ==========
    printSeparator();
    cout << "Demo 8: in_order()\n\n";
    cout << "Builds a string of keys in sorted (ascending) order.\n\n";
    cout << "Tree Structure: " << demo_bst.to_string() << "\n";
    cout << "In-Order String: \"" << demo_bst.in_order() << "\"\n";

    // ========== Demo 9: trim() ==========
    printSeparator();
    cout << "Demo 9: trim()\n\n";
    BST<string, int> bst9;
    int keys9[] = {10, 5, 20, 2, 7, 15, 25, 18};
    for(int key : keys9){
        bst9.insert("data_"+to_string(key), key);
    }
    cout << "Initial Tree:       " << bst9.to_string() << "\n";
    cout << "Initial In-Order:   " << bst9.in_order() << "\n\n";

    cout << "Trimming the tree to range [7, 20].\n";
    cout << "Should remove keys 2, 5, and 25.\n\n";
    bst9.trim(7, 20);

    cout << "Trimmed Tree:       " << bst9.to_string() << "\n";
    cout << "Trimmed In-Order:   " << bst9.in_order() << "\n";

    printSeparator();
    cout << "*** Demo Complete! ***\n\n";

    return 0;
}