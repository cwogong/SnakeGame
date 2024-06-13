#ifndef WINDOW_H
#define WINDOW_H
#include <curses.h>

#define Height 20
#define Width 50

class Window {
protected:
    int height;
    int width;
    int y;
    int x;
    WINDOW* win;
public:
    Window(int h, int w, int y, int x);
    void display_win();
    void clear_win();
};



#endif