#ifndef UI_H
#define UI_H

#include "Window.h"
#include "Snake.h"

class UI : public Window{
public:
    UI(int h, int w, int y, int x);
    void display_win();
    void update_UI(Snake snake);
};


#endif