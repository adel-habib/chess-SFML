#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

// BOARD 


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

int8_t currentFigure = 0;

int8_t board[8][8] = {
{wROCK,wKNIGHT,wBISHOP,wQUEEN,wKING,wBISHOP,wKING,wROCK},
{wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare,emptySquare},
{bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN},
{bROCK,bKNIGHT,bBISHOP,bQUEEN,bKING,bBISHOP,bKNIGHT,bROCK},
};


// Figures

sf::Texture bk, bq, br, bb, bn, bp, wk, wq, wr, wb, wn, wp;
sf::Sprite Figures[32];

int cnt = 0;
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

struct posistion 
{
   int x;
   int y; 
};
struct Square
{
    int8_t x;
    int8_t y;
};

posistion oldPos, newPos;
Square currentSquare, newSquare;
int currentPiece;


int squareSize = 100;
sf::Color col1 = sf::Color(232,235,239);
sf::Color col2 = sf::Color(125,135,150);
sf::Vector2f sc(0.05,0.05);
sf::Vector2i pos;



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


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess!");
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(squareSize, squareSize));
    sf::Texture texture;
    bool isMoving = false;
    float dx = 0, dy=0;
    texture.loadFromFile("assets/bK.png");
    sf::Sprite piece;
    piece.setTexture(texture);
    float xpos = 0, ypos = 0;
    
    //// 

    bk.loadFromFile("assets/bK.png");
    bq.loadFromFile("assets/bQ.png");
    br.loadFromFile("assets/bR.png");
    bb.loadFromFile("assets/bB.png");
    bn.loadFromFile("assets/bN.png");
    bp.loadFromFile("assets/bP.png"); 
    wk.loadFromFile("assets/wK.png");
    wq.loadFromFile("assets/wQ.png");
    wr.loadFromFile("assets/wR.png");
    wb.loadFromFile("assets/wB.png");    
    wn.loadFromFile("assets/wN.png");
    wp.loadFromFile("assets/wP.png");

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

                           currentSquare.x = round(sf::Mouse::getPosition(window).x/100);
                           currentSquare.y = round(sf::Mouse::getPosition(window).y/100);

                           oldPos.x = currentSquare.x*100; oldPos.y = currentSquare.y*100;

                           currentPiece = board[currentSquare.y][currentSquare.x];
                           currentFigure = i;
                           xpos = 100*currentSquare.x;
                           ypos = 100*currentSquare.y;
                           dx = mousePos.x - xpos;
                           dy = mousePos.y - ypos;
                       }
                   }


            }
            if(event.type==sf::Event::MouseButtonReleased){
                isMoving = false;
                newSquare.x = round(Figures[currentFigure].getPosition().x/100); 
                newSquare.y = round(Figures[currentFigure].getPosition().y/100);
                newPos.x = 100 * newSquare.x;
                newPos.y = 100 * newSquare.y;
                if(currentPiece == wPAWN || currentPiece==bPAWN){
                    if (abs(currentSquare.y - newSquare.y)<3)
                    {
                        Figures[currentFigure].setPosition(newPos.x,newPos.y);
                    }
                    else{Figures[currentFigure].setPosition(oldPos.x,oldPos.y);}
                    
                }else{Figures[currentFigure].setPosition(oldPos.x,oldPos.y);}
                

                //std::cout << "Old Sqaure:" <<currentSquare.x << "," <<currentSquare.y << "\n" << "newSq" << newSquare.x << "," << newSquare.y << "\n";
            }
            
            if (isMoving) {
                Figures[currentFigure].setPosition(mousePos.x-dy,mousePos.y-dy);
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