//
//  main.cpp
//  ejercicio_3_19_01_2015
//
//  Created by Gonzalo Vergara on 1/19/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>

int sumar_vector(int, int[][]);

int main(int argc, const char *argv[]){
    
    int n_elementos=0;
    std::cout <<"Entre el número elementos: ";
    std::cin >> n_elementos;
    int elementos[n_elementos];
    int elemento_i=0;
    
    for (int i=0; i<n_elementos; i++) {
        std::cout <<"Entre el elemento " << i << ": ";
        std::cin >> elemento_i;
        elementos[i]=elemento_i;
    }
    
    int suma= sumar_vector(n_elementos-1, elementos);
    std::cout <<"Suma:" << suma << ": ";
    return 0;
}

int sumar_vector(int n, int values[]){
    if(n==0){
        return values[0];
    }else{
        return values[n] + sumar_vector(n-1, values);
    }
}
