#include <iostream>
#include "Carta.h"
#include "Jugador.h"

#ifndef PILACARTES_H
#define PILACARTES_H

using namespace std;


class PilaCartes
{
    public:
        // CONSTRUCTORS I DESTRUCTOR ----------------------------------
        PilaCartes();
        // Pre: --; Post: pila buida
        PilaCartes(const PilaCartes& o); // const. de c�pia
        // Pre: --; Post: aquesta pila �s c�pia de la pila o
        ~PilaCartes(); // destructor
        // Pre: --; Post: mem�ria alliberada
        // CONSULTORS -------------------------------------------------
        bool buida() const;
        // Pre: -- ; Post: retorna cert si la pila �s buida; fals en cas contrari
        Carta cim() ;
        // Pre: pila no buida; Post: retorna el valor del cim de la pila
        // MODIFICADORS -----------------------------------------------
        void empila(Carta s);
        // Pre: --; Post: ha afegit s a dalt de la pila
        void desempila();
        // Pre: pila no buida; Post: ha eliminat element de dalt de la pila
        // OPERADOR REDEFINIT ---------------------------------------
        PilaCartes& operator=(const PilaCartes& o);
        // Pre: -- ; Post: aquesta pila �s c�pia de la pila o i la seva mem�ria din�mica ha estat pr�viament alliberada
        void mostrar();

        Carta tornar_cim();
        void mostrar_ultima();

    private:
        struct Node{
            Carta valor;
            Node* seg;
        };
        // ATRIBUTS
        Node* a_cim; // punter al cim de la pila
        // METODES PRIVATS
        void copia(const PilaCartes& o);
        // Pre: pila buida; Post: aquesta pila �s c�pia de la pila o
        void allibera();
        // Pre: --; Post: mem�ria din�mica alliberada

};

#endif // PILACARTES_H
