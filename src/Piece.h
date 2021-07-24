
#ifndef PIECE_H
#define PIECE_H
#include <SFML/Graphics.hpp>

enum class Color {BLACK, WHITE};

class Piece{

    private:
    Color color;
    int8_t vlaue;
    bool isAttacked;
    bool isFirstMove;
    

    public:
    sf::Sprite figure;
    void set_color(const Color &col);
    void set_value(const int8_t &val);
    void set_figure(const sf::Texture &t);
    void set_position(int i, int j);
    sf::Sprite get_figure();


};
#endif