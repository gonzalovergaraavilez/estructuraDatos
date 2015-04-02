//
//  main.cpp
//  tarea_4_3
//
//  Created by Gonzalo Vergara on 3/31/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include "DCircularLinkedList.h"
#include <fstream>
#include <sstream>
#include <ncurses.h>

#define OFFSET  3
DCircularLinkedList<char> newCircularList();

int main(int argc, const char * argv[]) {
    
    using namespace gva;
    
    /* Demostrar el uso de la clase genérica DCircularLinkedList<T> */
    
    /* Declaración de una lista de enteros */
    DCircularLinkedList<LinkedList<char> *>  lineas;
    
    std::ofstream myfile;
    myfile.open ("fil2e.txt");
    myfile << "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod\ntempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,\nquis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo\nconsequat. Duis aute irure dolor in reprehenderit in voluptate velit esse\ncillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non\nproident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    myfile.close();
    
    LinkedList<char> *tempLine = new LinkedList<char>;;
    std::string line;
    char character;
    std::ifstream myfile2 ("fil2e.txt");
    if (myfile2.is_open())
    {
        while (std::getline(myfile2, line))
        {
            //std::cout << line;
            tempLine = new LinkedList<char>;
            std::stringstream ss;
            ss.str(line);
            while(ss >> character){
                tempLine->insertBack(character);
                //std::cout << character;
            }
            //std::cout << std::endl;
            lineas.insertBack(tempLine);
        }
        myfile2.close();
    }else std::cout << "Unable to open file";
    
    delete tempLine;
    

    
    /*ncurses*/
    //WINDOW *subwindow;
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    
    printw("Welcome");
    
    /*subwindow = newwin(LINES-OFFSET,
                           COLS,
                           OFFSET,
                           0);*/
    
    //box(subwindow, 0 , 0);
    
    
    int ch;
    int x, y;
    x = 123;
    clear();
    refresh();
    
    /*wclear(subwindow);
    printw("The pressed key is ");
    attron(A_BOLD);
    printw("%c", ch);
    wrefresh(subwindow);
    box(subwindow, 0 , 0);
    attroff(A_BOLD);*/
    
    
    
    //Node
    /*
    Node<char> * tmpnode;
    tmpnode = lineas.first()->getInfo()->first();
    do{
        std::cout << tmpnode->getInfo();
        tmpnode = tmpnode->getNext();
        
    }while (tmpnode!=nullptr);*/

    Node< LinkedList<char> * > * tmp = lineas.first();
     Node<char> *charnode = tmp->getInfo()->first();
    do{
     while (charnode != nullptr) {
         std::cout <<charnode->getInfo();
     charnode = charnode->getNext();
     }
     tmp = tmp->getNext();
     charnode = tmp->getInfo()->first();
     //std::cout << std::endl;
     
     }while (tmp != lineas.first());
    
    while((ch = getch()) != 'x'){
        getyx(stdscr, y, x);
        switch (ch) {
            case KEY_LEFT:
                move(y, x-1);
                break;
            case KEY_RIGHT:
                move(y, x+1);
                break;
            case KEY_UP:
                move(y-1, x);
                break;
            case KEY_DOWN:
                move(y+1, x);
                break;
        }
    }
    
    

    /* Imprimir el contenido de la lista */
    //std::cout << lineas << std::endl;
    
    
    delwin(stdscr);
    
    endwin();
    
    return 0;
}

