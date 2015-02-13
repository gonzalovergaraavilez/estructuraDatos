//
//  Book.cpp
//  OrdenamientoGenerico
//
//  Created by Gonzalo Vergara on 2/12/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include "Book.h"

bool Book::has_equal_author(std::string author){
    return autor == author;
}

bool Book::has_equal_editorial(std::string editorial){
    return editorial == editorial;
}
bool Book::operator >(int anio)
{
    return anio_pub > anio;
}
bool Book::operator <(int anio)
{
    return anio_pub < anio;
}

std::ostream & operator << (std::ostream & os, Book & book)
{
    os << book.autor << " (" << book.anio_pub << ")" << ". " << book.titulo << ". " << book.editorial << " " << book.edicion << ", pp " << book.n_paginas << std::endl;
    
    return os;
}