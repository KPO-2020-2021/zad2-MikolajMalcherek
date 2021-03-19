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

  if (InicjalizujTest(&BazaT, argv[1]) == false)
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
  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    cout << "Podaj wynik operacji " << WyrZ_PytanieTestowe << endl;
    cout << ": ";
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
  }

//Wyswietla wynik testu
Wyswietl(stat);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
