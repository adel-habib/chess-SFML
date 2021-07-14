#include <SFML/Graphics.hpp>
sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
const int bKING = 6;
const int bQUEEN = 5;
const int bROCK = 4;
const int bBISHOP = 3;
const int bKNIGHT = 2;
const int bPAWN = 1;

const int wKING = -6;
const int wQUEEN = -5;
const int wROCK = -4;
const int wBISHOP = -3;
const int wKNIGHT = -2;
const int wPAWN = -1;

const int FREESPOT = 0;

int squareSize = 100;
sf::Color col1 = sf::Color(232,235,239);
sf::Color col2 = sf::Color(125,135,150);
sf::Vector2f sc(0.05,0.05);

int board[8][8] = {
{wROCK,wKNIGHT,wBISHOP,wQUEEN,wKING,wBISHOP,wKING,wROCK},
{wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN},
{FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT},
{FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT},
{FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT},
{FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT,FREESPOT},
{bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN},
{bROCK,bKNIGHT,bBISHOP,bQUEEN,bKING,bBISHOP,bKNIGHT,bROCK},
};

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
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::RectangleShape rec;
        rec.setSize(sf::Vector2f(squareSize, squareSize));
        sf::Event event;
        
        t1.loadFromFile("assets/bK.png");
        t2.loadFromFile("assets/bQ.png");
        t3.loadFromFile("assets/bR.png");
        t4.loadFromFile("assets/bB.png");
        t5.loadFromFile("assets/bN.png");
        t6.loadFromFile("assets/bP.png"); 
        t7.loadFromFile("assets/wK.png");
        t8.loadFromFile("assets/wQ.png");
        t9.loadFromFile("assets/wR.png");
        t10.loadFromFile("assets/wB.png");
        t11.loadFromFile("assets/wN.png");
        t12.loadFromFile("assets/wP.png");

        sf::Sprite bk(t1), bq(t2), br(t3), bb(t4), bn(t5), bp(t6), wk(t7), wq(t8), wr(t9), wb(t10), wn(t11), wp(t12);
 
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();}
            else if (event.type == sf::Event::MouseButtonPressed)
                {
                    
                }
                
              
                
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        // draw everything here...
        // window.draw(...);
        drawBoard(window,rec);

        // Updateboard
        for (size_t i = 0; i < 8; i++)
        {
           for (size_t j = 0; j < 8; j++)
           {
               if (board[i][j]==wPAWN)
               {
                   wp.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(wp);
               }
               else if (board[i][j]==bPAWN)
               {
                   bp.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(bp);
               }
               else if (board[i][j]==bKNIGHT)
               {
                   bn.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(bn);
               }
               else if (board[i][j]==wKNIGHT)
               {
                   wn.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(wn);
               }
               else if (board[i][j]==wBISHOP)
               {
                   wb.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(wb);

               }
               else if (board[i][j]==bBISHOP)
               {
                   bb.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(bb);
               }


               else if (board[i][j]==bKING)
               {
                   bk.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(bk);
               }
               else if (board[i][j]==wKING)
               {
                   wk.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(wk);
               }
               else if (board[i][j]==bQUEEN)
               {
                   bq.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(bq);
               }
               else if (board[i][j]==wQUEEN)
               {
                   wq.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(wq);
               }
               else if (board[i][j]==bROCK)
               {
                   br.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(br);
               }
               else if (board[i][j]==wROCK)
               {
                   wr.setPosition(sf::Vector2f(j*100,i*100));
                   window.draw(wr);
               }
               // END 




               
               
               
               
           }
           
        }
        
        // end the current frame
        window.display();
    }

    return 0;
}
