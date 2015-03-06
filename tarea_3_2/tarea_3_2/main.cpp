//
//  main.cpp
//  tarea_3_2
//
//  Created by Gonzalo Vergara on 3/4/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "Node.h"
#include "LinkedList.h"
bool isPrime(int);

int main(int argc, const char * argv[]) {
    using namespace gva;
    
    int n, m, i, tmp;
    LinkedList<int> * n_list  = new LinkedList<int>();
    LinkedList<int> * m_list  = new LinkedList<int>();
    
    std::cout << "Entre el número de elementos para N: ";
    std::cin >>n;
    std::cout << std::endl;
    
    for(i=0;i<n;i++){
        std::cout << "Entre el elemento no. " << i+1 << ": ";
        std::cin >>tmp;
        n_list ->insertBack(tmp);
        std::cout << std::endl;
    }
    
    
    std::cout << "Entre el número de elementos para M: ";
    std::cin >>m;
    std::cout << std::endl;
    
    for(i=0;i<m;i++){
        std::cout << "Entre el elemento no. " << i+1 << ": ";
        std::cin >>tmp;
        m_list ->insertBack(tmp);
        std::cout << std::endl;
    }
    int option = 0;
    std::cout << "Seleccione una opción: " << std::endl;
    std::cout << "1. M ⋃ N " << std::endl;
    std::cout << "2. N - M" << std::endl;
    std::cout << "3. M - N"  << std::endl;
    std::cout << "4. N * M"  << std::endl;
    std::cout << "5. N ⋂ M"  << std::endl;
    
    std::cin >>option;
    option -- ;
    LinkedList<int> * p_list  = new LinkedList<int>();
    
    switch (option) {
        case 0:
            p_list = n_list->unionWhith(*m_list);
            break;
        case 1:
            p_list = n_list->minus(*m_list);
            break;
        case 2:
            p_list = m_list->minus(*n_list);
            break;
        case 3:
            p_list = n_list->multiplyBy(*m_list);
            break;
        case 4:
            p_list = n_list->intersectWith(*m_list);
            break;
            
        default:
            break;
    }
   
    
    
    
    
    std::cout << "N: " << std::endl << *n_list << std::endl;
    std::cout << "M: " << std::endl << *m_list << std::endl;
    std::cout << "P: " << std::endl << *p_list << std::endl;
    return 0;
}
