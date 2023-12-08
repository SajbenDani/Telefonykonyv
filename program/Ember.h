//
// Created by sajbe on 2023. 04. 27..
//

#ifndef PROGRAM_EMBER_H
#define PROGRAM_EMBER_H
#include <iostream>
#include "String.h"
#include "Nevjegy.h"


class Ember : public Nevjegy {
    String becenev;
public:
    Ember() : Nevjegy(), becenev("") {};
    Ember(String nev, String telefonszam, String cim, String becenev) : Nevjegy(nev, telefonszam, cim), becenev(becenev) {};
    //Ember(const Ember& a);

    //Ember& operator=(const Ember& a);
    void kiir(std::ostream& os = std::cout);
    void kiir_fileformat(std::ostream& os = std::cout);
    //String getbecenev() const {return becenev;}
    virtual String getadat() const {return becenev;}
    ~Ember() {}
};


#endif //PROGRAM_EMBER_H
