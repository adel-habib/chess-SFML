#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1
#include <SFML/Graphics.hpp>
#include<iostream>
const int sq_sz=100;
const sf::Color sq_col1 = sf::Color(181, 136, 99);
const sf::Color sq_col2 = sf::Color(240, 217, 181);
const sf::Color sq_selected = sf::Color(171, 162, 58);

namespace fig{
    const int8_t bKING = 1;
    const int8_t bQUEEN = 2;
    const int8_t bROCK = 3;
    const int8_t bBISHOP = 4;
    const int8_t bKNIGHT = 5;
    const int8_t bPAWN = 6;
    const int8_t wKING = -1;
    const int8_t wQUEEN = -2;
    const int8_t wROCK = -3;
    const int8_t wBISHOP = -4;
    const int8_t wKNIGHT = -5;
    const int8_t wPAWN = -6;
    const int8_t emptySquare = 0;
};
#endif