#include "game.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    gameInit(true);
    Solution= new bahuanghou;
}

void Game::gameInit(bool mode)
{
    mov_step=0;
    selechess=64;
    if(mode)
        for(int count=0;count < 8;count++)
        {
            chess_loca[count]= count;
            chess_nmov[count]= 64;
            chess_movt[count]= 64;
        }
    else
        for(int count=0;count < 8;count++)
            chess_loca[count]= 64;
}

bool Game::gameReloca(unsigned int pre_loca,unsigned int new_loca)
{
    for(int posi=0;posi<8;posi++)
    {
        if(chess_loca[posi]==pre_loca)
        {
            chess_loca[posi]=new_loca;
            int count=8;
            int num_temp=0;
            for ( int i = 0; i < count - 1; i++) {
                for ( int j = 0; j < count - i - 1; j++) {
                        if (chess_loca[j]> chess_loca[j + 1])
                        {
                            num_temp = chess_loca[j];
                            chess_loca[j]=chess_loca[j+1];
                            chess_loca[j+1]=num_temp;
                        }
                    }
                }
            //
            return true;
        }
    }
    return false;
}

void Game::figure()
{
    Solution->bahuanghou_figure(chess_loca);
    mov_step =Solution->movestep;
    for(int count_f=0;count_f<mov_step;count_f++)
    {
        chess_nmov[count_f]=Solution->min_start_loca[count_f]-1;
        chess_movt[count_f]=Solution->min_end_loca[count_f]-1;
    }
}
