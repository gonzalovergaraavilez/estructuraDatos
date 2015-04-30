//
//  Contenedor.h
//  tarea_6_1
//
//  Created by Gonzalo Vergara on 4/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef tarea_6_1_Contenedor_h
#define tarea_6_1_Contenedor_h
#include "Producto.h"

class Contenedor{
private:
    int id_no = 0;
    std::string empresa = "None";
    std::vector<Producto*> products;
    int total = 0;
public:
    Contenedor() {}
    virtual ~Contenedor();
    
    Contenedor(int _id_no, std::string _empresa) : id_no(_id_no), empresa(_empresa){}
    
    int getIDno(){return id_no;}
    std::string getEmpresa(){return empresa;}
    std::vector<Producto*> getProducts(){return products;}
    int getTotal(){return total;}
    void setIDno(int value){id_no = value;}
    void setEmpresa(std::string value){empresa = value;}
    void setProducts(std::vector<Producto*> value){products = value;}
    void addProduct(Producto *value){products.push_back(value);total+=(value->getPrice()*value->getQuantity());}
    
    friend std::ostream & operator << (std::ostream & os, Contenedor  & contenedor);
    
};
std::ostream & operator << (std::ostream & os, Contenedor  & contenedor)
{
    os << "---- Contenedor " << contenedor.id_no << " Perteneciente a " << contenedor.empresa << " ----" << std::endl;
    for (int i=0;i<contenedor.products.size();i++){
        os << *contenedor.products[i];
    }
    os << "Costo del contenedor: $" << contenedor.total << std::endl;
    return os;
}
Contenedor::~Contenedor(){
    total = 0;
    empresa = "empty";
    id_no = 0;
    products.clear();
}

#endif
