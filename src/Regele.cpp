#include "Regele.h"
#include "Harta.h"

Regele::Regele()
{
    //ctor
}

Regele::~Regele()
{
    //dtor
}

bool Regele::VerificareImprejurari(const int x,const int y,char ***Map)
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

bool Regele::Strategie(int &x,int &y,char ***Map)//Acest tip de salahor se misca in orice directie
{
    bool stepMade=false;
    int pas;
    do
    {
        pas = rand( ) % 9;
        switch (pas)
        {
            case 0:
            {
                this->Blocat=VerificareImprejurari(x,y,Map);
            }
            break;
            case 1:
            {
                stepMade=this->Nord(x,y,Map);
            }
            break;
            case 2:
            {
                stepMade=this->NordEst(x,y,Map);
            }
            break;
            case 3:
            {
                stepMade=this->Est(x,y,Map);
            }
            break;
            case 4:
            {
                stepMade=this->SudEst(x,y,Map);
            }
            break;
            case 5:
            {
                stepMade=this->Sud(x,y,Map);
            }
            break;
            case 6:
            {
                stepMade=this->SudVest(x,y,Map);
            }
            break;
            case 7:
            {
                stepMade=this->Vest(x,y,Map);
            }
            break;
            case 8:
            {
                stepMade=this->NordVest(x,y,Map);
            }
            break;
        }
        if(this->Blocat==true)
        {
            break;
        }
    }while (!stepMade);
    return stepMade;
}
