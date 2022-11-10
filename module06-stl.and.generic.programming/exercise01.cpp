#include <iostream>
#include <vector>
#include <parallel/numeric>
#include <list>
#include <algorithm>

using namespace std;
int my_global_state;

bool isEvenNumber(int number) { // has side-effect!
    my_global_state++;
    return number % 2 == 0;
}

struct Even {
    int counter;
    bool operator()(int number) {
        counter++; // has side-effect!
        return number % 2 == 0;
    }
};

int main() {
    list<int> numbers{4, 8, 15, 16, 23, 42};
    auto sum = 0;
    // 1. for loop: external to the container using iterator
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
        auto number = *iter;
        if (number % 2 == 0) {
            auto cube = number * number * number;
            sum += cube;
        }
    }
    cout << "Sum of cubes of even numbers is "
         << sum
         << endl;
    // 2. for-each: external to the container
    sum = 0;
    for (const auto &number: numbers) {
        if (number % 2 == 0) {
            auto cube = number * number * number;
            sum += cube;
        }
    }
    cout << "Sum of cubes of even numbers is "
         << sum
         << endl;
    // 3. stl algorithm: accumulate -> internal loop
    sum = accumulate(numbers.begin(), numbers.end(), int{0},minus<int>());
    cout << "Sum of numbers is "
         << sum
         << endl;
    // auto numberOfEvens = count_if(numbers.begin(),numbers.end(),Even());
    // auto numberOfEvens = count_if(numbers.begin(), numbers.end(), isEvenNumber);
    auto isEvenNumberLambda = [](auto number) { return number % 2 == 0; };
    // count_if / accumulate / equal / for_each / ...
    // 1) higher-order function
    // 2) pure function has NO side effect! -> lambda expression
    // 3) Immutable Data Structures
    auto numberOfEvens = count_if(numbers.begin(), numbers.end(),isEvenNumberLambda);
    cout << "Number of even numbers is "
         << numberOfEvens
         << endl;
    return 0;
}
