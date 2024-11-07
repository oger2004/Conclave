#include <iostream>

#include "Baralla.h"

using namespace std;

Baralla::Baralla(){
    //constructor per defecte
    a_n=0;
    a_max=5;
    reserva();
}

Baralla::Baralla(int N){
    //constructor de baralla amb llavor
    a_n=0;
    a_max=5;
    a_llavor=N;
    reserva();

    int inf;
    char mag;
    char germ;
    for(int i=0; i<6; i++){
        mag=mag_t[i];
        for(int j=0; j<3; j++){
            germ=ger_t[j];
            for(int k=0; k<5; k++){
                inf=inf_t[k];
                Carta nova(mag,germ,inf);
                afegir(nova);
            }
        }
    }
}

Baralla::Baralla(const Baralla& t){
    //constructor copia de baralla
    copia(t);
}

Baralla::~Baralla(){
    //destructor de baralla
    allibera();
}

Baralla &Baralla:: operator=(const Baralla& t){
    //operador dassignacio de baralla
    if(this!=&t){
        allibera();
        copia(t);
    }
    return *this;
}

void Baralla::afegir(Carta& nova){
    //Pre:--
    //Post:afegeix una carta a la baralla
    if(a_n== a_max) expandeix();
    b[a_n]=nova;
    a_n++;
}

void Baralla::allibera(){
    //Pre:--
    //Post:allibera memoria virtual de la baralla
    delete [] b;
}

void Baralla::copia(const Baralla& t){
    //Pre:entrada una baralla
    //Post:fa una copia de la baralla entrada
    a_n=t.a_n;
    a_max=t.a_max;
    reserva();
    for(int i=0; i<a_n; i++)
        b[i]=t.b[i];
}

void Baralla::reserva(){
    //Pre:--
    //Post:reserva espai a memoria
    b=new Carta[a_max];
}

void Baralla::expandeix(){
    //Pre:--
    //Post:duplica l'espai a memoria reserva i torna a fer la baralla
    Carta *aux=b;
    a_max=2*a_max;
    reserva();
    for(int i=0; i<a_n; i++)
        b[i]=aux[i];
    delete []aux;
}

int Baralla::aleatori(int rang){
    //Pre:entra un rang
    //Post:retorna un valor elatori seguin una formula
    int res;
    a_llavor=a*a_llavor+c;
    res=((a_llavor/32)%m)%rang;
    return res;
}

void Baralla::intercanvi(Carta& c_pos, Carta& c_i){
    //Pre:entren dos cartes c,e
    //Post:C=e E=e
    Carta aux=c_pos;
    c_pos=c_i;
    c_i=aux;
}

void Baralla::mostrar(){
    //Pre:--
    //Post:es mostren les cartes de la baralla
    if(a_n==0) cout << "NO HI HA CAP CARTA";
    for(int i=0; i<a_n; i++){
        b[i].mostrar();
    }
    cout<<endl;
}

void Baralla::barrejar(){
    //Pre:--
    //Post:es barrejen les cartes de la baralla
    for(int i=n_cartes-1; i>0; i--){
        int pos=aleatori(i+1);
        intercanvi(b[pos],b[i]);
    }
}

Carta& Baralla::tornar_carta_int(int n_carta){
    //Pre:entra una posicio
    //Post:retorna la carta daquella posicio
    return b[n_carta];
}


/*
void Baralla::empilar_die(PilaCartes& d, PilaCartes& e){
    for(int i=a_n-1; i>=a_n/2; i--){
        e.empila(b[i]);
    }
    for(int i=(a_n/2)-1; i>=0; i--){
        d.empila(b[i]);
    }
 //   delete []b;
    a_n=0;
    a_max=5;
}
*/
Carta *Baralla::retorn_b(){
    //Pre:--
    //Post:retorna la baralla
    return b;
}

void Baralla::modificar_a_n(int n_carta){
    //Pre:--
    //Post:modifica el numero de cartes
    a_n=n_carta;
}

Carta Baralla::retornar_carta(int n_carta){
    //Pre:entra una posicio
    //Post:reotrna la carta de la baralla que ocupa aquella posicio
    return b[n_carta];
}




