//
//  Persona.h
//  ExamenP1_2
//
//  Created by Gonzalo Vergara on 2/19/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef __ExamenP1_2__Persona__
#define __ExamenP1_2__Persona__

#include <iostream>
#include <string>
#include <ostream>

class Persona {
private:
    int id_IFE;
    std::string nombre;
    std::string apellido;
    
public:
    Persona() : Persona(0, "","") {}
    Persona(int _id_IFE, std::string _nombre, std::string _apellido) : id_IFE(_id_IFE), nombre(_nombre), apellido(_apellido) {}
    int get_id();
    std::string get_nombre();
    std::string get_apellido();
    
};

#endif /* defined(__ExamenP1_2__Persona__) */

