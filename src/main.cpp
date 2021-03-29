#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"
using namespace std;

int main(int argc, char **argv)
{

  if (argc < 2)
  {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu BazaT = {nullptr, 0, 0};
fstream plik;
  if (InicjalizujTest(plik, argv[1]) == false)
  {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  LZespolona odpowiedz;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona wynik;
Statystyka stat;
//Inicjujemy statystyke uzytkownika, czyli funkcje liczenia uzyskanych punktow
Inicjuj(stat);
  while (PobierzNastpnePytanie(plik, &WyrZ_PytanieTestowe))
  {
    cout << "Podaj wynik operacji " << WyrZ_PytanieTestowe <<": "<< endl;

    for (int i = 0; i < 3; i++)
    {
      cin >> odpowiedz;
      if (cin.bad())
      {
        cout << "Blad wczytywania";
      }
      else
      {
        break;
      }

      cin.clear();
      cin.ignore(1024, '\n');
    }



/*Jesli odpowiedz jest poprawna dodaje punkt*/
    wynik = oblicz(WyrZ_PytanieTestowe);
    if(wynik==odpowiedz)
    {
      cout<<"dobrze"<<endl;
      stat.Pop++;
    }
    else
    {
     cout << "zle wynik to: ";
     stat.Ble++;
    Wyswietl(wynik); 

    }
    stat.Wszystkie++;
        cout << "wynik po += to: ";
    LZespolona a;
    LZespolona b;
    LZespolona c;

    a.im = WyrZ_PytanieTestowe.Arg1.im;
    a.re =  WyrZ_PytanieTestowe.Arg1.re;

    c=a;

    b.im =  WyrZ_PytanieTestowe.Arg2.im;
    b.re = WyrZ_PytanieTestowe.Arg2.re;

    a += b;

    cout << a.re << "    " << a.im << endl;
    c /=b;
    cout << "wynik po /= to: ";
    cout << c.re << "    " << c.im << endl;



  }
plik.close();
//Wyswietla wynik testu
Wyswietl(stat);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
