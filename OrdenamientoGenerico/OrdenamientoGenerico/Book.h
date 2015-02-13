//
//  Book.h
//  OrdenamientoGenerico
//
//  Created by Gonzalo Vergara on 2/12/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef __OrdenamientoGenerico__Book__
#define __OrdenamientoGenerico__Book__

#include <iostream>
#include <string>
#include <ostream>

class Book {
private:
    std::string titulo;
    std::string autor;
    int n_paginas;
    int edicion;
    std::string editorial;
    int anio_pub;
    
public:
    Book() : Book("", "", 0, 0, "", 0) {}
    Book(std::string _titulo, std::string _autor , int _n_paginas, int _edicion, std::string _editorial, int _anio_pub) : titulo(_titulo), autor(_autor), n_paginas(_n_paginas), edicion(_edicion), editorial(_editorial), anio_pub(_anio_pub)  {}
    
    bool operator >(int);
    bool operator <(int);
    bool has_equal_author(std::string);
    bool has_equal_editorial(std::string);
    friend std::ostream & operator << (std::ostream & os, Book & book);
    
};
#endif /* defined(__OrdenamientoGenerico__Book__) */
