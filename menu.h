#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <game.h>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButtonNewgame_clicked();

    void on_pushButton_quit_clicked();

private:
    Ui::Menu *ui;
   // Game * game;
};

#endif // MENU_H
