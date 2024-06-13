#include "Poison.h"

Poison_item::Poison_item(){}

void Poison_item::create_poison_item(){
    srand(time(NULL));
    y = (rand() % (Height - 2)) / 2 * 2 + 1;
    x = (rand() % (Width - 2)) / 2 * 2 + 1;
    mvprintw(y, x, "P");
}

void Poison_item::delete_poison_item() {
    mvprintw(y, x, " ");
}

int Poison_item::get_y() {
    return y;
}

int Poison_item::get_x() {
    return x;
}