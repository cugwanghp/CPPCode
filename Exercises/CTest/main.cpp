#include <iostream>
#include <memory>

int main(){
    unique_ptr<int> p1(nullptr);
    unique_ptr<int> p2(new int{10});

    p1 = std::move(p2); // p1 now owns the memory, p2 is nullptr
    if (p2 != nullptr) {
        std::cout << "p2 is not nullptr" << std::endl;
    }
    if (p1 != nullptr) {
        std::cout << "p1 is not nullptr" << std::endl;
    }

    return 0;
}