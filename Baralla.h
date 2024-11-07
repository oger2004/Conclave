#include <iostream>
#include <cstdlib>
#include "Carta.h"
#include "PilaCartes.h"

#ifndef BARALLA_H
#define BARALLA_H

using namespace std;


class Baralla
{
    public:
        Baralla();
        Baralla(int N);
        Baralla(const Baralla &t);
        ~Baralla();

        Baralla &operator=(const Baralla &t);

        void afegir(Carta &p);

        void barrejar();
        void mostrar();
        int aleatori(int rang);

        Carta& tornar_carta_int(int n_carta);

        void empilar_die(PilaCartes& d, PilaCartes& e);

        Carta *retorn_b();

        void modificar_a_n(int n_carta);

        Carta retornar_carta(int n_carta);

    private:
        unsigned a_llavor;

        int a_n;// Num caselles ocupades
        int a_max;//Num de pos reservades
        Carta *b; //Punter de tipus carta per fer taula

        const int a = 1103515245, c = 12345, m = 32768, n_cartes=90;

        char mag_t[6]={'b','o','p','r','t','v'};
        char ger_t[3]={'c','g','s'};
        int inf_t[5]={1,2,3,4,5};

        void intercanvi(Carta& c_pos, Carta& c_i);

        void allibera();
        //Pre: memòria alliberada; Post: aquesta taula és còpia de la taula t
        void copia(const Baralla &t);
        //Pre: --; Post: memòria reservada per a_max Punt2D
        void reserva();
        //Pre: --; Post: la memòria reservada es dobla
        void expandeix();
};

#endif // BARALLA_H
