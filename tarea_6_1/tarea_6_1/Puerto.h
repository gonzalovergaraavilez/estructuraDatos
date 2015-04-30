//
//  Puerto.h
//  tarea_6_1
//
//  Created by Gonzalo Vergara on 4/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef tarea_6_1_Puerto_h
#define tarea_6_1_Puerto_h
#include <vector>
#include "Pila.h"

class Puerto{
private:
    int m = 0;
    int n = 0;
    std::vector<Pila *> pilas;
    int total = 0;
public:
    Puerto() {}
    virtual ~Puerto();
    
    std::vector<Pila *> getPilas(){return pilas;}
    
    void setM(int value){m = value;}
    void setN(int value){n = value;}
    void setPilas(std::vector<Pila *> value){pilas = value;}
    bool addContainer(Contenedor *value);
    
    friend std::ostream & operator << (std::ostream & os, Puerto  & puerto);
    
};
std::ostream & operator << (std::ostream & os, Puerto  & puerto)
{
    for (int i=0;i<puerto.pilas.size();i++){
        os << *puerto.pilas[i];
        os << std::endl;
    }
    os << "--------" << std::endl << "Costo TOTAL del Puerto: $" << puerto.total << std::endl << std::endl;
    return os;
}
bool Puerto::addContainer(Contenedor *value){
    if(pilas.empty()){
        pilas.push_back(new Pila(1,n));
    }
        if((!pilas.back()->addContainer(value))&&(pilas.back()->getN()==pilas.back()->getContainers().size())){
            if(pilas.size()<m){
                pilas.push_back(new Pila);
                pilas.back()->setIDno((int)pilas.size());
                pilas.back()->addContainer(value);
                total+=value->getTotal();
                return true;
            }else{
                std::cout << "Puerto lleno!" << std::endl;
                return false;
            }
        }else{
            total+=value->getTotal();
            return true;
        }
}
Puerto::~Puerto(){
    m = 0;
    pilas.clear();
    total = 0;

}

#endif
