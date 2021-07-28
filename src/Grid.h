#ifndef GRID_H
#define GRID_H

#include<iostream>
#include"Index.h"
const size_t sz = 8;

class Grid 
{
    private:
    int8_t board[sz][sz];

    public:
    size_t size() const {return sz*sz;}
    int8_t& operator() (size_t row, size_t col){
        return board[row][col];
    }
    int8_t& operator() (Index index){
        return board[index.row][index.column];
    }
    const int8_t& operator() (Index index) const {
        return board[index.row][index.column];
    }

    int8_t& operator[] (Index index){
        return board[index.row][index.column];
    }
    void destruct(Index index){
        this->board[index.row][index.column] = 0;
    }
    void move(Index from, Index to){
        board[to.row][to.column] = board[from.row][from.column];
        destruct(from);
    }
    

};

#endif
