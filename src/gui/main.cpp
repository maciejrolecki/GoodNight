#include <iostream>
#include <QApplication>

#include "dialog.h"
#include "game.h"
/**
 * @brief Main class
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    Board cr = Board();
    cr.addStarPos(Color::STAR_RED, 2, 2);
    QApplication b(argc, argv);
    Game game;
    Dialog w = Dialog(game);
    w.show();
    return b.exec();
}
