//
//  Node.h
//  Final_Project
//
//  Created by Gonzalo Vergara on 5/4/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef Final_Project_Node_h
#define Final_Project_Node_h

namespace gva {
    
    template <class T>
    class Node {
        T info;
        Node<T> * next = nullptr;
        Node<T> * previous = nullptr;
        
    public:
        Node() { }
        ~Node() { next = nullptr; previous = nullptr; }
        Node(T _info) : info(_info) {}
        
        T getInfo() const { return info; }
        void setInfo(T value) { info = value; }
        
        Node<T> * getNext() const { return next; }
        void setNext(Node<T> * value) { next = value; }
        
        Node<T> * getPrevious() const { return previous; }
        void setPrevious(Node<T> * value) { previous = value; }
        
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
#endif
