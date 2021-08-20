#include "definitions.h"
//#include "bitboard.h"
#include<iostream>
#include<math.h>
using namespace std;

string binary = "0000000000000000000000000000000000000000000000000000000000000000";

class Bitboard{
    private:
    unsigned long long bitboards[12];

    public:
    static string binary;
    Bitboard();
    void init_bitboard();
};

Bitboard::Bitboard()  {
    for (auto &board : bitboards)
    {
        board = 0ULL;
    }
}

void Bitboard::init_bitboard(){
    string temp = binary;
    for (size_t p = 0; p < 12; p++)
    {
    
    for (size_t i = 0; i < 64; i++)
    {
        if(chessboard[i] == pieces[p]){
            set_bit(this->bitboards[p],i);
            temp[63-i] = '1';
        }
    }
    std::cout << pieces[p] << " : " << bitboards[p] << "\n";
    std::cout << temp << endl << endl;
    temp = binary;
    }

}



void init_pawns(unsigned long long &board, string &binary){
    for (size_t i = 0; i < binary.length(); i++)
    {
        if(chessboard[i]=='P'){
            set_bit(board,i);
            binary[63-i] = '1';
        }
    }
}

int main(){
    Bitboard boards;
    boards.init_bitboard();
    
    
}