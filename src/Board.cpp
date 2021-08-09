#include "Board.h"

void Board::init_board()
{
    int cnt = 0;
    //char pieces[16] = {'r','n','b','q','k','b','n','r','p','p','p','p','p','p','p','p'};
    std::string pieces = "rnbqkbnrpppppppp";

    for (int i = 0; i < 16; i++)
    {
        this->board[i] = pieces[i];
    }
    for (int i = 16; i < 48; i++)
    {
        this->board[i] = 'e';
    }
    for (int i = 56; i < 64; i++)
    {
        this->board[i] = pieces[cnt] - 32;
        cnt++;
    }
    for (int i = 48; i < 56; i++)
    {
        board[i] = pieces[cnt] - 32;
        cnt++;
    }
}

void Board::move_piece()
{
    board[to.index()] = board[from.index()];
    board[from.index()] = 'e';
}

char Board::operator[](int index)
{
    return board[index];
}