//
// Created by sajbe on 2023. 04. 27..
//

#ifndef PROGRAM_TELEFONKONYV_H
#define PROGRAM_TELEFONKONYV_H
#include <iostream>
#include "cstring"
#include <fstream>
#include "Nevjegy.h"
#include "Ceg.h"
#include "Ember.h"





class Telefonkonyv {
    size_t size;
    Nevjegy** Tomb;
public:
    Telefonkonyv() : size(0), Tomb(nullptr) {}

    void fileba_ment(const char* filename);
    void keres (String name);
    void szerkeszt(String nev, String szerkesztett, char mit);

    template<class T>
    void Insert(T* kontakt);
    void filebol_feltolt(const char* filename);
    void rendez();
    void elem_torlese(String name);
    void listaz();
    void torol();

    Nevjegy* operator[] (size_t x) {return Tomb[x];}

    ~Telefonkonyv(){
        torol();
    }
};


#endif //PROGRAM_TELEFONKONYV_H
