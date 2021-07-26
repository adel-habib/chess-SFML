#include "Board.h"
#include "Constants.h"
#include "Piece.h"
using namespace fig;


void Board::init_board(){
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

void Board::load_figures(){
    int cnt = 0;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            int n = this->board[i][j];
            if(n==0){continue;}
            if (n == bKING)
            {
                pieces[cnt].set_figure(t[0]);
                pieces[cnt].set_color(Color::BLACK);
            }
            else if (n == bQUEEN)
            {
                pieces[cnt].set_figure(t[1]);
                pieces[cnt].set_color(Color::BLACK);
            }
            else if (n == bROCK)
            {
                pieces[cnt].set_figure(t[2]);
                pieces[cnt].set_color(Color::BLACK);
            }
            else if (n == bBISHOP)
            {
               pieces[cnt].set_figure(t[3]);
               pieces[cnt].set_color(Color::BLACK);
            }
            else if (n == bKNIGHT)
            {
                pieces[cnt].set_figure(t[4]);
                pieces[cnt].set_color(Color::BLACK);
            }
            else if (n == bPAWN)
            {
                pieces[cnt].set_figure(t[5]);
                pieces[cnt].set_color(Color::BLACK);
            }
            else if (n == wKING)
            {
                pieces[cnt].set_figure(t[6]);
                pieces[cnt].set_color(Color::WHITE);
            }
            else if (n == wQUEEN)
            {
                pieces[cnt].set_figure(t[7]);
                pieces[cnt].set_color(Color::WHITE);
            }
            else if (n == wROCK)
            {
               pieces[cnt].set_figure(t[8]);
               pieces[cnt].set_color(Color::WHITE);
            }
            else if (n == wBISHOP)
            {
                pieces[cnt].set_figure(t[9]);
                pieces[cnt].set_color(Color::WHITE);
            }
            else if (n == wKNIGHT)
            {
                pieces[cnt].set_figure(t[10]);
                pieces[cnt].set_color(Color::WHITE);
            }
            else if (n == wPAWN)
            {
                pieces[cnt].set_figure(t[11]);
                pieces[cnt].set_color(Color::WHITE);
            }
            pieces[cnt].set_position(i,j);
            pieces[cnt].set_value(n);
            cnt++;
        }
        
    }
    
}
int Board::get_size(){
    return squareSize;
}
void Board::draw_board(sf::RenderWindow &window){
    for (size_t i = 0; i < 8; i++)
        {
            for(int j=0; j<8; j++){
            squares[i][j].setSize(sf::Vector2f(squareSize, squareSize));
            squares[i][j].setPosition(squareSize*i,squareSize*j);
            if(j%2==0){i%2==0?squares[i][j].setFillColor(sq_col2):squares[i][j].setFillColor(sq_col1);}
            else {i%2==0?squares[i][j].setFillColor(sq_col1):squares[i][j].setFillColor(sq_col2);}
            window.draw(squares[i][j]);
        }
        }
}
void Board::draw_pieces(sf::RenderWindow &window){
            for (size_t i = 0; i < 32; i++)
        {
            window.draw(pieces[i].figure);
        }
}

int8_t Board::get_piece(const Position &square){
    if (square.x>7 && square.y > 7)
    {
        std::invalid_argument("Get_piece only takes a square: INDEX \n");  
    }
    return board[square.y][square.x];
    
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