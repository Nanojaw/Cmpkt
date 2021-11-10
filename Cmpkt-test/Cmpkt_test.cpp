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
    lol.fill(269554195);

    const auto pair = cmpkt::Deserializer(cmpkt::Serialize_Array(&lol[0], lol.size())).DeserializeIntArray(0);

    for (int i = 0; i < pair.second; i++)
    {
        std::cout << pair.first[i] << std::endl;
    }

    delete[] pair.first; // delete the array

    return 0;
}