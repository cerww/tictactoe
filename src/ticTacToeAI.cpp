#include "ticTacToeAI.h"
ticTacToeAI::ticTacToeAI()
{
    //ctor
}
int ticTacToeAI::OWins=0;
int ticTacToeAI::XWins=0;
int ticTacToeAI::ties=0;
float ticTacToeAI::getBoardValue(tictactoeBoard board,int turns,int& total){
    if((board.Xs|board.Os)==0b111111111){
            ++total;
            ++ties;
            return 0;
    }
    else{
        std::vector<short> possibleWins{0b111000000,0b000111000,0b000000111,0b100100100,0b010010010,0b001001001,0b100010001,0b001010100};
        for(auto& i:possibleWins){
            if((board.Xs&i)==i){
                ++total;
                ++XWins;
                return -1;
            }
            if((board.Os&i)==i){
                ++total;
                ++OWins;
                return 1;
            }
        }
    }
    std::vector<float> vals;
    for(int i = 0;i<9;++i){
        if(((board.Xs|board.Os)>>i)%2==1) continue;
        auto nboard = board;
        if(turns%2==0) nboard.Os = nboard.Os|(1<<i);
        else nboard.Xs = nboard.Xs|(1<<i);
        vals.push_back(getBoardValue(nboard,turns+1,total));
    }
    float re = 0;
    for(auto x:vals) re+=x;
    return re;
    if(turns%2==0) return vecMin(vals);
    return vecMax(vals);
}
int ticTacToeAI::getBest(tictactoeBoard board,int turns){
    std::vector<float> vals(9,-1270);
    for(int i = 0;i<9;++i){
        if(((board.Xs|board.Os)>>i)%2==1) continue;
        OWins = 0;
        XWins = 0;
        ties = 0;
        auto nboard = board;
        int total = 0;
        if(turns%2==0) nboard.Os = nboard.Os|(1<<i);
        else nboard.Xs = nboard.Xs|(1<<i);
        vals[i] = getBoardValue(nboard,turns+1,total);//total;
        vals[i]=10000*((float)(vals[i]))/(float)total;
        //if(i==4){
            std::cout<<OWins<<" "<<XWins<<" "<<ties<<std::endl;
        //}
        //std::cout<<total<<std::endl;
    }
    for(auto x:vals)std::cout<<(int)x<<" "<<std::flush;
    int highest = 0;
    for(int i = 1;i<9;++i){
        if(vals[i]>vals[highest]) highest = i;
    }return highest;
}
ticTacToeAI::~ticTacToeAI()
{
    //dtor
}
