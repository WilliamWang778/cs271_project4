
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "bst.cpp"

using namespace std;


void test_insert()
{
    try
    {
        BST<string, int> bst;
        bst.insert("one", 1);
        string bst_str = bst.to_string();
        if (bst_str != "1")
        {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        for (int i = 2; i <= 10; i++)
        {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if (bst_str != "5 2 7 1 3 6 9 4 8 10")
        {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_get()
{
    try
    {
        BST<string, int> bst;
        string val = bst.get(0);
        if (val != "")
        {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert("one", 1);
        val = bst.get(1);
        if (val != "one")
        {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}

void test_remove()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7);
        string bst_str = balanced_bst.to_string();
        if (bst_str != "5 2 8 1 3 6 9 4 10")
        {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}



int main()
{

    string file_name = "usecase.cpp";
    cout << endl
         << "Running tests for " << file_name << endl
         << endl;

    //test_empty();
    test_insert();
    test_get();
    test_remove();
    // test_max_data();
    // test_max_key();
    // test_min_data();
    // test_min_key();
    // test_successor();
    // test_in_order();
    // test_trim();
    // test_binhex();

    cout << "Testing completed" << endl;

    return 0;
}