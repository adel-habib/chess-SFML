#ifndef COORDS_H
#define COORDS_H
#include<iostream>
#include<math.h>
#include<SFML/Graphics.hpp>
using namespace std;

class Coords{
    private:
     short int row; // Rank 
     short int col; // File

    public:
    Coords();
    Coords(int x, int y);
    int index();
    int index(int row_inc, int col_inc);
    // maps the index of a piece on the board (char board[64]) to a Coords of row and col 
    Coords index_to_coords (int ind);
    Coords &operator=(sf::Vector2i mousepos);
    Coords operator-(const Coords &c) const; 
    // Maps coords to chess notation i.e a1a3 
    string algebraic_notation();
     short int get_row();
     short int get_col();
    friend ostream & operator << (ostream &out, const Coords &c);
    bool operator==(const Coords &c) const;
    void set_row(int);
    void set_col(int);
    sf::Vector2i pos();


    

};
#endif