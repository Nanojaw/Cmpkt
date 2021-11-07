#include <array>
#include <iostream>
#include "Cmpkt.h"

class cObject
{
public:
    int V1;
    std::array<int, 10> V2;

public:
    cObject() : V1(0), V2(std::array<int, 10>()) {}
    cObject(const int v1, const std::array<int, 10> v2) : V1(v1), V2(v2) {}
};

int main()
{
    auto test = cObject();
    std::cout << sizeof test << std::endl;
    std::array<int, 10> lol{};
    lol.fill(1);

    cmpkt().Save("lol", 2);

    auto large = cObject(10, lol);
    std::cout << sizeof large << std::endl;
    return 0;
}