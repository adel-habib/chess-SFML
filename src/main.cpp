#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Constants.h"
#include "Piece.h"
#include "Board.h"
#include "Position.h"
#include "Game.h"

// algebric notation 
std::string getMove(const Position &fromS, const Position &toS){
    std::string fromm = static_cast<char>('a' + abs(7-fromS.y)) + std::to_string(fromS.x+1);
    std::string too = static_cast<char>('a' + abs(7-toS.y)) + std::to_string(toS.x+1);
    return fromm + too ;
}


int main()
{

    
    Piece pieces[32];
    Board B = Board();
    B.init_board();
    B.load_textures();
    B.load_figures(pieces);

    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess!");
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(B.get_size(), B.get_size()));
    bool isMoving = false;
    float dx = 0, dy=0;    
    Game game = Game();

    //// 


   
    

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
                // Which Figure is being pressed? 
                
                   for (size_t i = 0; i < 32; i++)
                   {
                       if(pieces[i].figure.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                           game.set_movement(true);
                           game.set_current_coords(sf::Mouse::getPosition(window));
                           game.set_current_piece(B.board);
                           game.set_current_figure(i);
                           dx = mousePos.x - game.get_current_coords().x;
                           dy = mousePos.y - game.get_current_coords().y;                           
                       }
                   }

            }
            if(event.type==sf::Event::MouseButtonReleased){

                game.set_movement(false);
                game.set_target_coords(mousePos);
                pieces[game.get_current_figure_index()].figure.setPosition(game.get_target_coords().x,game.get_target_coords().y);

            }
            
            if (game.get_is_moving()) {
                pieces[game.get_current_figure_index()].figure.setPosition(mousePos.x-dx,mousePos.y-dy);
                }
        }

        window.clear();

        B.draw_board(window);
        B.draw_pieces(pieces,window);
        window.display();
    }
   
    return 0;
}