#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "struktury.h"
using namespace std;




void wczytaj(const string& name, vector<string>& w);
void wczytaj_do_menu(const string& name, vector<danie>& w, vector <string> & kategorie);
void wypisz(vector<string>& w);
void separator();
void wypisz_menu(vector <danie>& w);
void wyswietl_menu(vector <string>& kat);
void podsumuj (vector <danie> zamowienie, const int& nr_stolika);