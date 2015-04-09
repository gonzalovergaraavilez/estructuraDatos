//
//  main.cpp
//  pregunta_2
//
//  Created by Gonzalo Vergara on 4/9/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace vcn;
LinkedList<int>* repeated(LinkedList<int>*);
int main(int argc, const char * argv[]) {
    LinkedList<int> *lista1 = new LinkedList<int>();
    
    lista1->insertBack(5);
    lista1->insertBack(2);
    lista1->insertBack(7);
    lista1->insertBack(2);
    lista1->insertBack(5);
    lista1->insertBack(5);
    lista1->insertBack(1);
    std::cout << *lista1;
    
    LinkedList<int> *lista3 = repeated(lista1);
    delete lista1;
    delete lista3;
    return 0;
}
LinkedList<int>* repeated(LinkedList<int> *lista){
    LinkedList<int> *lista2 = new LinkedList<int>();
    LinkedList<int> *lista4 = new LinkedList<int>();
    Node<int> *nod = lista->first();
    int tempn = 0;
    
    while(nod!=nullptr){
        tempn= lista2->searchAndReturnPosition(nod->getInfo());
        if (tempn==-1) {
            lista2->insertBack(nod->getInfo());
        }else{
            if(lista4->searchAndReturnPosition(nod->getInfo())==-1){
                lista4->insertBack(nod->getInfo());
            }
        }
        nod = nod->getNext();
    }
    delete lista2;
    std::cout << "Lista de repetidos: " << std::endl <<*lista4;
    return lista4;
}
