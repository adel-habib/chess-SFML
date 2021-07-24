#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Constants.h"
#include "Piece.h"
#include "Board.h"
#include "Position.h"
#include "Handler.h"

int main()
{
    Board board = Board();
    Handler handler;

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
                if (handler.is_valid_turn())
                {
                    handler.handle_mouse_release(mousePos, board.get_board());
                    board.place_piece(handler.to);
                }
                handler.print_move();
            }
            if (handler.is_valid_turn())
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