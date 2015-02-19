//
//  Vehiculo.h
//  ExamenP1_2
//
//  Created by Gonzalo Vergara on 2/19/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef __ExamenP1_2__Vehiculo__
#define __ExamenP1_2__Vehiculo__

#include <iostream>
class Vehiculo {
private:
    int codigo;
    std::string tipo;
    std::string marca;
    int anio;
    int kilometraje;
    std::string caracteristica_especial; // sea tracción, o cilindraje
    int id_persona;
    int id_venta;
    
public:
    Vehiculo() : Vehiculo(0, "","",0, 0, "", 0, 0) {}
    Vehiculo(int _codigo, std::string _tipo, std::string _marca, int _anio, int _kilometraje, std::string _caracteristica_especial, int _id_persona, int _id_venta) : codigo(_codigo), tipo(_tipo), marca(_marca), anio(_anio), kilometraje(_kilometraje), caracteristica_especial(_caracteristica_especial), id_persona(_id_persona), id_venta(_id_venta) {}
    int get_codigo();
    std::string get_tipo();
    std::string get_marca();
    int get_anio();
    int get_kilometraje();
    std::string get_caracteristica_especial();
    int get_id_persona();
    int get_id_venta();
};


#endif /* defined(__ExamenP1_2__Vehiculo__) */
