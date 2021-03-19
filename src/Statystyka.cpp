#include "Statystyka.hh"


void Wyswietl(Statystyka stat)
{
    cout<<"poprwne odpowiedzi :"<<stat.Pop<<endl;
    cout<<"nie poprwne odpowiedzi :"<<stat.Ble<<endl;
    cout<<"procent dobrych : "<< stat.Pop*100.0/stat.Wszystkie<<"%"<<endl;
}

void Inicjuj(Statystyka &stat)
{
    stat.Pop=0;
    stat.Ble=0;
    stat.Wszystkie=0;
}