#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Constants.h"
#include "Piece.h"
#include "Board.h"


struct Posistion 
{
   int x;
   int y; 
};
struct Square
{
    int x;
    int y;

    Square operator-(Square squ){
        Square newSquare;
        newSquare.x = x - squ.x;
        newSquare.y = y -squ.y;
        return newSquare;
    }
};


int8_t currentFigureIndex = 0;
int cnt = 0;

Posistion fromPos, toPos;
Square from, to;
int currentPiece;
int targetPiece;
// Figures
int squareSize = 100;






// algebric notation 
std::string getMove(Square fromS, Square toS){
    std::string fromm = static_cast<char>('a' + abs(7-fromS.y)) + std::to_string(fromS.x+1);
    std::string too = static_cast<char>('a' + abs(7-toS.y)) + std::to_string(toS.x+1);
    return fromm + too ;
}


int main()
{

    Board B = Board();
    Piece pieces[32];
    B.init_board();
    B.load_textures();
    B.load_figures(pieces);
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess!");
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(squareSize, squareSize));
    bool isMoving = false;
    float dx = 0, dy=0;
    
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
                           isMoving = true; // True if one of the figures is pressed 
                           std::cout<<pieces[i].figure.getGlobalBounds().left<< "and" << pieces[i].figure.getGlobalBounds().top <<"\n";
                           from.x = round(sf::Mouse::getPosition(window).x/100);
                           from.y = round(sf::Mouse::getPosition(window).y/100);
                           fromPos.x = from.x*100; 
                           fromPos.y = from.y*100;

                           currentPiece = B.board[from.y][from.x];
                           currentFigureIndex = i;

                           dx = mousePos.x - fromPos.x;
                           dy = mousePos.y - fromPos.y;
                           
                       }
                   }

            }
            if(event.type==sf::Event::MouseButtonReleased){
                isMoving = false;
                to.x = round(pieces[currentFigureIndex].figure.getPosition().x/100); 
                to.y = round(pieces[currentFigureIndex].figure.getPosition().y/100);
                toPos.x = 100 * to.x;
                toPos.y = 100 * to.y;
                targetPiece = B.board[to.y][to.x];

            }
            
            if (isMoving) {
                pieces[currentFigureIndex].figure.setPosition(mousePos.x-dy,mousePos.y-dy);
                }
        }

        window.clear();

        B.draw_board(window);
        B.draw_pieces(pieces,window);
        window.display();
    }
    
    return 0;
}