//
//  main.cpp
//  P1
//
//  Created by Gonzalo Vergara on 5/12/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include <iostream>
#include "Graph.h"
int main(int argc, const char * argv[]) {
    
    Graph<char, int> mapa("Guía Roji");
    
    /* Crear vértices */
    Vertex<char, int> * A = new Vertex<char, int>('A');
    Vertex<char, int> * B = new Vertex<char, int>('B');
    Vertex<char, int> * C = new Vertex<char, int>('C');
    Vertex<char, int> * D = new Vertex<char, int>('D');
    Vertex<char, int> * E = new Vertex<char, int>('E');
    
    /* Adicionar vértices al grafo */
    mapa.addVertex(A);
    mapa.addVertex(B);
    mapa.addVertex(C);
    mapa.addVertex(D);
    mapa.addVertex(E);
    
    /* Adicionar aristas */
    mapa.addEdge(A, B, 30);
    mapa.addEdge(A, C, 100);
    mapa.addEdge(A, D, 30);
    mapa.addEdge(A, E, 100);
    mapa.addEdge(B, A, 50);
    mapa.addEdge(B, C, 75);
    mapa.addEdge(B, D, 50);
    mapa.addEdge(B, E, 75);
    mapa.addEdge(C, A, 20);
    mapa.addEdge(C, B, 20);
    mapa.addEdge(C, C, 20);
    mapa.addEdge(C, D, 20);
    mapa.addEdge(D, A, 60);
    mapa.addEdge(D, B, 60);
    mapa.addEdge(D, C, 60);
    mapa.addEdge(D, E, 60);
    mapa.addEdge(E, A, 15);
    mapa.addEdge(E, B, 15);
    mapa.addEdge(E, C, 15);
    
    mapa.isComplete();
    
    mapa.addEdge(E, D, 15);
    
    mapa.isComplete();
    /* Eliminar una arista */;
    //mapa.removeEdge(A, B, 30);
    
    /* Mostrar el grafo */
    //std::cout << mapa << std::endl;

    return 0;
}
