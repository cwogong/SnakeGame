#ifndef GROWTH_H
#define GROWTH_H

#include <stdlib.h>
#include <time.h>
#include "Window.h"

class Growth_item{
    int y;
    int x;
public:
    Growth_item();
    bool is_valid_pos();
    void create_growth_item();
    void delete_growth_item();
    int get_y();
    int get_x();
};

#endif