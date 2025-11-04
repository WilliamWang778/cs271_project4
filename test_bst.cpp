#include <iostream>
#include <climits> 
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
        cerr << "Error testng empty from bst : " << e.what() << endl;
    }
}

void test_insert()
{
    try
    {
        // insert into empty tree
        BST<string, int> bst;
        bst.insert("two", 2);
        string bst_str = bst.to_string();
        if (bst_str != "2")
        {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }

        // decreasing keys 
        BST<string, int> dec_bst;
        for (int i = 10; i >= 1; --i)
        {
            dec_bst.insert("v", i);
        }
        bst_str = dec_bst.to_string();
        if (bst_str != "10 9 8 7 6 5 4 3 2 1")
        {
            cout << "Incorrect result of inserting keys 10..1 in order. Expected 10 9 8 7 6 5 4 3 2 1 but got : " << bst_str << endl;
        }

        // duplicates 
        BST<string, int> dup_bst;
        dup_bst.insert("a", 5);
        dup_bst.insert("b", 3);
        dup_bst.insert("c", 7);
        dup_bst.insert("d", 3);
        dup_bst.insert("e", 3);
        dup_bst.insert("f", 7);
        bst_str = dup_bst.to_string();
        if (bst_str != "5 3 7 3 7 3")
        {
            cout << "Incorrect result for duplicates. Expected 5 3 7 3 7 3 but got : " << bst_str << endl;
        }

        // negatives, zero, positives
        BST<string, int> mix_bst;
        int mix_vals[] = {0, -10, 10, -5, 5, -15, 15};
        for (int i = 0; i < 7; ++i)
        {
            mix_bst.insert("x", mix_vals[i]);
        }
        bst_str = mix_bst.to_string();
        if (bst_str != "0 -10 10 -15 -5 5 15")
        {
            cout << "Incorrect result for negatives/zero/positives. Expected 0 -10 10 -15 -5 5 15 but got : " << bst_str << endl;
        }

        // Data=float, Key=int
        {
            BST<float, int> t;
            t.insert(3.14f, 1);
            t.insert(2.71f, 2);
            t.insert(1.41f, 3);
            string s = t.to_string();
            if (s != "1 2 3") {
                cout << "float/int failed. Expected 1 2 3 but got: " << s << endl;
            }
        }

        // Data=bool, Key=int
        {
            BST<bool, int> t;
            t.insert(true, 10);
            t.insert(false, 5);
            t.insert(true, 20);
            string s = t.to_string();
            if (s != "10 5 20") {
                cout << "bool/int failed. Expected 10 5 20 but got: " << s << endl;
            }
        }

        // Data=char, Key=int
        {
            BST<char, int> t;
            t.insert('a', 2);
            t.insert('b', 1);
            t.insert('c', 3);
            string s = t.to_string();
            if (s != "2 1 3") {
                cout << "char/int failed. Expected 2 1 3 but got: " << s << endl;
            }
        }

        // Data=int, Key=char, ASCII order
        {
            BST<int, char> t;
            t.insert(30, 'c');
            t.insert(10, 'a');
            t.insert(20, 'b');
            t.insert(40, 'd');
            string s = t.to_string();
            if (s != "c a d b") {
                cout << "int/char failed. Expected c a d b but got: " << s << endl;
            }
        }

        // Data=string, Key=bool
        {
            BST<string, bool> t;
            t.insert("F", false);
            t.insert("T1", true);
            t.insert("T2", true);
            string s = t.to_string();
            if (s != "0 1 1") {
                cout << "string/bool failed. Expected 0 1 1 but got: " << s << endl;
            }
        }

        // Data=string, Key=int with INT_MAX and negatives
        {
            BST<string, int> t;
            t.insert("neg", -5);
            t.insert("zero", 0);
            t.insert("max", INT_MAX);
            string s = t.to_string();
            string exp = string("-5 0 ") + to_string(INT_MAX);
            if (s != exp) {
                cout << "string/int with INT_MAX failed. Expected "
                     << exp << " but got: " << s << endl;
            }
        }

        // Data=int, Key=string  
        {
            BST<int, string> t;
            t.insert(2, "two");
            t.insert(1, "one");
            t.insert(3, "three");
            string s = t.to_string();
            if (s != "two one three") {
                cout << "int/string failed. Expected two one three but got: " << s << endl;
            }
        }

        // Data=string, Key=char with duplicates 
        {
            BST<string, char> t;
            t.insert("B1", 'b');
            t.insert("A",  'a');
            t.insert("B2", 'b');
            t.insert("B3", 'b');
            string s = t.to_string();
            if (s != "b a b b") {
                cout << "string/char duplicates failed. Expected b a b b but got: " << s << endl;
            }
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
        // basic empty tree 
        {
            BST<string, int> bst;
            string val = bst.get(0);
            if (val != "")
            {
                cout << "Incorrect get from empty BST. Expected \"\" but got: " << val << endl;
            }
        }

        // basic
        {
            BST<string, int> bst;
            bst.insert("two", 2);
            string val = bst.get(2);
            if (val != "two")
            {
                cout << "Incorrect get result. Expected \"one\" but got: " << val << endl;
            }
        }


        // duplicates. get() should return the earliest inserted.
        {
            BST<string, int> bst;
            bst.insert("first", 4);
            bst.insert("second", 4);
            bst.insert("third", 4);
            string val = bst.get(4);
            if (val != "first")
            {
                cout << "Incorrect get with duplicates. Expected \"first\" but got: " << val << endl;
            }
        }

        // Data=int, Key=string
        {
            BST<int, string> bst;
            bst.insert(2, "two");
            bst.insert(1, "one");
            bst.insert(3, "three");

            int v1 = bst.get(string("two"));
            if (v1 != 2)
            {
                cout << "get(string key) failed. Expected 2 but got: " << v1 << endl;
            }

            int v_missing = bst.get(string("zzz")); 
            if (v_missing != 0)
            {
                cout << "get(missing string key) failed. Expected 0 but got: " << v_missing << endl;
            }
        }

        // Data=bool, Key=int
        {
            BST<bool, int> bst;
            bst.insert(true, 10);
            bst.insert(false, 5);

            bool b1 = bst.get(5);
            if (b1 != false)
            {
                cout << "get(bool data) failed. Expected false but got true" << endl;
            }

            bool b_missing = bst.get(7); 
            if (b_missing != false)
            {
                cout << "get(default bool) failed. Expected false but got true" << endl;
            }
        }

        // Data=float, Key=int 
        {
            BST<float, int> bst;
            bst.insert(3.5f, 1);
            bst.insert(2.0f, 2);

            float f1 = bst.get(1);
            if (f1 != 3.5f)
            {
                cout << "get(float) failed. Expected 3.5 but got: " << f1 << endl;
            }

            float f_missing = bst.get(99); 
            if (f_missing != 0.0f)
            {
                cout << "get(default float) failed. Expected 0.0 but got: " << f_missing << endl;
            }
        }

        // negatives and INT_MAX keys
        {
            BST<string, int> bst;
            bst.insert("neg", -5);
            bst.insert("zero", 0);
            bst.insert("max", INT_MAX);

            string a = bst.get(-5);
            string b = bst.get(0);
            string c = bst.get(INT_MAX);
            string d = bst.get(INT_MAX - 1); 

            if (a != "neg")   cout << "get(-5) failed. Expected \"neg\" but got: " << a << endl;
            if (b != "zero")  cout << "get(0) failed. Expected \"zero\" but got: " << b << endl;
            if (c != "max")   cout << "get(INT_MAX) failed. Expected \"max\" but got: " << c << endl;
            if (d != "")      cout << "get(INT_MAX-1) failed. Expected \"\" but got: " << d << endl;
        }


        
    }
    catch (exception &e)
    {
        cerr << "Error in getting data from bst: " << e.what() << endl;
    }
}



void test_remove()
{
    try
    {
        // remove from empty (no crash, still empty)
        {
            BST<string, int> bst;
            bst.remove(42);
            string s = bst.to_string();
            if (s != "")
            {
                cout << "Expected \"\" but got: " << s << endl;
            }
        }

        // leaf removal 
        {
            BST<string, int> bst;
            bst.insert("v", 2);
            bst.insert("v", 1);
            bst.insert("v", 3);
            bst.remove(1);
            string in = bst.in_order();
            if (in != "2 3")
            {
                cout << "Expected \"2 3\" but got: " << in << endl;
            }
        }

        // one child 
        {
            BST<string, int> bst;
            bst.insert("v", 1);
            bst.insert("v", 2);
            bst.insert("v", 3);
            bst.remove(2);
            string in = bst.in_order();
            if (in != "1 3")
            {
                cout << "Expected \"1 3\" but got: " << in << endl;
            }
        }

        // two children, successor is immediate right child 
        {
            BST<string, int> bst;
            bst.insert("v", 2);
            bst.insert("v", 1);
            bst.insert("v", 3);
            bst.remove(2);
            string in = bst.in_order();
            if (in != "1 3")
            {
                cout << "Expected \"1 3\" but got: " << in << endl;
            }
        }

        // two children, successor deeper in right subtree 
        {
            BST<string, int> bst;
            int vals[] = {5, 2, 8, 1, 3, 7, 9, 6};
            int n = sizeof(vals) / sizeof(vals[0]);
            for (int i = 0; i < n; i++)
            {
                bst.insert("v", vals[i]);
            }
            bst.remove(5);
            string in = bst.in_order();
            if (in != "1 2 3 6 7 8 9")
            {
                cout << "Expected \"1 2 3 6 7 8 9\" but got: " << in << endl;
            }
        }

        // remove non-existent key 
        {
            BST<string, int> bst;
            bst.insert("v", 1);
            bst.insert("v", 2);
            bst.insert("v", 3);
            string before = bst.in_order();
            bst.remove(99);
            string after = bst.in_order();
            if (before != after)
            {
                cout << "Tree changed unexpectedly. Before: "
                     << before << " After: " << after << endl;
            }
        }

        // remove roots repeatedly until empty
        {
            BST<string, int> bst;
            int vals[] = {4, 2, 6, 1, 3, 5, 7};
            int n = sizeof(vals) / sizeof(vals[0]);
            for (int i = 0; i < n; i++)
            {
                bst.insert("v", vals[i]);
            }

            int order[] = {4, 5, 6, 7, 3, 2, 1};
            int m = sizeof(order) / sizeof(order[0]);
            for (int i = 0; i < m; i++)
            {
                bst.remove(order[i]);
            }

            string in = bst.in_order();
            if (in != "")
            {
                cout << "Expected empty tree but got: " << in << endl;
            }
        }

        // duplicates remove same key 3 times
        {
            BST<string, int> bst;
            bst.insert("a", 4);
            bst.insert("b", 4);
            bst.insert("c", 4);

            bst.remove(4);
            string in1 = bst.in_order();
            if (in1 != "4 4")
            {
                cout << "Expected \"4 4\" but got: " << in1 << endl;
            }

            bst.remove(4);
            string in2 = bst.in_order();
            if (in2 != "4")
            {
                cout << "Expected \"4\" but got: " << in2 << endl;
            }

            bst.remove(4);
            string in3 = bst.in_order();
            if (in3 != "")
            {
                cout << "Expected \"\" but got: " << in3 << endl;
            }
        }

        // remove min and max
        {
            BST<string, int> bst;
            int vals[] = {-10, -5, 0, 5, 10};
            int n = sizeof(vals) / sizeof(vals[0]);
            for (int i = 0; i < n; i++)
            {
                bst.insert("v", vals[i]);
            }

            bst.remove(-10); 
            string in1 = bst.in_order();
            if (in1 != "-5 0 5 10")
            {
                cout << "Expected \"-5 0 5 10\" but got: " << in1 << endl;
            }

            bst.remove(10); 
            string in2 = bst.in_order();
            if (in2 != "-5 0 5")
            {
                cout << "Expected \"-5 0 5\" but got: " << in2 << endl;
            }
        }


        
    }
    catch (exception &e)
    {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
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
        cerr << "Error getting max data from bst : " << e.what() << endl;
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
        cerr << "Error getting max key from bst : " << e.what() << endl;
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
        if(tester.min_data() != -3){
            cout << "Min data on zigzag tree failed. Expected -3 but got: " << tester.min_data() << endl;
            cout << "From the tree: " << tester.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting min data from bst : " << e.what() << endl;
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
        cerr << "Error getting min key from bst : " << e.what() << endl;
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
    try
    {
        BST<string, string>* binHex = create_bst("binhex.txt");
        //test empty
        string bin = "";
        if(convert(binHex, bin) != ""){
            cout << "Usecase failed. Expected \"\" but got: " << convert(binHex, bin) << endl;
        }

        //test lacking 0's
        bin = "1";
        if(convert(binHex, bin) != "1"){
            cout << "Usecase failed. Expected \"1\" but got: " << convert(binHex, bin) << endl;
        }

        //test lacking 0's and is long
        bin = "10011011110001001010010101011111000010100";
        if(convert(binHex, bin) != "137894ABE14"){
            cout << "Usecase failed. Expected \"137894ABE14\" but got: " << convert(binHex, bin) << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error usecase from bst : " << e.what() << endl;
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

    cout << "Testing completed" << endl;

    return 0;
}