#pragma once

class cVector3
{
public:
    //Data ---
    float** Xyz;
    float* X;
    float* Y;
    float* Z;

    //Memory Stuff
    void Cm();
    void Em();
    void Dm() const;

    //Constructors --- Create Constructors
    cVector3();
    cVector3(const float& x, const float& y, const float& z);
    cVector3(const float& scalar);

    //Constructors --- Utility Constructors
    cVector3(const cVector3& source);
    cVector3(const cVector3&& source);

    
};
