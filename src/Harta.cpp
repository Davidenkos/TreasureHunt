#include "Harta.h"

Harta::Harta(int a, int b)
{
    srand(time(0));
    this->n = a;
    this->m = b;
    this->stop = false;
    this->comoriRamase = 3;
    this->nrSalahori = 4;
    this->alocareSpatiuHarta();
}

void Harta::alocareSpatiuHarta()
{
    Map = new char*[n];
    for (int i = 0; i < n; i++)
    {
        Map[i] =
        new char[m];
    }
    for (int i = 0; i < n; i++)
    {
        Map[i][0] = '|';
        Map[i][m-1] = '|';
    }
    for (int j = 0; j < m; j++)
    {

        Map[0][j] = '-';
        Map[n-1][j] = '-';
    }
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 1; j < m-1; j++)
        {
            Map[i][j] = ' ';
        }
    }
    Comori = new Comoara[comoriRamase];
    for (int i = 0; i < this->comoriRamase; i++)
    {
        Comori[i].x = rand() % (n-2) + 1;
        Comori[i].y = rand() % (m-2) + 1;
        if( ( (Comori[i].x-1 == 0) && (Comori[i].y-1 == 0 || Comori[i].y+1 == m-1)) || ((Comori[i].x+1 == n-1) && (Comori[i].y-1 == 0 || Comori[i].y+1 == m-1)) || (this->Map[Comori[i].x][Comori[i].y] == 'C') )
        {
            i--;
        }
        else
        {
            Map[Comori[i].x][Comori[i].y] = 'C';
        }
    }
    S.resize(this->nrSalahori);
    S[0] = new Nebun;
    S[1] = new Tura;
    S[2] = new Inutilul;
    S[3] = new Regele;
    for (int i = 0; i < this->nrSalahori; i++)
    {
        int xtemp = S[i]->getX();
        int ytemp = S[i]->getY();
        AsezareSalahori(xtemp, ytemp);
        S[i]->setPosition(xtemp, ytemp);
    }
}

void Harta::eliminareComoara(const int x, const int y, int *comoriRamase)//Metoda care elimina o comoara in cazul in care a fost gresit, primeste ca parametri pozitia comorii si cate au mai ramas
{
    for (int i = 0; i < *comoriRamase; i++)
    {
        if (this->Comori[i].x == x && this->Comori[i].y == y)
        {
            for (int j = i; j < *comoriRamase; j++)
            {
                this->Comori[j] = this->Comori[j+1];
            }
            (*comoriRamase)--;
        }
    }
}

void Harta::eliminareSalahor(const int x, const int y, int*nrSalahori)//La fel ca functia anterioara doar ca pentru clasa Salahor
{
    for (int i = 0; i < *nrSalahori; i++)
    {
        if (this->S[i]->x == x && this->S[i]->y == y)
        {
            for (int j = i; j < *nrSalahori; j++)
            {
                this->S[j] = this->S[j+1];
            }
            (*nrSalahori)--;
        }
    }
}

void Harta:: MutareRandom(Salahor *&S)//Self Explanatory(sper)
{
    int pas;
    bool stepMade = false;
    S->Blocat = false;
    int xtemp = S->getX(), ytemp=S->getY();
    do
    {
        pas = rand( ) % 9;
        switch (pas)
        {
            case 0:
            {
                S->Blocat = Verificare(xtemp, ytemp);
            }

            break;
            case 1:
            {
                stepMade = S->Nord(xtemp, ytemp, &Map);
            }
            break;
            case 2:
            {
                stepMade = S->NordEst(xtemp, ytemp, &Map);
            }
            break;
            case 3:
            {
                stepMade = S->Est(xtemp, ytemp, &Map);
            }
            break;
            case 4:
            {
                stepMade = S->SudEst(xtemp, ytemp, &Map);
            }
            break;
            case 5:
            {
                stepMade = S->Sud(xtemp, ytemp, &Map);
            }
            break;
            case 6:
            {
                stepMade = S->SudVest(xtemp, ytemp, &Map);
            }
            break;
            case 7:
            {
                stepMade = S->Vest(xtemp, ytemp, &Map);
            }
            break;
            case 8:
            {
                stepMade = S->NordVest(xtemp, ytemp, &Map);
            }
            break;
            }
            if(S->Blocat)
            {
                this->Map[xtemp][ytemp] = 'B';
                break;
            }
        }while (!stepMade);
        S->setPosition(xtemp, ytemp);
}

