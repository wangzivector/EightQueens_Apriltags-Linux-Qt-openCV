#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chessforview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    chessforview *chessboard;
    Game *game;
    bool gamemode;
    QPixmap  pma;
    QPixmap  pmb;
    QPixmap  pmc;
    QPixmap  pmd;
    QPixmap  pme;
    QPixmap  pmf;
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public  slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void dealtakeSlot(int);
    void dealputSlot(int);
};

#endif // MAINWINDOW_H
