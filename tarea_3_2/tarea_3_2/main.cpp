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
    
    //std::cout << *n_list << std::endl;

    std::cout << "Entre el número de elementos para M: ";
    std::cin >>m;
    std::cout << std::endl;
    
    for(i=0;i<m;i++){
        std::cout << "Entre el elemento no. " << i+1 << ": ";
        std::cin >>tmp;
        m_list ->insertBack(tmp);
        std::cout << std::endl;
    }
    
    //std::cout << *m_list << std::endl;
    LinkedList<int> * p_list  = new LinkedList<int>();
    p_list = n_list->unionWhith(*m_list);
    std::cout << *p_list << std::endl;
    return 0;
}
