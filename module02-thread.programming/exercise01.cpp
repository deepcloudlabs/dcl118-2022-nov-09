// Program
// User: Application -> Multi-tasking
//                      i) Child Process (Heap, Stack, Text, Data)
//                     ii) Thread        (Stack), Process (Heap, Text, Data)
// OS  : Process -> CPU + Memory (Heap, Stack, Text, Data)
// 1) Multi-Process, IPC
// 2) Single Process, Multiple-Thread, Multi-Core Parallel Programming
// 3) MP-MT

#include <iostream>
#include <thread>

using namespace std;

void fun(){
    // static int z = 1; // Process' Data
    int x{};
    int *p = new int{42}; // Process' Heap
    cout << "Hello Mars!" << endl;
    delete p;
}

struct TaskA { // state
    int y;
    void operator()(){
        int x{};
       cout << "Hello Moon!" << endl;
    }
};

int main() {
    int x{}; // process' stack
    cout << "Application is just started!" << endl;
    // 1. c-like function
    thread t1(fun); // fun's x -> t1's stack
    thread t4(fun); // fun's x -> t4's stack
    // 2. operator() -> struct -> object -> functor
    TaskA aTask;
    thread t2(aTask); // operator()'s x -> t2's stack
    // 3. lambda expression
    thread t3([](){
        int x{}; // t's stack
       cout << "Hello Sun!" << endl;
    });
    // auto tid = t1.native_handle();
    // http://binkurt.blogspot.com/2013/08/linuxda-pthread-kutuphanesi-ile-cok.html
    t1.join();
    t2.join();
    t3.join();
    cout << "Application is done." << endl;
    return 0;
}

