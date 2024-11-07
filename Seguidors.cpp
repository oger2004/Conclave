#include <iostream>
#include <iomanip>
#include "Seguidors.h"

using namespace std;

Seguidors::Seguidors()
{
    //Constructor per defecte de Seguidors
    for(int i=0; i<6; i++){
        a_mag[i]=a_mag_t[i];
        a_inf[i]=0;
    }
     n_seg=0;
}

bool Seguidors::mov_valid(char& mag_c){
    //Pre:entra una magia
    //Post:true si el jugador no te influencia en aquella magia false altrament
    bool mov=true;
    for(int i=0; i<6;i++){
        if(a_mag[i]==mag_c){
            if(a_inf[i]>0) mov=false;
        }
    }
    return mov;
}

Carta Seguidors::tornar_carta_seg(char& mag_c){
    //Pre:entra una magia
    //Post: es retorna la carta que correspon a aquella magia
    bool acab=false;
    int i=0;
    Carta tornar;
    while(i<6 and not acab){
        if(mag_c==a_mag[i]){
            acab=true;
            tornar=seg[i];
        }
        else
            i++;
    }

    return tornar;
}

int Seguidors::tornar_inf(char& mag){
    //Pre:entra una magia
    //Post:retorna la suma de la influencia d'aquella magia
    int inf;
    for(int i=0; i<6; i++){
        if(mag==a_mag[i]) inf=a_inf[i];
    }
    return inf;
}


void Seguidors::elim_seg(char& mag_c){
    //Pre:entra una magia
    //Post: selimina la influencia de la magia entrada
    for(int i=0; i<6; i++){
        if(mag_c==a_mag[i]){
            a_inf[i]=0;
            seg[i]=seg[n_seg-1];
        }
    }
    n_seg--;
}

void Seguidors::mostrar_i(){
    //Pre:--
    //Post:mostra els resum dels seguidors
    int inf;
    for(int i=0; i<6; i++){
        if(a_inf[i]==0) cout << "[" << setfill(' ') << setw(3)<< a_mag[i] << "] ";
        else {
            inf=a_inf[i];
            if(inf>9)
                cout << "[" <<inf<< a_mag[i] << "] ";
            else
                cout << "[ " <<inf<< a_mag[i] << "] ";
        }
    }
}

bool Seguidors::hi_ha_seg(char& mag_c){
    //Pre:entra una magia
    //Post: retorna false si no hi ha uinfluencia de la magia entrada true altrament
    bool hiha=false;

    for(int i=0; i<6; i++){
        if(mag_c==a_mag[i] and a_inf[i]>0) hiha=true;
    }

    return hiha;
}

void Seguidors::afegir_seg(Carta& c){
    //Pre:entra una carta
    //Post:safegeix la carta i es suma la seva influencia a la taula a_inf en lindex de la seva magia
    char mag=c.tornar_mag();
    int inf=c.tornar_inf();
    seg[n_seg]=c;
    n_seg++;

    for(int i=0; i<6; i++){
        if(mag==a_mag[i]) a_inf[i]+=inf;
    }
}

void Seguidors::mostrar_cartes(){
    //Pre:--
    //Post:Mostra totes les cartes que te una jugador com a seguidor
    for(int i=0; i<n_seg; i++){
        seg[i].mostrar();
        cout << " ";
    }
    cout << endl;
}


