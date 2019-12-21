#include <QApplication>
#include "game.h"
#include "menu.h"

/*
Tutorial Topics:
-events (keyPressEvent() and QKeyEvent)
-event propogation system
-QDebug
*/
//Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Menu* w=new Menu() ;
    w->show();

    return a.exec();
}

