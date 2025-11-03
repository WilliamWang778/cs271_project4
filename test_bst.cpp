#include <iostream>
#include "usecase.cpp"

using namespace std;



void test_empty(){
    try
    {
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
    catch (exception &e)
    {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_insert(){

}

void test_get(){

}

void test_remove(){

}

void test_max_data(){
    try
    {
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
    catch (exception &e)
    {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_max_key(){
    try
    {
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
    catch (exception &e)
    {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_min_data(){
    try
    {
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
    catch (exception &e)
    {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_min_key(){
    try
    {
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
    catch (exception &e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
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

void test_trim() {

    
}

void test_usecase(){
    try
    {
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
    catch (exception &e)
    {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
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