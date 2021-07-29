#ifndef BOARD_H
#define BOARD_H
#include "Constants.h"
#include "Position.h"
#include "Piece.h"
#include "Grid.h"


class Board{
    private:
    sf::Texture T[12];
    sf::Sprite pieces[32];
    sf::RectangleShape squares[8][8];
    Grid board;
    
    
    public:
    Board();
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

    const Grid &get_board(){
        return board;
    }
};

#endif