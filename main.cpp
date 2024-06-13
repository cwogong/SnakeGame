// dir :    C:\Users\cwogo\Desktop\"국민대학교"\"2024-1학기"\"(전공)C++프로그래밍(최준수)"\"2024-기말프로젝트"\test
// compile : g++ -o SnakeGame main.cpp window.cpp snake.cpp ui.cpp growth.cpp poison.cpp -lpdcursesw -std=c++11

#include <conio.h>
#include <curses.h>
#include "Window.h"
#include "Snake.h"
#include "UI.h"
#include "Growth.h"
#include "Poison.h"

#define Delay 200

int main(int argc, char *argv[])                                                
{                                                                                        
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);
    
    attron(COLOR_PAIR(1));
    Window map(Height, Width, 0, 0);
    map.display_win();
    attroff(COLOR_PAIR(1));

    UI ui(Height, 30, 0, Width - 1);
    ui.display_win();

    Snake snake;

    char ch;
    int delay = 0;

    Growth_item g;
    Poison_item p;

    while(true) {
        if (!snake.is_valid_pos()) {
                mvprintw(Height / 2 - 1, Width / 2 - 5, "Game Over!");
                mvprintw(Height / 2, Width / 2 - 7, "Press Any Key");
                break;
            }
        if (kbhit()) {
            ch = getch();

            if (ch == 'q') {
                break;
            }
            try{
                snake.move_snake(ch);
            }
            catch(char x){
                mvprintw(Height / 2 - 1, Width / 2 - 5, "Game Over!");
                mvprintw(Height / 2, Width / 2 - 7, "Press Any Key");
                break;
            }
        }
        else{
            ch = snake.dir_head;
            snake.move_snake(ch);
        }
        
        delay_output(Delay);
        delay += Delay;
        if (delay >= 5000) {
            delay = 0;
            p.delete_poison_item();
            g.delete_growth_item();
            p.create_poison_item();
            g.create_growth_item();
        }
        if (snake.is_grow(g)) snake.grow();
        if (snake.is_lose(p)) {
            try{snake.lose();}
            catch(char x){
                mvprintw(Height / 2 - 1, Width / 2 - 5, "Game Over!");
                mvprintw(Height / 2, Width / 2 - 7, "Press Any Key");
                break;
            }
        }

        ui.update_UI(snake);
    }

    getch();
    endwin();                                 
}