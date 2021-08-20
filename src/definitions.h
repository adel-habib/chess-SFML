#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>

#define set_bit(bitboard, square) ((bitboard) |= (1ULL << (square)))
#define get_bit(bitboard, square) ((bitboard) & (1ULL << (square)))
#define pop_bit(bitboard, square) ((bitboard) &= ~(1ULL << (square)))

//enum class bitboardmap {wp, wn, wb, wr, wq, wk, bp, bn, bb, br, bq, bk};

 std::string chessboard = "rnbqkbnrpppppppp00000000000000000000000000000000RNBQKNRPPPPPPPP";
 std::string pieces = "pnbrqkPNBRQK";

#endif