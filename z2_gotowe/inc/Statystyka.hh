#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>
using namespace std;

struct Statystyka
{
    int Pop;
    int Ble;
    int Wszystkie;
};

void Wyswietl(Statystyka stat);
void Inicjuj(Statystyka &stat);

#endif