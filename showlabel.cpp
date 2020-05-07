#include "showlabel.h"

#define cell_size 25
showLabel_base::showLabel_base(QWidget *parent,int id) : QLabel(parent)
{
    cell_id=id;

}

showLabel_chess::showLabel_chess(QWidget *parent,int id) : QLabel(parent)
{
    cell_id=id;
    seleflag=false;
}

showLabel_tagchess::showLabel_tagchess(QWidget *parent,int id) : QLabel(parent)
{
    cell_id=id;
}


void showLabel_chess::mousePressEvent(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {
        emit selectedSignal(cell_id);
    }
}

void showLabel_base::mousePressEvent(QMouseEvent *event)
{
    if(event->button()== Qt::RightButton)
    {
        emit evaluateSignal(cell_id);
    }
}

void showLabel_chess::setVision(int mode,const QPixmap & pmc,const QPixmap & pmd,const QPixmap & pme,const QPixmap & pmf)
{
//    QPixmap pmc(":/img/chess.png");
//    pmc=pmc.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    QPixmap pmd(":/img/selechess.png");
//    pmd=pmd.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    QPixmap pme(":/img/chess.png");
//    pme=pme.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    QPixmap pmf(":/img/nchess.png");
//    pmf=pmf.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    switch(mode)
    {
    case 1:
        seleflag=true;
        this->setPixmap(pmc);
        this->setVisible(true);
        break;
    case 2:
        seleflag=true;
        this->setPixmap(pmd);
        this->setVisible(true);
        break;
    case 3:
        this->setPixmap(pme);
        this->setVisible(false);
        seleflag=false;
        break;
    case 4:
        this->setPixmap(pmf);
        this->setVisible(true);
        break;
    default:
        break;
    }
}

void showLabel_tagchess::setVision(int mode,const QPixmap & pma,const QPixmap & pmb)
{
//    QPixmap pma(":/img/tagchess.png");
//    pma=pma.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    QPixmap pmb(":/img/tagchess.png");
//    pmb=pmb.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    switch(mode)
    {
    case 1:
        this->setPixmap(pma);
        this->setVisible(true);
        break;
    case 2:
        break;
    case 3:
        this->setPixmap(pmb);
        this->setVisible(false);
        break;
    default:
        break;
    }
}
//void showLabel_tagchess::setVisiontry(const QPixmap & pm)
//{
//    this->setPixmap(pm);
//    this->setVisible(true);
//}

