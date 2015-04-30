//
//  Pila.h
//  tarea_6_1
//
//  Created by Gonzalo Vergara on 4/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef tarea_6_1_Pila_h
#define tarea_6_1_Pila_h
#include "Contenedor.h"

class Pila{
private:
    int n = 3;
    int id_no = 0;
    std::vector<Contenedor *> containers;
    int total = 0;
public:
    Pila() {}
    virtual ~Pila();
    
    Pila(int _id_no, int _n) : id_no(_id_no), n(_n){}
    
    std::vector<Contenedor *> getContainers(){return containers;}
    
    int getIDno(){return id_no;}
    int getN(){return n;}
    
    void setIDno(int value){id_no = value;}
    void setN(int value){n = value;}
    void setContainers(std::vector<Contenedor *> value){containers = value;}
    bool addContainer(Contenedor *value);
    
    friend std::ostream & operator << (std::ostream & os, Pila  & pila);
    
};
std::ostream & operator << (std::ostream & os, Pila  & pila)
{
    os << "Pila " << pila.id_no << std::endl;
    for (int i=0;i<pila.containers.size();i++){
        os << *pila.containers[i];
        os << std::endl;
    }
    os << "--------" << std::endl << "Costo de la pila: $" << pila.total << std::endl;
    return os;
}
bool Pila::addContainer(Contenedor *value){
    if(n>containers.size()){
        containers.push_back(value);
        total+=value->getTotal();
        return true;
    }else{
        return false;
    }
    
}
Pila::~Pila(){
    n = 0;
    total = 0;
    id_no = 0;
    containers.clear();
}

#endif
