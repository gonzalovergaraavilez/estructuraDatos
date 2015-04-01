//
//  main.cpp
//  tarea_4_1
//
//  Created by Gonzalo Vergara on 3/25/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Stack.h"
#include <sstream>

using namespace vcn;

int main(int argc, const char * argv[]) {
    Stack<char> *stack = new Stack<char>();
    std::string str;
    std::cout << "Write your equation and press Enter: " <<std::endl;
    std::stringstream ss;
    
    char char_i;
    std::getline (std::cin,str);
    ss.str(str);
    while(ss.get(char_i)){
        stack->push(char_i);
    }
    
    bool is_balanced = stack->balanced();
    std::cout << "Your equation is ";
    std::cout<<(is_balanced ? "balanced" : "unbalanced");
    
    std::cout << std::endl;
    
    delete stack;
    return 0;
}

