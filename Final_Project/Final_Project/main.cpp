//
//  main.cpp
//  Final_Project
//
//  Created by Gonzalo Vergara on 5/4/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//
#include <iostream>
#include "DCircularLinkedList.h"
#include <ncurses.h>
    
#define OFFSET  3

    int main(int argc, const char * argv[]) {
        
        using namespace gva;
        
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
        
        wclear(subwindow);
        wprintw(subwindow,"1. Move arround with the arrow keys\n2. Save the file with 's'\n3. Press ENTER to insert a new line\n4. Use BACKSPACE to delete words or lines\n5. Press 'i' to enter Insert Word Mode\n6. Press 'q' to exit");
        wrefresh(subwindow);
        /*ncurses loop */
        while((ch = getch()) != 'q'){
            //wprintw(subwindow, "\nkey pressed %d",ch);
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
                case KEY_SLEFT:
                    getyx(stdscr, y, x);
                    move(y,0);
                    //printw("shifted left arrow");
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
