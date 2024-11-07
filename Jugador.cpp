#include <iostream>
#include <limits>
#include "Jugador.h"

using namespace std;

Jugador::Jugador()
{
    //Constructor per defecte de jugador
    a_nom=" ";
    for(int i=0; i<4; i++){
        ma[i]=Carta();
    }
    seg_jug=Seguidors();
    p_dec=0;
}

Jugador::~Jugador()
{
    //dtor
}

void Jugador::entrar_nom(){
    //Pre:--
    //Post:modifica el nom del jugador entrat per teclat
    getline(cin,a_nom);
}

string Jugador::tornar_nom(){
    //Pre:--
    //Post:retorna el nom del jugador
    return a_nom;
}


void Jugador::entrar_carta(int compt_cartes_don,Carta carta_ma){
    //Pre:entra la posicio de la carta i una carta
    //Post:s'afegeix a la ma la carta en la posicio indicada
    ma[compt_cartes_don]=carta_ma;
}

void Jugador::mostar_ma(){
    //Pre:--
    //Post:es mostren les cartes del jugador
    for(int i=0; i<4; i++){
        cout << i << ":"; ma[i].mostrar();cout << " ";
    }
    cout << endl;
}

void Jugador::mostrar_punts_decepcio(){
    //Pre:--
    //Post:es mostren els punts de decpecio del jugador
    cout << " " << p_dec << " ";
}

void Jugador::mostrar_seguidors_i(){
    //Pre:--
    //Post:es mostren el resum dels seguidors
    seg_jug.mostrar_i();
}

void Jugador::iniciar_seg(){
    //Pre:--
    //Post:s'inicialitzen els seguidors del jugador amb el seu constructor
    seg_jug=Seguidors();
}

Carta Jugador::tornar_carta(int& pos_c){
    //Pre:entra una posicio
    //Post:retorna la carta de la ma dde la posicio entrada
    return ma[pos_c];
}

bool Jugador::hi_ha_seg(char& mag_c){
    //Pre:entra una magia
    //Post:retorna true si hi ha seguidors daquella magia
    return seg_jug.hi_ha_seg(mag_c);
}

void Jugador::afegir_seguidors_f(Carta& c){
    //Pre:entra una carta
    //Post:afegeix aquesta carta a seguidors
    seg_jug.afegir_seg(c);
}

bool Jugador::mov_valid(char& mag_c){
    //Pre:entra una magia
    //Post:retorna true si el jugador no te cartes de la magia entrada
    return seg_jug.mov_valid(mag_c);
}

Carta Jugador::tornar_seg(char& mag_c){
    //Pre:entra una magia
    //Post:retorna el primer seguidor que trobi daquella magia
    Carta tornar;
    tornar=seg_jug.tornar_carta_seg(mag_c);
    return tornar;
}

void Jugador::treure_seg(char& mag_c){
    //Pre:entra una magia
    //Post:selimina una seguidor que de la magia entrada
    seg_jug.elim_seg(mag_c);
}

void Jugador::afegir_p_dec(int& p){
    //Pre:entra uns punts de decepcio
    //Post:s'afageixen al recompte dels punts de decepcio
    p_dec+=p;
}

void Jugador::mostrar_cartes_seg(){
    //Pre:--
    //Post:mostra les cartes dels seguidors
    seg_jug.mostrar_cartes();
}

int Jugador::tornar_s_seg(char& mag){
    //Pre:entra una magia
    //Post:torna la inlfuencia total dels seguidors de la magia entrada
    int inf=seg_jug.tornar_inf(mag);
    return inf;
}

int Jugador::tornar_n_dec(){
    //Pre:--
    //Post:retorna els punts de decepcio del jugador
    return p_dec;
}


void Jugador::afegir_carta(int& pos_c,Carta& nova){
    //Pre:entra una posicio i una carta
    //Post:s'afgeix aquesta carta a la ma en la posicio indicada
    ma[pos_c]=nova;
}

void Jugador::robar_carta(PilaCartes& p,int pos_c){
    //Pre:entra una pila de cartes i una posicio
    //Post:s'gafa la carta del cim de la pila i es posa la posicio indicada de la ma
    Carta nova;
    nova=p.tornar_cim();
    ma[pos_c]=nova;
}

void Jugador::mostrar_nom(){
    //Pre:--
    //Post:mostra el nom del jugador
    cout << a_nom<<endl;
}

void Jugador::mostrar_cartes_rad(int& j){
    //Pre:entra lindex del jugador
    //Post:es mostra el radera de la seva ma, lindex incrementat en 1 i el seu nom
        for(int i=0; i<4; i++){
            ma[i].mostrar_radera();
            cout << " ";
        }
        cout << "  " << j+1 <<" "<<a_nom;
        cout << endl;
}


