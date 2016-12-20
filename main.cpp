#include <iostream>
#include "tictactoe.h"
int main(){
    tictactoe game;
    game.printBoard();
    while(!game.checkWin()){
        int t = 0;
        std::cin>>t;
        game.doTurn(t);
        game.printBoard();
        std::cout<<std::endl;
    }
    return 0;
}

