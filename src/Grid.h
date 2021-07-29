#ifndef GRID_H
#define GRID_H
#include<iostream>
#include"Index.h"
#include"SFML/Graphics.hpp"
#include "Constants.h"
const size_t sz = 8;

class Grid 
{
    private:
    int8_t board[sz][sz];


    public:
    Grid();
    size_t size() const;
    int8_t &operator()(size_t row, size_t col);
    int8_t& operator() (const Index &index);
    const int8_t& operator() (const Index &index) const;
    int8_t& operator[] (const Index &index);
    void destruct(const Index &index);
    void move(const Index &from, const Index &to);

    void init_board();
    void load_textures();
    void set_textures();


    

};

#endif