bool Harta:: Verificare(const int x,const int y)//Primeste coordonatele unui cautator si verifica in jurul lui sa vada daca este blocat sau nu
{
    if( (this->Map[x-1][y-1] != ' ' && this->Map[x-1][y-1] != 'C') && (this->Map[x-1][y+1] != ' ' && this->Map[x-1][y+1] != 'C') &&(this->Map[x+1][y-1] != ' ' && this->Map[x+1][y-1] != 'C') &&(this->Map[x+1][y+1] != ' ' && this->Map[x+1][y+1] != 'C') &&(this->Map[x-1][y] != ' ' && this->Map[x-1][y] != 'C') &&(this->Map[x+1][y] != ' ' && this->Map[x+1][y] != 'C') &&(this->Map[x][y-1] != ' ' && this->Map[x][y-1] != 'C') && (this->Map[x][y+1] != ' ' && this->Map[x][y+1] != 'C') )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Harta::AsezareSalahori(int &x,int &y)//Aseaza Salahorii in cele 4 colturi ale hartii
{
    if(this->Map[1][1]=='S')
    {
        if(this->Map[1][m-2]=='S')
        {
            if(this->Map[n-2][1]=='S')
            {
                x=n-2;
                y=m-2;
            }
            else
            {
                x=n-2;
                y=1;
            }
        }
        else
        {
            x=1;
            y=m-2;
        }
    }
    else
    {
        x=1;
        y=1;
    }
    this->Map[x][y]='S';
}

std::ostream& operator <<(std::ostream &out,Harta &V)
{
    for(int i=0;i<V.n;i++)
    {
        for(int j=0;j<V.m;j++)
        {
            out<<V.Map[i][j];
        }
        out<<std::endl;
    }
    out<<std::endl;
    return out;
}

void Harta:: Start()//In aceasta functie se intampla rularea jocului, utilizatorul fiin intrebat la fiecare pas daca vrea sa continue runda fiind oferite detalii despre numarul cautatorilor si numarul comorilor ramase
{

    int nrCastigatori=0;
    int caracterTastat;
    bool gasitDeterminist=false;
    int runda=0;
    while(!stop)
    {
        if(runda==0)
        {
            std::cout<<"Runda initiala"<<std::endl<<*this;
        }
        else
        {
            std::cout<<"Runda "<<runda<<std::endl<<*this<<"Nr Salahori Ramasi:"<<nrSalahori<<std::endl<<"Nr Comori Ramase:"<<comoriRamase<<std::endl;

        }
        std::cout<<"Selectati cifra unu pentru a trece la urmatoarea runda sau zero pentru a opri jocul:"<<std::endl;
        std::cin>>caracterTastat;
        if(caracterTastat==1)
        {
            runda++;
            for(int i=0;i<this->nrSalahori;i++)
            {
                gasitDeterminist=false;
                int distantaX,distantaY;
                if(!S[i]->Blocat && !S[i]->Winner)
                {
                    int xtemp=S[i]->getX(),ytemp=S[i]->getY();
                    for(int j=xtemp-1;j<=xtemp+1;j++)
                    {
                        if(gasitDeterminist)
                        {
                            break;
                        }
                        for(int k=ytemp-1;k<=ytemp+1;k++)
                        {
                            if(j!=xtemp || k!=ytemp)
                            {
                                if(Map[j][k]=='C')
                                {
                                    gasitDeterminist=true;
                                    distantaX=j-xtemp;
                                    distantaY=k-ytemp;
                                    this->Map[xtemp][ytemp]='x';
                                    if(distantaX<0)
                                    {
                                        xtemp--;
                                    }
                                    else if(distantaX>0)
                                    {
                                        xtemp++;
                                    }
                                    if(distantaY<0)
                                    {
                                        ytemp--;
                                    }
                                    else if(distantaY>0)
                                    {
                                        ytemp++;
                                    }
                                    this->Map[xtemp][ytemp]='S';
                                    S[i]->setPosition(xtemp,ytemp);
                                    break;
                                }
                            }
                        }
                        std::cout<<std::endl;
                    }
                    if(!gasitDeterminist)
                    {
                        xtemp=S[i]->getX();
                        ytemp=S[i]->getY();
                        gasitDeterminist=S[i]->Strategie(xtemp,ytemp,&Map);
                        S[i]->setPosition(xtemp,ytemp);
                    }
                    if(!gasitDeterminist)
                    {
                        std::cout<<"DELOC"<<std::endl;
                        MutareRandom(S[i]);
                    }
                }
            }
            for(int i=0;i<this->nrSalahori;i++)
            {
                if(S[i]->Blocat)
                {
                    int xtemp=S[i]->getX(),ytemp=S[i]->getY();
                    eliminareSalahor(xtemp,ytemp,&nrSalahori);
                }
            }
            for(int i=0;i<this->nrSalahori;i++)
            {
                int xtemp=S[i]->getX(),ytemp=S[i]->getY();
                for(int j=0;j<this->comoriRamase;j++)
                {
                    if((xtemp==Comori[j].x && ytemp==Comori[j].y) && (!S[i]->Winner))
                    {
                        nrCastigatori++;
                        S[i]->Winner=true;
                        this->Map[xtemp][ytemp]='W';
                        eliminareComoara(xtemp,ytemp,&comoriRamase);
                        eliminareSalahor(xtemp,ytemp,&nrSalahori);
                    }
                }
            }
            if( (this->comoriRamase == 0) || (this->nrSalahori ==0) || (nrCastigatori==3) )
            {
                stop=true;
                std::cout<<*this<<std::endl<<"Jocul s-a terminat :("<<std::endl;
                break;
            }
        }
        else if(caracterTastat==0)
        {
            std::cout<<"Jocul a fost oprit de utilizator";
            break;
        }
        else
        {
            std::cout<<"Trebuie sa apasati pe 1 pentru a trece la runda urmatoare ! "<<std::endl;
        }
    }
}

Harta::~Harta()
{
    for(int i=0;i<n;i++)
    {
        delete[] Map[i];
    }
    delete[]Map;
}
