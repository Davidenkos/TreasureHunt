#ifndef INUTILUL_H
#define INUTILUL_H
#include "Salahor.h"

class Harta;

class Inutilul :public Salahor
{
    public:
        Inutilul();
        virtual ~Inutilul();
        friend class Harta;
        bool VerificareImprejurari(const int x, const int y, char***Map);
        bool Strategie(int &x, int &y, char***Map);
};

#endif // INUTILUL_H
