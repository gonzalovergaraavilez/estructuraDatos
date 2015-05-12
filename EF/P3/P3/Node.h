//
//  Node.h
//  P3
//
//  Created by Gonzalo Vergara on 5/12/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef P3_Node_h
#define P3_Node_h

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
        template <typename Tn>
        friend bool operator == (Node<Tn> &, Node<T> &);
    };
    
    template <class T>
    std::ostream & operator << (std::ostream & os, Node<T>  & node)
    {
        os << node.info;
        
        return os;
    }
    template <class T>
    bool operator == (Node<T>  & node1, Node<T>  & node2)
    {
        return node1.info== node2.info;
    }
    
    
}

#endif
