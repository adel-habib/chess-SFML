#ifndef GRID_H
#define GRID_H
#include<iostream>
#include"Index.h"
#include"SFML/Graphics.hpp"
#include "Constants.h"
const size_t sz = 8;

class Grid 
{
    private:
    int8_t board[sz][sz];
    sf::RectangleShape squares[64];
    sf::Texture T[12];
    sf::Sprite pieces[32];
    Index current_index;
    Index target_index;

    public:
    Grid();
    size_t size() const;
    int8_t &operator()(size_t row, size_t col);
    int8_t& operator() (const Index &index);
    const int8_t& operator() (const Index &index) const;
    int8_t& operator[] (const Index &index);
    void destruct(const Index &index);
    void move(const Index &from, const Index &to);

    void init_board();
    void draw_board(sf::RenderWindow &window);
    void load_textures();
    void load_pieces();
    void print_board();
    void draw_pieces(sf::RenderWindow &window);
    void handle_event(sf::RenderWindow &window,sf::Event &event,sf::Vector2i &position);

    

};

#endif
