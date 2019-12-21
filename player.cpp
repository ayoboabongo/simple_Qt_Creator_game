#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "ennemy.h"
#include <QMediaPlayer>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    //set color
   // setBrush(Qt::white);
   setPixmap(QPixmap("C:/Users/Abongo Ayobo/Documents/game/player_1.jpg"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+40,y());
        scene()->addItem(bullet);
        QMediaPlayer *sound=new QMediaPlayer() ;
        sound->setMedia(QUrl("C:/Users/Abongo Ayobo/Documents/game/Gun+Silencer.mp3"));
        sound->play() ;
    }
}

void Player::spawn(){
    // create an enemy
    Ennemy * enemy = new Ennemy();
    scene()->addItem(enemy);
}
