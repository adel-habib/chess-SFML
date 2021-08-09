#include <iostream>
#include <math.h>
#include "Board.h"
#include "GUI.h"
using namespace std;

int main(){
   
    Board b;
    b.init_board();
    Gui gui;
    gui.mainloop();
}