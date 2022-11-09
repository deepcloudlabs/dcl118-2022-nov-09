struct A {
    A (int x){}
    A (double x)=delete;
    A(const A& a) = delete;
    A& operator=(const A& a)=delete;
    void fun(){}
};

int main(){
    A a1(42), a2({42}), a3{42};
    // a1 = a2;
    // A a4 = a1;
    // A a5(a1);
    // A a6{a1};
    return 0;
}