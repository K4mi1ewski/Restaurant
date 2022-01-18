/** @file */

#include "funkcje.h"
#include "struktury.h"

using namespace std;




void wczytaj_do_menu(const string& name, vector<danie>& w, vector <string>& kategorie)
{
    ifstream baza(name);
    //string linia;
    stringstream ss;
    //char znak;
    string  nazwa, kategoria, opis, id_, cena_;
    int id;
    double cena;
    if (baza.good()) {
        while (!baza.eof())
        {
            getline(baza, id_, ';');
            id = stoi(id_);

            getline(baza, nazwa, ';');

            getline(baza, kategoria, ';');

            getline(baza, cena_, ';');
          //  ss << linia;
          //  while (ss >> znak)
          // {
          //      if (isdigit(znak))
          //          cena_ += znak;
          //      else if (znak == ',')
          //          cena_ += '.';
          //  };
            cena = stod(cena_);
            getline(baza, opis);

            w.push_back({ id, nazwa, kategoria, cena, opis });

            bool nowa_kategoria = true;
            for (auto el : kategorie)
            {
                if (el == kategoria)
                {
                    nowa_kategoria = false;
                    break;
                }
            }
            if (nowa_kategoria)
                kategorie.push_back(kategoria);
   
        }

    }
   
         baza.close();
}


void wyswietl_menu(vector <string> &kat)
{   for (size_t i = 0; i < kat.size(); i++)
{
    cout << i + 1 << setw(5) << kat[i] << endl;
}
cout << endl << "0"; cout << "  " << "Zloz zamowienie" << endl;
cout << endl << "R" << "  " << "Wyczysc zamowienie" << endl;
}

void podsumuj (vector <danie> zamowienie, const int& nr_stolika)
{
    string nazwa_pliku = "S";
    stringstream ss; ss << nr_stolika; 
    char znak; 
    while (ss >> znak)
        nazwa_pliku.push_back(znak);
    
    nazwa_pliku.push_back('.');   nazwa_pliku.push_back('t');  nazwa_pliku.push_back('x');  nazwa_pliku.push_back('t');
    double suma = 0;
    for (auto el : zamowienie)
        suma += el.cena;
    
    ofstream plik (nazwa_pliku);
    if (plik.is_open()) {
        plik << "Stolik nr " << nr_stolika << endl << endl;
        for (auto el : zamowienie)
        {
            size_t rozmiar_nazwy = el.nazwa.size();
            plik << el.nazwa  << setprecision(2) << showpoint << setw (25 - rozmiar_nazwy) << el.cena << endl;
        }
        plik << "=========================" << endl;
        plik << setprecision(4) << showpoint << suma;
    }
    plik.close();
    
}