#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#define cell_size 25
#define board 5

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    this->setWindowTitle("wangzit");
    gamemode=true;//true is man,false is opencv;
    game = new Game(this);
    chessboard = new chessforview(this);
    for(int step=0;step<64;step++)
    {
        connect(chessboard->cell_chess[step],SIGNAL(selectedSignal(int)),this,SLOT(dealtakeSlot(int)));
        connect(chessboard->cell_base[step],SIGNAL(evaluateSignal(int)),this,SLOT(dealputSlot(int)));
    }
    QPixmap pmc1(":/img/chess.png");
    pmc=pmc1.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pmd1(":/img/selechess.png");
    pmd=pmd1.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pme1(":/img/chess.png");
    pme=pme1.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pmf1(":/img/nchess.png");
    pmf=pmf1.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pma1(":/img/tagchess.png");
    pma=pma1.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pmb1(":/img/tagchess.png");
    pmb=pmb1.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}
////
//QPixmap pmt(":/img/nchess2.png");
//pmt=pmt.scaled(cell_size,cell_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//chessboard->cell_tagchess[63]->setVisiontry(pmt);
////

void MainWindow::on_pushButton_clicked()//reset
{
  ui->label->setText("ready!");
  game->gameInit(gamemode);
  chessboard->chessclean();
      for(int count_chess=0;count_chess<8;count_chess++)
          if(game->chess_loca[count_chess]<64)
             chessboard->cell_chess[game->chess_loca[count_chess]]->setVision(1,pmc,pmd,pme,pmf);
  ui->textEdit->setText("");
  for(int countview=0;countview<8;countview++)
      ui->textEdit->append(QString::number(game->chess_loca[countview]+1));
}

void MainWindow::on_pushButton_2_clicked()//figure
{

  ui->label->setText("figure!");
  game->figure();
  chessboard->chessclean();
  for(int count_chess=0;count_chess<8;count_chess++)
      if(game->chess_loca[count_chess]<64)
         chessboard->cell_chess[game->chess_loca[count_chess]]->setVision(1,pmc,pmd,pme,pmf);
  for(int count_m=0;count_m<game->mov_step;count_m++)
  {
    chessboard->cell_chess[game->chess_nmov[count_m]]->setVision(4,pmc,pmd,pme,pmf);
    chessboard->cell_tagchess[game->chess_movt[count_m]]->setVision(1,pma,pmb);
//    qDebug()<<QString::number(game->mov_step);
  }
}

void MainWindow::dealtakeSlot(int id_take)
{
    if(game->selechess!=64)
    {
        chessboard->cell_chess[game->selechess]->setVision(1,pmc,pmd,pme,pmf);
    }
    game->selechess=id_take;
    chessboard->cell_chess[game->selechess]->setVision(2,pmc,pmd,pme,pmf);
    ui->label->setText(QString::number(game->selechess+1));
}

void MainWindow::dealputSlot(int id_put)
{
    if(game->selechess==64)
    {
        return;
    }
    if(game->gameReloca(game->selechess,id_put))
    {
        ui->textEdit->setText("");
        for(int countview=0;countview<8;countview++)
            ui->textEdit->append(QString::number(game->chess_loca[countview]+1));
        chessboard->cell_chess[game->selechess]->setVision(3,pmc,pmd,pme,pmf);
        chessboard->cell_chess[id_put]->setVision(1,pmc,pmd,pme,pmf);
        ui->label->setText(QString::number(id_put+1));
        game->selechess=64;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
