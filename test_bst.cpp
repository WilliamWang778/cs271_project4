#include <iostream>
#include "usecase.cpp"

using namespace std;



void test_empty(){
    BST<int, int> tester;
    if(!tester.empty()){
        cout << "Empty failed. Expected empty tree but got: " << tester.to_string() << endl;
    }
    tester.insert(10,12);
    tester.insert(-10,-12);
    if(tester.empty()){
        cout << "Empty failed. Expected tree with 2 elements (10,12 & -10,-12) but got: " << tester.to_string() << endl;
    }
}

void test_insert(){

}

void test_get(){

}

void test_remove(){

}

void test_max_data(){
    BST<int, int> tester;
    if(tester.max_data() != int{}){
        cout << "Max data on an empty tree failed. Expected return type int{} but got: " << tester.max_data() << endl;
    }
    
    //test zigzag tree
    tester.insert(10,12);
    tester.insert(3,17);
    tester.insert(7,13);
    if(tester.max_data() != 3){
        cout << "Max data on zigzag tree failed. Expected 3 but got: " << tester.max_data() << endl;
        cout << "From the tree: " << tester.to_string() << endl;
    }
}

void test_max_key(){
    BST<int, int> tester;
    if(tester.max_key() != int{}){
        cout << "Max key on an empty tree failed. Expected return type int{} but got: " << tester.max_key() << endl;
    }
    
    //test zigzag tree
    tester.insert(10,12);
    tester.insert(3,17);
    tester.insert(7,13);
    if(tester.max_key() != 17){
        cout << "Max key on zigzag tree failed. Expected 17 but got: " << tester.max_key() << endl;
        cout << "From the tree: " << tester.to_string() << endl;
    }
}

void test_min_data(){
    BST<int, int> tester;
    if(tester.min_data() != int{}){
        cout << "Min data on an empty tree failed. Expected return type int{} but got: " << tester.min_data() << endl;
    }
    
    //test zigzag tree
    tester.insert(-10,-12);
    tester.insert(-3,-17);
    tester.insert(-7,-13);
    if(tester.max_data() != -3){
        cout << "Min data on zigzag tree failed. Expected -3 but got: " << tester.min_data() << endl;
        cout << "From the tree: " << tester.to_string() << endl;
    }
}

void test_min_key(){
    BST<int, int> tester;
    if(tester.min_key() != int{}){
        cout << "Min key on an empty tree failed. Expected return type int{} but got: " << tester.min_key() << endl;
    }
    
    //test zigzag tree
    tester.insert(-10,-12);
    tester.insert(-3,-17);
    tester.insert(-7,-13);
    if(tester.min_key() != -17){
        cout << "Min key on zigzag tree failed. Expected -17 but got: " << tester.min_key() << endl;
        cout << "From the tree: " << tester.to_string() << endl;
    }
}

void test_successor()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};

        BST<string, int> balanced_bst;

        for (int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }

        int succ = balanced_bst.successor(4);

        if (succ != 5){
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
        }

        succ = balanced_bst.successor(7);

        if (succ != 8) {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
        }
        // if successor 10 
        succ = balanced_bst.successor(10); 
        if (succ != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
    }
    catch (exception &e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }
}

void test_in_order()
{
    try
    {
        BST<string, int> bst;
        for (int i = 1; i <= 10; i++)
        {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_trim()
{
    try
    {
        // --- Test 1 ---
        BST<string, int> bst;

        int vals[3] = {1, 0, 2}; // to_string(): "1 0 2"
        for (int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i]) + " data", vals[i]);
        }

        bst.trim(1, 2); // [1,2]

        string bst_str = bst.to_string();

        if (bst_str != "1 2") 
        {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        
        // --- Test 2 ---
        BST<string, int> bst2;

        int vals2[5] = {3, 0, 4, 2, 1}; // to_string(): "3 0 4 2 1"
        for (int i = 0; i < 5; i++){
            bst2.insert(to_string(vals2[i]) + " data", vals2[i]);
        }

        bst2.trim(1, 3); // [1, 3]
        bst_str = bst2.to_string();
        if (bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }

        // --- Test 3: Removing root node and right subtree ---
        BST<string, int> bst3;
        int vals3[7] = {10, 5, 15, 3, 7, 12, 18}; // to_string(): "10 5 15 3 7 12 18"
        for (int i = 0; i < 7; i++)
        {
            bst3.insert(to_string(vals3[i]) + " data", vals3[i]);
        }
        bst3.trim(1, 9); // [1, 9]. New root should be 5.
        bst_str = bst3.to_string();
        if (bst_str != "5 3 7")
        {
            cout << "Incorrect tree after trimming (low) 10 5 15 3 7 12 18 with low=1, high=9. Expected 5 3 7 but got : " << bst_str << endl;
        }

        // --- Test 4: Removing root node and left subtree ---
        BST<string, int> bst4;
        int vals4[7] = {10, 5, 15, 3, 7, 12, 18}; // to_string(): "10 5 15 3 7 12 18"
        for (int i = 0; i < 7; i++)
        {
            bst4.insert(to_string(vals4[i]) + " data", vals4[i]);
        }
        bst4.trim(11, 20); // [11, 20], new root should be 15
        bst_str = bst4.to_string();
        if (bst_str != "15 12 18")
        {
            cout << "Incorrect tree after trimming (high) 10 5 15 3 7 12 18 with low=11, high=20. Expected 15 12 18 but got : " << bst_str << endl;
        }

        // --- Test 5: Removing all tree ---
        BST<string, int> bst5;
        int vals5[3] = {10, 5, 15}; // to_string(): "10 5 15"
        for (int i = 0; i < 3; i++)
        {
            bst5.insert(to_string(vals5[i]) + " data", vals5[i]);
        }
        bst5.trim(100, 200); // Out of range
        bst_str = bst5.to_string();
        if (bst_str != "") // Tree should be empty.
        {
            cout << "Incorrect tree after trimming all. Expected \"\" (empty string) but got : " << bst_str << endl;
        }

        // --- Test 6: Removing nothing ---
        BST<string, int> bst6;
        int vals6[3] = {10, 5, 15}; // to_string(): "10 5 15"
        for (int i = 0; i < 3; i++)
        {
            bst6.insert(to_string(vals6[i]) + " data", vals6[i]);
        }
        bst6.trim(1, 20); // All nodes are inside [1, 20]
        bst_str = bst6.to_string();
        if (bst_str != "10 5 15")
        {
            cout << "Incorrect tree after trimming nothing. Expected \"10 5 15\" but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

void test_usecase(){
    BST<string, string>* binHex = create_bst("binhex.txt");
    string bin = "";
    if(convert(binHex, bin) != ""){
        cout << "Usecase failed. Expected \"\" but got: " << convert(binHex, bin) << endl;
    }

    bin = "1";
    if(convert(binHex, bin) != "1"){
        cout << "Usecase failed. Expected \"1\" but got: " << convert(binHex, bin) << endl;
    }

    bin = "10011011110001001010010101011111000010100";
    if(convert(binHex, bin) != "1"){
        cout << "Usecase failed. Expected \"137894ABE14\" but got: " << convert(binHex, bin) << endl;
    }
}


int main(){

    test_empty();
    test_insert();
    test_get();
    test_remove();
    test_max_data();
    test_max_key();
    test_min_data();
    test_min_key();
    test_successor();
    test_in_order();
    test_trim();
    test_usecase();

    return 0;
}