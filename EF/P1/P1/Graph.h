//
//  Graph.h
//  P1
//
//  Created by Gonzalo Vergara on 5/12/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef P1_Graph_h
#define P1_Graph_h

#include "Vertex.h"
#include <string>
#include <algorithm>

template <class V, class E>
class Graph {
    
    std::string name;
    std::vector< Vertex<V, E> * > nodes;
    
public:
    Graph() { }
    Graph(std::string _name) : name(_name) { }
    ~Graph();
    
    bool isComplete();
    
    void addVertex(Vertex<V, E> * vertex);
    void addEdge(Vertex<V, E> * source, Vertex<V, E> * target, const E & info);
    void removeEdge(Vertex<V, E> * source, Vertex<V, E> * target, const E & info);
    
    template <class Vn, class En>
    friend std::ostream & operator<<(std::ostream & os, const Graph<Vn, En> & graph);
};
template <class V, class E>
bool Graph<V, E>::isComplete(){
    double size = nodes.size();
    double other_size = 0;
    for (auto v : nodes){
        auto node = find(nodes.begin(), nodes.end(), v);
        Vertex<V, E> * vertex = (*node);
        std::vector< Edge<V, E> * > * edges = vertex->getEdges();
        other_size = edges->size();
        other_size++;
        if(other_size!=size){ //Si el número de conexiones de algún vértices no es n-1 (su tamaño +1) entonces no es completo
            std::cout << "No es completo" << std::endl;
            return false;
        }
        
    }
    std::cout << "Es completo!" << std::endl;
    return true;
}

template <class V, class E>
Graph<V, E>::~Graph()
{
    for (auto v : nodes) {
        delete v;
    }
    
    nodes.clear();
}

template <class V, class E>
void Graph<V, E>::addVertex(Vertex<V, E> * vertex)
{
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V, E>::addEdge(Vertex<V, E> * source, Vertex<V, E> * target, const E & info)
{
    auto node = find(nodes.begin(), nodes.end(), source);
    
    /* Crear una arista y adicionarla al vertex */
    Edge<V, E> * edge = new Edge<V, E>(info, target);
    
    (*node)->addEdge(edge);
}

template <class V, class E>
void Graph<V, E>::removeEdge(Vertex<V, E> * source, Vertex<V, E> * target, const E & info)
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    
    Vertex<V, E> * vertex = (*node);
    
    std::vector< Edge<V, E> * > * edges = vertex->getEdges();
    
    Edge<V, E> * edge = nullptr;
    
    for (auto e : *edges) {
        if (e->getInfo() == info && e->getTarget() == target) {
            edge = e;
            break;
        }
    }
    
    
    if (edge) {
        vertex->removeEdge(edge);
    }
    
}

template <class V, class E>
std::ostream & operator<<(std::ostream & os, const Graph<V, E> & graph)
{
    os << "--- Graph: " << graph.name << " ---" << std::endl;
    
    for (auto v : graph.nodes) {
        os << *v;
    }
    
    return os;
}

#endif
