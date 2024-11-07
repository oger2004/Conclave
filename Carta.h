#ifndef CARTA_H
#define CARTA_H


class Carta
{
    public:
        Carta();
        Carta(char& mag,char& germ,int& inf);
        Carta(Carta& t);

      //  Carta &operator=(Carta& t);

        bool buida();

        void mostrar();
        void mostrar_radera();
        int tornar_inf();
        char tornar_ger();
        char tornar_mag();
        void sumar_inf(int& inf);

    private:
        char a_mag;
        char a_ger;
        int a_inf;
};

#endif // CARTA_H
