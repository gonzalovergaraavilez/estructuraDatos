//
//  main.cpp
//  tarea_6_2
//
//  Created by Gonzalo Vergara on 4/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "Universidad.h"
int main(int argc, const char * argv[]) {
    Estudiante *e1 = new Estudiante("Uno");
    Estudiante *e2 = new Estudiante("Dos");
    Estudiante *e3 = new Estudiante("Tres");
    
    //Tiempo total de 4 en la universidad;
    e1->addRelacion(e2, 2.0);
    e1->addRelacion(e1, 0.2);
    e1->addRelacion(e3, 1.2);
    
    e2->addRelacion(e1, 2.4);
    e3->addRelacion(e3, 1.8);
    
    
    Universidad *uni = new Universidad("My uni");
    uni->addEstudiante(e1);
    uni->addEstudiante(e2);
    uni->addEstudiante(e3);
    
    
    std::cout << *uni;
    delete e1;
    delete e2;
    delete e3;
    delete uni;
    
    
    return 0;
}
