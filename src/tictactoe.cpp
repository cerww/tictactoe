#include "tictactoe.h"
void tictactoe::doTurn(int spot){
    if((m_board>>spot)%2){
        std::cout<<"choose another"<<std::endl;
        return;
    }
    if(turns%2==0){
        m_Os = m_Os | (1<<spot);
    }else{
        m_Xs = m_Xs | (1<<spot);
    }++turns;
    m_board = m_board|(1<<spot);
}
char tictactoe::checkWin(){
    if(m_board==0b111111111) return 3;
    std::vector<short> possibleWins{0b111000000,0b000111000,0b000000111,0b100100100,0b010010010,0b001001001,0b100010001,0b001010100};
    for(auto& i:possibleWins){
        if((m_Xs&i)==i)
            return 2;
        if((m_Os&i)==i)
            return 1;
    }
    return 0;
}
void tictactoe::printBoard(){
    std::vector<char> boardy(9,'_');
    for(int i = 0;i<9;++i){
        if((m_Os>>i)%2) boardy[i] = 'O';
        if((m_Xs>>i)%2) boardy[i] = 'X';
    }
    for(int x = 0;x<3;++x){
        std::cout<<"|";
        for(int y = 0;y<3;++y){
            std::cout<<boardy[x*3+y]<<"|"<<std::flush;
        }std::cout<<std::endl;
    }
    std::cout<<m_Os<<" "<<m_Xs<<std::endl;
}
