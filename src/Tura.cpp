#include "Tura.h"
#include "Harta.h"

Tura::Tura()
{
    //ctor
}

Tura::~Tura()
{
    //dtor
}


bool Tura::VerificareImprejurari(const int x,const int y,char ***Map)//Acest tip de salahor se misca doar pe orizontal si vertical atat timp cat poate si nu exista o comoara adiacenta pozitiei lui
{
    if( ((*Map)[x+1][y] != ' ' && (*Map)[x+1][y] != 'C') && ((*Map)[x][y-1] != ' ' && (*Map)[x][y-1] != 'C') && ((*Map)[x][y+1] != ' ' && (*Map)[x][y+1] != 'C') && ((*Map)[x-1][y] != ' ' && (*Map)[x-1][y] != 'C') )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tura::Strategie(int &x, int &y, char ***Map)
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
                stepMade = this->Nord(x, y, Map);
            }
            break;
            case 2:
            {
                stepMade = this->Est(x, y, Map);
            }
            break;
            case 3:
            {
                stepMade = this->Vest(x, y, Map);
            }
            break;
            case 4:
            {
                stepMade = this->Sud(x, y, Map);
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
