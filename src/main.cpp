/*
#include <math.h>
#include "Board.h"
#include "GUI.h"
*/
#include <iostream>
using namespace std;

// Macros Data type set get pop 
#define u64 unsigned long long
#define get_bit(bitboard, square) (bitboard & (1ULL << square))
#define set_bit(bitboard, square) (bitboard |= (1UL << square))
#define pop_bit(bitboard, square) (get_bit(bitboard,square) ? bitboard^=(1ULL << square) : 0)


// count bits within a bitboard (Brian Kernighan's way)
static inline int count_bits(u64 bitboard)
{
    // bit counter
    int count = 0;
    
    // consecutively reset least significant 1st bit
    while (bitboard)
    {
        // increment count
        count++;
        
        // reset least significant 1st bit
        bitboard &= bitboard - 1;
    }
    
    // return bit count
    return count;
}

// get least significant 1st bit index
static inline int get_ls1b_index(u64 bitboard)
{
    // make sure bitboard is not 0
    if (bitboard)
    {
        // count trailing bits before LS1B
        return count_bits((bitboard & -bitboard) - 1);
    }
    
    //otherwise
    else
        // return illegal index
        return -1;
}


// constants 
const u64 not_a_file = 18374403900871474942ULL;
const u64 not_h_file = 9187201950435737471ULL;
const u64 not_hg_file = 4557430888798830399UL;
const u64 not_ab_file = 18229723555195321596ULL;

const int bishop_relevant_bits[64] = {
    6, 5, 5, 5, 5, 5, 5, 6, 
    5, 5, 5, 5, 5, 5, 5, 5, 
    5, 5, 7, 7, 7, 7, 5, 5, 
    5, 5, 7, 9, 9, 7, 5, 5, 
    5, 5, 7, 9, 9, 7, 5, 5, 
    5, 5, 7, 7, 7, 7, 5, 5, 
    5, 5, 5, 5, 5, 5, 5, 5, 
    6, 5, 5, 5, 5, 5, 5, 6
};

// rook relevant occupancy bit count for every square on board
const int rook_relevant_bits[64] = {
    12, 11, 11, 11, 11, 11, 11, 12, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    12, 11, 11, 11, 11, 11, 11, 12
};

// print board
void print_bitboard(u64 bitboard)
{
    cout << "\n";
    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            if (!file)
                cout << (8 - rank) << "  ";
            // Convert file and rank into square index
            int square = 8 * rank + file;
            cout << (get_bit(bitboard, square) ? 1 : 0) << " ";
        }

        cout << endl;
    }
    cout << "\n   a b c d e f g h \n ";

    // print bitboard as unsigned long
    cout << "  Bitboard: " << bitboard << "\n";
}

// squares 
enum
{
    a8,b8,c8,d8,e8,f8,g8,h8,
    a7,b7,c7,d7,e7,f7,g7,h7,
    a6,b6,c6,d6,e6,f6,g6,h6,
    a5,b5,c5,d5,e5,f5,g5,h5,
    a4,b4,c4,d4,e4,f4,g4,h4,
    a3,b3,c3,d3,e3,f3,g3,h3,
    a2,b2,c2,d2,e2,f2,g2,h2,
    a1,b1,c1,d1,e1,f1,g1,h1,
};
enum {white, black};

// precaculated attacks 
u64 pawn_attacks[2][64];
u64 knight_attacks[64];
u64 bishop_attacks[64];
u64 king_attacks[64];





