#include <iostream>
#include <limits>
#include <iomanip>
#include "Joc.h"

using namespace std;

Joc::Joc()
{
    //Constructor per defecte
    n_carta=90;
    n_jug=0;
    b=Baralla();
    d=PilaCartes();
    e=PilaCartes();
    for(int i=0; i<4;i++)
        jug[i]=Jugador();
    tauler=Tauler();

}

Joc::Joc(int N){
    //Pre: Ens entra la llavor
    //Post: Una baralla barrejada amb la llavor, cartes repartides entre els jugadors, el tauler i les piles fetes

    n_carta=90;

    cout<< "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
    cin>>n_jug;

    while(n_jug<2 or n_jug>4){
        cout << "NUMERO DE JUGADORS INCORRECTE" << endl;
        cout<< "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
        cin>>n_jug;
    }

    int compt_jug=0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(compt_jug<=n_jug-1){
        cout << "ENTRA EL NOM DEL JUGADOR " << compt_jug+1 << ":" <<endl;
        jug[compt_jug].entrar_nom();
        compt_jug++;
    }

    Baralla b_nova(N);

    b_nova.barrejar();
    b=b_nova;
    repartir();
    fer_tauler();
    fer_piles();
}



void Joc::comencar_joc(){
    //Pre: -
    //Post: Desenvolupa tot el joc s'acaba  quan les piles estan buides o els jugadors o indiquen

    char op=' ';
    int torn=0;

    inicialitzar_segui();

    while(op!='F'){

        if(torn==n_jug)torn=0;

        cout << endl << "TORN DE " << jug[torn].tornar_nom() << endl;
        cout << string(8 + jug[torn].tornar_nom().size(), '=') << endl;
        cout << endl;

        tauler.mostrar(d,e);

        cout << endl << "MA DE " << jug[torn].tornar_nom() << ":" << endl;
        jug[torn].mostar_ma();


        cout <<endl << endl <<"MANS DELS OPONENTS: "<<endl;
        mostra_ma_opo(torn);

        cout << endl << "RESUM DELS SEGUIDORS:" << endl;
        mostrar_seguidors();

        mostrar_menu();
        if(op!='F')cin>>op;
        q_fer(op,torn);

        if(op=='I' or op=='J' or op!='P' or op=='F')
            if(op!='P')torn++;

    }
}

void Joc::inicialitzar_segui(){
    //Pre:
    //Post:incialitza per tots els jugadors els seguidors amb el constructor per defecte
    for(int i=0;i<n_jug; i++){
        jug[i].iniciar_seg();
    }
}

void Joc::mostrar_seguidors(){
    //Pre:--
    //Post: Mostra la suma de les influencies dels seguidors
    for(int i=0;i<n_jug; i++){
        jug[i].mostrar_seguidors_i(); cout<<" "<< i+1<< " ";
        jug[i].mostrar_nom();
        cout << endl;
    }
}

void Joc::mostra_ma_opo(int& torn){
    //Pre:entra el torn dels jugadors
    //Post: mostra les cartes per radera dels oponents
    for(int j=0; j<n_jug; j++){
        if(j!=torn) jug[j].mostrar_cartes_rad(j);
    }
}

void Joc::fer_piles(){
    //Pre:--
    //Post:Crea les piles la dreta i la esquerra
    for(int i=n_carta-1; i>=n_carta/2; i--){
        e.empila(b.tornar_carta_int(i));
    }
    for(int i=(n_carta/2)-1; i>=0; i--){
        d.empila(b.tornar_carta_int(i));
    }
}

void Joc::repartir(){
    //Pre:--
    //Post:Reparteix les cartes als jugadors
    int compt_cartes_don=0;
    int n_elim=6*4+6*(4-n_jug);
    n_carta-=n_elim;
    b.modificar_a_n(n_carta);
    n_carta--;

    for(int i=0; i<n_jug; i++){

        while(compt_cartes_don<4){
            Carta nova;
            nova=b.tornar_carta_int(n_carta);

            //MODIFICAR LA A_N A DINS CLASSE BARALLA CARTA NOVA; YA ESTA BE AIXI
            jug[i].entrar_carta(compt_cartes_don,nova);

            n_carta--;
            compt_cartes_don++;
        }

        compt_cartes_don=0;
    }
    n_carta++;
    b.modificar_a_n(n_carta);
}

