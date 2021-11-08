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
    
    std::array<int, 10> lol{};
    lol.fill(1);
    auto large = cObject(10, lol);
    
    auto binary = std::string("lol");
    auto filename = std::string("data");
    auto lel = long double(5.234312323445346554367457884655);

    cmpkt::serialize_primitives(lel);

    return 0;
}