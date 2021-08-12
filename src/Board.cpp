#include "Board.h"

void Board::init_board()
{
    int cnt = 0;
    //char pieces[16] = {'r','n','b','q','k','b','n','r','p','p','p','p','p','p','p','p'};
    string pieces = "rnbqkbnrpppppppp";

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

void Board::move_piece(Coords from, Coords to)
{
    board[to.index()] = board[from.index()];
    board[from.index()] = 'e';
}

char Board::operator[](int index)
{
    return board[index];
}

bool Board::is_enemy(int from, int to)
{
    if (board[to] == 'e')
    {
        return false;
    }
    bool x = isupper(board[from]);
    bool y = isupper(board[to]);
    return x != y;
}

void Board::pawn(Coords from)
{
    // Movement direction and original position
    int row_inc, rowref;
    isupper(board[from.index()]) ? row_inc = -1 : row_inc = 1;
    row_inc == 1 ? rowref = 1 : rowref = 6;

    // Forward movement
    if (is_empty(from.index(row_inc, 0)))
    {
        validmoves.push_back(from.index(row_inc, 0));
        // Doppel forward movement
        if (board[from.get_row() == rowref] && is_empty(from.index(2*row_inc, 0)))
        {
            validmoves.push_back(from.index(2 * row_inc, 0));
        }
    }
    // Right capturing
    if (is_enemy(from.index(), from.index(row_inc, 1)))
    {
        validmoves.push_back(from.index(row_inc, 1));
    }
    // Left capturing
    if (is_enemy(from.index(), from.index(row_inc, -1)))
    {
        validmoves.push_back(from.index(row_inc, 1));
    }
}

bool Board::is_empty(int ind)
{
    return board[ind] == 'e';
}

vector<int> Board::get_validmoves(){
    return validmoves;
}