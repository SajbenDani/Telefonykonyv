#include <iostream>
#include <fstream>
#include "memtrace.h"
#include "cstring"
#include "Nevjegy.h"
#include "Ceg.h"
#include "Ember.h"
#include "String.h"
#include "Telefonkonyv.h"




using namespace std;
int main() {
    Telefonkonyv telefonkonyv;
    telefonkonyv.filebol_feltolt("Lista.txt");

    String name;
    int valasz;
    char valaszchar;
    String szerkesztett;
    LABELdefault:
    std::cout << "Valasszon az alabbi lehetosegek kozul: " << std::endl << "1. listazas" << std::endl << "2. uj kontakt felvetele" << std::endl << "3. Kontakt torlese" << std::endl << "4. szerkesztes" << std::endl << "5. nev alapjan kereses" << std::endl <<"6. kilepes es mentes" << std::endl << std::endl;
    std::cin >> valasz;
    switch(valasz){
        case 1:
            telefonkonyv.listaz();
            goto LABELdefault;
            //break;
        case 2:
            LABEL1:
            std::cout << "A. Ember, B. Ceg" << std::endl;
            char tipus;
            std::cin >> tipus;
            if(tipus == 'A' || tipus == 'a'){
                std::cout << "Kerem adja meg a kovetkezo adatokat ebben a sorrendben" << std::endl << "Nev Telefonszam Cim(Formatum:Varos Utca Hazszam) Becenev" << std::endl;
                String nev, szam, becenev, city, street, streettype, adress;
                std::cin >> nev;
                std::cin >> szam;
                std::cin >> city >> street >> streettype >> adress;
                std::cin >> becenev;
                String cim = city+" "+street+" "+streettype+" "+adress;

                Ember* uj = new Ember(nev, szam, cim, becenev);
                telefonkonyv.Insert(uj);
                telefonkonyv.fileba_ment("Lista.txt");
                goto LABELdefault;
                //break;
            }
            if(tipus == 'B' || tipus == 'b'){
                std::cout << "Kerem adja meg a kovetkezo adatokat ebben a sorrendben" << std::endl << "Nev Telefonszam Cim(Formatum:Varos Utca Hazszam) Adoszam" << std::endl;
                String nev, szam, adoszam, city, street, streettype, adress;
                std::cin >> nev;
                std::cin >> szam;
                std::cin >> city >> street >> streettype >> adress;
                std::cin >> adoszam;
                String cim = city+" "+street+" "+streettype+" "+adress;

                Ceg *uj = new Ceg(nev, szam, cim, adoszam);
                telefonkonyv.Insert(uj);
                telefonkonyv.fileba_ment("Lista.txt");
                goto LABELdefault;
                //break;
            }
            else {
                std::cout << "Kerem A-t vagy B-t adjon meg" << std::endl;
                goto LABEL1;
            } //checking
        case 3:
            std::cout << "Kit szeretne torolni?" << std::endl;
            std::cin >> name;
            try {
                telefonkonyv.elem_torlese(name);
            }
            catch (const char* Hiba2){
                std::cout << Hiba2 << std::endl;
                goto LABELdefault;
            }

            telefonkonyv.fileba_ment("Lista.txt");
            goto LABELdefault;
        case 4:
            LABELERROR:
            std::cout << "Kit szeretne szerkeszteni?" << std::endl;
            std::cin >> name;
            std::cout << "Milyen adatot szeretne szerkeszteni? (A. nev, B. szam, C. cim, D. becenev/adoszam)" << std::endl;
            std::cin >> valaszchar;
            std::cout << "Mi legyen az uj adat?" << std::endl;
            std::cin >> szerkesztett;
            try
            {
                telefonkonyv.szerkeszt(name, szerkesztett, valaszchar);
            }
            catch (const char* Hiba)
            {
                std::cout << Hiba << std::endl;
                goto LABELERROR;
            }
            telefonkonyv.fileba_ment("Lista.txt");
            goto LABELdefault;
        case 5:
            std::cout << "Kit szeretne megkeresni?" << std::endl;
            std::cin >> name;
            try
            {
                telefonkonyv.keres(name);
            }
            catch (const char* Hiba)
            {
                std::cout << Hiba << std::endl;
                goto LABELdefault;
            }
            goto LABELdefault;
        case 6:
            std::cout << "Kilepes!" << std::endl;
            telefonkonyv.fileba_ment("Lista.txt");
            break;
    }

    return 0;
}
