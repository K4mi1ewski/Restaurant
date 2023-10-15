/** @file */

#include "funkcje.h"
#include "struktury.h"

using namespace std;

void wczytaj_do_menu(const string& name, vector<danie>& w, vector <string>& kategorie)
{
    ifstream baza(name);
    stringstream ss;
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


void wyswietl_menu(vector <string>& kat)
{
    for (size_t i = 0; i < kat.size(); i++)
    {
        cout << i + 1 << setw(5) << kat[i] << endl;
    }
    cout << endl << "0"; cout << "  " << "Zloz zamowienie" << endl;
    cout << endl << "R" << "  " << "Wyczysc zamowienie" << endl;
}

void podsumuj(vector <danie> zamowienie, const int& nr_stolika)
{
    const int dwa = 2; //program ma wyswietlac dwie liczby po kropce 
    const int odstep = 7; // tyle ma wynosic odstep miedzy najdluzsza nazwa produktu a cena
    string nazwa_pliku = "S";
    stringstream ss; ss << nr_stolika;
    char znak;
    while (ss >> znak)
        nazwa_pliku.push_back(znak);
    ss.str(""); ss.clear();

    nazwa_pliku.push_back('.');   nazwa_pliku.push_back('t');  nazwa_pliku.push_back('x');  nazwa_pliku.push_back('t');
    double suma = 0;
    for (auto el : zamowienie)
        suma += el.cena;

    ofstream plik(nazwa_pliku);
    if (plik.is_open()) {
        plik << "Stolik nr " << nr_stolika << endl << endl;
        size_t maxi_nazwa = 0; double maxi_cena = 0;
        for (auto element : zamowienie)
        {
            if (strlen(element.nazwa.c_str()) > maxi_nazwa)
                maxi_nazwa = strlen(element.nazwa.c_str());

            if (element.cena > maxi_cena)
                maxi_cena = element.cena;
        }
        string cena_tmp;
        ss << maxi_cena; ss >> cena_tmp; ss.clear();
        size_t maxi_cena_dlugosc = strlen(cena_tmp.c_str());
        for (auto el : zamowienie)
        {
            size_t dlugosc_nazwy = strlen(el.nazwa.c_str());
            size_t przesun = maxi_nazwa - dlugosc_nazwy + odstep + maxi_cena_dlugosc;
            plik << el.nazwa << " " << setprecision(dwa) << fixed << showpoint << setw(przesun) << el.cena << endl;
        }
        size_t zakres = maxi_nazwa + maxi_cena_dlugosc + odstep + dwa;
        for (size_t i = 0; i < zakres; i++)
        {
            plik << "=";
        }
        plik << endl;
        plik << setprecision(dwa) << fixed << showpoint << suma;
    }
    plik.close();
}

bool czy_liczba(const char* napis)
{
    char znak; stringstream strumien;
    strumien << napis;
    while (strumien >> znak)
    {
        if (!isdigit(znak))
        {
            return false;
        }
    }
    return true;
}