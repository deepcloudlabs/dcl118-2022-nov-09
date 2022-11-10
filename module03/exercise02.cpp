#include <iostream>

int main() {
    /**
    for (auto i=0;i< 99999999; ++i){
        try{
            int *p = new int[99999999];
        } catch (std::bad_alloc e){
            std::cerr << "Cannot allocate memory: " << e.what() << std::endl;
        }
    }
     */
     const std::nothrow_t t;
    for (auto i=0;i< 99999999; ++i) {
        int *p = new(t) int[99999999999];
        if (p== nullptr){
            std::cerr << "Cannot allocate memory!" << std::endl;
            break;
        }
    }
    return 0;
}
