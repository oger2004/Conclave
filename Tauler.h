#ifndef TAULER_H
#define TAULER_H

#include <iostream>
#include "Baralla.h"
#include "Carta.h"

using namespace std;

class Tauler
{
    public:
        Tauler();
        Tauler(int nf, int nc);
        Tauler(Baralla& b, int& nc);
        Tauler(Tauler &t);
        ~Tauler();
    //    Tauler &operator=(const Tauler &t);

        void posarElem(int i, int j,  Carta &p);
        Carta obtElem(int i, int j);
        int obtNF();
        int obtNC();

        void llegirPunts();
        void mostrar(PilaCartes& d, PilaCartes& e);

        void colocar_carta(int& pos_n,int& pos_m,Carta& t);
        bool ple();
        bool fila_sumen_deu(int pos_n,int m);
        bool molts_espais(int& n_espais);
        int tornar_inf(int& n,int& j);
        char tornar_mag(int& n,int& j);
        char tornar_ger(int& n,int& j);
        void eliminar_carta(int& n,int& m);
        bool columna_sumen_deu(int m,int n);
        bool agafar_seguid(int& pos_n,int& pos_m,Carta& c);
        void emplenar(PilaCartes& e,PilaCartes& d,int& n_espais,char& nom_pila);
        bool buida(int& pos_n,int& pos_m);

        Carta torna_carta(int& n,int& m);


    private:

     //   const int MIDA_TAULER=4;
        Carta a_Tauler[4][4];

        bool no_emplenar(int i,int j);

        void allibera();
        void reserva();
        void copia(const Tauler &t);

};

#endif // TAULER_H
