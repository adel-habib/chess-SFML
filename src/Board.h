#ifndef BOARD_H
#define BOARD_H
#include "Coords.h"
#include<iostream>
#include<vector>
class Board{
    private:
    char board[64];
    Coords bking_pos, wking_pos;
    vector<int> validmoves;

    public: 
    void pawn(Coords from);
    vector<int> get_validmoves();
    void init_board();
    bool is_enemy(int from, int to);
    bool is_empty(int ind);
    void move_piece(Coords from, Coords to);
    char operator[](int);

};

#endif