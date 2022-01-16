

#include "funkcje.h"
#include "struktury.h"
using namespace std;





int main(int argc, char* argv [])
{
   
    if (argc != 4 || argv[1] != "-s")
    {
        cerr << "POPRAWNE WYWOLANIE: " << argv[0] << "-s (numer stolika) (nazwa pliku tekstowego) ";
        return 0;
    }
    
    int numer_stolika = stoi (argv[2]);
    string nazwa_pliku = argv[3];
    vector <string> kategorie;
    vector <danie> menu;
    vector <string> napisy;
    vector <danie> zamowienie;
    wczytaj_do_menu("baza.txt", menu, kategorie);
    separator();
    
    wczytaj("baza.txt", napisy);
    wypisz(napisy);
    separator();
    wypisz_menu(menu);
    separator();
    wypisz(kategorie);
    separator();
    wyswietl_menu(kategorie);
    separator();
    char wybor_kat;
    int* N = new int;
    int wybor_dania;
    do {
        wyswietl_menu(kategorie);
        cin >> wybor_kat;
        *N = wybor_kat - '0';
        if (*N == 0)
        {
           break;
        }
        if (*N <= kategorie.size())
        {
            do
            {
                system("cls");
                cout << "===" << kategorie[(*N) - 1] << "===" << endl;
                for (auto el : menu)
                {
                    if (el.kategoria == kategorie[(*N) - 1])
                        cout << el.id << " " << setw(6) << el.nazwa << " " << el.kategoria << " " << setprecision(2) << showpoint << el.cena << "; " << el.opis << endl;
                }
                cout << endl << "0  Powrot";
                cin >> wybor_dania;
                
                for (auto el : menu)
                {
                    if (el.id == wybor_dania && el.kategoria == kategorie[(*N) - 1])
                    {
                        zamowienie.push_back(el);
                    }
                    else if (el.id == wybor_dania && el.kategoria != kategorie[(*N) - 1])
                        cerr << "Tego dania nie ma w tej kategorii!" << endl;
                   
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
        }
        system("cls");
    } while (wybor_kat != '0');
    
    podsumuj(zamowienie, numer_stolika);
   
    
    return 0;
    
  

}


