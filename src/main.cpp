#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

struct Posistion 
{
   int x;
   int y; 
};
struct Square
{
    int x;
    int y;

    Square operator-(Square squ){
        Square newSquare;
        newSquare.x = x - squ.x;
        newSquare.y = y -squ.y;
        return newSquare;
    }
};



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

int8_t board[8][8] = {
{bROCK,bKNIGHT,bBISHOP,bQUEEN,bKING,bBISHOP,bKNIGHT,bROCK},
{bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN},
{wROCK,wKNIGHT,wBISHOP,wQUEEN,wKING,wBISHOP,wKING,wROCK},
};

int8_t currentFigureIndex = 0;
int cnt = 0;

Posistion fromPos, toPos;
Square from, to;
int currentPiece;
int targetPiece;
// Figures
int squareSize = 100;

sf::Color col1 = sf::Color(232,235,239);
sf::Color col2 = sf::Color(125,135,150);


sf::Texture bk, bq, br, bb, bn, bp, wk, wq, wr, wb, wn, wp;
sf::Sprite Figures[32];

void loadPositions(){
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            int n = board[i][j];
            if(n==0){continue;}
            if (n == bKING)
            {
                Figures[cnt].setTexture(bk);
            }
            else if (n == bQUEEN)
            {
                Figures[cnt].setTexture(bq);
            }
            else if (n == bROCK)
            {
                Figures[cnt].setTexture(br);
            }
            else if (n == bBISHOP)
            {
                Figures[cnt].setTexture(bb);
            }
            else if (n == bKNIGHT)
            {
                Figures[cnt].setTexture(bn);
            }
            else if (n == bPAWN)
            {
                Figures[cnt].setTexture(bp);
            }
            else if (n == wKING)
            {
                Figures[cnt].setTexture(wk);
            }
            else if (n == wQUEEN)
            {
                Figures[cnt].setTexture(wq);
            }
            else if (n == wROCK)
            {
                Figures[cnt].setTexture(wr);
            }
            else if (n == wBISHOP)
            {
                Figures[cnt].setTexture(wb);
            }
            else if (n == wKNIGHT)
            {
                Figures[cnt].setTexture(wn);
            }
            else if (n == wPAWN)
            {
                Figures[cnt].setTexture(wp);
            }
            Figures[cnt].setPosition(100*j,100*i);
            cnt++;
        }
        
    }
    
}


void drawBoard(sf::RenderWindow &window, sf::RectangleShape rec){
for (size_t j = 0; j < 8; j++)
        {
            for(int i=0; i<8; i++){
            rec.setPosition(squareSize*i,squareSize*j);
            if(j%2==0){i%2==0?rec.setFillColor(col1):rec.setFillColor(col2);}
            else {i%2==0?rec.setFillColor(col2):rec.setFillColor(col1);}
            window.draw(rec);
        }
        }
}


// algebric notation 
std::string getMove(Square fromS, Square toS){
    std::string fromm = static_cast<char>('a' + abs(7-fromS.y)) + std::to_string(fromS.x+1);
    std::string too = static_cast<char>('a' + abs(7-toS.y)) + std::to_string(toS.x+1);
    return fromm + too ;
}


bool isAllowed(){
    // checks if the next square is empty or has a piece of opposite color 
    bool isEmpty = board[to.y][to.x] == 0;
    bool isDiff = std::signbit(board[from.y][from.x]*board[to.y][to.x]);
    if(isEmpty || isDiff) return true;
    else return false;

}
bool isWhite(){
    if(currentPiece<0) return true;
    else return false;
}
bool isBlack(){
    if(currentPiece>0) return true;
    else return false;
}

void update_board(){
    board[to.y][to.x] = board[from.y][from.x];
    board[from.y][from.x] = emptySquare;
}

void movePiece(){
    if(targetPiece!=emptySquare){for (size_t i = 0; i < 32; i++)
    {
        if(Figures[i].getGlobalBounds().left == toPos.x && Figures[i].getGlobalBounds().top==toPos.y){Figures[i].setPosition(-100,100);break;}
    }
    }
    Figures[currentFigureIndex].setPosition(toPos.x,toPos.y);
    update_board();
}
void moveBack(){Figures[currentFigureIndex].setPosition(fromPos.x,fromPos.y);}

