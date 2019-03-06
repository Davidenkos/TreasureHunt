#ifndef SALAHOR_H
#define SALAHOR_H

#include <stdbool.h>
#include <time.h>
#include <vector>

class Harta;

class Salahor
{
    protected:
    int x,y;
    bool Winner,Blocat;
    public:
        Salahor();
        ~Salahor();
        int getX();
        int getY();
        bool Nord(int &x, int &y, char ***Harta);
        bool NordEst(int &x, int &y, char ***Harta);
        bool NordVest(int &x, int &y, char ***Harta);
        bool Est(int &x, int &y, char ***Harta);
        bool Vest(int &x, int &y, char ***Harta);
        bool SudEst(int &x, int &y, char ***Harta);
        bool SudVest(int &x, int &y, char ***Harta);
        bool Sud(int &x, int &y, char ***Harta);
        void setPosition(const int & x, const int & y);
        friend class Harta;
        virtual bool VerificareImprejurari(const int x, const int y, char***Harta) = 0;
        virtual bool Strategie(int &x, int&y, char*** Harta) = 0;


};

#endif // SALAHOR_H
