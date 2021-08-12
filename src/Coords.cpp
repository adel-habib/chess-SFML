#include "Coords.h"


Coords::Coords(){
    this->row = 0;
    this->col = 0;
}

Coords::Coords(int x, int y){
    this->col = x;
    this->row = y;
}
string Coords::algebraic_notation()
{
    return static_cast<char>('a' + this->row) + std::to_string(this->col + 1);
}

int Coords::index()
{
    return 8 * this->row + this->col;
}
int Coords::index(int rowadd, int coladd)
{
    return 8 * ((this->row) + rowadd) + (this->col) + coladd;
}

Coords Coords::index_to_coords(int ind)
{
    Coords C;
    C.col = ind % 8;
    C.row = round(ind / 8);
    return C;
}

 short int Coords::get_row()
{
    return this->row;
}

 short int Coords::get_col()
{
    return this->col;
}

Coords &Coords::operator=(sf::Vector2i mousepos)
{
    this->col = round(mousepos.x / 100);
    this->row = round(mousepos.y / 100);
    return *this;
}

ostream &operator<<(ostream &out, const Coords &c)
{
    out << "(" << c.row << "," << c.col << ") \n";
    return out;
}

bool Coords::operator==(const Coords &c) const
{
    if (this->row == c.row && this->col == c.col)
    {
        return true;
    }
    else
        return false;
}
void Coords::set_row( int row){
    this->row = row;
}
void Coords::set_col(int col){
    this->col = col;
}
Coords Coords::operator-(const Coords &c) const{
     Coords ncoords;
     ncoords.set_col(this->col - c.col);
     ncoords.set_row(this->row - c.row);
     cout << ncoords;
     return ncoords;
}
