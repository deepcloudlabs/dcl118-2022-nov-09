#include <memory>
#include <vector>

using namespace std;

int fun(){return 42;}
double gun(int x,short y){ return x+y;}

int main(){
    int x = 42;
    auto i = x;
    auto j = fun();
    static const auto k= 42;
    auto run = gun; // double (*)(int x,short y)
    vector<shared_ptr<int>> w;
    vector<shared_ptr<int>>::iterator pos1 = w.begin();
    auto pos2 = w.begin();
    auto sun = [](int x) -> bool {
        return true;
    };
    for (shared_ptr<int>& u : w){

    }
    for (auto u : w){

    }
    sun(42);
    for (auto& i : {4.2,8.3,15.4,16.3,23.5,42.6}){

    }
    int array[] = {4,8,15,16,23,42};
    auto sum = 0;
    for (auto x : array)
        sum += x;
    return 0;
}
