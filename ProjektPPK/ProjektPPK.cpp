

#include "funkcje.h"
#include "struktury.h"
using namespace std;





int main(int argc, char argv [])
{
    vector <danie> menu;
    vector <string> napisy;
    wczytaj("baza.txt", napisy);
    wypisz(napisy);
    separator();
    wczytaj_do_menu("baza.txt", menu);
    
    
    
    
    
  

}


