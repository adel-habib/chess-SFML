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
    Piece pieces[32];
    Board B = Board();
    Handler handler;
    B.init_board();
    B.load_textures();
    B.load_figures(pieces);
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess!");
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(B.get_size(), B.get_size()));
    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Get's updated all the time => while 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {                
                   for (size_t i = 0; i < 32; i++)
                   {
                       if(pieces[i].figure.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                           handler.handle_mousePress(mousePos,B.board,i);
                           handler.validate_turn();                     
                       }
                   }
            }
            if(event.type==sf::Event::MouseButtonReleased){
                if(handler.is_valid_turn()){
                handler.handle_mouse_release(mousePos,B.board);
                pieces[handler.get_cfi()].figure.setPosition(handler.to.coord.x,handler.to.coord.y);
            }
            }
            if (handler.is_valid_turn()) {
                pieces[handler.get_cfi()].figure.setPosition(mousePos.x-handler.get_offset().x,mousePos.y-handler.get_offset().y);
                }
        }

        window.clear();

        B.draw_board(window);
        B.draw_pieces(pieces,window);
        window.display();
    }
   
    return 0;

}