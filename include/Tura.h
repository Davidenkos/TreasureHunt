#ifndef TURA_H
#define TURA_H
#include "Salahor.h"

class Harta;

class Tura :public Salahor
{
    public:
        Tura();
        virtual ~Tura();
        bool VerificareImprejurari(const int x,const int y,char***Map);
        bool Strategie(int &x,int &y,char***Map);

};

#endif // TURA_H
