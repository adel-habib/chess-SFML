#ifndef VALIDATOR_H
#define VALIDATOR_H

#include<iostream>
class Validator{
    private:
    bool valid;
    public:
    void validate_pawn(int8_t dx, int8_t dy, int8_t y, int8_t tpiece);
    void validate_knight(int8_t dy, int8_t dx);
    void validate_bishop(int8_t dy, int8_t dx);
    bool is_legal();
    void reset();








};

#endif