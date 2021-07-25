#include "Validator.h"

void Validator::validate_pawn(int8_t dx, int8_t dy, int8_t y, int8_t tpiece){
    // if placed on empty square then movement must be forward 
    std::cout << "HERE \n";
    if(tpiece==0 && dx == 0){

        if( (dy==2 && y==1) || (dy==-2 && y==6) ){
            std::cout << "True 1 \n";
            valid = true;
        }
        if(std::abs(dy) == 1){
            valid = true;
            std::cout << "True 2\n";
        }
    }
    // if placed otherwise on enemy square, movement must be diagonal 
    else if(std::abs(dy*dx) == 1 && tpiece!=0){
        valid = true;
        std::cout << "True 3 \n";
    } else{ valid = false;}

}

bool Validator::is_legal(){
    if(valid){std::cout<<"Is_legal: True \n";}
    return this->valid;
}

void Validator::validate_knight(int8_t dx, int8_t dy){
    if(std::abs(dy*dx) == 2){
        valid = true;
    }
    else {valid = false;}
}

void Validator::validate_bishop(int8_t dx, int8_t dy){
    if(std::abs(dy) == std::abs(dx)){
        valid = true;
    } else{
        valid = false;
    }
}
void Validator::validate_rock(int8_t dx, int8_t dy){
    if( dy==0 || dx==0 ){
        valid = true;
    } else{
        valid = false;
    }
}
void Validator::validate_queen(int8_t dx, int8_t dy){
    if(!valid){validate_rock(dx,dy);}
    if(!valid){validate_bishop(dx,dy);}
}

void Validator::reset(){
    valid=false;
}

void Validator::validate_move(int8_t cpiece, int8_t tpiece, int8_t dx, int8_t dy, int8_t fromy){
    switch (std::abs(cpiece))
    {
    case 6: validate_pawn(dx,dy,fromy,tpiece);
        break;
    case 5: validate_knight(dx,dy);
        break;
    case 4: validate_bishop(dx,dy);
        break;
    case 3: validate_rock(dx,dy);
        break;
    case 2: validate_queen(dx,dy);
        break;
    
    default:
        break;
    }
    if(dx==0 && dy==0){this->valid = false;}
}