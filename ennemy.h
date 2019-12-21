#ifndef ENNEMY_H
#define ENNEMY_H


#include <QGraphicsPixmapItem>
#include <QObject>

class Ennemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ennemy(QGraphicsItem* parent=nullptr);
public slots:
    void move();
};
#endif // ENNEMY_H