void Joc::fer_tauler(){
    //Pre:--
    //Post:Crea el tauler
    Tauler nou_Tauler(b,n_carta);
    tauler=nou_Tauler;

    b.modificar_a_n(n_carta);

}

void Joc::mostrar_menu(){
    //Pre:--
    //Post:Mostra el menu d'opcions
    cout << "OPCIONS: "<<endl;
    cout << "(I) FER JUGADA CEDINT INFLUENCIA" << endl;
    cout << "(J) FER JUGADA SENSE CEDIR INFLUENCIA"<<endl;
    cout << "(P) MOSTRAR PILES"<<endl;
    cout << "(F) ABANDONAR PARTIDA"<<endl;
    cout << "ENTRA UNA OPCIO:"<<endl;

}

void Joc::q_fer(char& op,int& i){
    //Pre:d'entrada te la el torn i el tipus de jugada del jugador
    //Post: desenvolupa la jugada demanada per el jugador
    if(d.buida() and e.buida()) finalitzar_partida();
    else if(op=='I') cedir_inf(i);
    else if(op=='J') n_cedir_inf(i);
    else if(op=='P') mostra_piles();
    else if(op=='F') cout << "PARTIDA ABANDONADA"<<endl;
    else cout << "OPCIO NO DEFINIDA"<<endl;
}

void Joc::finalitzar_partida(){
    //Pre:--
    //Post:final de partida mostra els seguidors les cartes, els punts de decepcio i el guanyador
    cout << endl << "RESULTAT FINAL" << endl;
    cout << string(14, '=') << endl << endl;

    cout << "TOTS ELS SEGUIDORS:" << endl;

    for(int i=0; i<n_jug; i++){
        cout << i+1 << " ";
        jug[i].mostrar_nom();
        cout << endl;
        jug[i].mostrar_cartes_seg();
    }
    cout << endl;

    cout << endl << "RESUM DELS SEGUIDORS:" << endl;

    for(int i=0; i<n_jug; i++){
        jug[i].mostrar_seguidors_i();
        cout << endl;
    }

    cout << "PUNTS DE DECEPCIO:"<<endl;

    cout << endl << "PUNTS DE DECEPCIO:" << endl;

    calc_punts_dec();
    for(int i=0; i<n_jug; i++){
        cout << setfill(' ') << setw(3);
        jug[i].mostrar_punts_decepcio();
        jug[i].mostrar_nom();
        cout<<endl;
    }

    int minim=1000;
    int dec_num;
    int jug_guany;
    for(int i=0; i<n_jug; i++){
        dec_num=jug[i].tornar_n_dec();
        if(dec_num<minim){
            minim=dec_num;
            jug_guany=i;
        }
    }

    cout << "ENHORABONA "; jug[jug_guany].mostrar_nom(); cout<<"! HAS GUANYAT LA PARTIDA!"<<endl;
}

void Joc::calc_punts_dec(){
    //Pre:--
    //Post:calcula els punts de decepcio de cada jugador

//IMPLEMENTARHO AMB LA SUMA JA FETA DE LA TAULA DE SEGUIDORS TOT I QUE NO FUNCIONI

    int maxim=0;
    char mag;
    int posicio_jug_ant=0;
    int inf;
    bool es_primer=false;
    int primer=0;
    for(int i=0; i<6; i++){
        //Per cada magia mirar quin jugador te mes influencia
        mag=a_mag_t[i];
        for(int j=0; j<n_jug; j++){
            inf=jug[j].tornar_s_seg(mag);
            if(inf<maxim){
                //Afegir punts de decepcio si esta per sota del maxim
                jug[j].afegir_p_dec(inf);
                if(primer==0)
                    es_primer=true;
                primer++;

            }
            else{
                //Si es el jugador amb mes influencia no afegir decepcio
                //Guardem la seva dels jugadors que han donat maxim influencia perque si algu els supera puguem afegir punts de decepcio
                if(not es_primer){
                    posicio_jug_ant=j;
                    maxim=inf;
                    es_primer=false;
                }
                else{
                    inf=jug[posicio_jug_ant].tornar_s_seg(mag);
                    jug[posicio_jug_ant].afegir_p_dec(inf);
                    posicio_jug_ant=j;
                    maxim=inf;
                }
            }
        }
        posicio_jug_ant=0;
        maxim=0;
        es_primer=false;
        primer=0;
    }

}


