#include "Grid.h"
Grid::Grid(){
    init_board();
}
size_t Grid::size() const { return sz * sz; }
int8_t &Grid::operator()(size_t row, size_t col)
{
    return board[row][col];
}
int8_t &Grid::operator()(const Index &index)
{
    return board[index.row][index.column];
}
const int8_t &Grid::operator()(const Index &index) const
{
    return board[index.row][index.column];
}

int8_t &Grid::operator[](const Index &index)
{
    return board[index.row][index.column];
}
void Grid::destruct(const Index &index)
{
    this->board[index.row][index.column] = 0;
}
void Grid::move(const Index &from, const Index &to)
{
    board[to.row][to.column] = board[from.row][from.column];
    destruct(from);
}

void Grid::init_board(){
    for (size_t row = 0; row < 8; row++)
    {
        for (size_t col = 0; col < 8; col++)
        {
            if(row>2 && row<6){board[row][col]=fig::emptySquare;}
            if(row==1){board[row][col]=fig::bPAWN;}
            if(row==6){board[row][col]=fig::wPAWN;}
            if(row==0 || row == 7){
                int n = 1;
                (row == 0) ? n=1 : n=-1;
                if(col==0|| col ==7){
                    board[row][col] = 3*n;
                }
                if(col==1|| col ==6){
                    board[row][col] = 5*n;
                }
                if(col==2|| col ==5){
                    board[row][col] = 4*n;
                }
                if(col==3){
                    board[row][col] = 2*n;
                }
                if(col==4){
                    board[row][col] = 1*n;
                }                                                         
            }
        }
        
    }
    
}
/*
void Grid::load_textures(){
    int cnt=0;
    std::string labels[12] = {"bK","bQ","bN","bB","bN","wP","wK","wQ","wN","wB","wN","wP" };
    std::string ext = ".png";
    for(auto &label : labels){
        label = label + ext;
    }
    for(auto & t: T){
        t.loadFromFile(labels[cnt]);
        cnt++;
    }
}
*/
