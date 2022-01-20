/** @file */

#include "funkcje.h"
#include "struktury.h"
using namespace std;
int main(int argc, char* argv [])
{
    if (argc != 4 || strcmp (argv[1], "-s")!= 0 || czy_liczba(argv[2]) == false)
    {
        cerr << "POPRAWNE WYWOLANIE: " << argv[0] << " -s (numer stolika) (nazwa pliku tekstowego) ";
        return 0;
    }
    int numer_stolika = stoi(argv[2]);
    string nazwa_pliku = argv[3];

    ifstream plik (nazwa_pliku);
    if (!plik)
    {
        cerr << "Niepoprawny plik!!!" << endl;
        return 0;
    }
    plik.close();
    vector <string> kategorie;
    vector <danie> menu;
    vector <danie> zamowienie;
    wczytaj_do_menu(nazwa_pliku, menu, kategorie);
    char wybor_kat;
    int N;
    string wybor_dania;
    do {
        wyswietl_menu(kategorie);
        cin >> wybor_kat;
        N = wybor_kat - '0' - 1;
        if (wybor_kat == '0')
        {
           break;
        }
        int N_ = N + 1;
        size_t T = N_;
        if (T <= kategorie.size())
        {
            do
            {
                system("cls");
                cout << "===" << kategorie[N] << " ===" << endl;
                size_t maxi_rozmiar_nazwy = 0; 
                for (auto element : menu)
                {  
                    if (element.kategoria == kategorie[N])
                    {
                        if (strlen (element.nazwa.c_str()) > maxi_rozmiar_nazwy)
                            maxi_rozmiar_nazwy = strlen (element.nazwa.c_str());
                    }
                }

                for (auto el : menu)
                {    
                    if (el.kategoria == kategorie[N])
                    {
                        const int dwa = 2; const int odstep = 7;
                        size_t rozmiar_nazwy = strlen (el.nazwa.c_str());
                        size_t przesuniecie = maxi_rozmiar_nazwy - rozmiar_nazwy  + odstep;
                        cout << setw(dwa) << el.id << " " << el.nazwa << " " << setprecision(dwa) << showpoint << fixed << setw (przesuniecie) << el.cena << "; " << el.opis << endl;
                    }
                }
                cout << endl <<  "0  Powrot" << endl;
                cin >> wybor_dania;
                bool sprawdz = czy_liczba(wybor_dania.c_str());
                if (sprawdz == true)
                {
                    int numer_dania = stoi(wybor_dania);
                    for (auto el : menu)
                    {
                        if (el.id == numer_dania && el.kategoria == kategorie[N])
                        {
                            zamowienie.push_back(el);
                        }
                        else if (el.id == numer_dania && el.kategoria != kategorie[N])
                        {
                            cerr << "Tego dania nie ma w tej kategorii!" << endl;
                            cin.clear(); getchar(); getchar();
                        }
                    }
                }
                else
                {
                    cerr << "Prosze wprowadzic liczbe!" << endl;
                    cin.clear(); getchar(); getchar();
                }
            } while (wybor_dania != "0");

        }
        else if (wybor_kat == 'R' || wybor_kat == 'r')
        {
            zamowienie.erase(zamowienie.begin(), zamowienie.end());
        }
        else
        {
            cerr << "NIEPOPRAWNY ZNAK! WYBIERZ NUMER OD 1 DO " << kategorie.size() << " LUB 0 ABY ZAKONCZYC; MOZESZ WYCZYSCIC ZAMOWIENIE WPROWADZAJAC 'R' ";
            cin.clear(); getchar(); getchar();
        }
        system("cls");
    } while (wybor_kat != '0');
    
    podsumuj(zamowienie, numer_stolika);
   
    
    return 0;
    
  

}


