#include <iostream>
#include "Carta.h"


using namespace std;

Carta::Carta()
{
    //Constructor per defecte de Carta
    a_mag=' ';
    a_ger=' ';
    a_inf=0;
}

Carta::Carta(char& mag,char& germ,int& inf){
    //Constructor amb valors de Carta
    a_mag=mag;
    a_ger=germ;
    a_inf=inf;
}

void Carta::sumar_inf(int& inf){
    //Pre:influencia d'una carta
    //Post:la suma daquesta influencia
    a_inf+=inf;
}

Carta::Carta(Carta& t)
{
    //Constructor copia de Carta
    a_mag=t.a_mag;
    a_ger=t.a_ger;
    a_inf=t.a_inf;
}

/*Carta &Carta::operator=(Carta& t){
    a_ger=t.a_ger;
    a_inf=t.a_inf;
    a_mag=t.a_mag;

    return *this;
}
*/

bool Carta::buida(){
    //Pre:--
    //Post:Retorna si la carta es buida
    if(a_ger==' ' and a_inf==0 and a_mag==' ') return true;
    else return false;
}

int Carta::tornar_inf(){
    //Pre:--
    //Post:retorna la influencia de la Carta
    return a_inf;
}

char Carta::tornar_ger(){
    //Pre:--
    //Post:retorna la germandat de la Carta
    return a_ger;
}
char Carta::tornar_mag(){
    //Pre:--
    //Post:retorna la magia de la Carta
    return a_mag;
}

void Carta::mostrar_radera(){
    //Pre:--
    //Post:mostra la carta per radera
    cout << "["<< a_mag <<"]";
}

void Carta::mostrar(){
    //Pre:--
    //Post:Mostra la carta per davant
    cout << "["<< a_mag << a_inf << a_ger <<"]";
}

