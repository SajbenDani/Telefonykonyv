//
// Created by sajbe on 2023. 04. 27..
//
#include <iostream>
#include "memtrace.h"
#include "Ember.h"




void Ember::kiir(std::ostream& os) {
    os << "nev: " << getnev();
    os << std::endl;
    os << "telefonszam: " << gettelefonszam();
    os << std::endl;
    os << "cim: " << getcim();
    os << std::endl;
    os << "becenev: " << becenev << std::endl;
    os << std::endl;
}

void Ember::kiir_fileformat(std::ostream& os) {
    os << getnev() << " " << gettelefonszam() << " " << getcim() << " " << becenev;
}

