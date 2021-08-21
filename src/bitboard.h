#ifndef BITBOARD_H
#define BITBOARD_H
#include "definitions.h"
#include<iostream>





class Bitboard{
    private:
    unsigned long long bitboards[12];
    std::string board;

    public:
    Bitboard();
    void init_bitboard();
    void print_board();
    void set_board();
};


#endif