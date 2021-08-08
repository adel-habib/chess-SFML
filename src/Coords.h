#ifndef COORDS_H
#define COORDS_H
#include<iostream>
#include<math.h>

using namespace std;

class Coords{
    private:
    unsigned short int row; // Rank 
    unsigned short int col; // File

    public:

    int index();
    // maps the index of a piece on the board (char board[64]) to a Coords of row and col 
    Coords index_to_coords(int ind);
    // Maps coords to chess notation i.e a1a3 
    string algebraic_notation();
    


    

};
#endif