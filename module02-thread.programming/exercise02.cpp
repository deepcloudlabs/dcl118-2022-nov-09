#include <thread>
#include <iostream>
#include <mutex>
#include <atomic>

int counter = 0; // Process' Data
// Thread-safe Application
// 1. Lock-based: mutex -> Thread Parking -> Voluntary Context-Switching
// /proc/<PID>/status
std::mutex mut;
// 2. Lock-free : atomic (CPU) -> does not require Thread Parking
std::atomic<int> atomic_counter(0);

void taska() {
    //std::cout << std::this_thread::get_id() << " is running the task..." << std::endl;
    for (auto i = 0; i < 100000; ++i) {
        // critical section -> mutual exclusion
        // 1. std::lock_guard<std::mutex> lock(mut);
        // counter++;
        atomic_counter++;
    }
    std::cout << std::this_thread::get_id() << " is done." << std::endl;
}

struct Task {
    int *p;

    Task() {
        p = new int(0);
    }

    Task(const Task &other) {
        this->p = new int(0);
        this->p[0] = other.p[0];
    }

    Task(Task &&other) {
        this->p = other.p;
        other.p = nullptr;
    }

    int getValue() {
        if (p != nullptr)
            return *p;
    }

    ~Task() {
        if (p != nullptr)
            delete p;
    }

    void operator()() {
        for (auto i = 0; i < 100000; ++i) {
            (*p)++;
        }
    }
};

int main() {
    std::cout << "Application is started" << std::endl;
    std::thread t1(taska);
    std::thread t2(taska);
    std::thread t3(taska);
    t1.join();
    t2.join();
    t3.join();
    // std::cout << counter << std::endl;
    std::cout << atomic_counter << std::endl;
    std::cout << "Application is done" << std::endl;
    return 0;
}
