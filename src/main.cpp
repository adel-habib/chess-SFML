#include <iostream>
#include <math.h>
#include "Board.h"
using namespace std;

int main(){
   
    Board b;
    b.init_board();
    int cnt = 0;
    for (int i = 63; i > -1; i--)
    {
        if(cnt%8==0){
            cout << "\n";
        }
        cout <<b.board[i] << " ";
        cnt++;
    }
    cout <<"\n";
    return 0;
}