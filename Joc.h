#include <iostream>

#ifndef JOC_H
#define JOC_H

#include "Baralla.h"
#include "PilaCartes.h"
#include "Carta.h"
#include "Tauler.h"
#include "Jugador.h"


using namespace std;

class Joc
{
    public:
        Joc();
        Joc(int N);

        void preparar(int& n_j);
        void comencar_joc();

    private:
        int n_jug;
        const int n_cartes_total=90;
        int n_carta;

        Baralla b;
        PilaCartes d;
        PilaCartes e;
        Tauler tauler;
        Jugador jug[4];
        char a_mag_t[6]={'b','o','p','r','t','v'};

        bool magia_existeix(char& mag_c);
        void inicialitzar_segui();

        void mostra_ma_opo(int& torn);
        void fer_piles();
        void repartir();
        void fer_tauler();
        void mostrar_seguidors();
        void mostrar_menu();
        void q_fer(char& op,int& i);
        void cedir_inf(int& i);
        void pilabuida(char& nom_pila);
        void n_cedir_inf(int& i);
        void afegir_seguidors_f(int& n,int& m,Carta& c,int& torn);
        void afegir_seguidors_f_P(int& n,int& m,Carta& c,int& torn);
        void afegir_seguidors_c(int& n,int& m,Carta& c,int& torn);
        void afegir_seguidors_c_P(int& n,int& m,Carta& c,int& torn);
        void mostra_piles();
        void preg_jugada(int& pos_c,int& pos_n,int& pos_m);
        void finalitzar_partida();
        void calc_punts_dec();
};

#endif // JOC_H
