//
//  main.cpp
//  ExamenP1_2
//
//  Created by Gonzalo Vergara on 2/19/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "Persona.h"
#include "Venta.h"
#include "OrdenamientoGenerico.h"

int main(int argc, const char * argv[]) {
    int ventas_totales = 0;
    Venta *ventas = new Venta[ventas_totales];
    
    ventas_totales++;
    ventas = (Venta *)realloc(ventas, ventas_totales * sizeof(Venta));
    
    std::cout << "Bienvenido, elija la opción:" << std::endl;
    std::cout << "1. Agregar persona " << std::endl;
    int opcion;
    std::cin >> opcion;
    opcion--;
    
    switch (opcion) {
        case 0:
            <#statements#>
            break;
            
        default:
            break;
    }
    return 0;
}
