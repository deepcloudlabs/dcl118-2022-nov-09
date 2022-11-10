#include <iostream>

using namespace std;
struct A {
    static long long int x;    // declaration
    int z; // 4B
    short y; // 2B
    // 2B
    void fun(){}
    void gun(){}
    void sun(){}
};

struct B : public A {
    int z;
};

long long int A::x = 42; // definition -> Data

int main(){
    cout << "Size of A is " << sizeof(A) << endl;
    cout << "Size of B is " << sizeof(B) << endl;
    return 0;
}