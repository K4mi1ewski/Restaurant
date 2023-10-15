/** @file */

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include "funkcje.h"
using namespace std;
/** Potrawa wczytana z pliku posiadajaca 5 danych */
struct danie {
    int id; ///< Id danej liczby, czyli numer, ktory wprowadza uzytkownik aby zamowic potrawe
    string nazwa; ///< Nazwa potrawy 
    string kategoria; ///< Kategoria potrawy
    double cena; ///< Cena potrawy
    string opis; ///< Krotki opis potrawy
};
#endif