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
void wczytaj_do_menu(const string& name, vector<danie>& w);
void wypisz(vector<string>& w);
void separator();