#ifndef TICTACTOEAI_H
#define TICTACTOEAI_H
#include "tictactoe.h"
#include <vector>
#include <unordered_map>
#include "vecFuncs.h"
struct tictactoeBoard{
    friend class tictactoe;
    tictactoeBoard(){};
    tictactoeBoard(tictactoe b){
        Xs = b.m_Xs;
        Os = b.m_Os;
    };
    ~tictactoeBoard(){};
    short Xs = 0;
    short Os = 0;
};//Os|Xs gives board
namespace std{
    template<>
    class hash<tictactoeBoard>{
    public:
        size_t operator()(const tictactoeBoard& board)const{
            return board.Xs^board.Os;
        }
    };
};
class ticTacToeAI{
    public:
        friend class tictactoe;
        ticTacToeAI();
        virtual ~ticTacToeAI();
        int getBest(tictactoeBoard,int);
        static int OWins;
        static int XWins;
        static int ties;
    private:
        float getBoardValue(tictactoeBoard,int,int&);
};

#endif // TICTACTOEAI_H
