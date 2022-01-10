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

void wczytaj_do_menu(const string& name, vector<danie>& w)
{
    vector <string> linie;
    ifstream baza(name);
    string linia, id, nazwa, kategoria, cena, opis;
    stringstream ss;
    char znak;
    
    if (baza.is_open())
    {
        while (!baza.eof())
        {
            string id = "", nazwa = "", kategoria = "", cena = "", opis = "";
            do {
                baza.get(znak);
                if (baza && znak != ';' )
                {   
                    
                    id.push_back(znak);
                }
            } while (znak != ';');
            cout <<  id << " ";

            do {
                baza.get(znak);
                if (baza && znak != ';' )
                {
                    nazwa.push_back(znak);
                }
            } while (znak != ';');
            cout  << nazwa << " ";

            do {
                baza.get(znak);
                if (baza && znak != ';')
                {
                    kategoria.push_back(znak);
                }
            } while (znak != ';');
            cout   << kategoria << " ";

            do {
                baza.get(znak);
                if (baza && znak != ';')
                {
                    cena.push_back(znak);
                }
            } while (znak != ';');
            cout  << cena << " ";

            do {
                baza.get(znak);
                if (baza && znak != ';')
                {
                    opis.push_back(znak);
                }
            } while (znak != ';');
            cout << opis << " ";
        }

    }
   
    
    
    
    
    
    
    baza.close();
}

void separator()
{
    cout << endl << " -------------------------------------------------------------------------- " << endl;
}





