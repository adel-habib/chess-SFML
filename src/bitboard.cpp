#include "bitboard.h"


Bitboard::Bitboard()  {
    for (auto &board : bitboards)
    {
        board = 0ULL;
    }
}

void Bitboard::init_bitboard(){
    std::cout << "Initialising bitboards for pieces and default positions: \n \n"; 
    std::string temp = Constants::BINARY64;
    for (size_t p = 0; p < 12; p++)
    {
    
    for (size_t i = 0; i < 64; i++)
    {
        if(Constants::CHESSBOARD[i] == Constants::PIECES[p]){
            set_bit(this->bitboards[p],i);
            temp[63-i] = '1';
        }
    }
    std::cout << "Piece: " <<Constants::PIECES[p] << ", Decimal value: " << bitboards[p] << "\n";
    std::cout << "Binary repres. : " << temp << std::endl << std::endl;
    temp = Constants::BINARY64;
    }
    std::cout << std::string(64,'-') << "\n \n";
}


void Bitboard::set_board(){
    this->board = Constants::BINARY64;
    
    for (size_t piece = 0; piece < 12; piece++)
    {
        for (size_t square = 0; square < 64; square++)
        {
            if(get_bit(bitboards[piece],square)){
                board[63-square] = Constants::PIECES[piece];
            }
        }
        
    }
    
    
}

void Bitboard::print_board(){
    int index;
    for (size_t rank = 0; rank < 8; rank++)
    {
        
        for (size_t file = 0; file < 8; file++)
        {
            
            index = 8*rank + file;
            if(!file) std::cout<< "\n"<< 8 - rank << std::string(3,' ');
            std::cout << " " << board[index] << " ";
            
        }
        
    }
    std::cout <<"\n \n" <<std::string(3,' ');
    std::string files = "abcdefgh";
    for(auto file : files){
        std::cout << std::string(2,' ') << file;
    }
    printf("\n");
}
