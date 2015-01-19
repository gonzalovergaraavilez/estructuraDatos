//
//  main.cpp
//  ejercicio_1_19_01_2015
//
//  Created by Gonzalo Vergara on 1/19/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>

void divisor(int,int);

int main(int argc, const char *argv[]){
    int m=0;
    int n=0;
    
    std::cout <<"Entre m: ";
    std::cin >> m;
    std::cout <<"Entre n: ";
    std::cin >> n;
    
    if(n > m){
        std::cout << "m debe ser mayor a n";
        return 1;
    }
    
    divisor(m, n);
    
    return 0;
}

void divisor(int m, int n){
    int r = m%n;
    if (r == 0){
        std::cout << n << " es el máximo común divisor" << std::endl;
    }else {
        return divisor(n, r);
    }
}
