
#ifndef Position_H
#define Position_H

#include<math.h>
#include<iostream>

struct Position
{
    int x, y; 
    enum class Kind {SQUARE, COORD};
    Kind kind;
    Position():x(0),y(0){}
    Position(Kind typ) : x(0), y(0){this->kind = typ;}
    Position(int x, int y){
        this->x =x;
        this->y=y;
    }
    Position(double x, double y){
        this->x = int(x);
        this->y = int(y);
    }
    Position operator-(Position pos){
        Position nPos;
        nPos.x = x - pos.x;
        nPos.y = y - pos.y;
        return nPos;
    }
    Position operator+(Position pos){
        Position nPos;
        nPos.x = x + pos.x;
        nPos.y = y + pos.y;
        return nPos;
    }
    Position operator*(int mult){
        Position nPos = Position(this->kind);
        nPos.x = this->x * mult;
        nPos.y = this->y * mult;
        return nPos;

    }

    void square_to_coords(Position squ){
        if (squ.kind==Position::Kind::SQUARE)
        {
           x = squ.x * 100;
           y = squ.y * 100;
        }else{
            std::cout<<"Error: square_to_coords accepts only a Position of kind Square" << "\n";
        }
        
    }
     void set_square(float x, float y){
         this->x=round(x/100);
         this->y=round(y/100);
       }

};
#endif