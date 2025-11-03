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

void test_successor(){

}

void test_in_order(){

}

void test_trim(){

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