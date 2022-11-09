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
    cout << "Hello Mars!" << endl;
}

int main() {
    thread t1(fun);
    auto tid = t1.native_handle();
    // http://binkurt.blogspot.com/2013/08/linuxda-pthread-kutuphanesi-ile-cok.html
    t1.join();
    cout << "Hello Jupiter" << endl;
    return 0;
}

