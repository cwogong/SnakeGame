#include "UI.h"
#include <curses.h>

UI::UI(int h, int w, int y, int x) : Window(h, w, y, x){}

void UI::display_win(){
    box(win, 0, 0);
    mvprintw(y + 1, x + 8, "<Score Board>");
    mvprintw(y + 3, x + 6, "Length    : 3 / 50");
    mvprintw(y + 5, x + 6, "Growth item : 0");
    mvprintw(y + 7, x + 6, "Poison item : 0");
    mvprintw(y + 9, x + 6, "Gate        : 0");
    wrefresh(win);
}

void UI::update_UI(Snake snake) {
    mvprintw(y + 1, x + 8, "<Score Board>");
    mvprintw(y + 3, x + 6, "Length    : %d / 50", snake.length);
    mvprintw(y + 5, x + 6, "Growth item : %d", snake.growth);
    mvprintw(y + 7, x + 6, "Poison item : %d", snake.poison);
    mvprintw(y + 9, x + 6, "Gate        : 0");
}