#ifndef HARTA_H
#define HARTA_H

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <vector>
#include "Salahor.h"
#include "Nebun.h"
#include "Tura.h"
#include "Regele.h"
#include "Inutilul.h"


class Salahor;

class Harta
{
    private:
    bool stop;
    char ** Map;
    int n, m;
    int nrSalahori;
    int comoriRamase;
    std::vector <Salahor*>  S;
    struct Comoara
    {
        int x, y;
    };
    struct Comoara *Comori;
    void AfisareHarta();
    void alocareSpatiuHarta();
    void eliminareComoara(const int x, const int y, int *comoriRamase);
    void eliminareSalahor(const int x, const int y, int *nrSalahori);
    void AsezareSalahori(int &x, int &y);
    bool Verificare(const int x, const int y);
    friend class Salahor;
    friend class Nebun;
    void MutareRandom(Salahor *&S);
    public:
        Harta(int a, int b);
        void Start();
        friend std::ostream& operator<<(std::ostream &out, Harta &Map);
        ~Harta();
};

#endif // HARTA_H
