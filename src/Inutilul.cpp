#include "Inutilul.h"
#include "Harta.h"

Inutilul::Inutilul()
{
    //ctor
}

Inutilul::~Inutilul()
{
    //dtor
}


bool Inutilul::VerificareImprejurari(const int x, const int y, char ***Map)
{
    if( ((*Map)[x+1][y] != ' ' && (*Map)[x+1][y] != 'C') && ((*Map)[x+1][y-1] != ' ' && (*Map)[x+1][y-1] != 'C') && ((*Map)[x+1][y+1] != ' ' && (*Map)[x+1][y+1] != 'C') )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Inutilul::Strategie(int &x, int &y, char ***Map)//Din lipsa de inspiratie am facut ca acest tip de salahor sa se miste spre nord de fiecare data cand are ocazia
{
    bool stepMade = false;
    int pas;
    do
    {
        pas = rand( ) % 4;
        switch (pas)
        {
            case 0:
            {
                this->Blocat = VerificareImprejurari(x,y,Map);
            }
            break;
            case 1:
            {
                stepMade = this->Nord(x, y, Map);
            }
            break;
            case 2:
            {
                stepMade = this->NordVest(x, y, Map);
            }
            break;
            case 3:
            {
                stepMade = this->NordEst(x, y, Map);
            }
            break;
        }
        if(this->Blocat == true)
        {
            break;
        }
    }while (!stepMade);
    return stepMade;
}
