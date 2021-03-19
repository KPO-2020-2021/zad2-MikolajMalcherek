#include "LZespolona.hh"
using namespace std;
#include <iostream>
#include <cmath>

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;

}




/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}



/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im + Skl1.im*Skl2.re;
  return Wynik;
}



/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona  Wynik;
  double mianownik;
  Wynik = Skl1*sprzezenie(Skl2);
  mianownik = pow(modul(Skl2),2);
  Wynik = Wynik/mianownik;
  return Wynik;
}



//Funckja pomocna do funkcji powyzszej aby podzielic liczbe typu LZespolona przez liczbe typu double
//Definiujemy operator dzielenia dla zmiennych o typach LZespolona i double
LZespolona operator / (LZespolona Skl1, double mianownik)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re/mianownik;
  Wynik.im = Skl1.im/mianownik;
  return Wynik;
}

//Sprzezenie liczby zespolonej
LZespolona sprzezenie(LZespolona urojona)
{
  urojona.im = urojona.im * (-1);
  return urojona;
}


//modul liczby zespolonej
double modul(LZespolona liczba)
{
  double modul;
  modul = sqrt((liczba.im*liczba.im) + (liczba.re*liczba.re));
  return modul;
}


//Funckja wyswietlajaca liczbe zespolona
void Wyswietl(LZespolona wynik)
{
        string znak;
    if(wynik.im<0)
    {
        znak = "";
    }
    else znak = '+';

    cout << "(" << wynik.re << znak << wynik.im << "i)" << endl; 
}




//Funckja sluzaca wypisaniu liczby zespolonej
ostream & operator << (ostream &wyj, const LZespolona LZesp)
{
  wyj << " (" << LZesp.re << showpos << LZesp.im << "i)" << noshowpos;
  return wyj;
}



//Funkcja sluzaca wczytaniu liczby zespolonej
istream & operator >> (istream &wej, LZespolona& LZesp)
{
  char znak;
  wej >> znak;
  if(znak!='(')
  {
    wej.setstate(ios::badbit);
  }
  wej >> LZesp.re;
  wej >> LZesp.im;
  wej >> znak;
    if(znak!='i')
  {
    wej.setstate(ios::badbit);
  }
  wej >> znak;
      if(znak!=')')
  {
    wej.setstate(ios::badbit);
  }
  return wej;
}



//Funkcja przyrownania dwoch liczb zespolonych
bool operator == (LZespolona Skl1 , LZespolona Skl2)
{
  if(abs(Skl1.re- Skl2.re)<=0.01 && abs(Skl1.im- Skl2.im)<=0.01)
  {
    return true;
  }
  return false;
}