#ifndef NEBUN_H
#define NEBUN_H
#include "Salahor.h"

class Harta;

class Nebun :public Salahor
{
    public:
        Nebun();
        ~Nebun();
        friend class Harta;
        bool VerificareImprejurari(const int x, const int y, char***Map);
        bool Strategie(int &x, int &y, char***Map);
};

#endif // NEBUN_H
