/** @file */

#include "funkcje.h"
#include "struktury.h"
using namespace std;
int main(int argc, char* argv[])
{
    if (argc != 4 || strcmp(argv[1], "-s") != 0 || czy_liczba(argv[2]) == false)
    {
        cerr << "NIEPRAWIDLOWE PARAMETRY! POPRAWNE WYWOLANIE: " << argv[0] << " -s (numer stolika) (nazwa pliku tekstowego) ";
        return 0;
    }
    int numer_stolika = stoi(argv[2]);
    string nazwa_pliku = argv[3];

    ifstream plik(nazwa_pliku);
    if (!plik)
    {
        cerr << "Plik <" << nazwa_pliku << "> nie zostal znaleziony!" << endl;
        return 0;
    }
    plik.close();
    vector <string> kategorie;
    vector <danie> menu;
    vector <danie> zamowienie;
    wczytaj_do_menu(nazwa_pliku, menu, kategorie);
    string wybor_kat;
    int N;
    string wybor_dania;
    do {
        wyswietl_menu(kategorie);
        cin >> wybor_kat;
        if (czy_liczba(wybor_kat.c_str()) == true)
        {
            N = stoi(wybor_kat) - 1;
            if (stoi(wybor_kat) == 0)
            {
                break;
            }
            size_t T = stoi(wybor_kat);
            if (T <= kategorie.size())
            {
                do
                {
                    system("cls");
                    cout << "====" << kategorie[N] << " ====" << endl;
                    size_t maxi_rozmiar_nazwy = 0; double max_cena = 0;
                    for (auto element : menu)
                    {
                        if (element.kategoria == kategorie[N])
                        {
                            if (strlen(element.nazwa.c_str()) > maxi_rozmiar_nazwy)
                                maxi_rozmiar_nazwy = strlen(element.nazwa.c_str());
                        }
                        if (element.cena > max_cena)
                            max_cena = element.cena;
                    }
                    string cena_temp; stringstream strumien;
                    strumien << max_cena; strumien >> cena_temp;
                    size_t max_cena_dlugosc = strlen(cena_temp.c_str());
                    strumien.clear();
                    for (auto el : menu)
                    {
                        if (el.kategoria == kategorie[N])
                        {
                            const int dwa = 2; const int odstep = 7;
                            size_t rozmiar_nazwy = strlen(el.nazwa.c_str());
                            size_t przesuniecie = maxi_rozmiar_nazwy - rozmiar_nazwy + odstep + max_cena_dlugosc;
                            cout << setw(dwa) << el.id << " " << el.nazwa << " " << setprecision(dwa) << showpoint << fixed << setw(przesuniecie) << el.cena << "; " << el.opis << endl;
                        }
                    }
                    cout << endl << "0  Powrot" << endl;
                    cin >> wybor_dania;
                    bool sprawdz = czy_liczba(wybor_dania.c_str());
                    bool czy_istnieje = false;
                    if (sprawdz == true)
                    {
                        int numer_dania = stoi(wybor_dania);
                        for (auto el : menu)
                        {
                            if (el.id == numer_dania && el.kategoria == kategorie[N])
                            {
                                zamowienie.push_back(el);
                                czy_istnieje = true;
                                cin.clear();
                            }
                            else if (el.id == numer_dania && el.kategoria != kategorie[N])
                            {
                                cerr << "Tego dania nie ma w tej kategorii!" << endl;
                                czy_istnieje = true;
                                cin.clear(); getchar(); getchar();
                            }
                        }
                        if (!czy_istnieje && numer_dania != 0)
                        {
                            cerr << "Nie ma dania o takim numerze! Sprobuj ponownie!" << endl;
                            cin.clear(); getchar(); getchar();
                        }
                    }
                    else
                    {
                        cerr << "Prosze wprowadzic liczbe!" << endl;
                        cin.clear(); getchar(); getchar();
                    }
                } while (wybor_dania != "0");
            }
            else
            {
                cerr << "NIE MA TAKIEJ KATEGORII, WYBIERZ NUMER OD 1 DO " << kategorie.size() << " LUB 0 ABY ABY ZAKONCZYC; MOZESZ WYCZYSCIC ZAMOWIENIE WPROWADZAJAC 'R' ";
                cin.clear(); getchar(); getchar();
            }
        }
        else if (wybor_kat == "R" || wybor_kat == "r")
        {
            zamowienie.erase(zamowienie.begin(), zamowienie.end());
        }
        else
        {
            cerr << "NIEPOPRAWNY ZNAK! WYBIERZ NUMER OD 1 DO " << kategorie.size() << " LUB 0 ABY ZAKONCZYC; MOZESZ WYCZYSCIC ZAMOWIENIE WPROWADZAJAC 'R' ";
            cin.clear(); getchar(); getchar();
        }
        system("cls");
    } while (wybor_kat != "0");

    podsumuj(zamowienie, numer_stolika);

    return 0;
}