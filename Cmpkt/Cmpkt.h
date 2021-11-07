#pragma once
#include <string>

// ReSharper disable once IdentifierTypo
// ReSharper disable once CppInconsistentNaming
class cmpkt
{
public:
    template<typename C>
    void Save(std::string filename, C);
    template<typename C>
    void Read(std::string filename, C*);
};
