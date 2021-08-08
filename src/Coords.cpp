#include"Coords.h"

string Coords::algebraic_notation(){
    return static_cast<char>('a' + this->row) + std::to_string(this->col + 1);
}

int Coords::index(){
    return 8*this->row + this->col; 
}

Coords Coords::index_to_coords(int ind){
    Coords C;
    C.col = ind%8;
    C.row = round(ind/8);
    return C;
}

