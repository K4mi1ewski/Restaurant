/** @file */

#include "funkcje.h"
#include "struktury.h"
using namespace std;





int main(int argc, char* argv [])
{
    string parametr = argv[1];
    if (argc != 4 || parametr != "-s")
    {
        cerr << "POPRAWNE WYWOLANIE: " << argv[0] << " -s (numer stolika) (nazwa pliku tekstowego) ";
        return 0;
    }
    int numer_stolika = stoi(argv[2]);
    string nazwa_pliku = argv[3];

    ifstream plik (nazwa_pliku);
    if (plik.bad())
    {
        cerr << "Niepoprawny plik!!!" << endl;
        return 0;
    }
   
    vector <string> kategorie;
    vector <danie> menu;
    vector <danie> zamowienie;
    wczytaj_do_menu(nazwa_pliku, menu, kategorie);
 
    
   
    char wybor_kat;
    int N;
    int wybor_dania;
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
                        if (element.nazwa.size() > maxi_rozmiar_nazwy)
                            maxi_rozmiar_nazwy = element.nazwa.size();
                    }
                }

                for (auto el : menu)
                {    
                    if (el.kategoria == kategorie[N])
                    {
                        stringstream strumien; char znak; int dokladnosc = 2;
                        size_t rozmiar_nazwy = el.nazwa.size();
                          int przesuniecie = maxi_rozmiar_nazwy - rozmiar_nazwy  + 7;
                          strumien << el.cena;
                          while (strumien >> znak)
                          {
                              if (znak == '.')
                                  break;
                              else
                                  dokladnosc++;
                          }

                        cout << setw(2) << el.id << " " << el.nazwa << " " << setprecision(dokladnosc) << showpoint << setw (przesuniecie) << el.cena << "; " << el.opis << endl;
                    }
                }
                cout << endl << "0  Powrot" << endl;
                cin >> wybor_dania;
                
                for (auto el : menu)
                {
                    if (el.id == wybor_dania && el.kategoria == kategorie[N])
                    {
                        zamowienie.push_back(el);
                    }
                    else if (el.id == wybor_dania && el.kategoria != kategorie[N])
                    {
                        cerr << "Tego dania nie ma w tej kategorii!" << endl;
                        Sleep(5000);
                    }
                }

            } while (wybor_dania != 0);

        }
        else if (wybor_kat == 'R' || wybor_kat == 'r')
        {
            zamowienie.erase(zamowienie.begin(), zamowienie.end());
        }
        else
        {
            cerr << "NIEPOPRAWNY ZNAK! WYBIERZ NUMER OD 1 DO " << kategorie.size() << " LUB 0 ABY ZAKONCZYC; MOZESZ WYCZYSCIC ZAMOWIENIE WPROWADZAJAC 'R' ";
            Sleep(5000);
        }
        system("cls");
    } while (wybor_kat != '0');
    
    podsumuj(zamowienie, numer_stolika);
   
    
    return 0;
    
  

}


