#ifndef POISON_H
#define POISON_H

#include <stdlib.h>
#include <time.h>
#include "Window.h"

class Poison_item{
    int y;
    int x;
public:
    Poison_item();
    void create_poison_item();
    void delete_poison_item();
    int get_y();
    int get_x();
};

#endif