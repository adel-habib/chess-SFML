#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Constants.h"
#include "Piece.h"
#include "Board.h"
#include "Position.h"
#include "Handler.h"
#include "Validator.h"

int main()
{
    Board board = Board();
    Handler handler;
    Validator validator;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess!", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        //handler.set_mouse_pos(mousePos);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (board.is_piece_pressed(mousePos))
                {
                    handler.handle_mousePress(mousePos, board.get_board());
                    handler.validate_turn();
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if(handler.is_valid_turn()){
                    
                    handler.handle_mouse_release(mousePos, board.get_board());
                    handler.set_direction();
                    handler.validate_placement(board.get_board());
                    if (handler.is_valid_placement())
                    {
                        
                        validator.validate_move(handler.get_cpiece(), handler.get_tpiece(), handler.get_dx(), handler.get_dy(), handler.get_fromy());
                    }
                     if (!validator.is_legal())
                    {
                        handler.handle_invalid_move();
                    }
                    if(validator.is_legal())
                    {
                        board.update_board(handler.get_from(), handler.get_to());
                        handler.toggle_turn();
                        validator.reset();
                    }
                    board.place_piece(handler.to);
                    handler.print_move();
                }
                /*
                if (handler.is_valid_turn())
                {
                    handler.set_direction();
                    handler.handle_mouse_release(mousePos, board.get_board());
                    handler.validate_placement(board.get_board());
                    

                    // Here we want to check the logic of move, if it's legal we complete the move and toggle the turn
                    // if it is illegal we set 'to' in Handler to 'from' and keep the board to its current state
                    // validator.validate_pawn(handler.get_dx(),handler.get_dy(),handler.get_fromy(),handler.get_tpiece());
                    // validator.validate_knight(handler.get_dy(),handler.get_dx());
                    // validator.validate_bishop(handler.get_dy(),handler.get_dx());
                    if (handler.is_valid_placement())
                    {
                        
                        validator.validate_move(handler.get_cpiece(), handler.get_tpiece(), handler.get_dx(), handler.get_dy(), handler.get_fromy());
                    }
                    if (!validator.is_legal())
                    {
                        handler.handle_invalid_move();
                    }
                    if(validator.is_legal())
                    {
                        board.update_board(handler.get_from(), handler.get_to());
                        handler.toggle_turn();
                        validator.reset();
                    }
                    board.place_piece(handler.to);
                    handler.print_move();
                }
                */

                std::cout << "---------------------------\n";
            }
            if (handler.is_moving())
            {
                board.move_piece(mousePos.x - handler.get_offset().x, mousePos.y - handler.get_offset().y);
            }
        }

        window.clear();

        board.draw_board(window);
        board.draw_pieces(window);
        window.display();
    }

    return 0;
}