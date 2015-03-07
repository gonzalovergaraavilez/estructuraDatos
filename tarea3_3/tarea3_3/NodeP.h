//
//  NodeP.h
//  tarea3_3
//
//  Created by Gonzalo Vergara on 3/6/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef __tarea3_3__NodeP__
#define __tarea3_3__NodeP__

#include <iostream>
    template <class T>
    class Node {
        std::string nombre;
        std::string apellidos;
        int edad;
        std::string fecha_nacimiento;
        Node<T> * next = nullptr;
        
    public:
        Node() { }
        Node(std::string _nombre, std::string _apellidos, int _edad, std::string _fecha_nacimiento) : nombre(_nombre), apellidos(_apellidos), edad(_edad), fecha_nacimiento(_fecha_nacimiento) {}
        
        T getInfo() const { return info; }
        void setInfo(T value) { info = value; }
        
        Node<T> * getNext() const { return next; }
        void setNext(Node<T> * value) { next = value; }
        
        template <typename Tn>
        friend std::ostream & operator << (std::ostream & os, Node<Tn>  & node);
        template <typename Tn>
        friend bool operator == (Node<Tn> &, Node<T> &);
    };
    
    template <class T>
    std::ostream & operator << (std::ostream & os, Node<T>  & node)
    {
        os << node.nombre << ", " << node.apellidos << ", " << node.edad << ", " node.fecha_nacimiento << std::endl;
        
        return os;
    }
    template <class T>
    bool operator == (Node<T>  & node1, Node<T>  & node2)
    {
        return node1.info== node2.info;
    }

#endif /* defined(__tarea3_3__NodeP__) */
