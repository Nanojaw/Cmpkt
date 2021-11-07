#pragma once

// ReSharper disable once IdentifierTypo
// ReSharper disable once CppInconsistentNaming
class cmpkt
{
public:
    static void Save(std::string& binary, std::string& filename)
    {
        std::cout << filename << ": " << binary << std::endl;
    }
    // TODO make functions for serializing primitive types
};
