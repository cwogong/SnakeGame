#include "Growth.h"

Growth_item::Growth_item(){}

void Growth_item::create_growth_item(){
    srand(time(NULL) + 1);
    y = (rand() % (Height - 2)) / 2 * 2 + 1;
    x = (rand() % (Width - 2)) / 2 * 2 + 1;
    mvprintw(y, x, "G");
}

void Growth_item::delete_growth_item() {
    mvprintw(y, x, " ");
}

int Growth_item::get_y() {
    return y;
}

int Growth_item::get_x() {
    return x;
}