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
    WINDOW *subwindow;
    WINDOW *textwindow;
    int offsetx, offsety;
    
    initscr();
    refresh();
    
    offsetx = 0;
    offsety = 10;
    
    subwindow = newwin(10, COLS, offsety, offsetx);
    textwindow = newwin(10, COLS, 0, 0);
    
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    int ch;
    int x, y;
    x = 123;
    clear();
    refresh();
    int line_length;
    int word_n = 0;
    int move_to = 0;
    
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
    wclear(textwindow);
    do{
        while (charnode != nullptr) {
            wprintw(textwindow,"%s ",(charnode->getInfo()).c_str());
            charnode = charnode->getNext();
            wrefresh(textwindow);
        }
        wprintw(textwindow,"\n");
        //std::cout << std::endl;
        tmp = tmp->getNext();
        charnode = tmp->getInfo()->first();
        //std::cout << std::endl;
    }while (tmp != lineas.first());
    wrefresh(textwindow);
    move(0, 0);
    /*ncurses loop */
    while((ch = getch()) != 'x'){
        //printw("key pressed %d",ch);
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
            case 27: //ESC
                wprintw(textwindow,"exit ket pressed");
                break;
            case KEY_SLEFT:
                getyx(stdscr, y, x);
                move(y,0);
                //printw("shifted left arrow");
                break;
            case 127:
                //printw("backspace");
                //wclear(stdscr);
                wclear(subwindow);
                getyx(stdscr, y, x);
                wprintw(subwindow,"current coords: x: %d, y: %d \n", x, y);
                tmp = lineas.at(y);
                if(tmp!=nullptr){
                    wprintw(subwindow,"\n tmp  not null");

                    charnode = tmp->getInfo()->first();
                    line_length = 0; //Compensate last word whitespace
                    word_n = 0;
                    while (charnode != nullptr) {
                        if(line_length<=x){
                            line_length +=(charnode->getInfo()).length();
                            line_length++; //whitespace
                            //wprintw(subwindow,"\nline_length: %d", line_length);
                            word_n++;
                        }
                        charnode = charnode->getNext();
                    }
                    charnode = tmp->getInfo()->at(word_n-1);
                    x=line_length-2;
                    x-=(charnode->getInfo()).length();
                    if (x<0) x= 0;
                    wprintw(subwindow,"\nword_n: %d", word_n);
                    tmp->getInfo()->remove(word_n-1);
                    
                    //wprintw(subwindow,"\nword_n content after delete: %s", (tmp->getInfo()->at(word_n-1)->getInfo()).c_str());
                    
                    /*charnode = tmp->getInfo()->first();
                    if(word_n>1){
                        while (charnode != tmp->getInfo()->at(word_n-2)) {
                            x+=(charnode->getInfo()).length()+1;
                            charnode = charnode->getNext();
                        }
                        x--; //last whitespace
                    }*/
                    move(y, x);
                    
                    wrefresh(subwindow);
                    wrefresh(textwindow);
                     //reprint
                    wclear(textwindow);
                     tmp = lineas.first();
                     charnode = tmp->getInfo()->first();
                     do{
                     while (charnode != nullptr) {
                     wprintw(textwindow,"%s ",(charnode->getInfo()).c_str());
                     charnode = charnode->getNext();
                     refresh();
                     }
                     wprintw(textwindow,"\n");
                     //std::cout << std::endl;
                     tmp = tmp->getNext();
                     charnode = tmp->getInfo()->first();
                     //std::cout << std::endl;
                     }while (tmp != lineas.first());

                    wrefresh(textwindow);
                }
                //wrefresh(subwindow);
                //refresh();
                break;
            case KEY_SRIGHT:
                getyx(stdscr, y, x);
                tmp = lineas.at(y);
                charnode = tmp->getInfo()->first();
                line_length = -1; //Compensate last word whitespace
                while (charnode != nullptr) {
                    line_length +=(charnode->getInfo()).length(); //addch() for ncurses
                    line_length++; //whitespace
                    charnode = charnode->getNext();
                }
                //printw("%d", line_length);
                move(y,line_length);
                break;
        }
        refresh();
        
    }
    /*ncurses*/
    delwin(stdscr);
    delwin(subwindow);
    endwin();
    
    return 0;
}

