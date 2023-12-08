//
// Created by sajbe on 2023. 05. 12..
//
#include "memtrace.h"
#include "Telefonkonyv.h"

void Telefonkonyv::fileba_ment(const char* filename){
    std::ofstream outFile;
    outFile.open(filename);
    if (!outFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        exit(1);   // terminate with error
    }
    outFile << size << std::endl;
    for (size_t i = 0; i < size; ++i) {
        Tomb[i]->kiir_fileformat(outFile);
        outFile << std::endl;
    }
    outFile.close();
}

void Telefonkonyv::keres (String name) {
        bool bennevan = false;
        for(size_t i=0; i < size; i++){
            if(strcmp(Tomb[i]->getnev().c_str(), name.c_str()) == 0){
                bennevan = true;
                break;
            }
        }
        if(!bennevan){
            throw "Nincs ilyen nev!";
        }
        for(size_t i=0; i < size; i++){
            if(strcmp(Tomb[i]->getnev().c_str(), name.c_str()) == 0){
                Tomb[i]->kiir();
            }
        }
    }

void Telefonkonyv::szerkeszt(String nev, String szerkesztett, char mit){
        if(size == 0){
            throw "Nincs mit szerkeszteni";
        }

        bool bennevan = false;
        for(size_t i=0; i < size; i++){
            if(strcmp(Tomb[i]->getnev().c_str(), nev.c_str()) == 0){ //Tomb[i+1]->getnev() volt a nev helyett
                bennevan = true;
                break;
            }
        }
        if(!bennevan){
            throw "Nem letezik ilyen nev! Probalja meg ujra!";
        }

        String tempname, tempnumber, tempadress, tempnickname, tempado;
        for(size_t i=0; i < size; i++){
            if(strcmp(Tomb[i]->getnev().c_str(), nev.c_str()) == 0){ //Tomb[i+1]->getnev()
                bool Nber = false;
                if(std::isalpha(Tomb[i]->getnev()[0])){
                    Nber = true;
                }
                tempname = Tomb[i]->getnev();
                tempnumber = Tomb[i]->gettelefonszam();
                tempadress = Tomb[i]->getcim();
                tempnickname = Tomb[i]->getadat();//getbecenev();
                tempado = Tomb[i]->getadat();//getadoszam();
                delete Tomb[i];
                switch(mit){
                    case 'A':
                        if(Nber){
                            Ember* uj = new Ember(szerkesztett, tempnumber, tempadress, tempnickname);
                            Tomb[i] = uj;
                        }
                        else{
                            Ceg *uj = new Ceg(szerkesztett, tempnumber, tempadress, tempado);
                            Tomb[i] = uj;
                        }
                        break;
                    case 'B':
                        if(Nber){
                            Ember* uj = new Ember(tempname, szerkesztett, tempadress, tempnickname);
                            Tomb[i] = uj;
                        }
                        else{
                            Ceg *uj = new Ceg(tempname, szerkesztett, tempadress, tempado);
                            Tomb[i] = uj;
                        }
                        break;
                    case 'C':
                        if(Nber){
                            Ember* uj = new Ember(tempname, tempnumber, szerkesztett, tempnickname);
                            Tomb[i] = uj;
                        }
                        else{
                            Ceg *uj = new Ceg(tempname, tempnumber, szerkesztett, tempado);
                            Tomb[i] = uj;
                        }
                        break;
                    case 'D':
                        if(Nber){
                            Ember* uj = new Ember(tempname, tempnumber, tempadress, szerkesztett);
                            Tomb[i] = uj;
                        }
                        else{
                            Ceg *uj = new Ceg(tempname, tempnumber, tempadress, szerkesztett);
                            Tomb[i] = uj;
                        }
                        break;
                }
            }
        }
        rendez();
    }


template<class T>
void Telefonkonyv::Insert(T* kontakt) {
        Nevjegy** temp = new Nevjegy*[size + 1];
        for (size_t i = 0; i < size; i++) {
            temp[i] = Tomb[i];
        }
        temp[size] = kontakt;

        delete[] Tomb;
        Tomb = temp;
        size++;
        rendez();

    }


void Telefonkonyv::filebol_feltolt(const char* filename){

        std::ifstream inFile;
        inFile.open(filename);
        if (!inFile) {
            std::cerr << "Unable to open file " << filename << std::endl;
            exit(1);   // terminate with error
        }

        int db = 0;
        inFile >> db;
        String name, number, city, street, streettype, adress, other;
        int i = 0;
        while (i < db) {
            inFile >> name >> number >> city >> street >> streettype >> adress >> other;
            String cim = city+" "+street+" "+streettype+" "+adress;
            if (!std::isalpha(other[0])) {
                //ez egy cég
                Ceg* uj = new Ceg(name, number, cim, other);
                Insert(uj);
            } else {
                //ilyenkor ember
                Ember* uj = new Ember(name, number, cim, other);
                Insert(uj);
            }
            i++;
        }
        inFile.close();
    }



void Telefonkonyv::rendez(){
        Nevjegy* temp;
        for(size_t i=0; i < size; i++){
            for(size_t j = 0; j < size-1-i; j++){
                if(strcmp(Tomb[j]->getnev().c_str(), Tomb[j+1]->getnev().c_str()) > 0){
                    temp = Tomb[j];
                    Tomb[j]= Tomb[j+1];
                    Tomb[j+1] = temp;
                }
            }
        }
    }




void Telefonkonyv::elem_torlese(String name){
    size_t hanyadik = 0;
    bool talalat = false;
        for (size_t i = 0; i < size; ++i) {
            if (strcmp(Tomb[i]->getnev().c_str(), name.c_str()) == 0) {
                hanyadik = i;
                talalat = true;
                break;
            }
        }

        if (!talalat) {
            throw "Nincs ilyen nev a telefonkonyvben!";
        }
        if (size == 1) {
            torol();
        } else {
            size_t tempsize = size - 1;
            Nevjegy **temp = new Nevjegy *[tempsize];
            int j = 0;
            for (size_t i = 0; i < size; ++i) {
                if (i != hanyadik) {
                    temp[j] = Tomb[i];
                    ++j;
                }
            }
            delete Tomb[hanyadik];
            delete[] Tomb;
            Tomb = temp;
            size = tempsize;
        }
    }

void Telefonkonyv::listaz() {
        for(size_t i = 0; i < size; i++){
            Tomb[i]->kiir();
        }
    }

void Telefonkonyv::torol() {
        for (size_t i = 0; i < size; ++i) {
            delete Tomb[i];
        }
        delete[] Tomb;
        size = 0;
        Tomb = nullptr;
    }