#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <string>
#include "Grid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    Grid grid;
    grid.set_board_squares();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Vector2i position = sf::Mouse::getPosition(window);
        sf::Event event;
        // handle events
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                grid.handle_press(position);
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                grid.handle_release(position);
            }

            if(grid.is_draggable()){
                grid.drag_piece(position);
            }
        }
       

        // draw
        window.clear();
        grid.draw_board(window);
        grid.draw_pieces(window);

        window.display();
    }

    return 0;
}
