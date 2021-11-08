#include <array>
#include <iostream>
#include "cmpkt.h"

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
    
    std::array<int, 100> lol{};
    lol.fill(100);
    
    std::cout << cmpkt::serialize_array(&lol[0], lol.size()) << std::endl;

    return 0;
}