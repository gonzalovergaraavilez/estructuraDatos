//
//  main.cpp
//  tarea4_2
//
//  Created by Gonzalo Vergara on 3/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "CircularLinkedList.h"
#include "Token.h"
int main(int argc, const char * argv[]) {
    
    using namespace vcn;
    
    CircularLinkedList<int> * direcciones = new CircularLinkedList<int>();
    
    /*Fill directions list*/
    direcciones->insertBack(5);
    direcciones->insertBack(2);
    direcciones->insertBack(3);
    direcciones->insertBack(34);
    direcciones->insertBack(8);
    direcciones->insertBack(6);
    direcciones->insertBack(73);
    
    
    /*Create Token*/
    Token *token = new Token;
    
    bool success = token->send(2, 73, "message from 34 to 73", direcciones);
    std::cout<<(success ? "The message was sent correctly" : "One or both directions are invalid") << std::endl;
    
    delete direcciones;
    delete token;
    
    return 0;
}
