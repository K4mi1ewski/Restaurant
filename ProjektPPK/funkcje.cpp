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
    while (!baza.eof())
    {
      
         
        getline(baza, linia, ';');
        id = stoi(linia);
       
        
        ss.clear();
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
        cout << setw (4) << el.id << el.nazwa << el.kategoria << el.cena << el.opis << endl;
    }



}



