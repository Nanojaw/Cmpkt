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
    void Dm();
};
