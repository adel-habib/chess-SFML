struct Position
{
    int x, y; 
    Position() : x(0), y(0){}
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
};
