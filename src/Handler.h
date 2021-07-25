#ifndef HANDLER_H
#define HANDLER_H
#include <iostream>
#include "Position.h"
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include"Direction.h"


enum class Colour
{
    BLACK,
    WHITE,
    EMPTY
};

/**
 * Implementation of  window events handler 
 *
 * It handels user events such as dragging and dropping pieces, keyboard events etc
 * Calculates the coordinates and converts them to board indeces 
 * initial validation of correct turn and correct placement of pieces 
 * It doesn't validate the legality of the move in terms of chess logic 
 * 
 */


class Handler
{
private:
    Colour turn;
    Position from;
    Position mouse_pos;
    Position offset;
    int8_t cPiece;
    int8_t tPiece;
    Colour cpColor;
    Colour tpColor;
    bool isMoving;
    bool validTurn;
    bool validPlacement;
    bool pawnForward;
    bool isBlocked;
    int8_t dy;
    int8_t dx;
    Direction direction;


public:
    Position to;
    Handler();
    void handle_mousePress(sf::Vector2i mouse_pos, const int8_t (&board)[8][8]);
    void handle_mouse_release(sf::Vector2i mouse_pos, const int8_t (&board)[8][8]);
    Colour get_color(const int8_t &piece);
    void validate_turn();
    bool is_valid_turn();
    Position get_offset();
    Position get_target_coords();
    void toggle_turn();
    void set_mouse_pos(sf::Vector2i mp);

    bool is_placed_on_enemy();
    bool is_placed_on_self();
    bool is_placed_on_empty_sq();
    bool is_placed_on_same_color();
    void handle_invalid_move();
    std::string to_chess_notation();
    void print_move();
    std::string print_piece(int8_t piece);
    Position get_from();
    Position get_to();
    int8_t get_fromy();
    int8_t get_cpiece();
    int8_t get_tpiece();
    int8_t get_dx();
    int8_t get_dy();
    void set_dragging();
    bool is_moving();
    void validate_placement(const int8_t(&board)[8][8]);
    void set_direction();
    Direction get_driection();

    bool is_valid_placement(){
        return this->validPlacement;
    }
    void is_jumping_piece(const int8_t (&board)[8][8]);

};


#endif