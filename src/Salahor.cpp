#include "Salahor.h"
#include "Harta.h"
Salahor::Salahor()
{
    this->x = 0;
    this->y = 0;
    this->Winner = false;
    this->Blocat = false;
}

Salahor::~Salahor()
{
    //dtor
}

int Salahor::getX()
{
    return this->x;
}

int Salahor::getY()
{
    return this->y;
}

bool Salahor:: Nord(int &x ,int&y, char ***Map)//Functii de mutare pe harta a cautatorilor

{
    if((*Map)[x-1][y] == ' ' || (*Map)[x-1][y] == 'C' )
    {
        (*Map)[x][y] = 'x';
        x--;
        (*Map)[x][y] = 'S';
        return true;
    }
    else
        return false;
}

bool Salahor:: NordEst(int &x, int&y, char ***Map)
{
    if( (*Map)[x-1][y+1] == ' ' || (*Map)[x-1][y+1] == 'C' )
    {
        (*Map)[x][y] = 'x';
        x--;
        y++;
        (*Map)[x][y] = 'S';
        return true;
    }
    else
        return false;
}

bool Salahor:: Est(int &x, int&y, char ***Map)
{
    if((*Map)[x][y+1] == ' ' || (*Map)[x][y+1] == 'C' )
    {
        (*Map)[x][y] = 'x';
        y++;
        (*Map)[x][y] = 'S';
        return true;
    }
    else
        return false;
}

bool Salahor:: SudEst(int &x, int&y, char ***Map)
{
    if((*Map)[x+1][y+1] == ' ' || (*Map)[x+1][y+1] == 'C' )
    {
        (*Map)[x][y] = 'x';
        x++;
        y++;
        (*Map)[x][y] = 'S';
        return true;
    }
    else
        return false;
}

bool Salahor:: Sud(int &x, int&y, char ***Map)
{
    if((*Map)[x+1][y] == ' ' || (*Map)[x+1][y] == 'C' )
    {
        (*Map)[x][y] = 'x';
        x++;
        (*Map)[x][y] = 'S';
        return true;
    }
    else
        return false;
}

bool Salahor:: SudVest(int &x, int&y, char ***Map)
{
    if((*Map)[x+1][(y)-1] == ' ' || (*Map)[x+1][y-1] == 'C' )
    {
        (*Map)[x][y] = 'x';
        x++;
        y--;
        (*Map)[x][y] = 'S';
        return true;
    }
    else
        return false;
}

bool Salahor:: Vest(int &x, int&y, char ***Map)
{
    if((*Map)[x][y-1] == ' ' || (*Map)[x][y-1] == 'C' )
    {
        (*Map)[x][y] = 'x';
        y--;
        (*Map)[x][y] = 'S';
        return true;
    }
    else
        return false;
}
bool Salahor:: NordVest(int &x, int&y, char ***Map)
{
    if((*Map)[x-1][y-1] == ' ' || (*Map)[x-1][y-1] == 'C' )
    {
        (*Map)[x][y] = 'x';
        x--;
        y--;
        (*Map)[x][y] = 'S';
        return true;
    }
    else
        return false;
}

void Salahor::setPosition(const int &x, const int &y)
{
    this->x = x;
    this->y = y;
}

