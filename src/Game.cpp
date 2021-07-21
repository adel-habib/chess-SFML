#include "Game.h"

// Operator overloading 

Turn &operator++(Turn &T){
    switch (T)
    {
    case Turn::BLACK: return T = Turn::WHITE;
    case Turn::WHITE: return T = Turn::BLACK;
    }
}



// Constructors 

Game::Game():turn(Turn::WHITE), isMoving(false), current_piece(0),currentFigureIndex(0),target_piece(0){}




// Setters: 

void Game::set_current_piece(const int8_t (&board)[8][8]){
    this->current_piece = board[this->square_from.y][this->square_from.x];
    this->current_piece > 0? this->current_piece_color=Turn::BLACK : this->current_piece_color=Turn::WHITE;
}
void Game::set_current_coords(const sf::Vector2i &mouse_pos){
    this->square_from.x = round(mouse_pos.x/100);
    this->square_from.y = round(mouse_pos.y/100);

    this->coord_from = square_from * 100;

}

void Game::set_target_coords(const sf::Vector2i &mouse_pos){
    // keep the piece in bounds of the boards 
    if(mouse_pos.x/100<0){square_to.x=0;}
    else if(mouse_pos.x/100 > 7){square_to.x=7;}
    else{this->square_to.x = round(mouse_pos.x/100);}

    if(mouse_pos.y/100<0){square_to.y=0;}
    else if(mouse_pos.y/100 > 7){square_to.y=7;}
    else{this->square_to.y = round(mouse_pos.y/100);}

    this->coord_to = square_to * 100;

}

void Game::set_current_figure(uint8_t i){
        this->currentFigureIndex = i;
}

void Game::set_movement(bool movement){
    this->isMoving = movement;
}

void Game::set_offset(int x, int y){
    this->offset.x =  x - coord_from.x;
    this->offset.y = y - coord_from.y;
}




// Getters 

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


Position Game::get_offset(){
    return this->offset;
}

bool Game::get_is_moving(){
    return this->isMoving;
}
void Game::toggle_turn(){
    ++this->turn;
}

Turn Game::get_turn(){
    return this->turn;
}


void Game::getTurn(){
    if(this->turn==Turn::BLACK){
        std::cout << "Turn: Black \n";
    }
    else{
        std::cout << "Turn: White \n";
    }
}


Turn Game::get_current_piece_color(){
    return this->current_piece_color;
}




// Functionality 

std::string Game::coord_to_notation(){
    std::string fromm = static_cast<char>('a' + abs(7-square_from.y)) + std::to_string(square_from.x+1);
    std::string too = static_cast<char>('a' + abs(7-square_to.y)) + std::to_string(square_to.x+1);
    this->moves.push((fromm+too));
    std::cout << "Move: " << fromm + too << "\n";
    return fromm + too ;
}

void Game::validate_turn(){
    this->turn == this->current_piece_color? this->isMoving = true : this->isMoving=false;
}


