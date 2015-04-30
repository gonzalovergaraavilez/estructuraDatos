//
//  Estudiante.h
//  tarea_6_2
//
//  Created by Gonzalo Vergara on 4/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef tarea_6_2_Estudiante_h
#define tarea_6_2_Estudiante_h
#include <vector>
class Relacion;

class Estudiante{
private:
    std::string nombre = "Nombre";
    float porcentaje_acompanado = 0.0;
    int n_relaciones = 0;
    float tiempo_promedio = 0;
    std::vector<Relacion> relaciones;
    float tiempo_total = 4.0; //Asumiendo un tiempo total de 4 años. Tiempos en fracciones de años
public:
    Estudiante() {}
    virtual ~Estudiante();
    
    Estudiante(std::string _nombre) : nombre(_nombre){}
    
    std::string getNombre();
    float getPorcentajeAcompanado(){return porcentaje_acompanado;}
    int getNRelaciones(){return n_relaciones;}
    float getTiempoPromedio(){return tiempo_promedio;}
    
    void setNombre(std::string value){nombre = value;}
    void setPorcentajeAcompanado(float value){porcentaje_acompanado = value;}
    void setNRelaciones(int value){n_relaciones = value;}
    void setTiempoPromedio(float value){tiempo_promedio= value;}
    
    void addRelacion(Estudiante *, float);
    
    friend std::ostream & operator << (std::ostream & os, Estudiante  & estudiante);
    
};
class Relacion{
private:
    Estudiante *relacionado;
    float tiempo;
    
public:
    Relacion() {}
    virtual ~Relacion();
    
    Relacion(Estudiante *_relacionado, float _tiempo) : relacionado(_relacionado), tiempo(_tiempo){}
    
    float getTiempo(){return tiempo;}
    Estudiante * getRelacionado(){return relacionado;}
    
    void setTiempo(float value){tiempo = value;}
    void setRelacionado(Estudiante *value){relacionado = value;}
    
    friend std::ostream & operator << (std::ostream & os, Relacion  & relacion);
    
};
std::ostream & operator << (std::ostream & os, Relacion  & relacion)
{
    os << "Con: " << relacion.relacionado->getNombre() << "\t\t\t";
    os << "Duración: " << relacion.tiempo << std::endl;
    
    return os;
}
Relacion::~Relacion(){
    relacionado = nullptr;
    tiempo = 0;
}

std::string Estudiante::getNombre(){
    return nombre;
}
void Estudiante::addRelacion(Estudiante *r, float t){
    Relacion temp_relacion = Relacion(r, t);
    relaciones.push_back(temp_relacion);
    porcentaje_acompanado = (porcentaje_acompanado*tiempo_total+t)/tiempo_total;
    n_relaciones++;
    tiempo_promedio = (tiempo_promedio*(n_relaciones-1)+t)/n_relaciones;
}
std::ostream & operator << (std::ostream & os, Estudiante  & estudiante)
{
    os << "Estudiante: " << estudiante.nombre << std::endl;
    if(!estudiante.relaciones.empty()){
        os << "Relaciones: " << std::endl << "--------" << std::endl;
        for(int i =0;i<estudiante.relaciones.size();i++){
            os << estudiante.relaciones[i];
        }
        os << "--------" << std::endl;
        os << "Porcentaje acompañado: " << estudiante.porcentaje_acompanado*100 << "%, porcentaje solo: " << (1-estudiante.porcentaje_acompanado)*100 << "%" << std::endl;
        os << "Tiempo promedio: " << estudiante.tiempo_promedio << " años" << std::endl;
        os << std::endl;
    }
    
    return os;
}
Estudiante::~Estudiante(){
    nombre = "";
    porcentaje_acompanado = 0.0;
    n_relaciones = 0;
    tiempo_promedio = 0;
    relaciones.clear();
}

#endif
