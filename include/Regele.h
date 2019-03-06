#ifndef REGELE_H
#define REGELE_H
#include "Salahor.h"
class Harta;

class Regele :public Salahor
{
    public:
        Regele();
        virtual ~Regele();
        bool VerificareImprejurari(const int x, const int y, char***Map);
        bool Strategie(int &x, int &y, char***Map);

};

#endif // REGELE_H
