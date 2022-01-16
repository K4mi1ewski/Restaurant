#include "funkcje.h"
#include "struktury.h"

using namespace std;
void wczytaj(const string& name, vector<string>& w) {
    ifstream baza(name);
    string linia;
    if (baza)
    {
        while (getline(baza, linia))
            w.push_back(linia);
    }

    baza.close();
}

void wypisz(vector <string>& w)
{
    for (const string& el : w)
        cout << el << endl;
}

void wczytaj_do_menu(const string& name, vector<danie>& w, vector <string>& kategorie)
{
    ifstream baza(name);
    string linia;
    stringstream ss;
    char znak;
    string  nazwa, kategoria, opis, id_, cena_;
    int id;
    double cena;
    if (baza.good()) {
        while (!baza.eof())
        {
            getline(baza, linia, ';');
            id = stoi(linia);

            getline(baza, nazwa, ';');

            getline(baza, kategoria, ';');

            getline(baza, linia, ';');
            ss << linia;
            while (ss >> znak)
            {
                if (isdigit(znak))
                    cena_ += znak;
                else if (znak == ',')
                    cena_ += '.';
            };
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

            cena_.clear(); id_.clear();
        }

    }
   
         baza.close();
}



void separator()
{
    cout << endl << " -------------------------------------------------------------------------- " << endl;
}

void wypisz_menu(vector <danie>& w)
{
    for (auto el : w)
    {
        cout << setw (4)  << el.id << setw (8 ) << el.nazwa << setw (16) << el.kategoria << setw (4) << el.cena  <<  setw (4) << el.opis << endl;
    }
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
        plik << "Stolik nr " << nr_stolika << endl;
        for (auto el : zamowienie)
        {
            plik << el.nazwa << "       " << setprecision(2) << showpoint << el.cena << endl;
        }
        plik << "===============" << endl;
        plik << setprecision(2) << showpoint << suma;
    }
    plik.close();
    
}