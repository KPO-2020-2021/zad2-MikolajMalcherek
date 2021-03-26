#include <iostream>
#include "WyrazenieZesp.hh"
using namespace std;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
istream &operator>>(istream &wej, WyrazenieZesp &WyrZ)
{
    char znak;

    wej >> WyrZ.Arg1;
    wej >> znak;
    switch (znak)
    {

    case '+':
        WyrZ.Op = Op_Dodaj;

        break;
    case '-':
        WyrZ.Op = Op_Odejmij;

        break;
    case '*':
        WyrZ.Op = Op_Mnoz;
        break;
    case '/':
        WyrZ.Op = Op_Dziel;
        break;
    default:
        wej.setstate(ios::badbit);
        break;
    }
    wej >> WyrZ.Arg2;
    return wej;
}

//Funkcja wyswietlajaca wyrazenie zespolone
void Wyswietl(WyrazenieZesp liczba)
{
    string znak;

    Wyswietl(liczba.Arg1);
    switch (liczba.Op)
    {

    case 0:
        cout << "+";

        break;
    case 1:
        cout << "-";

        break;
    case 2:
        cout << "*";
        break;
    case 3:
        cout << "/";
        break;
    }
    Wyswietl(liczba.Arg2);
} ///f-cja wyswietl pytanie

//Funkcja wypisujaca wyrazenie zespolone
//Dzialaniem tej funkcji jest wstawienie odpowiedniego znaku miedzy dwie liczby zespolone
ostream &operator<<(ostream &wyj, const WyrazenieZesp liczba)
{

    wyj << liczba.Arg1;
    switch (liczba.Op)
    {

    case 0:
        wyj << "+";

        break;
    case 1:
        wyj << "-";

        break;
    case 2:
        wyj << "*";
        break;
    case 3:
        wyj << "/";
        break;
    }
    wyj << liczba.Arg2;
    return wyj;
}

//Funkcja obliczajaca dzialania na liczbach zespolonych opierajac sie na wczesniej zdefiniowanych operatorach
LZespolona oblicz(WyrazenieZesp liczba)
{
    LZespolona wynik;
    switch (liczba.Op)
    {
    case Op_Dodaj:
        wynik = liczba.Arg1 + liczba.Arg2;
        break;

    case Op_Odejmij:
        wynik = liczba.Arg1 - liczba.Arg2;
        break;

    case Op_Mnoz:
        wynik = liczba.Arg1 * liczba.Arg2;
        break;

    case Op_Dziel:
        wynik = liczba.Arg1 / liczba.Arg2;
        break;
    }
    return wynik;
}
