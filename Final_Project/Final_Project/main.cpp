//
//  main.cpp
//  Final_Project
//
//  Created by Gonzalo Vergara on 5/4/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//
#include <iostream>
#include "DCircularLinkedList.h"
#include "Point.h"
#include "Step.h"
#include <limits>
#include <math.h> 

void print_menu();
double read_input();
void read_greater_than_zero();
void read_greater_than_zero_precision();

/*Trayectorias*/
double calculate_c(double,double);
double calculate_a(double,double, double);
double calculate_b(double,double, double);
double calculate_th1(double,double, double);
double calculate_th2(double, double);
double calculate_x1(double, double);
double calculate_y1(double, double);


template <class P>
void scale(P *, double);

template <class P>
void translate_scale(P, double, double, double);
    
template <class P>
void translate(P *, double, double);

template <class P>
bool transformationes_loop(P *);

template <class P>
bool trayectories_loop(P *);

int n;
double n_precision;
double scale_to;

int main(int argc, const char * argv[]) {
    using namespace gva;
    bool e;
    print_menu();
    n = read_input();
    while (n!=0) {
        switch (n) {
            case 1:
                e = transformationes_loop(new DCircularLinkedList<Point*>());
                break;
            case 2:
                e = trayectories_loop(new DCircularLinkedList<Step*>());
                break;
            default:
                std::cout << "Esa no es una opción del meúnu. Intenta de nuevo\n\n";
                print_menu();
                n = read_input();
                break;
        }
        print_menu();
        n = read_input();
}
    
    std::cout << "Goodbye!\n";
    return 0;
}
void print_menu(){
    std::cout << "---- Cinemática Inversa y Matriz de Transformación Homogénea ----\n[1] Transformaciones\n[2] Trayectorias\n[0] Salir\n \nSelección: ";
}
double calculate_c(double a,double b){return sqrt(a*a+b*b);}
double calculate_a(double l1,double l2, double c){return acos((l2*l2+c*c-l1*l1)/(2*c*l2));}
double calculate_b(double l1,double l2, double a){return asin(l2/l1*sin(a));}
double calculate_th1(double xi,double yi, double b){return atan(yi/xi)-b;}
double calculate_th2(double a, double b){return a+b;}
double calculate_x1(double l1, double th1){return l1*cos(th1);}
double calculate_y1(double l1, double th1){return l1*sin(th1);}

template <class P>
bool trayectories_loop(P *f){
    double _xi,_yi, _l1, _l2, _xf, _yf, _stps, _a, _b, _c, _th1, _th2, _dx, _dy, _x1, _y1;
    std::cout << "\n\n---- Trayectorias ----\n";
    
    std::cout << "¿Cuánto mide la primera articulación?: ";
    read_greater_than_zero_precision();
    _l1 = n_precision;
    std::cout << "¿Cuánto mide la segunda articulación?: ";
    read_greater_than_zero_precision();
    _l2 = n_precision;
    std::cout << "xi: ";
    read_greater_than_zero_precision();
    _xi = n_precision;
    std::cout << "yi: ";
    read_greater_than_zero_precision();
    _yi = n_precision;
    std::cout << "xf: ";
    read_greater_than_zero_precision();
    _xf = n_precision;
    std::cout << "yf: ";
    read_greater_than_zero_precision();
    _yf = n_precision;
        std::cout << "¿Cuántos pasos?: ";
    read_greater_than_zero_precision();
    _stps = n_precision;
    
    _c = calculate_c(_xi, _yi);
    _a = calculate_a(_l1, _l2, _c);
    _b = calculate_b(_l1, _l2, _a);
    _th1 = calculate_th1(_xi, _yi, _b);
    _th2 = calculate_th2(_a, _b);
    _x1 = calculate_x1(_l1, _th1);
    _y1 = calculate_y1(_l1, _th1);
    _dx = (_xf-_xi)/_stps;
    _dy = (_yf-_yi)/_stps;
    
    std::cout << "\nCalculando pasos...\n ---- \n";
    Step *tmp_step = new Step(_xi, _yi, _x1, _y1, _a, _b, _c, _th1, _th2);
    f->insertBack(tmp_step);
    for(int j=0;j<=_stps;j++){
        std::cout << *tmp_step;
        _xi +=_dx;
        _yi +=_dy;
        _c = calculate_c(_xi, _yi);
        _a = calculate_a(_l1, _l2, _c);
        _b = calculate_b(_l1, _l2, _a);
        _th1 = calculate_th1(_xi, _yi, _b);
        _th2 = calculate_th2(_a, _b);
        _x1 = calculate_x1(_l1, _th1);
        _y1 = calculate_y1(_l1, _th1);
        tmp_step= new Step(_xi, _yi, _x1, _y1, _a, _b, _c, _th1, _th2);
        f->insertBack(tmp_step);
    }
    delete tmp_step;
    std::cout << "----\n\n";

    return  true;
}