void Joc::mostra_piles(){
    //Pre:--
    //Post:mostra les dues piles
    cout << "PILA ESQUERRA:"<<endl;
    e.mostrar();
    cout << "PILA DRETA:" <<endl;
    d.mostrar();
}

void Joc::cedir_inf(int& i){
    //Pre:torn del jugador
    //Post:desenvolupa la jugada J
    cout << "ENTRA LA MAGIA QUE VOLS CEDIR: "<<endl;
    char mag_c;
    cin>>mag_c;

    cout << "ENTRA EL JUGADOR A QUI LA VOLS CEDIR: "<<endl;
    int n_jug_c;
    cin>>n_jug_c;

    char interes='s';
    while(interes=='s'){
        if(not jug[n_jug_c-1].mov_valid(mag_c) and not magia_existeix(mag_c)){
            //SHAN DE TORNAR LES CARTES QUE CONICIDEIXIN AMB LA MAGIA I AFEGIRLES A LALTRE JUGADOR
            // I ELIMINARLES DEL JUGADOR INICIAL
            while(jug[i].hi_ha_seg(mag_c)){ // SI NO QUEDEN CARTES DE LA MATEIXA MAGIA PARAR DE CEDIR INF
                Carta inf_seg;
                inf_seg=jug[i].tornar_seg(mag_c);

                jug[i].treure_seg(mag_c);
                jug[n_jug_c-1].afegir_seguidors_f(inf_seg);
            }
        }
        else if(not jug[n_jug_c-1].mov_valid(mag_c)){
            cout << "MOVIMENT NO VALID" <<endl;
            cout << "ENCARA T'INTERESSA CEDIR INFLUENCIA? (s/n) "<<endl;
            cin>> interes;

            if(interes=='s'){
                cout << "ENTRA LA MAGIA QUE VOLS CEDIR: "<<endl;
                cin>>mag_c;

                cout << "ENTRA EL JUGADOR A QUI LA VOLS CEDIR: "<<endl;
                cin>>n_jug_c;
            }
        }
        else if(not magia_existeix(mag_c)){
            cout << "MAGIA INEXISTENT" <<endl;
            cout << "ENCARA T'INTERESSA CEDIR INFLUENCIA? (s/n) "<<endl;
            cin>> interes;

            if(interes=='s'){
                cout << "ENTRA LA MAGIA QUE VOLS CEDIR: "<<endl;
                cin>>mag_c;

                cout << "ENTRA EL JUGADOR A QUI LA VOLS CEDIR: "<<endl;
                cin>>n_jug_c;
            }
        }
    }

    n_cedir_inf(i);
}
bool Joc::magia_existeix(char& mag_c){
    //Pre:un caracter corresponent a una posible magia
    //Post:true=magia existeix false altrament
    int i=0;
    bool trobat=false;
    while(i<6 and not trobat){
        if(a_mag_t[i]==mag_c) trobat=true;
        else i++;
    }
    return trobat;
}




