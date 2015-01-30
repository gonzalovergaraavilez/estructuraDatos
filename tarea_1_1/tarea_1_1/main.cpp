//
//  main.cpp
//  tarea_1_1
//
//  Created by Gonzalo Vergara on 1/27/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include <math.h>

void matrix(int, int, int);

int main(int argc, const char * argv[]) {
    std::cout << "N:";
    int n=0;
    std::cin >> n;
    matrix(0, 0,n);
}

void matrix(int i, int j, int n){
    if(j<n){
        if(i<n-1){
            if(i>=j){
                std::cout << pow(2, j) << " ";
                matrix(++i, j, n);
            }else{
                std::cout << pow(2, i) << " ";
                
                matrix(++i, j, n);
            }
        }else{
            std::cout << pow(2, j);
            std::cout << std::endl;
            matrix(0, ++j, n);
        }
    }else if(j==n){
        return;
    }
}
