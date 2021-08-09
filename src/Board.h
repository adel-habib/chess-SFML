#ifndef BOARD_H
#define BOARD_H
#include "Coords.h"
#include<iostream>

class Board{
    private:
    char board[64];
    Coords from;
    Coords to;
    Coords bking_pos, wking_pos;
    public: 
    void init_board();
    void move_piece();
    char operator[](int);

};

#endif