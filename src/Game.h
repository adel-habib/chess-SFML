#ifndef GAME_H
#define GAME_H
#include "Position.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Board.h"
#include <iostream>

class Game{
    private:
    int8_t current_piece, target_piece;
    int currentFigureIndex;
    Position square_from, square_to = Position(Position::Kind::SQUARE);
    Position coord_from, coord_to = Position(Position::Kind::COORD);
    bool isMoving;

    public:
    void set_current_piece(const int8_t (&board)[8][8]);
    void set_target_piece(const int8_t (&board)[8][8]);
    int get_current_piece();
    void set_current_coords(const sf::Vector2i &mouse_pos);
    Position get_current_coords();
    void set_target_coords(const sf::Vector2i &mouse_pos);
    Position get_target_coords();
    void set_current_figure(uint8_t i);
    int get_current_figure_index();
    void set_movement(bool movement);
    bool get_is_moving();

};


#endif