//
//  main.cpp
//  P3
//
//  Created by Gonzalo Vergara on 5/12/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include <sstream>
#include "BinaryTree.h"

using namespace gva;
using namespace std;
using namespace vcn;

LinkedList<char>* listify(std::string);

int main(int argc, const char * argv[]) {
    
    /*Read characters into lists for processing: */
    LinkedList<char> *preorden= new LinkedList<char>();
    LinkedList<char> *enorden= new LinkedList<char>();
    
    std::string temp_string = "GEAIBMCLDFKJH";
    preorden = listify(temp_string);
    
    temp_string = "IABEGLDCFMKHJ";
    enorden = listify(temp_string);
    
    /*Binary Tree*/
    /* Crear un árbol binario */
    BinaryTree<char> arbol;
    
    /* Insertar nodos */
    
    BNode<char> * root = new BNode<char>(preorden->first()->getInfo());
    arbol.insert(nullptr, root);
    Node<char> *current_node = preorden->first()->getNext();
    Node<char> *current_node_inorder = enorden->first();
    BNode<char> * current_tree_node = root;
    bool last = false;
    /*Llenar hasta encontrar con el elemento más a la izquierda (enorden->first())*/
    do {
        arbol.insertLeft(current_tree_node, new BNode<char>(current_node->getInfo()));
        if(current_node->getInfo()==current_node_inorder->getInfo()){
            last = true;
        }
        current_node = current_node->getNext();
        current_tree_node = current_tree_node->getLeft();

    }while (!last);
    last = false;
    do {
        current_tree_node = current_tree_node->getParent();
        current_node_inorder = current_node_inorder->getNext();
        if(current_tree_node->getInfo()==current_node_inorder->getInfo()){ //insertar a la derecha
            arbol.insertRight(current_tree_node, current_node->getInfo());
            current_node = current_node ->getNext();
            current_tree_node = current_tree_node->getParent();
        }
        if(current_tree_node->getInfo()==arbol.getRoot()->getInfo()){
            last = true;
        }

    } while (!last);
    
    /* Mostrar el árbol en preOrder */
    std::cout << " ---- preOrder ----" << std::endl;
    arbol.preOrder();
    std::cout << std::endl;
    
    /* Mostrar el árbol en inOrder */
    std::cout << " ---- inOrder ----" << std::endl;
    arbol.inOrder();
    std::cout << std::endl;
    
    delete preorden;
    delete enorden;
    return 0;
}

LinkedList<char>* listify(std::string s){
    LinkedList<char> *lista = new LinkedList<char>();
    /*Leer de string*/
    std::stringstream ss;
    char char_i;
    ss.str(s);
    while(ss.get(char_i)){
            lista->insertBack(char_i);
    }
    //std::cout << "Converted: " << std::endl << *lista;
    return lista;
}
