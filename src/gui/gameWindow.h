#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsView>
#include <cmath>
#include <QPen>
#include <QPushButton>
#include <QSlider>

#include "../nuitcore/gameState.hpp"
#include "../nuitcore/game.h"
#include "point.hpp"

/**
 * @brief The Graphical presentation of the game. Serves for interactions between the user and the game.
 */
class GameWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Game Window object
     * 
     * @param game game that it has to integrate with the game window
     * @param _nbPlayers Number of players that are currently playing
     * @param parent The widget that it can relate to.
     * @param rad Reference size that is used for the placement of the widgets and items.
     */
    GameWindow(Game &game, int _nbPlayers, QWidget *parent = nullptr, double rad = 50);
    /**
     * @brief Displays in the current window whose turn it is currently.
     * 
     */
    void displayPlayerTurn();
    /**
     * @brief Displays in the current window what the current player has to do.
     * 
     * @param string Text to display.
     */
    void displayIndications(QString string);
    /**
     * @brief Displays the state of the game int the first phase of the game. When the light is still active.
     * The players will place their stars on the game board.
     * @param scene Where to place the widgets and items.
     */
    void displayPhase1(QGraphicsScene *scene);
    /**
     * @brief Displays the state of the game int the second phase of the game. When the light is off.
     * The players will remove their stars without seeing their color.
     * @param scene Where to place the widgets and items.
     */
    void displayPhase2(QGraphicsScene *scene);
    /**
     * @brief Displays the final state of the game. Starts a new window that offers the possibility to play again or to exit.
     * 
     */
    void endDisplay();
    /**
     * @brief Adds the indicator of where the user can place their stars.
     * 
     */
    void displayRose();
    /**
     * @brief Is triggered when the user clicks on a star that can be clicked.
     * 
     * @param checkpoint Where he clicked. Reprented by the line in the GUI
     * @param place Where he clicked. Reprented by the column in the GUI
     */
    void clickPlace(size_t checkpoint, size_t place);
    /**
     * @brief Delete the items that were added to the foreground.
     * 
     */
    void deleteForeground();

    /**
     * @brief Updates display.
     */
    void updateDisplay();
    //Observer
    /**
     * @brief Destroy the Game Window object
     * 
     */
    virtual ~GameWindow()
    {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }
    virtual void Update() override
    {
        updateDisplay();
    };
    void RemoveMeFromTheList()
    {
        _game.Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }

protected: 
 
    size_t _nbPlayers = 0; // number of players
    QWidget *parent = nullptr;
    QGraphicsScene *foreground = new QGraphicsScene(); // main scene
    QString indicationText = "EMPTY"; //what the player should do
    QString playerTurnText = "EMPTY"; //which player should okay
    QGraphicsTextItem *communication; // Object through which the communication will be displayed
    QGraphicsTextItem *playerTurnItem;// Object through which the order of play will be displayed
    double rad; //Reference size that is used for the placement of the widgets and items.

    //Observer
    Game &_game;
    Board *_board;
    int number_;
    size_t checkpoint = 9;
    size_t place = 5;
    QPushButton *end = nullptr;

    Qt::GlobalColor getQtColor(Color color);
    QString getPlayerName(Color color);

private:
/** 
 * @brief starts the game
 */
    void startGame();
};
#endif // GAMEWINDOW_H
