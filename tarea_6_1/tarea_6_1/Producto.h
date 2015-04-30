//
//  Producto.h
//  tarea_6_1
//
//  Created by Gonzalo Vergara on 4/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef tarea_6_1_Producto_h
#define tarea_6_1_Producto_h
class Producto{
private:
    std::string description = "Default";
    int quantity = 0;
    int price = 0;
public:
    Producto() {}
    virtual ~Producto();
    
    Producto(std::string _description, int _quantity, int _price) : description(_description), quantity(_quantity), price(_price){}

    std::string getDescription(){return description;}
    int getQuantity(){return quantity;}
    int getPrice(){return price;}
    
    void setDescription(std::string value){description = value;}
    void setQuantity(int value){quantity = value;}
    void setPrice(int value){price = value;}
    
    friend std::ostream & operator << (std::ostream & os, Producto  & producto);
    
};
std::ostream & operator << (std::ostream & os, Producto  & producto)
{
    os << producto.description << "\t\t\t";
    os << producto.quantity << "\t\t\t";
    os << "$" << producto.price;
    os << std::endl;
    
    return os;
}
Producto::~Producto(){
    description = "empty";
    quantity = 0;
    price = 0;
}
#endif
