//
//  Venta.h
//  ExamenP1_2
//
//  Created by Gonzalo Vergara on 2/19/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef __ExamenP1_2__Venta__
#define __ExamenP1_2__Venta__

#include <iostream>
class Venta {
private:
    int id_venta;
    int monto;
    int id_vehiculo;
    int id_persona;
    
public:
    Venta() : Venta(0, 0, 0, 0) {}
    Venta(int _id_venta, int _monto, int _id_vehiculo, int _id_persona) : id_venta(_id_venta), monto(_monto), id_vehiculo(_id_vehiculo), id_persona(_id_persona) {}
    int get_id_venta();
    int get_monto();
    int get_id_vehiculo();
    int get_id_persona();
    
};


#endif /* defined(__ExamenP1_2__Venta__) */
