#include <iostream>

#include "PilaCartes.h"

using namespace std;

PilaCartes::PilaCartes(){
    //Constructor per defecte de pila
    a_cim=NULL;
}

bool PilaCartes::buida() const{
    //Pre:--
    //Post:retorna si la pila es buida
    return a_cim==NULL;
}

Carta PilaCartes::cim(){
    //Pre:--
    //Post:retorna el valor de la carta al cim de la pila
    return a_cim->valor;
}

void PilaCartes::empila(Carta s){
    //Pre:--
    //Post:efageix una carta al cim
    Node *nou=new Node;
    nou->valor=s;
    nou->seg=a_cim;
    a_cim=nou;
}

void PilaCartes::desempila(){
    //Pre:--
    //Post:treu una carta del cim
    Node *aux=a_cim;
    a_cim=a_cim->seg;
    delete aux;
}

PilaCartes::PilaCartes(const PilaCartes& o){
    //constructor copia
    a_cim=NULL;
    copia(o);
}

PilaCartes::~PilaCartes(){
    //destructor
    allibera();
}

PilaCartes& PilaCartes::operator=(const PilaCartes& o){
    //operador dassignacio
    if(this!=&o){
        allibera();
        copia(o);
    }
    return *this;
}

void PilaCartes::allibera(){
    //Pre:--
    //Post:allibera memoria virtual
    while(!buida()){
        Node *aux=a_cim;
        a_cim=a_cim->seg;
        delete aux;
    }
}

void PilaCartes::copia(const PilaCartes& o){
    //Pre:entrada una pila
    //Post:retorna una copia de la pila entrada
    if(!o.buida()){
        Node *p,*q,*aux;
        p=new Node;
        a_cim=p;
        aux= o.a_cim;
        p->valor=aux->valor;
        p->seg=NULL;
        q=p;
        aux=aux->seg;
        while(aux!=NULL){
            p=new Node;
            q->seg=p;
            p->valor=aux->valor;
            p->seg=NULL;
            q=p;
            aux=aux->seg;
        }
    }
}

void PilaCartes::mostrar_ultima(){
    //Pre:--
    //Post:mostra el valor del cim de la pila
    if(a_cim==NULL) {
        cout << "[ ]" << endl;
    }
    else a_cim->valor.mostrar_radera();
}

Carta PilaCartes::tornar_cim(){
    //Pre:--
    //Post:retorna la carta cim i la elimina
    Carta nova;
    if(a_cim!=NULL){
        nova=a_cim->valor;
        a_cim=a_cim->seg;
    }

    return nova;
}

void PilaCartes::mostrar(){
    //Pre:--
    //Post:mostra les cartes de la pila
    if(a_cim==NULL) {
        cout << "NO HI HA CARTES" << endl;
    }
    Node *temp = a_cim;
    while(temp!=NULL){
        temp->valor.mostrar_radera();
        cout << " ";
        temp = temp->seg;
    }
    cout << endl;
}
