//
//  Node.h
//  tarea_3_1
//
//  Created by Gonzalo Vergara on 3/3/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef __tarea_3_1__Node__
#define __tarea_3_1__Node__

#include <iostream>
namespace gva {
    
    template <class T>
    class Node {
        T info;
        Node<T> * next = nullptr;
        
    public:
        Node() { }
        ~Node() { next = nullptr; }
        Node(T _info) : info(_info) {}
        
        T getInfo() const { return info; }
        void setInfo(T value) { info = value; }
        
        Node<T> * getNext() const { return next; }
        void setNext(Node<T> * value) { next = value; }
        
        template <typename Tn>
        friend std::ostream & operator << (std::ostream & os, Node<Tn>  & node);
    };
    
    template <class T>
    std::ostream & operator << (std::ostream & os, Node<T>  & node)
    {
        os << node.info;
        
        return os;
    }
    
}

#endif /* defined(__tarea_3_1__Node__) */
