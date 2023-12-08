//
// Created by sajbe on 2023. 04. 27..
//
#include <iostream>
#include "memtrace.h"
#include "Ceg.h"




void Ceg::kiir(std::ostream& os) {
    os << "nev: " << getnev();
    os << std::endl;
    os << "telefonszam: " << gettelefonszam();
    os << std::endl;
    os << "cim: " << getcim();
    os << std::endl;
    os << "adoszam: " << adoszam << std::endl;
    os << std::endl;
}

void Ceg::kiir_fileformat(std::ostream& os) {
    os << getnev() << " " << gettelefonszam() << " " << getcim() << " " << adoszam;
}

