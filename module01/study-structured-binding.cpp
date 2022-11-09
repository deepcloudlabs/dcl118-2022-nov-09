#include <iostream>
#include <tuple>

using namespace std;
struct circle {
    double x, y, radius;
};

int main() {
    circle c1{1.0, 2.0, 100.0};
    cout << "x: " << c1.x
         << ",y: " << c1.y
         << ",radius: " << c1.radius
         << endl;
/*
    auto x = c1.x;
    auto y = c1.y;
    auto radius = c1.radius;
    */
    auto [x, y, radius] = c1;
    cout << "x: " << x
         << ",y: " << y
         << ",radius: " << radius
         << endl;
    tuple<double,double,double> c2{0.0,0.0,1.0};
    auto [x1,y1,r1] = c2;
    cout << "x: " << x1
         << ",y: " << y1
         << ",radius: " << r1
         << endl;
    array<double,3> my_array{100.0,200.0,300.0};
    auto [x2,y2,r2] = my_array;
    cout << "x: " << x2
         << ",y: " << y2
         << ",radius: " << r2
         << endl;

    return 0;
}
