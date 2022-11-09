#include <iostream>

class A {
public:
    explicit A(int u){
        std::cout << "A:A(int u)" << std::endl;
    }
    A(int a,int b){
        std::cout << "A:A(int x,int y)" << std::endl;
    }

};
void fun(A a){}
int main(){
    A a0{1};
    A a1(1,2);
    A a2{1,2};
    A a3 = {1,2};
    // after explicit: the following lines are all error!
    /*
    A a4 = 42;
    A a5 = {42};
    fun(42);
    fun({42})
     */
    return 0;
}