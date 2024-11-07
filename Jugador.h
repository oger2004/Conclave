#include <iostream>
#ifndef JUGADOR_H
#define JUGADOR_H

#include "Carta.h"
#include "Seguidors.h"
#include "Tauler.h"
#include "PilaCartes.h"

using namespace std;

class Jugador
{
    public:
        Jugador();
        ~Jugador();

        void entrar_nom();

        void entrar_carta(int compt_cartes_don,Carta carta_ma);
        void mostrar_nom();
        void mostar_ma();
        void mostrar_cartes_rad(int& j);
        void mostrar_seguidors_i();
        void iniciar_seg();
        Carta tornar_carta(int& pos_c);
        void afegir_seguidors_f(Carta& c);
        void afegir_carta(int& pos_c,Carta& nova);

        void robar_carta(PilaCartes& p,int pos_c);
        Carta tornar_seg(char& mag_c);
        void treure_seg(char& mag_c);
        bool mov_valid(char& mag_c);
        bool hi_ha_seg(char& mag_c);
        void mostrar_cartes_seg();
        void mostrar_punts_decepcio();
        void afegir_p_dec(int& p);
        int tornar_s_seg(char& mag);
        int tornar_n_dec();
        string tornar_nom();



    private:
        string a_nom;
        Carta ma[4];
        Seguidors seg_jug;
        int p_dec;

};

#endif // JUGADOR_H
