//
//  LinkedList.h
//  tarea_3_2
//
//  Created by Gonzalo Vergara on 3/3/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef __tarea_3_1__LinkedList__
#define __tarea_3_1__LinkedList__

#include <iostream>
#include "Node.h"

namespace gva {
    
    template <class T>
    class LinkedList {
        Node<T> * _first = nullptr;
        int _size = 0;
        
        class Iterator {
            LinkedList<T> * _data;
            int _position;
            
        public:
            Iterator(LinkedList<T> * _adata, int _aposition)
            : _data(_adata), _position(_aposition) {}
            
            Node<T> operator *() const { return *(_data->at(_position)); }
            const  Iterator & operator ++() { ++_position; return *this; }
            bool operator != (const Iterator & it) const { return _position != it._position; }
        };
        
    public:
        LinkedList() {}
        virtual ~LinkedList();
        
        Node<T> * first();
        int size();
        bool empty();
        
        void insert(T, int);
        void insert(Node<T> *, int);
        void insertFront(T);
        void insertFront(Node<T> *);
        void insertBack(T);
        void insertBack(Node<T> *);
        
        Node<T> * remove(int);
        Node<T> *  removeFront();
        Node<T> *  removeBack();
        
        void clear();
        
        Node<T> *  at(int);
        int at(Node<T> *);
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, LinkedList<Tn> &);
        
        Iterator begin() { return { this, 0}; }
        Iterator end() {return {this, _size }; }
        
        Node<T> * operator [](const int);
        
        LinkedList<T> * unionWhith (LinkedList<T> &);
        
    };
    
    template  <class T>
    LinkedList<T>::~LinkedList()
    {
        clear();
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::first()
    {
        return _first;
    }
    
    template  <class T>
    int LinkedList<T>::size()
    {
        return _size;
    }
    
    template  <class T>
    bool LinkedList<T>::empty()
    {
        return _size == 0;
    }
    
    /* Si position < 0 se inserta al inicio
     * Si position > _size se inserta al final
     * en cualquier otro caso, se inserta en la posición dada
     */
    template  <class T>
    void LinkedList<T>::insert(T element, int position)
    {
        /* Crear el nuevo nodo a insertar */
        Node<T> * newnode = new Node<T>(element);
        
        insert(newnode, position);
    }
    
    template  <class T>
    void LinkedList<T>::insert(Node<T> * newnode, int position)
    {
        /* Cuando la lista está vacía o position < 0*/
        if (empty() || position <= 0) {
            newnode->setNext(_first);
            _first = newnode;
        }
        /* Cuando se inserta en cualquier posición diferente del inicio */
        else {
            
            if (position > _size) { position = _size; }
            
            Node<T> * tmp = at(position-1);
            
            newnode->setNext(tmp->getNext());
            tmp->setNext(newnode);
        }
        
        /* Incrementar el tamaño de la lista */
        ++_size;
    }
    
    template  <class T>
    void LinkedList<T>::insertFront(T element)
    {
        insert(element, 0);
    }
    
    template  <class T>
    void LinkedList<T>::insertFront(Node<T> * node)
    {
        insert(node, 0);
    }
    
    template  <class T>
    void LinkedList<T>::insertBack(T element)
    {
        insert(element, _size);
    }
    
    template  <class T>
    void LinkedList<T>::insertBack(Node<T> * node)
    {
        insert(node, _size);
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::remove(int position)
    {
        if (empty() || (position < 0 || position >= _size )) {
            return nullptr;
        }
        
        Node<T> * removenode;
        
        /* Eliminar el primer nodo de la lista */
        if (position == 0) {
            removenode = _first;
            _first = _first->getNext();
            
        }
        /* Eliminar cualquier otro nodo */
        else {
            Node<T> * prev = at(position-1);
            removenode = prev->getNext();
            prev->setNext(removenode->getNext());
        }
        
        /* Establecer el siguiente en nullptr */
        removenode->setNext(nullptr);
        
        /* Decrementar el tamaño de la lista */
        --_size;
        
        return removenode;
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::removeFront()
    {
        return remove(0);
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::removeBack()
    {
        return remove(_size - 1);
    }
    
    template  <class T>
    void LinkedList<T>::clear()
    {
        Node<T> * tmp = _first;
        
        while (tmp != nullptr) {
            _first = _first->getNext();
            delete tmp;
            tmp = _first;
        }
        
        _size = 0;
        
        _first = nullptr;
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::at(int position)
    {
        if (empty() || (position < 0 || position >= _size )) {
            return nullptr;
        }
        
        int pos = 0;
        Node<T> * tmp = _first;
        
        while (tmp != nullptr && pos++ < position)
        {
            tmp = tmp->getNext();
        }
        
        return tmp;
        
    }
    
    template  <class T>
    int LinkedList<T>::at(Node<T> * node)
    {
        if (empty() || node == nullptr) {
            return -1;
        }
        
        int pos = 0;
        Node<T> * tmp = _first;
        
        while (tmp != nullptr && tmp != node)
        {
            tmp = tmp->getNext();
            ++pos;
        }
        
        if (pos == _size){ return -1; }
        
        return pos;
    }
    
    template <class T>
    std::ostream & operator <<(std::ostream & os, LinkedList<T> & list)
    {
        for (auto node : list )
        {
            os << node << std::endl;
        }
        
        return os;
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::operator [](const int position)
    {
        return at(position);
    }
    
    template  <class T>
    LinkedList<T>* LinkedList<T>::unionWhith (LinkedList<T> & secondList){
        LinkedList<int> * new_list  = new LinkedList<int>();

        Node<T> * tmp = _first;
        
        while (tmp != nullptr)
        {
            new_list->insertBack(tmp->getInfo());
            tmp = tmp->getNext();
        }
        
        Node<T> * tmp_j = secondList.first();
        while (tmp_j != nullptr)
        {
            int found = 0;
            tmp = new_list->first();
            while (tmp != nullptr) {
                if (tmp_j->getInfo() == tmp->getInfo()) {
                    found = 1;
                }
                tmp = tmp->getNext();
            }
            if (found==0) {
                new_list->insertBack(tmp_j->getInfo());
            }
           
            tmp_j = tmp_j->getNext();
        }
        return new_list;
    }
}

#endif /* defined(__tarea_3_2__LinkedList__) */
