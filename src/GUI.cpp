#include "GUI.h"

Gui::Gui() : window(sf::VideoMode(800, 800), "Chess SFML", sf::Style::Titlebar | sf::Style::Close), expect_target(false), moveOnClick(false), drag(false)
{
    board.init_board();
    set_squares();
    init_textures();
    init_sprites();
}

// Setting up the board

void Gui::set_squares()
{
    int x = 0;
    int j = 0;
    for (size_t i = 0; i < 64; i++)
    {
        if (i != 0 && i % 8 == 0)
        {
            j++;
            x = 0;
        }
        squares[i].setSize(sf::Vector2f(100, 100));
        squares[i].setPosition(sf::Vector2f(100 * x, 100 * j));
        if (j % 2 == 0)
        {
            (x % 2 == 0) ? squares[i].setFillColor(COL2) : squares[i].setFillColor(COL1);
        }
        else
        {
            (x % 2 == 0) ? squares[i].setFillColor(COL1) : squares[i].setFillColor(COL2);
        }
        x++;
    }
}

void Gui::draw_squares()
{
    for (size_t i = 0; i < 64; i++)
    {
        window.draw(squares[i]);
    }
}

void Gui::init_textures()
{
    std::string labels[12] = {"bK", "bQ", "bR", "bB", "bN", "bP", "wK", "wQ", "wR", "wB", "wN", "wP"};
    for (auto &label : labels)
    {
        label = "assets/" + label + ".png";
    }
    for (size_t i = 0; i < 12; i++)
    {
        t[i].loadFromFile(labels[i]);
    }
}

void Gui::init_sprites()
{
    string figures = "kqrbnpKQRBNP";
    Coords coords;
    int texcnt = 0;
    int spicnt = 0;
    for (auto fig : figures)
    {
        for (size_t i = 0; i < 64; i++)
        {
            if (board[i] == 'e')
            {
                continue;
            }
            if (fig == board[i])
            {
                coords = coords.index_to_coords(i);
                pieces[spicnt].setTexture(t[texcnt]);
                pieces[spicnt].setPosition(coords.get_col() * 100, coords.get_row() * 100);
                spicnt++;
            }
        }
        texcnt++;
    }
}

void Gui::draw_pieces()
{
    for (size_t i = 0; i < 32; i++)
    {
        window.draw(pieces[i]);
    }
}

void Gui::set_pos(bool s_from)
{
    for (size_t i = 0; i < 32; i++)
    {
        if (pieces[i].getGlobalBounds().contains(mousepos.x, mousepos.y))
        {
            if (s_from)
            {
                from = mousepos;
                drag = true;
                pressed_piece = board[from.index()];
                pressed_figure = i;
                expect_target = true;
            }
        }
        else
        {
            to = mousepos;
        }
    }
}
void Gui::handle_press()
{
    

}

void Gui::handle_release() 
{
    
}

void Gui::highlight_squares(vector<int> validmoves)
{
    for (auto move : validmoves)
    {
        squares[move].setFillColor(sq_selected);
    }
}

void Gui::move_piece()
{
    Coords offset;
    offset = to - from;
    cout << offset;
    
    pieces[pressed_figure].move(offset.get_col() * 100, offset.get_row() * 100 );
}

void Gui::mainloop()
{
    while (window.isOpen())
    {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            this->mousepos = sf::Mouse::getPosition(window);
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                handle_press();
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                handle_release();
            }
            if(drag){
                pieces[pressed_figure].setPosition(mousepos.x+offset.x,mousepos.y+offset.y);
            }
        }

        // Clear the whole window before rendering a new frame
        window.clear();
        // Draw some graphical entities
        draw_squares();
        
        draw_pieces();
        // End the current frame and display its contents on screen
        window.display();
    }
}