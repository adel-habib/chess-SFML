#include "Game.h"

void Game::set_current_piece(const int8_t (&board)[8][8]){
    this->current_piece = board[this->square_from.y][this->square_from.x];
}
void Game::set_current_coords(const sf::Vector2i &mouse_pos){
    this->square_from.x = round(mouse_pos.x/100);
    this->square_from.y = round(mouse_pos.y/100);
    this->coord_from = square_from * 100;

}

void Game::set_target_coords(const sf::Vector2i &mouse_pos){
    this->square_to.x = round(mouse_pos.x/100);
    this->square_to.y = round(mouse_pos.y/100);
    this->coord_to = square_to * 100;

}

void Game::set_current_figure(uint8_t i){
        this->currentFigureIndex = i;
}
int Game::get_current_piece(){
    return this->current_piece;
}
Position Game::get_current_coords(){
    return coord_from;
}
Position Game::get_target_coords(){
    return this->coord_to;
}

int Game::get_current_figure_index(){
    return currentFigureIndex;
}

void Game::set_movement(bool movement){
    this->isMoving = movement;
}
bool Game::get_is_moving(){
    return this->isMoving;
}