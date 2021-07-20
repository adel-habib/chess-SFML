#ifndef BOARD_H
#define BOARD_H
#include "Constants.h"

class Piece;
class Board{
    private:
    const int squareSize=100;
    const sf::Color col1 = sf::Color(232,235,239);
    const sf::Color col2 = sf::Color(125,135,150);
    sf::RectangleShape square;
    public:
    int8_t board[8][8];
    sf::Texture t[12];
    void init_board();
    void load_textures();
    void load_figures(Piece piece[]);
    void draw_board(sf::RenderWindow &window);
    void draw_pieces(Piece pieces[], sf::RenderWindow &window);
    int get_size();
};

#endif