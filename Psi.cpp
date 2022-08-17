#include "Psi.h"

Psi::Psi()
{
    name = "";
    penPos = 0;
    penNeg = 0;
}

Psi::Psi(string name1, int pos, int neg)
{
    this->name = name1;
    this->penPos = pos;
    this->penNeg = neg;
}

Psi::Psi(string name, int pos, int neg, string Eff, string Status)
{

}

int Psi::getNeg()
{
    return penNeg;
}

int Psi::getPos()
{
    return penPos;
}

string Psi::getName()
{
    return name;
}

void Psi::setNeg(int s)
{
    penNeg = s;
}

void Psi::setPos(int s)
{
    penPos = s;
}

void Psi::setName(string sd)
{
    name = sd;
}

int Psi::psiCalc(int p, int n, int t)
{
    int mod{};
    t -= n;
    t += p;

    if (t <= n||t >= p)
    {
        mod = 0;
    }

    if (t == n + 1 || t == p - 1) // danger zone
    {
        mod %= t * p + n; // critical mass
    }

    if (t > n && t < p && t == *new int((p + n) / 2)) // perfect zen
    {
        mod += t * p; // fck yea
        mod -= t * n;
    }

    if (t > n && t < p)
    {
        mod = t;
    }

    return mod;
}

int Psi::turnsOE(int pCalc, int n, int p)
{       
    pCalc %= p * pCalc * n;
    
    return pCalc;
}
