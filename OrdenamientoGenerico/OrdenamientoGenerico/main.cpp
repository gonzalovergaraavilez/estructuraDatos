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

int main(int argc, const char * argv[]) {
    int opcion_menu= 1;
    int contador = 4;
    const int numero_max = 10;
    
    Book biblioteca[numero_max];
    biblioteca[0]= Book("100 años", "Garcia Marquez", 123, 2, "meme", 1990);
    biblioteca[1]= Book("ensayos sobre la seguera", "José Saramago", 123, 2, "meme", 1980);
    biblioteca[2]= Book("100 años", "Garcia Marquez", 123, 2, "meme", 2000);
    biblioteca[3]= Book("Ejemplo de libro", "Haruki Murakami", 123, 2, "meme", 2015);

    std::string titulo;
    std::string autor;
    int paginas;
    int edicion;
    std::string editorial;
    int anio;
    
    while (opcion_menu!=0) {
        print_string("\nMenú \n 1. Crear libro \n 2. Eliminar Libro \n 3. Mostrar libros antes de fecha n 4. Mostrar libros después de fecha \n  ");
        std::cin >> opcion_menu;
        switch (opcion_menu) {
            case 1:
                if (contador<numero_max) {
                    titulo = get_string_attribute("Título");
                    autor = get_string_attribute("Autor");
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
                int fecha;
                std::cin >> fecha;
                find_before(fecha, numero_max, biblioteca);
                break;
            case 4:
                print_string("Fecha: ");
                int fecha2;
                std::cin >> fecha2;
                find_after(fecha2, numero_max, biblioteca);
                break;
            default:
                break;
        }
    }
    
    return 0;
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