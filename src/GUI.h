#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include "math.h"
#include <cctype>
const sf::Color COL1 = sf::Color(181, 136, 99);
const sf::Color COL2 = sf::Color(240, 217, 181);
const sf::Color sq_selected = sf::Color(171, 162, 58);
class Gui
{
private:

    sf::RenderWindow window; 
    sf::RectangleShape squares[64];
    sf::Texture t[12];
    sf::Sprite pieces[32];
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Vector2i mousepos;



    Board board;
    Coords from;
    Coords to;
public:
    Gui();
    void mainloop();
    // Setting up the board 
    void init_textures();
    void set_squares();
    void draw_squares();
    void init_sprites();
    void draw_pieces();
    
    // Handling events 
    void detect_press();
};


#endif