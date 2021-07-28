#include "Index.h"

Index::Index() : row(0), column(0), s_max(7) { set_coords(); }

Index::Index(size_t x, size_t y) : s_max(7)
{
    this->row = x;
    this->column = y;
    set_coords();
}

Index &Index::operator+(Index other)
{
    this->row += other.row;
    this->column += other.column;
    set_coords();
    return *this;
}

// Doagonal increment -- board(1,1)++ => board (2,2)
Index &Index::operator++()
{
    if (this->column == s_max || this->row == s_max)
    {
        std::cout << "Maximum bound reached \n";
        return *this;
    }
    this->row += 1;
    this->column += 1;
    set_coords();
    return *this;
}
// Doagonal Decrement -- board(2,2)++ => board (1,1)
Index &Index::operator--()
{
    if (this->column == 0 || this->row == 0)
    {
        std::cout << "Minimum bound reached \n";
        return *this;
    }
    this->row -= 1;
    this->column -= 1;
    set_coords();
    return *this;
}

Index &Index::operator-(Index other)
{
    this->row -= other.row;
    this->column -= other.column;
    set_coords();
    return *this;
}

Index &Index::operator=(Index other)
{
    this->row = other.row;
    this->column = other.column;
    set_coords();
    return *this;
}
void Index::increment_row()
{
    if (this->row < s_max)
    {
        this->row++;
    }
}
void Index::decrement_row()
{
    if (this->row > 0)
    {
        this->row--;
    }
}

void Index::increment_col(){
    if(this->column < s_max){
        this->column++;
    }
}
void Index::decrement_col(){
    if(this->column < 0){
        this->column--;
    }
}

void Index::set_coords()
{
    this->coord.x = this->column * 100;
    this->coord.y = this->row * 100;
}
std::string Index::to_chess_notation()
{
    return static_cast<char>('a' + abs(7 - this->row)) + std::to_string(this->column + 1);
}