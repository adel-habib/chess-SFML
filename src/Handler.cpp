#include"Handler.h"



Handler::Handler(){
    this->turn = Colour::WHITE;
    this->cfi = 0;
    this->from = 0;
    this->to = 0;
    this->cPiece = 0 ;
    this->tPiece = 0;
}

Colour Handler::get_color(const int8_t &piece){
        if(piece>0){return Colour::BLACK;}
        else if (piece<0){return Colour::WHITE;}
        else{return Colour::EMPTY;}
    }

void Handler::handle_mousePress(sf::Vector2i mouse_pos, const int8_t (&board)[8][8], int8_t CFI){
        this->from.x = round(mouse_pos.x/100);
        this->from.y = round(mouse_pos.y/100);
        from.set_coords();
        offset.x = mouse_pos.x - from.coord.x;
        offset.y = mouse_pos.y - from.coord.y;
        this->cPiece = board[from.y][from.x];
        this->cfi = CFI;
        cpColor = get_color(cPiece);
    }
void Handler::validate_turn(){
    if(this->turn == this->cpColor){isValidTurn=true; }
    else
    { 
        isValidTurn = false;
    }
    if(isValidTurn){
        std::cout<<"Valid turn \n";
    }
    else
    {
        std::cout<<"inValid turn \n";
    }
    
    
}
void Handler::handle_mouse_release(sf::Vector2i mouse_pos, const int8_t (&board)[8][8]){
    this->to.x = round(mouse_pos.x/100);
    this->to.y = round(mouse_pos.y/100);
    to.set_coords();
    this->tPiece = board[to.y][to.x];
    cpColor = get_color(tPiece);
    if (this->isValidTurn){toggle_turn();}
    this->isValidTurn = false;

}