bool knightValidMove(Square old, Square next){
    if(abs(old.x-next.x)==2 && abs(old.y-next.y)==1 && isAllowed()){return true;}
    else if (abs(old.y-next.y)==2 && abs(old.x-next.x)==1 && isAllowed()){return true;}
    else return false;
}


bool pawnValidMove(){
    Square len = from - to; 
    bool isForward = (isWhite() && (len.y>0) ) || (isBlack() && (len.y<0));
    std::cout<<"is Foraward: " << isForward<< "\n";
    int dn = isWhite()? from.y -1 : from.y+1 ;
    bool isBlocked = board[dn][from.x] != emptySquare;
    if(isForward && isAllowed()){
        if(len.x==0 && abs(len.y)<3 && !isBlocked){return true;}
        else if(abs(len.x)==1 && abs(len.y)==1 && targetPiece!=emptySquare){return true;}
        else return false;
    }
    else return false;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess!");
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(squareSize, squareSize));
    bool isMoving = false;
    float dx = 0, dy=0;
    
    //// 

    bk.loadFromFile("assets/bK.png"); bq.loadFromFile("assets/bQ.png"); br.loadFromFile("assets/bR.png"); bb.loadFromFile("assets/bB.png");
    bn.loadFromFile("assets/bN.png"); bp.loadFromFile("assets/bP.png"); wk.loadFromFile("assets/wK.png"); wq.loadFromFile("assets/wQ.png");
    wr.loadFromFile("assets/wR.png"); wb.loadFromFile("assets/wB.png"); wn.loadFromFile("assets/wN.png"); wp.loadFromFile("assets/wP.png");

    loadPositions();

   
    

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Get's updated all the time => while 
        
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                // Which Figure is being pressed? 
                
                   for (size_t i = 0; i < 32; i++)
                   {
                       if(Figures[i].getGlobalBounds().contains(mousePos.x,mousePos.y)){
                           isMoving = true; // True if one of the figures is pressed 
                           std::cout<<Figures[i].getGlobalBounds().left<< "and" << Figures[i].getGlobalBounds().top <<"\n";
                           from.x = round(sf::Mouse::getPosition(window).x/100);
                           from.y = round(sf::Mouse::getPosition(window).y/100);
                           fromPos.x = from.x*100; 
                           fromPos.y = from.y*100;

                           currentPiece = board[from.y][from.x];
                           currentFigureIndex = i;

                           dx = mousePos.x - fromPos.x;
                           dy = mousePos.y - fromPos.y;
                           
                       }
                   }

            }
            if(event.type==sf::Event::MouseButtonReleased){
                isMoving = false;
                to.x = round(Figures[currentFigureIndex].getPosition().x/100); 
                to.y = round(Figures[currentFigureIndex].getPosition().y/100);
                toPos.x = 100 * to.x;
                toPos.y = 100 * to.y;
                targetPiece = board[to.y][to.x];

                if(currentPiece == wPAWN || currentPiece==bPAWN){
                    if (pawnValidMove())
                    {
                        movePiece();
                    }
                    else{moveBack();}
                    
                }else if (currentPiece == wKNIGHT || currentPiece == bKNIGHT)
                {
                   if (knightValidMove(from,to))
                   {
                       movePiece();
                   }
                   else{moveBack();}
                   
                }
                
                
                else{moveBack();}
                std::cout<< getMove(from,to) <<"\n";
            }
            
            if (isMoving) {
                Figures[currentFigureIndex].setPosition(mousePos.x-dy,mousePos.y-dy);
                }
        }

        window.clear();

        
        drawBoard(window,square);
        //piece.setPosition(sf::Vector2f(0,0));
        for (size_t i = 0; i < 32; i++)
        {
            window.draw(Figures[i]);
        }

        window.display();
    }

    return 0;
}