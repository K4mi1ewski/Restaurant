#include "funkcje.h"
#include "struktury.h"


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

void wczytaj_do_menu(const string& name, vector<danie>& w)
{
    vector <string> linie;
    ifstream baza(name);
    string linia, id, nazwa, kategoria, cena, opis;
    stringstream ss;
    char znak;
    
    if (baza)
    {
        do {
            baza.get(znak);
            if (baza)
            {
                id.push_back(znak);
            }
        } while (znak != ';');
        cout << id;
        
    
       
        do {
            baza.get(znak);
            if (baza)
            {
                nazwa.push_back(znak);
            }
        } while (znak != ';');
        cout << nazwa;
    
    
    
    }
   
    
    
    
    
    
    
    baza.close();
}

void separator()
{
    cout << endl << " -------------------------------------------------------------------------- " << endl;
}





