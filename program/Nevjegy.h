//
// Created by sajbe on 2023. 04. 27..
//

#ifndef PROGRAM_NEVJEGY_H
#define PROGRAM_NEVJEGY_H
#include "String.h"


class Nevjegy {
    String nev;
    String telefonszam;
    String cim;
public:
    Nevjegy() : nev(""), telefonszam(""), cim("") {
    }

    Nevjegy(String name, String number, String adress) : nev(name), telefonszam(number), cim(adress) {};

    //Nevjegy(const Nevjegy& a);

    virtual void kiir(std::ostream& os = std::cout) {}
    virtual void kiir_fileformat(std::ostream& os = std::cout) {}

    String getnev() const {return nev;};
    //virtual String getbecenev() const {};
    //virtual String getadoszam() const {};
    virtual String getadat() const = 0;
    String getcim() const {return cim;};
    String gettelefonszam() const {return telefonszam;};
    //Nevjegy& operator=(const Nevjegy& a);
    virtual ~Nevjegy() {}
};



#endif //PROGRAM_NEVJEGY_H
