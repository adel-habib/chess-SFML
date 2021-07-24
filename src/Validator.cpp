#include "Validator.h"

void Validator::validate_pawn(int8_t dx, int8_t dy, int8_t y, int8_t tpiece){
    if(tpiece==0 && dx == 0){

        if( (dy==2 && y==1) || (dy==-2 && y==6) ){
            valid = true;
            std::cout << "Validator: Pawn moved 2 squares Forward! \n";
        }
        if(std::abs(dy) == 1){
            std::cout << "Validator: Pawn moved 1 square Forward! \n";
            valid = true;
        }
    }
    else if(std::abs(dy*dx) == 1 && tpiece!=0){
        std::cout << "Validator: Pawn captured \n";
        valid = true;
    } else{ valid = false; std::cout << "Validator: invalid Pawn Movement!\n";}

}

bool Validator::is_legal(){
    if(valid){std::cout<<"Is_legal: True \n";}
    return this->valid;
}

void Validator::validate_knight(int8_t dy, int8_t dx){
    if(std::abs(dy*dx) == 2){
        valid = true;
    }
    else {valid = false;}
}

void Validator::validate_bishop(int8_t dy, int8_t dx){
    if(std::abs(dy) == std::abs(dx)){
        valid = true;
    } else{
        valid = false;
    }
}

void Validator::reset(){
    valid=false;
}