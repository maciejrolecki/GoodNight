#ifndef ENDINGDIALOG_H
#define ENDINGDIALOG_H

#include <QDialog>
#include "dialog.h"

namespace Ui {
class EndingDialog;
}
/**
 * Window displayed at the end of the game letting the user decide if he wants to play again or not.
 */
class EndingDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief EndingDialog The final window with the result of the game
     * @param finalText Text to display, who won the game
     * @param color
     * @param parent The widget that it can relate to.
     */
    explicit EndingDialog(QString finalText,Qt::GlobalColor color,QWidget *parent=nullptr);
    /**
     * @brief Destroy the Ending Dialog object
     * 
     */
    ~EndingDialog();

private slots:
/**
 * @brief Restarts the game and closes the current window.
 * 
 */
    void on_pushButton_clicked();
/**
 * @brief Exits the game.
 * 
 */
    void on_exitBt_clicked();

private:
    QString finalText;
    Qt::GlobalColor color;
    Ui::EndingDialog *ui;
};

#endif // ENDINGDIALOG_H
