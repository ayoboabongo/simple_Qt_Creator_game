#include "ennemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "game.h"


extern Game * game;

Ennemy::Ennemy(QGraphicsItem* parent):QObject (),QGraphicsPixmapItem ()
{
    // set position
    int random_number= rand() % 700 ;
    setPos(random_number,0) ;

    //set color
    //setBrush(Qt::red);

    // drew the graphics
    setPixmap(QPixmap("C:/Users/Abongo Ayobo/Documents/game/ennemy.jpg"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Ennemy::move(){
    // move ennemy down
    setPos(x(),y()+5);
    if((pos().y())>scene()->height())
    {
        //decrease the health
        game->health->decrease() ;
        scene()->removeItem(this);
        delete this ;
        qDebug()<<"enemy deleted" ;
    }
}
