
#ifndef Position_H
#define Position_H

#include<math.h>
#include<iostream>

struct coordinates
{
    int x,  y;
};


struct Position
{
    int x, y; 
    coordinates coord;
    enum class Kind {INDEX, COORD};
    Kind kind;
    Position():x(0),y(0){this->set_coords();}
    Position(Kind typ) : x(0), y(0){this->kind = typ;this->set_coords();}
    Position(int x, int y){
        this->x =x;
        this->y=y;
        this->set_coords();
    }
    Position(double x, double y){
        this->x = int(x);
        this->y = int(y);
    }
    

    bool operator==(Position pos){
        return ( (this->x == pos.x) && (this->y == pos.y) );
    }


    void square_to_coords(Position squ){
        if (squ.kind==Position::Kind::INDEX)
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

       void set_coords(){
           coord.x = x * 100;
           coord.y = y * 100;
       }

};
#endif