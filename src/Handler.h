#ifndef HANDLER_H
#define HANDLER_H 
#include<iostream>
#include "Position.h"
#include <SFML/Graphics.hpp>

enum class Colour{BLACK, WHITE, EMPTY}; 


class Handler{
    private:
    Colour turn;
    Position from;
    
    Position offset;
    int8_t cPiece;
    int8_t tPiece;
    int8_t cfi;
    Colour cpColor;
    Colour tpColor;
    bool isMoving;
    bool isValidTurn;


    public: 
    Position to;
    Handler();
    void handle_mousePress(sf::Vector2i mouse_pos, const int8_t (&board)[8][8], int8_t CFI);
    void handle_mouse_release(sf::Vector2i mouse_pos, const int8_t (&board)[8][8]);

    void set_color();
    void set_from();
    void set_to();
    void set_offset();
    void set_cPiece();
    Colour get_color(const int8_t &piece);
    void validate_turn();
    bool is_valid_turn(){
        return isValidTurn;
    }
    int8_t get_cfi(){
        return cfi;
    }
    Position get_offset(){
        return this->offset;
    }
    Position get_target_coords(){
        return to;
    }
    void toggle_turn(){
        turn==Colour::WHITE?turn=Colour::BLACK : turn=Colour::WHITE;
    }



};






#endif