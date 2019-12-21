#include "menu.h"
#include "ui_menu.h"
#include "game.h"
#include <QApplication>

Game * game;

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButtonNewgame_clicked()
{
    //Game* game;
    game = new Game();
   // game->health->setHealth(3) ;
    hide();
    game->show();

}

void Menu::on_pushButton_quit_clicked()
{
     exit(EXIT_FAILURE) ;
}
