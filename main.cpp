/************************************************************************
 * Exercici de la Sessió 10
 *
 * Falta l'especificació
 ************************************************************************/
#include <iostream>
#include <limits>
#include "Joc.h"

using namespace std;

void previ(Joc& joc)
{
    /*
    int n_j;
    cout<< "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
    cin>>n_j;

    while(n_j<2 or n_j>4){
        cout << "NUMERO DE JUGADORS INCORRECTE" << endl;
        cout<< "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
        cin>>n_j;
    }

    joc.preparar(n_j);

    int compt_jug=0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(compt_jug<=n_j-1){
        cout << "ENTRA EL NOM DEL JUGADOR " << compt_jug+1 << ":" <<endl;
        joc.afegir_jug(compt_jug);
        compt_jug++;
    }
    */
}

int main()
{
	unsigned llavor;
    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> llavor;

    Joc joc(llavor);
  //  previ(joc);

    joc.comencar_joc();

}














