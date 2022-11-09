class A { // Declaration
public:
    A(int x){}
    int gun(){return 42;} // Text
};

A a = 42; // Data

int fun(){ // Text
    static int i= 42; // Data
    int j = 108; // Stack
    return 42;
}

int& run(int array[6]){
   return array[0];
}

// l-value -> compiler allocates memory cells
int i = 1; // Data
int *p = // Data
        new int(42); // Heap

auto sun = [](int u,int v){return u*v;};
// r-value
// i+42 = 4;

int main(){ // Text
    // i+2 -> r-value -> has no memory allocated
    // int *q = &(i+2); // Error
    // sun(1,2) = 42; // sun(1,2) is r-value
    // fun() = 42;    // fun() is r-value
    int my_array[] = {4,8,15,16,23,42};
    run(my_array) = 42; // l-value
    my_array[0] = 12;
    return 0;
}
