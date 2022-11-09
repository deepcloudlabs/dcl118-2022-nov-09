#include <initializer_list>
#include <iostream>

struct A {
    int u;
    double v;

    A(int u, double v) : u(u), v(v) {}
};

struct B {
    int x,y;
    B(int x,int y): x(x), y(y){
        std::cout << "B:B(int x,int y)" << std::endl;
    }
    B(std::initializer_list<int>){
        std::cout << "B:B(std::initializer_list<int>)" << std::endl;
    }
};

void print(std::initializer_list<int> values){
    for (auto p=values.begin(); p!= values.end(); ++p){
        std::cout << *p << std::endl;
    }
}

int main() {
    int i;
    double j{}; // 0.0
    int *p;
    int *q{}; // nullptr

    int x1(5.34); // x1 -> 5
    int x2 = 5.34; // x2 -> 5

    // int x3{5.0}; // Error: {5.0} narrowing!
    char c1{56}; // it is OK
    char c2 = 1.57e23;
    char c3 = 99999;
    // char c2{99999}; // Error: value narrowing!

    short lost[6]{4, 8, 15, 16, 23, 42}; // Stack
    int *primes = new int[6]{2, 3, 5, 7, 11, 13}; // Heap
    A a1(2,3);
    A a2(2.5,3);
    A a3{2,3};
    // A a4{2.5,3}; // Error: narrowing
    print({4,8,15,16,23,42});
    print({});
    B b1(1.2,2);
    // B b2({1.2,2}); // Error: narrowing
    B b3{1,2};
    B b4({1,2});
    B b5 = {1,2};
    B b6{1,2,3,4,5,6};
    return 0;
}

