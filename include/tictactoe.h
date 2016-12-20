#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <vector>
#include <unordered_map>
#include <iostream>
class tictactoe
{
    public:
        tictactoe(){};
        virtual ~tictactoe(){};
        void doTurn(int spot);
        char checkWin();//1 = O,2 = X,3 = tie
        void printBoard();
    protected:

    private:
        short m_board = 0;
        char turns = 0;
        short m_Xs = 0;
        short m_Os = 0;
};

#endif // TICTACTOE_H
