#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

void Wyswietl(LZespolona wynik);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona Skl1 , LZespolona Skl2);
LZespolona operator * (LZespolona Skl1 , LZespolona Skl2);
LZespolona operator / (LZespolona Skl1 , LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, double mianownik);
double modul(LZespolona liczba);
LZespolona sprzezenie(LZespolona urojona);




ostream & operator << (ostream &wyj, const LZespolona LZesp);
istream & operator >> (istream &wej, LZespolona& LZesp);


bool operator == (LZespolona Skl1 , LZespolona Skl2);



#endif
