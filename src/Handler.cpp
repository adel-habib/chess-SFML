#include "Handler.h"

Handler::Handler()
{
    this->turn = Colour::WHITE;
    this->validPlacement = false;
    this->cPiece = 0;
    this->tPiece = 0;
}





Position Handler::get_from()
{
    return this->from;
}

Position Handler::get_to()
{
    return this->to;
}

Position Handler::get_offset()
{
    return this->offset;
}

 int8_t Handler::get_fromy(){
     return this->from.y;
 }
    int8_t Handler::get_cpiece(){
        return cPiece;
    }
    int8_t Handler::get_tpiece(){
        return this->tPiece;
    }
    int8_t Handler::get_dx(){
        return dx;
    }
    int8_t Handler::get_dy(){
        return dy;
    }

Colour Handler::get_color(const int8_t &piece)
{
    //std::cout << "PIECE: " << static_cast<int16_t>(piece) << "\n";
    if (piece > 0)
    {
        return Colour::BLACK;
    }
    else if (piece < 0)
    {
        return Colour::WHITE;
    }
    else
    {
        return Colour::EMPTY;
    }
}



void Handler::handle_mousePress(sf::Vector2i mouse_pos, const int8_t (&board)[8][8])
{
    this->from.x = round(mouse_pos.x / 100);
    this->from.y = round(mouse_pos.y / 100);
    from.set_coords();

    offset.x = mouse_pos.x - from.coord.x;
    offset.y = mouse_pos.y - from.coord.y;

    this->cPiece = board[from.y][from.x];
    
    cpColor = get_color(cPiece);
}

void Handler::validate_turn()
{
    if (this->turn == this->cpColor)
    {
        this->isMoving = true;
        validTurn = true;
    }
    else
    {
        validTurn = false;
    }

}
void Handler::handle_mouse_release(sf::Vector2i mouse_pos, const int8_t (&board)[8][8])
{
    this->to.x = round(mouse_pos.x / 100);
    this->to.y = round(mouse_pos.y / 100);
    to.set_coords();
    this->tPiece = board[to.y][to.x];
    tpColor = get_color(tPiece);
    if (is_placed_on_same_color())
    {
        to = from;
    }
    this->dy = to.y - from.y;
    this->dx = to.x - from.x;
    if (std::abs(cPiece) == 6)
    {
        dy *cPiece > 0 ? pawnForward = true : pawnForward = false;
    }
    this->isMoving = false;
}

bool Handler::is_valid_turn()
{
    return validTurn;
}



void Handler::toggle_turn()
{
    turn == Colour::WHITE ? turn = Colour::BLACK : turn = Colour::WHITE;
}


void Handler::set_mouse_pos(sf::Vector2i mp)
{
    mouse_pos.coord.x = mp.x;
    mouse_pos.coord.y = mp.y;
}

bool Handler::is_placed_on_enemy()
{
    if (tPiece * cPiece < 0)
    {
        std::cout << "Placed on enemy! " << static_cast<int16_t>(tPiece *cPiece) << "\n";
        return true;
    }
    else
    {
        return true;
    }
}

bool Handler::is_placed_on_self()
{
    if (from == to)
    {
        std::cout << "Placed on self! \n"; 
        return true;
    }
    else
    {
        return false;
    }
}
bool Handler::is_placed_on_empty_sq()
{
    if (tpColor == Colour::EMPTY)
    {
        std::cout << "Placed on empty square! \n"; 
        return true;
    }
    else
        return false;
}
bool Handler::is_placed_on_same_color()
{
    std::string temp;
    std::cout << temp;
    return (tpColor == cpColor);
}

std::string Handler::to_chess_notation()
{
    std::string fromm = static_cast<char>('A' + abs(7 - this->from.y)) + std::to_string(this->from.x + 1);
    std::string too = static_cast<char>('A' + abs(7 - this->to.y)) + std::to_string(this->to.x + 1);
    return fromm + too;
}

void Handler::print_move()
{
    std::string move = to_chess_notation();
    if (move.substr(0, 2) == move.substr(2, 3))
    {
        std::cout << "Invalid Move " << print_piece(cPiece) << " from: " << move.substr(0, 2) << " returned to it's square \n";
    }
    else
    {
        std::cout << print_piece(cPiece) << " from: " << move.substr(0, 2) << " to: " << move.substr(2, 3) << " Where there is " << print_piece(tPiece) << "\n";
    }
}

std::string Handler::print_piece(int8_t piece)
{
    std::string p;
    if (piece > 0)
    {
        p = "Black";
    }
    else if (piece < 0)
    {
        p = "white";
    }
    else
    {
        p = "Empty square";
        return p;
    }
    switch (std::abs(piece))
    {
    case 1:
        p = p + " King";
        break;
    case 2:
        p = p + " Queen";
        break;
    case 3:
        p = p + " Rock";
        break;
    case 4:
        p = p + " Bishop";
        break;
    case 5:
        p = p + " Knight";
        break;
    case 6:
        p = p + " Pawn";
        break;
    default:
        break;
    }
    return p;
}


void Handler::handle_invalid_move()
{
    this->to.x = from.x;
    this->to.y = from.y;
    to.set_coords();
}

bool Handler::is_moving(){return this->isMoving;}


void Handler::validate_placement(){
    if(is_placed_on_same_color()){
        this->validPlacement = false;
        to = from;
    }
    else if( (cPiece==fig::bPAWN||cPiece==fig::wPAWN) && !pawnForward){
        this->validPlacement= false;
        to = from; 
    }
    else{this->validPlacement = true;}

}