u64 mask_pawn_attacks(int side, int square){
    u64 attacks = 0ULL;
    u64 bitboard = 0ULL;
    set_bit(bitboard,square);
    // white pawns 
    if(!side){
        if( (bitboard >> 7) & not_a_file) attacks |=  ( bitboard >> 7) ;
        if( (bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);
    }
    // black pawns
    else{
        if( (bitboard << 7) & not_h_file) attacks |=  ( bitboard << 7) ;
        if( (bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
    }
    return attacks;
}

u64 mask_knight_attacks(int square){
    u64 attacks = 0ULL;
    u64 bitboard = 0ULL;

    set_bit(bitboard,square);

    if ((bitboard >> 17) & not_h_file) attacks |= (bitboard >> 17);
    if ((bitboard >> 15) & not_a_file) attacks |= (bitboard >> 15);
    if ((bitboard >> 10) & not_hg_file) attacks |= (bitboard >> 10);
    if ((bitboard >> 6) & not_ab_file) attacks |= (bitboard >> 6);

    if ((bitboard << 17) & not_a_file) attacks |= (bitboard << 17);
    if ((bitboard << 15) & not_h_file) attacks |= (bitboard << 15);
    if ((bitboard << 10) & not_ab_file) attacks |= (bitboard << 10);
    if ((bitboard << 6) & not_hg_file) attacks |= (bitboard << 6);

    return attacks;
}

u64 mask_king_attacks(int square){
    u64 attacks = 0ULL;
    u64 bitboard = 0ULL;
    set_bit(bitboard,square);

    if((bitboard<<1) & not_a_file) attacks |= (bitboard<<1);
    if((bitboard>>1) & not_h_file) attacks |= (bitboard>>1);
    if( (bitboard >> 7) & not_a_file) attacks |=  ( bitboard >> 7) ;
    if( (bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);
    if( (bitboard << 7) & not_h_file) attacks |=  ( bitboard << 7) ;
    if( (bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
    if((bitboard<<8)) attacks |= (bitboard<<8);
    if((bitboard>>8))attacks |= (bitboard>>8);

    return attacks;
}

u64 mask_bishop_attacks(int square){
    u64 attacks = 0ULL;
    u64 bitboard = 0ULL;
    set_bit(bitboard,square);

    int tr = square / 8;
    int tf = square % 8;
    int r, f;
    for (r=tr+1, f=tf+1; r<=6 && f<=6; r++, f++ ){
        attacks|=(1ULL<< (8*r + f));
    }
    for (r=tr+1, f=tf-1; r<=6 && f>0; r++, f-- ){
        attacks|=(1ULL<< (8*r + f));
    }
    for (r=tr-1, f=tf+1; r>0 && f<=6; r--, f++ ){
        attacks|=(1ULL<< (8*r + f));
    }
    for (r=tr-1, f=tf-1; r>0 && f>0; r--, f-- ){
        attacks|=(1ULL<< (8*r + f));
    }
    return attacks;

}

u64 mask_rock_attacks(int square){
    u64 attacks = 0ULL;
    u64 bitboard = 0ULL;
    set_bit(bitboard,square);

    int tr = square / 8;
    int tf = square % 8;
    int r, f;
    for (r=tr+1, f=tf; r<=6; r++) attacks|=(1ULL<< (8*r + f));
    for (r=tr-1, f=tf; r>0; r--)  attacks|=(1ULL<< (8*r + f));
    for (r=tr, f=tf+1; f<=6; f++) attacks|=(1ULL<< (8*r + f));
    for (r=tr, f=tf-1; f>0; f--)  attacks|=(1ULL<< (8*r + f));

    return attacks;
}
void init_pawn_attacks(){
    for (size_t square = 0; square < 64; square++)
    {
        pawn_attacks[white][square] = mask_pawn_attacks(white,square);
        pawn_attacks[black][square] = mask_pawn_attacks(black,square);
     }
    
}
void init_knight_attacks(){
    for (size_t square = 0; square < 64; square++)
    {
       knight_attacks[square] = mask_knight_attacks(square);
     }
    
}

void init_king_attacks(){
    for (size_t square = 0; square < 64; square++)
    {
       knight_attacks[square] = mask_king_attacks(square);
     }
    
}

void init_bishop_attacks(){
    for (size_t square = 0; square < 64; square++)
    {
       bishop_attacks[square] = mask_bishop_attacks(square);
     }
    
}


// generate bishop attacks on the fly
u64 bishop_attacks_on_the_fly(int square, u64 block)
{
    // result attacks bitboard
    u64 attacks = 0ULL;
    
    // init ranks & files
    int r, f;
    
    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;
    
    // generate bishop atacks
    for (r = tr + 1, f = tf + 1; r <= 7 && f <= 7; r++, f++)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block) break;
    }
    
    for (r = tr - 1, f = tf + 1; r >= 0 && f <= 7; r--, f++)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block) break;
    }
    
    for (r = tr + 1, f = tf - 1; r <= 7 && f >= 0; r++, f--)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block) break;
    }
    
    for (r = tr - 1, f = tf - 1; r >= 0 && f >= 0; r--, f--)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block) break;
    }
    
    // return attack map
    return attacks;
}

// generate rook attacks on the fly
u64 rook_attacks_on_the_fly(int square, u64 block)
{
    // result attacks bitboard
    u64 attacks = 0ULL;
    
    // init ranks & files
    int r, f;
    
    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;
    
    // generate rook attacks
    for (r = tr + 1; r <= 7; r++)
    {
        attacks |= (1ULL << (r * 8 + tf));
        if ((1ULL << (r * 8 + tf)) & block) break;
    }
    
    for (r = tr - 1; r >= 0; r--)
    {
        attacks |= (1ULL << (r * 8 + tf));
        if ((1ULL << (r * 8 + tf)) & block) break;
    }
    
    for (f = tf + 1; f <= 7; f++)
    {
        attacks |= (1ULL << (tr * 8 + f));
        if ((1ULL << (tr * 8 + f)) & block) break;
    }
    
    for (f = tf - 1; f >= 0; f--)
    {
        attacks |= (1ULL << (tr * 8 + f));
        if ((1ULL << (tr * 8 + f)) & block) break;
    }
    
    // return attack map
    return attacks;
}

// init leaper pieces attacks
void init_leapers_attacks()
{
    // loop over 64 board squares
    for (int square = 0; square < 64; square++)
    {
        // init pawn attacks
        pawn_attacks[white][square] = mask_pawn_attacks(white, square);
        pawn_attacks[black][square] = mask_pawn_attacks(black, square);
        
        // init knight attacks
        knight_attacks[square] = mask_knight_attacks(square);
        
        // init king attacks
        king_attacks[square] = mask_king_attacks(square);
    }
}


// set occupancies 
u64 set_occupancy(int index, int bits_in_mask, int u64 attack_mask){
    // occupancy map 
    u64 occupancy = 0ULL;
    for (size_t i = 0; i < bits_in_mask; i++)
    {
        int square = get_ls1b_index(attack_mask);
        pop_bit(attack_mask,square);
        if(index & (1<<i)) occupancy |= (1ULL << square);
    }
    




    return occupancy;
}

// random generator 
unsigned int state = 1804289383;
// generate 32-bit pseudo legal numbers 
unsigned int get_random_number(){
    // get current state 
    unsigned int number= state;
    // XOR SHIFT ALGORITHM 
    number ^= number <<13;
    number ^= number>> 17;
    number ^= number << 5;
    state = number;
    return number;

    }

int main()
{
    init_leapers_attacks();
    
}