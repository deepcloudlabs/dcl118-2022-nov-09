#include <iostream>
#include <thread>
#include <future>

long sequence(long n) {
    auto step = 0L;
    while (n > 1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        step++;
    }
    std::cout << std::this_thread::get_id() << " is done." << std::endl;
    return step;
}

std::future<long> async_sequence(long n) {
    return std::async(sequence,n);
}

int main(){ // async/await
    std::cout << "# of  logical processors: "
              << std::thread::hardware_concurrency()
              << std::endl;
    std::future<long> result1 = std::async(sequence,17);
    std::future<long> result2 = std::async(sequence,19);
    // Do important stuff...
    std::cout << result1.get() << std::endl;
    std::cout << result2.get() << std::endl;

    std::cout << async_sequence(17).get() << std::endl;
    return 0;
}