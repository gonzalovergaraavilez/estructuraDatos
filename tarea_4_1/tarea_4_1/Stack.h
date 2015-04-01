//
//  Stack.h
//  tarea_4_1
//
//  Created by Gonzalo Vergara on 3/25/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef __tarea_4_1__Stack__
#define __tarea_4_1__Stack__

#include "../../LinkedList/LinkedList/LinkedList.h"

namespace vcn {
    template <class T>
    class Stack : private LinkedList<T> {
    public:
        Stack();
        virtual ~Stack();
        
        int size();
        bool empty();
        
        Node<T> * top();
        Node<T> * pop();
        void push(T);
        void push(Node<T> *);
        
        bool balanced();
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, Stack<Tn> &);
    };
    template <class T>
    bool Stack<T>::balanced(){
        int count = 0;
        Node<char> *node = this->top();
        while(node!=nullptr){
            //std::cout << "current node" << node->getInfo() << std::endl;
            if(node->getInfo()=='('){
                count++;
                //std::cout << "opening" << std::endl;
            }else if(node->getInfo()==')'){
                count--;
                //std::cout << "closing" <<std::endl;
            }
            node = node->getNext();
        }
        if (count!=0) {
            return false;
        }
        return true;
    }

    
    template <class T>
    Stack<T>::Stack() : LinkedList<T>()
    {
    }
    
    template <class T>
    Stack<T>::~Stack()
    {
        this->clear();
    }
    
    template <class T>
    int Stack<T>::size()
    {
        return LinkedList<T>::size();
    }
    
    template <class T>
    bool Stack<T>::empty()
    {
        return LinkedList<T>::empty();
    }
    
    template <class T>
    Node<T> * Stack<T>::top()
    {
        return this->first();
    }
    
    template <class T>
    Node<T> * Stack<T>::pop()
    {
        return this->removeFront();
    }
    
    template <class T>
    void Stack<T>::push(T value)
    {
        this->insertFront(value);
    }
    
    template <class T>
    void Stack<T>::push(Node<T> * node)
    {
        this->insertFront(node);
    }
    
    template <class T>
    std::ostream & operator <<(std::ostream & os, Stack<T> & stack)
    {
        for (auto i : stack) {
            os << i << std::endl;
        }
        
        return os;
    }
    
}

#endif /* defined(__tarea_4_1__Stack__) */
