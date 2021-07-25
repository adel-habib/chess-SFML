#ifndef VALIDATOR_H
#define VALIDATOR_H

#include<iostream>
class Validator{
    private:
    bool valid;
    public:
    void validate_pawn(int8_t dx, int8_t dy, int8_t y, int8_t tpiece);
    void validate_knight(int8_t dx, int8_t dy);
    void validate_bishop(int8_t dx, int8_t dy);
    void validate_rock(int8_t dx, int8_t dy);
    void validate_queen(int8_t dx, int8_t dy);

    void validate_move(int8_t cpiece, int8_t tpiece, int8_t dx, int8_t dy, int8_t fromy);
    bool is_legal();
    void reset();








};

#endif