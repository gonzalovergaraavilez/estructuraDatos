//
//  main.cpp
//  tarea_4_3
//
//  Created by Gonzalo Vergara on 3/31/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "DCircularLinkedList.h"
#include <fstream>
#include <sstream>

int main(int argc, const char * argv[]) {
    
    using namespace gva;
    
    /* Demostrar el uso de la clase genérica DCircularLinkedList<T> */
    
    /* Declaración de una lista de enteros */
    DCircularLinkedList<std::string> palabras;
    DCircularLinkedList<DCircularLinkedList<std::string> *>  lineas;

    

    
    /* Determinar si la lista está vacía */
    //std::cout  << "Empty = " << (numeros->empty() ? "true" : "false") << std::endl;
    
    
    /* Insertar elemento en la lista */
    
    
    /* Determinar el tamaño */
    //std::cout  << "Size = " << numeros->size() << std::endl;
    
    /* Obtener el primer elemento */
    //std::cout  << "First = " << *numeros->first() << std::endl;
    
    /* Obtener el último elemento */
    //std::cout  << "Last = " << *numeros->last() << std::endl;
    
    /* Crear un nuevo nodo  e insertarlo en la lista */
    //Node<int> * newnode = new Node<int>(30);
    
    //numeros->insert(newnode, 6);
    
    
    
    /* Obtener el iésimo elemento  */
    /*int pos = 5;
    std::cout  << "At(" << pos << ") Previous = " << *(numeros->at(pos)->getPrevious()) << std::endl;
    std::cout  << "At(" << pos << ") = " << *(numeros->at(pos)) << std::endl;
    std::cout  << "At(" << pos << ") Next = " << *(numeros->at(pos)->getNext()) << std::endl;*/
    
    /* Obtener la posición de un elemento dado un apuntador al mismo */
   // Node<int> * node = numeros->at(0);
    
    //std::cout  << "Node está en posición " << numeros->LinkedList::at(node) << std::endl;
    
    /* Imprimir el contenido de la lista */
    //std::cout << *numeros << std::endl;
    
    /* Borrar un nodo de la lista */
    /*Node<int> * removenode = numeros->remove(6);
    
    if (removenode) {
        std::cout << " Nodo a borrar = " << *removenode << std::endl;
        delete removenode;
    }*/
    
    /* Imprimir el contenido de la lista */
    //std::cout << *numeros << std::endl;
    /* Determinar el tamaño */
    //std::cout  << "Size = " << numeros->size() << std::endl;
    
    /* Obtener el iésimo elemento  */
    /*pos = 5;
    std::cout  << "At(" << pos << ") Previous = " << *(numeros->at(pos)->getPrevious()) << std::endl;
    std::cout  << "At(" << pos << ") = " << *(numeros->at(pos)) << std::endl;
    std::cout  << "At(" << pos << ") Next = " << *(numeros->at(pos)->getNext()) << std::endl;
    
    */
    
    std::ofstream myfile;
    myfile.open ("fil2e.txt");
    myfile << "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod \ntempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,\nquis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo \nconsequat. Duis aute irure dolor in reprehenderit in voluptate velit esse \ncillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non \nproident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n";
    myfile.close();
    
    std::stringstream ss;
    
    std::string line;
    std::string word;
    std::ifstream myfile2 ("fil2e.txt");
    if (myfile2.is_open())
    {
        while ( getline (myfile2,line) )
        {
            ss.str(line);
            while(ss >> word){
                palabras.insertBack(word);
            }
            lineas.insertBack(&palabras);
        }
        myfile2.close();
    }

    else std::cout << "Unable to open file";

    /* Imprimir el contenido de la lista */
    std::cout << lineas << std::endl;
    
    
    /* Borrar toda la lista y liberar la memoria de todos los nodos */
    
    return 0;
}
