#include "Board.h"
#include "Constants.h"
using namespace fig;

void Board::load_textures()
{
    int cnt = 0;
    std::string labels[12] = {"bK", "bQ", "bN", "bB", "bN", "wP", "wK", "wQ", "wN", "wB", "wN", "wP"};
    std::string ext = ".png";
    for (auto &label : labels)
    {
        label = label + ext;
    }
    for (auto &t : T)
    {
        t.loadFromFile(labels[cnt]);
        cnt++;
    }
}

void Board::load_figures()
{
    int cnt = 0;
    for (size_t row = 0; row < 8; row++)
    {
        for (size_t col = 0; col < 8; col++)
        {
            int fig = this->board(row, col);
            if (fig == 0)
            {
                continue;
            }
            if (fig == bKING)
            {
                pieces[cnt].setTexture(T[0]);
            }
            else if (fig == bQUEEN)
            {
                pieces[cnt].setTexture(T[1]);
            }
            else if (fig == bROCK)
            {
                pieces[cnt].setTexture(T[2]);
            }
            else if (fig == bBISHOP)
            {
                pieces[cnt].setTexture(T[3]);
            }
            else if (fig == bKNIGHT)
            {
                pieces[cnt].setTexture(T[4]);
            }
            else if (fig == bPAWN)
            {
                pieces[cnt].setTexture(T[5]);
            }
            else if (fig == wKING)
            {
                pieces[cnt].setTexture(T[6]);
            }
            else if (fig == wQUEEN)
            {
                pieces[cnt].setTexture(T[7]);
            }
            else if (fig == wROCK)
            {
                pieces[cnt].setTexture(T[8]);
            }
            else if (fig == wBISHOP)
            {
                pieces[cnt].setTexture(T[9]);
            }
            else if (fig == wKNIGHT)
            {
                pieces[cnt].setTexture(T[10]);
            }
            else if (fig == wPAWN)
            {
                pieces[cnt].setTexture(T[11]);
            }
            pieces[cnt].setPosition(row, col);
            cnt++;
        }
    }
}

void Board::draw_board(sf::RenderWindow &window)
{
    for (size_t row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            squares[row][col].setSize(sf::Vector2f(sq_sz, sq_sz));
            squares[row][col].setPosition(sq_sz * row, sq_sz * col);
            if (col % 2 == 0)
            {
                row % 2 == 0 ? squares[row][col].setFillColor(sq_col2) : squares[row][col].setFillColor(sq_col1);
            }
            else
            {
                row % 2 == 0 ? squares[row][col].setFillColor(sq_col1) : squares[row][col].setFillColor(sq_col2);
            }
            window.draw(squares[row][col]);
        }
    }
}

void Board::draw_pieces(sf::RenderWindow &window)
{
    for (size_t i = 0; i < 32; i++)
    {
        window.draw(pieces[i]);
    }
}

/*

int Board::get_size(){
    return squareSize;
}


Board::Board(){
    init_board();
    load_textures();
    load_figures();
}

void Board::place_piece(Position pos){
    this->pieces[cpi].figure.setPosition(pos.coord.x,pos.coord.y);
}
void Board::move_piece(int x, int y){
    this->pieces[cpi].figure.setPosition(x,y);
}
bool Board::is_piece_pressed(sf::Vector2i mouse_pos){
    for (size_t i = 0; i < 32; i++)
    {
        if(pieces[i].figure.getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
            this->cpi = i;
            //std::cout << "TRUE! \n";
            return true;
        }
        
    }
    return false;
    
}
std::string Board::square_notation(const Position &sq){

    return (static_cast<char>('A' + abs(7 - sq.y)) + std::to_string(sq.x + 1));

}
void Board::update_board(Position from, Position to){
    this->board[to.y][to.x] = board[from.y][from.x];
    this->board[from.y][from.x] = fig::emptySquare;
    std::cout<<"Board updated: " << square_notation(from) << " is now: Empty and " << square_notation(to) << " is now: "<<static_cast<int16_t> (board[to.y][to.x]) << "\n";
}

void Board::remove_piece(Position to){
    for (size_t i = 0; i < 32; i++)
    {
        if(pieces[i].figure.getGlobalBounds().left == to.coord.x && pieces[i].figure.getGlobalBounds().top == to.coord.y){
            pieces[i].figure.setPosition(900,900);
        }
    }
    
}
*/