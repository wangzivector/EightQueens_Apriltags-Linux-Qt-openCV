#ifndef CHESSFORVIEW_H
#define CHESSFORVIEW_H
#include <QWidget>
#include"showlabel.h"
#include"game.h"

class chessforview : public QWidget
{
    Q_OBJECT

public:
    explicit chessforview(QWidget *parent = 0);
    showLabel_base* cell_base[64];
    showLabel_chess* cell_chess[64];
    showLabel_tagchess* cell_tagchess[64];
    void chessclean();
private:
};
#endif // CHESSFORVIEW_H
