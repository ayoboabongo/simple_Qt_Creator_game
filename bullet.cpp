#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "ennemy.h"
#include "score.h"
#include "game.h"


extern Game * game;

Bullet::Bullet(QGraphicsItem* parent):QObject (),QGraphicsPixmapItem ()
{
    // drew the graphics
    setPixmap(QPixmap("C:/Users/Abongo Ayobo/Documents/game/bullet.jpg"));

    //set color
   // setBrush(Qt::green);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){

    //collision avec enemy
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid (*(colliding_items[i]))==typeid (Ennemy))
        {
            game->score->increase() ;
            // remove both of them
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //then delete
            delete colliding_items[i] ;
            delete this ;

        }
    }

    // move bullet up
    setPos(x(),y()-10);
    if((pos().y())<0)
    {
        scene()->removeItem(this);
        delete this ;
        qDebug()<<"bullet deleted" ;
    }
}
