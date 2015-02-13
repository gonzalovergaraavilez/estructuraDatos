//
//  main.cpp
//  OrdenamientoGenerico
//
//  Created by Gonzalo Vergara on 2/5/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <ostream>
#include "OrdenamientoGenerico.h"
#include "Book.h"

std::string get_string_attribute(std::string);
int get_int_attribute(std::string);
void print_all(int, Book[]);
void print_string(std::string);
void find_before(int, int, Book[]);
void find_after(int, int, Book[]);
void find_between(int, int, int, Book[]);
void find_author(std::string, int, Book[]);
void find_editorial(std::string, int , Book[]);

int main(int argc, const char * argv[]) {
    int opcion_menu= 1;
    int contador = 4;
    const int numero_max = 10;
    
    Book biblioteca[numero_max];
    biblioteca[0]= Book("100 años", "Garcia", 123, 2, "porrua", 1990);
    biblioteca[1]= Book("ensayos sobre la seguera", "Saramago", 123, 2, "meme", 1980);
    biblioteca[2]= Book("100 años", "Garcia", 123, 2, "meme", 2000);
    biblioteca[3]= Book("Ejemplo de libro", "Murakami", 123, 2, "meme", 2015);

    std::string titulo;
    std::string autor;
    int paginas;
    int edicion;
    std::string editorial;
    int anio;
    
    int fecha;
    int fecha2;
    
    while (opcion_menu!=0) {
        print_string("\nMenú \n 1. Crear libro \n 2. Eliminar Libro \n 3. Mostrar libros antes de fecha \n 4. Mostrar libros después de fecha \n 5. Mostrar libros entre 2 fechas \n 6. Mostrar libros escritos por un autor \n 7. Mostrar libros de una editorial \n  ");
        std::cin >> opcion_menu;
        switch (opcion_menu) {
            case 1:
                if (contador<numero_max) {
                    titulo = get_string_attribute("Título");
                    autor = get_string_attribute("Apellido de Autor");
                    paginas = get_int_attribute("Número de páginas");
                    edicion = get_int_attribute("No. de Edición");
                    editorial = get_string_attribute("Editorial");
                    anio = get_int_attribute("Año de publicación");
                    biblioteca[contador]=Book(titulo, autor,paginas, edicion, editorial,anio);
                    std::cout << "Libro creado: \n" << biblioteca[contador];
                    contador++;
                }else{
                    std::cout << "Número máximo de libros alcanzado\n";
                }
                
                break;
            case 2:
                print_all(numero_max, biblioteca);
                print_string("Número de libro a eliminar: ");
                int elimina_n;
                std::cin >> elimina_n;
                biblioteca[elimina_n-1]= Book();
                print_string("Libro eliminado \n");
                print_all(numero_max, biblioteca);
                break;
            case 3:
                print_string("Fecha: ");
                std::cin >> fecha;
                find_before(fecha, numero_max, biblioteca);
                break;
            case 4:
                print_string("Fecha: ");
                std::cin >> fecha;
                find_after(fecha, numero_max, biblioteca);
                break;
            case 5:
                print_string("Fecha 1: ");
                std::cin >> fecha;
                print_string("Fecha 2: ");
                std::cin >> fecha2;
                find_between(fecha, fecha2, numero_max, biblioteca);
                break;
            case 6:
                print_string("Autor: ");
                std::cin >> autor;
                find_author(autor, numero_max, biblioteca);
                break;
            case 7:
                print_string("Editorial: ");
                std::cin >> editorial;
                find_editorial(editorial, numero_max, biblioteca);
                break;
            default:
                break;
        }
    }
    
    return 0;
}

void find_editorial(std::string _editorial, int n, Book bib[]){
    for (int i=0; i<n; i++) {
        if(bib[i]>0){ //checar que por lo menos el año de publicación sea mayor a cero
            if (bib[i].has_equal_editorial(_editorial)) {
                std::cout << bib[i];
            }
        }
    }
}
void find_author(std::string auth, int n, Book bib[]){
    for (int i=0; i<n; i++) {
        if(bib[i]>0){ //checar que por lo menos el año de publicación sea mayor a cero
            if (bib[i].has_equal_author(auth)) {
                std::cout << bib[i];
            }
        }
    }
}
void find_between(int fecha, int fecha2, int n, Book bib[]){
    if (fecha<fecha2){
            for (int i=0; i<n; i++) {
                if(bib[i]>0){
                    if (bib[i]>fecha&&bib[i]<fecha2) {
                        std::cout << bib[i];
                    }
                }
            }
    }else{
        print_string("La primera fecha debe ser menor a la segunda");
    }
}

void find_before(int fecha, int n, Book bib[]){
    for (int i=0; i<n; i++) {
        if(bib[i]>0){
            if (bib[i]<fecha) {
                std::cout << bib[i];
            }
        }
    }
}
void find_after(int fecha, int n, Book bib[]){
    for (int i=0; i<n; i++) {
        if(bib[i]>0){
            if (bib[i]>fecha) {
                std::cout << bib[i];
            }
        }
    }
}

void print_string(std::string string){
    std::cout << string;
}
void print_all(int n, Book bib[]){
    print_string("\n");
    for (int i=0; i<n; i++) {
        std::cout <<  i+1 << ". " << bib[i] << "";
    }
}
std::string get_string_attribute(std::string atributo){
    std::cout << atributo << ": ";
    std::string temp_string;
    std::cin >> temp_string;
    return temp_string;
}
int get_int_attribute(std::string atributo){
    std::cout << atributo << ": ";
    int temp_int;
    std::cin >> temp_int;
    return temp_int;
}