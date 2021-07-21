#include "Board.h"
#include "Constants.h"
#include "Piece.h"
using namespace fig;


void Board::init_board(){
    square.setSize(sf::Vector2f(squareSize, squareSize));
    int8_t temp[8][8] = {
{bROCK,bKNIGHT,bBISHOP,bQUEEN,bKING,bBISHOP,bKNIGHT,bROCK},
{bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN},
{wROCK,wKNIGHT,wBISHOP,wQUEEN,wKING,wBISHOP,wKING,wROCK},
};
for (size_t i = 0; i < 8; i++)
{
    for (size_t j = 0; j < 8; j++)
    {
       this->board[i][j] = temp[i][j];
    }
    
}
}

void Board::load_textures(){
    t[0].loadFromFile("assets/bK.png");
    t[1].loadFromFile("assets/bQ.png");
    t[2].loadFromFile("assets/bR.png"); 
    t[3].loadFromFile("assets/bB.png");
    t[4].loadFromFile("assets/bN.png"); 
    t[5].loadFromFile("assets/bP.png"); 
    t[6].loadFromFile("assets/wK.png"); 
    t[7].loadFromFile("assets/wQ.png");
    t[8].loadFromFile("assets/wR.png");
    t[9].loadFromFile("assets/wB.png");
    t[10].loadFromFile("assets/wN.png");
    t[11].loadFromFile("assets/wP.png");
}

void Board::load_figures(Piece piece[]){
    int cnt = 0;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            int n = this->board[i][j];
            if(n==0){continue;}
            if (n == bKING)
            {
                piece[cnt].set_figure(t[0]);
                piece[cnt].set_color(Color::BLACK);
            }
            else if (n == bQUEEN)
            {
                piece[cnt].set_figure(t[1]);
                piece[cnt].set_color(Color::BLACK);
            }
            else if (n == bROCK)
            {
                piece[cnt].set_figure(t[2]);
                piece[cnt].set_color(Color::BLACK);
            }
            else if (n == bBISHOP)
            {
               piece[cnt].set_figure(t[3]);
               piece[cnt].set_color(Color::BLACK);
            }
            else if (n == bKNIGHT)
            {
                piece[cnt].set_figure(t[4]);
                piece[cnt].set_color(Color::BLACK);
            }
            else if (n == bPAWN)
            {
                piece[cnt].set_figure(t[5]);
                piece[cnt].set_color(Color::BLACK);
            }
            else if (n == wKING)
            {
                piece[cnt].set_figure(t[6]);
                piece[cnt].set_color(Color::WHITE);
            }
            else if (n == wQUEEN)
            {
                piece[cnt].set_figure(t[7]);
                piece[cnt].set_color(Color::WHITE);
            }
            else if (n == wROCK)
            {
               piece[cnt].set_figure(t[8]);
               piece[cnt].set_color(Color::WHITE);
            }
            else if (n == wBISHOP)
            {
                piece[cnt].set_figure(t[9]);
                piece[cnt].set_color(Color::WHITE);
            }
            else if (n == wKNIGHT)
            {
                piece[cnt].set_figure(t[10]);
                piece[cnt].set_color(Color::WHITE);
            }
            else if (n == wPAWN)
            {
                piece[cnt].set_figure(t[11]);
                piece[cnt].set_color(Color::WHITE);
            }
            piece[cnt].set_position(i,j);
            piece[cnt].set_value(n);
            cnt++;
        }
        
    }
    
}
int Board::get_size(){
    return squareSize;
}
void Board::draw_board(sf::RenderWindow &window){
    for (size_t j = 0; j < 8; j++)
        {
            for(int i=0; i<8; i++){
            square.setPosition(squareSize*i,squareSize*j);
            if(j%2==0){i%2==0?square.setFillColor(col1):square.setFillColor(col2);}
            else {i%2==0?square.setFillColor(col2):square.setFillColor(col1);}
            window.draw(square);
        }
        }
}
void Board::draw_pieces(Piece pieces[], sf::RenderWindow &window){
            for (size_t i = 0; i < 32; i++)
        {
            window.draw(pieces[i].figure);
        }
}

int8_t Board::get_piece(const Position &square){
    if (square.kind==Position::Kind::SQUARE && square.x<8 && square.y <8)
    {
       return board[square.y][square.x];
    }else 
    {
        std::cout << " Get_piece only takes a square \n";
    }
    
    
}
