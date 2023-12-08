//
// Created by sajbe on 2023. 04. 27..
//

#ifndef PROGRAM_CEG_H
#define PROGRAM_CEG_H
#include <iostream>
#include "String.h"
#include "Nevjegy.h"


class Ceg : public Nevjegy{
    String adoszam;
public:
    Ceg() : Nevjegy(), adoszam("") {};
    Ceg(String nev, String telefonszam, String cim, String adoszam) : Nevjegy(nev, telefonszam, cim), adoszam(adoszam) {};
    //Ceg(const Ceg& a);
    //Ceg& operator=(const Ceg& a);
    void kiir(std::ostream& os = std::cout);
    void kiir_fileformat(std::ostream& os = std::cout);
    virtual String getadat() const {return adoszam;}
    //String getadoszam() const {return adoszam;}
    ~Ceg() {}
};

#endif //PROGRAM_CEG_H
