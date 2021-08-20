#include "bitboard.h"

Bitboard::Bitboard()  {
    for (auto &board : bitboards)
    {
        board = 0ULL;
    }
}

void Bitboard::init_bitboard(){

    for (size_t i = 0; i < 64; i++)
    {
        if(chessboard[i] == pieces[0]){
            set_bit(this->bitboards[0],i);
        }
    }
    std::cout << pieces[0] << " : " << bitboards[0] << "\n";
}