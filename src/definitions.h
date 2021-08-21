#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>

#define set_bit(bitboard, square) ((bitboard) |= (1ULL << (square)))
#define get_bit(bitboard, square) ((bitboard) & (1ULL << (square)))
#define pop_bit(bitboard, square) ((bitboard) &= ~(1ULL << (square)))


namespace Constants{
    constexpr const char* BINARY64 =   "0000000000000000000000000000000000000000000000000000000000000000";
    constexpr const char* CHESSBOARD = "rnbqkbnrpppppppp00000000000000000000000000000000PPPPPPPPRNBQKBNR";
    constexpr const char* PIECES = "pnbrqkPNBRQK";
    
    // Bitboard values at the beginning of the game for the default positions (Obtained from the function bitb init_boards)
};

#endif