void Joc::n_cedir_inf(int& i){
    //Pre:torn jugador
    //Post:desenvolupa jugada J
    int pos_c;
    int pos_n, pos_m;
    char nom_pila;

    preg_jugada(pos_c,pos_n,pos_m);

    while(not tauler.buida(pos_n,pos_m)){
        cout << "JUGADA NO PERMESA"<<endl;
        cout << "TORNA A INDICAR LA JUGADA"<<endl;
        preg_jugada(pos_c,pos_n,pos_m);
    }

    cout << "DE QUINA PILA VOLS ROBAR LA CARTA? (e/d) "<<endl;
    cin>>nom_pila;

    while(nom_pila!='d' and nom_pila!='e'){
        cout <<"AQUESTA PILA NO EXISTEIX" <<endl;
        if(d.buida()) nom_pila='e';
        else if(e.buida()) nom_pila='d';
        else{
            cout << "DE QUINA PILA VOLS ROBAR LA CARTA? (e/d) "<<endl;
            cin>>nom_pila;
        }
    }

    Carta colocar;
    colocar=jug[i].tornar_carta(pos_c);

    tauler.colocar_carta(pos_n,pos_m,colocar);

    if(tauler.ple() and tauler.fila_sumen_deu(pos_n,pos_m) and  not tauler.columna_sumen_deu(pos_m,pos_n)){
        //ENVIEM A SEGUIDORS TOTS ELS MAGS QUE NO SIGUIN DE LA
        //MATEIXA GERMANDAT DEL EMISSOR TANT DE FILA COM COLUMNA
        afegir_seguidors_f_P(pos_n,pos_m,colocar,i);
        afegir_seguidors_c_P(pos_n,pos_m,colocar,i);

    }
    else if(tauler.fila_sumen_deu(pos_n,pos_m) or tauler.columna_sumen_deu(pos_m,pos_n)){
        //AGAFAR MAGS DE LA MATEIXA MAGIA O GERMANDAT QUE LEMISSOR
        //DE LA MATEIXA FILA SAFEGEIXEN A SEGUIDORS
        if(tauler.fila_sumen_deu(pos_n,pos_m))afegir_seguidors_f(pos_n,pos_m,colocar,i);
        if(tauler.columna_sumen_deu(pos_m,pos_n)) afegir_seguidors_c(pos_n,pos_m,colocar,i);

    }

    pilabuida(nom_pila);

    if(nom_pila=='e') jug[i].robar_carta(e,pos_c);
    else if(nom_pila=='d') jug[i].robar_carta(d,pos_c);

    int n_espais=0;
    if(tauler.molts_espais(n_espais)){
        tauler.emplenar(e,d,n_espais,nom_pila);
    }
}

void Joc::preg_jugada(int& pos_c,int& pos_n,int& pos_m){
    //Pre:s'entra la posicio de la carta i les posicions del tauler sense inicialitar
    //Post: es modifiquen els valors entrats
    cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR: " << endl;
    cin>>pos_c;

    while(pos_c>3 or pos_c<0){
        cout << "POSICIO NO VALIDA"<<endl;
        cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR: " << endl;
        cin>>pos_c;
    }

    cout << "ENTRA LA POSICIO DEL TAULER ON VOLS COL.LOCAR LA CARTA:" << endl;
    cin>> pos_n >> pos_m;

    while(pos_m>3 or pos_m<0 or pos_n>3 or pos_n<0){
        cout << "POSICIO NO VALIDA"<<endl;
        cout << "ENTRA LA POSICIO DEL TAULER ON VOLS COL.LOCAR LA CARTA:" << endl;
        cin>> pos_n >> pos_m;
    }
}

void Joc::pilabuida(char& nom_pila){
    //Pre:--
    //Post:comptrova si alguna de les piles es bida i canvia el valor que determina d'on es roben cartes
    if(d.buida() and e.buida()) cout << "LES DOS PILES SON BUIDES"<<endl;
    else if(nom_pila=='e' and e.buida()){
        nom_pila='d';
    }
    else if(nom_pila=='d' and d.buida()){
        nom_pila='e';
    }
}

void Joc::afegir_seguidors_f(int& n,int& m,Carta& c,int& torn){
    //Pre:entren la posicio al tauler la carta a colocar i el torn
    //Post: safegeix al jugador del torn els seguidors corresponents
    char mag_t,ger_t;

    for(int j=0; j<4; j++){
        // j RECORRE LES COLUMNES
        mag_t=tauler.tornar_mag(n,j);
        ger_t=tauler.tornar_ger(n,j);
        if(mag_t==c.tornar_mag() and j!=m){
            //AMB TOTES LES DADES QUE TENIM CONVERTIRHO EN CARTES I AFEGIRLES AL JUGADOR QUE VULGUEM
            Carta inf_seg;
            inf_seg=tauler.torna_carta(n,j);
            jug[torn].afegir_seguidors_f(inf_seg);
            tauler.eliminar_carta(n,j);
        }
        else if(ger_t==c.tornar_ger() and j!=m){
            //AMB TOTES LES DADES QUE TENIM CONVERTIRHO EN CARTES I AFEGIRLES AL JUGADOR QUE VULGUEM
            Carta inf_seg;
            inf_seg=tauler.torna_carta(n,j);
            jug[torn].afegir_seguidors_f(inf_seg);
            tauler.eliminar_carta(n,j);
        }
    }
}

