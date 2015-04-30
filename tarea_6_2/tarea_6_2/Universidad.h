//
//  Universidad.h
//  tarea_6_2
//
//  Created by Gonzalo Vergara on 4/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef tarea_6_2_Universidad_h
#define tarea_6_2_Universidad_h
#include "Estudiante.h"
#include <stack>

class Universidad{
private:
    std::string nombre = "Nombre";
    Estudiante *max_relaciones = nullptr;
    Estudiante *max_estable = nullptr; //Asumiendo el más estable como el que tiene mayor tiempo promedio por relación
    std::vector<Estudiante*> estudiantes;
public:
    Universidad() {}
    virtual ~Universidad();
    
    Universidad(std::string _nombre) : nombre(_nombre){}
    
    std::string getNombre();
    Estudiante * getMaxRelaciones(){return max_relaciones;}
    Estudiante * getMaxEstable(){return max_estable;}
    
    void setNombre(std::string value){nombre = value;}
    void setMaxRelaciones(Estudiante * value){max_relaciones = value;}
    void setMaxEstable(Estudiante * value){max_estable = value;}
    void setEstudiantes(std::vector<Estudiante *> value){estudiantes= value;}
    
    void addEstudiante(Estudiante *);
    
    friend std::ostream & operator << (std::ostream & os, Universidad  & universidad);
    
};
void Universidad::addEstudiante(Estudiante *e){
    estudiantes.push_back(e);
    if (max_relaciones==nullptr || (e->getNRelaciones()>max_relaciones->getNRelaciones())) {
        max_relaciones = e;
    }
    if (max_estable ==nullptr || (e->getTiempoPromedio()>max_estable->getTiempoPromedio())) {
        max_estable = e;
    }
}

std::ostream & operator << (std::ostream & os, Universidad  & universidad)
{
    os << "Universidad: " << universidad.nombre << std::endl << "----" << std::endl << std::endl;
    os << "Estudiantes CON relaciones: " <<std::endl << "---- " << std::endl;
    std::stack<Estudiante *> sin_relaciones;
    for(int i = 0; i<universidad.estudiantes.size();i++){
        if(universidad.estudiantes[i]->getNRelaciones()>0){
            os << *universidad.estudiantes[i];
        }else{
            sin_relaciones.push(universidad.estudiantes[i]);
        }
    }
    if(!sin_relaciones.empty()){
        os << std::endl;
        os << "Estudiantes SIN relaciones: " <<std::endl << "---- " << std::endl;
        while(!sin_relaciones.empty()){
            os << *sin_relaciones.top();
            sin_relaciones.pop();
        }

    }
    os << std::endl;
    os << "Máximos: " << std::endl << "---" << std::endl;
    os << "Estudiante con mayor número de relaciones: " << universidad.max_relaciones->getNombre() << std::endl;
    os << "Estudiante con mayor estabilidad: " << universidad.max_estable->getNombre() << std::endl;
    return os;
}
Universidad::~Universidad(){
    nombre = "";
    max_relaciones = nullptr;
    max_estable = nullptr;
    estudiantes.clear();
}

#endif