template <class P>
bool transformationes_loop(P *f){
    double _x,_y;
    std::cout << "\n\n---- Transformaciones ----\n";
    
    std::cout << "¿Cuántos puntos tiene la figura?: ";
   
    read_greater_than_zero();
    
    for (int i=0; i<n; i++) {
        std::cout << "\nx" <<i+1 << ": " ;
        _x = read_input();
        std::cout << "\ny" <<i+1 << ": " ;
        _y = read_input();
            Point *newpoint = new Point(_x, _y);
        f->insertBack(newpoint);
        //delete newpoint; no funciona si se queda el delete
    }
    std::cout << "¿Qué tipo de transformación quieres hacer?\n[1] Escalamiento\n[2] Traslación\n[3] Ambas\n[0] Salir\n \nSelección: ";
    n = read_input();
    switch (n) {
        case 1:
            std::cout << "¿Cuánto quieres escalarlo?: ";
            read_greater_than_zero_precision();
            scale(f, n_precision);
            break;
        case 2:
            std::cout << "Traslación en \nx: ";
             _x = read_input();
            std::cout << "Traslación en \ny: ";
            _y = read_input();
            translate(f,_x, _y);
            break;
        case 3:
            std::cout << "¿Cuánto quieres escalarlo?: ";
            read_greater_than_zero_precision();
            std::cout << "Traslación en \nx: ";
            _x = read_input();
            std::cout << "Traslación en \ny: ";
            _y = read_input();
            translate_scale(f,_x, _y, n_precision);
            break;
        case 0:
            break;
        default:
            std::cout << "Esa no es una opción del meúnu. Intenta de nuevo: ";
            n = read_input();
            break;
    }
    return true;
}
template <class P>
void translate_scale(P *f, double _x, double _y, double _s){
    Node<Point * > *tmp_point =f->at(0);
    double calc;
    std::cout << "Excalando y trasladando...\n ---- \n";
    
    do{
        calc =tmp_point->getInfo()->getX()*_s+_x;
        tmp_point->getInfo()->setXN(calc);
        calc =tmp_point->getInfo()->getY()*_s+_y;
        tmp_point->getInfo()->setYN(calc);
        std::cout << *tmp_point->getInfo();
        tmp_point = tmp_point->getNext();
        
    }while (tmp_point != f->at(0));
    
    std::cout << "\n---- \n\n";

}
template <class P>
void translate(P *f, double _x, double _y){
    Node<Point * > *tmp_point =f->at(0);
    double calc;
    std::cout << "Trasladando...\n ---- \n";
    
    do{
        calc =tmp_point->getInfo()->getX()+_x;
        tmp_point->getInfo()->setXN(calc);
        calc =tmp_point->getInfo()->getY()+_y;
        tmp_point->getInfo()->setYN(calc);
        std::cout << *tmp_point->getInfo();
        tmp_point = tmp_point->getNext();
        
    }while (tmp_point != f->at(0));
    
    std::cout << "\n---- \n\n";
}
template <class P>
void scale(P *f, double s){
    Node<Point * > *tmp_point =f->at(0);
    double calc;
    std::cout << "Escalando...\n ---- \n";

    do{
        calc =tmp_point->getInfo()->getX()*s;
        tmp_point->getInfo()->setXN(calc);
        calc =tmp_point->getInfo()->getY()*s;
        tmp_point->getInfo()->setYN(calc);
        std::cout << *tmp_point->getInfo();
        tmp_point = tmp_point->getNext();
        
    }while (tmp_point != f->at(0));
    
    std::cout << "\n---- \n\n";
}
void read_greater_than_zero_precision(){
    n_precision = read_input();
    while (n_precision<=0) {
        std::cout << "Fuera de rango. Intenta de nuevo: ";
        n_precision = read_input();
    }
    if (n_precision>100) {
        std::cout << "Tiene que ser menor a 100, se truncará a el máximo: ";
        n_precision = 100;
    }
    
}
void read_greater_than_zero(){
     n = read_input();
    while (n<=0) {
        std::cout << "Fuera de rango. Intenta de nuevo: ";
        n = read_input();
    }
}
double read_input()
{
    double input = -1;
    bool valid= false;
    do
    {
        std::cin >> input;
        if (std::cin.good())
        {
            valid = true;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Entrada inválida. Vuelve a intentar: ";
        }
    } while (!valid);
    
    return (input);
}