void Joc::afegir_seguidors_c(int& n,int& m,Carta& c,int& torn){
    //Pre:entren la posicio al tauler la carta a colocar i el torn
    //Post: safegeix al jugador del torn els seguidors corresponents
    char mag_t,ger_t;

    for(int j=0; j<4; j++){
        // j SON LES FILES
        //ARA MIREM PER LA MATEIXA COLUMNA
        mag_t=tauler.tornar_mag(j,m);
        ger_t=tauler.tornar_ger(j,m);
        if(mag_t==c.tornar_mag() and j!=n){
            //AMB TOTES LES DADES QUE TENIM CONVERTIRHO EN CARTES I AFEGIRLES AL JUGADOR QUE VULGUEM
            Carta inf_seg;
            inf_seg=tauler.torna_carta(j,m);
            jug[torn].afegir_seguidors_f(inf_seg);
            tauler.eliminar_carta(j,m);
        }
        else if(ger_t==c.tornar_ger() and j!=n){
            //AMB TOTES LES DADES QUE TENIM CONVERTIRHO EN CARTES I AFEGIRLES AL JUGADOR QUE VULGUEM
            Carta inf_seg;
            inf_seg=tauler.torna_carta(j,m);
            jug[torn].afegir_seguidors_f(inf_seg);
            tauler.eliminar_carta(j,m);
        }
    }
}

void Joc::afegir_seguidors_c_P(int& n,int& m,Carta& c,int& torn){
    //Pre:entren la posicio al tauler la carta a colocar i el torn
    //Post: safegeix al jugador del torn els seguidors corresponents
    char mag_t,ger_t;

    for(int j=0; j<4; j++){
        // j SON LES FILES
        //ARA MIREM PER LA MATEIXA COLUMNA
        mag_t=tauler.tornar_mag(j,m);
        ger_t=tauler.tornar_ger(j,m);
        if(mag_t!=c.tornar_mag() and j!=n){
            //AMB TOTES LES DADES QUE TENIM CONVERTIRHO EN CARTES I AFEGIRLES AL JUGADOR QUE VULGUEM
            Carta inf_seg;
            inf_seg=tauler.torna_carta(j,m);
            jug[torn].afegir_seguidors_f(inf_seg);
            tauler.eliminar_carta(j,m);
        }
        else if(ger_t!=c.tornar_ger() and j!=n){
            //AMB TOTES LES DADES QUE TENIM CONVERTIRHO EN CARTES I AFEGIRLES AL JUGADOR QUE VULGUEM
            Carta inf_seg;
            inf_seg=tauler.torna_carta(j,m);
            jug[torn].afegir_seguidors_f(inf_seg);
            tauler.eliminar_carta(j,m);
        }
    }
}

void Joc::afegir_seguidors_f_P(int& n,int& m,Carta& c,int& torn){
    //Pre:entren la posicio al tauler la carta a colocar i el torn
    //Post: safegeix al jugador del torn els seguidors corresponents
    char mag_t,ger_t;

    for(int j=0; j<4; j++){
        // j RECORRE LES COLUMNES
        mag_t=tauler.tornar_mag(n,j);
        ger_t=tauler.tornar_ger(n,j);
        if(mag_t!=c.tornar_mag() and j!=m){
            //AMB TOTES LES DADES QUE TENIM CONVERTIRHO EN CARTES I AFEGIRLES AL JUGADOR QUE VULGUEM
            Carta inf_seg;
            inf_seg=tauler.torna_carta(n,j);
            jug[torn].afegir_seguidors_f(inf_seg);
            tauler.eliminar_carta(n,j);
        }
        else if(ger_t!=c.tornar_ger() and j!=m){
            //AMB TOTES LES DADES QUE TENIM CONVERTIRHO EN CARTES I AFEGIRLES AL JUGADOR QUE VULGUEM
            Carta inf_seg;
            inf_seg=tauler.torna_carta(n,j);
            jug[torn].afegir_seguidors_f(inf_seg);
            tauler.eliminar_carta(n,j);
        }
    }
}


/*
9
4
Bj
Ri
Ste
Bi
J
0
2 2
e
J
2
2 1
e
J
3
1 2
e
J
1
1 1
e
J
0
3 1
e
J
1
2 1
e
J
3
3 3
e
I
p
3
3 2
e


*/


void Joc::preparar(int& n_j){
    n_jug=n_j;
}
