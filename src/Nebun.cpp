#include "Nebun.h"
#include "Harta.h"
Nebun::Nebun()
{
    //ctor
}

Nebun::~Nebun()
{
    //dtor
}


bool Nebun::VerificareImprejurari(const int x, const int y, char ***Map)
{
    if( ((*Map)[x-1][y-1] != ' ' && (*Map)[x-1][y-1] != 'C') && ((*Map)[x-1][y+1] != ' ' && (*Map)[x-1][y+1] != 'C') && ((*Map)[x+1][y-1] != ' ' && (*Map)[x+1][y-1] != 'C') && ((*Map)[x+1][y+1] != ' ' && (*Map)[x+1][y+1] != 'C') )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Nebun::Strategie(int &x, int &y, char ***Map)//Acest tip de salahor se misca doar pe diagonala atat timp cat poate si nu exista o comoara adiacenta pozitiei lui
{
    bool stepMade = false;
    int pas;
    do
    {
        pas = rand( ) % 5;
        switch (pas)
        {
            case 0:
            {
                this->Blocat = VerificareImprejurari(x, y, Map);
            }
            break;
            case 1:
            {
                stepMade = this->NordVest(x, y, Map);
            }
            break;
            case 2:
            {
                stepMade = this->NordEst(x, y, Map);
            }
            break;
            case 3:
            {
                stepMade = this->SudVest(x, y, Map);
            }
            break;
            case 4:
            {
                stepMade = this->SudEst(x, y, Map);
            }
            break;
        }
        if(this->Blocat == true)
        {
            break;
        }
    }while(!stepMade);
    return stepMade;
}

