#include "Window.h"

Window::Window(int h, int w, int y, int x): height(h), width(w), y(y), x(x) {win = newwin(height, width, y, x);}
void Window::display_win(){                 // 윈도우 생성 함수
        box(win, 0, 0);
        wrefresh(win);
}