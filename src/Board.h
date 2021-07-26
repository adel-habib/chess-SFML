#ifndef BOARD_H
#define BOARD_H
#include "Constants.h"
#include "Position.h"
#include "Piece.h"


class Board{
    private:
    sf::Texture t[12];
    Piece pieces[32];
    sf::RectangleShape squares[8][8];
    int8_t board[8][8];
    int8_t cpi; 
    
    
    public:
    Board();
    void init_board();
    void load_textures();
    void load_figures();
    void draw_board(sf::RenderWindow &window);
    void draw_pieces(sf::RenderWindow &window);
    int get_size();
    int8_t get_piece(const Position &square);
    void place_piece(Position pos);
    void move_piece(int x, int y);
    bool is_piece_pressed(sf::Vector2i mouse_pos);
    int8_t get_cpi();
    std::string square_notation(const Position &sq);
    void update_board(Position from, Position to);
    void remove_piece(Position to);

    const int8_t (&get_board())[8][8]{
        return board;
    }
};

#endif