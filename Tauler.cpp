#include <iostream>
#include <iomanip>

#include "Tauler.h"

using namespace std;

Tauler::Tauler(){
    //Constructor per defecte de Tauler
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            a_Tauler[i][j]=Carta();
        }
    }
}

Tauler::Tauler(Baralla& b,int& nc){
    //Constructor de tauler a partir de la baralla i el nombre e cartes
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(no_emplenar(i,j)) a_Tauler[i][j]=Carta();
            else{
                a_Tauler[i][j]=b.tornar_carta_int(nc-1);
                nc--;
            }
        }
    }
}

bool Tauler::no_emplenar(int i,int j){
    //Pre:posicio i,j
    //Post:retorna true si no s'ha demplenar false altrament
    if(i==2 and j==1) return true;
    else if(i==2 and j==2) return true;
    else if(i==1 and j==1) return true;
    if(i==1 and j==2) return true;
    else return false;
}



Tauler::~Tauler(){


}

void Tauler::mostrar(PilaCartes& d, PilaCartes& e){
    //Pre: les dos piles
    //Post:mostra el tauler

    cout << string(5, ' ');
    for (int i = 0; i < 4; i++) {
        cout << setfill(' ') << setw(6) << i;
    }
    cout << endl;

    for (int i = 0; i < 4; i++) {
        if (i == 1){
            e.mostrar_ultima();
        }// [revers carta cim pila esquerra];

        else cout << "   ";

        cout << setfill(' ') << setw(3) << i << " ";
        for (int j = 0; j < 4; j++) {
            cout << " ";
            Carta buida;
            if(a_Tauler[i][j].buida()) cout << "[   ]";
            else a_Tauler[i][j].mostrar();
       //     [carta posició (i,j)]
        }

        if (i == 1) {
            cout << "  ";
            d.mostrar_ultima();
        //    [revers carta cim pila dreta]
        }

        cout << endl;
    }
}

void Tauler::colocar_carta(int& pos_n,int& pos_m,Carta& t){
    //Pre:entra una posicio i una carta
    //Post:coloca la carta a la posicio
    a_Tauler[pos_n][pos_m]=t;

}

bool Tauler::ple(){
    //Pre:--
    //Post:true si el tauler es ple false altrament
    bool ple=true;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(a_Tauler[i][j].buida()) ple=false;
        }
    }
    return ple;
}

bool Tauler::fila_sumen_deu(int pos_n,int m){
    //Pre: la posicio m,n
    //Post:retorna si a la fila sumen 10
    int s=0;
    bool sumen=false;
    int i=0;
    bool  buit=false;

    if(a_Tauler[pos_n][0].buida()) i=1;
    if(a_Tauler[pos_n][1].buida()) i=2;
    if(a_Tauler[pos_n][2].buida()) i=3;
    while(i<4 and not buit){
        if(a_Tauler[pos_n][i].buida()) buit=true;
        if(not buit) s+=a_Tauler[pos_n][i].tornar_inf();
        i++;
    }
    if(s>=10) sumen=true;

    return sumen;
}

Carta Tauler::torna_carta(int& n,int& m){
    //Pre:entra posicio n,m
    //Post:retorna la carta de posicio n,m
    return a_Tauler[n][m];
}


bool Tauler::buida(int& pos_n,int& pos_m){
    //Pre:entra la posicio n,m
    //Post:retorna true si la posicio n,m es buida
    return a_Tauler[pos_n][pos_m].tornar_inf()==0;
}

bool Tauler::columna_sumen_deu(int m,int n){
    //Pre: la posicio m,n
    //Post:retorna si a la columna sumen 10
    int s=0;
    bool sumen=false;
    int i=0;
    bool  buit=false;

    if(a_Tauler[0][m].buida()) i=1;
    if(a_Tauler[1][m].buida()) i=2;
    if(a_Tauler[2][m].buida()) i=3;
    while(i<4 and not buit){
        if(a_Tauler[i][m].buida()) buit=true;
        if(not buit) s+=a_Tauler[i][m].tornar_inf();
        i++;
    }

    if(s>=10) sumen=true;
    return sumen;
}
/*
bool Tauler::agafar_seguid(int& pos_n,int& pos_m,Carta& c){
    //Pre:entra la la posicio del tauler i una carta
    //Post:
    bool agafar=true;

    for(int i=0; i<4;i++){
        for(int j=0; j<4; j++){
            if(i!=pos_n and j!=pos_m and (c.tornar_ger()==a_Tauler[i][j].tornar_ger() or c.tornar_mag()==a_Tauler[i][j].tornar_mag()))
                agafar=false;
        }
    }
    return agafar;
}
*/
void Tauler::emplenar(PilaCartes& e,PilaCartes& d,int& n_espais,char& nom_pila){
    //Pre:entren dos piles, el nombre d'espais buits i el nom de la pila que hem dagafar
    //Post:si les dos piles no estan buides s'agafa de la pila indicada a no ser que estigui buida que sagafara de laltre
    for(int i=0; i<4;i++){
        for(int j=0; j<4; j++){
            if(a_Tauler[i][j].buida() and n_espais>=5){
                if(not e.buida() or not d.buida()){
                    if(d.buida()) nom_pila='e';
                    else if(e.buida()) nom_pila='d';

                    if(nom_pila=='d'){
                        a_Tauler[i][j]=d.tornar_cim();
                        n_espais--;
                    }
                    else{
                        a_Tauler[i][j]=e.tornar_cim();
                        n_espais--;
                    }
                }
            }
        }
    }
}



bool Tauler::molts_espais(int& n_espais){
    //Pre:entra un valor indeterminat
    //Post:retorna true si el nombre despias es mes gran que 4
    n_espais=0;
    for(int i=0; i<4;i++){
        for(int j=0; j<4; j++){
            if(a_Tauler[i][j].buida()) n_espais++;
        }
    }
    return n_espais>4;
}

int Tauler::tornar_inf(int& n,int& j){
    //Pre:posicio n,j
    //Post: retornar la influencia de la carta de la posicio n,j
    return a_Tauler[n][j].tornar_inf();
}

char Tauler::tornar_mag(int& n,int& j){
    //Pre:posicio n,j
    //Post: retornar la magia de la carta de la posicio n,j
    return a_Tauler[n][j].tornar_mag();
}
char Tauler::tornar_ger(int& n,int& j){
    //Pre:posicio n,j
    //Post: retornar la germandat de la carta de la posicio n,j
    return a_Tauler[n][j].tornar_ger();
}

void Tauler::eliminar_carta(int& n,int& m){
    //Pre:posicio n,m
    //Post: elimina la carta de la posicio n,m
    a_Tauler[n][m]=Carta();
}


















