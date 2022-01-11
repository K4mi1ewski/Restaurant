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

    if (baza.is_open())
    {
        string  nazwa, kategoria, opis;
        int id; double cena;
          while (getline(baza, linia))
          {
                ss << linia;
                string id_, cena_;
                stringstream laduj;
                do {
                    
                    ss.get(znak);
                    if (baza && znak != ';' && znak != 32)
                    {  
                        id_.push_back(znak);
                    }
                  
                } while (znak != ';');
                laduj << id_;
                laduj >> id;
                cout << id << " ";
                
                do {
                    ss.get(znak);
                    if (baza && znak != ';' )
                        nazwa.push_back(znak);
                
                } while (znak != ';');
                cout << nazwa << " ";
                do {
                    ss.get(znak);
                    if (baza && znak != ';' && znak != 32)
                        kategoria.push_back(znak);
                } while (znak != ';');
                
                cout << kategoria << " ";
               
                do {

                    ss.get(znak);
                    if (baza && znak != ';' && znak != 32)
                    {
                        cena_.push_back(znak);
                    }

                } while (znak != ';');
                laduj.clear();
                laduj << cena_;
                laduj >> cena;

                cout << cena << " ";
                getline(ss, opis);
               /*do {
                    ss.get(znak);
                    if (baza && znak != ';')
                        opis.push_back(znak);

                } while (!ss.eof());*/
                cout << opis << " ";
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
            
            
                ss.clear(); id = 0; cena = 0; opis = "", kategoria = "", nazwa = "";
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



