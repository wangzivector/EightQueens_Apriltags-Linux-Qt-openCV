#include<chessforview.h>
#define cell_size 25
#define board 5

chessforview::chessforview(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(board*2,board*2,200,200);
    QPixmap pm(":/img/base.png");
    pm=pm.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

    QPixmap pm1(":/img/chess.png");
    pm1=pm1.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

    QPixmap pm2(":/img/tagchess.png");
    pm2=pm2.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

    for(int id=0;id<64;id++)
    {
        cell_base[id] = new showLabel_base(this,id);
        cell_chess[id] = new showLabel_chess(this,id);
        cell_tagchess[id] = new showLabel_tagchess(this,id);

        cell_base[id]->setPixmap(pm);
        cell_base[id]->setGeometry((id%8)*(cell_size),(id/8)*(cell_size),cell_size,cell_size);

        cell_chess[id]->setPixmap(pm1);
        cell_chess[id]->setGeometry((id%8)*(cell_size),(id/8)*(cell_size),cell_size,cell_size);

        cell_tagchess[id]->setPixmap(pm2);
        cell_tagchess[id]->setGeometry((id%8)*(cell_size),(id/8)*(cell_size),cell_size,cell_size);
        if((id%2)==1)
            cell_tagchess[id]->setVisible(false);
        else
            cell_chess[id]->setVisible(false);
    }
}



void chessforview::chessclean()
{
    for(int id=0;id<64;id++)
    {
        cell_chess[id]->setVisible(false);
        cell_tagchess[id]->setVisible(false);
    }
}
