//
//  main.cpp
//  pregunta_3
//
//  Created by Gonzalo Vergara on 4/9/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include <sstream>

using namespace gva;
using namespace std;

LinkedList<int>* listify(std::string);

int main(int argc, const char * argv[]) {
    LinkedList<LinkedList<int> *> *listas = new LinkedList<LinkedList<int>*>();
    
    LinkedList<int> *list1= new LinkedList<int>();
    LinkedList<int> *list2= new LinkedList<int>();
    
    
    std::string temp_string = "{3,4,5,6,5}";
    list1 = listify(temp_string);
    
    temp_string = "{2,5,5,7,5}";
    list2 = listify(temp_string);
    
    LinkedList<int> * p_list  = new LinkedList<int>();
    p_list = list1->unionWhith(*list2);
    
    std::cout << "Resultado: " << std::endl << *p_list;
    
    delete listas;
    delete list1;
    delete list2;
    return 0;
}

LinkedList<int>* listify(std::string s){
    LinkedList<int> *lista = new LinkedList<int>();
    /*Leer de string*/
    std::stringstream ss;
    char char_i;
    ss.str(s);
    int n= 0;
    while(ss.get(char_i)){
        if(char_i != '{' && char_i != '}' && char_i != ','){
            n = char_i - '0';
            lista->insertBack(n);
        }
    }
    std::cout << "Converted: " << std::endl << *lista;
    return lista;
}