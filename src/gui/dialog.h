#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "gameWindow.h"

namespace Ui {
class Dialog;
}
/**
 * Window displayed when starting the program but also when launching the game again, from the game itself.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Dialog The entry Window
     * @param game Concerned Game class that is necessary for running th egame properly
     * @param parent The widget that it can relate to.
     */
    explicit Dialog(Game& game,QWidget *parent = nullptr);
/**
 * @brief Destroy the Dialog object
 * 
 */
     ~Dialog();

private slots:
    /**
     * @brief on__sendBt_clicked tied to the button necessary for launching the game.
     */
    void on__sendBt_clicked();

private:
    Ui::Dialog *ui;
    Game game;
};

#endif // DIALOG_H
