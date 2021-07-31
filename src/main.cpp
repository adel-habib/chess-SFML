#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <string>
#include "Grid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    Grid grid;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Vector2i position = sf::Mouse::getPosition(window);
        sf::Event event;
        // handle events
        grid.handle_event(window,event,position);

        // draw 
        window.clear();
        grid.draw_board(window);
        grid.draw_pieces(window);
        window.display();
    }

    return 0;
}
