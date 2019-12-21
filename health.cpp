#include "health.h"
#include <QFont>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "menu.h"
extern Game* game;
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the health to 3
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    if(health==0)
    {
       // game=new Game();
        Menu* w =new Menu();
        game->hide() ;       
        w->show() ;
        setHealth(3) ;
         // exit(EXIT_FAILURE) ;
    }
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}

void Health::setHealth(int h)
{
    health=h;
}
