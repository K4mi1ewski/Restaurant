/** @file */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include "struktury.h"
using namespace std;

/** Funkcja odczytuje dane dotyczace potraw z pliku i zapisuje je do wektorow.
@param name Nazwa pliku ktory funkcja otwiera i z ktorego czyta dane
@param w Wektor struktur do ktorego funkcja zapisuje dane
@param kategorie Wektor nazw (stringow) do ktorego funkcja zapisuje kategorie potraw */
void wczytaj_do_menu(const string& name, vector<danie>& w, vector <string>& kategorie);

/** Funkcja wypisuje na ekran kategorie potraw z menu do wyboru.
@param kat Wektor kategorii, ktore funkcja wypisuje na ekran
*/
void wyswietl_menu(vector <string>& kat);

/** Funkcja podsumowuje zamowienie i zapisuje je do pliku.
@param zamowienie Wektor z potrawami wybranymi przez klienta
@param nr_stolika Numer stolika ktory zostanie zapisany w tytule wyjsciowego pliku
*/
void podsumuj(vector <danie> zamowienie, const int& nr_stolika);

/** Funkcja sprawdza, czy dany ciag znakow jest liczba.
@param napis Ciag znakow do sprawdzenia
@return Wartosc true gdy w ciagu znakow wystepowaly tylko cyfry, w przeciwnym wypadku wartosc false
*/
bool czy_liczba(const char* napis);
#endif
