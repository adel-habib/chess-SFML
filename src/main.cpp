#include "bitboard.h"
#include<iostream>
#include<math.h>
using namespace std;

//std::string chessboard = "rnbqkbnrpppppppp00000000000000000000000000000000RNBQKNRPPPPPPPP";
//std::string pieces = "pnbrqkPNBRQK";
//std::string binary = "0000000000000000000000000000000000000000000000000000000000000000";


int main(){
    Bitboard boards;
    boards.init_bitboard();
    boards.set_board();
    boards.print_board();
}