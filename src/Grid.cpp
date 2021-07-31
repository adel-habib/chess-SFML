#include "Grid.h"
Grid::Grid()
{

    init_board();
    load_textures();

    load_pieces();
}
size_t Grid::size() const { return sz * sz; }
int8_t &Grid::operator()(size_t row, size_t col)
{
    return board[row][col];
}
int8_t &Grid::operator()(const Index &index)
{
    return board[index.row][index.column];
}
const int8_t &Grid::operator()(const Index &index) const
{
    return board[index.row][index.column];
}

int8_t &Grid::operator[](const Index &index)
{
    return board[index.row][index.column];
}
void Grid::destruct(const Index &index)
{
    this->board[index.row][index.column] = 0;
}
void Grid::move(const Index &from, const Index &to)
{
    board[to.row][to.column] = board[from.row][from.column];
    destruct(from);
}

void Grid::init_board()
{
    using namespace fig;
    int8_t temp[8][8] = {
        {bROCK, bKNIGHT, bBISHOP, bQUEEN, bKING, bBISHOP, bKNIGHT, bROCK},
        {bPAWN, bPAWN, bPAWN, bPAWN, bPAWN, bPAWN, bPAWN, bPAWN},
        {emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare},
        {emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare},
        {emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare},
        {emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare, emptySquare},
        {wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN},
        {wROCK, wKNIGHT, wBISHOP, wQUEEN, wKING, wBISHOP, wKNIGHT, wROCK},
    };
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            board[i][j] = temp[i][j];
        }
    }
}

void Grid::print_board()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            std::cout << static_cast<int16_t>(this->board[i][j]) << "  ";
        }
        std::cout << "\n";
    }
}

void Grid::draw_board(sf::RenderWindow &window)
{
    int x = 0;
    int j = 0;
    for (size_t i = 0; i < 64; i++)
    {
        if (i != 0 && i % 8 == 0)
        {
            j++;
            x = 0;
        }
        squares[i].setSize(sf::Vector2f(100, 100));
        squares[i].setPosition(sf::Vector2f(100 * x, 100 * j));
        if (j % 2 == 0)
        {
            (x % 2 == 0) ? squares[i].setFillColor(sq_col2) : squares[i].setFillColor(sq_col1);
        }
        else
        {
            (x % 2 == 0) ? squares[i].setFillColor(sq_col1) : squares[i].setFillColor(sq_col2);
        }
        window.draw(squares[i]);
        x++;
    }
}
void Grid::load_textures()
{
    std::string labels[12] = {"bK", "bQ", "bR", "bB", "bN", "bP", "wK", "wQ", "wR", "wB", "wN", "wP"};
    for (auto &label : labels)
    {
        label = "assets/" + label + ".png";
    }
    for (size_t i = 0; i < 12; i++)
    {
        T[i].loadFromFile(labels[i]);
    }
}

void Grid::load_pieces()
{
    using namespace fig;
    int cnt = 0;
    for (size_t row = 0; row < 8; row++)
    {
        for (size_t col = 0; col < 8; col++)
        {
            int n = this->board[row][col];
            if (n == 0)
            {
                continue;
            }
            if (n == bKING)
            {
                pieces[cnt].setTexture(T[0]);
            }
            else if (n == bQUEEN)
            {
                pieces[cnt].setTexture(T[1]);
            }
            else if (n == bROCK)
            {
                pieces[cnt].setTexture(T[2]);
            }
            else if (n == bBISHOP)
            {
                pieces[cnt].setTexture(T[3]);
            }
            else if (n == bKNIGHT)
            {
                pieces[cnt].setTexture(T[4]);
            }
            else if (n == bPAWN)
            {
                pieces[cnt].setTexture(T[5]);
            }
            else if (n == wKING)
            {
                pieces[cnt].setTexture(T[6]);
            }
            else if (n == wQUEEN)
            {
                pieces[cnt].setTexture(T[7]);
            }
            else if (n == wROCK)
            {
                pieces[cnt].setTexture(T[8]);
            }
            else if (n == wBISHOP)
            {
                pieces[cnt].setTexture(T[9]);
            }
            else if (n == wKNIGHT)
            {
                pieces[cnt].setTexture(T[10]);
            }
            else if (n == wPAWN)
            {
                pieces[cnt].setTexture(T[11]);
            }
            pieces[cnt].setPosition(col * 100, row * 100);
            cnt++;
        }
    }
}

void Grid::draw_pieces(sf::RenderWindow &window)
{
    for (size_t i = 0; i < 32; i++)
    {
        window.draw(pieces[i]);
    }
}

void Grid::handle_event(sf::RenderWindow &window,sf::Event &event,sf::Vector2i &position){
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Mouse click handling 
            if(event.type==sf::Event::MouseButtonPressed){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    for (int i = 0; i < 32; i++)
                    {
                        if(pieces[i].getGlobalBounds().contains(position.x,position.y)){
                            current_index.mousepos_to_index(position);
                            std::cout << current_index << "\n";
                        }
                    }
                    
                    
                }

            }
            if(event.type == sf::Event::MouseButtonReleased){
                this->target_index.mousepos_to_index(position);
                std::cout<< " Target:" << target_index;
            }
        }
}