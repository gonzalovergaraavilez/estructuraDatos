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
    
    DCircularLinkedList<LinkedList<std::string> *>  lineas;
    LinkedList<std::string> palabras;

    
    /*ncurses*/
    //WINDOW *subwindow;
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    int ch;
    int x, y;
    x = 123;
    clear();
    refresh();
    
    std::ofstream myfile;
        myfile.open ("fil2e.txt");
        myfile << "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod \ntempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,\nquis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo \nconsequat. Duis aute irure dolor in reprehenderit in voluptate velit esse \ncillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non \nproident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n";
        myfile.close();

    LinkedList<std::string> *tempLine = new LinkedList<std::string>;
        std::string line;
        std::string word;
        std::ifstream myfile2 ("fil2e.txt");
        if (myfile2.is_open())
            {
                while ( std::getline (myfile2,line) )
                        {
                            tempLine = new LinkedList<std::string>;
                            std::stringstream ss(line);
                                while(ss >> word){
                                        tempLine->insertBack(word);
                                    }
                                lineas.insertBack(tempLine);
                            }
                    myfile2.close();
                }else std::cout << "Unable to open file";
    delete tempLine;
    
    Node< LinkedList<std::string> * > * tmp = lineas.first();
    Node<std::string> *charnode = tmp->getInfo()->first();
    clear();
    do{
        while (charnode != nullptr) {
            printw("%s ",(charnode->getInfo()).c_str()); //addch() for ncurses
            charnode = charnode->getNext();
            refresh();
        }
        printw("\n");
        //std::cout << std::endl;
        tmp = tmp->getNext();
        charnode = tmp->getInfo()->first();
        //std::cout << std::endl;
    }while (tmp != lineas.first());
    /*ncurses loop */
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
        refresh();
        
    }
    /*ncurses*/
    delwin(stdscr);
    
    endwin();
    
    return 0;
}

