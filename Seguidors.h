#include <iostream>

#include "Carta.h"

#ifndef SEGUIDORS_H
#define SEGUIDORS_H



using namespace std;

class Seguidors
{
    public:
        Seguidors();

        void mostrar_i();
        void afegir_seg(Carta& c);
        Carta tornar_carta_seg(char& mag_c);
        void elim_seg(char& mag_c);
        bool mov_valid(char& mag_c);
        bool hi_ha_seg(char& mag_c);
        void mostrar_cartes();
        int tornar_inf(char& mag);

    private:
        char a_mag_t[6]={'b','o','p','r','t','v'};
        char a_inf[6];
        int n_seg;
        char a_mag[6];
        Carta seg[20];
};

#endif // SEGUIDORS_H
