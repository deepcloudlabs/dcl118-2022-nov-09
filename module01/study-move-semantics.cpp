#include <iostream>

using namespace std;

class A {
    // Pointer to VT: 8-byte
    int *p; // 8-Byte
    byte b1; // 1-Byte
    byte b2;
    int *q;
    // padding: 7-Byte
public:
    /*
     *     0: A::fun
     *     1: A::gun
     *     2: A::sun
     */
    virtual void fun(){} // 0
    virtual void gun(){} // 1
    virtual void sun(){}  // 2
    A(int x=0) {
        p = new int{x};
        cout << "A::A(int)" << endl;
    }

    // Copy Constructor : lvalue
    A(const A &right) {
        // p = right.p; // default: shallow copy
        this->p = new int{right.p[0]}; // deep copy
        cout << "A::A(const A &right)" << endl;
    }

    // since C++11: rvalue
    A(A &&right) { // Move Constructor
       this->p = right.p;
       right.p = nullptr;
        cout << "A::A(A &&right)" << endl;
    }

    // Assignment Operator
    A &operator=(A &right) { // l-value
        this->p[0] = right.p[0];
        cout << "A::operator=(A &right)" << endl;
       return *this;
    }
    A &operator=(A&& right) { // r-value
        this->p = right.p;
        right.p = nullptr;
        cout << "A::operator=(A &right)" << endl;
       return *this;
    }

    // Destructor
    ~A() {
        delete p;
        cout << "A::~A()" << endl;
    }
};
class B : public A {
    /*
     *     0: A::fun
     *     1: B::gun
     *     2: A::sun
     */
public:
    void gun() override {

    }
};
int main() {
    A *p = new B{};
    p->gun(); // Late-Binding -> Run-time
              // 1) address = p[0] + Offset(gun) * 8
              //    jsr address
    A a1{42}; // A::A(int)
    a1.gun(); // static-binding A::gun
    cout << sizeof(a1) << endl;
    A a2 = a1; // Copy constructor
    A a3 = move(a1); // Move Constructor
    A a4(move(a2)); // Move Constructor
    A a5{move(a3)}; // Move Constructor

    return 0;
}

template <typename T>
void swap(T& u, T& v){
    T temp{move(u)};
    u = move(v);
    v = move(temp);
}