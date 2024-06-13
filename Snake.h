#ifndef SNAKE_H
#define SNAKE_H
#include <curses.h>
#include <vector>
#include "Growth.h"
#include "Poison.h"

class Snake{
public:
    int length;                                 // 몸 길이
    int tail;                                   // 꼬리의 index
    int snake[100][2] = {};                     // snake의 각 부분마다의 위치 저장 / [0][0], [0][1] : head의 y, x좌표
    char dir_head;                              // 현재 snake가 진행하고 있는 방향 ( w : up, a : left,  s : down, d : right)
    char dir_tail;                              // 꼬리가 진행하고 있는 방향
    int growth;
    int poison;

    Snake();                                    // 생성자
    bool is_grow(Growth_item g);                // growth 아이템을 먹었는지 확인하는 함수
    bool is_lose(Poison_item p);                // poison 아이템을 먹었는지 확인하는 함수
    void grow();                                // growth 아이템을 먹었을 때 실행하는 함수
    void lose();                                // poison 아이템을 먹었을 때 실행하는 함수
    void move_snake(char ch);                   // snake의 위치를 바꾸는 함수
    void draw_snake();                          // snake의 위치에 따라 화면에 출력하는 함수
    void clear_snake();                         // 출력된 snake를 없애는 함수
    bool is_valid_pos();                        // 현재 snake의 위치가 올바른 위치인지 확인하는 함수
};


#endif