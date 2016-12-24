#include <iostream>
#include "tictactoe.h"
#include "ticTacToeAI.h"
int main(){
    tictactoe game;
    game.printBoard();
    ticTacToeAI ticAI;
    int turns = 0;
    //std::cout<<0b001010100<<std::endl;
    while(!game.checkWin()){
        int t = 0;
        if(turns%2==1){
        //if(1){
            std::cin>>t;
        }else{
            t = ticAI.getBest(tictactoeBoard(game),turns);
            std::cout<<"\n"<<t<<std::endl;
        }
        game.doTurn(t);
        game.printBoard();
        std::cout<<std::endl;
        ++turns;
    }
    return 0;
}

