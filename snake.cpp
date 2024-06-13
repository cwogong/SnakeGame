#include "Snake.h"

Snake::Snake(): length(3), growth(0), poison(0) {
    snake[0][0] = Height / 2;               // head의 y좌표
    snake[0][1] = Width / 2;                // head의 x좌표
    snake[1][0] = snake[0][0];              // 나머지 2칸의 몸통 좌표
    snake[1][1] = snake[0][1] + 2;
    snake[2][0] = snake[0][0];
    snake[2][1] = snake[1][1] + 2;

    dir_head = 'a';                              // 처음 움직이는 방향 (a : left)

    draw_snake();
    refresh();
}

void Snake::draw_snake(){
    mvaddch(snake[0][0], snake[0][1], '@');
    for (int i = 1 ; i < length; i++) {
        mvaddch(snake[i][0], snake[i][1], 'O' );
    }
    refresh();
}

void Snake::clear_snake() {
    for (int i = 0 ; i < length; i++) {
        mvaddch(snake[i][0], snake[i][1], ' ' );

    }
    refresh();
}

bool Snake::is_valid_pos() {
    return !(snake[0][0] <= 0 || snake[0][0] >= Height - 1 || snake[0][1] <= 0 || snake[0][1] >= Width - 1);
}

void Snake::move_snake(char ch) {
    clear_snake();

    if (ch == 'w') {
        if (dir_head == 's') throw ch;
        for (int i = length; i > 0; i--) {
            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        snake[0][0]--;
    }
    if (ch == 'd') {
        if (dir_head == 'a') throw ch;
        for (int i = length; i > 0; i--) {
            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        snake[0][1] += 2;
    }
    if (ch == 's') {
        if (dir_head == 'w') throw ch;
        for (int i = length; i > 0; i--) {
            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        snake[0][0]++;
    }
    if (ch == 'a') {
        if (dir_head == 'd') throw ch;
        for (int i = length; i > 0; i--) {
            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        snake[0][1] -= 2;
    }

    draw_snake();
    dir_head = ch;
}

bool Snake::is_grow(Growth_item g) {
    int y = g.get_y();
    int x = g.get_x();
    return (snake[0][0] == y && snake[0][1] == x);
}

bool Snake::is_lose(Poison_item p) {
    int y = p.get_y();
    int x = p.get_x();
    return (snake[0][0] == y && snake[0][1] == x);
}

void Snake::grow() {
    length++;
    growth++;
}

void Snake::lose() {
    mvaddch(snake[length - 1][0], snake[length - 1][1], ' ');
    length--;
    poison++;
    if (length < 3){
        throw 'x';
    }
}
