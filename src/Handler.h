#ifndef HANDLER_H
#define HANDLER_H
#include <iostream>
#include "Position.h"
#include <SFML/Graphics.hpp>
#include "Constants.h"
enum class Colour
{
    BLACK,
    WHITE,
    EMPTY
};

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
    bool isValidTurn;
    bool isLegalMove;
    bool isPawnForward;
    bool isBlocked;
    int8_t dy;
    int8_t dx;


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


};

#endif