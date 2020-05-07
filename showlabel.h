#ifndef SHOWLABEL_H
#define SHOWLABEL_H
#include <QLabel>
#include <QMouseEvent>

class showLabel_base : public QLabel
{
    Q_OBJECT

public:
    explicit showLabel_base(QWidget *parent = 0,int id = 0);
    int cell_id;

protected:
    void mousePressEvent(QMouseEvent *event);    //按下

signals:
//    void selectedSignal(int id);
    void evaluateSignal(int id);
public slots:

};

class showLabel_chess : public QLabel
{
    Q_OBJECT

public:
    explicit showLabel_chess(QWidget *parent = 0,int id = 0);
    int cell_id;
    bool seleflag;
    void mousePressEvent(QMouseEvent *event);    //按下
    void setVision(int,const QPixmap &,const QPixmap &,const QPixmap &,const QPixmap &);

signals:
        void selectedSignal(int id);

public slots:

};

class showLabel_tagchess : public QLabel
{
    Q_OBJECT

public:
    explicit showLabel_tagchess(QWidget *parent = 0,int id = 0);
    int cell_id;
    void setVision(int,const QPixmap &,const QPixmap &);
protected:
public slots:

};


#endif // SHOWLABEL_H
