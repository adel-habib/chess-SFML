#include "Piece.h"

void Piece::set_color(const Color &col){
    this->color = col;
}

void Piece::set_figure(const sf::Texture &t){
    this->figure.setTexture(t);
}

void Piece::set_value(const int8_t &val){
    this->vlaue = val;
}

void Piece::set_position(int i, int j){
    this->figure.setPosition(100*j,100*i);
}

sf::Sprite Piece::get_figure(){
    return this->figure;
}
