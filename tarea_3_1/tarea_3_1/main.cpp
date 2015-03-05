//
//  main.cpp
//  tarea_3_1
//
//  Created by Gonzalo Vergara on 3/3/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "Node.h"
#include "LinkedList.h"
bool isPrime(int);

int main(int argc, const char * argv[]) {
    using namespace gva;
    
    
    LinkedList<int> * numeros_primos  = new LinkedList<int>();
    /* Definir p */
    int p;
    std::cout << "p: ";
    std::cin >> p;
    
    /* Definir p */
    int q;
    std::cout << "q: ";
    std::cin >> q;
    
    /* Definir n */
    int n;
    std::cout << "n: ";
    std::cin >> n;
    std::cout << std::endl;
    
    if (p>q){
        int tmp = p;
        p = q;
        q = tmp;
    }
    int counter = 0;
    
    for (int i=p; i<=q; i++) {
        if(counter<n){
            if(isPrime(i)) {
                numeros_primos->insertFront(i);
                counter++;
            }
        }
    }
    if(counter<n) std::cout << "No hay tantos números primos en el rango, pero bueno, van en orden descendente:" << std::endl;
    std::cout << *numeros_primos << std::endl;
    numeros_primos->~LinkedList();
    return 0;
}

bool isPrime(int n){
    if (n == 0 || n == 1 || n<0) return false; //Asumiendo que 1 no es número primo
    for (int i=2; i<n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
