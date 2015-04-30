//
//  main.cpp
//  tarea_6_1
//
//  Created by Gonzalo Vergara on 4/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>

#include "Puerto.h"

int main(int argc, const char * argv[]) {
    
    //M y N definidos
    int n = 3;
    int m = 2;
    Producto *product1 = new Producto("naranja", 20, 2);
    Producto *product2 = new Producto("leche", 1, 33);
    Producto *product3 = new Producto("huevo", 3, 12);
    Producto *product4 = new Producto("jamón", 1, 1);
    
    Contenedor *container1 = new Contenedor(2, "Bachoco");
    Contenedor *container2 = new Contenedor(5, "Pilgrims");
    Contenedor *container3 = new Contenedor(3, "Fud");

    container1->addProduct(product1);
    container1->addProduct(product2);
    container2->addProduct(product4);
    container1->addProduct(product3);
    container3->addProduct(product2);
    container2->addProduct(product1);
    container2->addProduct(product3);
    container3->addProduct(product4);
    
    Puerto *puerto = new Puerto();
    puerto->setM(m);
    puerto->setN(n);
    puerto->addContainer(container1);
    puerto->addContainer(container2);
    puerto->addContainer(container3);
    puerto->addContainer(container2);
    puerto->addContainer(container1);
    puerto->addContainer(container1);
    std::cout << *puerto;
    
    puerto->addContainer(container2);
    puerto->addContainer(container3);
    
    
    
    delete product1;
    delete product2;
    delete product3;
    delete product4;
    delete container1;
    delete container2;
    delete container3;
    
    delete puerto;
    return 0;
}
