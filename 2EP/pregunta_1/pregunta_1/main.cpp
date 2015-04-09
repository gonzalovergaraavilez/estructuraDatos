//
//  main.cpp
//  pregunta_1
//
//  Created by Gonzalo Vergara on 4/9/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "Stack.h"

void convertToBinary(int);
using namespace vcn;

int main(int argc, const char * argv[]) {
    int num = 222;
    convertToBinary(num);
    
    return 0;
}

void convertToBinary(int num){
    Stack<int> stack; //manejo de memoria automático
    std::cout << "Base 10: " <<std::endl << num << std::endl;
    int temp;
    std::string tempS= "";
    while(num>0){
        temp = num % 2;
        num = num/2;
        stack.push(temp);
    }
    std::cout << "Binario: " <<std::endl << stack << std::endl;
}
