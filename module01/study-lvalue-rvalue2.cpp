#include <iostream>

using namespace std;
/*
void fun(int i){ // lvalue + rvalue
    cout << "fun(int i)" << endl;
} // by value
 */
void fun(int *p){
    cout << "fun(int *p)" << endl;
} // by pointer
void fun(int& i){ // lvalue
    cout << "fun(int&)" << endl;
} // by reference
void fun(int&& i){ // rvalue
    cout << "fun(int&&)" << endl;
} // by reference

int main(){ // Text
    int x = 3;
    int& y = x;
    // int& z = 42; // Error: by reference variable -> rvalue
    const int& t = 42; // It is OK now!
    fun(42);
    fun(&x);
    fun(x);
    return 0;
}
