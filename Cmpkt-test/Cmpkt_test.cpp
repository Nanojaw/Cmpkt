#include <iostream>
#include <vector>


class cObject
{
public:
    int V1;
    std::vector<int> V2;

public:
    cObject() : V1(0), V2(std::vector<int>(0)) {}
    cObject(const int v1, std::vector<int>& v2) : V1(v1), V2(v2) {}
};

int main()
{
    cObject test = cObject();
    std::cout << sizeof test;
    std::vector<int> lol (10, 2);
    cObject large = cObject(10, lol);
    std::cout << sizeof large;
    return 0;
}