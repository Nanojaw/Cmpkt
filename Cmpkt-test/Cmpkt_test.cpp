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
    std::array<int, 10> lol{};
    lol.fill(269554195);

    cmpkt::Save(cmpkt::Serialize_Array(&lol[0], lol.size()), "data.txt");

    std::vector<int> test = cmpkt::Deserializer(cmpkt::Load("data.txt")).DeserializeIntArray(0);

    for (int i = 0; i < test.size(); i++) std::cout << test[i] << std::endl;

    return 0;
}