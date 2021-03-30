#include "LZespolona.hh"
using namespace std;
#include <iostream>
#include <cmath>
#include <iomanip>


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
  if(mianownik==0)
  {
    throw "nie dzieli sie przez zero";
  }
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
  wyj << "(" << fixed << setprecision(2) << LZesp.re << showpos << fixed << setprecision(2) << LZesp.im << "i)" << noshowpos;
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



LZespolona operator += (LZespolona &Arg1, LZespolona const &Arg2)
{
  Arg1 = Arg1 + Arg2;
  return Arg1;
}


/*
LZespolona operator += (LZespolona &Arg1, LZespolona const &Arg2)
{

  Arg1.im = Arg1.im + Arg2.im;
  Arg1.re = Arg1.re + Arg2.re;
  return Arg1;
}
*/





//Dla ulamkow program obliczy wynik z pelna dokładnoscia , jedynie przy wypisaniu odpowiedzi zaokragli do dwoch miejsc po przecinku
LZespolona operator /= (LZespolona &Arg1, LZespolona const &Arg2)
{
Arg1=Arg1/Arg2;
return Arg1;
}





double arg(LZespolona z){
  double r = modul(z);
  double sigma;
if(z.re!=0)
{
  if(z.re>0)
  {
    sigma=atan2(z.im,z.re);
  }
  if(z.re<0)
  {
    sigma=atan2(z.im,z.re);
  }
}
  if(z.re=0){
    if(z.im>0)
    {
      sigma = 3.14/2;
    }

    if(z.im<0){
      sigma = -3.14/2;
    }

    else{
      cout << "Nie można określić argumentu-czesc rzeczywista i urojona sa rowne 0!" << endl;
    }

  }
  return 1;

}




/*
LZespolona operator /= (LZespolona &Arg1, LZespolona const &Arg2)
{
  LZespolona  Wynik;
  double mianownik;
  Arg1 = Arg1*sprzezenie(Arg2);
  mianownik = pow(modul(Arg2),2);
  Arg1 = Arg1/mianownik;
  return Arg1;
}
*/
