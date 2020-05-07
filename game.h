#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "bahuanghou.h"

class Game : public QWidget  //要使用信号槽必须继承QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = 0);
    unsigned int chess_loca[8];
    int chess_nmov[8];
    int chess_movt[8];
    int selechess;
    int mov_step;
    void gameInit(bool);
    bool gameReloca(unsigned int,unsigned int);
    void figure();
private:
    bahuanghou *Solution;
};


#endif // GAME_H
