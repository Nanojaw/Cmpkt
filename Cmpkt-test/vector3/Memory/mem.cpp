#include "../Vector3.h"

void cVector3::Cm()
{
    Xyz = new float*[3];
    Xyz[0] = new float;
    Xyz[1] = new float;
    Xyz[2] = new float;

    X = Xyz[0];
    Y = Xyz[1];
    Z = Xyz[2];
}

void cVector3::Em()
{
    Cm();
}

void cVector3::Dm() const
{
    delete[] Xyz;

    delete X;
    delete Y;
    delete Z;
}
