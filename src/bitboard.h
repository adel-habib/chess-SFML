#ifndef BITBOARD_H
#define BITBOARD_H
#include "definitions.h"
#include<iostream>
 std::string chessboard = "rnbqkbnrpppppppp00000000000000000000000000000000RNBQKNRPPPPPPPP";
 std::string pieces = "pnbrqkPNBRQK";
 
class Bitboard{
    private:
    unsigned long long bitboards[12];

    public:
    Bitboard();
    void init_bitboard();
};


#endif