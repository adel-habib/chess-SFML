#ifndef INDEX_H
#define INDEX_H

#include <iostream>
struct Coords
{
    uint16_t x, y;
};

class Index
{
    private:
    const size_t s_max;

public:
    uint8_t row;
    uint8_t column;
    Coords coord;
    

    Index();
    Index(size_t x, size_t y);

    Index &operator+(Index other);

    // Doagonal increment -- board(1,1)++ => board (2,2)
    Index &operator++();
    // Doagonal Decrement -- board(2,2)++ => board (1,1)
    Index &operator--();

    Index &operator-(Index other);
    Index &operator=(Index other);
    void increment_row();
    void decrement_row();
    void increment_col();
    void decrement_col();
    void set_coords();
    std::string to_chess_notation();


};

#endif