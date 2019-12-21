#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=nullptr);
    void decrease();
    int getHealth();
    void setHealth(int);
private:
    int health;
};
#endif // HEALTH_H
